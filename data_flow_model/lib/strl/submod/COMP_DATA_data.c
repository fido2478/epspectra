#include "COMP_DATA.h"
#ifndef XES
#ifdef GSM
#include "../../interface/intergsm.h"
#else
#include "../../interface/interface.h"  /* C++ class header */
#endif
#endif
#ifndef _DATATYPE_H
#define _DATATYPE_H

#include "../../include/datatype.h"

#endif

/*---------------------------------------------
 * Describe Procedure & Function
 * This is COMPUTE_DATA_data.c
 *---------------------------------------------*/

int CHECK_MYWRITERLL(char *r)
{
#ifndef XES
  return InterGet_Mywriterll(r);
#endif
}

int CHECK_MYMARKEDDATA_SIZE(char *r)
{
#ifndef XES
  return InterCheck_MymarkedDataSize(r);
#endif
}

StrlSampleSize REALCOMPUTEDATA(char *r,int x)
{
#ifndef XES
  /*char str[80]="0";
  unsigned long ul=InterDFComputeData(r,x);
  sprintf(str, "%lu",ul);
#ifdef DEBUG
  printf("[1]REALCOMPUTEDATA =>%s: return value[%s]\n",r,str);
#endif
*/
  return uld2str(InterDFComputeData(r,x));
#endif
}
/*
void REALCOMPUTEDATAVR(VrSampleSize* str,char *r,int x)
{
#ifndef XES
  *str=InterDFComputeData(r,x);
#endif
}
*/
StrlSampleIndex ADD_SAMPLEINDEX(StrlSampleIndex a,StrlSampleSize b)
{
  /*char str[80]="0";
    sprintf(str, "%lld",str2lld(a)+str2lld(b));*/
  return lld2str(str2lld(a)+str2lld(b));
}
void REALCOMPUTEDATANEW(StrlSampleSize str,char *r,int x)
{
#ifndef XES
  unsigned long ul=InterDFComputeData(r,x);
  sprintf(&str, "%lu",ul);
  /*str=uld2str(InterDFComputeData(r,x));*/
#endif
}

void ADD_SAMPLEINDEXNEW(StrlSampleIndex str, StrlSampleIndex a,StrlSampleSize b)
{
  sprintf(&str, "%lld",str2lld(a)+str2lld(b));
}

void WRITEDATA(char *r,int dx)
{
#ifndef XES
#ifdef DEBUG
  printf("[1]WRITEDATA =>%s\n",r);
#endif
  InterWriteData(r,dx);
#endif
}
/*
void ADD_SAMPLEINDEXVR(VrSampleIndex* str, VrSampleIndex a,VrSampleSize b)
{
  *str=a+b;
}
*/
