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

#ifndef _STRLSIGPROC_H_
#define _STRLSIGPROC_H_

#include <StrlTypes.h>
//#include <VrTypes.h>
#include <StrlPerfGraph.h>

extern unsigned int cacheSize;
extern float maxLatency;
class StrlBuffer;
class StrlConnect;
//class StrlMultiTask;

typedef struct writerLL {
  //everything from current thread's desiredWP to maxValid is valid
  VrSampleIndex maxValid;
  struct writerLL *next;
};

typedef struct readerLL {
  VrSampleIndex index;
  struct readerLL *next;
};

class StrlSigProc {
  //friend class StrlMultiTask;

private:
  /***********************************************************/
  /*** "Internal" methods -- only called from core modules ***/
  /***********************************************************/
  // Return 1 if all upstream inputs are fully connected
  // to sources (i.e. work is ready to be run)
  /*** Output Buffers ***/
  int uses_sync; 
  float proc_samplingFrequency;
  __volatile__ VrSampleIndex WP; //data before this has been written 
  //data before this has been marked and will be written
  __volatile__ VrSampleIndex markedWP; 
  //maximum size that we should ever output at once
  //  due to cache size and latency contraints
  //  may actually output anywhere < 2*maxOutSize
  //  to prevent unnecessarily small chunks from being marked
  unsigned int maxOutSize; 
  /*** Performance monitoring data ***/
#ifdef PERFMON
protected:
  StrlCycleCount *cycles;
private:
#endif
  /*** Input Connectors ***/
  StrlConnect ** inputConn;
  unsigned int setupCalled;
  unsigned int outputSize; 
  unsigned int type_size;
  unsigned int itype_size;
  unsigned int initializeCalled;
  //Granularity output can be produced in, for performance or other reasons.
  void updateMinRP();
#ifdef THREADS
  pthread_key_t myMarkedData; //pointer to VrSampleRange
  pthread_key_t inputs_forecasted; //array of VrSampleRange
  pthread_key_t myWriterLL; //pointer to writerLL
  pthread_key_t myReaderLLs; //array of readerLLs
#else
  VrSampleRange myMarkedData;
  VrSampleRange *inputs_forecasted;
  writerLL *myWriterLL;
  readerLL *myReaderLLs; //array of size numberInputs
#endif

  /* Linked list of writing threads */
  /*   each writerLL structure indicated where the thread started writing */
  __volatile__ writerLL *first, *last;
  THREAD_DECLARE(mutex);
  void attach_writer(writerLL *r);
  void detach_writer(writerLL *r);
  virtual void initialize() {}; 
  //returns the total number of bytes accessed (read or written)
  //  per second by the upstream chain ending with this module
  //  zero has a special meaning (no outputs in cache)
  int minwritespace(VrSampleIndex newWP, unsigned int desired); 
  //These work best in the constructor, but will work
  //  in initialize if the SigProc has ONLY ONE output buffer
  void initOutputBuffers(int n);
  virtual void initOutputBuffer(int n); //create a particular buffer
  void initMarkedData();
  virtual unsigned int mapSizeUp(int i, unsigned int size);
  //is data marked to be computed?
  virtual int dataMarked(VrSampleRange r); 
  //figure out which data to compute
  virtual int markData(VrSampleRange r){}
  //compute the marked data

protected: //the guppi stuff needs this (FIX)
  StrlBuffer** outBuffer;
  //how big a read we might get.  maxOutSize should never exceed this
  unsigned int maxDSReadSize; 
  unsigned int numberInputs;
  unsigned int numberOutputs; 
  virtual StrlSigProc *getUpstreamModuleN(port p);
  double getInputSamplingFrequencyN(port p);
  void setup_upstream();
  void setOutputSize(int o) { outputSize=o; }
  int getNumberInputs() {return numberInputs;}
  //Call is_synced(index) from forecast(...) to see if forecast is
  //  being called on the current output block (return value==1)
  //  or a future outptu block (return value==0)
  int is_synced(VrSampleIndex index) {
    if(WP >= index)
       return 1;
    return 0;
  }
  //Call sync(index) from work(...) to ensure the rest of the procedure runs
  //  sequentially...
  void sync(VrSampleIndex index) {
    uses_sync=1; 
#ifdef PARANOID
    if(WP > index) {
      fprintf(stderr, "out of order update to WP\n");
      exit(-1);
    }
#endif 
    //wait for us to be first writer
    while(!is_synced(index)) {
#ifdef THREADS
#ifdef PERFMON
      cycles->blockOnSync++;
#endif
      sched_yield();
#else
      fprintf(stderr, "Sync() waiting for another thread to write when we aren't using threads!\n");
      exit(-1);
#endif
    }
  }
  VrSampleIndex proc_minRP();

public:
  VrSampleIndex minrpCheck(VrSampleIndex pendingWP,VrSampleRange r);
  void StrlWriteData(int);
  VrSampleIndex getMymarkedIndex(){return myMarkedData.index;}
  void Set_MarkedWP(VrSampleIndex lg);
  unsigned long GetMymarkedSize(){return myMarkedData.size;}
  unsigned long StrlWork(int x);
  int Get_Mywriterll() {if(!myWriterLL) return 0;return 1;}
  int Check_MymarkedDataSize(){ if(myMarkedData.size==0) return 0;return 1;}
  virtual int compute(){} 
  int StrlmarkData(VrSampleIndex pendingWP, int requestSize,int dataMarkedUpstream,VrSampleRange testrange); 
  void init_base();
  virtual int isConnectedToSource();
  StrlSigProc(int mode, unsigned int arg_itype_size, unsigned int arg_type_size);
  virtual ~StrlSigProc();
  int connect_proc(StrlSigProc* c, port p, unsigned int sf); //connects next input to an upstream buffer
  /*******************************************************************/
  /*** Methods you should override in processing modules ***/
  /*******************************************************************/
  // default name for a module (override with actual name)
  virtual const char *name() { return "StrlSigProc"; }
  //Define this function to map an output range
  //  to ranges required on each input connector, inputs[x]
  //  0=OK results and -1=don't know what I need yet
  virtual int forecast(VrSampleRange output, VrSampleRange inputs[]); 
  //returns the total number of bytes read (ignores written bytes)
  //  per second by the upstream chain ending with this module
  //  zero has a special meaning (no outputs in cache)
  virtual float memoryTouched(); 
  //Generate up to output.size output points at o[output#][sample#]
  //  using data at the inputptrs[input#][sample#]
  //  Pointer start at corresponding VrSampleIndex in the range params.
  //  output.size is a multiple of outputSize
  //  returns the number of outputs (<= output.size) that it was
  //  able to compute with the given input ranges.  If this value
  //  is < output.size, forecast() will need to be called again.
  virtual int work(VrSampleRange output, void *o[],
		   VrSampleRange inputs[], void *i[]) = 0; 
  // initialize internal structures, etc.
  //what fraction of the input samples (from input n) does this module look
  //at? 1.0=all 0.0=none <1.0=some fraction
  // >1.0 -- very very rare, means looks at proportionally more
  //         data (e.g. always twice the input data) --
  //         this isn't taps or any constant extra data
  virtual float averageInputUse(int n) {return 1.0;} 
  virtual int checkOutputSamplingFrequency(float) { return 0;} 
  /**********************************************************/
  /*** "External" methods -- call from out-of-band script ***/
  /**********************************************************/
  virtual int setSamplingFrequency(double sf); 
  //has data already been computed?
  virtual int dataReady(VrSampleRange r); 
  virtual void size_setup(unsigned int size);
  virtual void setup();
  VrSampleIndex getMarkedWP() {return markedWP;}
  VrSampleIndex getWP() {return WP;}
  unsigned int getOutputSize() {return outputSize;}
  unsigned int getnumberInputs() {return numberInputs;}
#ifdef PERFMON
  /*** Performance monitoring procedures ***/
  unsigned int num_print_stats;
  double getTotalCycles();
  double getTotalCycles(int m);
  double getTotalCyclesMS();//for MainSink
  double getCyclesPerSampleMS();//for MainSink
  unsigned long long getTotalSamples();
  double getCyclesPerSample();
  double getCyclesPerSample(int m);
  void addToGraph(StrlPerfGraph *g);
  void print_stats();
  void startAwaitTickCount() {cycles->startAwaitTCount();}
  void stopAwaitTickCount() {cycles->stopAwaitTCount();}
  void incNumberAwaitTick(){cycles->increaseNumTick();}
  double getAwaitTickCycles() {return cycles->getAwaitTCycles();}
  unsigned long long getNumerAwaitTick(){return cycles->getNumAwaitTick();}
#endif
  unsigned int getMaxOutputSize() {return maxOutSize;}
  float getSamplingFrequency() { return proc_samplingFrequency; }
  virtual int callback(int attribute_number, float value) { return 0; }
};

//Macro to connect_proc (next) input of a to (1st) output of B
#define CONNECTN(a, b, n, sf, bps) a->connect_proc(b, n, sf)
#define CONNECT(a, b, sf, bps) CONNECTN(a, b, 0, sf, bps)
#endif

#ifndef THREADS
extern StrlSigProc *startMarkedModule;
#endif
