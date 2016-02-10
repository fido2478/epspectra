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


#ifndef _STRLDECIMATINGSIGPROC_H_
#define _STRLDECIMATINGSIGPROC_H_

#include <StrlHistoryProc.h>

template<class iType, class oType> 
class StrlDecimatingSigProc : public StrlHistoryProc<iType,oType> {
protected:
  int decimation;
public: 
  StrlDecimatingSigProc() : decimation(1) {}
  StrlDecimatingSigProc(int outputs) : StrlHistoryProc<iType, oType>(outputs), decimation(1) {}
  StrlDecimatingSigProc(int outputs, int dec) : StrlHistoryProc<iType, oType>(outputs), decimation(dec) {}

  virtual int forecast(VrSampleRange output,
		       VrSampleRange inputs[]);
   virtual int downcast(VrSampleRange input,
		       VrSampleRange* output);
  virtual float averageInputUse(int n) {
    if(decimation>(int) history) return (float)history/(float)decimation;
    else return 1.0;
  }

  virtual unsigned int mapSizeUp(int i, unsigned int size);

  virtual int checkOutputSamplingFrequency(int sf) {
    if(sf!=getUpstreamModuleN(0)->getSamplingFrequency()/decimation) return -1;
    else return 0;}

  virtual ~StrlDecimatingSigProc() {}
};

template<class iType,class oType> int
StrlDecimatingSigProc<iType,oType>::forecast(VrSampleRange output,
					   VrSampleRange inputs[]) {
  /* dec:1 ratio with history */
  for(unsigned int i=0;i<numberInputs;i++) {
    inputs[i].index=output.index*decimation; /* ! do not subtract history ! */
    inputs[i].size=output.size*decimation + history-1;
    printf("%s (forecast): Input SampleRange[%lld, %lu]\n",name(),inputs[i].index,inputs[i].size);
  }
  return 0;
}  

template<class iType,class oType> int
StrlDecimatingSigProc<iType,oType>::downcast(VrSampleRange input,
				     VrSampleRange* output) {
  /* dec:1 ratio with history */
  output->index=input.index/decimation;/* ! do not subtract history ! */
  output->size=(input.size - history + 1)/decimation;
#ifdef DEBUG
  printf("%s (downcast):input [%lld, %lu] => output [%lld, %lu]\n",name(),input.index,input.size,output->index,output->size);
#endif
  return 0;
}  

template<class iType,class oType> unsigned int
StrlDecimatingSigProc<iType,oType>::mapSizeUp(int i, unsigned int size) {
  unsigned int map_size;

  if(size==1) {
    printf("%s : mapSizeUp %u \n",name(),history);
     return history;}
  else {
    map_size=size * decimation+history-1;
    printf("%s : mapSizeUp %u \n",name(),map_size);
    return map_size;}
}

#endif



















