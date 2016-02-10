#include "COMPUTE_DATA.h"
#include <interface.h>  /* C++ class header */

#ifndef _DATATYPE_H
#define _DATATYPE_H

#include <datatype.h>

#endif

/*---------------------------------------------
 * Describe Procedure & Function
 * This is COMPUTE_DATA_data.c
 *---------------------------------------------*/

int CHECK_MYWRITERLL(char *r)
{
  return InterGet_Mywriterll(r);
}

int CHECK_MYMARKEDDATA_SIZE(char *r)
{
  return InterCheck_MymarkedDataSize(r);
}

StrlSampleSize REALCOMPUTEDATA(char *r,int x)
{
  StrlSampleSize sz;
  sz=uld2str(InterComputeData(r,x));
  return sz;
}

StrlSampleIndex ADD_SAMPLEINDEX(StrlSampleIndex a,StrlSampleSize b)
{
  return lld2str(str2lld(a)+str2lld(b));
}

void WRITEDATA(char *r,int dx)
{
  InterWriteData(r,dx);
}
