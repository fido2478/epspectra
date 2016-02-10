/*
 * Copyright 2000, 2001 INRIA
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of INRIA not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.
 */


/* This is interface.h
 * Any code associated with CLASS type in C++ must not be included 
 * in this file.
 */ 
#include "../include/datatype.h"

/*************************************************
 * This is declaration for an overall control part.
 *************************************************/
#ifndef _INTERFACE_H
#define _INTERFACE_H

void SetEnvironment ();
/* VrSampleRange *getSRange(); */
int InterGetMarkValue();
VrSampleRange InterGetSmplRange();

/* For INITIALIZE module */
int GetNumberofSinks();
int GetNumberofGoodSinks(); 

/* create module & trigger */
void InterInitializeSink();
void InterConnectModules(char *r,char *s,int i,int j);
void InterMakeTopology();
const char* InterGetUDPSource(int y);
const char* InterGetFileSource(char *r,int y);
const char* InterGetFileSource4up(char *r,int y);
const char* InterGetSpeechCoder();
const char* InterGetChannelCoder();
const char* InterGetInterleaver();
const char* InterGetCipher();
const char* InterGetModulator();
const char* InterGetDemodulator();
const char* InterGetDecipher();
const char* InterGetDeinterleaver();
const char* InterGetChannelDecoder();
const char* InterGetSpeechDecoder();
const char* InterGetAudioSink();
const char* InterGetUDPSink(char* r,int y);
const char* InterGetFileSink(char*);
const char* InterGetFileSink4up(char*);

unsigned int InterGetMaxOutSize(char *r);
VrSampleRange InterGetSampleRange(char *r);
VrSampleIndex InterGetMarkedWP(char *r);
VrSampleIndex InterGetWP(char *r);
int InterStrlmarkData(VrSampleIndex s,int req,int dm,VrSampleRange range,char *r);
int InterStrlFitRange(VrSampleIndex,int,VrSampleRange,char*);
VrSampleRange InterForecast(VrSampleRange s, char *r);
VrSampleRange InterDowncast(VrSampleRange s, char *r);
void InterForecastNew(char*,VrSampleRange s, char *r);
void InterDowncastNew(char*,VrSampleRange s, char *r);
/*compute function */
int InterGet_Mywriterll(char *r);
VrSampleIndex InterGetMymarkedIndex(char *r);
unsigned long InterGetMymarkedSize(char *r);
VrSampleRange InterGetMymarkedData(char *r);
int InterCheck_MymarkedDataSize(char *r);
unsigned long InterDFComputeData(char *r,int x);
void InterWriteData(char *r,int dx);
char* InterComputeForMainSink(char *r);
VrSampleRange* InterFitRangeForMainSink(VrSampleRange s, char *r);
void InterGuimain_Start();
void InterGuimain_Run();
#ifdef PERFMON
/* performonce */
void InterStarPerfGraph();
void InterStopPerfGraph();
void InterInitPerfGraph();
void InterGetPerfGraph(double sec);
void InterGlobalAwaitTSTARTcount();
void InterGlobalAwaitTSTOPcount();
void InterLocalAwaitTSTARTcount(char *ch);
void InterLocalAwaitTSTOPcount(char *ch);
void InterLocalIncAwaitTick(char *ch);
void InterGlobalIncAwaitTick();
#endif
/* scheduling */
float InterGetFrequency(char *r);
void InterSaveSkippedDataSize (int size);
#endif
