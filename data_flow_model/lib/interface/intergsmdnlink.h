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
/* void CreateMultiTask (); */

const char* TheNameOfSource();
const char* TheNameOfIL();
const char* TheNameOfCC();
const char* TheNameOfDIL();
const char* TheNameOfSink();

/*
void AddSink();
void AddScopeSink();
void StartSink();
*/

/* For MyMultiTask function */
/*
void InterAdd(char);
void InterStart();
int InterGetnumberSinks();
int InterGetnumSinks();
*/
/* VrSampleIndex IntergetMarkedWP(int); */
/*
unsigned int IntergetMaxOutputSize(int);
float IntergetSamplingFrequency(int);
int IntermarkData(int,VrSampleRange);
void Intercompute();
void Interyield();
*/
/* void MTprocess(); */

/* function for monitoring */
/* VrSampleRange *getSRange(); */
int InterGetMarkValue();
VrSampleRange InterGetSmplRange();

/*int CcGetComputeValue();*/

/* For INITIALIZE module */
int GetNumberofSinks();
int GetNumberofGoodSinks(); 

/* create module & trigger */
void InterInitializeSink();
void InterConnectModules(char *r,char *s,int i,int j);
void InterMakeTopology();

const char* InterGetDNSource(char *r,int y);
const char* InterGetSC();
const char* InterGetIL();
const char* InterGetChCoder();
const char* InterGetCipher();
const char* InterGetDNSink(char *r, int x);
const char* InterGetDNFileSink(char *r);

unsigned int InterGetMaxOutSize(char *r);
VrSampleRange InterGetSampleRange(char *r);
VrSampleIndex InterGetMarkedWP(char *r);
VrSampleIndex InterGetWP(char *r);
int InterStrlmarkData(VrSampleIndex s,int req,int dm,VrSampleRange range,char *r);
int InterStrlFitRange(VrSampleIndex,int,VrSampleRange,char*);
char* InterForecast(VrSampleRange s, char *r);
char* InterDowncast(VrSampleRange s, char *r);
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
