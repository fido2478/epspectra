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

#ifndef _STRLSINK_H_
#define _STRLSINK_H_

#include <StrlSigProc.h>

template<class iType> 
class StrlSink : public StrlSigProc {
private:
  unsigned int optimalSize;
  VrSampleIndex nextSinkTS;
  struct timeval initialTime; 

public: 
  virtual const char *name() { return "StrlSink"; }
  //set this if you want the sink to use smaller chunks
  //  than the maxLatency would dictate
  void setOptimalSize(unsigned int s) { optimalSize = s;} 
  /* brettv 6/29 ignore written data
  //don't override this in sinks
  virtual float memoryTouched() {
    return StrlSigProc::memoryTouched()+getSamplingFrequency()*memoryTouchedPerOutput(1, sizeof(iType));
  }

  //how many _bytes_ the sink writes on average per "unit output"
  //(i.e. VrSampleIndex of (imaginary) output NOT input)
  //override this is your sink doesn't just read each input once
  virtual float memoryTouchedPerOutput() {
    //default: touch as many inputs as we used
    float f=0;
    for(unsigned int i=0;i<numberInputs;i++)
      f+=getUpstreamModuleN(i)->getSamplingFrequency()*averageInputUse(i)*sizeof(iType)/getSamplingFrequency();
    return f;
  }
  */

  virtual void setup();
  void setup_upstream(); 
  virtual void start();  
  virtual void process();  
  virtual void stop(); 
  virtual int work(VrSampleRange output, void *o[],
		   VrSampleRange inputs[], void *i[]) {
    return work(output, inputs, i);
  };
  virtual int work(VrSampleRange output, 
		   VrSampleRange inputs[], void *i[]) = 0; 
  StrlSink() :StrlSigProc(0, sizeof(iType), 0),optimalSize(0x70000000),
    nextSinkTS(0) { }
  void startTimer() {
    if (gettimeofday(&initialTime, 0) < 0) {
      perror("StrlSigProc: gettimeofday failed!!!");
      exit(1);
    }
  } 
  double elapsedTime() {
    unsigned long usecs;
    struct timeval t2; 
    if (gettimeofday(&t2, 0) < 0) {
      perror("StrlSigProc: gettimeofday failed!!!");
      exit(1);
    } 
    usecs = (t2.tv_sec - initialTime.tv_sec)*1000000 + 
      (t2.tv_usec - initialTime.tv_usec);
    return usecs/1000000.0;
  }
};

template <class iType> void
StrlSink<iType>::setup()
{
  //output sampling frequency (related to how fast "samples" requested
  //  by start_samples() are "prodcued") default to 1st connectors 
  //  frequency, but sinks can set this in initialize() if necessary
  if(getSamplingFrequency()==0.0)
    setSamplingFrequency(getInputSamplingFrequencyN(0));
  StrlSink<iType>::setup_upstream();
}

template <class iType> void
StrlSink<iType>::setup_upstream()
{
  float m = memoryTouched(); //returns memory accesses / second of chain

  //Compute a globally optimal size to run on for the whole chain
  //(every input and output stays in cache for enitre length of chain)
  unsigned int cachedSize = (int) (cacheSize * (getSamplingFrequency() / m));

  fprintf(stderr,"%s cachedSize = %d\n",name(),cachedSize);
  if(cachedSize/getSamplingFrequency() > maxLatency) {
    fprintf(stderr,"   reducing latency from %f",cachedSize/getSamplingFrequency());
    cachedSize = (unsigned int) (getSamplingFrequency() * maxLatency);
    fprintf(stderr," to %f seconds\n",cachedSize/getSamplingFrequency());
  }
  if(optimalSize < cachedSize) {
    fprintf(stderr,"   manually specified optimalSize of %d (%f sec)\n",optimalSize,optimalSize/getSamplingFrequency());
    cachedSize=optimalSize;
  }
  //round down
  if((cachedSize % getOutputSize()) != 0) {
    cachedSize = (cachedSize/getOutputSize()) * getOutputSize();
  }
  if(cachedSize==0) cachedSize=getOutputSize(); 
  maxDSReadSize=optimalSize=cachedSize;
  StrlSigProc::setup_upstream(); 
}

template <class iType> void
StrlSink<iType>::start() { 
  startTimer(); 
  process(); 
}

template <class iType> void
StrlSink<iType>::process() {
}

template <class iType> void
StrlSink<iType>::stop() {
  //stopTimer();
}
#endif

