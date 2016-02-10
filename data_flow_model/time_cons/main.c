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


#include <stdio.h>
#include <sys/time.h>
#include "TC_UDP_TX.h"
#include "main_strl.h"

struct timeval initialTime;
startTimer()
{
  if (gettimeofday(&initialTime, 0) < 0) {
    perror("VrMultiTask: gettimeofday failed!!!");
    exit(1);
  }
}

double elapsedTime()
{
  unsigned long usecs;
  struct timeval t2;
  
  if (gettimeofday(&t2, 0) < 0) {
    perror("VrMultiTask: gettimeofday failed!!!");
    exit(1);
  }
  
  usecs = (t2.tv_sec - initialTime.tv_sec)*1000000 + 
    (t2.tv_usec - initialTime.tv_usec);
  return usecs/1000000.0;
}

main(int argc,char** argv){
  double seconds;
  double dt;
  fprintf(stderr,"#######################################\n");
  fprintf(stderr," You can specify \"dt\" and \"runtime\".\n");
  fprintf(stderr,"#######################################\n");
  if (argc > 1){
    dt=atoi(argv[1]);
    if (argc > 2)
      seconds=atoi(argv[2]);
    else
      seconds=20;}
  else {
    dt=2;        /* default dt = 2 */
    seconds=20;  /* default sec = 20 */
  }
  fprintf(stderr,"\ndt : %f\t runtime : %f\n\n",dt,seconds);
  TC_UDP_TX_I_inputdt(dt);
  startTimer();
  for(;elapsedTime()<seconds;)
     /* 	for (;;)*/
    TC_UDP_TX();
  STOP_PERF_GRAPH();
  GET_PERF_GRAPH(seconds);

}
