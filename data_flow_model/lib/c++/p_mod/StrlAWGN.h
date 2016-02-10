/*  Modified  2000, 2001  INRIA */

/* -*- Mode: c++ -*- 
 *
 *  Copyright 1997 Massachusetts Institute of Technology
 * 
 *  Permission to use, copy, modify, distribute, and sell this software and its
 *  documentation for any purpose is hereby granted without fee, provided that
 *  the above copyright notice appear in all copies and that both that
 *  copyright notice and this permission notice appear in supporting
 *  documentation, and that the name of M.I.T. not be used in advertising or
 *  publicity pertaining to distribution of the software without specific,
 *  written prior permission.  M.I.T. makes no representations about the
 *  suitability of this software for any purpose.  It is provided "as is"
 *  without express or implied warranty.
 * 
 */


#ifndef _STRLAWGN_H_
#define _STRLAWGN_H_

#include <StrlSigProc.h>
#include <StrlCycleCount.h>

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

template<class iType>
class StrlAWGN : public StrlSigProc {
protected:
  int maxAmp, psnr;
  float sigma;
  long seed;
  virtual void initialize() {};
  float ran1();
  float gasdev();
public: 
  virtual const char *name() { return "StrlAWGN"; }
  virtual int work(VrSampleRange output, void *o[],
		   VrSampleRange inputs[], void *i[]);
  StrlAWGN(int snr = 72,int ma = 64);
  void setSNR(int arg_snr);
};

template<class iType> float
StrlAWGN<iType>::ran1()
{
    int j;
    long k;
    static long iy=0;
    static long iv[NTAB];
    float temp;

    if (seed <= 0 || !iy) {
        if (-seed < 1) seed=1;
        else seed = -seed;
        for (j=NTAB+7;j>=0;j--) {
            k=seed/IQ;
            seed=IA*(seed-k*IQ)-IR*k;
            if (seed < 0) seed += IM;
            if (j < NTAB) iv[j] = seed;
        }
        iy=iv[0];
    }
    k=(seed)/IQ;
    seed=IA*(seed-k*IQ)-IR*k;
    if (seed < 0)
        seed += IM;
    j=iy/NDIV;
    iy=iv[j];
    iv[j] = seed;
    temp=AM * iy;
    if (temp > RNMX)
        temp = RNMX;
    return temp;
}

template<class iType> float
StrlAWGN<iType>::gasdev()
{
    static int iset=0;
    static float gset;
    float fac,rsq,v1,v2;

    iset = 1 - iset;
    if  (iset) {
        do {
            v1=2.0*ran1()-1.0;
            v2=2.0*ran1()-1.0;
            rsq=v1*v1+v2*v2;
        } while (rsq >= 1.0 || rsq == 0.0);
        fac= sqrt(-2.0*log(rsq)/rsq) * sigma;
        gset=v1*fac;
        return v2*fac;
    }
    return gset;
}

template<class iType> int
StrlAWGN<iType>::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  iType **i = (iType **)ai;
  iType **o = (iType **)ao;
  int size = output.size;
  while (size -->0) {
    int temp = *i[0] + (int)gasdev();
//jca printf ("i[0] %d temp %d sigma %e\n", *i[0], temp, gasdev() );
	i[0]++;
    if (temp < -128)
       temp = -128;
    else if (temp > 127)
       temp = 127;
    *o[0]++ = temp;
  }
  return output.size;
}

template<class iType> void
StrlAWGN<iType>::setSNR(int arg_snr)
{
  psnr = arg_snr;
  sigma = maxAmp / pow(10,(psnr/(double)20));
printf ("snr %d ma %d sigma %f\n", psnr, maxAmp, sigma);
}

template<class iType>
StrlAWGN<iType>::StrlAWGN(int snr,int ma)
  : StrlSigProc(1, sizeof(iType), sizeof(iType))
{
  maxAmp = ma;
  setSNR(snr);

  /* seeding random number generator with the cycle counter */
  /* seed needs to be negative */
#if defined (__i386__)
  // Need to fix seeding
  seed = 3021;
  /*
  long long tmp = CYCLE_COUNT();
  if (tmp < 0) seed = -tmp;
  else seed = tmp;
  */
#else
  seed = 3021;
#endif
}
#endif
