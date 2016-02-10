#include "FIT_RANGE.h"
#include "stdio.h"
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
 * This is FIT_RANGE_data.c
 *---------------------------------------------*/

StrlSampleIndex ADD_INDEX_SIZE(char *str)
{
  VrSampleRange data;
  /*char indx[80]="0";*/

  sscanf(str, "%lld %lu",&data.index, &data.size);
  data.index=data.index + data.size;
  /*sprintf(indx, "%lld",data.index);*/
  return lld2str(data.index);
}

void ADD_INDEX_SIZENEW(StrlSampleIndex indx, char *str)
{
  VrSampleRange data;

  sscanf(str, "%lld %lu",&data.index, &data.size);
  data.index=data.index + data.size;
  sprintf(&indx, "%lld",data.index);
#ifdef DEBUG
  printf("ADD_INDEX_SIZENEW => [%s] %s\n",str,&indx);
#endif
}
/*
void ADD_INDEX_SIZEVR(VrSampleIndex* indx, VrSampleRange str)
{
  *indx=str.index+str.size;
}
*/
int GET_SIZE(StrlSampleRange str)
{
  int data;
  sscanf(str, "%d %d",&data, &data);
  return data;
}
/*
int GET_SIZEVR(VrSampleRange str)
{
  return str.size;
}
*/
StrlSampleIndex GETINDEX(char *str)
{
  VrSampleRange data;
  /*char indx[80]="0";*/
  sscanf(str, "%lld %lu",&data.index, &data.size);
  /*sprintf(indx, "%lld",data.index);*/
  return lld2str(data.index);
}
 
void GETINDEXNEW(StrlSampleIndex indx, char *str)
{
  VrSampleRange data;
  sscanf(str, "%lld %lu",&data.index, &data.size);
  sprintf(&indx, "%lld",data.index);
}
/*
void GETINDEXVR(VrSampleIndex* indx, VrSampleRange str)
{
  *indx=str.index;
}
*/
int SUBTRACT_A_B(StrlSampleIndex a,StrlSampleIndex b)
{
  long long x,y;
  x=str2lld(a);   y=str2lld(b);
#ifdef DEBUG
  printf("[1]SUBTRACT_A_B => %s - %s\n",a,b);
#endif
  return (int) x-y;
}
/*
int SUBTRACT_A_BVR(VrSampleIndex a,VrSampleIndex b)
{
  return a-b;
}
*/
int ROUNDOWN_SIZE(int x,UnsignedInt y)
{
  return x=((x/y)*y);
}
/*
int ROUNDUP_REQUESTSIZE(int x,UnsignedInt y)
{
  return x=(((x + y - 1)/y ) * (y));
}
*/

StrlSampleRange SET_SAMPLERANGE(StrlSampleIndex y,int z)
{
  VrSampleRange data;
  /*char str[80]="0";*/
  data.index=str2lld(y);
  data.size=z;
  /*sprintf(str, "%lld %lu",data.index, data.size);*/
  return SRange2str(data);
}

void SET_SAMPLERANGENEW(StrlSampleIndex str,StrlSampleIndex y,int z)
{
  VrSampleRange data;
  data.index=str2lld(y);
  data.size=z;
  sprintf(&str, "%lld %lu",data.index, data.size);
#ifdef DEBUG
  printf("[1]SET_SAMPLERANGENEW => %lld %lu = %s(strl)\n",y,z,&str);
#endif
}
/*
void SET_SAMPLERANGEVR(VrSampleIndex* str,VrSampleIndex y,int z)
{
  str->index=y;str->size=z;
}
*/
StrlSampleRange DOWNCASTS(StrlSampleRange s,char *r)
{
#ifndef XES
  /*char str[80]="0";
  VrSampleRange data=InterDowncast(str2SRange(s),r);
  sprintf(str, "%lld %lu",data.index, data.size); 
#ifdef DEBUG
  printf("[1]DOWNCASTS =>%s: [%s]\n",r,s);
#endif
  return str;*/
  return SRange2str(InterDowncast(str2SRange(s),r));
#endif
}

StrlSampleRange FORECASTS(StrlSampleRange s,char *r)
{
#ifndef XES
  /*  char str[80]="0";
  VrSampleRange data=InterForecast(str2SRange(s),r);
  sprintf(str, "%lld %lu",data.index, data.size); 
#ifdef DEBUG
  printf("[1]FORECASTS =>%s: [%s]\n",r,s);
#endif
return str; */
  return SRange2str(InterForecast(str2SRange(s),r));
#endif
}

void DOWNCASTSNEW(StrlSampleRange str,StrlSampleRange s,char *r)
{
#ifndef XES
  InterDowncastNew(&str,str2SRange(s),r);
#endif
}

void FORECASTSNEW(StrlSampleRange str,StrlSampleRange s,char *r)
{
#ifndef XES
  InterForecastNew(&str,str2SRange(s),r); 
#endif
}
/*
void DOWNCASTSVR(VrSampleRange* str,VrSampleRange s,char *r)
{
#ifndef XES
  InterDowncastVr(str,s,r);
#endif
}

void FORECASTSVR(VrSampleRange* str,VrSampleRange s,char *r)
{
#ifndef XES
  InterForecastVr(str,s,r); 
#endif
}
*/

/*
int REAL_MARK_DATA(StrlSampleIndex p_wp,int req,int dm,StrlSampleRange range,char *r)
{
  VrSampleIndex x=str2lld(p_wp);
  VrSampleRange rg=str2SRange(range);
  return InterStrlmarkData(x,req,dm,rg,r);
}  
*/
int REAL_FIT_RANGE(StrlSampleIndex p_wp,int req,StrlSampleRange range,char *r)
{
#ifndef XES
  VrSampleIndex x=str2lld(p_wp);
  VrSampleRange rg=str2SRange(range);
#ifdef DEBUG
  printf("[1]REAL_FIT_RANGE => index %s, requestsize %d\n",p_wp,req);
#endif
  return InterStrlFitRange(x,req,rg,r);
#endif
}  
/*
int REAL_FIT_RANGEVR(VrSampleIndex p_wp,int req,VrSampleRange range,char *r)
{
#ifndef XES
  return InterStrlFitRange(p_wp,req,range,r);
#endif
}  
*/
int GETMAXOUTSIZE(char *r)
{
#ifndef XES
  return InterGetMaxOutSize(r);
#endif
}

int error_exit(int x)
{
  fprintf(stderr,"impossible case\n");
  exit(x);
}

