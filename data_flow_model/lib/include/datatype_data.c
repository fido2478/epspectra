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

/***********************************
### datatype_data.c #####
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "../interface/intergsm.h"  /* C++ class header */
#include <sys/time.h>
#include <unistd.h>
#define STRLEN 80

StrlSampleIndex INITIAL_INDEX ="0";
StrlSampleRange INITIAL_RANGE ="0 0";
StrlSampleRange START_RANGE ="0 0";
StrlSampleSize INITIAL_SIZE ="0";
/*VrSampleIndex INITIAL_INDEXVR =0;
VrSampleRange INITIAL_RANGEVR ={0, 0};
VrSampleSize INITIAL_SIZEVR =0;*/
StrlString INITIAL_STRING = "           ";
Debug4Var INITIAL_DEBUG4VAR = {"0","0"};
UnsignedInt INITIAL_UNSIGNEDINT=0;
UnsignedLL INITIAL_UNSIGNEDLL=0;
Float_Type INITIAL_FLOAT =0.0;

/*****************************************
### The def of a type StrlSampleIndex ###
 *****************************************/

void _text_to_StrlSampleIndex (string_ptr, str)
      StrlSampleIndex string_ptr;
     char* str;
{
  strcpy(str,string_ptr);
  /*sscanf(str, "%s",string_ptr);*/
}

char* _StrlSampleIndex_to_text (t)
      StrlSampleIndex t;
{
  static char buf[STRLEN];
  strcpy(buf,t);
  /*sprintf(buf, "%s", t);*/
  return (buf);
}

/********************************************
 ## The def of a type StrlSampleSize ##
 ********************************************/

void _text_to_StrlSampleSize (string_ptr, str)
      StrlSampleSize string_ptr;
     char* str;
{
  strcpy(str,string_ptr);
  /*sscanf(str, "%s",string_ptr);*/
}

char* _StrlSampleSize_to_text (t)
      StrlSampleSize t;
{
  static char buf[STRLEN];
  strcpy(buf,t);
  /*sprintf(buf, "%s", t);*/
  return (buf);
} 

/********************************************
 ## The def of a type StrlSampleRange 
 ********************************************/

void _text_to_StrlSampleRange (string_ptr, str)
      StrlSampleRange string_ptr;
     char* str;
{
  strcpy(str,string_ptr);
  /*sscanf(str, "%s",string_ptr);*/
}

char* _StrlSampleRange_to_text (t)
      StrlSampleRange t;
{
  static char buf[STRLEN];
  strcpy(buf,t);
  /*sprintf(buf, "%s", t);*/
  return (buf);
} 

int _check_StrlSampleRange (string)
     char* string;
{
  long long INDX;
  unsigned long SZ;
  return((sscanf(string, "%lld %lu",&INDX, &SZ
           )==2) ? 1 : 0);
}    

/********************************************
 ## The def of a type StrlString
 ********************************************/

void _text_to_StrlString (string_ptr, str)
      StrlString string_ptr;
     char* str;
{
  strcpy(str,string_ptr);
  /*sscanf(str, "%s",string_ptr);*/
}

char* _StrlString_to_text (t)
      StrlString t;
{
  static char buf[STRLEN];
  strcpy(buf,t);
  /*sprintf(buf, "%s", t);*/
  return (buf);
} 

int _check_StrlString (string)
     char* string;
{
  static char buf[STRLEN];
  return((sscanf(string, "%s",buf)==1) ? 1 : 0);
}    

/********************************************
    The def of a type Debug
 ********************************************/

void _text_to_Debug4Var (string_ptr, str)
      Debug4Var *string_ptr;
      char* str;
{
  sscanf(str, "%s %s",string_ptr->name,string_ptr->variable);
}

char* _Debug4Var_to_text (t)
      Debug4Var t;
{
  static char buf[STRLEN];
  sprintf(buf, "%s %s", t.name,t.variable);
  return (buf);
} 

int _check4Var_Debug (string)
     char* string;
{
  char *r;
  char *s;
  return((sscanf(string,"%s %s",r,s)==2) ? 1 : 0);
}    

/*********************************************
### The definition of a type of VrSampleIndex ###
**********************************************/
void _text_to_VrSampleIndex (string_ptr, str)
      VrSampleIndex* string_ptr;
     char* str;
{
  sscanf(str, "%lld",string_ptr);
}
 
char* _VrSampleIndex_to_text (t)
      VrSampleIndex t;
{
  static char buf[STRLEN];
  sprintf(buf, "%lld", t);
  return (buf);
}
 
int _check_VrSampleIndex (string)
     char* string;
{
  unsigned long NUM;
  return((sscanf(string, "%lld",
           &NUM)==1) ? 1 : 0);
}                       

/*********************************************
### The deftion of a type of VrSampleRange ###
**********************************************/
void _text_to_VrSampleRange (string_ptr, str)
      VrSampleRange* string_ptr;
     char* str;
{
  sscanf(str, "%lld %lu",&(string_ptr->index),&(string_ptr->size));
}
 
char* _VrSampleRange_to_text (t)
      VrSampleRange t;
{
  static char buf[STRLEN];
  sprintf(buf, "%lld %lu", t.index, t.size);
  return (buf);
}
 
int _check_VrSampleRange (string)
     char* string;
{
  unsigned long INDX, SZ;
  return((sscanf(string, "%lld %lu",&INDX, &SZ
           )==2) ? 1 : 0);
}  
 
/********************************************
 ### The deftion of a type of UnsignedLL  ###
 ********************************************/
void _text_to_UnsignedLL (string_ptr, str)
      UnsignedLL* string_ptr;
     char* str;
{
  sscanf(str, "%lld",string_ptr);
}
 
char* _UnsignedLL_to_text (t)
      UnsignedLL t;
{
  static char buf[21];
  sprintf(buf, "%lld", t);
  return (buf);
}
 
int _check_UnsignedLL (string)
     char* string;
{
  unsigned long long x;
  return((sscanf(string, "%lld",&x)==1) ? 1 : 0);
}  
 
/********************************************
 ### The deftion of a type of UnsignedLong  ###
 ********************************************/
void _text_to_UnsignedLong (string_ptr, str)
      UnsignedLong* string_ptr;
     char* str;
{
  sscanf(str, "%lu",string_ptr);
}
 
char* _UnsignedLong_to_text (t)
      UnsignedLong t;
{
  static char buf[21];
  sprintf(buf, "%lu", t);
  return (buf);
}
 
int _check_UnsignedLong (string)
     char* string;
{
  unsigned long x;
  return((sscanf(string, "%lu",&x)==1) ? 1 : 0);
}  

/********************************************
 ### The deftion of a type of UnsignedInt ###
 ********************************************/
void _text_to_UnsignedInt (string_ptr, str)
      UnsignedInt* string_ptr;
     char* str;
{
  sscanf(str, "%u",string_ptr);
}
 
char* _UnsignedInt_to_text (t)
      UnsignedInt t;
{
  static char buf[10];
  sprintf(buf, "%u", t);
  return (buf);
}
 
int _check_UnsignedInt (string)
     char* string;
{
  unsigned int x;
  return((sscanf(string, "%u",&x)==1) ? 1 : 0);
}  


/********************************************
 ### The deftion of a type of float ###
 ********************************************/
void _text_to_Float_Type (string_ptr, str)
      Float_Type* string_ptr;
     char* str;
{
  sscanf(str, "%f",string_ptr);
}
 
char* _Float_Type_to_text (t)
      Float_Type t;
{
  static char buf[10];
  sprintf(buf, "%f", t);
  return (buf);
}
 
int _check_Float_Type (string)
     char* string;
{
  float x;
  return((sscanf(string, "%f",&x)==1) ? 1 : 0);
}  


/***********************************************
 * d2str
 * parameter:(int) return : string
 ***********************************************/

char * d2str(int x)
{
  char *str = (char *)malloc(sizeof(char [10]));
  /*char str[STRLEN]="0";*/
  sprintf(str, "%d",x);
  return (str);
}

/***********************************************
 * ud2str
 * parameter:(unsigned int) return : string
 ***********************************************/

char *ud2str(unsigned int x)
{
  char *str = (char *)malloc(sizeof(char [10]));
  /*char str[STRLEN]="0";*/
  sprintf(str, "%u",x);
  return (str);
}

/***********************************************
 * lld2str
 * parameter : long long, return value : string
 ***********************************************/

char *lld2str(unsigned long long x)
{
  char *str = (char *)malloc(sizeof(char [20]));
  /*char str[STRLEN]="0";*/
  sprintf(str, "%lld",x);
  return (str);
}

/************************************************
 * str2lld
 * parameter : char string, return : long long
 ************************************************/

unsigned long long str2lld(char * str)
{
  unsigned long long data;
  sscanf(str, "%lld", &data);
  return data;
}

/************************************************
 * uld2str
 * parameter : unsigned long, return : string
 ************************************************/

char *uld2str(unsigned long x)
{
  char *str = (char *)malloc(sizeof(char [20]));
  /*char str[STRLEN]="0";*/
  sprintf(str, "%lu",x);
  return (str);
} 

/************************************************
 * str2uld
 * parameter : char string, return : unsigned long
 ************************************************/

unsigned long str2uld(char * str)
{
  unsigned long data;
  sscanf(str, "%lu", &data);
  return data;
}

/************************************************
 * SRange2str
 * parameter : VrSampleRange, return : string
 ************************************************/

char *SRange2str(VrSampleRange x)
{
  char *str = (char *)malloc(sizeof(char [40]));
  /*char str[STRLEN]="0";*/
  sprintf(str, "%lld %lu",x.index, x.size);
  return (str);
}

/************************************************
 * str2SRange
 * parameter : char string, return : VrSampleRange
 ************************************************/

VrSampleRange str2SRange(char *str)
{
  VrSampleRange data;
  sscanf(str, "%lld %lu",&data.index, &data.size);
#ifdef DEBUG
  printf("string into VrSampleRange\n");
  printf("str2SRange [%lld, %lu]\n",data.index,data.size);
#endif
  return data;
} 

/************************************************
 * setMaxlld
 * parameter : string, return void
 ************************************************/

void setMaxlld(char *s)
{
  strcpy(s,"1844674000000000000");
}  

char* GETMARKEDWP(char *r)
{
#ifndef XES
  /*char str[STRLEN]="0";
  VrSampleIndex index=InterGetMarkedWP(r);
  sprintf(str, "%lld",index);
#ifdef DEBUG
  printf("[1]GETMARKEDWP => %lld = %s(strl)\n",index,str);
  #endif*/
  return lld2str(InterGetMarkedWP(r));
#endif
}

void GETMARKEDWPNEW(StrlSampleIndex str,char *r)
{
#ifndef XES
  VrSampleIndex index=InterGetMarkedWP(r);
  sprintf(&str, "%lld",index);
#ifdef DEBUG
  printf("[1]GETMARKEDWPNEW => %lld = %s(strl)\n",index,&str);
#endif
#endif
}

void GETMARKEDWPVR(VrSampleIndex* str,char *r)
{
#ifndef XES
  *str=InterGetMarkedWP(r);
#ifdef DEBUG
  printf("[1]GETMARKEDWPVR => %lld\n",*str);
#endif
#endif
}

StrlSampleIndex GET_MYMARKEDINDEX(char *r)
{
#ifndef XES
  /*char str[STRLEN]="0";
  VrSampleIndex index=InterGetMymarkedIndex(r);
  sprintf(str, "%lld",index);*/
  return lld2str(InterGetMymarkedIndex(r));
#endif
} 

void GET_MYMARKEDINDEXNEW(StrlSampleIndex indx,char *r)
{
#ifndef XES
  VrSampleIndex index=InterGetMymarkedIndex(r);
  sprintf(&indx, "%lld",index);
#ifdef DEBUG
  printf("[1]GET_MYMARKEDINDEXNEW => %lld = %s(strl)\n",index,&indx);
#endif

#endif
}
 
void GET_MYMARKEDINDEXVR(VrSampleIndex* indx,char *r)
{
#ifndef XES
  *indx=InterGetMymarkedIndex(r);
#endif
} 

StrlSampleSize GET_MYMARKEDSIZE(char *r)
{
#ifndef XES
  /*char str[STRLEN]="0";
  unsigned long sz=InterGetMymarkedSize(r);
  sprintf(str, "%lld",sz);*/
  return lld2str(InterGetMymarkedSize(r));
#endif
} 

void GET_MYMARKEDSIZENEW(StrlSampleSize str,char *r)
{
#ifndef XES
  unsigned long sz=InterGetMymarkedSize(r);
  sprintf(&str, "%lld",sz);
#ifdef DEBUG
  printf("[1]GET_MYMARKEDSIZENEW => %lld = %s(strl)\n",sz,&str);
#endif
#endif
} 
/*
void GET_MYMARKEDSIZEVR(VrSampleSize* str,char *r)
{
#ifndef XES
  unsigned int st=InterGetMymarkedSize(r);
  *str=st;
#endif
} 
*/
StrlSampleRange GET_MYMARKEDDATA(char *r)
{
#ifndef XES
  char str[80];
  VrSampleRange rs=InterGetMymarkedData(r);
  sprintf(str, "%lld %lu",rs.index, rs.size);
  /*rg=SRange2str(InterGetMymarkedData(r));*/
  return str;
#endif
}

void GET_MYMARKEDDATANEW(StrlSampleRange str,char *r)
{
#ifndef XES
  VrSampleRange rs=InterGetMymarkedData(r);
  sprintf(&str, "%lld %lu",rs.index, rs.size);
#ifdef DEBUG
  printf("[1]GET_MYMARKEDDATANEW => %s(strl)\n",&str);
#endif

#endif
}

void GET_MYMARKEDDATAVR(VrSampleRange* str,char *r)
{
#ifndef XES
  *str=InterGetMymarkedData(r);
#endif
}

void SET_MARKEDWP(char *r,StrlSampleIndex sz)
{
#ifndef XES
  InterSet_MarkedWP(r,str2lld(sz));
#ifdef DEBUG
  printf("[1]SET_MARKEDWP =>%s: index=%s\n",r,sz);
#endif
#endif
}

void SET_MARKEDWPVR(char *r,VrSampleIndex sz)
{
#ifndef XES
  InterSet_MarkedWP(r,sz);
#endif
}

StrlSampleIndex GETWP(char *r)
{
#ifndef XES
  /*char str[STRLEN]="0";
  VrSampleIndex index=InterGetWP(r);
  sprintf(str, "%lld",index);
#ifdef DEBUG
  printf("[1]GETWP => %lld = %s(strl)\n",index,str);
  #endif*/
  return lld2str(InterGetWP(r));
#endif
}

void GETWPNEW(StrlSampleIndex str,char *r)
{
#ifndef XES
  VrSampleIndex index=InterGetWP(r);
  sprintf(&str, "%lld",index);
#ifdef DEBUG
  printf("[1]GETWPNEW => %lld = %s(strl)\n",index,&str);
#endif
#endif
}

void GETWPVR(VrSampleIndex* str,char *r)
{
#ifndef XES
  *str=InterGetWP(r);
#ifdef DEBUG
  printf("[1]GETWPVR => %lld\n",*str);
#endif
#endif
}

int CMPSAMPLEINDEX(StrlSampleIndex s, StrlSampleIndex r)
{
  return (str2lld(s)-str2lld(r));
}

int CMPSAMPLESIZE(StrlSampleSize s,StrlSampleSize r)
{
  return (str2uld(s)-str2uld(r));
}

int CMPSAMPLEINDEXVR(VrSampleIndex s, VrSampleIndex r)
{
  return (s-r);
}
/*
int CMPSAMPLESIZEVR(VrSampleSize s,VrSampleSize r)
{
  return (s-r);
}
*/
int GET_NUMBERINPUTS(char *r)
{
#ifndef XES
  return InterGetNumberInputs(r);
#endif
}

/************************************************
 * DEBUG_S_INDEX
 * parameter:string,StrlSampleIndex ;return Debug4Var
 ************************************************/
/*
void DEBUG_S_INDEX(Debug4Var* dv,char *r,StrlSampleIndex s)
{
  strcpy(dv->name,r);
  strcpy(dv->variable,s);
}
*/
Debug4Var DEBUG_INDEX(char *r,StrlSampleIndex s)
{
  Debug4Var dv;
  strcpy(dv.name,r);
  strcpy(dv.variable,s);
  return dv;
}

/************************************************
 * DEBUG_S_RANGE
 * parameter:string,StrlSampleRange ;return Debug4Var
 ************************************************/
Debug4Var DEBUG_RANGE(char *r,StrlSampleRange s)
{
  Debug4Var dv;
  strcpy(dv.name,r);
  strcpy(dv.variable,s);
  return dv;
}

/************************************************
 * DEBUG_S_INT
 * parameter:(string,int) ;return Debug4Var
 ************************************************/
Debug4Var DEBUG_INT(char *r,int s)
{
  /*  Debug4Var dv[STRLEN];
  strcpy(dv.name,r);
  strcpy(
  d2str(dv.variable,s);
  return dv;*/
}

/************************************************
 * DEBUG_S_UNINT
 * parameter:(string,int) ;return Debug4Var
 ************************************************/
Debug4Var DEBUG_UNINT(char *r,UnsignedInt s)
{
  /*  Debug4Var dv;
  strcpy(dv.name,r);
  ud2str(dv.variable, s);
  return dv;*/
}

UnsignedInt GET_OUTPUTSIZE(char *r)
{
#ifndef XES
  return InterGetOutputSize(r);
#endif
}


/***************************************************
 * These funcs are used in i_mod and sinks modules
 ***************************************************/


int CHECKSAMPLESIZE(StrlSampleRange a,StrlSampleRange b)
{
  VrSampleRange data1,data2;
  
  sscanf(a,"%lld %lu",&data1.index,&data1.size);
  sscanf(b,"%lld %lu",&data2.index,&data2.size);
  data1.index=data1.index + data1.size;
  data2.size=data2.size*2;
  data2.index=data2.index + data2.size;

  return data1.index-data2.index;
}
/*
int CHECKSAMPLESIZEVR(VrSampleRange a,VrSampleRange b)
{
  return ((a.index+a.size)-(b.index+b.size*2));
}
*/
StrlSampleRange UPDATESAMPLE(StrlSampleRange str)
{
  VrSampleRange data;
  StrlSampleRange ret;
  sscanf(str,"%lld %lu",&data.index,&data.size);
  data.index=data.index + data.size;
  sprintf(ret, "%lld %lu",data.index, data.size);
#ifdef DEBUG
  printf("[1]UPDATESAMPLE => %s(strl)\n",ret);
#endif
  return ret;
}

void UPDATESAMPLENEW(StrlSampleRange str)
{
  VrSampleRange data;
  sscanf(&str,"%lld %lu",&data.index,&data.size);
  data.index=data.index + data.size;
  sprintf(&str, "%lld %lu",data.index, data.size);
#ifdef DEBUG
  printf("[1]UPDATESAMPLENEW => %s(strl)\n",&str);
#endif
}
/*
void UPDATESAMPLEVR(VRSampleRange* a)
{
  a->index=a->index + a->size;
}
*/
StrlSampleRange COMP_FOR_MAINSINK(StrlSampleRange a,char *r)
{
#ifndef XES
  VrSampleRange data;
  sscanf(a,"%lld %lu",&data.index,&data.size);
  data.index=data.index + data.size;
  return InterComputeForMainSink(r);
#endif
}


StrlSampleRange INSIDE_COMP_FIT(StrlSampleRange x, StrlSampleRange y,char *r)
{
#ifndef XES
  VrSampleRange data1, data2;
  VrSampleRange *temp;
  StrlSampleRange str;
  int portion;
  int i;
  sscanf(x, "%lld %lu",&data1.index,&data1.size);
  sscanf(y, "%lld %lu",&data2.index,&data2.size);
  /*  portion=(int) data1.size/data2.size;
      for (i=0;i<portion;i=i+1){ */
  for(;;){
    InterComputeForMainSink(r);
    if((data1.index+data1.size)>=(data2.index+2*data2.size))
      data2.index=data2.index + data2.size;
    else
      break;
    temp=InterFitRangeForMainSink(data2,r);
    data2.index=temp->index;
    data2.size=temp->size;
  }
  sprintf(str, "%lld %lu",data2.index, data2.size);
  /*str=SRange2str(data2);*/
  return str;
#endif
}

void CONNECT_MODULES(char *r,char *s,int i,int j)
{
#ifndef XES
  InterConnectModules(r,s,i,j);
#endif
}

void INITIAL_SINK(char *r)
{
#ifndef XES
  InterInitializeSink(r);
#endif
}

/*****************************************
 * check await tick cycle
 *****************************************/
#ifdef PERMON
void LOCALAWAITTICKSTART(char *r)
{
#ifndef XES
  InterLocalAwaitTSTARTcount(r);
#endif
}
void LOCALAWAITTICKSTOP(char *r)
{
#ifndef XES
  InterLocalAwaitTSTOPcount(r);
#endif
}
void GLOBALAWAITTICKSTART()
{
#ifndef XES
  InterGlobalAwaitTSTARTcount();
#endif
}
void GLOBALAWAITTICKSTOP()
{
#ifndef XES
  InterGlobalAwaitTSTOPcount();
#endif
}
void GLOBALINCAWAITTICK()
{
#ifndef XES
  InterGlobalIncAwaitTick();
#endif
}
void LOCALINCAWAITTICK(char *r)
{
#ifndef XES
  InterLocalIncAwaitTick(r);
#endif
}
#endif
/***************************************
 * scheduling function
 ***************************************/
float GET_FREQUENCY(char *r)
{
#ifndef XES
  float fq;
  fq=InterGetFrequency(r);
  /*fprintf(stderr,"sink's fq :\t%f\n",fq);*/
  return fq;
#endif
}

UnsignedLong NEWGETWP(char *r)
{
#ifndef XES
  return InterGetWP(r);
#endif
}

UnsignedLL GET_TIMESTAMP()
{
  struct timeval now; 
  gettimeofday(&now,NULL);
  return (now.tv_sec * 1000000 + now.tv_usec);
}

int ELAPSE_TIME(UnsignedLL prev_time,double dtsec)
{
  struct timeval now; 
  unsigned long long this_time;
  gettimeofday(&now,NULL);
  this_time=now.tv_sec * 1000000 + now.tv_usec;
  if ((this_time-prev_time)>=dtsec*1000000) 
    return 1;
  else
    return 0;
}
  
int ALAMEACHSEC(float dtsec)
{
  usleep((unsigned long long)dtsec*1000000);
  return 1;
}

UnsignedLL EVAL_TS_TM(float infq,float outfq, double dt, UnsignedLong this_sample, UnsignedLong prev_sample)
{
  /*
  fprintf(stderr,"prev_sample :\t%f\t\t this_sample :\t%ld\n",prev_sample,this_sample);
  fprintf(stderr,"infq :\t%f\t outfq :\t%f \t dt :\t%f\n",infq,outfq,dt);
  fprintf(stderr,"outfq*dt :\t%f \t\t diff_sample :\t%ld \n",(double)outfq*dt,(this_sample-prev_sample));
  */
  if ((outfq*dt) > (this_sample-prev_sample)){
    /*
    fprintf(stderr,"%lld\t%f\n",(double)(outfq*dt)-(double)(this_sample-prev_sample),(infq/outfq));
    fprintf(stderr,"missed deadline : skip\t%f\n",(unsigned long long)((unsigned long long)(outfq*dt)-(this_sample-prev_sample))*(infq/outfq));
    */
    return (unsigned long long)((unsigned long long)(outfq*dt)-(this_sample-prev_sample))*(infq/outfq);
  }
  return 0;
}

UnsignedLL EVAL_TS(float fq, StrlSampleRange sm, UnsignedLL dt1, UnsignedLL dt2)
{
  unsigned long long est_sm;
  VrSampleRange data;
  sscanf(sm, "%lld %lu",&data.index, &data.size);
  est_sm=(unsigned long long)(((dt1-dt2)/1000000)*fq); /* sec=usec/1000000 */
  if(data.size < est_sm){
    printf("missed deadline : skip\t%lld\n",(est_sm-data.size));
    return est_sm-data.size;
  }
  return 0;
}

StrlSampleIndex SKIP_SAMPLEDATA(UnsignedLL sm,StrlSampleIndex rg)
{
  StrlSampleIndex str;
  sprintf(str, "%lld",str2lld(rg)+sm);
  /*str=lld2str(str2lld(rg)+sm);*/
  return str;
}

int CMPSMPINDEX(float diff,StrlSampleRange insample,StrlSampleRange outsample)
{
  VrSampleRange indata, outdata;
  sscanf(insample, "%lld %lu",&indata.index, &indata.size);
  sscanf(outsample, "%lld %lu",&outdata.index, &outdata.size);
  if ((indata.size*(int)diff)==outdata.index)
    return 1;
  else
    return 0;
}

int CMPULL(UnsignedLL x,UnsignedLL y)
{
  if (x>y)
    return 1;
  else
    return 0;
}

void SKIPPING_DATA(UnsignedLL size)
{
#ifndef XES
  InterSaveSkippedDataSize(size);
  /*fprintf(stderr, "skipping\t %d (input sample)\n",abs(size));*/
#endif
}
