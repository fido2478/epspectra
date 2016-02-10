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


#include "UDP_RX.h"
#include "../lib/interface/interface.h"  /* C++ class header */
#include <string.h>


char* GET_UDPSOURCE(int y)
{
  return InterGetUDPSource(y);
}
char* GET_FILTER(int x,int y,float w,float z)
{
  return InterGetFilter(x,y,w,z);
}
char* GET_NOISE()
{
  return InterGetNoise();
}
char* GET_CXPLOTSINK()
{
  return InterGetCXPlotSink();
}
float GET_SYMPERIODofFILTER()
{
  return InterGetSymbolPeriod();
}
void SET_SYMPERIOD(float f)
{
  InterSetSymbolPeriod(f);
}
void SET_SYMTIMING(float f)
{
  InterSetSymbolTiming(f);
}
