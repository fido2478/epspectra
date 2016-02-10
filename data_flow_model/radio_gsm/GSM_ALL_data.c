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


#include "GSM_ALL.h"
#include "../lib/interface/intergsm.h"  /* C++ class header */
#include <string.h>
#include <stdio.h>
/************ Definition of input/output signals **********/
/*void GSM_ALL_I_InitRange(char* r){
  fscanf(stderr,"%s",r);
}*/
void GSM_ALL_O_FileSource_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_SpeechCoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_ChannelCoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_Interleaver_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_Cipher_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_Modulator_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_Demodulator_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_Decipher_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_DeInterleaver_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_ChannelDecoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_SpeechDecoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void GSM_ALL_O_AudioSink_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}

/* PERF_ALL */
void PERF_ALL_O_FileSource_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_SpeechCoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_ChannelCoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_Interleaver_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_Cipher_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_Modulator_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_Demodulator_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_Decipher_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_DeInterleaver_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_ChannelDecoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_SpeechDecoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_ALL_O_FileSink_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}

/* PERF_DOWNLINK */
void PERF_DNLINK_O_FileSource_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_DNLINK_O_SpeechCoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_DNLINK_O_ChannelCoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_DNLINK_O_Interleaver_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_DNLINK_O_Cipher_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_DNLINK_O_Modulator_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_DNLINK_O_FileSink_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
/*DOWNLINK */
void DNLINK_O_FileSource_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void DNLINK_O_SpeechCoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void DNLINK_O_ChannelCoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void DNLINK_O_Interleaver_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void DNLINK_O_Cipher_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void DNLINK_O_Modulator_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void DNLINK_O_UDPSink_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
/* UPLINK */
void UPLINK_O_UDPSource_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void UPLINK_O_Demodulator_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void UPLINK_O_Decipher_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void UPLINK_O_DeInterleaver_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void UPLINK_O_ChannelDecoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void UPLINK_O_SpeechDecoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void UPLINK_O_AudioSink_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
/* PERF_UPLINK */
void PERF_UPLINK_O_FileSource_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_UPLINK_O_Demodulator_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_UPLINK_O_Decipher_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_UPLINK_O_DeInterleaver_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_UPLINK_O_ChannelDecoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_UPLINK_O_SpeechDecoder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void PERF_UPLINK_O_FileSink_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
/************ Definition of functions ******************/
char* GET_FILESOURCE(char *r,int y){
#ifndef XES
  return InterGetFileSource(r,y);
#endif
}
char* GET_FILESOURCE4UP(char *r,int y){
#ifndef XES
  return InterGetFileSource4up(r,y);
#endif
}
char* GET_SPEECHCODER(){
#ifndef XES
  return InterGetSpeechCoder();
#endif
}
char* GET_CHANNELCODER(){
#ifndef XES
  return InterGetChannelCoder();
#endif
}
char* GET_INTERLEAVER(){
#ifndef XES
  return InterGetInterleaver();
#endif
}
char* GET_CIPHER(){
#ifndef XES
  return InterGetCipher();
#endif
}
char* GET_MODULATOR(){
#ifndef XES
  return InterGetModulator();
#endif
}
char* GET_DEMODULATOR(){
#ifndef XES
  return InterGetDemodulator();
#endif
}
char* GET_DECIPHER(){
#ifndef XES
  return InterGetDecipher();
#endif
}
char* GET_DEINTERLEAVER(){
#ifndef XES
  return InterGetDeinterleaver();
#endif
}
char* GET_CHANNELDECODER(){
#ifndef XES
  return InterGetChannelDecoder();
#endif
}
char* GET_SPEECHDECODER(){
#ifndef XES
  return InterGetSpeechDecoder();
#endif
}
char* GET_AUDIOSINK(){
#ifndef XES
  return InterGetAudioSink();
#endif
}
char* GET_FILESINK(char* r){
#ifndef XES
  return InterGetFileSink(r);
#endif
}
char* GET_FILESINK4UP(char* r){
#ifndef XES
  return InterGetFileSink4up(r);
#endif
}
/* UPLINK & DNLINK */
char* GET_UDPSOURCE(int x){
#ifndef XES
  return InterGetUDPSource(x);
#endif
}
char* GET_UDPSINK(char* r,int y){
#ifndef XES
  return InterGetUDPSink(r,y);
#endif
}
/*****************************************/

#ifdef PERFMON
void INIT_PERF_GRAPH(){
#ifndef XES
  InterInitPerfGraph();
#endif
}
void GET_PERF_GRAPH(double x){
#ifndef XES
  InterGetPerfGraph(x);
#endif
}
void START_PERF_GRAPH(){
#ifndef XES
  InterStartPerfGraph();
#endif
}
void STOP_PERF_GRAPH(){
#ifndef XES
  InterStopPerfGraph();
#endif
}
void INIT_PERF_GRAPH4UP(){
#ifndef XES
  InterInitPerfGraph4up();
#endif
}
void GET_PERF_GRAPH4UP(double x){
#ifndef XES
  InterGetPerfGraph4up(x);
#endif
}
void START_PERF_GRAPH4UP(){
#ifndef XES
  InterStartPerfGraph4up();
#endif
}
void STOP_PERF_GRAPH4UP(){
#ifndef XES
  InterStopPerfGraph4up();
#endif
}
#endif
