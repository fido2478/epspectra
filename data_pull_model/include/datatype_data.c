/***********************************
### datatype_data.c #####
************************************/

#include <stdio.h>
#include <string.h>
#include "datatype.h"
#include <interface.h>  /* C++ class header */
#define STRLEN 80

StrlSampleIndex INITIAL_INDEX ="";
StrlSampleRange INITIAL_RANGE ="";
StrlSampleSize INITIAL_SIZE ="";
Debug4Var INITIAL_DEBUG4VAR = {"",""};
UnsignedInt INITIAL_UNSIGNEDINT=0;
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
  static char buf[STRLEN]="";
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
  static char buf[STRLEN]="";
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
  static char buf[STRLEN]="";
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
  static char buf[STRLEN]="";
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
  static char buf[STRLEN]="";
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
  static char buf[STRLEN]="";
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
  static char buf[10]="";
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
  static char buf[10]="";
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

char *d2str(int x)
{
  char *str = (char *)malloc(sizeof(char [10]));
  sprintf(str, "%d",x);
  return str;
}

/***********************************************
 * ud2str
 * parameter:(unsigned int) return : string
 ***********************************************/

char *ud2str(unsigned int x)
{
  char *str = (char *)malloc(sizeof(char [10]));
  sprintf(str, "%u",x);
  return str;
}

/***********************************************
 * lld2str
 * parameter : long long, return value : string
 ***********************************************/

char *lld2str(unsigned long long x)
{
  char *str = (char *)malloc(sizeof(char [STRLEN]));
  sprintf(str, "%lld",x);
  return str;
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
  char *str = (char *)malloc(sizeof(char [STRLEN]));
  sprintf(str, "%lu",x);
  return str;
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
  char *str = (char *)malloc(sizeof(char [STRLEN]));
  sprintf(str, "%lld %lu",x.index, x.size);
  return str;
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

StrlSampleIndex GETMARKEDWP(char *r)
{
  StrlSampleIndex str;
  VrSampleIndex index=InterGetMarkedWP(r);
  str=lld2str(index);
#ifdef DEBUG
  printf("[1]GETMARKEDWP => %lld = %s(strl)\n",index,str);
#endif
  return str;
}

StrlSampleIndex GET_MYMARKEDINDEX(char *r)
{
  StrlSampleIndex str;
  VrSampleIndex index=InterGetMymarkedIndex(r);
  str=lld2str(index);
  return str;
} 

StrlSampleSize GET_MYMARKEDSIZE(char *r)
{
  StrlSampleSize str;
  unsigned long sz=InterGetMymarkedSize(r);
  str=lld2str(sz);
  return str;
} 

StrlSampleRange GET_MYMARKEDDATA(char *r)
{
  StrlSampleRange rg=SRange2str(InterGetMymarkedData(r));
  return rg;
}

StrlSampleIndex CHKMINRP(StrlSampleIndex pWP, StrlSampleRange rg, char *r)
{
  StrlSampleIndex si=lld2str(InterminrpCheck(str2lld(pWP),str2SRange(rg),r));
  return si;
}
void SET_MARKEDWP(char *r,StrlSampleIndex sz)
{
  InterSet_MarkedWP(r,str2lld(sz));
}

StrlSampleIndex GETWP(char *r)
{
  StrlSampleIndex str;
  VrSampleIndex index=InterGetWP(r);
  str=lld2str(index);
#ifdef DEBUG
  printf("[1]GETWP => %lld = %s(strl)\n",index,str);
#endif
  return str;
}

StrlSampleRange GET_S_RANGE(char *r)
{
  
  return SRange2str(InterGetSampleRange(r));
}

int CMPSAMPLEINDEX(StrlSampleIndex s, StrlSampleIndex r)
{
  return (str2lld(s)-str2lld(r));
}

int CMPSAMPLEINDEX1(StrlSampleIndex s, StrlSampleIndex r)
{
  return (str2lld(s)-str2lld(r));
}

int CMPSAMPLESIZE(StrlSampleSize s,StrlSampleSize r)
{
  return (str2uld(s)-str2uld(r));
}

int GET_NUMBERINPUTS(char *r)
{
  return InterGetNumberInputs(r);
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
  Debug4Var dv;
  strcpy(dv.name,r);
  strcpy(dv.variable,d2str(s));
  return dv;
}

/************************************************
 * DEBUG_S_UNINT
 * parameter:(string,int) ;return Debug4Var
 ************************************************/
Debug4Var DEBUG_UNINT(char *r,UnsignedInt s)
{
  Debug4Var dv;
  strcpy(dv.name,r);
  strcpy(dv.variable,ud2str(s));
  return dv;
}

UnsignedInt GET_OUTPUTSIZE(char *r)
{
  return InterGetOutputSize(r);
}

/*****************************************
 * check await tick cycle
 *****************************************/
void LOCALAWAITTICKSTART(char *r)
{
  InterLocalAwaitTSTARTcount(r);
}
void LOCALAWAITTICKSTOP(char *r)
{
  InterLocalAwaitTSTOPcount(r);
}
void GLOBALAWAITTICKSTART()
{
  InterGlobalAwaitTSTARTcount();
}
void GLOBALAWAITTICKSTOP()
{
  InterGlobalAwaitTSTOPcount();
}
void GLOBALINCAWAITTICK()
{
  InterGlobalIncAwaitTick();
}
void LOCALINCAWAITTICK(char *r)
{
  InterLocalIncAwaitTick(r);
}
