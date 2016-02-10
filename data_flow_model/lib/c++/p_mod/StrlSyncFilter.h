/*  Modified 2000, 2001 INRIA */

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


#ifndef _STRLSYNCFILTER_H_
#define _STRLSYNCFILTER_H_

#include <StrlPulse.h>

#if defined (ENABLE_MMX)
#include <StrlMMX.h>
#endif

/* 
  This filter is a version of the complex FIR filter that is designed
  to be "digital aware". It tracks the symbol boundaries and
  (eventually) will be able to provide any pattern of output samples
  in each symbol period.

  The "digital aware" portions only support a single output stream
  now, but it seems feasible to make this filter supoort multiple
  outputs.
  
  */
// ********************************************************

#define   PRECISION_BITS    12
#define BOZO_HISTORY	1000

template<class iType> 
class StrlSyncFilter : public StrlPulse<iType,StrlComplex> {
protected:
  int *num_taps, num_ch, bump;
  StrlComplex** taps;
  StrlComplex *phase_corr_incr, phase_bump, *phase_offset;
  long time;
  long differential_offset, delta_differential_offset;
  int symbol_boundary, symbol_period, pointer_incr, old_output_loc, new_output_loc; 
  float *center_freq, *gain;
  void buildFilter_complex(int);
#if defined (ENABLE_MMX)
  mmxTaps** processedTaps; //Precomputed constants, shifted four times
#endif
public: 
  virtual const char *name() { return "StrlSyncFilter"; }
  virtual int work(VrSampleRange output, void *o[],
		   VrSampleRange inputs[], void *i[]);
  virtual void initialize();
  int setCenter_Freq(int, float);
  int setCenter_Freq(float);
  int setPhase_Offset(StrlComplex);
  int setNumber_Taps(int,int);
  int setNumber_Taps(int);

virtual  float getSymbol_Period();
virtual  int setSymbol_Period(float);
virtual  int setSymbol_Timing(float);
  void start_oversampling(int, int,int,StrlComplex*,int*) {};
  virtual int forecast(VrSampleRange output,
		       VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input,
		       VrSampleRange* output);
    StrlSyncFilter(int n, float d, const int t[], const float f[], 
  		     const float g[]);
  StrlSyncFilter(float d, int t,float f, float g);
  ~StrlSyncFilter();
  int version() { return 1; };
};

template<class iType> int
StrlSyncFilter<iType>::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  iType **i = (iType **)ai;
  StrlComplex **o = (StrlComplex **)ao;
  unsigned int size = output.size;
  StrlComplex result = 0;
  int ch_num = 0;
  StrlComplex *taps_tmp;

  StrlComplex phase_correction[num_ch];

  for(ch_num=0;ch_num<num_ch; ch_num++) {
    phase_correction[ch_num]=pow(phase_corr_incr[ch_num],(int) output.index) * phase_offset[ch_num];
  }

  while (size--) {
    symbol_boundary += symbol_period;
    new_output_loc = (symbol_boundary + (symbol_period >> 1)) >> PRECISION_BITS;
    /* note: offset of output location is specified as 1/2 period by above */

    pointer_incr = new_output_loc - old_output_loc;
    if (pointer_incr <0) { /* counter must have rolled over */
      // cout << pointer_incr << endl;
      pointer_incr += (1 << (32-PRECISION_BITS));
    }
    old_output_loc = new_output_loc;

    if (pointer_incr != decimation) {
      differential_offset += pointer_incr-decimation;
      //cout << "adjusting diff offset: " << differential_offset << endl;
    }

    if (bump != 0) {
          delta_differential_offset = bump >> PRECISION_BITS;
  	  differential_offset += delta_differential_offset;
	  phase_correction[0] *= phase_bump;
	  phase_bump = StrlComplex(1,0);
	  printf ("setting offset %ld\n", differential_offset);
	  //jca symbol_boundary += bump;
	  cout << "Bumping pointer " << (float) (bump) / (float)(1<<PRECISION_BITS) << endl;
	  bump =0;
    }
    result = 0;
    
    for (ch_num =0; ch_num<num_ch; ch_num++){
      //make input pointer local
      iType *inputptr = &i[0][0]; //jca differential_offset];
      
#if defined (ENABLE_MMX)
      if(processedTaps[ch_num]->mmxReady())
	result = processedTaps[ch_num]->mmxCVDProduct(inputptr);
      else
#endif
		{ 
    taps_tmp = taps[ch_num];
	for (int j=0; j < num_taps[ch_num]; j++)
	  result += *taps_tmp++ * *inputptr++;
      }
   
      // Perform phase correction 
      phase_correction[ch_num] *= phase_corr_incr[ch_num];
      result *= phase_correction[ch_num];
      *o[ch_num]++ = result;
    }
    i[0] += pointer_incr;
  }
  return output.size;
}

template<class iType> void
StrlSyncFilter<iType>::buildFilter_complex(int ch){
  int inSampFreq;
  int index;
  float N = num_taps[ch];
  float M = N-1; /* filter Order */

  inSampFreq = (int)getInputSamplingFrequencyN(0); 
  if (center_freq[ch] == 0.0){
      // Build Complex Filter => 
      //            produces a low-pass filter using a real Hamming window
      for ( index=0 ; index < num_taps[ch] ; index++)
       taps[ch][index] = gain[ch]*StrlComplex((0.54-0.46*cos(2*M_PI*index/(M))));
  } else {		// Build composite Complex Filter => adds freq-shifting part
    float arg = 2*M_PI*center_freq[ch] / (float)inSampFreq;
    for ( index=0 ; index < num_taps[ch] ; index++)
      taps[ch][index] = StrlComplex(gain[ch]*cos(arg*index)*(0.54-0.46*cos(2*M_PI*index/(M))),
         gain[ch]*(-1)*sin(arg*index)*(0.54-0.46*cos(2*M_PI*index/(M))));
    phase_corr_incr[ch] = StrlComplex(cos(arg*(float)symbol_period/(float)(1<<PRECISION_BITS)),
				(-1)*sin(arg*(float)symbol_period/(float)(1<<PRECISION_BITS)));
  }
#if defined (ENABLE_MMX)
  if(processedTaps[ch]!=NULL)
    delete processedTaps[ch];
  processedTaps[ch]=new mmxTaps(taps[ch],num_taps[ch]);
#endif
}

template<class iType> 
StrlSyncFilter<iType>::StrlSyncFilter(int n, float per, const int t[], 
					      const float freq[], const float g[])
  :StrlPulse<iType,StrlComplex>(n, (int) per), num_ch(n)
{

  differential_offset = 0;
  num_taps=new int[num_ch];
  phase_corr_incr = new StrlComplex[num_ch];
  phase_offset = new StrlComplex[num_ch];
  center_freq = new float[num_ch];
  gain = new float[num_ch];
  taps = new (StrlComplex *[num_ch]);
  symbol_period = (int) (per * (float)(1 << PRECISION_BITS));

#if defined (ENABLE_MMX)
  processedTaps = new (mmxTaps *[num_ch]);
#endif
  
  for (int i=0; i<num_ch; i++){
    num_taps[i] = t[i];
    phase_corr_incr[i] = StrlComplex(1,0);
    phase_offset[i] = StrlComplex(1,0);
    center_freq[i] = freq[i];
    gain[i] = g[i];
#if defined (ENABLE_MMX)
  processedTaps[i]=NULL;
#endif
  }

}

template<class iType> 
StrlSyncFilter<iType>::StrlSyncFilter(float per,int t,float freq, float g)
  :StrlPulse<iType,StrlComplex>(1,(int) per), num_ch(1)
{
  differential_offset = 0;
  num_taps=new int[num_ch];
  phase_corr_incr = new StrlComplex[num_ch];
  phase_offset = new StrlComplex[num_ch];
  center_freq = new float[num_ch];
  gain = new float[num_ch];
  taps = new (StrlComplex *[num_ch]);
  symbol_period = (int) (per * (float)(1 << PRECISION_BITS));
  symbol_boundary = 0;
  old_output_loc = (symbol_period >>1) >> PRECISION_BITS;
  bump = 0;

#if defined (ENABLE_MMX)
  processedTaps = new (mmxTaps *[num_ch]);
  processedTaps[0]=NULL;
#endif
  num_taps[0] = t;
  phase_corr_incr[0] = StrlComplex(1,0);
  phase_offset[0] = StrlComplex(1,0);
  center_freq[0] = freq;
  gain[0] = g;
}

template<class iType> 
void StrlSyncFilter<iType>::initialize()
{
  for (int i=0; i<num_ch; i++){ 
    taps[i]=new StrlComplex[num_taps[i]];
    buildFilter_complex(i);
  }
  //Set history
  int max_num_taps = 0;
  for (int i=0; i<num_ch; i++)
    if (num_taps[i] > max_num_taps) max_num_taps = num_taps[i];
  history = max_num_taps + BOZO_HISTORY;		//jca
  differential_offset  = 0;
  delta_differential_offset=0;
}

template<class iType> 
int StrlSyncFilter<iType>::setCenter_Freq(int ch, float cf)
{
  center_freq[ch] = cf;
  buildFilter_complex(ch);
  return 1;
}

template<class iType> 
int StrlSyncFilter<iType>::setCenter_Freq(float cf)
{
  return setCenter_Freq(0,cf);
}

template<class iType> 
int StrlSyncFilter<iType>::setPhase_Offset(StrlComplex f)
{
 phase_offset[0]=f;
 return 1;
}

template<class iType> 
int StrlSyncFilter<iType>::setNumber_Taps(int ch, int numT)
{
  num_taps[ch] = numT;
  delete taps[ch];
  taps[ch]=new StrlComplex[num_taps[ch]];

  //set history
  int max_num_taps = 0;
  for (int i=0; i<num_ch; i++){
    if (num_taps[i] > max_num_taps) max_num_taps = num_taps[i];
  }
  //jca history = max_num_taps;
  history = max_num_taps + BOZO_HISTORY;		//jca

  buildFilter_complex(ch);
  return 1;
}

template<class iType> 
int StrlSyncFilter<iType>::setNumber_Taps(int numT)
{
  return setNumber_Taps(0, numT);
}

template<class iType> 
float StrlSyncFilter<iType>::getSymbol_Period() 
{
  /* returns symbol period in seconds */
  return (float)symbol_period /(float)(1 << PRECISION_BITS)  /  (float)getInputSamplingFrequencyN(0);
}

template<class iType> 
int StrlSyncFilter<iType>::setSymbol_Period(float period)
{
  double arg = 2*M_PI*center_freq[0] / (double)getInputSamplingFrequencyN(0);

  /* input symbol period in seconds -> converts to fractional number of samples*/
  symbol_period = (int)(period * (float)(1 << PRECISION_BITS) * (float)getInputSamplingFrequencyN(0));

  phase_corr_incr[0] = StrlComplex(cos(arg*(double)symbol_period/(double)(1<<PRECISION_BITS)),
				(-1)*sin(arg*(double)symbol_period/(double)(1<<PRECISION_BITS)));

  cout << " Set period to " << (double) symbol_period / (double)(1 << PRECISION_BITS) << endl;
  return 1;
}

template<class iType> 
int StrlSyncFilter<iType>::setSymbol_Timing(float fraction)
{
  double arg = 2*M_PI*center_freq[0] / (double)getInputSamplingFrequencyN(0);

  /* input fraction (FP) of symbol period for offset adjustment: (+) =
     advance boundary relative to sample stream, (-)= retard boundary */
  bump  =  (int)( fraction * (float) symbol_period);
  phase_bump = StrlComplex(cos(arg*(double)bump/(double)(1<<PRECISION_BITS)),
				(-1)*sin(arg*(double)bump/(double)(1<<PRECISION_BITS)));
  return 1;
}

template<class iType> int
StrlSyncFilter<iType>::forecast(VrSampleRange output,
					   VrSampleRange inputs[]) {
  //  if (output.index>WP) return -1;
  if (!is_synced(output.index)) return -1;
  /* dec:1 ratio with history */
  for(unsigned int i=0;i<numberInputs;i++) {
    inputs[i].index=output.index*decimation+ differential_offset; /* ! do not subtract history ! */
    //cout << inputs[i].index << "  " << differential_offset << endl;
    inputs[i].size=output.size*decimation + history-1;
  }
  return 0;
}  

template<class iType> int
StrlSyncFilter<iType>::downcast(VrSampleRange input,
				     VrSampleRange* output) {
  //  if (output.index>WP) return -1;
  if (!is_synced(output->index)) return -1;
  /* dec:1 ratio with history */
  output->index=(input.index-differential_offset)/decimation;
  output->size=(input.size - history + 1)/decimation;
  return 0;
}  

template<class iType> 
StrlSyncFilter<iType>::~StrlSyncFilter()
{
  
  for (int i=0; i<num_ch; i++){ 
    delete taps[i];
#if defined (ENABLE_MMX)
    if(processedTaps[i]!=NULL)
      delete processedTaps[i];
#endif
  }
  delete num_taps;
  delete [] phase_corr_incr;
  delete [] phase_offset;
  delete center_freq;
  delete gain;
  delete taps;
}
#endif
