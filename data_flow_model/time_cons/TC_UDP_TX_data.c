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


#include "TC_UDP_TX.h"
#include "../lib/interface/interface.h"  /* C++ class header */
#include <string.h>


char* GET_SOURCE(char *r,int y)
{
  return InterGetSource(r,y);
}

char* GET_CODER(int x)
{
  return InterGetCoder(x);
}

char* GET_MOD_F(int x,float y,int z,int a,int b,int c,float d,int e)
{
  return InterGetMod_f(x,y,z,a,b,c,d,e);
}

char* GET_MOD()
{
  return InterGetMod();
}

char* GET_SUMMER()
{
  return InterGetSummer();
}

char* GET_SCOPESINK_F(float a,int b,int c,int d,int e)
{
  return InterGetScopesink_f(a,b,c,d,e);
}

char* GET_SINK(char *r,int x)
{
  return InterGetSink(r,x);
}

/*** GUI start ***/
void INITGUI_MAIN_START()
{
  InterGuimain_Start();
}

void RUN_GUI_MAIN()
{
  InterGuimain_Run();
}
/*** GUI end ***/
#ifdef PERFMON
void INIT_PERF_GRAPH()
{
  InterInitPerfGraph();
}

void GET_PERF_GRAPH(double x)
{
  InterGetPerfGraph(x);
}
void START_PERF_GRAPH()
{
  InterStartPerfGraph();
}
void STOP_PERF_GRAPH()
{
  InterStopPerfGraph();
}
#endif
