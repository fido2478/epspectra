#include <stdio.h>

#include <sys/time.h>

#include <sys/resource.h>

#define ENUF(msg, value) {perror(msg); exit(value); }
 
extern int errno;               /* global error number variable */
int procID;
main(argc, argv)
int argc;
char *argv[];
{
char buf[40];
 int i;
  
  if (argc != 1 ) ENUF("Usage: DEMO command\n", 1); 
  errno=0;
  procID = getpid();
  sprintf(buf, "ps lx | grep '%d' | grep -v  grep", procID); 
  for (i=1; i != 4; i++) { 
     if (errno != 0) ENUF("could not set priority", 2)
     else { info(i); system(buf); }
  }
  info(0) ; system(buf); 
  fprintf(stdout,
     "Priority on completion is %d\n",getpriority(PRIO_PROCESS, procID));
} /* main */
 
info(i)
int i;
{
  fprintf(stdout,
     "Current priority is %d\n",getpriority(PRIO_PROCESS,procID));
 
  if (setpriority(PRIO_PROCESS,procID,i)<0) ENUF("could not set priority",3); 
}
