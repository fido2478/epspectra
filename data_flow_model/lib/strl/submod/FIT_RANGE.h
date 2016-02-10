/* This is FIT_RANGE.h */

#ifndef _DATATYPE_H
#define _DATATYPE_H

#include "../../include/datatype.h"

#endif

StrlSampleIndex ADD_INDEX_SIZE(char*);
int GET_SIZE(char*);
int SUBTRACT_A_B(StrlSampleIndex,StrlSampleIndex);
int ROUNDUP_REQUESTSIZE(int,UnsignedInt);
int ROUNDOWN_SIZE(int,UnsignedInt);
StrlSampleRange SET_SAMPLERANGE(StrlSampleIndex y,int z);
StrlSampleRange FORECASTS(StrlSampleRange,char*);
StrlSampleRange DOWNCASTS(StrlSampleRange,char*);
/*void SET_SAMPLERANGENEW(char*,StrlSampleIndex y,int z);
void FORECASTSNEW(char*,StrlSampleRange,char*);
void DOWNCASTSNEW(char*,StrlSampleRange,char*);*/
int REAL_MARK_DATA(StrlSampleIndex,int,int,StrlSampleRange,char*);
int REAL_FIT_RANGE(StrlSampleIndex,int,StrlSampleRange,char*);
int GETMAXOUTSIZE(char*);
int error_exit(int);
