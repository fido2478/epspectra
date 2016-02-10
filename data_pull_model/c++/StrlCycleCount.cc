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

#include<StrlCycleCount.h>

#ifdef PERFMON
static int counts_started = 0;

void StrlCycleCount::print_stats() {
#ifdef THREADS
    fprintf(stderr, "# units of data skipped= %lld\n", skippedData);
    fprintf(stderr, "# times buffer was full= %lld\n", bufferFullOnWrite);
    fprintf(stderr, "# times the update of WP was delayed= %lld\n", WPdelayedUpdate);
    fprintf(stderr, "# times data was attempted to be marked in the wrong order= %lld\n", blockOnUnmarkedData);
    fprintf(stderr, "# times work() did not complete all the work forecast() claimed it would= %lld\n", uncompleteWork);
    fprintf(stderr, "amount of time spent waiting for WP to update in upstream module= %lld\n", blockOnMarkedData);
    fprintf(stderr, "amount of time spent in sync()= %lld\n\n", blockOnSync);
#endif

    fprintf(stderr, "# samples written= %ld\n", totalSamples);
#ifdef PERFCTR
    fprintf(stderr, "cycles spent in work()= %lld\n", total.counter[0]);
    fprintf(stderr, "%s in work()= %lld\n", PERF1_NAME, total.counter[1]);
    fprintf(stderr, "%s in work()= %lld\n", PERF2_NAME,total.counter[2]);
#else
    fprintf(stderr, "cycles spent in work()= %.f\n",PMCCycle);
#endif
    if(totalSamples) {
#ifdef PERFCTR
      fprintf(stderr, "average cycles/output sample= %lld\n", total.counter[0]/totalSamples);
      fprintf(stderr, "average %s/output sample= %lld\n",PERF1_NAME, total.counter[1]/totalSamples);
      fprintf(stderr, "average %s/output sample= %lld\n\n",PERF2_NAME, total.counter[2]/totalSamples);
#else
      fprintf(stderr, "average cycles/output sample= %.f\n",PMCCycle/totalSamples);
      //      fprintf(stderr,"* cycles spent in 'await tick'=%lld\n",getAwaitTCycles());
    fprintf(stderr,"* the number of times=%lld\n",getNumAwaitTick());
    //    fprintf(stderr,"*average cycle / await tick = % lld \n",getAwaitTCycles()/getNumAwaitTick());
#endif
    }
  }

StrlCycleCount::StrlCycleCount() {
    resetCount();
    if(pthread_mutex_init(&mutex, NULL)!=0) {
      fprintf(stderr, "Couldn't initialize mutex\n");
      exit(-1);
    }
#ifdef THREADS
    if(pthread_key_create(&mystart, NULL)!=0) {
      fprintf(stderr,"StrlCycleCount: Could not create thread specific variable.\n");
      exit(-1);
    }
    if(pthread_mutex_init(&mutex, NULL)!=0) {
      fprintf(stderr, "Couldn't initialize mutex\n");
      exit(-1);
    }
#else
#ifdef PERFCTR
    start.counter[0] =  0; //mark counter stopped
#else
    first.hi=0;first.lo=0;
    last.hi=0;last.lo=0;
    AwaitTfirst.hi=0;AwaitTfirst.lo=0;
    AwaitTlast.hi=0;AwaitTlast.lo=0;
#endif
#endif
    if(!counts_started) {
      //perfctr_print_info(); //DEBUG
#ifndef THREADS
      if(START_COUNTS()<0) {
	perror("StrlCycleCount: could not start counts");
	fprintf(stderr,"Must be running on a system with the /dev/perfctr driver installed.\n");
	exit(-1);
      }
#endif
      counts_started=1;
    }
  }

#endif //PERFMON
