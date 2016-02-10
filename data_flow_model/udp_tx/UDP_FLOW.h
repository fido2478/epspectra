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

/* This is udp_flow.h */
#include "../lib/include/datatype.h"
#include "../lib/strl/src/SOURCE.h"
#include "../lib/strl/i_mod/P_MOD.h"
#include "../lib/strl/snk/SINK.h"
#include "../lib/strl/submod/FIT_RANGE.h"
#include "../lib/strl/submod/COMP_DATA.h"

char* GET_SOURCE(char *r,int y);
char* GET_CODER(int x);
char* GET_MOD_F(int x,float y,int z,int a,int b,int c,float d,int e);
char* GET_MOD();
char* GET_SUMMER();
char* GET_SCOPESINK_F(float a,int b,int c,int d,int e);
char* GET_SCOPESINK();
char* GET_SINK(char *r,int x);
int UDP_FLOW();
void INITGUI_MAIN_START();/*gui*/
void RUN_GUI_MAIN();/*gui*/
#ifdef PERFMON
void INIT_PERF_GRAPH();
void GET_PERF_GRAPH(double);
void START_PERF_GRAPH();
void STOP_PERF_GRAPH();
#endif
