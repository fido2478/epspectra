/*--------------------------------
 * datatype.h
 *--------------------------------*/
#ifndef _DATATYPE
#define _DATATYPE

#ifndef _VRSAMPLE
#define _VRSAMPLE

typedef unsigned long long VrSampleIndex;

typedef struct {
        VrSampleIndex index;
        unsigned long size;
} VrSampleRange;

#endif _VRSAMPLE

#define _VrSampleIndex(X,Y) (*(X)=(Y))  
#define _VrSampleRange(X,Y) (*(X)=(Y))

typedef char* StrlSampleIndex;
typedef char* StrlSampleSize;
typedef char* StrlSampleRange;

#define _StrlSampleIndex(X,Y) (*(X)=(Y))
#define _StrlSampleSize(X,Y) (*(X)=(Y)) 
#define _StrlSampleRange(X,Y) (*(X)=(Y)) 

typedef struct {
  char name[50];
  char variable[50];
} Debug4Var;

#define _Debug4Var(X,Y) (*(X)=(Y))

typedef unsigned int UnsignedInt;

#define _UnsignedInt(X,Y) (*(X)=(Y))

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
StrlSampleIndex GETMARKEDWP(char*);
StrlSampleIndex GET_MYMARKEDINDEX(char *);
StrlSampleSize GET_MYMARKEDSIZE(char *r);
StrlSampleRange GET_MYMARKEDDATA(char *r);
void SET_MARKEDWP(char *r,StrlSampleIndex sz);
StrlSampleIndex GETWP(char*);
StrlSampleRange GET_S_RANGE(char *r);
int CMPSAMPLEINDEX(StrlSampleIndex, StrlSampleIndex);
int CMPSAMPLEINDEX1(StrlSampleIndex, StrlSampleIndex);
int CMPSAMPLESIZE(StrlSampleSize,StrlSampleSize);
int GET_NUMBERINPUTS(char*);
/* void DEBUG_S_INDEX(Debug4Var* dv,char *r,StrlSampleIndex s);*/
Debug4Var DEBUG_INDEX(char *r,StrlSampleIndex s);
Debug4Var DEBUG_RANGE(char *r,StrlSampleRange s);
Debug4Var DEBUG_INT(char *r,int s);
Debug4Var DEBUG_UNINT(char *r,UnsignedInt s);
UnsignedInt GET_OUTPUTSIZE(char *r);
StrlSampleIndex CHKMINRP(StrlSampleIndex pWP,StrlSampleRange rg,char *r);
void LOCALAWAITTICKSTART(char *r);
void LOCALAWAITTICKSTOP(char *r);
void GLOBALAWAITTICKSTART();
void GLOBALAWAITTICKSTOP();
#endif _DATATYPE
