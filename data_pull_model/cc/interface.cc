/********************************************
* This is * interface.cc *
*********************************************/
#include <iostream.h>
#include <string.h>
#include <StrlSigProc.h>
#include <StrlFileSource.h>
#include <StrlDigMod.h>
#include <StrlSum.h>
#include <StrlBits2Symbols.h>
#include <StrlUDPSink.h>
#include <StrlScopeSink.h>
//#include <StrlFFTSink.h>

#ifdef PERFMON
#include <StrlPerfGraph.h>
#endif

/**************************************************************
 * StrlMultiTask class is redefined for the implementation of 
 * Control part of SPECtRA system in ESTEREL
 * it is at pspectra/cc/i386/lib/vr/.
 **************************************************************/
#include <StrlConstellation_defs.h>
#include <StrlTypes.h>

/*****  GUI begin ********/ 
#include "VrGUI.h"
/*****  GUI end ******/

#define STRLEN 80
#define VRSCOPESINK_FLAG 1
/*********************************
 * define variables
 *********************************/
#define DEFAULT_TPD 2600.0
int BufferSizeMultiplier=3; 
int process_one = 1;
int persistent = 0;
int run = 1;
int center_freq_mult = 4, band=1;
int out_rate = 400000;
int in_rate = 2000;
int offset, const_num = 5;
int num_symb = 16, output_symbol_bits = 4, K=2;
float alpha=0.6;
int ampl=80;

#define SOURCE_TYPE StrlFileSource<char>
#define SOURCE_PARAMETER ("tmp.gz",1)

#define MOD_TYPE StrlDigMod<char,char>
#define MOD_PARAMETER (out_rate/in_rate, 65000.0, ampl, num_symb, symbol_phase[const_num], symbol_amplitude[const_num], K, alpha, center_freq_mult)

#define CODER_TYPE StrlBits2Symbols
#define CODER_PARAMETER (output_symbol_bits)

#define SUMMER_TYPE StrlSum<char,char>
#define SUMMER_PARAMETER ()

#define SCOPESINK_TYPE StrlScopeSink<char> // StrlFFTSink<char>
#define SCOPESINK_PARAMETER (DEFAULT_TPD/2,-128,128,500,1)//(0,200,1024) 

#define SINK_TYPE StrlUDPSink<char>
#define SINK_PARAMETER ("localhost",5001)

#define FFTSINK_FLAG 0
#define VRSCOPESINK_FLAG 1



SOURCE_TYPE *source;
MOD_TYPE *mod;
CODER_TYPE *coder;
SUMMER_TYPE *summer;
SCOPESINK_TYPE *scopesink;
SINK_TYPE *sink;

/**** GUI begin ******/
VrGUI *guimain;

#ifdef PERFMON
StrlPerfGraph *perfgraph;
#endif

void set_clear()
{
  scopesink->clear();
}

void set_my_scale(double f) {
printf ("set scale %f\n", f);
  scopesink->setSkip(f,0);
  scopesink->clear();
}

void set_persistent()
{
  persistent = 1 - persistent;
  scopesink->set_persistent(persistent);
}
void set_run()
{
  run = 1-run;
  scopesink->setRun(run);
}

void(*last_const)();
void set_sync() { set_my_scale(20); }

void set_base() { band = 0; 
                  (*last_const)();}


void set_pass() { band = 1; 
                  (*last_const)();}

void set_eye() { set_my_scale(2); }


void set_constellation0()
{   
  mod -> change_constellation(alpha, ampl, 2, 8,
			      symbol_phase[0], symbol_amplitude[0], band);
  coder -> setOutputBits(1);
  mod -> set_sync_symbols(0,1);
  last_const = set_constellation0;
}
void set_constellation1()
{   
  mod -> change_constellation(alpha, ampl, 4, 6,
			      symbol_phase[1], symbol_amplitude[1], band);
  coder -> setOutputBits(2);
  mod -> set_sync_symbols(1,3);
  last_const = set_constellation1;
}
void set_constellation2()
{   
  mod -> change_constellation(alpha, ampl, 8, 4,
			      symbol_phase[2], symbol_amplitude[2], band);
  coder -> setOutputBits(3);
  mod -> set_sync_symbols(3,7);
  last_const = set_constellation2;
}
void set_constellation3()
{   
  mod -> change_constellation(alpha, ampl, 4, 6,
			      symbol_phase[3], symbol_amplitude[3], band);
  mod -> set_sync_symbols(0,2);
  coder -> setOutputBits(2);
  last_const = set_constellation3;
}
void set_constellation4()
{   
  mod -> change_constellation(alpha, ampl, 8, 4,
			      symbol_phase[4], symbol_amplitude[4], band);
  coder -> setOutputBits(3);
  mod -> set_sync_symbols(0,4);
  last_const = set_constellation4;
}
void set_constellation5()
{   
  mod -> change_constellation(alpha, ampl, 16, 2,
			      symbol_phase[5], symbol_amplitude[5], band);
  coder -> setOutputBits(4);
  mod -> set_sync_symbols(0,15);
  last_const = set_constellation5;
}


/***** GUI end *********/

extern "C" {  /* begin extern "C" */

  /***********************************************
   * This is the definition of function and varialbe
   * for the Real Control part.
   ***********************************************/

/**** GUI begin ******/
void InterGuimain_Start()
{
  guimain->start();
}

void InterGuimain_Run()
{
  guimain->processEvents(10);
}
/***** GUI end *********/
void InterCreateSource()
{
  source = new SOURCE_TYPE SOURCE_PARAMETER;
}

void InterCreateCoder()
{
  coder = new CODER_TYPE CODER_PARAMETER;
}

void InterCreateMod()
{
  mod = new MOD_TYPE MOD_PARAMETER;
}

void InterCreateSummer()
{
  summer =new SUMMER_TYPE SUMMER_PARAMETER;
}
/*
void InterCreateScopesink()
{
  scopesink = new SCOPESINK_TYPE SCOPESINK_PARAMETER;
  #if VRSCOPESINK_FLAG
  scopesink->setSkip(1,0);
  #endif
}
*/
void InterCreateSink()
{
  sink =new SINK_TYPE SINK_PARAMETER;
}

const char* TheNameOfSource(){
  return source->name();
}

const char* TheNameOfCoder(){
  return coder->name();
} 
 
const char* TheNameOfMod(){
  return mod->name();
} 

const char* TheNameOfScopesink(){
  return scopesink->name();
}

const char* TheNameOfSink(){
  return sink->name();
} 
        
const char* TheNameOfSummer(){
  return summer->name();
}

/**********************************
 * Create modules
 **********************************/

const char* InterGetSource(char *r,int y)
{
  //  source = new SOURCE_TYPE SOURCE_PARAMETER;
  source = new StrlFileSource<char>(r,y);
  return source->name();
}

const char* InterGetCoder(int x)
{
  //  coder = new CODER_TYPE CODER_PARAMETER;
  coder = new StrlBits2Symbols(x);
  return coder->name();
}

const char* InterGetMod_f(int x,float y,int z,int a,int b,int c,float d,int e)
{
  //  mod = new MOD_TYPE MOD_PARAMETER;
  mod = new StrlDigMod<char,char>(x,y,z,a,symbol_phase[b],symbol_amplitude[b],c,d,e);
  return mod->name();
}

const char* InterGetMod()
{
  mod = new MOD_TYPE MOD_PARAMETER;
  return mod->name();
}

const char* InterGetSummer()
{
  //  summer =new SUMMER_TYPE SUMMER_PARAMETER;
  summer=new StrlSum<char,char>();
  return summer->name();
}

const char* InterGetScopesink_f(float a,int b,int c,int d,int e)
{
  /***** GUI begin *****/
  guimain=new VrGUI(1,NULL);
  last_const = set_constellation5;
  (void) VrGUILabel(guimain->top,"WAVEFORMS",0,30);
  VrGUILayout *scopelay_modes = guimain->top->horizontal();
  (void) VrGUISpace(scopelay_modes, 50);
  (void) new VrGUIButton(scopelay_modes, "BPSK", set_constellation0);
  (void) new VrGUIButton(scopelay_modes, "4-PAM", set_constellation1);
  (void) new VrGUIButton(scopelay_modes, "8-PAM", set_constellation2);
  (void) new VrGUIButton(scopelay_modes, "QPSK", set_constellation3);
  (void) new VrGUIButton(scopelay_modes, "8-PSK", set_constellation4);
  (void) new VrGUIButton(scopelay_modes, "16-QAM", set_constellation5);
  (void) new VrGUIButton(scopelay_modes, "8-VSB", set_constellation2);

  (void) VrGUILabel(guimain->top, "Time domain", 0, 30);
  VrGUILayout *scopelay_main = guimain->top->horizontal();
  VrGUILayout *scopelay = scopelay_main->vertical();
  /***** GUI end *****/

  scopesink=new StrlScopeSink<char>(scopelay,a,b,c,d,e);
  scopesink->setSkip(1,0);

  /**** GUI begin ****/
  VrGUILayout *scopelay_slider = scopelay->horizontal();
  (void) new VrGUISlider(scopelay_slider, set_my_scale, "Time", 
			 DEFAULT_TPD/100, DEFAULT_TPD);
  VrGUILayout *scopelay2 = scopelay_main->vertical();
  (void) new VrGUIButton(scopelay2, "Baseband", set_base);
  (void) new VrGUIButton(scopelay2, "Passband", set_pass);
  (void) VrGUISpace(scopelay2, 50);
  (void) new VrGUIButton(scopelay2, " Run ", set_run);
  (void) new VrGUIButton(scopelay2, "Store", set_persistent);
  (void) new VrGUIButton(scopelay2, "Clear", set_clear);
  (void) VrGUISpace(scopelay2, 50);
  (void) new VrGUIButton(scopelay2, "Sync time", set_sync);
  (void) new VrGUIButton(scopelay2, "Eye time", set_eye);
  (void) VrGUISpace(scopelay2, 200);
  (void) VrGUISpace(guimain->top, 10);
  /**** GUI end ****/

  return scopesink->name();
}

const char* InterGetSink(char *r,int x)
{
  //  sink =new SINK_TYPE SINK_PARAMETER;
  sink=new StrlUDPSink<char>(r,x);
  return sink->name();
}

StrlSigProc *GetObject(char *r)
{
  if (!strcmp(r,source->name()))
    return source;
  if (!strcmp(r, coder->name()))
    return coder;
  if (!strcmp(r, mod->name()))
    return mod;
  if (!strcmp(r, scopesink->name()))
    return scopesink;
  if (!strcmp(r, sink->name()))
    return sink;
  if (!strcmp(r, summer->name()))
    return summer;
}

#ifdef PERFMON
void InterInitPerfGraph()
{
  perfgraph=new StrlPerfGraph();
  sink->addToGraph(perfgraph);
  scopesink->addToGraph(perfgraph);
}
void InterStartPerfGraph()
{
  perfgraph->globalSTARTcount(); //start count global clock
}
void InterStopPerfGraph()
{
  perfgraph->globalSTOPcount(); //stop count global clock
}
void print_stats()
{
  fprintf(stderr, "\nGLOBAL counts:\n");
  fprintf(stderr, "--------------\n");
  fprintf(stderr, "\nPer module counts:\n");
  fprintf(stderr, "------------------\n\n");
  sink->print_stats();
  scopesink->print_stats();
}

void InterGetPerfGraph(double sec)
{
  /*  print_stats();*/
  fprintf(stderr, "\nSummary:\n");
  fprintf(stderr, "--------------\n");
  perfgraph->print_stats();
  
  cerr<<"WP: "<<(sink->getWP())<<endl;
  cerr<<"time source: "<<(source->getWP()/source->getSamplingFrequency())<<endl;
  cerr<<"time sink: "<<(sink->getWP()/sink->getSamplingFrequency())<<endl;
  cerr << endl << "Running time: "<<sec<<endl;  
  perfgraph->setTitle("udp transmitter");
  perfgraph->outputGraph(sec);
}

void InterLocalAwaitTSTARTcount(char *ch)
{
  StrlSigProc* x=GetObject(ch);
  x->startAwaitTickCount();
}
void InterLocalAwaitTSTOPcount(char *ch)
{
  StrlSigProc* x=GetObject(ch);
  x->stopAwaitTickCount();
}
void InterLocalIncAwaitTick(char *ch)
{
  StrlSigProc* x=GetObject(ch);
  x->incNumberAwaitTick();
}
void InterGlobalAwaitTSTARTcount()
{
  if(perfgraph!=NULL)
    perfgraph->AwaitTSTARTcount();
  else {
    cerr<<"perfgraph is not open"<<endl;
    exit(1);
  }
}
void InterGlobalAwaitTSTOPcount()
{
  if(perfgraph!=NULL){
    perfgraph->AwaitTSTOPcount();
  }
  else {
    cerr<<"perfgraph is not open"<<endl;
    exit(1);
  }
} 
void InterGlobalIncAwaitTick()
{
  perfgraph->InreaseNUMTick();
}
#endif
/*
const char* InterGetSummer()
{
  summer =new SUMMER_TYPE SUMMER_PARAMETER;
  return summer->name();
}

const char* InterGetScopesink()
{
  scopesink = new SCOPESINK_TYPE SCOPESINK_PARAMETER;
  scopesink->setSkip(1,0);
  return scopesink->name();
}

const char* InterGetSink()
{
  sink =new SINK_TYPE SINK_PARAMETER;
  return sink->name();
}
*/


/***********************************
 * Initialization function
 ***********************************/

void InterInitializeSink(char *r)
{
  StrlSigProc* x=GetObject(r);
  if(x->isConnectedToSource())
    x->init_base();
  else exit(1);
  x->setup();
}

void InterConnectModules(char *r,char *s,int i)
{
  StrlSigProc* x=GetObject(r);
  StrlSigProc* y=GetObject(s);
  x->connect_proc(y,0,i);
}

  /*
void InterMakeTopology()
{
  CONNECT(scopesink, mod, out_rate, 8);
  CONNECT(sink, summer, out_rate, 8);
  CONNECT(summer, mod, out_rate, 8);
  CONNECT(mod, coder, in_rate, 8);
  CONNECT(coder, source, in_rate * output_symbol_bits / 8, 8);
}

void InterMakeTrigger()
{
  mt = new StrlMultiTask();
}

unsigned int InterSinkgetMaxOutputSize(){
  return sink->getMaxOutputSize();
}

unsigned int InterScopeSinkgetMaxOutputSize(){
  return scopesink->getMaxOutputSize();
}
*/
VrSampleRange InterGetSampleRange(char *r)
{
  VrSampleRange srange;
  StrlSigProc* x=GetObject(r);
  srange.index=x->getMarkedWP();
  srange.size=x->getMaxOutputSize();
  return srange;
}

VrSampleIndex InterGetMarkedWP(char *r)
{
  VrSampleIndex indx;
  StrlSigProc* x=GetObject(r);
  indx=x->getMarkedWP();
  return indx;
}


VrSampleIndex InterGetWP(char *r)
{
  VrSampleIndex indx;
  StrlSigProc* x=GetObject(r);
  indx=x->getWP();
  return indx;
}

unsigned int InterGetOutputSize(char *r)
{
  unsigned int p;
  StrlSigProc* x=GetObject(r);
  p=x->getOutputSize();
  return p;
}

int InterGetNumberInputs(char *r)
{
  unsigned int p;
  StrlSigProc* x=GetObject(r);
  p=x->getnumberInputs();
  return (int) p;
}

char* InterForecast(VrSampleRange s, char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange inputs[x->getnumberInputs()];

  x->forecast(s,inputs);
  char *str = (char *)malloc(sizeof(char [STRLEN]));
  sprintf(str, "%lld %lu",inputs[0].index, inputs[0].size); 
  return str;
}

int InterStrlmarkData(VrSampleIndex s,int req,int dm,VrSampleRange range,char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->StrlmarkData(s,req,dm,range);
}

  /*******************************************
   * MARK_DATA calls these function.
   *******************************************/
VrSampleIndex InterminrpCheck(VrSampleIndex pWP,VrSampleRange rg,char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->minrpCheck(pWP,rg);
}
  /*******************************************
   * COMPUTE_DATA calls these function.
   *******************************************/

int InterGet_Mywriterll(char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->Get_Mywriterll();
}

int InterCheck_MymarkedDataSize(char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->Check_MymarkedDataSize();
}

unsigned long InterComputeData(char *r,int ret)
{
  StrlSigProc* x=GetObject(r);
  return x->StrlWork(ret);
}

VrSampleIndex InterGetMymarkedIndex(char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->getMymarkedIndex();
}

unsigned long InterGetMymarkedSize(char *r)
{
  StrlSigProc* x=GetObject(r);
  return x->GetMymarkedSize();
}

VrSampleRange InterGetMymarkedData(char *r)
{
  StrlSigProc* x=GetObject(r);
  VrSampleRange srange;
  srange.index=x->getMymarkedIndex();
  srange.size=x->GetMymarkedSize();
  return srange;
}  

void InterSet_MarkedWP(char *r,VrSampleIndex lg)
{
  StrlSigProc* x=GetObject(r);
  x->Set_MarkedWP(lg);
}

void InterWriteData(char *r,int dx)
{
  StrlSigProc* x=GetObject(r);
  x->StrlWriteData(dx);
}  

} /* end extern "C" */

