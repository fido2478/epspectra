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

#ifndef _VRGSMMODULATOR_H_
#define _VRGSMMODULATOR_H_
       

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <StrlSigProc.h>
#define MAX_SHORT_2 32767

typedef unsigned short    u_short;
typedef unsigned int      u_int;

template<class oType>
class GsmModulator :public StrlSigProc {

 protected:
  float B;
  int fsT; // number of samples per symbol
  int len_burst; // GSM burst length
  float *gauss; // the gaussian function for GMSK
  int len_gauss; // Number of samples in the gauss function
 public:
  GsmModulator();
  ~GsmModulator();
  virtual void initialize();
  virtual const char *name() { return "GsmModulator"; }
  //unsigned int mapSizeUp(int inputNumber, unsigned int size);
  virtual int forecast (VrSampleRange output, VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input, VrSampleRange* output);
  virtual int work(VrSampleRange output, void *o[],
		                   VrSampleRange inputs[], void *i[]);
  void GmskModulate(char *, oType *, int);
  int Gaussian(float, int, float *);
  int Convolute(float *, int, float *, int, float *);
};


template<class oType>
GsmModulator<oType>::GsmModulator():StrlSigProc(1, sizeof(char), sizeof(oType))
{
  fsT =6;
  len_burst = 148;
  
  B = 0.6;
  /* Create a Gaussian function with B=0.6 -- [-5, 5] */
  gauss = new float[10*fsT]; 
  len_gauss = Gaussian(B, fsT, gauss);
  /* Init some constants */
  
}

template<class oType>
GsmModulator<oType>::~GsmModulator() {
  delete gauss; // ancien
}


//unsigned int
//GsmModulator::mapSizeUp(int inputNumber , unsigned int size) {
// return size;
//}


template<class oType>void
GsmModulator<oType>::initialize() {

}


template<class oType>int
GsmModulator<oType>::forecast(VrSampleRange output, VrSampleRange inputs[]) 
{
  /* no history */
  inputs[0].index = output.index/fsT;//ancien  
  inputs[0].size  = output.size/fsT;// ancien 
  //inputs[0].index = output.index/(2*fsT); 
  //inputs[0].size  = output.size/(2*fsT);
#ifdef DEBUG
  printf("%s (forecast): (output) SRange[%lld, %lu] => upstream(input) SRange[%lld, %lu]\n",name(),output.index, output.size, inputs[0].index,inputs[0].size);
#endif
  return 0;
}


template<class oType>int
GsmModulator<oType>::downcast(VrSampleRange input, VrSampleRange* output) 
{
  /* no history */
  output->index=input.index*fsT; 
  output->size=input.size*fsT; 
#ifdef DEBUG
  printf("%s (downcast): input [%lld, %lu] => output [%lld, %lu]\n",name(),input.index,input.size,output->index, output->size);
#endif
  return 0;
}

template<class oType>int
GsmModulator<oType>::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  static int inc_in = len_burst*sizeof(char);
  static int inc_out = len_burst*fsT;// hkim *2*sizeof(float)
   //static int inc_out = len_burst*2*fsT;
  int len;
  int nb_bursts;
  int offset_in = 0;
  int offset_out = 0;

  char **i = (char **)ai;
  oType **o = (oType **)ao;//hkim

  len = inputs[0].size;
  nb_bursts = len/inc_in;
   
   // For each GSM bursts:
  for(int k=0; k<nb_bursts; k++) {
    
    GmskModulate(i[0] + offset_in, o[0] + offset_out, len_burst);
    /*
      //debug here:
      printf("k= %d in:\n", k);
      for(int m=0; m<inc_in; m++){
	printf("%x", i[m + offset_in]);
	if((m + offset_in) % 20 ==19)
	  printf("\n");
      }
      printf("\n");
      printf("k= %d in:\n", k);
      for(int m=0; m<inc_out; m++){
	printf("%x", i[m + offset_out]);
	if((m + offset_out) % 20 ==19)
	  printf("\n");
      }
      printf("\n");
      // end debug.
    */
    offset_in  += inc_in;
    offset_out += inc_out;
  }   
  return output.size;
}



template<class oType>void
GsmModulator<oType>::GmskModulate(char *in, oType *out, int len_symbols)
{
  const float aux = M_PI / (2.0 * fsT);
  int max = len_symbols*fsT;
  int max1 = (5+len_symbols) * fsT;
  int len_conv;
  char *symbols_expanded;
  float *symbols_integrated, *symbols_convoluted;

  symbols_expanded = new char[max];
  symbols_integrated = new float[max];
  symbols_convoluted = new float[max+10*fsT-1];
  
  /* Expand symbols with fsT factor */
  for(register int i=0; i<len_symbols; i++) {
      (void *) memset((void *)&symbols_expanded[i*fsT], ((int)in[i] ? 1: -1), 
		      (unsigned int)fsT);
  }

  /* Integrate the expanded symbols */
  symbols_integrated[0] = 0.0;
  for(register int i=1; i<max-1; i++){
    symbols_integrated[i] = symbols_integrated[i-1] + 
      (aux * symbols_expanded[i+1]);
    //fprintf(stderr, "integ %f\n", symbols_integrated[i]);
  }

 /* Convolution with the Gaussian */
    len_conv = Convolute(gauss, len_gauss, symbols_integrated, max, 
			 symbols_convoluted);

    /* Keep only the [5*fsT, (5+len_symbols)*fsT] coefficients 
     * corresponding to the convolution with the [0,1] gaussian
     * and normalize them.
     */
    {
      register float *pt_symbols_conv = &symbols_convoluted[0]; 

      for(register int i=5*fsT; i<max1; i++){
	//fprintf(stderr, "i %d %f\t", i, symbols_convoluted[i] );
	*pt_symbols_conv++ = symbols_convoluted[i] / fsT;
      }
    }

    /* Compute the baseband GMSK modulated signal */
    {
      //register float *out_re = &out[0]; //hkim
      //register float *out_im = &out[1]; //hkim
      register float val;

      for(register int i=0; i<max; i++) {
	val = symbols_convoluted[i];
	oType tmp(cos(val),sin(val));//hkim
	out[i].operator=(tmp);//hkim
	//*out_re = cos(val); //hkim
	//*out_im = sin(val); //hkim
        //out_re += 2; //hkim
        //out_im += 2; //hkim
      }
    }

  /* Add here multiplication with cos(nw0), -sin(nw0) and the summation. */
  /*
  {
    register int i;
    float f0=9.0e6;
    float w0=2.0*M_PI*f0;
    float Ts=3.69e-6/(float)fsT;
    float aux;
    
 
    for(i=0; i<max; i++) {
      aux = out->re[i]*cos(i*Ts*w0) + out->im[i]*sin(i*Ts*w0);
      printf("%d\t%f\n", i, aux);
    }
  }
  */

  /* Clean up buffers */  
  delete symbols_expanded;
  delete symbols_integrated;
  delete symbols_convoluted;
  return;
}


template<class oType>int
GsmModulator<oType>::Gaussian(float B, int fsT, float *out)
{
  const float temp1 = B*sqrt(M_PI/(2.0*log(2.0)));
  const float temp2 = - (M_PI*M_PI*(float)B*B) / (2.0*log(2.0));
  const float inc = 1.0 / fsT;
  int max = 10 * fsT;
  float *x;
  
  x = new float[max];

  x[0] = -5.0;
  for(register int i=1; i<max; i++)
    x[i] = x[i-1] + inc;
  for(register int i=0; i<max; i++)
    out[i] = temp1 * exp(temp2 * x[i] * x[i]);

  delete x;
  return(max);
  
}


template<class oType>int
GsmModulator<oType>::Convolute(float *a, int len_a, float *b, int len_b, float *out)
{
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))

  int min, max;
  int len_out = len_a + len_b -2; //TT fixed -2 instead of -1
  register float *pt_a, *pt_b, aux;
  
  for(register int k=0; k<=len_out; k++) {
    min = MAX(0, k+2-len_b);
    max = MIN(k, len_a-1);
    aux = 0.0;
    pt_a = &a[min];
    pt_b = &b[k-min];
    for(register int j=min; j<=max; j++) {
      aux += *pt_a++ * *pt_b--;
    }
    out[k] = aux;
  }
  return(len_out); 
}

#endif
