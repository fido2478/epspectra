#include "MARK_DATA.h"
#include <interface.h>  /* C++ class header */

#ifndef _DATATYPE_H
#define _DATATYPE_H

#include <datatype.h>

#endif

/*---------------------------------------------
 * Describe Procedure & Function
 * This is MARK_DATA_data.c
 *---------------------------------------------*/

StrlSampleIndex ADD_INDEX_SIZE(char *str)
{
  VrSampleRange data;
  StrlSampleIndex indx;

  sscanf(str, "%lld\t %lu",&data.index, &data.size);
  data.index=data.index + data.size;
  indx=lld2str(data.index);
  return indx;
}

StrlSampleIndex GETINDEX(char *str)
{
  VrSampleRange data=str2SRange(str);
  StrlSampleIndex indx;

  indx=lld2str(data.index);
  return indx;
}

int SUBTRACT_A_B(StrlSampleIndex a,StrlSampleIndex b)
{
  long long x,y;
  x=str2lld(a);   y=str2lld(b);
  return (int) x-y;
}



int ROUNDUP_REQUESTSIZE(int x,UnsignedInt y)
{
  return x=(((x + y - 1)/y ) * (y));
}

StrlSampleRange SET_SAMPLERANGE(StrlSampleIndex y,int z)
{
  VrSampleRange data;
  data.index=str2lld(y);
  data.size=z;
  return SRange2str(data);
}


StrlSampleRange FORECASTS(StrlSampleRange s,char *r)
{
  return InterForecast(str2SRange(s),r);
}

int REAL_MARK_DATA(StrlSampleIndex p_wp,int req,int dm,StrlSampleRange range,char *r)
{
  VrSampleIndex x=str2lld(p_wp);
  VrSampleRange rg=str2SRange(range);
  return InterStrlmarkData(x,req,dm,rg,r);
}  
