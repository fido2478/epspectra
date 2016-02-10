/* -*- Mode: c++ -*-
 *
 *  Copyright 1997 Massachusetts Institute of Technology
 *  Modified  2000, 2001 INRIA 
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
