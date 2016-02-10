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

/********************************************
* This is * intergsm.cc *
*********************************************/
#include <iostream.h>
#include <string.h>
#include <StrlSigProc.h>

#include <StrlFileSource.h>

#include <StrlUDPSource.h>
//#include <StrlGsmUPSource.h>
#include <StrlGsmSpeechDecoder.h>
#include <StrlGsmChannelDecoder.h>
#include <StrlGsmDecipher.h>
#include <StrlGsmDeInterleaver.h>
#include <StrlFileSink.h>
//#include <StrlGsmUPSink.h>
#ifdef PERFMON
#include <StrlPerfGraph.h>
#endif
/**************************************************************
 * StrlMultiTask class is redefined for the implementation of 
 * Control part of SPECtRA system in ESTEREL
 * it is at pspectra/cc/i386/lib/vr/.
 **************************************************************/
#include <StrlTypes.h>

#define GUI_FLAG 0
unsigned long long SkippedSampleSize=0;
unsigned long NumofSSS=0;
int BufferSizeMultiplier=2; /* = numberSinks +1 */
int process_one = 1;
int persistent = 0;
int run = 1;

//#define UPSRC_TYPE StrlUDPSource<char>
#define UPSRC_TYPE StrlFileSource<char>
//#define UPSRC_TYPE StrlGsmUPSource<char>
#define SPD_TYPE StrlGsmSpeechDecoder
#define DIL_TYPE StrlGsmDeInterleaver
#define CHD_TYPE StrlGsmChannelDecoder
#define DCIP_TYPE StrlGsmDecipher
//#define UPSNK_TYPE StrlGsmUPSink<char>
#define UPSNK_TYPE StrlFileSink<char>

UPSRC_TYPE *upsource;
DIL_TYPE *dil;
CHD_TYPE *chd;
SPD_TYPE *spd;
DCIP_TYPE *dcip;
UPSNK_TYPE *upsink;


#if (GUI_FLAG)
/*****  GUI begin ********/ 
#include "VrGUI.h"
/*****  GUI end ******/
#endif

#define STRLEN 80
/*********************************
 * define variables
 *********************************/
#ifdef PERFMON
StrlPerfGraph *perfgraph;
#endif

extern "C" {  /* begin extern "C" */

  /***********************************************
   * This is the definition of function and varialbe
   * for the Real Control part.
   ***********************************************/
#if (GUI_FLAG)
/**** GUI begin ******/
void InterGuimain_Start()
{
  guimain->start();
}

void InterGuimain_Run()
{
  guimain->processEvents(10);
}
/***** GUI end *********/
#endif
/**********************************
 * Create modules
 **********************************/
/*
const char* InterGetUPSource(int y)
{
  upsource = new StrlUDPSource<char>(y);
  //  upsource = new StrlGsmUPSource<char>(y);
  return upsource->name();
}
*/
const char* InterGetUPFileSource(char *r, int y)
{
  upsource = new StrlFileSource<char>(r,y);
  //  upsource = new StrlGsmUPSource<char>(y);
  return upsource->name();
}
const char* InterGetDIL()
{
  dil = new StrlGsmDeInterleaver;
  return dil->name();
}
const char* InterGetChDecoder()
{
  chd = new StrlGsmChannelDecoder;
  return chd->name();
}
const char* InterGetDecipher()
{
  dcip = new StrlGsmDecipher;
  return dcip->name();
}
const char* InterGetSD()
{
  spd = new StrlGsmSpeechDecoder;
  return spd->name();
}
const char* InterGetUPSink(char *r)
{
  upsink=new StrlFileSink<char>(r);
  //  upsink=new StrlGsmUPSink<char>(r);
  return upsink->name();
}

/*
const char* InterGetSummer()
{
  summer =new SUMMER_TYPE SUMMER_PARAMETER;
  return summer->name();
}

const char* InterGetScopesink()
{
  scopesink = new SCOPESINK_TYPE SCOPESINK_PARAMETER;
  scopesink->setSkip(1,0);
  return scopesink->name();
}
*/

StrlSigProc *GetObject(char *r)
{
  if (upsource!=NULL)
    if (!strcmp(r,upsource->name()))
      return upsource;
  if (dcip !=NULL) 
    if(!strcmp(r, dcip->name()))
      return dcip;
  if (dil !=NULL) 
    if( !strcmp(r, dil->name()))
      return dil;
  if (chd !=NULL) 
    if(!strcmp(r, chd->name()))
      return chd;
  if (spd !=NULL)
    if(!strcmp(r, spd->name()))
      return spd;
  if (upsink !=NULL)
    if(!strcmp(r, upsink->name()))
      return upsink;
  return NULL;
}

#ifdef PERFMON
void InterInitPerfGraph()
{
  perfgraph=new StrlPerfGraph();
  sink->addToGraph(perfgraph);
}

void InterStartPerfGraph()
{
  perfgraph->globalSTARTcount(); //start count global clock
}

void print_stats()
{
  fprintf(stderr, "\nGLOBAL counts:\n");
  fprintf(stderr, "--------------\n");
  fprintf(stderr, "\nPer module counts:\n");
  fprintf(stderr, "------------------\n\n");
  sink->print_stats();
}

void InterStopPerfGraph()
{
  perfgraph->globalSTOPcount(); //stop count global clock
}

void InterGetPerfGraph(double sec)//It should be called after stopperfgraph
{
  /*  print_stats();*/
  fprintf(stderr, "\nSummary:\n");
  fprintf(stderr, "--------------\n");
  perfgraph->print_stats();
  cerr<<endl<<"Skipped Sample Size : "<<SkippedSampleSize<<"  # of times : "<<NumofSSS<<endl;
  cerr<<"WP: "<<(sink->getWP())<<endl;
  cerr<<"time source: "<<(source->getWP()/source->getSamplingFrequency())<<endl;
  cerr<<"time sink: "<<(sink->getWP()/sink->getSamplingFrequency())<<endl;
  cerr << endl << "Running time: "<<sec<<endl;  
  perfgraph->setTitle("udp transmitter");
  perfgraph->outputGraph(sec);
}
void InterLocalAwaitTSTARTcount(char *ch)
{
  StrlSigProc* x=GetObject(ch);
  x->startAwaitTickCount();
}
void InterLocalAwaitTSTOPcount(char *ch)
{
  StrlSigProc* x=GetObject(ch);
  x->stopAwaitTickCount();
}
void InterLocalIncAwaitTick(char *ch)
{
  StrlSigProc* x=GetObject(ch);
  x->incNumberAwaitTick();
}
void InterGlobalAwaitTSTARTcount()
{
  if(perfgraph!=NULL)
    perfgraph->AwaitTSTARTcount();
  else {
    cerr<<"perfgraph is not open"<<endl;
    exit(1);
  }
}
void InterGlobalAwaitTSTOPcount()
{
  if(perfgraph!=NULL){
    perfgraph->AwaitTSTOPcount();
  }
  else {
    cerr<<"perfgraph is not open"<<endl;
    exit(1);
  }
} 
void InterGlobalIncAwaitTick()
{
  perfgraph->InreaseNUMTick();
}
#endif

/***********************************
 * Initialization function
 ***********************************/

void InterInitializeSink(char *r)
{
  StrlSigProc* x=GetObject(r);
  if(x->isConnectedToSource())
    x->init_base();
  else exit(1);
  x->setup();
}

void InterConnectModules(char *r,char *s,int i,int j)
{
  StrlSigProc* x=GetObject(r);
  StrlSigProc* y=GetObject(s);
  x->connect_proc(y,0,i);
}

VrSampleRange InterGetSampleRange(char *r)
{
  VrSampleRange srange;
  StrlSigProc* x=GetObject(r);
  srange.index=x->getMarkedWP();
  srange.size=x->getMaxOutputSize();
  return srange;
}

VrSampleIndex InterGetMarkedWP(char *r)
{
  VrSampleIndex indx;
  StrlSigProc* x=GetObject(r);
  indx=x->getMarkedWP();
  return indx;
}


VrSampleIndex InterGetWP(char *r)
{
  VrSampleIndex indx;
  StrlSigProc* x=GetObject(r);
  indx=x->getWP();
  return indx;
}

unsigned int InterGetOutputSize(char *r)
{
  unsigned int p;
  StrlSigProc* x=GetObject(r);
  p=x->getOutputSize();
  return p;
}

unsigned int InterGetMaxOutSize(char *r)
{
  unsigned int p;
  StrlSigProc* x=GetObject(r);
  p=x->getMaxOutputSize();
  return p;
}

int InterGetNumberInputs(char *r)
{
  unsigned int p;
  StrlSigProc* x=GetObject(r);
  p=x->getnumberInputs();
  return (int) p;
}

char* InterForecast(VrSampleRange s, char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange inputs[x->getnumberInputs()];

  x->forecast(s,inputs);
  char *str = (char *)malloc(sizeof(char [STRLEN]));
  sprintf(str, "%lld %lu",inputs[0].index, inputs[0].size); 
  return str;
}

char* InterDowncast(VrSampleRange s,char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange output;

  x->downcast(s,&output);
  char *str = (char *)malloc(sizeof(char [STRLEN]));
  sprintf(str, "%lld %lu",output.index, output.size); 
  return str;
}

int InterStrlFitRange(VrSampleIndex s,int req,VrSampleRange range,char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->StrlFitRange(s,req,range);
}
/*
int InterStrlmarkData(VrSampleIndex s,int req,int dm,VrSampleRange range,char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->StrlmarkData(s,req,dm,range);
}
*/
  /*******************************************
   * COMPUTE_DATA calls these function.
   *******************************************/

int InterGet_Mywriterll(char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->Get_Mywriterll();
}

int InterCheck_MymarkedDataSize(char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->Check_MymarkedDataSize();
}

unsigned long InterDFComputeData(char *r,int ret)
{
  StrlSigProc* x=GetObject(r);
  return x->Data_Flow_Work(ret);
}

VrSampleIndex InterGetMymarkedIndex(char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->getMymarkedIndex();
}

unsigned long InterGetMymarkedSize(char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->GetMymarkedSize();
}

VrSampleRange InterGetMymarkedData(char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange srange;
  srange.index=x->getMymarkedIndex();
  srange.size=x->GetMymarkedSize();
  return srange;
}  

void InterSet_MarkedWP(char *r,VrSampleIndex lg)
{
  StrlSigProc* x=GetObject(r);
  x->Set_MarkedWP(lg);
}

void InterWriteData(char *r,int dx)
{
  StrlSigProc* x=GetObject(r);
  x->StrlWriteData(dx);
}  

/**************************************
 * specialized computing data function
 **************************************/
VrSampleRange* InterFitRangeForMainSink(VrSampleRange s, char *r)
{
 
  StrlSigProc* x=GetObject(r);
  return x->StrlFitRangeForMainSink(s);

  /*  StrlSigProc* x=GetObject(r);
  VrSampleRange output;
  VrSampleIndex desiredWP,pendingWP;
  unsigned int requestSize;
  unsigned int maxOutSize;

  x->downcast(s,&output);
  pendingWP=x->getMarkedWP();
  desiredWP=output.index+output.size;
  requestSize=desiredWP-pendingWP;
  maxOutSize=x->getMaxOutputSize();

  if(requestSize>maxOutSize)
    requestSize=maxOutSize;
  unsigned int temp=x->getOutputSize();
  requestSize=((requestSize/temp)*temp);
  output.index=pendingWP;
  output.size=requestSize;

  VrSampleRange inputs[x->getnumberInputs()];
  x->forecast(output,inputs);
  
  x->StrlFitRange(pendingWP,requestSize,inputs[0]);
  
  VrSampleRange *str = (VrSampleRange *)malloc(sizeof(VrSampleRange));
  str->index=inputs[0].index;
  str->size=inputs[0].size;
  return str;*/
}

void InterComputeForMainSink(char *r)
{

  StrlSigProc* x=GetObject(r);
  x->StrlComputeForMainSink();
  /*  
  int not_source=0;
  int complete_var=0;
  int not_complete_flag=0;

  StrlSigProc* x=GetObject(r);
  if (!(x->Get_Mywriterll()))
    return;
  if (!(x->Check_MymarkedDataSize()))
    return;
 
 if (x->getnumberInputs()>0)
    not_source=1;

 complete_var=x->Data_Flow_Work(not_source);

 if(x->GetMymarkedSize()>complete_var)
   not_complete_flag=not_complete_flag-1;

 if(not_complete_flag<0)
   x->Set_MarkedWP(x->getMymarkedIndex()+complete_var);
   x->StrlWriteData(not_source);
  */
}

float InterGetFrequency(char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->getSamplingFrequency();
}

void InterSaveSkippedDataSize (int size)
{
  fprintf(stderr,"[%s]skipping\t %d (input sample)\n",__FILE__,size);
  SkippedSampleSize +=size;
  ++NumofSSS;
}

} /* end extern "C" */
