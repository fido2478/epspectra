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

/*--------------------------------
 * datatype.h
 *--------------------------------*/
#ifndef _DATATYPE
#define _DATATYPE

#ifndef _VRSAMPLE
#define _VRSAMPLE

enum {VR_NULL,VR_CHAR,VR_UCHAR,VR_SHORT,VR_INT,VR_FLOAT,VR_COMPLEX,
      VR_FRAME,VR_IPPACKET};

typedef unsigned long long VrSampleIndex;

typedef struct {
        VrSampleIndex index;
        unsigned long size;
} VrSampleRange;

#endif _VRSAMPLE

#define _VrSampleIndex(X,Y) (*(X)=(Y))  
#define _VrSampleRange(X,Y) (*(X)=(Y))


typedef char* StrlString;
typedef char* StrlSampleIndex;
typedef char* StrlSampleSize;
typedef char* StrlSampleRange;
#define _StrlSampleIndex(X,Y) (*(X)=(Y))
#define _StrlSampleSize(X,Y) (*(X)=(Y)) 
#define _StrlSampleRange(X,Y) (*(X)=(Y)) 
#define _StrlString(X,Y) (*(X)=(Y))

typedef struct {
  char name[50];
  char variable[50];
} Debug4Var;

#define _Debug4Var(X,Y) (*(X)=(Y))

typedef unsigned int UnsignedInt;

#define _UnsignedInt(X,Y) (*(X)=(Y))

typedef unsigned long long UnsignedLL;

#define _UnsignedLL(X,Y) (*(X)=(Y))

typedef unsigned long UnsignedLong;

#define _UnsignedLong(X,Y) (*(X)=(Y))

typedef float Float_Type;

#define _Float_Type(X,Y) (*(X)=(Y))

typedef struct {
  float second[10];
} Psecond;

#define _Psecond(X,Y) (*(X)=(Y))

char *d2str(int x);
char *ud2str(unsigned int x);
char *lld2str(unsigned long long ); 
unsigned long long str2lld(char * );
char *uld2str(unsigned long ); 
unsigned long str2uld(char * ) ;
char *SRange2str(VrSampleRange ); 
VrSampleRange str2SRange(char *) ;
void setMaxlld(char *) ;
/* Here is for mark data */
char* GETMARKEDWP(char*);
/*void GETMARKEDWPNEW(char*,char*);*/
StrlSampleIndex GET_MYMARKEDINDEX(char *);
StrlSampleSize GET_MYMARKEDSIZE(char *r);
StrlSampleRange GET_MYMARKEDDATA(char *r);
/*void GET_MYMARKEDINDEXNEW(char*,char *);
void GET_MYMARKEDSIZENEW(char*,char *r);
void GET_MYMARKEDDATANEW(char*,char *r);*/
void SET_MARKEDWP(char *r,StrlSampleIndex sz);
StrlSampleIndex GETWP(char*);
int CMPSAMPLEINDEX(StrlSampleIndex, StrlSampleIndex);
int CMPSAMPLESIZE(StrlSampleSize,StrlSampleSize);
int GET_NUMBERINPUTS(char*);
int CHECKNUMOFTIMES(StrlSampleRange x, StrlSampleRange y);
StrlSampleRange INSIDE_COMP_FIT(StrlSampleRange x, StrlSampleRange y,char *r);
/* void DEBUG_S_INDEX(Debug4Var* dv,char *r,StrlSampleIndex s);*/
Debug4Var DEBUG_INDEX(char *r,StrlSampleIndex s);
Debug4Var DEBUG_RANGE(char *r,StrlSampleRange s);
Debug4Var DEBUG_INT(char *r,int s);
Debug4Var DEBUG_UNINT(char *r,UnsignedInt s);
UnsignedInt GET_OUTPUTSIZE(char *r);

int CHECKSAMPLESIZE(StrlSampleRange,StrlSampleRange);
StrlSampleRange UPDATESAMPLE(StrlSampleRange);
/*void UPDATESAMPLENEW(StrlSampleRange*);
void UPDATESAMPLENEW(char* a);*/
StrlSampleRange COMP_FOR_MAINSINK(StrlSampleRange a,char *r);
void CONNECT_MODULES(char *r,char *s,int i,int j);
void INITIAL_SINK(char *r);
#ifdef PERMON
void LOCALAWAITTICKSTART(char *r);
void LOCALAWAITTICKSTOP(char *r);
void GLOBALAWAITTICKSTART();
void GLOBALAWAITTICKSTOP();
#endif
void SKIPPING_DATA(UnsignedLL size);
UnsignedLong NEWGETWP(char *r);
float GET_FREQUENCY(char *r);
UnsignedLL GET_TIMESTAMP();
int ELAPSE_TIME(UnsignedLL,double);
int ALAMEACHSEC(float);
UnsignedLL EVAL_TS_TM(float,float, double, UnsignedLong, UnsignedLong);
UnsignedLL EVAL_TS(float fq, StrlSampleRange sm, UnsignedLL dt1, UnsignedLL dt2);
StrlSampleIndex SKIP_SAMPLEDATA(UnsignedLL sm,StrlSampleIndex rg);
int CMPSMPINDEX(float diff,StrlSampleRange insample,StrlSampleRange outsample);
int CMPULL(UnsignedLL x,UnsignedLL y);
#endif _DATATYPE
