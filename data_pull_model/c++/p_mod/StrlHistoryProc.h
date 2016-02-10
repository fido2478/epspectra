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


#ifndef _STRLHISTORYPROC_H_
#define _STRLHISTORYPROC_H_

#include <StrlSigProc.h>

// StrlSigProc with history.  Set the history variable in initialize()
// to the maximum history that will ever be needed.
template<class iType, class oType> 
class StrlHistoryProc : public StrlSigProc {
protected:
  unsigned int history;

public: 
  StrlHistoryProc(int outputs) : StrlSigProc(outputs, sizeof(iType), sizeof(oType)), history(1) {}
  virtual int forecast(VrSampleRange output,
		       VrSampleRange inputs[]);
  virtual unsigned int mapSizeUp(int i, unsigned int size);
  virtual ~StrlHistoryProc() {}
};

template<class iType,class oType> int
StrlHistoryProc<iType,oType>::forecast(VrSampleRange output,
				     VrSampleRange inputs[]) {
  /* 1:1 ratio with history */
  for(unsigned int i=0;i<numberInputs;i++) {
    inputs[i].index=output.index; /* ! do not subtract history ! */
    inputs[i].size=output.size + history-1;
#ifdef DEBUG
    printf("%s (forecast): Input SampleRange[%lld, %lu]\n",name(),inputs[i].index,inputs[i].size);
#endif
  }
  return 0;
}  

template<class iType,class oType> unsigned int
StrlHistoryProc<iType,oType>::mapSizeUp(int i, unsigned int size) {
  unsigned int map_size =(unsigned int) (size *
         (getUpstreamModuleN(i)->getSamplingFrequency()
          /getSamplingFrequency())+history-1);  
  printf("%s : mapSizeUp %u \n",name(),map_size);
  return map_size;
//  return (unsigned int) (size *
//	 (getUpstreamModuleN(i)->getSamplingFrequency()
//	  /getSamplingFrequency())+history-1);
}
#endif
