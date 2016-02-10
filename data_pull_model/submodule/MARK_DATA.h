/* This is MARK_DATA.h */

#ifndef _DATATYPE_H
#define _DATATYPE_H

#include "../include/datatype.h"

#endif

StrlSampleIndex ADD_INDEX_SIZE(char*);
int SUBTRACT_A_B(StrlSampleIndex,StrlSampleIndex);
int ROUNDUP_REQUESTSIZE(int,UnsignedInt);
StrlSampleRange SET_SAMPLERANGE(StrlSampleIndex y,int z);
StrlSampleRange FORECASTS(StrlSampleRange,char*);
int REAL_MARK_DATA(StrlSampleIndex,int,int,StrlSampleRange,char*);
