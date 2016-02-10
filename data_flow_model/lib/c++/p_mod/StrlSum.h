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

#ifndef _STRLSUM_H_
#define _STRLSUM_H_

#include <StrlSigProc.h>
#if defined (ENABLE_MMX)
#include <StrlMMX.h>
#endif

template<class iType,class oType> 
class StrlSum : public StrlSigProc {
protected:
#if defined (ENABLE_MMX)
  char mmxReady;
#endif  
public: 
  virtual const char *name() { return "StrlSum"; }
  virtual int work(VrSampleRange output, void *o[],
		   VrSampleRange inputs[], void *i[]);
  virtual void initialize() {
#if 0
    //work on 8-units blocks
    setHistory(8);
    setOutputSize(8);
#endif
	printf("%s has nothing to intialize\n",name());
//	cout<<"In the "<<name()<<"nothing initialized"<<endl;
  };
  StrlSum();
};

template<class iType,class oType> int
StrlSum<iType,oType>::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  iType **i = (iType **)ai;
  oType **o = (oType **)ao;
  int size = output.size;
  int ni = getNumberInputs();
  oType temp;

  while(size-- > 0) {
#if 0
    int units = availableUnits();
    if(availableSpace() < units ) units = availableSpace();
    if (n < units) units = n;

#ifdef XENABLE_MMX
    if(mmxReady && getNumberInputs()>1) {
      units=units-units%8;
#ifdef PARANOID
      if(units <= 0){
        fprintf(stderr, "Can't write any data in StrlSum\n");
        exit(1);
      }
#endif
      mmxAdd(inputHistoryPtrN(0), inputHistoryPtrN(1),
             units, outputWritePtr());
      incReadPtrN(0,units);
      incReadPtrN(1,units);
      int jj=2;
      while(jj < getNumberInputs()){
        mmxAdd(outputWritePtr(), inputHistoryPtrN(jj),
               units, outputWritePtr());
      incReadPtrN(jj,units);
      jj++;
      }

    } else
#endif
#endif
    {
        temp = *i[0]++;
        int j=1;
        while(j < ni)
          temp += *i[j++]++;
        *o[0]++ = temp;
    }
#ifdef COMP_VAL
    printf(" out %x ",temp);
#endif
//  printf("%s (work) : size %d\n",name(),size);
  }
#ifdef DEBUG
  printf("%s (work) : output SRange [%lld, %lu]\n",name(),output.index,output.size);
  printf("%s (work) return : %lu (output.size)\n",name(),output.size);  
#endif
  return output.size;
}

template<class iType,class oType> 
StrlSum<iType,oType>::StrlSum()
  : StrlSigProc(1, sizeof(iType), sizeof(oType))
{
#ifdef ENABLE_MMX
  mmxReady=queryMMX();
#endif
}
#endif
