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

#ifndef _VRGSMDEMODULATOR_H_
#define _VRGSMDEMODULATOR_H_
       

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <StrlSigProc.h>
template<class iType>
class GsmDemodulator : public StrlSigProc {

 protected:

 public:

  int fsT; // number of samples per symbol
  int len_burst; // GSM burst length
  GsmDemodulator();
  virtual ~GsmDemodulator();
  virtual void initialize();
  virtual const char *name() { return "GsmDemodulator"; }
  //unsigned int mapSizeUp(int inputNumber, unsigned int size);
  virtual int forecast (VrSampleRange output, VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input, VrSampleRange* output);
  virtual int work(VrSampleRange output, void *o[],
                                     VrSampleRange inputs[], void *i[]);
  void GmskDemodulate(iType *, char *, int, int);
  void GetPhase(iType *, int, float *);
  void SmoothPhase(float *, int);
  void CrossCorrelation(float*, int, float*, float*, int, int, int);
  

};

template<class iType>
GsmDemodulator<iType>::GsmDemodulator():StrlSigProc(1, sizeof(iType), sizeof(char))
{
  /* Init some constants */
  fsT =6;
  len_burst = 148;
}
template<class iType>
GsmDemodulator<iType>::~GsmDemodulator() {
}

template<class iType>void
GsmDemodulator<iType>::initialize() {
}

template<class iType>int
GsmDemodulator<iType>::forecast(VrSampleRange output, VrSampleRange inputs[]) 
{
  /* no history */
  //inputs[0].index = output.index*(2*sizeof(float)*fsT);  
  //inputs[0].size  = output.size*(2*sizeof(float)*fsT); 
  //inputs[0].index = output.index*(2*fsT);  
  //inputs[0].size  = output.size*(2*fsT);
   inputs[0].index = output.index*fsT;
   inputs[0].size = output.size*fsT; 
#ifdef DEBUG
  printf("%s (forecast): (output) SRange[%lld, %lu] => upstream(input) SRange[%lld, %lu]\n",name(),output.index, output.size, inputs[0].index,inputs[0].size);
#endif
   return 0;
}

template<class iType>int
GsmDemodulator<iType>::downcast(VrSampleRange input, VrSampleRange* output) 
{
  /* no history */
  output->index=input.index/fsT;
  output->size=input.size/fsT; 
#ifdef DEBUG
  printf("%s (downcast): input [%lld, %lu] => output [%lld, %lu]\n",name(),input.index,input.size,output->index, output->size);
#endif
  return 0;
}

template<class iType>int
GsmDemodulator<iType>::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  //static int inc_in  = len_burst*2*sizeof(float)*fsT;//hkim
  static int inc_in  = len_burst*fsT;
  static int inc_out = len_burst*sizeof(char);
  int len;
  int nb_bursts;
  int offset_in = 0;
  int offset_out = 0;

  iType **i = (iType **)ai;//hkim
  char **o  = (char **)ao;

  len = inputs[0].size;
  nb_bursts = len / inc_in;

   //if(len % inc_in != 0)
   //fprintf(stderr, 
   //    "GsmDemodulator::Work'Unvalid length of data \n");
   
   // For each GSM bursts:
   for(int k=0; k<nb_bursts; k++) {
     GmskDemodulate(i[0] + offset_in, o[0] + offset_out, len_burst, fsT);//hkim
     //GmskDemodulate(i[0] + offset_in, o[0] + offset_out, len_burst, fsT);//hkim
     offset_in  += inc_in;
     offset_out += inc_out;
   }   
   return output.size;
}
template<class iType>void
GsmDemodulator<iType>::GmskDemodulate(iType *gmsk_signal, char *symbols_out, 
				 int len_symbols, int fsT)
{
  int slope, new_slope;
  char last_s;
  float *phase;
  bool tog;//TT fix

  phase = new float[(len_symbols+2)*fsT];

  /*
   * First retrieve phase (modulo PI) of the GMSK signal.
   */
  GetPhase(gmsk_signal, len_symbols*fsT, phase);

  /*
   * Then, smooth the phase in order to retrieve
   * the real phase (without the modulo PI).
   * This operation cannot be done with only one sample per symbol
   * (i.e. with fsT = 1).
   */
  SmoothPhase(phase, len_symbols*fsT);
  tog = (phase[1] > 0 ? true : false); //TT fix

  /*
   * Then, retrieve the symbols by looking at the change of
   * phase between two symbols. 
   * The first symbol is always supposed known.
   */
  last_s = -1; /* known symbol */
  symbols_out[0] = 0;
  slope = (phase[fsT] > phase[0]);
  
  for(register int i=0; i<len_symbols*fsT; i+=fsT) {
    if((new_slope=(phase[i+fsT] > phase[i])) != slope) {
      last_s = -last_s;
    }
    //TT fix start
    if(tog) {
      if(last_s >= 0)
	symbols_out[i/fsT] = 0;
      else
	symbols_out[i/fsT] = 1;
    } else {
      if(last_s < 0)
	symbols_out[i/fsT] = 0;
      else
	symbols_out[i/fsT] = 1;
    }
    //TT fix end

    slope = new_slope;
  }

  delete phase;
  return;
}

template<class iType>void
GsmDemodulator<iType>::GetPhase(iType *c, int len, float *phase)
{
  register int i, j;

  //hkim
  for(i=0, j=0; j<len; i++, j++) {
    if(real(c[i]) == 0.0) { //real
      if(imag(c[i]) > 0) { //imag
	phase[j] = M_PI / 2.0;
      } else {
	if(imag(c[i]) < 0) { //imag
	  phase[j] = - M_PI / 2.0;
	} else {
	  fprintf(stderr, "phase: Null complex, i=%d\n", i);
	  exit(1);
	}
      }
    } else{
      phase[j] = atan(imag(c[i])/real(c[i])); //imag/real
    }
  }
  /*
  for(i=0, j=0; j<len; i+=2, j++) {
    if(c[i] == 0.0) {
      if(c[i+1] > 0) {
	phase[j] = M_PI / 2.0;
      } else {
	if(c[i+1] < 0) {
	  phase[j] = - M_PI / 2.0;
	} else {
	  fprintf(stderr, "phase: Null complex, i=%d\n", i);
	  exit(1);
	}
      }
    } else{
      phase[j] = atan(c[i+1]/c[i]);
    }
  }
  */
}

template<class iType>void
GsmDemodulator<iType>::SmoothPhase(float *phase, int len)
{
#define ABS(x) ((x) > 0 ? (x) : -(x))  
  int slope_pos;
  float offset= 0.0;
  float aux;



  slope_pos = (phase[1] > phase[0]);
  for(register int i=2; i<len; i++) {
    aux = phase[i] + offset;
    if(ABS(aux-phase[i-1]) > 1.0) {
      offset += (slope_pos ? M_PI : -M_PI);
    }
    phase[i] += offset;
    slope_pos = (phase[i] > phase[i-1]);
  }
}

template<class iType>void
GsmDemodulator<iType>::CrossCorrelation(float *x, int first_x, float *y, 
				  float *out, int len, int nb_xcor,
					int inc)

{
  float *x_re, *x_im, *y_re, *y_im;
  float re, im; 
  float *out_re = &out[0];
  float *out_im = &out[1];
  double norm=0.0;
  int offset = first_x * 2;

  inc *= 2;
  for(register int m=0; m<nb_xcor*inc; m+=inc) {
    x_re = &x[offset] + m*2;
    x_im = &x[offset+1] + m*2;
    y_re = &y[0];
    y_im = &y[1];
    re = im = 0.0;
    for(register int n=m; n<len; n++) {
      re += (*x_re * *y_re) + (*x_im * *y_im);
      im += (*x_im * *y_re) - (*x_re * *y_im);
      x_re+=2; x_im+=2; y_re+=2; y_im+=2;
    }

    *out_re = re; out_re += 2;
    *out_im = im; out_im += 2;
  }

  /* Normalize the coefficients */
  nb_xcor *= 2;
  for(register int n=0; n<nb_xcor; n+=2) {
    re = out[n];
    im = out[n+1];
    norm += re*re + im*im;
  }
  norm = sqrt(norm);
  for(register int n=0; n<nb_xcor; n++) {
    out[n] /= norm;
  }
  return;
}


#endif
