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


#ifndef _STRLMMX_H_
#define _STRLMMX_H_

//long long is 64 bits
typedef unsigned long long mmxpc2; //Packed Complex (2 vals, 16 bit-precision)
typedef unsigned long long mmxpcr; //Packed Complex Result (32 bit precision)

extern "C" void _vradd_mmx(char array1[], char array2[], unsigned int x, char array3[]);
extern "C" void _ccvdp_mmx(char inputArray[], mmxpc2 *mmxTaps,mmxpcr *r,int numTaps);
extern "C" int _query_mmx();
extern "C" void _vrproc_mmx(short array1[], short array2[],unsigned int length, short array3[]);

static inline int queryMMX() {return _query_mmx();}

class mmxTaps {
private:
  StrlComplex *taps;
  int numTaps;
  char *memPointer;
  mmxpc2 *pTaps;
  float real_fixed16factor; //1bit sign 15 bit mantissa
  float imag_fixed16factor; //1bit sign 15 bit mantissa
public:
  mmxTaps() : numTaps(0),memPointer(NULL) {};
  mmxTaps(StrlComplex[], int);
  inline int mmxReady() {return (numTaps!=0);}
  StrlComplex mmxCVDProduct(char inputArray[]);
  ~mmxTaps();
  inline mmxpc2 vrcToMMXPC2(StrlComplex a, StrlComplex b) {
    short Ar=(short) (a.real()*real_fixed16factor);
    short Ai=(short) (a.imag()*imag_fixed16factor);
    short Br=(short) (b.real()*real_fixed16factor);
    short Bi=(short) (b.imag()*imag_fixed16factor);
    mmxpc2 x = (unsigned long long) Br & 0xffff;
    x <<= 16;
    x |= (unsigned long long) Ar & 0xffff;
    x <<= 16;
    x |= (unsigned long long) Bi & 0xffff;
    x <<= 16;
    x |= (unsigned long long) Ai & 0xffff;
    return x; //(Br Ar Bi Ai)
  } 

  inline StrlComplex MMXPCRToVrc(mmxpcr p) {
    long Pr=(long) (p>>32);
    long Pi=(long) (p&0xFFFFFFFF);
    float fPr=(float) Pr / ((float) real_fixed16factor);
    float fPi=(float) Pi / ((float) imag_fixed16factor);
    return StrlComplex(fPr,fPi);
  }
};

inline
mmxTaps::mmxTaps(StrlComplex mytaps[],int n) : taps(mytaps), numTaps(n){
  if(!_query_mmx()) {
    numTaps=0;
    return;
  }
  //determine fixed16factor
  float rmax=-1, rmin=100;
  float imax=-1, imin=100;
  for(int x=0;x<numTaps;x++) {
    float r=abs(real(taps[x]));
    float i=abs(imag(taps[x]));
    if(r<rmin && r!=0) rmin=r;
    if(r>rmax) rmax=r;
    if(i<imin && i!=0) imin=i;
    if(i>imax) imax=i;
  }
  
  /*fprintf(stderr, "RMax %f, Rmin %f, IMax %f, Imin  %f\n", rmax,rmin,imax,imin);
  float factor1 = (1<<15)/rmax;
  float factor2 = (1<<15)/rmin;
  fprintf(stderr, "Size of real range: %f\n", rmax/rmin);
  */

  real_fixed16factor=(1<<15)/(rmax+rmin);
  
  /*
  fprintf(stderr, "RFactor = %f\n", real_fixed16factor);
  fprintf(stderr, "Real Max, Min in fixed pt: %d %d\n",
	((short) (rmax*real_fixed16factor)), ((short) (rmin*real_fixed16factor)) );
  */

  /*
  factor1 = (1<<15)/imax;
  factor2 = (1<<15)/imin;
  fprintf(stderr, "Size of imag range: %f\n", imax/imin);
  */

  imag_fixed16factor=(1<<15)/(imax+imin);

  /*
  fprintf(stderr, "IFactor = %f\n", imag_fixed16factor);
  fprintf(stderr, "Imag Max, Min in fixed pt: %d %d\n",
	((short) (imax*imag_fixed16factor)), ((short) (imin*imag_fixed16factor)));
  */

  int size = numTaps/2+1+4;   //4 is in case loop which does 8 mults runs over
  //mmxpc2 *pTaps=new mmxpc2[size*2];

  int iSizeOf = sizeof(mmxpc2);
  unsigned long csize = size*2*iSizeOf+iSizeOf;
  memPointer = new char[csize];
  unsigned int iAdjust = (unsigned int) memPointer % (unsigned int) iSizeOf;
  pTaps = (mmxpc2 *) ((unsigned int) (iSizeOf-iAdjust) +
		      (unsigned int) memPointer);
  pTaps[0]=vrcToMMXPC2(taps[0],taps[1]);
  pTaps[size]=vrcToMMXPC2(0,taps[0]);
  for(int x=1;x<size-1-4;x++) {
    pTaps[x]=vrcToMMXPC2(taps[2*x],taps[2*x+1]);
    pTaps[size+x]=vrcToMMXPC2(taps[2*x-1],taps[2*x]);
  }
  if(numTaps%2==0) {
    pTaps[size-1-4] = 0;
    pTaps[2*size-1-4] = vrcToMMXPC2(taps[2*(size-4)-3],0);
  } else {
    pTaps[size-1-4] = vrcToMMXPC2(taps[2*(size-4)-2],0);
    pTaps[2*size-1-4] = vrcToMMXPC2(taps[2*(size-4)-3],taps[2*(size-4)-2]);
  }
  for(int x=size-4;x<size;x++)
    pTaps[x]=pTaps[size+x]=0;
}

inline
mmxTaps::~mmxTaps() {
  if(memPointer!=NULL)
    delete [] memPointer;
}

inline
StrlComplex
mmxTaps::mmxCVDProduct(char inputArray[]) {
  StrlComplex r;
  StrlComplex rextra = 0;
  mmxpc2 *pt=pTaps;
  StrlComplex *t = taps;
  int n=numTaps;

  if(numTaps==0) //MMX not present or mmxTaps not initialized
    return 0;

  unsigned long p1 = (unsigned long) inputArray;
  p1 &= 7;
  if(p1!=0) {
    /**** This stuff never gets used since the way the GuPPi drivers ****/
    /**** ensures out data is always aligned...                      ****/
    /**** (It also has therefore NOT been tested!!!)                 ****/
    if(p1 & 1) {
      //fprintf(stderr, "ADJUST1\n");
      //use second array for alignment (point to 2nd tap)
      pt+=(numTaps/2+1+4);
    }
    //fprintf(stderr, "Adjust: %d\n", p1);
    p1 = 8 - p1;
    pt += p1/2;
    n-=p1;
    while(p1--) {
      rextra +=  *t++ * *inputArray++;
    }
  }

  mmxpcr pr;

  int nextra = n & 0x7; //extra after multiple of 8

  _ccvdp_mmx(inputArray,pt,&pr,n-nextra);

  if(nextra>0) {
    t+=n-nextra;
    inputArray+=n-nextra;
    while(nextra--) {
      rextra +=  *t++ * *inputArray++;
    }
  }

  r = MMXPCRToVrc(pr);
  r += rextra;
  return r;
}

inline
void
mmxAdd(char in1[],char in2[],unsigned int x, char out[]) {
  if(x==0) //MMX not present or input arrays not present
    return;
   _vradd_mmx(in1, in2, x, out);
}

inline
void
mmxFMMulAdd(short in1[], short in2[], unsigned int length, short out[]) {
  if(length==0) //nothing to process
    return;

  //***Assumes length of in2 is a multiple of 4***
  //***Assumes length of in1 is at least 4     ***
  if((length % 16)==0)
    _vrproc_mmx(in1, in2, length, out);
      else {
	unsigned int n = length % 16;
	unsigned int p3 = length - n;
	_vrproc_mmx(in1, in2, p3, out);
	for(unsigned int i=p3;i<=length;i+=4) {
	  unsigned int q3= i/4;
	  out[q3] = (in1[0] * in2[i]) + (in1[1] * in2[i+1]) + (in1[2] * in2[i+2]) + (in1[3] * in2[i+3]);
	}
      }
}

#endif

