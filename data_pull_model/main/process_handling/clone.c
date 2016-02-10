#include <stdio.h>

#define ENUF(msg, value) { perror(msg); exit(value); }
main(argc, argv)
int argc;
char *argv[];
{int ChildDoze, ParentDoze, procID;
 
 if (argc != 2 ) ENUF("Usage: DEMO F or B \n", 1);
  
  if ((argv[1][0]=='B')||(argv[1][0]=='b'))      { ChildDoze=10; ParentDoze=5; }
  else if ((argv[1][0]=='F')||(argv[1][0]=='f')) { ChildDoze=5; ParentDoze=10; }
  else ENUF("illegal option %s \n", 99);
 
  if ( ( procID = fork() ) == 0) { /* Child process code i.e. ProcID == 0 */
     fprintf(stdout, " Child:Before doze own and parent IDs are %d %d \n",
               getpid(), getppid());
     sleep(ChildDoze);
     fprintf(stdout, " Child:After doze own and parent IDs are  %d %d \n",
               getpid(), getppid());
 
     if (execlp("ps", "ps", "-x", NULL) <0) ENUF("can not fork", 2); } else { /* Parent process code i.e. ProcID <> 0 */
     fprintf(stdout,
          "Parent:Before doze child,own and parent IDs are %d %d %d\n",
          procID, getpid(), getppid());
     sleep(ParentDoze);
     fprintf(stdout,
          "Parent:After doze child,own and parent IDs are %d %d %d \n",
          procID, getpid(), getppid()); }
} /* main */
