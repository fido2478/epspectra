#include <stdio.h>

#include <signal.h>

         /* SIGTSTP, SIGKILL */

#include <sys/wait.h>

       /* WUNTRACED */
 
#define ENUF(msg, value) { perror(msg); exit(value); }
 
/* to compile under Solaris link with -lucb */
 
void childINT()  { fprintf(stderr, "\n*** Child got SIGINT ***\n"); }
 
void parentINT() { fprintf(stderr, "\n*** Parent got SIGINT ***\n");}
 
void prt_status(int w, int p, int s)
{ if (w == p)fprintf(stderr, "Termination status: %d, Exit status: %d \n",
                            s & 0377, (s >> 8) & 0377); }
 
main(argc, argv)
int argc;
char *argv[];
{ int i, procID;
  void childCONT(), childKILL(), childTSTP(), childINT(), parentINT();
  void (*oldINT)();
  int status;
 
  if (argc != 1 ) 
    ENUF("Usage:  DEMO command\n",1);
  if ((procID = fork())<0) 
    ENUF("Unable to create new process", 98)
  else 
    if (procID== 0 ) 
      { /* Child process code */
	oldINT=signal( SIGINT , SIG_IGN);/* returns original value */ 
	if (oldINT != SIG_IGN ) 
	  signal(SIGINT, childINT); 
	fprintf(stderr,"\nChild started\n"); 
	fprintf(stderr,"[child]procID %d, getpid %d, getppid %d\n",procID,getpid(),getppid());
	pause(); /* wait for a signal */ 
	fprintf(stderr,"\nChild sends SIGINT to %d\n",getppid());
	if ((i=kill(getppid(), SIGINT)) != 0 ) 
	  ENUF("SIGINT/child", i); 
	fprintf(stderr,"\nChild mutates\n"); 
	if (execlp("PDEMO","PDEMO",NULL)<0) 
	  ENUF("can not run command", 97); 
      } 
    else 
      { /* Parent process code */ 
	signal(SIGINT, parentINT); 
	fprintf(stderr,"\nParent started\n"); 
	fprintf(stderr,"[father]procID %d, getpid %d\n",procID,getpid());
	sleep(1); 
	fprintf(stderr,"\nParent sends SIGINT to %d\n",procID); 
	if ((i= kill(procID,  SIGINT)) != 0 ) 
	  ENUF("SIGINT/parent", i); 
	pause(); /* wait for a signal */ 
	sleep(3); 
	fprintf(stderr,"\nParent sends SIGTSTP to %d\n",procID); 
	if ((i= kill(procID,  SIGTSTP)) != 0 ) 
	  ENUF("SIGTSTP/parent", i); 
	prt_status(wait3(&status, WUNTRACED, 0), procID, status); 
	fprintf(stderr, "\nParent sends SIGCONT\n"); 
	if ((i= kill(procID,  SIGCONT)) != 0 ) 
	  ENUF("SIGCONT/parent", i); 
	sleep(3); 
	fprintf(stderr, "\nParent sends SIGKILL\n"); 
	if ((i= kill(procID,  SIGKILL)) != 0 ) 
	  ENUF("SIGKILL/parent", i); 
	prt_status(wait(&status), procID, status); 
      } 
} /* main */
