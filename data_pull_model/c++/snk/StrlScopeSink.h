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

/*
 * Interface to a Virtual Radio sink connected to a GUI for an oscilloscope.
 * StrlScopeSink inherits from StrlSink, whereas VrGUI inherits from QWidget.
 */

/* some parts is revised by Hahnsang */

#ifndef _STRLSCOPESINK_H_
#define _STRLSCOPESINK_H_

#include <StrlSink.h>

#ifdef _GUI_DEFINE
#include <VrGUI.h>
#endif
/*
#ifdef PERFMON
#include <StrlCycleCount.h>
#endif
*/
#define DEBUG1 0
#define DEBUG2 0

extern "C" {
#include <dlfcn.h>
#include <float.h>
#include <math.h>
	   }

#define TRIGGER_SAMPLES		6000    // samples to check for new trigger
#define TRIGGER_SENSITIVITY	0.9	    // fraction of maximum value seen in signal
#define XAXIS_NAME			"Time divisions"
#define YAXIS_NAME			"Amplitude"

enum ScopeSinkState { TRIGGER_SETTING, TRIGGER_WAITING, DISPLAYING, SKIPPING };

template<class iType> 
class StrlScopeSink : public StrlSink<iType> {
  /*
private:
#ifdef PERFMON
  StrlCycleCount *scopecycles;
#endif
  */
 public:
  /*
#ifdef PERFMON
virtual double getTotalCycles(){return scopecycles->getTotalCycles();}
virtual double getTotalCycles(int m){return scopecycles->getTotalCycles(m); }
virtual unsigned long long getTotalSamples(){return StrlSigProc::getTotalSamples(); }
virtual double getCyclesPerSample(){
  if (getTotalSamples()) 
    return getTotalCycles()/getTotalSamples();
  else return 0;
}
virtual double getCyclesPerSample(int m){
  if (getTotalSamples()) 
    return getTotalCycles(m)/getTotalSamples();
  else return 0;
}
#endif
  */
  virtual const char *name() { return "StrlScopeSink"; }
  virtual void initialize();
#ifdef _GUI_DEFINE
   void clear(){display->clear();}
#else
    void clear(){}
#endif
   
#ifdef _GUI_DEFINE
   void set_persistent(int arg_persistent) 
    {display->set_persistent(arg_persistent);}
#else
   void set_persistent(int arg_persistent) {}
#endif
  virtual int work(VrSampleRange output, 
		   VrSampleRange inputs[], void *i[]);
  static const int maxnPoints = 1000;	// number of points to plot
#ifdef _GUI_DEFINE
  StrlScopeSink(VrGUILayout *layout, float arg_default, int arg_min, int arg_max, int arg_nPoints = maxnPoints, int arg_no_wait = 0);
#else
  StrlScopeSink(float arg_default, int arg_min, int arg_max, int arg_nPoints = maxnPoints, int arg_no_wait = 0); // Hahnsang edited
#endif
  ~StrlScopeSink();
  void setScale(float arg_scale);
  void setRun(int r) {run = r;};
  void setSkip(int arg_inc, int arg_between);
  void setPoints(int arg_nPoints);
	static const int divisions = 10;	// number of x-axis divisions

 private:
  double    tpd;	// time per x-axis division (microseconds)
  double   *amplitude;		// amplitudes to plot on y-axis
  double    samplingFrequency;  // samples/microsecond
  int	    samplesAvailable;	// for work procedure
  int       skipWork;
  int       skipIncrement;
  int       skipBetween;
  int       nPoints;	// max number of points to plot
  int       current_nPoints;	// number of points to plot
  int       run;
#ifdef _GUI_DEFINE
  VrGUIPlot	*display; 
#endif
  int       ymin, ymax;		// possible range of sample values
  int       sampleValue;	// value of last sample
  double    trigger;		// amplitude to trigger new display

  ScopeSinkState state;		// how next sample will be used
  ScopeSinkState prevState;	// how last sample was used
  				// TRIGGER_SETTING, TRIGGER_WAITING
  double maxAmplitude;		// base for setting new trigger
  int    triggerCount;		// samples to check before resetting trigger
  				// DISPLAYING
  int    nextPoint;		// index of next point to generate for graph
  double *xValues;
  int no_wait;
  int first_time_collect;

  void setTrigger(iType *i[]);
  void findTrigger(iType *i[]);
  void collectData(iType *i[]);
  void skipData(iType *i[]);

};

/*****************************************************************************
 * Implementation of template (C++ requires it to be in .h file).
 ****************************************************************************/


/*
 * Creates a new StrlScopeSink.
 */
#ifdef _GUI_DEFINE
template<class iType>
StrlScopeSink<iType>::StrlScopeSink(VrGUILayout *layout, float arg_default, int arg_min, int arg_max, int arg_nPoints, int arg_no_wait)
{
  nPoints = arg_nPoints;
  current_nPoints = nPoints;
  amplitude = new double[nPoints+1];
  xValues = new double[nPoints];
  for (int i = 0; i < nPoints; i++)
		xValues[i] = i;
  no_wait = arg_no_wait;
  ymin = arg_min;
  ymax = arg_max;
  trigger = ymax/TRIGGER_SENSITIVITY; // set high to force recomputation
  display = new VrGUIPlot (layout, XAXIS_NAME, YAXIS_NAME, 1,
		0, nPoints, ymin, ymax, nPoints, divisions); 
  tpd = arg_default;
  setOptimalSize(nPoints);
  /*
#ifdef PERFMON
  scopecycles = new StrlCycleCount();
#endif
  */
}
#else
template<class iType>  
StrlScopeSink<iType>::StrlScopeSink(float arg_default,
        int arg_min, int arg_max, int arg_nPoints, int arg_no_wait)
{
  nPoints = arg_nPoints;
  current_nPoints = nPoints;
  amplitude = new double[nPoints+1];
  xValues = new double[nPoints];
  for (int i = 0; i < nPoints; i++)
                xValues[i] = i;
  no_wait = arg_no_wait;
  ymin = arg_min;
  ymax = arg_max;
  trigger = ymax/TRIGGER_SENSITIVITY; // set high to force recomputation
  tpd = arg_default;
  setOptimalSize(nPoints);
  /*
#ifdef PERFMON
  scopecycles = new StrlCycleCount();
#endif
  */
} 
#endif
template<class iType> void
StrlScopeSink<iType>::initialize()
{
  samplingFrequency = getInputSamplingFrequencyN(0)/1000000;
  setScale(tpd);
  run =1 ;
  cout<<"In the "<<name()<<"samplingFrequency "<<samplingFrequency<<endl;
}

template<class iType> int
StrlScopeSink<iType>::work(VrSampleRange output, 
			   VrSampleRange inputs[], void *ai[])
{
  iType **i = (iType **)ai;
  sync(output.index);
  samplesAvailable = output.size;
#ifdef _DEBUG
  printf("%s (work) : samplesAvailable(=output.size) %d\n",name(),samplesAvailable); 
#endif
  while (samplesAvailable > 0) {
#ifdef COMP_VAL
    printf("in %c ",**i);
#endif
    switch (state) {
    case TRIGGER_SETTING:
//      printf("TRIGGER SETTING : samplesAvailable %d",samplesAvailable);
      cycles->startCountMS();
      setTrigger(i);
      cycles->stopCountMS();
      break;
    case TRIGGER_WAITING:
//      printf("TRIGGER WAITING : samplesAvailable %d",samplesAvailable);  
      cycles->startCountMS();
      findTrigger(i);
      cycles->stopCountMS();
      break;
    case DISPLAYING:
//      printf("DISPLAYING : samplesAvailable %d",samplesAvailable);  
      collectData(i); 
      break;
    case SKIPPING:
//      printf("SKIPPING : samplesAvailable %d",samplesAvailable);  
      cycles->stopCountMS();
      skipData(i);
      cycles->stopCountMS();
      break;
    }
#ifdef COMP_VAL
    printf("out %c ",**i);
#endif
  }
#ifdef DEBUG
  printf("%s (work) : output SampleRange [%lld, %lu]\n",name(),output.index,output.size);
  printf("%s (work) return : %lu (output.size)\n",name(),output.size);
#endif
  return output.size;
}

/*
 * Records maximum amplitude of signal seen in TRIGGER_SAMPLES settings.
 */
template<class iType> void
StrlScopeSink<iType>::setTrigger(iType *i[]) {
  if (prevState != state) {
    #if DEBUG1
    cerr << "Setting trigger value." << endl;
    #endif
    prevState = state;
    triggerCount = TRIGGER_SAMPLES;
    maxAmplitude = (double)ymin;
  }
  if (triggerCount-- <= 0) {
    trigger = TRIGGER_SENSITIVITY*maxAmplitude;
    state = TRIGGER_WAITING;
  } else {
    
    sampleValue = (int)*i[0]++;
    samplesAvailable--;
    if (sampleValue > maxAmplitude) maxAmplitude = (double)sampleValue;
  }
} 

/*
 * If triggerCount > 0, gets the next sample and compares it with both the
 * last sample and the trigger.  Sets the state to DISPLAYING if it is
 * greater than both.  Sets the state to TRIGGER_SETTING if triggerCount = 0.
 */
template<class iType> void
StrlScopeSink<iType>::findTrigger(iType *i[]) {
  if (prevState != state) {
    #if DEBUG1
    cerr << "Waiting for trigger value." << endl;
    #endif
    prevState = state;
    triggerCount = TRIGGER_SAMPLES;
    sampleValue = ymax;
  }
  if (triggerCount-- <= 0) {
    state = TRIGGER_SETTING;
  } else {
    int lastValue = sampleValue;
    sampleValue = (int)*i[0]++;
    samplesAvailable--;
    if (sampleValue > trigger && sampleValue > lastValue) state = DISPLAYING;
  }
}

/*
 * Acquires the next point to plot on the graph.  Displays the graph when
 * all points are acquired.
 */
template<class iType> void
StrlScopeSink<iType>::collectData(iType *i[]) {
  cycles->startCountMS();
//  cout << "collect data: " << nextPoint << "  " << current_nPoints << endl;
  if (first_time_collect) {
    #if DEBUG1
    cerr << "Acquiring data." << endl;
    #endif
    prevState = state;
    nextPoint = 0;
    skipWork = skipIncrement + skipBetween;
	first_time_collect = 0;
  }
  //  cout << skipWork << endl;
  if (nextPoint <= current_nPoints)  {
    // Fix: have source skip proper number of values instead of using a loop
    while (skipWork > 0) {
      if (samplesAvailable-- <= 0) return;
      sampleValue = (int)*i[0]++;   // Fix: eliminate loop? just bump counter?
      skipWork--;
    }
    amplitude[nextPoint++] = (double)sampleValue;
//    cout << "read " << sampleValue << " from " << (int) i[0]-1 << endl;
//    cout << (double) sampleValue << endl;
    skipWork = skipIncrement;
//    cout << skipWork << " " << skipIncrement << endl;
  }
  if (nextPoint >= current_nPoints)  {
//    cout << "display" << cout ;
#ifdef _GUI_DEFINE
    if (run){
      cycles->stopCountMS();
      display->data(xValues, amplitude, current_nPoints);  // mlw
      cycles->startCountMS();
      }
#endif
	first_time_collect = 1;
	if (!no_wait)
    	state = SKIPPING;
  }
  cycles->stopCountMS();
}
template<class iType> void
StrlScopeSink<iType>::setScale(float arg_scale)
{
  tpd = arg_scale;
  //  skipIncrement = (int) (((double)tpd*divisions*samplingFrequency)/current_nPoints);
  skipBetween = 0;
  state = TRIGGER_WAITING;
  if (no_wait)
  	state = DISPLAYING;
  first_time_collect = 1;
  triggerCount = 0;
}
template<class iType> void
StrlScopeSink<iType>::setSkip(int arg_inc, int arg_between)
{
  skipIncrement = arg_inc;
  skipBetween = arg_between;
  cout << "setting:  " << skipIncrement << " " << skipBetween << endl;

  state = TRIGGER_WAITING;
  if (no_wait)
  	state = DISPLAYING;
  first_time_collect = 1;
  triggerCount = 0;
}
template<class iType> void
StrlScopeSink<iType>::setPoints(int arg_nPoints)
{
  if (arg_nPoints < nPoints)
	current_nPoints = arg_nPoints;
  else
	printf (stderr, "setPoints %d exceeds max %d\n", arg_nPoints, nPoints);
}

template<class iType> void
StrlScopeSink<iType>::skipData(iType *i[]) {
  if (prevState != state) {
    prevState = state;
    #if DEBUG1
    cerr << "Skipping data." << endl;
    #endif
  }
  state = TRIGGER_WAITING;
  // Fix: tell the scheduler to ignore some number of samples
}

template<class iType> 
StrlScopeSink<iType>::~StrlScopeSink()
{
  delete[] amplitude;
}
#endif



