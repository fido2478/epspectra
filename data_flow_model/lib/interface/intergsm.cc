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
#include "StrlUDPSource.h"
#include "StrlFileSource.h"
#include "GsmSpeechCoder.h"
#include "GsmChannelCoder.h"
#include "GsmInterleaver.h"
#include "GsmCipher.h"
#include "GsmModulator.h"
#include "GsmDemodulator.h"
#include "GsmDecipher.h"
#include "GsmDeInterleaver.h"
#include "GsmChannelDecoder.h"
#include "GsmSpeechDecoder.h"
#include "StrlAudioSink.h"
#include "StrlUDPSink.h"
#include "StrlFileSink.h"
#ifdef PERFMON
#include <StrlPerfGraph.h>
#endif
/**************************************************************
 * StrlMultiTask class is redefined for the implementation of 
 * Control part of SPECtRA system in ESTEREL
 * it is at pspectra/cc/i386/lib/vr/.
 **************************************************************/
#include <StrlTypes.h>
/******** Global Parameter ***********/
#define GUI_FLAG 0
/**
#define STRLUDPSOURCE StrlUDPSource<complex>
#define STRLFILESOURCE StrlFileSource<char>
#define STRLFILESOURCE4UP StrlFileSource<complex>
#define STRLSPEECHCODER GsmSpeechCoder
#define STRLCHANNELCODER GsmChannelCoder
#define STRLINTERLEAVER GsmInterleaver
#define STRLCIPHER GsmCipher
#define STRLMODULATOR GsmModulator<complex>
#define STRLDEMODULATOR GsmDemodulator<complex>
#define STRLDECIPHER GsmDecipher
#define STRLDEINTERLEAVER GsmDeInterleaver
#define STRLCHANNELDECODER GsmChannelDecoder
#define STRLSPEECHDECODER GsmSpeechDecoder<short>
#define STRLAUDIOSINK StrlAudioSink<short>
#define STRLUDPSINK StrlUDPSink<complex>
#define STRLFILESINK StrlFileSink<complex>
#define STRLFILESINK4UP StrlFileSink<short>
**/
unsigned long long SkippedSampleSize=0;
unsigned long NumofSSS=0;
int BufferSizeMultiplier=2; /* = numberSinks +1 */
int process_one = 1;
int persistent = 0;
int run = 1;
/********** definition of objects (modules) *************/
/**
STRLUDPSOURCE *udpsource;
STRLFILESOURCE *filesource;
STRLFILESOURCE4UP *filesource4up;
STRLSPEECHCODER *speechcoder;
STRLCHANNELCODER *channelcoder;
STRLINTERLEAVER *interleaver;
STRLCIPHER *cipher;
STRLMODULATOR *modulator;
STRLDEMODULATOR *demodulator;
STRLDECIPHER *decipher;
STRLDEINTERLEAVER *deinterleaver;
STRLCHANNELDECODER *channeldecoder;
STRLSPEECHDECODER *speechdecoder;
STRLAUDIOSINK *audiosink;
STRLUDPSINK *udpsink;
STRLFILESINK *filesink;
STRLFILESINK4UP *filesink4up;
**/
StrlUDPSource<complex> *udpsource;
StrlFileSource<char> *filesource;
StrlFileSource<complex> *filesource4up;
GsmSpeechCoder *speechcoder;
GsmChannelCoder *channelcoder;
GsmInterleaver *interleaver;
GsmCipher *cipher;
GsmModulator<complex> *modulator;
GsmDemodulator<complex> *demodulator;
GsmDecipher *decipher;
GsmDeInterleaver *deinterleaver;
GsmChannelDecoder *channeldecoder;
GsmSpeechDecoder<short> *speechdecoder;
StrlAudioSink<short> *audiosink;
StrlUDPSink<complex> *udpsink;
StrlFileSink<complex> *filesink;
StrlFileSink<short> *filesink4up;
#ifdef PERFMON
StrlPerfGraph *perfgraph;
StrlPerfGraph *perfgraph4up;
#endif


#if (GUI_FLAG)
/*****  GUI begin ********/ 
#include "VrGUI.h"
/*****  GUI end ******/
#endif

#define STRLEN 80
/*********************************
 * define variables
 *********************************/

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
const char* InterGetUDPSource(int y){
  udpsource = new StrlUDPSource<complex>(y);
  return udpsource->name();
}
const char* InterGetFileSource(char *r,int y){
  filesource = new StrlFileSource<char>(r,y);
  return filesource->name();
}
const char* InterGetFileSource4up(char *r,int y){
  filesource4up = new StrlFileSource<complex>(r,y);
  return filesource4up->name();
}
const char* InterGetSpeechCoder(){
  speechcoder = new GsmSpeechCoder;
  return speechcoder->name();
}
const char* InterGetChannelCoder(){
  channelcoder = new GsmChannelCoder;
  return channelcoder->name();
}
const char* InterGetInterleaver(){
  interleaver = new GsmInterleaver;
  return interleaver->name();
}
const char* InterGetCipher(){
  cipher = new GsmCipher;
  return cipher->name();
}
const char* InterGetModulator(char *r){
  modulator = new GsmModulator<complex>;
  return modulator->name();
}
const char* InterGetDemodulator(char *r){
  demodulator = new GsmDemodulator<complex>;
  return demodulator->name();
}
const char* InterGetDecipher(){
  decipher = new GsmDecipher;
  return decipher->name();
}
const char* InterGetDeinterleaver(){
  deinterleaver = new GsmDeInterleaver;
  return deinterleaver->name();
}
const char* InterGetChannelDecoder(){
  channeldecoder = new GsmChannelDecoder;
  return channeldecoder->name();
}
const char* InterGetSpeechDecoder(){
  speechdecoder = new GsmSpeechDecoder<short>;
  return speechdecoder->name();
}
const char* InterGetAudioSink(){
  audiosink = new StrlAudioSink<short>();
  return audiosink->name();
}
const char* InterGetUDPSink(char* r,int y){
  udpsink = new StrlUDPSink<complex>(r,y);
  return udpsink->name();
}
const char* InterGetFileSink(char* r){
  filesink = new StrlFileSink<complex>(r);
  return filesink->name();
}
const char* InterGetFileSink4up(char* r){
  filesink4up = new StrlFileSink<short>(r);
  return filesink4up->name();
}

StrlSigProc *GetObject(char *r)
{
  if (udpsource!=NULL)
    if (!strcmp(r,udpsource->name()))
      return udpsource;
  if (filesource!=NULL)
    if (!strcmp(r,filesource->name()))
      return filesource;
  if (filesource4up!=NULL)
    if (!strcmp(r,filesource4up->name()))
      return filesource4up;
  if (speechcoder!=NULL)
    if (!strcmp(r, speechcoder->name()))
      return speechcoder;
  if (channelcoder!=NULL) 
    if(!strcmp(r, channelcoder->name()))
      return channelcoder;
  if (interleaver!=NULL) 
    if(!strcmp(r, interleaver->name()))
      return interleaver;
  if (cipher !=NULL) 
    if(!strcmp(r, cipher->name()))
      return cipher;
  if (modulator!=NULL)
    if (!strcmp(r,modulator->name()))
      return modulator;
  if (demodulator !=NULL) 
    if(!strcmp(r, demodulator->name()))
      return demodulator;
  if (decipher !=NULL) 
    if( !strcmp(r, decipher->name()))
      return decipher;
  if (deinterleaver !=NULL) 
    if(!strcmp(r, deinterleaver->name()))
      return deinterleaver;
  if (channeldecoder !=NULL)
    if(!strcmp(r, channeldecoder->name()))
      return channeldecoder;
  if (speechdecoder !=NULL)
    if(!strcmp(r, speechdecoder->name()))
      return speechdecoder;
  if (audiosink!=NULL) 
    if(!strcmp(r, audiosink->name()))
      return audiosink;
  if (udpsink!=NULL) 
    if(!strcmp(r, udpsink->name()))
      return udpsink;
  if (filesink!=NULL)
    if(!strcmp(r, filesink->name()))
      return filesink;
  if (filesink4up!=NULL)
    if(!strcmp(r, filesink4up->name()))
      return filesink4up;
  return NULL;
}

#ifdef PERFMON
void InterInitPerfGraph()
{
  perfgraph=new StrlPerfGraph();
  filesink->addToGraph(perfgraph);
}
void InterInitPerfGraph4up()
{
  perfgraph4up=new StrlPerfGraph();
  filesink4up->addToGraph(perfgraph4up);
}
void InterStartPerfGraph()
{
  perfgraph->globalSTARTcount(); //start count global clock
}
void InterStartPerfGraph4up()
{
  perfgraph4up->globalSTARTcount(); //start count global clock
}
void print_stats()
{
  fprintf(stderr, "\nGLOBAL counts:\n");
  fprintf(stderr, "--------------\n");
  fprintf(stderr, "\nPer module counts:\n");
  fprintf(stderr, "------------------\n\n");
  filesink->print_stats();
}
void print_stats4up()
{
  fprintf(stderr, "\nGLOBAL counts:\n");
  fprintf(stderr, "--------------\n");
  fprintf(stderr, "\nPer module counts:\n");
  fprintf(stderr, "------------------\n\n");
  filesink4up->print_stats();
}
void InterStopPerfGraph()
{
  perfgraph->globalSTOPcount(); //stop count global clock
}
void InterStopPerfGraph4up()
{
  perfgraph4up->globalSTOPcount(); //stop count global clock
}
void InterGetPerfGraph(double sec)//It should be called after stopperfgraph
{
  /*  print_stats();*/
  fprintf(stderr, "\nSummary:\n");
  fprintf(stderr, "--------------\n");
  perfgraph->print_stats();
  //cerr<<endl<<"Skipped Sample Size : "<<SkippedSampleSize<<"  # of times : "<<NumofSSS<<endl;
  cerr<<"WP: "<<(filesink->getWP())<<endl;
  cerr<<"time filesource: "<<(filesource->getWP()/filesource->getSamplingFrequency())<<endl;
  cerr<<"time filesink: "<<(filesink->getWP()/filesink->getSamplingFrequency())<<endl;
  cerr << endl << "Running time: "<<sec<<endl;  
  perfgraph->setTitle("GSM downlink");
  perfgraph->outputGraph(sec);
}
void InterGetPerfGraph4up(double sec)//It should be called after stopperfgraph
{
  /*  print_stats();*/
  fprintf(stderr, "\nSummary:\n");
  fprintf(stderr, "--------------\n");
  perfgraph4up->print_stats();
  //cerr<<endl<<"Skipped Sample Size : "<<SkippedSampleSize<<"  # of times : "<<NumofSSS<<endl;
  cerr<<"WP: "<<(filesink4up->getWP())<<endl;
  cerr<<"time filesource: "<<(filesource4up->getWP()/filesource4up->getSamplingFrequency())<<endl;
  cerr<<"time filesink: "<<(filesink4up->getWP()/filesink4up->getSamplingFrequency())<<endl;
  cerr << endl << "Running time: "<<sec<<endl;  
  perfgraph4up->setTitle("GSM uplink");
  perfgraph4up->outputGraph(sec);
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
void InterGlobalAwaitTSTARTcount4up()
{
  if(perfgraph4up!=NULL)
    perfgraph4up->AwaitTSTARTcount();
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
void InterGlobalAwaitTSTOPcount4up()
{
  if(perfgraph4up!=NULL){
    perfgraph4up->AwaitTSTOPcount();
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
void InterGlobalIncAwaitTick4up()
{
  perfgraph4up->InreaseNUMTick();
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

VrSampleRange InterForecast(VrSampleRange s, char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange inputs[x->getnumberInputs()];

  x->forecast(s,inputs);
  //char *str = (char *)malloc(sizeof(char [STRLEN]));
  /*char str[STRLEN];*/
  //sprintf(str, "%lld %lu",inputs[0].index, inputs[0].size); 
  //return str;
  return inputs[0];
}

VrSampleRange InterDowncast(VrSampleRange s,char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange output;

  x->downcast(s,&output);
  //char *str = (char *)malloc(sizeof(char [STRLEN]));
  /*char str[STRLEN];*/
  //sprintf(str, "%lld %lu",output.index, output.size); 
  //return str;
  return output;
}

void InterForecastNew(char* str,VrSampleRange s, char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange inputs[x->getnumberInputs()];

  x->forecast(s,inputs);
  sprintf(str, "%lld %lu",inputs[0].index, inputs[0].size); 
}

void InterDowncastNew(char* str,VrSampleRange s,char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange output;

  x->downcast(s,&output);
  sprintf(str, "%lld %lu",output.index, output.size); 
}

void InterForecastVr(VrSampleRange* str,VrSampleRange s, char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange inputs[x->getnumberInputs()];

  x->forecast(s,inputs);
  str->index=inputs[0].index; str->size=inputs[0].size;
}

void InterDowncastVr(VrSampleRange* str,VrSampleRange s,char *r)
{
  StrlSigProc* x=GetObject(r);
  x->downcast(s,str);
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
