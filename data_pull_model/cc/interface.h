/* This is interface.h
 * Any code associated with CLASS type in C++ must not be included 
 * in this file.
 */ 
#include <datatype.h>


/*************************************************
 * This is declaration for an overall control part.
 *************************************************/
#ifndef _INTERFACE_H
#define _INTERFACE_H

void SetEnvironment ();
/* void CreateMultiTask (); */

const char* TheNameOfSource();
const char* TheNameOfMod();
const char* TheNameOfScopesink();
const char* TheNameOfSink();
const char* TheNameOfSummer();

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
int IntermarkData(int,VrSampleRange,char*);
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

void InterCreateSource();
void InterCreateCoder();
void InterCreateMod();
void InterCreateSummer();
void InterCreateScopesink();
void InterCreateSink();

void InterInitializeScopesink();
void InterInitializeSink();
void InterConnectModules(char *r,char *s,int i);
void InterMakeTopology();


const char* InterGetSource(char *r,int y);
/*const char* InterGetSource();*/
const char* InterGetCoder(int x);
/*const char* InterGetCoder();*/
const char* InterGetMod_f(int x,float y,int z,int a,int b,int c,float d,int e);
const char* InterGetMod();
const char* InterGetSummer();
const char* InterGetScopesink_f(float a,int b,int c,int d,int e);
const char* InterGetScopesink();
const char* InterGetSink(char *r,int x);
/*const char* InterGetSink();*/
#ifdef PERFMON
void InterInitPerfGraph();
void InterGetPerfGraph(double);
#endif
VrSampleRange InterGetSampleRange(char *r);
VrSampleIndex InterGetMarkedWP(char *r);
VrSampleIndex InterGetWP(char *r);
int InterStrlmarkData(VrSampleIndex s,int req,int dm,VrSampleRange range,char *r);
char* InterForecast(VrSampleRange s, char *r);
/*mark function */
VrSampleIndex InterminrpCheck(VrSampleIndex pWP,VrSampleRange rg,char *r);
/*compute function */
int InterGet_Mywriterll(char *r);
VrSampleIndex InterGetMymarkedIndex(char *r);
unsigned long InterGetMymarkedSize(char *r);
VrSampleRange InterGetMymarkedData(char *r);
int InterCheck_MymarkedDataSize(char *r);
unsigned long InterComputeData(char *r,int x);
void InterWriteData(char *r,int dx);
/* gui */
void InterGuimain_Start(); 
void InterGuimain_Run();
/* gui */
#ifdef PERFMON
/* performonce */
void InterStartPerfGraph();
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
#endif
