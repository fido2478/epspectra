/* -*- Mode: c++ -*-
 *
 *  Copyright 1997 Massachusetts Institute of Technology
 *  Modified 2000, 2001 INRIA
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
#include <StrlBuffer.h>
#include <StrlConnect.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#ifndef SHMMAX
//#include <asm/shmparam.h> //for SHMMAX
//from asm/shmparam.h
#define SHMMAX 0x2000000		/* max shared seg size (bytes) */
#endif /* SHMMAX */

double StrlBuffer::buffer_getSamplingFrequency() {return upstream->getSamplingFrequency();}

inline VrSampleIndex
StrlBuffer::updateMinRP()
{
  VrSampleIndex newminRP = (*connectors)->minRP();

  unsigned int i=0;
  while(++i<numberConnectors) {
    VrSampleIndex t=connectors[i]->minRP();
    if(t<newminRP) newminRP=t;
  }
  
  //It's OK that this has no mutual exclusion, since minRP
  //  is just a hint and will always eventually become correct
  //  (i.e. this->minRP <= min(connectors->minRP))
  if(newminRP > minRP) minRP = newminRP;

  return minRP;
 
}

//called from downstream module
//assumes data is there...
/*Pointer could be anywhere in either section of shared memory*/
inline char* StrlBuffer::getReadPointer(VrSampleRange r) {

#ifdef PARANOID 
  if(!upstream->dataReady(r)) {
    fprintf (stderr, "getReadPointer: trying to read data that hasn't been written.\n");
    exit(-1);
  }
  if(bufferStart==NULL) {
    //buffer never created
    fprintf(stderr,"Buffer never created -- make sure setup is run on sinks downstream from all outputs of %s\n",upstream->name());
    exit(-1);
  }
#endif

  long long offset = r.index - WPdupstart;

#ifdef PARANOID
  if(offset<- (long long) bufferSize || r.index < minRP) {
    fprintf (stderr, "StrlBuffer(%p): read VrSampleIndex too small =%lld\n", this, r.index);
    exit(-1);
  }
  if(offset+r.size > bufferSize || r.index+r.size > upstream->getMarkedWP()) {
    fprintf (stderr, "StrlBuffer(%p): read VrSampleIndex+size too large =%lld\n", this, r.index+r.size);
    exit(-1);
  }
#endif 
  return bufferDupStart+offset * type_size; 
}

//called from upstream module
/* Always writes at least part of the block to 
   "duplicate" (or 2nd) shared memory section */
inline char*
StrlBuffer::getWritePointer(VrSampleRange r) {

#ifdef THREADS
  pthread_mutex_lock(&dupstartlock);
#endif
  long long offset = r.index - WPdupstart;

  //Buffer Wrap
  while(offset+r.size > bufferSize ) {
    offset -= bufferSize;
    WPdupstart += bufferSize;
  }

#ifdef THREADS
  pthread_mutex_unlock(&dupstartlock);
#endif

#ifdef PARANOID
  if(offset < - (long long) bufferSize) {
    fprintf (stderr, "StrlBuffer(%p): WP VrSampleIndex too small =%lld offset %lld bufferSize %d dup %lld\n",
		this, r.index, offset, bufferSize, WPdupstart);
    exit(-1);
  }
#endif

  if(writespace(r.index+r.size)<0) {
    //markData should catch this
    fprintf(stderr, "StrlBuffer: Buffer full!\n");
      exit(-1);
  } 
  return bufferDupStart+offset * type_size; 
}


void
StrlBuffer::setup(unsigned int arg_type_size)
{
  if(bufferStart==NULL) {
    //buffer has not been created yet.
    allocateBuffer(arg_type_size);
    fprintf(stderr, "%s output bufferSize = %d (%f sec)\n",
	    upstream->name(), bufferSize,
	    bufferSize/upstream->getSamplingFrequency());
  } else {
    fprintf(stderr,"Topology cannot be changed after inital setup.\n");
    exit(-1);
#if 0
    //Kill this stuff
    if(requiredBufferSize() > bufferSize) {
      fprintf(stderr, "StrlBuffer: growing by %d\n",
	      requiredBufferSize()-bufferSize);
      //Note: we haven't implemented a way to copy the data from
      //the old buffer to the new one... (FIX)
      fprintf(stderr, "warning: losing data and not reseting pointers\n");
      makeBuffer();
    }
#endif
  }
}

void
StrlBuffer::connect_buffer(StrlConnect *c)
{
  StrlConnect ** cs = new (StrlConnect *[numberConnectors+1]);
  cs[numberConnectors]=c;
  if(numberConnectors>0) {
    for(unsigned int i=0;i<numberConnectors;i++)
      cs[i]=connectors[i];
    delete [] connectors;
  }
  connectors=cs;
  numberConnectors++;
  if(bufferStart!=NULL){
    fprintf(stderr,"Topology cannot be changed after inital setup.\n");
    exit(-1);
  }
}      

unsigned int
StrlBuffer::requiredBufferSize() 
{

  //BufferSizeMultiplier usually = the number of threads + 1

  unsigned int r=upstream->getMaxOutputSize();

  r *= numberConnectors; //each connector might want its own data
  r *= 2; //hack (FIX?)
  r *= BufferSizeMultiplier;
  return r;
}

void
StrlBuffer::allocateBuffer(unsigned int arg_type_size) 
{ 
  bufferSize=requiredBufferSize();
  type_size = arg_type_size;

  bufferSize_bytes = bufferSize*type_size;

  //Integral # of pages
  if((bufferSize_bytes % PAGE_SIZE) != 0) {
    bufferSize_bytes = (bufferSize_bytes/PAGE_SIZE + 1) * PAGE_SIZE;
    bufferSize = bufferSize_bytes/type_size;
  }

  //Check max size
  if(2*bufferSize_bytes > SHMMAX) {
    fprintf(stderr,"Warning: could not allocate more than %d bytes for shared memory buffer.\n",SHMMAX);
    bufferSize_bytes = SHMMAX/2;
    bufferSize = bufferSize_bytes/type_size;
  }

  //Allocate a 2N block of shared memory, then deallocate it
  //  and allocate a N block mapped twice into the same location
  //  the 2N block was mapped into.
  int shmid2 = 0;
  int shmid = 0;

  char *start = NULL;
  if((shmid2 = shmget(IPC_PRIVATE,2*bufferSize_bytes,IPC_CREAT | 0700)) == -1||
     (shmid = shmget(IPC_PRIVATE,bufferSize_bytes,IPC_CREAT | 0700)) == -1 ||
     (start  = (char *) shmat (shmid2, 0, 0)) == (char *) -1) {
    perror("Could not allocate shared memory");
    exit(-1);
    return;
  }

  shmdt((char *)start);
  shmctl(shmid2, IPC_RMID, 0);

  if(shmat (shmid, start, 0) == (char *) -1 ||
     shmat (shmid, start+bufferSize_bytes, 0) == (char *) -1) {
    perror("Could not allocate shared memory");
    exit(-1);
    return;
  }

  shmctl(shmid, IPC_RMID, 0);

  bufferStart=(char *) start;
  bufferDupStart=bufferStart+bufferSize * type_size;
  bufferEnd=bufferDupStart+bufferSize * type_size;

  //  cerr << upstream->name() <<" bufferDupStart = "<<(void *) bufferDupStart<<endl;

}

StrlBuffer:: StrlBuffer(StrlSigProc* m)   
  :bufferStart(NULL),bufferSize(0), WPdupstart(0), minRP(0),
   upstream(m),connectors(NULL),numberConnectors(0),
   setupCalled(0)
{
  if(PAGE_SIZE != getpagesize()) {
    fprintf(stderr,"The PAGE_SIZE #define is not set to the actual page size. Recompile.\n");
    exit(-1);
  }
#ifdef THREADS
  if(pthread_mutex_init(&dupstartlock, NULL)!=0) {
    fprintf(stderr, "Couldn't initialize mutex\n");
    exit(-1);
  }
#endif
}
