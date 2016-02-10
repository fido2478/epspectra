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

#ifndef _STRLBUFFER_H_
#define _STRLBUFFER_H_

#include "StrlTypes.h"

extern int BufferSizeMultiplier;
class StrlConnect;
class StrlSigProc;
class StrlBuffer {
protected:
  char* bufferStart;     //beginning of unique, aligned 
  //duplicate start = end of unique + 1 = start + bufferSize
  char* bufferDupStart; 
  char* bufferEnd;       //end of entire buffer(+1) = bufferDupStart+bufferSize 
  unsigned int bufferSize;    // = bufferDupStart - bufferStart
  unsigned int bufferSize_bytes; //above * sizeOf(T)
  unsigned int type_size; // size of 1 unit of data 
  VrSampleIndex WPdupstart; //VrSampleIndex at bufferDupStart
  THREAD_DECLARE(dupstartlock);
  VrSampleIndex minRP;	//hint; <= min_i(connectors[i]->minRP) -- updated rarely
  StrlSigProc* upstream; //who writes to this buffer 
  StrlConnect ** connectors;   //who reads from this buffer
  unsigned int numberConnectors;      //how many of above
  unsigned int setupCalled; //count of how many setup requests we've received 
  unsigned int requiredBufferSize();
  virtual void allocateBuffer(unsigned int arg_type_size); 

public: 
  unsigned int buffersize() { return bufferSize; };
  unsigned int getNumberConnectors() { return numberConnectors; }
  // Add c as a reader of this buffer
  void connect_buffer(StrlConnect *c);
  double buffer_getSamplingFrequency();
  StrlSigProc* getUpstreamModule() {return upstream;} 
  //Called once from upstream module
  void setup(unsigned int arg_type_size);
  //recompute the hint minRP
  VrSampleIndex updateMinRP();

  //returns how much space will be left if the write pointer is updated to WP
  //  if >0, write can proceed
  int writespace(VrSampleIndex WP) {
    int s = bufferSize - (WP - minRP);
    if(s > 0) return s;
    else {
      updateMinRP();
      return bufferSize - (WP - minRP);
    }
  }
  //called from the upstream StrlSigProc (in prepareRead)
  char *getWritePointer(VrSampleRange r);
  //called from a downstream StrlSigProc, via StrlConnect
  virtual char *getReadPointer(VrSampleRange r);
  StrlBuffer(StrlSigProc *m); 
  virtual ~StrlBuffer() { };
};

#define PAGE_SIZE getpagesize()
#endif
