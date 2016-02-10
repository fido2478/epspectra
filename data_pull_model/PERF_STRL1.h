/* This is perf_strl1.h */

#include "include/datatype.h"
#include "source/SOURCE.h"
#include "p_mod/P_MOD.h"
#include "sink/SINK.h"
#include "submodule/MARK_DATA.h"

int PERF_STRL();
char* GET_SOURCE(char *r,int y);
char* GET_CODER(int x);
char* GET_MOD_F(int x,float y,int z,int a,int b,int c,float d,int e);
char* GET_MOD();
char* GET_SUMMER();
char* GET_SCOPESINK_F(float a,int b,int c,int d,int e);
char* GET_SCOPESINK();
char* GET_SINK(char *r,int x);

void CONNECT_MODULES(char *r,char *s,int i);
void MAKETOPOLOGY();
/*void TRIGGER();*/
int CHOOSESINK(StrlSampleIndex,StrlSampleIndex);
int SET_COMPUTE_FLAG(int);
void START_PERF_GRAPH();
void STOP_PERF_GRAPH();
void INIT_PERF_GRAPH();
void GET_PERF_GRAPH(double);
