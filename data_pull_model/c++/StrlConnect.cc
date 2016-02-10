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

#include<StrlSigProc.h>
#include<StrlConnect.h>

StrlConnect::StrlConnect(StrlSigProc*s, StrlBuffer* b) : buffer(b), ds_sigproc(s), 
    first(NULL), last(NULL), lastRP(0) {
#ifdef THREADS
  if(pthread_mutex_init(&mutex, NULL)!=0) {
    fprintf(stderr, "Couldn't initialize mutex\n");
    exit(-1);
  }
#endif
    buffer->connect_buffer(this);
  } 
double StrlConnect::connect_getSamplingFrequency() {return buffer->buffer_getSamplingFrequency();}
