/* -*- Mode: c++ -*- 
 *
 *  Copyright 1997 Massachusetts Institute of Technology
 * 
 *  Permission to use, copy, modify, distribute, and sell this software and its
 *  documentation for any purpose is hereby granted without fee, provided that
 *  the above copyright notice appear in all copies and that both that
 *  copyright notice and this permission notice appear in supporting
 *  documentation, and that the name of M.I.T. not be used in advertising or
 *  publicity pertaining to distribution of the software without specific,
 *  written prior permission.  M.I.T. makes no representations about the
 *  suitability of this software for any purpose.  It is provided "as is"
 *  without express or implied warranty.
 * 
 */

#include <StrlSigProc.h>
#include <StrlConnect.h>

#define ROUNDUP(SIZE,UNIT) {SIZE = ( ( (SIZE+UNIT-1)/UNIT) * UNIT ); }
unsigned int cacheSize = CACHESIZE;
float maxLatency = .2; //in seconds
#ifdef THREADS
pthread_key_t startMarkedModule;
#else
StrlSigProc *startMarkedModule;
#endif 

//returns: 1 if all data has been computed
int StrlSigProc::dataReady(VrSampleRange r) {
  //We need to move the buffer's write pointer to be >= index+size
  //FIX parse through the link list?
  if (r.index + r.size <= WP)
    return 1; // all data has already been finished
  return 0;
}

//returns: 1 if all data is marked to be computed
int StrlSigProc::dataMarked(VrSampleRange r) {
  //We need to move the buffer's marked pointer to be >= index+size
  if (r.index + r.size <= markedWP)
    return 1; // all data is marked
  return 0;
}
  
//Returns the minimum write space in downstream buffers
//  (given that you desire at least "desired" space)
int StrlSigProc::minwritespace(VrSampleIndex newWP, unsigned int desired)
{
    int s = (*outBuffer)->writespace(newWP+desired); 
    unsigned int i=0;
    while(++i<numberOutputs) {
      int t=outBuffer[i]->writespace(newWP+desired);
      if(t<s) s=t;
    }
    return s+desired;
}

// requires LL to be locked already (holdover from when
// makeData could be running in multiple threads)
void StrlSigProc::attach_writer(writerLL *r)
{
    if (!first)
      first=r;
    else {
      last->next=r;
#ifdef PARANOID
      if(last->maxValid > r->maxValid) {
	fprintf(stderr, "Out of order write threads.\n");
	exit(-1);
      }
#endif
    }
    last=r;
#ifdef PARANOID
    if(last->maxValid != markedWP) {
      fprintf(stderr, "WriterLL inconsistency (another thread marked more data before the writer linked list was updated).\n");
      exit(-1);
    }
#endif
    THREAD_UNLOCK;
}

void StrlSigProc::detach_writer(writerLL *r)
{
    THREAD_LOCK; 
    if(first==r) {
      first=r->next;
      if(last==r) last=NULL;
      WP=r->maxValid;
    } else {
#ifdef PERFMON
      cycles->WPdelayedUpdate++;
#endif
      writerLL *t= (writerLL *) first;
      while(t->next != r) t=t->next;
      t->next=r->next;
      t->maxValid=r->maxValid; 
      if(last==r) last = t;
    }
    THREAD_UNLOCK;
}
//Returns the minimum RP in downstream buffers' readers
//  computes the most up to date value possible.
VrSampleIndex StrlSigProc::proc_minRP() {
    if(!outBuffer)
      return (VrSampleIndex) -1; 
    VrSampleIndex m = (*outBuffer)->updateMinRP(); 
    unsigned int i=0;
    while(++i<numberOutputs) {
      VrSampleIndex t=outBuffer[i]->updateMinRP();
      if(t<m) m=t;
    }
    return m;
}

VrSampleIndex StrlSigProc::minrpCheck(VrSampleIndex pendingWP,VrSampleRange r)
{
  VrSampleIndex minrp = 0;
  if(WP==pendingWP && (minrp=proc_minRP()) > WP) {
    //we are first writing thread
    //and all other chains are done with data before VrSampleIndex minrp
    //so we can skip some data 
    if(uses_sync) {
      //(can't ever skip if the module uses the sync() call!)
      //so expand our data to compute everything up to index
      r.size+=(pendingWP-r.index);
      r.index=pendingWP;
      printf("[1] executing...\n");
    } else { 
      if(minrp>r.index) minrp=r.index;
#ifdef PERFMON
      cycles->skippedData+=(minrp-pendingWP);
#endif
      pendingWP=minrp;
      printf("[2] executing...\n"); 
      return pendingWP;
    } 
  } else {
    //could: find which of outBuffer[?]->connectors[?]->lastRP == minrp
#ifdef PERFMON
    cycles->blockOnUnmarkedData++;
#endif
    //fprintf(stderr,"Out of order mark attempt\n");
    printf ("[%s:%d] out of order minrp %lld r.index %lld\n", __FILE__, __LINE__, minrp, r.index);
    return -1;
  }
  return pendingWP;
}

//called by a downstream buffer (does NOT run in parallel)
//returns: 2 if data if all data is already computed
//returns: 1 if data is ready to be computed (and has been marked)
//returns: 0 if data is ready on this level or above
//           but no further data should be marked.
//returns: -1 if no data is ready to be computed
//returns: -2 if data is marked by another thread

int StrlSigProc::StrlmarkData(VrSampleIndex pendingWP, int requestSize,int dataMarkedUpstream,VrSampleRange inputrange )
{
  unsigned int space=0;
  VrSampleIndex desiredWP;

  /*** Mark data here if upstream mark was successful ***/
  if(outBuffer)
        space = minwritespace(pendingWP,requestSize);
  if (outBuffer && space < (unsigned int)requestSize) {
#ifdef PERFMON
   cycles->bufferFullOnWrite++;
#endif
    if(dataMarkedUpstream) return 0;
    return -1;
  }

  /** Mark data to be computed **/
  desiredWP = pendingWP + requestSize;
  THREAD_LOCK; //hold-over from old way (see below)
  markedWP=desiredWP; //assumes single-threaded marking!!!
#ifdef DEBUG
  printf("%s (StrlmarkData1):  myMarkedData [%lld, %lu] markedWP %lld desiredWP %lld, WP %lld\n",name(), myMarkedData.index, myMarkedData.size, markedWP,desiredWP,WP);
#endif
  /** initialize pointers to thread-specific marking data **/
  if(!myWriterLL) {             //init (psuedo)thread specific data
    myMarkedData.index=(long long) -1;
    myMarkedData.size=0;
    myWriterLL=new writerLL;
    inputs_forecasted=new VrSampleRange[numberInputs];
    myReaderLLs=new readerLL[numberInputs];
  }
  VrSampleRange& myrange=myMarkedData;
  VrSampleRange *myinputs=(VrSampleRange *) THREAD_GETSPECIFIC(inputs_forecasted
);
  writerLL *wLL = (writerLL *) THREAD_GETSPECIFIC(myWriterLL);
  readerLL *readerLLs = (readerLL *) THREAD_GETSPECIFIC(myReaderLLs);

  /** save which range this thread marked **/
  myrange.index = pendingWP;
  myrange.size = requestSize;
#ifdef DEBUG
  printf("%s (StrlmarkData2) : myMarkedData [%lld, %lu], markedWP %lld, desiredWP(index+size) %lld, pendingWP %lld, WP %lld requestSize %lu\n",name(),myMarkedData.index, myMarkedData.size, markedWP, desiredWP, pendingWP, WP,requestSize);
#endif
  /** save which input ranges were forcasted as needed for this marking **/
  for(unsigned int i=0;i<numberInputs;i++)
    myinputs[i]=inputrange;
  /** create our entry in writer linked list **/
  wLL->maxValid=desiredWP;
  wLL->next = NULL;
  attach_writer(wLL);

  /** create our entries in the reader linked lists upstream **/
  if(numberInputs > 0 ) {
    //Figure out what we'll ask for next
    VrSampleRange nextBlock[numberInputs];
    VrSampleRange nextrange = {pendingWP+requestSize, getOutputSize()};
#ifdef DEBUG
    printf("*Next SRange*\n");
#endif 
    int retval=forecast(nextrange, nextBlock);
    for(unsigned int i=0;i<numberInputs;i++) {
      if(inputrange.size <= 0)
                readerLLs[i].index = (VrSampleIndex) -1;
        else {
        readerLLs[i].index = myinputs[i].index;
          readerLLs[i].next = NULL;
        if(retval<0)    //don't know next block yet, use this one
          inputConn[i]->attach_reader(&readerLLs[i],myinputs[i].index);
        else
          inputConn[i]->attach_reader(&readerLLs[i],nextBlock[i].index);
      }
    }
  }

  /** set the starting module for this compute block to this **/
  startMarkedModule = this;
#ifdef DEBUG
  printf("%s markData returns 1\n",name());
#endif
  return 1; //continue marking downstream if possible
}
 

//returns -1 if not all work completed
unsigned long StrlSigProc::StrlWork(int return_type)
{ 
  VrSampleRange& r=myMarkedData;
  VrSampleRange *inputs=(VrSampleRange *) THREAD_GETSPECIFIC(inputs_forecasted);
  void *inputptrs[numberInputs];
  void *outputptrs[numberOutputs];
  unsigned long complete=0; //units finished

  //Compute data we've marked

  if (return_type) 
    for(unsigned int i=0;i<numberInputs;i++)
      {
	while(!getUpstreamModuleN(i)->dataReady(inputs[i]))
	  {
	    printf("%s data not ready\n",name());
	  };
#ifdef PERFMON
	cycles->blockOnMarkedData++;
#endif
	inputptrs[i]=(void *)inputConn[i]->getReadPointer(inputs[i]);
      }

  for(unsigned int i=0;i<numberOutputs;i++)
      outputptrs[i]=(void *)outBuffer[i]->getWritePointer(r);
#ifdef PERFMON
      cycles->startCount(); // transfer running from overhead and back
#endif

#ifdef DEBUG
printf("%s (before work):output SRange [%lld, %lu], complete %d\n",name(), r.index,r.size,complete);
#endif
      complete = work(r, outputptrs, inputs, inputptrs);
#ifdef DEBUG
printf("%s (after work):output SRange [%lld, %lu], complete %d\n",name(), r.index,r.size,complete);
#endif
       if(complete<r.size) {
	fprintf(stderr,"[%s] Warning: didn't finish all the work.\n", name());
	//couldn't finish all the work, reschedule
#ifdef PARANOID
	if(!uses_sync || markedWP != r.index+r.size) {
	  fprintf(stderr,"[%s] Non-serialized module didn't finish its work.\n", name());
	  exit(-1);
	}
#endif
	//	not_complete--;
      }
#ifdef PERFMON
      cycles->stopCount();
      cycles->updateSamples(complete);
#endif

  return complete;
}

void StrlSigProc::Set_MarkedWP(VrSampleIndex lg)
{
  markedWP=lg;
#ifdef PERFMON
	cycles->uncompleteWork++;
#endif
}
  
void StrlSigProc::StrlWriteData(int dx)
{
  if(dx){
    readerLL *readerLLs = (readerLL *) THREAD_GETSPECIFIC(myReaderLLs);
	for(unsigned int i=0;i<numberInputs;i++) {
	  if(readerLLs[i].index != (VrSampleIndex) -1) 
	    inputConn[i]->detach_reader(&readerLLs[i]);
	}
      }	    
  writerLL *wLL = (writerLL *) THREAD_GETSPECIFIC(myWriterLL);
  detach_writer(wLL); //updates WP 
  myMarkedData.size = 0;
}

int
StrlSigProc::connect_proc(StrlSigProc* arg_proc, port p, unsigned int sf)
{
  StrlConnect ** cs = new (StrlConnect *[numberInputs+1]);
  StrlBuffer *b;

  if(p>arg_proc->numberOutputs) {
    fprintf(stderr,"This SigProc does not have that many outputs.\n");
    exit(-1);
  }
  if(!arg_proc->outBuffer[p])
    arg_proc->initOutputBuffer(p);
  b = arg_proc->outBuffer[p];
  cs[numberInputs]=new StrlConnect((StrlSigProc *) this, b);
  if(numberInputs>0) {
    for(unsigned int i=0;i<numberInputs;i++)
      cs[i]=inputConn[i];
    delete inputConn;
  }
  inputConn=cs;
  numberInputs++;
/* We would like to eliminate this function and calculate
   samplingRate and BPS automatically ... */
  if (arg_proc->setSamplingFrequency(sf) < 0 ) {
    fprintf(stderr,"Sampling Rate/Bits Per Sample do not match\n");
    exit(-1);
  } 
  return 0;
}

void
StrlSigProc::initOutputBuffer(int n)
{
  outBuffer[n]=new StrlBuffer(this);
}

void
StrlSigProc::initMarkedData()
{
#ifdef THREADS
    if(pthread_key_create(&myMarkedData, NULL)) {
      fprintf(stderr,"StrlBuffer: Could not create thread specific variable.\n");
      exit(-1);
    }
    if(pthread_key_create(&inputs_forecasted, NULL)) {
      fprintf(stderr,"StrlBuffer: Could not create thread specific variable.\n");
      exit(-1);
    }
    if(pthread_key_create(&myWriterLL, NULL)) {
      fprintf(stderr,"StrlBuffer: Could not create thread specific variable.\n");
      exit(-1);
    }
    if(pthread_key_create(&myReaderLLs, NULL)) {
      fprintf(stderr,"StrlBuffer: Could not create thread specific variable.\n");
      exit(-1);
    }
    //these variables are initialized in markData()
#else
    myWriterLL=NULL; //variables are initialized in markData()
#endif

}

int
StrlSigProc::setSamplingFrequency(double sf)
{
  if(sf<=0)
    return -1;

  if (checkOutputSamplingFrequency(sf) < 0) {
    fprintf(stderr,"Warning: couldn't set to invalid samplingFrequency\n");
    return -1;
  }
  proc_samplingFrequency = sf;
  return 0;
}

int StrlSigProc::forecast(VrSampleRange output, VrSampleRange inputs[]) {
  /* 1:1 ratio with no history */
  for(unsigned int i=0;i<numberInputs;i++) {
    inputs[i].index=output.index; /* ! do not subtract history ! */
    inputs[i].size=output.size; /* + history */
#ifdef DEBUG
  printf("%s (forecast): (output) SRange[%lld, %lu] => upstream(input) SRange[%lld, %lu]\n",name(),output.index, output.size, inputs[i].index,inputs[i].size);
#endif
  }
  return 0;
}  

StrlSigProc::StrlSigProc(int outputs, unsigned int arg_itype_size, unsigned int arg_type_size)
  : uses_sync(0), proc_samplingFrequency(0.0), WP(0), markedWP(0), maxOutSize(0),
	inputConn(NULL), setupCalled(0), outputSize(1), type_size(arg_type_size),
    itype_size(arg_itype_size), initializeCalled(0), first(NULL), last(NULL),
    outBuffer(NULL), maxDSReadSize(0), numberInputs(0), numberOutputs(0)
{ 
#ifdef PERFMON
  num_print_stats=0;
  cycles = new StrlCycleCount();
#endif
#ifdef THREADS
  if(pthread_mutex_init(&mutex, NULL)) {
    fprintf(stderr, "Couldn't initialize mutex\n");
    exit(-1);
  }
#endif
  if (!outputs)		// For sinks
    outBuffer = NULL;
  else {
    outBuffer = new (StrlBuffer *[outputs]);
    numberOutputs=outputs;
    for(int i=0;i<outputs;i++)
      outBuffer[i]=NULL;
  }
  initMarkedData();
}

StrlSigProc::~StrlSigProc()
{
#ifdef THREADS
  pthread_key_delete(myMarkedData);
  pthread_key_delete(inputs_forecasted);
  pthread_key_delete(myWriterLL);
  pthread_key_delete(myReaderLLs);
#endif
}

double StrlSigProc::getInputSamplingFrequencyN(port p)
{
  return inputConn[p]->connect_getSamplingFrequency();
}

  //setup proceeds in two phases:
  // (1) init() phase: initialize() is called on all modules
  //                   and sampling rates are pinned down
  //                   (proceeds from top to bottom)
  // (2) setup() phase: how much data modules will be reading
  //                    is set and bufferSizes are computed
  //                   (proceeds from bottom to top)

void StrlSigProc::setup() { 
    unsigned int downstreamConnectors=0;
    for(unsigned int i=0;i<numberOutputs;i++)
      downstreamConnectors+=outBuffer[i]->getNumberConnectors();
    //FIX 
    if(++setupCalled>=downstreamConnectors) {
      //called from all downstream chains
      //continue setup upstream
      setup_upstream(); 
      //setup the output buffers
      for(unsigned int i=0;i<numberOutputs;i++)
        outBuffer[i]->setup(type_size);
    }
}
void StrlSigProc::setup_upstream()
{
    //called once per setup of an entire tree

    /*** how big of blocks this module may be asked to
	 compute at one time*/
    unsigned int size=maxDSReadSize;

    size = (size/getOutputSize()) * getOutputSize(); //round down
    if(size == 0) size = getOutputSize();
    
    /*If our maxOutSize is changing propagate the setup upstream */
    if(size!=maxOutSize) {
      maxOutSize=size;
      fprintf(stderr,"%s.setup[%p] %d freq %f (%f sec)\n",
			name(), this, maxOutSize, proc_samplingFrequency, maxOutSize/proc_samplingFrequency);
#ifdef DEBUG
      printf("%s.setup[%p] %d maxOutSize freq %f (%f sec)\n",
			name(), this, maxOutSize, proc_samplingFrequency, maxOutSize/proc_samplingFrequency);
#endif
      for(unsigned int i=0;i<numberInputs;i++) {

	if(getUpstreamModuleN(i)->getSamplingFrequency()==0.0 ||
	   getSamplingFrequency()==0.0 ) {
	  fprintf(stderr,"SamplingFrequency can not be zero.\n");
	  exit(-1);
	} 
	unsigned int oSize = getUpstreamModuleN(i)->getOutputSize();
	unsigned int size_up = mapSizeUp(i,size); 
//	printf("%s module get %u size from mapSizeUp.\n",name(),size_up);
    ROUNDUP(size_up, oSize); 
	//add an extra block in case a read is not outputSize aligned
	size_up += oSize; 
	getUpstreamModuleN(i)->size_setup(size_up);
      }
    }
}  

  //returns how big a block this module will need upstream (on input i)
  //  given it has to produce size outputs
unsigned int StrlSigProc::mapSizeUp(int i, unsigned int size)
{
  unsigned int map_size =(unsigned int) (size *
			   (getUpstreamModuleN(i)->getSamplingFrequency()
			    /getSamplingFrequency()));
#ifdef DEBUG
  printf("%s : mapSizeUp %u \n",name(),map_size);
#endif
  return map_size;
  //    return (unsigned int) (size *
  //		   (getUpstreamModuleN(i)->getSamplingFrequency()
  //		    /getSamplingFrequency()));
}

void StrlSigProc::size_setup(unsigned int size)
{ 
    if(size > maxDSReadSize)
      maxDSReadSize = size; 
    StrlSigProc::setup();
}

int
StrlSigProc::isConnectedToSource()
{
  if(!inputConn)
    return 0;
  for(unsigned int i=0;i<numberInputs;i++)
    if(!getUpstreamModuleN(i)->isConnectedToSource())
      return 0;
  return 1;
}

void StrlSigProc::init_base()
{
      for(unsigned int i=0;i<numberInputs;i++) {
	getUpstreamModuleN(i)->init_base();
      }
      if(!initializeCalled) {
	initialize();
	initializeCalled++;
      }
}

#ifdef PERFMON
  /*** Performance monitoring procedures ***/
double StrlSigProc::getTotalCycles()
{
  return cycles->getTotalCycles();
}

double StrlSigProc::getTotalCycles(int m)
{
  return cycles->getTotalCycles(m);
}
double StrlSigProc::getTotalCyclesMS()
{
  return cycles->getTotalCyclesMS();
}
double StrlSigProc::getCyclesPerSampleMS()
{
  if (getTotalSamples()) return getTotalCyclesMS()/getTotalSamples();
  else return 0;
}
unsigned long long StrlSigProc::getTotalSamples()
{
  return cycles->getTotalSamples();
}
double StrlSigProc::getCyclesPerSample()
{
    if (getTotalSamples()) return getTotalCycles()/getTotalSamples();
    else return 0;
}
double StrlSigProc::getCyclesPerSample(int m)
{
    if (getTotalSamples()) return getTotalCycles(m)/getTotalSamples();
    else return 0;
}
void StrlSigProc::addToGraph(StrlPerfGraph *g)
{
    for(unsigned int i=0;i<numberInputs;i++) {
      getUpstreamModuleN(i)->addToGraph(g);
    }
    g->add(name(),this);
}
void StrlSigProc::print_stats()
{
    //print only once
    if(num_print_stats++) return;
    //print upstream first
    for(unsigned int i=0;i<numberInputs;i++) {
      getUpstreamModuleN(i)->print_stats();
    }
    fprintf(stderr, "\n%s counts:\n",name());
    fprintf(stderr, "--------------\n");
    cycles->print_stats();
}
#endif
float StrlSigProc::memoryTouched()
{
    float f=0;
    for(unsigned int i=0;i<numberInputs;i++) {
      float uf=getUpstreamModuleN(i)->memoryTouched();
      f+=uf+getUpstreamModuleN(i)->getSamplingFrequency()*averageInputUse(i)*itype_size;
    }
    return f; //+getSamplingFrequency()*type_size*numberOutputs;
}
StrlSigProc *StrlSigProc::getUpstreamModuleN(port p)
{
  return inputConn[p]->getUpstreamModule();
} 
