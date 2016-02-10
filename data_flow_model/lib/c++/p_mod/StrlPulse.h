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


#ifndef _STRLPULSE_H_
#define _STRLPULSE_H_

#include <StrlDecimatingSigProc.h>
#include <StrlComplex.h>

template<class iType, class oType> 
class StrlPulse : public StrlDecimatingSigProc<iType,oType> {
protected:
public: 
  StrlPulse() : StrlDecimatingSigProc<iType, oType>() {}
  StrlPulse(int outputs) : StrlDecimatingSigProc<iType, oType>(outputs) {}
  StrlPulse(int outputs, int dec) : StrlDecimatingSigProc<iType, oType>(outputs, dec) {}
  virtual ~StrlPulse() {}
  virtual float getSymbol_Period() = 0;
  virtual int setSymbol_Period(float) = 0;
  virtual int setSymbol_Timing(float) = 0;
  virtual void start_oversampling(int, int,int,StrlComplex*,int*) = 0;
  virtual int version() = 0;
};
#endif
