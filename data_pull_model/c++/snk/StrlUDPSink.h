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

#ifndef _STRLUDPSINK_H_
#define _STRLUDPSINK_H_
#define __volatile__

#include <StrlSink.h>
#include <fstream.h>
#include <sys/socket.h> 
#include <string.h>
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/wait.h>
#include <netdb.h> 
#include <arpa/inet.h>
#include <iostream.h>
#include <netinet/in.h>

#include <sys/time.h>
#include <unistd.h>

#define MAX_UDP 1990
template<class iType> 
class StrlUDPSink : public StrlSink<iType> {
private:
  int sockfd;
  int outputsize;
  int sleep_time;
  struct sockaddr_in their_addr;
  struct hostent *he;
  unsigned long long next_time;

public:
  virtual const char *name() { return "StrlUDPSink"; }
  virtual int work(VrSampleRange output, 
		   VrSampleRange inputs[], void *i[]);

  virtual void set_sleep_time(int t) { sleep_time = t; } 
  virtual void initialize() {
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
            perror("socket");
            exit(1);
        }
  	printf("%s initialize socket as %d\n",name(),sockfd);
//	cout<<"In the "<<name()<<"initializing"<<endl;
  }

  StrlUDPSink(char* hostname, int port) {
	next_time = 0;
    if ((he=gethostbyname(hostname)) == NULL) {  /* get the host info */
      herror("gethostbyname");
      exit(1);
    }
    their_addr.sin_family = AF_INET;      /* host byte order */
    their_addr.sin_port = htons(port);  /* short, network byte order */
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    bzero(&(their_addr.sin_zero), 8);     /* zero the rest of the struct */
  }
  virtual ~StrlUDPSink() { }
};

template<class iType> int
StrlUDPSink<iType>::work(VrSampleRange output, 
			VrSampleRange inputs[], void *ai[])
{
  struct timeval now; 
  unsigned long long this_time;
  int current, temp;
  int left=output.size*sizeof(iType);
  unsigned char *cp = (unsigned char *)ai[0];

#ifdef PRINT_OUT_SR
  printf("%s (work) : output SampleRange [%lld, %lu]\n",name(),output.index, output.size);
#endif

#ifdef SLOWDOWN
  gettimeofday(&now,NULL);
  this_time = now.tv_sec * 1000000 + now.tv_usec;
  if (this_time < next_time){
    printf("sleeping : %lu usec \n", (next_time - this_time));
    usleep((int) (next_time - this_time));
  }
#define SAMPLE_TIME 125	/* usec / sample */
  next_time = this_time + output.size * SAMPLE_TIME;
#endif

  while (left > 0) {
    current = left;
    if (current > MAX_UDP)
       current = MAX_UDP;
    temp =sendto(sockfd, cp, current, 0,
		  (struct sockaddr *)&their_addr, sizeof(struct sockaddr));
#ifdef SLOWDOWN
	usleep(200000);	// slow down output from source
#endif
    //printf("%s (work) : current %d, temp %d\n",name(),current,temp); 
    //jca YIELD();
    if (temp>0){  //ignore any errors mofo
      cp += temp;
      left -= temp;
    }
    else {
      printf ("[%s:%d] sendto errno %d\n", __FILE__, __LINE__, errno);
      break;
    }
#ifdef COMP_VAL
    printf("in %c ",*cp);
#endif
  }
#ifdef DEBUG
  printf("%s (work) return : %lu(output.size)\n",name(),output.size);  
#endif 
  return output.size;
}
#endif
