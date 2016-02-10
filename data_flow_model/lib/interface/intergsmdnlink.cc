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
//#include <StrlGsmDNSource.h>
#include <StrlGsmSpeechCoder.h>
#include <StrlGsmInterleaver.h>
#include <StrlGsmChannelCoder.h>
#include <StrlGsmCipher.h>
#include <StrlUDPSink.h>
#include <StrlFileSink.h>
//#include <StrlGsmDNSink.h>

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


#define DNSRC_TYPE StrlFileSource<char>
//#define DNSRC_TYPE StrlGsmDNSource<char>
#define SC_TYPE StrlGsmSpeechCoder
#define IL_TYPE StrlGsmInterleaver
#define CHC_TYPE StrlGsmChannelCoder
#define CIP_TYPE StrlGsmCipher
//#define DNSNK_TYPE StrlGsmDNSink<char>
//#define DNSNK_TYPE StrlUDPSink<char>
#define DNSNK_TYPE StrlFileSink<char>

DNSRC_TYPE *dnsource;
SC_TYPE *sc;
IL_TYPE *il;
CHC_TYPE *chc;
CIP_TYPE *cip;
DNSNK_TYPE *dnsink;

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

const char* InterGetDNSource(char *r,int y)
{
  dnsource = new StrlFileSource<char>(r,y);
  //  dnsource = new StrlGsmDNSource<char>(r,y);
  return dnsource->name();
}

const char* InterGetSC()
{
  sc = new StrlGsmSpeechCoder;
  return sc->name();
}
const char* InterGetIL()
{
  il = new StrlGsmInterleaver;
  return il->name();
}
const char* InterGetChCoder()
{
  chc = new StrlGsmChannelCoder;
  return chc->name();
}
const char* InterGetCipher()
{
  cip = new StrlGsmCipher;
  return cip->name();
}
const char* InterGetDNFileSink(char *r)
{
  dnsink=new StrlFileSink<char>(r);
  //  dnsink=new StrlGsmDNSink<char>(r,x);
  return dnsink->name();
}
/*
const char* InterGetDNSink(char *r,int x)
{
  dnsink=new StrlUDPSink<char>(r,x);
  //  dnsink=new StrlGsmDNSink<char>(r,x);
  return dnsink->name();
}
*/
StrlSigProc *GetObject(char *r)
{
  if (dnsource!=NULL)
    if (!strcmp(r,dnsource->name()))
      return dnsource;
  if (sc!=NULL)
    if (!strcmp(r, sc->name()))
      return sc;
  if (chc!=NULL) 
    if(!strcmp(r, chc->name()))
      return chc;
  if (il!=NULL) 
    if(!strcmp(r, il->name()))
      return il;
  if (cip !=NULL) 
    if(!strcmp(r, cip->name()))
      return cip;
  if (dnsink!=NULL) 
    if(!strcmp(r, dnsink->name()))
      return dnsink;
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
