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

/* This is GSM_ALL.h */
#ifndef GSM_ALL_HEADER
#define GSM_ALL_HEADER
#include "../lib/include/datatype.h"
#include "../lib/strl/src/SOURCE.h"
#include "../lib/strl/i_mod/P_MOD.h"
#include "../lib/strl/snk/SINK.h"
#include "../lib/strl/submod/FIT_RANGE.h"
#include "../lib/strl/submod/COMP_DATA.h"

/* UPLINK */
/*void UPLINK_I_InitRange(char* r);*/
void UPLINK_O_UDPSource_module(char* r);
void UPLINK_O_Demodulator_module(char* r);
void UPLINK_O_Decipher_module(char* r);
void UPLINK_O_DeInterleaver_module(char* r);
void UPLINK_O_ChannelDecoder_module(char* r);
void UPLINK_O_SpeechDecoder_module(char* r);
void UPLINK_O_AudioSink_module(char* r);
/* DNLINK */
void DNLINK_O_FileSource_module(char* r);
void DNLINK_O_SpeechCoder_module(char* r);
void DNLINK_O_ChannelCoder_module(char* r);
void DNLINK_O_Interleaver_module(char* r);
void DNLINK_O_Cipher_module(char* r);
void DNLINK_O_Modulator_module(char* r);
void DNLINK_O_UDPSink_module(char* r);
/* PERF_DNLINK */
void PERF_DNLINK_O_FileSource_module(char* r);
void PERF_DNLINK_O_SpeechCoder_module(char* r);
void PERF_DNLINK_O_ChannelCoder_module(char* r);
void PERF_DNLINK_O_Interleaver_module(char* r);
void PERF_DNLINK_O_Cipher_module(char* r);
void PERF_DNLINK_O_Modulator_module(char* r);
void PERF_DNLINK_O_FileSink_module(char* r);
/* PERF_UPLINK */
void PERF_UPLINK_O_FileSource_module(char* r);
void PERF_UPLINK_O_Demodulator_module(char* r);
void PERF_UPLINK_O_Decipher_module(char* r);
void PERF_UPLINK_O_DeInterleaver_module(char* r);
void PERF_UPLINK_O_ChannelDecoder_module(char* r);
void PERF_UPLINK_O_SpeechDecoder_module(char* r);
void PERF_UPLINK_O_FileSink_module(char* r);
/*ALL*/
/*void GSM_ALL_I_InitRange(char* r);*/
void GSM_ALL_O_FileSource_module(char* r);
void GSM_ALL_O_SpeechCoder_module(char* r);
void GSM_ALL_O_ChannelCoder_module(char* r);
void GSM_ALL_O_Interleaver_module(char* r);
void GSM_ALL_O_Cipher_module(char* r);
void GSM_ALL_O_Modulator_module(char* r);
void GSM_ALL_O_Demodulator_module(char* r);
void GSM_ALL_O_Decipher_module(char* r);
void GSM_ALL_O_DeInterleaver_module(char* r);
void GSM_ALL_O_ChannelDecoder_module(char* r);
void GSM_ALL_O_SpeechDecoder_module(char* r);
void GSM_ALL_O_AudioSink_module(char* r);
/* PERF_ALL */
void PERF_ALL_O_FileSource_module(char* r);
void PERF_ALL_O_SpeechCoder_module(char* r);
void PERF_ALL_O_ChannelCoder_module(char* r);
void PERF_ALL_O_Interleaver_module(char* r);
void PERF_ALL_O_Cipher_module(char* r);
void PERF_ALL_O_Modulator_module(char* r);
void PERF_ALL_O_Demodulator_module(char* r);
void PERF_ALL_O_Decipher_module(char* r);
void PERF_ALL_O_DeInterleaver_module(char* r);
void PERF_ALL_O_ChannelDecoder_module(char* r);
void PERF_ALL_O_SpeechDecoder_module(char* r);
void PERF_ALL_O_FileSink_module(char* r);
/* UPLINK */
char* GET_UDPSOURCE(int);
/* DNLINK */
char* GET_UDPSINK(char*,int);
char* GET_FILESINK(char*);
char* GET_FILESINK4UP(char*);
/* ALL */
char* GET_FILESOURCE(char*,int);
char* GET_FILESOURCE4UP(char*,int);
char* GET_SPEECHCODER();
char* GET_CHANNELCODER();
char* GET_INTERLEAVER();
char* GET_CIPHER();
char* GET_MODULATOR();
char* GET_DEMODULATOR();
char* GET_DECIPHER();
char* GET_DEINTERLEAVER();
char* GET_CHANNELDECODER();
char* GET_SPEECHDECODER();
char* GET_AUDIOSINK();

int GSM_ALL();
#ifdef PERFMON
void INIT_PERF_GRAPH();
void GET_PERF_GRAPH(double);
void START_PERF_GRAPH();
void STOP_PERF_GRAPH();
void INIT_PERF_GRAPH4UP();
void GET_PERF_GRAPH4UP(double);
void START_PERF_GRAPH4UP();
void STOP_PERF_GRAPH4UP();
#endif

#endif
