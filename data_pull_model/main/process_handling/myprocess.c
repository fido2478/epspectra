#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

#define ENUF(msg, value) { perror(msg); exit(value); }

void action_TICK () {fprintf(stderr, "\n*** tick ***\n");}
void childINT()  { fprintf(stderr, "\n*** Child got SIGINT ***\n"); }
void parentINT() { fprintf(stderr, "\n*** Parent got SIGINT ***\n");}
void prt_status(int w, int p, int s){ 
  if (w == p)
    fprintf(stderr, "Termination status: %d, Exit status: %d \n",
                            s & 0377, (s >> 8) & 0377); 
}                            
goto_EXIT() {exit(1);}

int procID;

main(){
  void action_TICK ();
  void childCONT(), childKILL(), childTSTP(), childINT(), parentINT();
  
  switch (procID=fork()) {
  case -1 : fprintf(stderr, "Unable to fork\n");
    exit(0);
    break;
  case 0 : slave();
  default : master();
  }
}

slave () {
  int i;
  void (*oldINT)();
  i=0;
  oldINT=signal( SIGINT , SIG_IGN);/* returns original value */ 
  if (oldINT != SIG_IGN ) 
    signal(SIGINT,action_TICK);
  fprintf(stderr,"\nChild started\n"); 
  fprintf(stderr,"[child]procID %d, getpid %d, getppid %d\n",procID,getpid(),getppid());

  for(;;) {
    pause(); /* wait for a signal */ 
    if ((i=kill(getppid(), SIGINT)) != 0 ) 
      ENUF("SIGINT/child", i); 

  }
  /*
  fprintf(stderr,"\nChild sends SIGINT to %d\n",getppid());
  if ((i=kill(getppid(), SIGINT)) != 0 ) 
    ENUF("SIGINT/child", i); 
  fprintf(stderr,"\nChild mutates\n"); 
  if (execlp("PDEMO","PDEMO",NULL)<0) 
  ENUF("can not run command", 97); */
}

master () {
  int status;
  unsigned long long i;
  i=0;
  signal(SIGINT, parentINT);
  fprintf(stderr,"\nParent started\n"); 
  fprintf(stderr,"[father]procID %d, getpid %d\n",procID,getpid());
  sleep(1); 
  fprintf(stderr,"\nParent sends SIGINT to %d\n",procID); 

  /*  for (i=0;;i=i+1){*/
  for (;;) {
    if (kill(procID,  SIGINT) != 0 ) 
      ENUF("SIGINT/parent", 0); 
    /*    pause(); /* wait for a signal */ 
    /*    sleep(0.3);
	  fprintf(stderr,"%lld\n",i);*/
  };
  /*  fprintf(stderr,"\nParent sends SIGTSTP to %d\n",procID); 
  if ((i= kill(procID,  SIGTSTP)) != 0 ) 
    ENUF("SIGTSTP/parent", i); 
  prt_status(wait3(&status, WUNTRACED, 0), procID, status); 
  fprintf(stderr, "\nParent sends SIGCONT\n"); 
  if ((i= kill(procID,  SIGCONT)) != 0 ) 
    ENUF("SIGCONT/parent", i); 
  sleep(3); 
  fprintf(stderr, "\nParent sends SIGKILL\n"); */

  if ((i= kill(procID,  SIGKILL)) != 0 ) 
    ENUF("SIGKILL/parent", i); 
  prt_status(wait(&status), procID, status); 
}
