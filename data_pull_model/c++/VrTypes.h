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

#ifndef _VRTYPES_H_
#define _VRTYPES_H_

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#ifdef THREADS
#include<pthread.h>
#endif
}
#include <VrComplex.h>
#include <VrCycleCount.h>
#include <iostream.h>

class VrSigProc;
#ifdef THREADS
#define THREAD_DECLARE(A) pthread_mutex_t A;
#define THREAD_LOCK		pthread_mutex_lock(&mutex)
#define THREAD_UNLOCK	pthread_mutex_unlock(&mutex)
#define THREAD_GETSPECIFIC(A)	pthread_getspecific(A)
extern pthread_key_t startMarkedModule;
//#define YIELD() {sched_yield();}
#define YIELD() {usleep(1);}
#else
#define THREAD_DECLARE(A)
#define THREAD_LOCK		{}
#define THREAD_UNLOCK	{}
#define THREAD_GETSPECIFIC(A)	(A)
//extern StrlSigProc *startMarkedModule;
//extern VrSigProc *startMarkedModule;
#define YIELD() {usleep(1);}
#endif

typedef unsigned int port;

enum {VR_NULL,VR_CHAR,VR_UCHAR,VR_SHORT,VR_INT,VR_FLOAT,VR_COMPLEX,
      VR_FRAME,VR_IPPACKET};

class VrNullData {
  int tmp;
public:
  VrNullData() {}
  VrNullData(int x) :tmp(x) {}
};

typedef char bit;
typedef VrComplex complex;
typedef unsigned char uchar;
typedef unsigned long long VrSampleIndex;
typedef struct {
	VrSampleIndex index;
	unsigned long size;
} VrSampleRange; 

inline int is_complex(VrComplex x) { return 1;}
inline int is_complex(float x) { return 0;}
inline int is_complex(double x) { return 0;}
inline int is_complex(int x) { return 0;}
inline int is_complex(char x) { return 0;}
inline int is_complex(short x) { return 0;}
#endif
