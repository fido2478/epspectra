/*  Modified 2000, 2001 INRIA */
/* -*- Mode: c++ -*-
 *
 *  Copyright 1999 Massachusetts Institute of Technology
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


#ifndef _STRLFFTSINK_H_
#define _STRLFFTSINK_H_

#include <StrlSink.h>
#include <fftw.h>

extern "C" {
#include <dlfcn.h>
#include <float.h>
#include <math.h>
	   }

#define FFT_XAXIS_NAME			"Frequency (Hz)"
#define FFT_YAXIS_NAME			"Squared Magnitude (dB)"

template<class iType> 
class StrlFFTSink : public StrlSink<iType> {

 public:
  virtual const char *name() { return "StrlFFTSink"; }
  virtual void initialize();
  virtual int work(VrSampleRange output, 
		   VrSampleRange inputs[], void *i[]);
  static const int maxnPoints = 1024;	// number of points to plot
#ifdef ESTEREL
  StrlFFTSink(int arg_min, int arg_max, int arg_nPoints = maxnPoints);
#else 
  StrlFFTSink(VrGUILayout *layout,
	int arg_min, int arg_max, int arg_nPoints = maxnPoints);
#endif
  ~StrlFFTSink();
  void setRun(int r) {run = r;};
  void setPoints(int arg_nPoints);
  static const int divisions = 10;	// number of x-axis divisions

 private:
  double   *dbValues;		// output (dB) values from FFT
  double    samplingFrequency;  // samples/microsecond
  int	    samplesAvailable;	// for work procedure
  int       skipWork;
  int       skipIncrement;
  int       skipBetween;
  int       nPoints;	// max number of points to plot
  int       current_nPoints;	// number of points to plot
  int       run;
  float		axis_offset;

  /*  struct FFTW_COMPLEX *amplitude, *frValues; TT*/
  FFTW_COMPLEX *amplitude, *frValues;
  fftw_plan plan;
#ifndef XES
  VrGUIPlot	*display;
#endif

  int       ymin, ymax;		// possible range of sample values
  iType     sampleValue;	// value of last sample
  int    nextPoint;		// index of next point to generate for graph
  double *xValues;
  int first_time_collect;
  int one_or_two;
  void collectData(iType *i[]);
};

/*****************************************************************************
 * Implementation of template (C++ requires it to be in .h file).
 ****************************************************************************/


/*
 * Creates a new StrlFFTSink.
 */
#ifdef XES
template<class iType>
StrlFFTSink<iType>::StrlFFTSink(int arg_min, int arg_max, int arg_nPoints)
{
  nPoints = arg_nPoints;
  current_nPoints = nPoints;
  amplitude = new FFTW_COMPLEX[nPoints+1];
  frValues = new FFTW_COMPLEX[nPoints+1];
  dbValues = new double[nPoints+1];
  xValues = new double[nPoints];
  ymin = arg_min;
  ymax = arg_max;
  setOptimalSize(nPoints);
  skipIncrement = 1;
  skipBetween = 0;
  first_time_collect = 1;
  axis_offset = 0.0;
} 
#else
 template<class iType>
StrlFFTSink<iType>::StrlFFTSink(VrGUILayout *layout_arg,
	int arg_min, int arg_max, int arg_nPoints)
{
  layout = layout_arg;
  nPoints = arg_nPoints;
  current_nPoints = nPoints;
  amplitude = new FFTW_COMPLEX[nPoints+1];
  frValues = new FFTW_COMPLEX[nPoints+1];
  dbValues = new double[nPoints+1];
  xValues = new double[nPoints];
  ymin = arg_min;
  ymax = arg_max;
  setOptimalSize(nPoints);
  skipIncrement = 1;
  skipBetween = 0;
  first_time_collect = 1;
  axis_offset = 0.0;
} 
#endif
template<class iType> void
StrlFFTSink<iType>::initialize()
{
  iType test_for_complex=0;

  samplingFrequency = getInputSamplingFrequencyN(0);
  
  printf("%s initialize samplingFrequency as %f\n",name(),samplingFrequency);
  for (int i= 0; i <= nPoints/2 ; i++)
    xValues[i] = ((float)i/(float)nPoints*samplingFrequency)-axis_offset;
  for (int i= nPoints/2 +1; i< nPoints ; i++)
    xValues[i] = ((float)(i-nPoints)/(float)nPoints*samplingFrequency)-axis_offset;

#ifndef XES
  plan = fftw_create_plan(nPoints, FFTW_FORWARD, FFTW_ESTIMATE);
  if (plan == NULL) {
    fprintf(stderr, "StrlFFTSink(initialize): error creating plan\n");
    exit(-1);
  }

  if (is_complex(test_for_complex)) {
	display = new VrGUIPlot (layout, FFT_XAXIS_NAME, FFT_YAXIS_NAME, 1,
		-samplingFrequency/2, samplingFrequency/2, ymin, ymax, nPoints, divisions);
	one_or_two = 1;
  }
  else {
	display = new VrGUIPlot (layout, FFT_XAXIS_NAME, FFT_YAXIS_NAME, 1,
		0, samplingFrequency/2, ymin, ymax, nPoints/2, divisions);
	one_or_two = 2;
  }
#endif

  run = 1;
}

template<class iType> int
StrlFFTSink<iType>::work(VrSampleRange output, 
			   VrSampleRange inputs[], void *ai[])
{
  sync(output.index);
  samplesAvailable = output.size;
#ifdef DEBUG
  printf("%s (work) : samplesAvailable(=output.size) %d\n",name(),samplesAvailable);
#endif
  printf("%s (work) : output SampleRange [%lld, %lu]\n",name(),output.index,output.size); 
  while (samplesAvailable > 0){
#ifdef COMP_VAL
    printf("in ");
#endif
      collectData((iType **)ai);
#ifdef COMP_VAL
      printf("%c ",**ai);
#endif
//      printf("collectData : samplesAvailable %d\n",samplesAvailable);
  }
#ifdef DEBUG
  printf("%s (work) return : %lu (output.size)\n",name(),output.size); 
#endif
  return output.size;
}

/*
 * Acquires the next point to plot on the graph.  Displays the graph when
 * all points are acquired.
 */
template<class iType> void
StrlFFTSink<iType>::collectData(iType *i[])
{
  if (first_time_collect) {
    nextPoint = 0;
    skipWork = skipIncrement + skipBetween;
    first_time_collect = 0;
  }

  if (nextPoint <= current_nPoints)  {
    // Fix: have source skip proper number of values instead of using a loop
    while (skipWork > 0) {
      if (samplesAvailable-- <= 0) return;
      sampleValue = *i[0]++;   // Fix: eliminate loop? just bump counter?
      skipWork--;
    }
    c_re(amplitude[nextPoint]) = real(sampleValue);
    c_im(amplitude[nextPoint++]) = imag(sampleValue);
    skipWork = skipIncrement;

  }
  if (nextPoint >= current_nPoints)  {

    if (run){
#ifndef XES
      fftw(plan, 1, amplitude, 1, 0, frValues, 1, 0);
#endif
      for (int i = 0; i<nPoints ; i++)
	dbValues[i] = 10 * log((frValues[i].re*frValues[i].re)+(frValues[i].im*frValues[i].im)); 
#ifndef XES
      display->data(xValues, dbValues, current_nPoints/one_or_two);  // mlw
#endif
    }
    first_time_collect = 1;
  }
}

template<class iType> void
StrlFFTSink<iType>::setPoints(int arg_nPoints)
{
  if (arg_nPoints < nPoints)
	current_nPoints = arg_nPoints;
  else
	printf (stderr, "setPoints %d exceeds max %d\n", arg_nPoints, nPoints);
}

template<class iType> 
StrlFFTSink<iType>::~StrlFFTSink()
{
  delete[] amplitude;
  delete[] xValues;
  delete[] frValues;
  delete[] dbValues;
}
#endif
