/*  Modified 2000, 2001 INRIA
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

#ifndef _STRLCOMPLEXPLOTSINK_H_
#define _STRLCOMPLEXPLOTSINK_H_

#define PLOT                1
#define PARTIAL_PLOT        0
#define TWO                 0

#include <stdio.h>
#include "StrlSkippingSink.h"

#define MAX_SYMBOLS    100000
#define SQR_HISTORY_OFFSET 20
#define VRCOMPLEX_nPoints 100
class StrlComplexPlotSink : public StrlSkippingSink<StrlComplex> {
protected:
  int sync_version;
  StrlPulse<char,char> *sync_pointer;
  float timeDuration, slice;
  float pos_threshold, high_pos_threshold, low_pos_threshold;
  float neg_threshold, high_neg_threshold, low_neg_threshold;
  int size;
  int current_point_index;
  int N, flip, flip_c, plot, plot_count, symb_count, symbol_sync;
  StrlComplex sum, old_conj;
  StrlComplex sqr_hist[2*SQR_HISTORY_OFFSET], *current_sqr, *last_sqr;
  int data_ready_flag;
//#if PULSE_VERSION
  StrlComplex *correlation_input, temp;
  int old_drf, oversample_interval, log_oversample_factor;
  int correlate_interval, input_size, corr_calc;
   double xValues[VRCOMPLEX_nPoints], yValues[VRCOMPLEX_nPoints];
//#endif /* PULSE_VERSION */
//jca #if LOG_SYMBOLS
  char *data_ptr, *cur_data_ptr;
//jca #endif
public:
  StrlComplexPlotSink(StrlPulse<char, char>*, float td, int s);
  virtual ~StrlComplexPlotSink() {}
  virtual const char *name() { return "StrlCXPlotSink"; }
  virtual void initialize();
  virtual int work(VrSampleRange output,
		   VrSampleRange inputs[], void *i[]);
  float getTimeDuration() {return timeDuration;}
  void setTimeDuration(float t) {
    timeDuration = t;
    history = ((int)(getInputSamplingFrequencyN(0) * timeDuration));
  }
  int getSize() {return size;}
  void setSize(int s) {size = s;}
  void do_correlation(int,int);
  char symbol_decision(float);
  void init_plot();
  void point_plot(StrlComplex);
  void finish_plot();
//jca #if LOG_SYMBOLS
  char* getRcvdData(){ cur_data_ptr = data_ptr; return data_ptr;}
//jca #endif
};

int
StrlComplexPlotSink::work(VrSampleRange output,
			   VrSampleRange inputs[], void *ai[])
{
  StrlComplex **i = (StrlComplex **)ai;
  int size = output.size;
  int length=0;
  StrlComplex temp, est_theta;

  if (data_ready_flag) {	/* PULSE_VERSION */
    cout << "Corr" << endl;
    do_correlation(4,6);
    data_ready_flag = 0;
    getchar();
  }
#if (PLOT | PARTIAL_PLOT)
  init_plot();
#endif
  symbol_sync=1;
  if (symbol_sync) {
    while (size-- > 0) {
      length = history;
      while(length-- > 0) {
		temp = *i[0]++;
		*current_sqr = temp * temp;
		*(current_sqr-SQR_HISTORY_OFFSET) = temp * temp;
		sum = sum + *current_sqr - *(current_sqr-N);
		current_sqr++;
		if (current_sqr == last_sqr) current_sqr -= SQR_HISTORY_OFFSET;
		est_theta = sqrt ( sum / sqrt((real(sum)*real(sum) + imag(sum)*imag(sum))));
		if (real(old_conj*est_theta)<0) flip =  -flip;
		old_conj = StrlComplex(real(est_theta), -imag(est_theta));
		//       		temp = temp * StrlComplex(real(est_theta), -imag(est_theta));
		if (flip <0) temp = -temp;
		slice = real(temp);
		symb_count++;
		if (symb_count%100000 == 0) cout << "100K" << endl;
		if (!sync_version) {	/* PULSE_VERSION */
			if (symb_count == 10){
	  			cout << "try out high res " << endl;
	  			data_ready_flag = 0;
	  			sync_pointer -> start_oversampling(8, 6, 10,
					     	correlation_input, &data_ready_flag);
			}
#if PULSE_VERSION && 0
			if (data_ready_flag == 1 && old_drf == 0) {
	  			cout << "Corr lag " << symb_count-corr_calc << endl;
	  			old_drf = 1;
			}
			if (symb_count%correlate_interval == 10) {
	  			cout << "Correlation" << endl;
	  			data_ready_flag = 0;
	  			old_drf = 0;
	  			sync_pointer -> start_oversampling(oversample_interval, log_oversample_factor,
					     correlation_input, &data_ready_flag);
	  			cout << data_ready_flag << endl;
	  			corr_calc = symb_count;
			}
#endif
		}					/* PULSE_VERSION */
#if LOG_SYMBOLS
  		if (cur_data_ptr < &data_ptr[MAX_SYMBOLS])
			*cur_data_ptr++ = symbol_decision(-slice);
#endif
#if (PLOT | PARTIAL_PLOT)
		point_plot(temp);
#endif
      }	/* while (length-- > 0) */
#if (PLOT | PARTIAL_PLOT)
      finish_plot();
#endif
    } /* while (size-- > 0) */
  }
  else { 		/* if !symbol_sync */
    //    get_initial_sync();
  }
  return output.size;
}

#if 0
void
StrlComplexPlotSink::get_initial_sync()
{
	  data_ready_flag = 0;
	  old_drf = 0;
	  sync_pointer -> start_oversampling(oversample_interval, log_oversample_factor,
					     correlation_input, &data_ready_flag);
}
#endif

char
StrlComplexPlotSink::symbol_decision(float slice)
{
  char symbol;
#ifdef EIGHT
#define OUTER (slice > 0)
#define MID (slice > pos_threshold)
#define INNER (slice > high_pos_threshold)
#define INNER2 (slice > low_pos_threshold)
#else /* !EIGHT */
#define OUTER (1)
#define INNER2 (slice > neg_threshold)
#ifdef TWO
#define MID (1)
#define INNER (slice > 0)
#else /* !TWO */
#define MID (slice > 0)
#define INNER (slice > pos_threshold)
#endif /* TWO */
#endif /* EIGHT */
  if (OUTER)
    if (MID)
      if (INNER)
		symbol = 0x00;
      else  symbol = 0x01;
     else
      if (INNER2)
		symbol = 0x02;
      else  symbol = 0x03;
   else
    if (slice>neg_threshold)
      if (slice>high_neg_threshold) symbol = 0x04;
      else  symbol = 0x05;
     else
      if (slice> low_neg_threshold) symbol = 0x06;
      else  symbol = 0x07;
  //      cout <<  (int)(symbol);
  return symbol;
}

void
StrlComplexPlotSink::do_correlation(int N, int B) /* PULSE_VERSION */
{
printf ("start do_correlation\n");

  int tmp1, flip_c;
  float sum1;
  StrlComplex  sum;
  StrlComplex correction, old_correction;

#if 0
  init_plot();
  for (int tmp = 0 ; tmp < N * (1 << B); tmp ++){
    point_plot( *(correlation_input+tmp) * (*(correlation_input+tmp)));
  }
  finish_plot();
  getchar();
  fprintf(fd,"plot [%d:%d][%d:%d] \"-\"  w l\n",-size, size, -size, size);
  for (int tmp = 0 ; tmp < N * (1 << B); tmp ++){
    point_plot( *(correlation_input+tmp) * (*(correlation_input+tmp)));
  }
  finish_plot();
  getchar();
#endif

#if 1

  old_correction = StrlComplex();
  flip_c =1;

  sum = 0;
  for (int tmp = 0 ; tmp < oversample_interval * (1 << log_oversample_factor); tmp ++){
    sum += *(correlation_input+tmp) * (*(correlation_input+tmp));
  }
  cout << 180.0 / M_PI * arg(sqrt(sum)) << endl;
  //correction = StrlComplex( cos( arg(sqrt(sum))), sin( arg(sqrt(sum))));
  correction = sqrt ( sum / sqrt((real(sum)*real(sum) + imag(sum)*imag(sum))));
  cout << 180.0 / M_PI * arg((correction)) << endl;
  //	sum = 0;
  for (int tmp = 0 ; tmp < (oversample_interval-8) * (1 << log_oversample_factor); tmp ++){
    sum1 = 0;
    for (tmp1 =0 ; tmp1  < 2 *  (1 << log_oversample_factor); tmp1 ++)
      sum1 += real(*(correlation_input+tmp+tmp1) * correction);
    for (; tmp1  < 6 *  (1 << log_oversample_factor); tmp1 ++)
      sum1 -= real(*(correlation_input+tmp+tmp1) * correction);
    for (; tmp1  < 8 *  (1 << log_oversample_factor); tmp1 ++)
      sum1 += real(*(correlation_input+tmp+tmp1) * correction);

    if (real(old_correction*correction)<0) flip_c =  -flip_c;
    old_correction = StrlComplex(real(correction), -imag(correction));
    temp = *(correlation_input+tmp) * StrlComplex(real(correction), -imag(correction));
    if (flip_c <0) correction = -correction;

	if (tmp < VRCOMPLEX_nPoints) {
    	xValues[tmp] = tmp;
		yValues[tmp] = 2*sum1/8.0/(float)(1 << log_oversample_factor);
	}
  }
#endif

}

void
StrlComplexPlotSink::finish_plot()
{
#if PARTIAL_PLOT
    plot_count++;
#endif
  current_point_index = 0;
}
void
StrlComplexPlotSink::point_plot(StrlComplex point)
{
	if (current_point_index < VRCOMPLEX_nPoints) {
#if PLOT
    xValues[current_point_index] = real(point);
	yValues[current_point_index++] = imag(point);
#endif
#if PARTIAL_PLOT
	if (plot) {
    	xValues[current_point_index] = real(point);
		yValues[current_point_index++] = imag(point);
	}
#endif
	}
}

void
StrlComplexPlotSink::init_plot()
{
#if PLOT
  plot =1;
#endif
#if PARTIAL_PLOT
  plot = (plot_count%50 ==0);
#endif
  current_point_index = 0;
}

void
StrlComplexPlotSink::initialize()
{
  float dummy;

  increment = (int)(getInputSamplingFrequencyN(0) * timeDuration);
  history = increment; 
  current_sqr = &sqr_hist[SQR_HISTORY_OFFSET];
  last_sqr = current_sqr + SQR_HISTORY_OFFSET;
  old_conj = StrlComplex();
  flip =1;
  plot_count =0;
  symb_count = 0;

  N = 5;
  for (int i = 0; i<2*SQR_HISTORY_OFFSET; i++)
	 sqr_hist[i] = StrlComplex();
  if (sync_version) {		/* SYNC_VERSION */
     sync_pointer -> setSymbol_Timing((float)0.0);
     dummy = sync_pointer -> getSymbol_Period();
     sync_pointer -> setSymbol_Period(dummy*1.0);
  }
  else {					/* PULSE_VERSION */
     log_oversample_factor = 4;
     oversample_interval = 60;
     correlate_interval = 2000;
     input_size = (1 << log_oversample_factor) * oversample_interval;
     correlation_input = (StrlComplex *) new StrlComplex[input_size];
  }
//jca #if LOG_SYMBOLS
  data_ptr = new char[MAX_SYMBOLS];
  cur_data_ptr = data_ptr;
//jca #endif
  pos_threshold = 0.7;
  neg_threshold = -0.7;
  high_pos_threshold = 1.1;
  low_pos_threshold = 0.4;
  high_neg_threshold = -0.4;
  low_neg_threshold = -1.1;
}

StrlComplexPlotSink::StrlComplexPlotSink(StrlPulse<char,char> *filter, float td, int s)
  :sync_pointer(filter),timeDuration(td),size(s)
{
  data_ready_flag = 0;
  sync_version = sync_pointer->version();
  fprintf(stderr,"initializing in %s",name());
}
#endif
