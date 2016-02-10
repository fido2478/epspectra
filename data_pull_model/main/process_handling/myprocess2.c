#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

#define ENUF(msg, value) { perror(msg); exit(value); }

int procID;

void action_TICK () {fprintf(stderr, "\n*** tick ***\n");}
void childINT()  { 
  for(;;){
    action_TICK ();}
  if (kill(getppid(), SIGINT) != 0 ) 
    ENUF("SIGINT/child", 0); 

}
void parentINT() { 
  fprintf(stderr, "\n*** Parent got SIGINT ***\n");
  if (kill(procID,  SIGINT) != 0 ) 
    ENUF("SIGINT/parent", 0);
}
void prt_status(int w, int p, int s){ 
  if (w == p)
    fprintf(stderr, "Termination status: %d, Exit status: %d \n",
                            s & 0377, (s >> 8) & 0377); 
}                            
goto_EXIT() {exit(1);}

main(){
  void action_TICK ();
  void childKILL(), childINT(), parentINT();
  
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

  oldINT=signal( SIGINT , SIG_IGN);/* returns original value */ 
  if (oldINT != SIG_IGN ) 
    signal(SIGINT,childINT);

  fprintf(stderr,"\nChild started\n"); 

  for(;;){}
}

static struct termios stored_settings;

void set_keypressed (void) 
{
  struct termios new_settings;

  tcgetattr (0, &stored_settings);

  new_settings = stored_settings;
  
  new_settings.c_lflag &= (~ICANON);
  new_settings.c_cc[VTIME] = 0;
  new_settings.c_cc[VMIN] = 1;

  tcsetattr (0, TCSANOW, &new_settings);
  return;
}

void reset_keypressed (void)
{
  tcsetattr (0, TCSANOW, &stored_settings);
  return;
}

master () {
  int status;
  int i;
  fd_set rfds;
  struct timeval tv;
  int retval;
  char c;
  set_keypressed ();

  FD_ZERO(&rfds);
  FD_SET(0, &rfds);

  signal(SIGINT, parentINT);
  fprintf(stderr,"\nParent started\n"); 
  sleep(1); 

  if (kill(procID,  SIGINT) != 0 ) 
    ENUF("SIGINT/parent", i); 
  
  select (1, &rfds, NULL, NULL, NULL);

  if ((i= kill(procID,  SIGKILL)) != 0 ) 
    ENUF("SIGKILL/parent", i);

  c = getchar();
  reset_keypressed ();

}
