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

#ifndef _STRLCONNECT_H_
#define _STRLCONNECT_H_

class StrlSigProc;
class StrlBuffer;
#include<StrlBuffer.h>

class StrlConnect {
  friend class StrlBuffer;

private:
  StrlBuffer *buffer;
  StrlSigProc* ds_sigproc; 
  __volatile__ readerLL *first, *last;
  __volatile__ VrSampleIndex lastRP; 
  THREAD_DECLARE (mutex);

public: 
  void attach_reader(readerLL *r,VrSampleIndex nextBlock) {
    THREAD_LOCK;
    if(first==NULL) {
      first=r;
#ifdef PARANOID
      if(lastRP > r->index) {
	fprintf(stderr, "Out of order read threads (predicted read VrSampleIndex incorrent).\n");
	exit(-1);
      }
#endif
    } else {
      last->next=r;
#ifdef PARANOID
      if(last->index > r->index) {
	fprintf(stderr, "Out of order read threads.\n");
	exit(-1);
      }
#endif
    } 
    last=r;
    lastRP=nextBlock; //what's coming up next 
    THREAD_UNLOCK;
  }
  void detach_reader(readerLL *r) {
    THREAD_LOCK;
    if(first==r) {
      first=r->next;
      if(last==r) {
	last=NULL;
	//	lastRP=r->index;
      }
    } else {
      readerLL *t= (readerLL *) first;
      while(t->next != r) {
	t=t->next;
      }
      t->next=r->next; 
      if(last==r) {
	last = t;
	//	lastRP=r->index;
	//What will the next block from downstream ask for?
      }
    } 
    THREAD_UNLOCK;
  }

  VrSampleIndex minRP() {
    THREAD_LOCK;
    VrSampleIndex m=lastRP; 
    if(first!=NULL) {
      readerLL *t= (readerLL *) first;
      do {
	if(t->index < m) m=t->index;
      }	while((t=t->next) != NULL);
    } 
    THREAD_UNLOCK;
    return m;
  } 
  char *getReadPointer(VrSampleRange r) { return buffer->getReadPointer(r); } 
  StrlSigProc *getUpstreamModule() { return buffer->getUpstreamModule(); } 
  //Make input connector for s reading from buffer b     //     
  StrlConnect(StrlSigProc*s, StrlBuffer* b);
  double connect_getSamplingFrequency();
  virtual ~StrlConnect() {}
}; 
#endif 
