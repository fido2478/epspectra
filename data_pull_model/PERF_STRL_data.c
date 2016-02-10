#include "PERF_STRL.h"
#include <interface.h>  /* C++ class header */
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
/*
char* GET_SCOPESINK()
{
  return InterGetScopesink();
}
*/
char* GET_SINK(char *r,int x)
{
  return InterGetSink(r,x);
}

void CONNECT_MODULES(char *r,char *s,int i)
{
  InterConnectModules(r,s,i);
}

void INITIAL_SINK(char *r)
{
  InterInitializeSink(r);
}

int CHOOSESINK(StrlSampleIndex s,StrlSampleIndex r)
{
  return (str2lld(s)-str2lld(r));
}

int SET_COMPUTE_FLAG(int i)
{
  if (i>0)
    return 1;
  else
    return 0;
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
void START_PERF_GRAPH()
{
  InterStartPerfGraph();
}
void STOP_PERF_GRAPH()
{
  InterStopPerfGraph();
}
void INIT_PERF_GRAPH()
{
  InterInitPerfGraph();
}

void GET_PERF_GRAPH(double x)
{
  InterGetPerfGraph(x);
}
