/*  Modified  2000, 2001 INRIA */

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


#ifndef _StrlINTERPOLATINGSIGPROC_H_
#define _StrlINTERPOLATINGSIGPROC_H_

#include <StrlHistoryProc.h>

template<class iType, class oType> 
class StrlInterpolatingSigProc : public StrlHistoryProc<iType,oType> {
protected:
  int interp;
public: 
  virtual int forecast(VrSampleRange output, VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input, VrSampleRange* output);
  StrlInterpolatingSigProc() : interp(1) {}
  StrlInterpolatingSigProc(int outputs) : StrlHistoryProc<iType, oType>(outputs), interp(1) {}
  StrlInterpolatingSigProc(int outputs, int i) : StrlHistoryProc<iType, oType>(outputs), interp(i) {}
  virtual ~StrlInterpolatingSigProc() {}
};

template<class iType,class oType> int
StrlInterpolatingSigProc<iType,oType>::forecast(VrSampleRange output, VrSampleRange inputs[]) {
  /* 1:interp ratio */
/*
 * Note that this code only works correctly if output size of the
 * module (set using setOutputSize(n) in initialize() ) is a multiple
 * of interp.
 */
#ifdef _DEBUG
  printf("Interpolating... interpolation %d , history %d\n",interp, history);
#endif
  for(unsigned int i=0;i<numberInputs;i++) {
    inputs[i].index=output.index/interp; /* ! do not subtract history ! */
    inputs[i].size=output.size/interp + history-1;
#ifdef DEBUG
    printf("%s (forecast): output [%lld, %lu] => input [%lld, %lu]\n",name(),output.index, output.size, inputs[i].index,inputs[i].size);
#endif
  }
  return 0;
}

  template<class iType,class oType> int
StrlInterpolatingSigProc<iType,oType>::downcast(VrSampleRange input, VrSampleRange* output) {
  /* interp:1 ratio */
/*
 * Note that this code only works correctly if output size of the
 * module (set using setOutputSize(n) in initialize() ) is a multiple
 * of interp.
 */
#ifdef _DEBUG
  printf("Interpolating... interpolation %d , history %d\n",interp, history);
#endif
  output->index=input.index*interp; /* ! do not subtract history ! */
  output->size=(input.size - history+1)*interp;
#ifdef DEBUG
  printf("%s (downcast): input[%lld, %lu] => output [%lld, %lu]\n",name(),input.index, input.size, output->index,output->size);
#endif
  return 0;
}
#endif
