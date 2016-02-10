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

#ifndef _STRLSOURCE_H_
#define _STRLSOURCE_H_

#include <StrlSigProc.h>

template<class oType> 
class StrlSource : public StrlSigProc {
public:
  StrlSource():StrlSigProc(1, 0, sizeof(oType)) {};
  virtual int forecast(VrSampleRange output,
			VrSampleRange *inputs) {
    fprintf(stderr, "StrlSource: forecast should never be called.\n");
    exit(-1);
    return -1;
  };
  virtual int downcast(VrSampleRange input,
			VrSampleRange* output) {
    fprintf(stderr, "StrlSource: forecast should never be called.\n");
    exit(-1);
    return -1;
  };
  virtual const char *name() { return "StrlSource"; }

  virtual int work(VrSampleRange output, void *o[],
		    VrSampleRange inputs[], void *i[]) {
    return work(output, o);
  };
  virtual int work(VrSampleRange output, void *o[])=0;
  virtual int isConnectedToSource() {return 1;}
}; 
#endif 
