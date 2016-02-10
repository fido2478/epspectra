#include <stdio.h>
#include <sys/time.h>
#include "../PERF_STRL.h"
#include "lib4main.h"

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
  fprintf(stderr,"#######################################\n");
  fprintf(stderr," You can specify \"runtime\".\n");
  fprintf(stderr,"#######################################\n");
  if (argc > 1)
    seconds=atoi(argv[1]);
  else
    seconds=20;
  startTimer();
  for(;elapsedTime()<seconds;)
    PERF_STRL();
  STOP_PERF_GRAPH();
  GET_PERF_GRAPH(seconds);
}
