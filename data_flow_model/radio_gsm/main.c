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
#include "GSM_ALL.h"

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
  /*
  double seconds;
  fprintf(stderr,"#######################################\n");
  fprintf(stderr," You can specify \"runtime\".\n");
  fprintf(stderr,"#######################################\n");*/
/*  if (argc > 1)
    seconds=atoi(argv[1]);
  else
    seconds=20;
  startTimer();
  for(;elapsedTime()<seconds;)*/
  GSM_ALL();
  GSM_ALL_I_InitRange("0 1600");/*set initrange*/
  while(1){
    GSM_ALL();
  }
}
