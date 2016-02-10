/* Modified 2000, 2001 INRIA */  

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


#ifdef PERFMON
#include <StrlPerfGraph.h>
#include <StrlSigProc.h>
#include <stdio.h>
#include <strings.h>

#define NUM_BARS 1
//#define NUM_BARS 3

StrlCycleCount *overhead = new StrlCycleCount();

void StrlPerfGraph::globalSTARTcount() {
  overhead->startCount();
}
void StrlPerfGraph::globalSTOPcount() {
  overhead->stopCount();
}
void StrlPerfGraph::AwaitTSTARTcount() {
  overhead->startAwaitTCount();
}
void StrlPerfGraph::AwaitTSTOPcount() {
  overhead->stopAwaitTCount();
}
void StrlPerfGraph::InreaseNUMTick() {
  overhead->increaseNumTick();
}
void StrlPerfGraph::add(const char *name, StrlSigProc *m) {

  if(num_modules >= MAXGRAPHMODULES) 
    return;

  StrlSigProc ** ms = new (StrlSigProc *[num_modules+1]);
  ms[num_modules]=m;
  labels[num_modules]=name;
  if(num_modules>0) {
    for(int i=0;i<num_modules;i++) {
      ms[i]=modules[i];
      if(modules[i]==m) {
	delete ms;
	return; //already added
      }
    }
    delete modules;
  }
  modules=ms;
  num_modules++;
}

#define NUMOFGLOBALMODULE 3 //run, compute, schedule item
void StrlPerfGraph::outputGraph(double seconds) {
    
#ifdef PERFMON
  double global_cycles=overhead->getTotalCycles();//gl
  double total_mod_cycles=0;//gl
  int num_gl=NUMOFGLOBALMODULE; //number of module in gl
  const char *gl_labels[NUMOFGLOBALMODULE];
  double gl_cycles[NUMOFGLOBALMODULE];

  gl_labels[0]="Running Time";
  gl_labels[1]="Computing Time";
  gl_labels[2]="Scheduling Time";
  gl_cycles[0]=global_cycles;//Running Time
  gl_cycles[1]=0; //Computing Time
  gl_cycles[2]=0; //Scheduling Time

  FILE *f=fopen("/proc/cpuinfo","r");
  if(f!=NULL) {
    char line[80];
    while(fgets(line,80,f)!=NULL) {
      float b=0;
      if(sscanf(line,"cpu MHz\t: %f",&b)!=0) {
	if(b>10 && b<5000) {
	  cpu_mhz=b;
	  break;
	}
      }
    }
  }
  fclose(f);//hkim

  FILE *fd=popen("gnuplot -geometry 800x500","w");
  int i;
  FILE *fdd=fopen("~/epspectra/data_flow_model/tot_cyc_mod_strl_dfm.gnu","w");//permod
  FILE *fgl=fopen("~/epspectra/data_flow_model/run_comp_sch_strl_dfm.gnu","w");//gl
  fprintf(fd,"set xlabel \"%s\"\n",title);
  fprintf(fd,"set xtics (");
  fprintf(fdd,"set xlabel \"%s\"\n",title);//permod
  fprintf(fdd,"set xtics (");//permod
  fprintf(fgl,"set xlabel \"%s\"\n",title);//gl
  fprintf(fgl,"set xtics (");//gl

  for(i=0;i<num_modules;i++) {
    fprintf(fd,"\"%s\" %d",labels[i],i+1);
    fprintf(fdd,"\"%s\" %d",labels[i],i+1);//permod
    if(i+1<num_modules){
      fprintf(fd,", ");
      fprintf(fdd,", ");//permod
    }
  }
  fprintf(fd,")\n");
  fprintf(fdd,")\n");//permod
  for(i=0;i<num_gl;i++){ //gl
    fprintf(fgl,"\"%s\" %d",gl_labels[i],i+1);
    if(i+1<num_gl){
      fprintf(fgl,", ");
    }
  }
  fprintf(fgl,")\n");//gl
  
  fprintf(fd,"set ylabel \"MCycles\"\n");
  fprintf(fdd,"set ylabel \"MCycles\"\n");//permod
  fprintf(fgl,"set ylabel \"MCycles\"\n");//gl
  if(cpu_mhz>0) {
    fprintf(fd,"set y2label \"%%CPU\"\n");
    fprintf(fd,"set ytics nomirror\n");
    fprintf(fd,"set y2tics\n");
    fprintf(fdd,"set y2label \"%%CPU\"\n");//permod
    fprintf(fdd,"set ytics nomirror\n");//permod
    fprintf(fdd,"set y2tics\n");//permod
    fprintf(fgl,"set y2label \"%%CPU\"\n");//gl
    fprintf(fgl,"set ytics nomirror\n");//gl
    fprintf(fgl,"set y2tics\n");//gl
  }

  fprintf(fd,"set title \"Performance Results on ");
  fprintf(fdd,"set title \"Performance Results on ");//permod
  fprintf(fgl,"set title \"Performance Results on ");//gl
  if(cpu_mhz>0){ 
    fprintf(fd,"%.1f",cpu_mhz);
    fprintf(fdd,"%.1f",cpu_mhz);//permod
    fprintf(fgl,"%.1f",cpu_mhz);//gl
  }
  else{
    fprintf(fd,"???");
    fprintf(fdd,"???");//permod
    fprintf(fgl,"???");//gl
  }
  fprintf(fd," MHz machine (for %f seconds)\"\n",seconds);
  fprintf(fdd," MHz machine (for %f seconds)\"\n",seconds);//permod
  fprintf(fgl," MHz machine (for %f seconds)\"\n",seconds);//gl
  //  fprintf(fd,"set nokey\n");
  //  printf("set xtics 0,history\n");
  fprintf(fd,"set time\n");
  fprintf(fd,"set grid\n");
  fprintf(fdd,"set time\n");//permod
  fprintf(fdd,"set grid\n");//permod
  fprintf(fgl,"set time\n");//gl
  fprintf(fgl,"set grid\n");//gl
  
  float bar_width = 1/(float) (NUM_BARS+2);
  fprintf(fd,"set boxwidth %.2f\n",bar_width);
  fprintf(fdd,"set boxwidth %.2f\n",bar_width);//permod
  fprintf(fgl,"set boxwidth %.2f\n",bar_width);//gl

  float max_cycles=1;
  for(i=0; i<num_modules; i++) {
    const char *n = modules[i]->name();
    if(strcmp(n,"StrlScopeSink")==0){
      total_mod_cycles+=modules[i]->getTotalCyclesMS();
      if(max_cycles<modules[i]->getTotalCyclesMS())
	max_cycles=modules[i]->getTotalCyclesMS();
    }
    else{
      total_mod_cycles+=modules[i]->getTotalCycles();//gl
      if(max_cycles<modules[i]->getTotalCycles())
	max_cycles=modules[i]->getTotalCycles();
    }
  }
  gl_cycles[1]=total_mod_cycles;//gl computing time
  if(global_cycles<=total_mod_cycles){
    fprintf(stderr, "\n impossible case:total module time is greater then global time \n");
    exit(0);
  }
  gl_cycles[2]=gl_cycles[0]-gl_cycles[1];//gl scheduling time

  float divisor1 = 1000000; //Million
  if(cpu_mhz>0) {
    //Convert to percent
    float divisor2 = 10000; //Million / 100
    divisor2 *= (seconds*cpu_mhz); // Divide by # Mcycles in seconds
    fprintf(fd,"set y2range [0:%d]\n",(int) (((max_cycles / divisor2) * 1.1)+.5));
    fprintf(fdd,"set y2range [0:%d]\n",(int) (((max_cycles / divisor2) * 1.1)+.5));//permod
    fprintf(fgl,"set y2range [0:%d]\n",(int) (((gl_cycles[0] / divisor2) * 1.1)+.5));
  }

  max_cycles /= divisor1; 
  max_cycles *= 1.1;     //Add a little
  max_cycles += .5;      //Round up

  fprintf(fd,"plot [0:%d][%d:%d] \"-\" title \"cycles\" w boxes\n",num_modules+1, 0, (int) max_cycles);
  //  fprintf(fd,", \"-\" title \"%s\" w boxes",PERF1_NAME);
  //  fprintf(fd,", \"-\" title \"%s\" w boxes\n",PERF2_NAME);
  fprintf(fdd,"plot [0:%d][%d:%d] \"-\" title \"cycles\" w boxes\n",num_modules+1, 0, (int) max_cycles);//permod
  
  global_cycles /= divisor1; 
  global_cycles *= 1.1;     //Add a little
  global_cycles += .5;      //Round up
  fprintf(fgl, "plot [0:%d][%d:%d] \"-\" title \"cycles\" w boxes\n",num_gl+1, 0, (int) global_cycles);//gl

  for(int j=0;j<NUM_BARS;j++) {
    for(i=0; i<num_modules; i++) {
      const char *n = modules[i]->name();
      if(strcmp(n,"StrlScopeSink")==0){
	fprintf(fd,"%f %f\n",i+1+(bar_width*(j-NUM_BARS/2.0)), ((float) modules[i]->getTotalCyclesMS())/divisor1);
	fprintf(fdd,"%f %f\n",i+1+(bar_width*(j-NUM_BARS/2.0)), ((float) modules[i]->getTotalCyclesMS())/divisor1);//permod
	}else{
	fprintf(fd,"%f %f\n",i+1+(bar_width*(j-NUM_BARS/2.0)), ((float) modules[i]->getTotalCycles(j))/divisor1);
	fprintf(fdd,"%f %f\n",i+1+(bar_width*(j-NUM_BARS/2.0)), ((float) modules[i]->getTotalCycles(j))/divisor1);//permod
      }
    }
    for(i=0; i<num_gl; i++){
      fprintf(fgl,"%f %f\n",i+1+(bar_width*(j-NUM_BARS/2.0)), ((float) gl_cycles[i])/divisor1);//gl
    }
    fprintf(fd,"e\n");
    fprintf(fdd,"e\n");//permod
    fprintf(fgl,"e\n");//gl
  }

  fflush(fd);

  fprintf(stderr, "\nPress enter:\n");
  //  sleep(10);
  getchar();
  pclose(fd);
  fclose(fdd);//permod
  fclose(fgl);//gl
  gnu_sample_modules(seconds);
#else

  fprintf(stderr, "You must define PERFMON before compiling to get performance results\n");

#endif
}

#define NUM_SAM_BARS 1
void StrlPerfGraph::gnu_sample_modules(double seconds){
  int i;
  FILE *fdd=fopen("~/epspectra/data_flow_model/tot_smpl_mod_strl_dfm.gnu","w");//define directory
  fprintf(fdd,"set xlabel \"%s\"\n","Total samples: the original udp transmitter");//define the name of this result
  fprintf(fdd,"set xtics (");

  for(i=0;i<num_modules;i++) {
    fprintf(fdd,"\"%s\" %d",labels[i],i+1);
    if(i+1<num_modules){
      fprintf(fdd,", ");
    }
  }
  fprintf(fdd,")\n");
  
  fprintf(fdd,"set ylabel \"Samples\"\n");//define the name of y left label
  if(cpu_mhz>0) {
    //    fprintf(fdd,"set y2label \"average cycles/sample\"\n");//define the name of y right label
    fprintf(fdd,"set ytics nomirror\n");
    //    fprintf(fdd,"set y2tics\n");//
  }
  fprintf(fdd,"set title \"Performance Results on ");//define title
  if(cpu_mhz>0){ 
    fprintf(fdd,"%.1f",cpu_mhz);
  }
  else{
    fprintf(fdd,"???");
  }
  fprintf(fdd," MHz machine (for %f seconds)\"\n",seconds);
  fprintf(fdd,"set time\n");
  fprintf(fdd,"set grid\n");
  
  float bar_width = 1/(float) (NUM_SAM_BARS+2);
  fprintf(fdd,"set boxwidth %.2f\n",bar_width);
  /************* measurement of y axe metrix ********************/
  float max_samples=1;
  for(i=0; i<num_modules; i++) {
    if(max_samples<modules[i]->getTotalSamples())
      max_samples=modules[i]->getTotalSamples();
  }
  /************* mapping cpu loading to cycle **************/
  //  if(cpu_mhz>0) {
    //Convert to percent
  //    float divisor2 = 10000; //Million / 100
  //    divisor2 *= (seconds*cpu_mhz); // Divide by # Mcycles in seconds
  //    fprintf(fdd,"set y2range [0:%d]\n",(int) (((max_cycles / divisor2) * 1.1)+.5));//permod
  //  }

  //  float divisor1 = 1000000; //Million
  //  max_samples /= divisor1; 
  max_samples *= 1.1;     //Add a little
  max_samples += .5;      //Round up

  fprintf(fdd,"plot [0:%d][%d:%d] \"-\" title \"samples\" w boxes\n",num_modules+1, 0, (int) max_samples);//define range of metrix

  for(int j=0;j<NUM_SAM_BARS;j++) {
    for(i=0; i<num_modules; i++) {
      fprintf(fdd,"%f %f\n",i+1+(bar_width*(j-NUM_SAM_BARS/2.0)), modules[i]->getTotalSamples());//get samples per module
    }
    fprintf(fdd,"e\n");//the sign of the end of gnu file
  }
  fclose(fdd);//close file
}

void StrlPerfGraph::print_stats() {
    
#ifdef PERFMON
  int i;
  fprintf(stderr, "Total samples generated by module:\n");
  for(i=0; i<num_modules; i++) {
    const char *n = modules[i]->name();
    fprintf(stderr, "%20s: %15ld\n",n, modules[i]->getTotalSamples());
  }

  double total[NUM_BARS];//computing
  for(int j=0;j<NUM_BARS;j++) {
    fprintf(stderr, "\nTotal (Average per sample) %s generated by module:\n",StrlCycleCount::measurementName(j));
    total[j]=0;
    for(i=0; i<num_modules; i++) {
      const char *n = modules[i]->name();
      if(strcmp(n,"StrlScopeSink")==0){
	fprintf(stderr, "%20s: %15.f (%7.f)\n",n, modules[i]->getTotalCyclesMS(),modules[i]->getCyclesPerSampleMS());
	total[j]+=modules[i]->getTotalCyclesMS();}
	else{
	fprintf(stderr, "%20s: %15.f (%7.f)\n",n, modules[i]->getTotalCycles(j),modules[i]->getCyclesPerSample(j));
	total[j]+=modules[i]->getTotalCycles(j);}
    }
  }

  fprintf(stderr, "\nComputing / Scheduling(including X-Win) / (%%):\n");
  double system=0;
  for(int j=0;j<NUM_BARS;j++) {
    char *n=StrlCycleCount::measurementName(j);
    system = (double)overhead->getTotalCycles(j); //scheduling
    fprintf(stderr, "%s:\n%15.f / %15.f  %02.2f%%\n",n, total[j], system-total[j], (system-total[j])*100.0/system);
  }
  /***
  fprintf(stderr, "\nDistribution of Scheduling cycle:\n");
  fprintf(stderr, "---------------\nThe number of await tick generated by module:\n");
  long long tick_num=0;
  for(i=0; i<num_modules; i++) {
    const char *n = modules[i]->name();
    fprintf(stderr, "%20s: %7lld\n",n,modules[i]->getNumerAwaitTick());
    tick_num+=modules[i]->getNumerAwaitTick();
  }
  fprintf(stderr,"%20s: %7lld\n","etc",(overhead->getNumAwaitTick()-overhead->getNumAwaitTick()));
  //tick_num+=overhead->getNumAwaitTick();
  fprintf(stderr,"%20s: %7lld\n","Sum",tick_num);
  fprintf(stderr,"\naverage cycles per await tick = %f\n",overhead->getAwaitTCycles());
  fprintf(stderr,"\nIn the scheduling cycles:\n");
  fprintf(stderr,"Overhead of AwaitTick over Scheduling (%%):\n");
  fprintf(stderr,"%18f / %18f  %02.2f%%\n",system,overhead->getAwaitTCycles()*tick_num,(overhead->getAwaitTCycles()*tick_num*100.0)/system);
  ***/
#else

  fprintf(stderr, "You must define PERFMON before compiling to get performance results\n");

#endif
}
#endif /* PERFMON */
