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


#include <stdio.h>
#include "main_strl.h"

/************************************
 * input define
 ************************************/
/* 
void TC_UDP_TX_I_dt(float f){
  fprintf(stderr,"\ninput dt (sec): ");
  fscanf(stderr,"%f",f);
}
void TC_UDP_TX_I_on_TimeConstraint (int t){
  fprintf(stderr,"\nDo you want to run with Time Constraint? Type 1 or 0: ");
  fscanf(stderr,"%d",t);
}
*/
void TC_UDP_TX_O_Source_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void TC_UDP_TX_O_Summer_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void TC_UDP_TX_O_Mod_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void TC_UDP_TX_O_Coder_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void TC_UDP_TX_O_Sink_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
void TC_UDP_TX_O_Scopesink_module(char* r){
#ifdef DEBUG
  fprintf(stderr,"%s\n",r);
#endif
}
/***************************************
 * print computed sample ranges
 ***************************************/
void TC_UDP_TX_O_SINK_COMPUTEDSR(char* r){
#ifdef DEBUG
  fprintf(stderr,"sink(comp):%s\n",r);
#endif
}
void TC_UDP_TX_O_SUMMER_COMPUTEDSR(char* r){
#ifdef DEBUG
  fprintf(stderr,"summer(comp):%s\n",r);
#endif
}
void TC_UDP_TX_O_SCOPESINK_COMPUTEDSR(char* r){
#ifdef DEBUG
  fprintf(stderr,"scopesink(comp)%s\n",r);
#endif
}
void TC_UDP_TX_O_MOD_COMPUTEDSR(char* r){
#ifdef DEBUG
  fprintf(stderr,"mod(comp)%s\n",r);
#endif
}
void TC_UDP_TX_O_CODER_COMPUTEDSR(char* r){
#ifdef DEBUG
  fprintf(stderr,"coder(comp):%s\n",r);
#endif
}
void TC_UDP_TX_O_SOURCE_COMPUTEDSR(char* r){
#ifdef DEBUG
  fprintf(stderr,"source(comp):%s\n",r);
#endif
}
/**************************************
 * print temporal variables
 **************************************/
void TC_UDP_TX_O_debug_source(Debug4Var r){
#ifdef DEBUG
  fprintf(stderr,"source:[%s,%s]\n",r.name,r.variable);
#endif
}
void TC_UDP_TX_O_debug_coder(Debug4Var r){
#ifdef DEBUG
  fprintf(stderr,"coder:[%s,%s]\n",r.name,r.variable);
#endif
}
void TC_UDP_TX_O_debug_mod(Debug4Var r){
#ifdef DEBUG
  fprintf(stderr,"mod:[%s,%s]\n",r.name,r.variable);
#endif
}
void TC_UDP_TX_O_debug_summer(Debug4Var r){
#ifdef DEBUG
  fprintf(stderr,"summer:[%s,%s]\n",r.name,r.variable);
#endif
}
void TC_UDP_TX_O_debug_scopesink(Debug4Var r){
#ifdef DEBUG
  fprintf(stderr,"scopesink:[%s,%s]\n",r.name,r.variable);
#endif
}
void TC_UDP_TX_O_debug_sink(Debug4Var r){
#ifdef DEBUG
  fprintf(stderr,"sink:[%s,%s]\n",r.name,r.variable);
#endif
}
/***************************************
 * print current sample ranges
 ***************************************/
void TC_UDP_TX_O_SOURCE_SRANGE(char* r){
#ifdef DEBUG
  fprintf(stderr,"source:%s\n",r);
#endif
}
void TC_UDP_TX_O_CODER_SRANGE(char* r){
#ifdef DEBUG
  fprintf(stderr,"coder:%s\n",r);
#endif
}
void TC_UDP_TX_O_MOD_SRANGE(char* r){
#ifdef DEBUG
  fprintf(stderr,"mod:%s\n",r);
#endif
}
void TC_UDP_TX_O_SUMMER_SRANGE(char* r){
#ifdef DEBUG
  fprintf(stderr,"summer:%s\n",r);
#endif
}
void TC_UDP_TX_O_SINK_SRANGE(char* r){
#ifdef DEBUG
  fprintf(stderr,"sink:%s\n",r);
#endif
}
void TC_UDP_TX_O_SCOPESINK_SRANGE(char* r){
#ifdef DEBUG
  fprintf(stderr,"scope_range:%s\n",r);
#endif
}
