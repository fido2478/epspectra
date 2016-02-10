

#include <stdio.h>

#define ENUF(message, value)   { perror(message); exit(value); }
 
char **environ;               /* environment strings and values */
 
main(argc, argv)
int argc;
char *argv[];
{
  char *opts[3];              /* array of program options */
  char newenv[50][100];       /* new environment space */
  char *eptrs[50];       /* array of environment pointers */
  int i;
  char **t;
 
  if (argc != 2)
     ENUF("Usage:DEMO execl/execlp/execv/execvp/execle/execve\n",1);
 
  if (strcmp(argv[1], "execl") == 0){
     display("execl(\"/usr/ucb/vi\", \"ex\", \"mutant.c\", NULL)\n");
     if (execl("/usr/ucb/vi", "ex", "mutant.c", NULL) <0) ENUF("(execl)", 1)} 
  if (strcmp(argv[1], "vi")== 0){ 
    display("execl(\"/usr/ucb/vi\", \"vi\", \"mutant.c\", NULL)\n"); 
    if (execl("/usr/ucb/vi", "vi", "mutant.c", NULL) < 0) ENUF("(execl)", 1) } 
  else 
    if (strcmp(argv[1], "execlp")== 0) { 
      display("execlp(\"ps\", \"-x\", NULL) \n"); 
      fprintf(stdout, "PID before execlp is %d\n", getpid()); 
      if (execlp("ps", "-x", NULL) < 0) ENUF("(execlp)", 2); } 
    else 
      if (strcmp(argv[1], "execv")== 0) { 
	display("execv(\"/usr/ucb/which\", opts) \n"); 
	opts[0]="which" ; 
	opts[1]="ls" ; 
	opts[2]="NULL";
	  if (execv("/usr/ucb/which", opts) < 0) 
	    ENUF("(execv)", 3); 
      } 
      else 
	if (strcmp(argv[1], "execvp")== 0) { 
	  display("execvp(\"size\", opts)\n"); 
	  opts[0]="size" ; 
	  opts[1]="DEMO" ; 
	  opts[2]="NULL"; 
	    if (execvp("size", opts) < 0) 
	      ENUF("(execvp)", 4); } 
	else 
	  if (strcmp(argv[1], "execle")== 0) { /* mutate with unchanged environment space */ 
	    display("execle(\"/usr/ucb/printenv\",\"printenv\",\"USER\",NULL,environ)\nUSER=");
	    if (execle(" /usr/ucb/printenv","printenv","USER",NULL,environ)<0) ENUF("(execle)",5); } 
	  else 
	    if (strcmp(argv[1], "execve")== 0) { /* mutate with changed environment space */ 
	      display("execve(\"/usr/ucb/printenv\", opts, eptrs) \nUSER=");
	      opts[0]=" printenv"; 
	      opts[1]="USER" ; 
	      opts[2]="NULL"; 
		for (i="0," *t="environ;" *t !="NULL;" i++, t++){ 
		  eptrs[i]="*t;" /* copy pointer */ strcpy(newenv[i], *t); /* copy original env. string */ 
		  if (strncmp("USER=", eptrs[i], 5) == 0) 
		    eptrs[i]=" USER="Ninja";" /* over-write environment variable */ 
		      } 
	      eptrs[i]="NULL"; 
		if (execve("/usr/ucb/printenv",opts,eptrs) < 0) 
		  ENUF("(execve)", 6); } /* now generate some errors */ 
	    else 
	      if (strcmp(argv[1], "noddy")== 0){ 
		display("execl(\"/tmp/noddy\", NULL) \n"); 
		if (execl("/tmp/noddy", NULL)<0) 
		  ENUF("this program does not exist",7); 
	      } 
} /* main */ 
display (s) char *s; { fprintf(stdout, "*** %s", s); } 
