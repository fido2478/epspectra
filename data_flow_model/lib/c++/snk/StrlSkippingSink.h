/*  Modified 2000, 2001 INRIA */

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


#ifndef _STRLSKIPPINGSINK_H_
#define _STRLSKIPPINGSINK_H_

#include <StrlSink.h>
#include <stdio.h>

//This sink uses a history-size chunk of data every increment units of data
//  (i.e. skips over increment-history units of data)
//  Each unit requested from the sink's work() procecure will operation
//  on a _block_ (history-size) of data.
template<class iType> 
class StrlSkippingSink : public StrlSink<iType> {
protected:
  unsigned int history;
  unsigned int increment;
public: 

  StrlSkippingSink() : history(1) {
    setOptimalSize(1);/*forces size of 1 to allow skipping*/}

  virtual void setup () {
	if (increment <= 0) {
		fprintf (stderr, "[%s:%d] setup() invalid value for increment=%d\n", __FILE__, __LINE__, increment);
		exit(-1);
	}
    setSamplingFrequency(getUpstreamModuleN(0)->getSamplingFrequency()/increment);
    StrlSink<iType>::setup();
  }

  virtual int forecast(VrSampleRange output,
		       VrSampleRange inputs[]);

  virtual int downcast(VrSampleRange input,
		       VrSampleRange* output);

  virtual float averageInputUse(int n) {
    if(increment>history) return (float) history/(float) increment;
    else return 1.0;
  }

  virtual unsigned int mapSizeUp(int i, unsigned int size) {
    return (unsigned int) (size * averageInputUse(i) *
	   (getUpstreamModuleN(i)->getSamplingFrequency()
	    /getSamplingFrequency()));
  }

  virtual ~StrlSkippingSink() {}
};

template<class iType> int
StrlSkippingSink<iType>::forecast(VrSampleRange output,
				VrSampleRange inputs[]) {
  /* 1:history with increment skipping */
  /* size should always be 1 */
  if(output.size>1) {
    return -1;
  }

  for(unsigned int i=0;i<numberInputs;i++) {
    inputs[i].index=output.index*increment; /* ! do not subtract history ! */
    inputs[i].size=history;
  }
  return 0;
}  

template<class iType> int
StrlSkippingSink<iType>::downcast(VrSampleRange input,
				     VrSampleRange* output) {
  /* 1:history with increment skipping */
  /* size should always be 1 */
  if(output->size>1) {
    return -1;
  }
  output->index=input.index/increment;
  output->size=1;
  return 0;
}    

#endif



















