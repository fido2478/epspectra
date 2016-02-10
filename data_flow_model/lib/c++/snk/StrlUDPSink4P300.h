/*  Modified 2000, 2001 INRIA */

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
  unsigned long numofpacket; //for know the loss of sent packet
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
    numofpacket=0;
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
    int tmp=(next_time - this_time);
    //printf("sleeping* : %lu usec \n", tmp);//average=45000, 55000 max=110000
    //this average is optimized for notebook PC with P300
    if(tmp>170000){
      tmp=tmp*3.8888889;//2.1875;
      usleep((int)(tmp));
      printf("sleeping175 : %lu usec \n", tmp);}
    else if(tmp>160000){
      tmp=tmp*3.6666667;//2.0625;
      usleep((int)(tmp));
      printf("sleeping165 : %lu usec \n", tmp);}
    else if(tmp>150000){
      tmp=tmp*3.4444444;//1.9375;
      usleep((int)(tmp));
      printf("sleeping155 : %lu usec \n", tmp);}
    else if(tmp>140000){
      tmp=tmp*3.2222222;//2.6363636;//1.8125;
      usleep((int)(tmp));
      printf("sleeping145 : %lu usec \n", tmp);}
    else if(tmp>130000){
      tmp=tmp*3;//2.4545455;//1.6875;
      usleep((int)(tmp));
      printf("sleeping135 : %lu usec \n", tmp);}
    else if (tmp>120000){//(125000/40000)
      tmp=tmp*2.2727273;//3.125;//1.5625;
      usleep((int)(tmp));
      printf("sleeping125 : %lu usec \n", tmp);}
    else if (tmp>110000){//(115000/55000)
      tmp=tmp*2.5555556;//2.0909091;//1.4375;
      usleep((int)(tmp));
      printf("sleeping115 : %lu usec \n", tmp);}
    else if (tmp>100000){//(105000/60000)
      tmp=tmp*2.3333333;//1.9090909;//1.75;//1.3125;
      usleep((int)(tmp));
      printf("sleeping105 : %lu usec \n", tmp);}
    else if (tmp>90000){//95000/75000
      tmp=tmp*2.1111111;//1.7272727;//1.2666667;//1.1875;//2
      usleep((int)(tmp));
      printf("sleeping95 : %lu usec \n", tmp);}
    else if (tmp>80000){//85000/80000
      tmp=tmp*1.5178571;//1.8888889;//1.5454545;//1.0625;
      usleep((int)(tmp));
      printf("sleeping85 : %lu usec \n", tmp);}
    else if(tmp>70000){
      tmp=tmp*1.6666667;//1.3636364;//0.9375;
      usleep((int)tmp);
      printf("sleeping75 : %d usec \n", (tmp));}
    else if(tmp>60000){
      tmp=tmp*1.4444444;//1.1818182;//0.8125;
      usleep((int)tmp);
      printf("sleeping65 : %d usec \n", (tmp));}
    else if(tmp>50000){
      //tmp=tmp*0.687;
      usleep((int)tmp);
      printf("sleeping55 : %d usec \n", (tmp));}
    else if(tmp>40000){
      tmp=tmp*0.81818182;//0.5625;
      usleep((int)tmp);
      printf("sleeping45 : %d usec \n", (tmp));}
    else  if(tmp>30000){
      tmp=tmp*0.63636364;//0.4375;
      usleep((int)tmp);
      printf("sleeping35: %d usec \n", (tmp));}
    else if(tmp>20000){
      tmp=tmp*0.45454545;//0.3125;
      usleep((int)tmp);
      printf("sleeping25: %d usec \n",(tmp));}
    //printf("sleeping : %lu usec \n", (next_time - this_time));
    //usleep((int) (next_time - this_time));
  }
#ifdef GSM
#define GSMDOWNLINK_TIME 22.522523/4/* 1.2668919=(average=45000)/(output:35520) */ /* 1 (sec) : 44400 (freq) = 1000000 (usec) : x */
  next_time = this_time + output.size * GSMDOWNLINK_TIME;
#else
#define SAMPLE_TIME 125	/* usec / sample */
  next_time = this_time + output.size * SAMPLE_TIME;
#endif
#endif
#ifdef DATA_RATE
  /********** check data rate ****************/
  gettimeofday(&now,NULL);
  this_time = now.tv_sec*1000000 + now.tv_usec;
  unsigned long tot_data=0;
  /*******************************************/
#endif
  while (left > 0) {
    current = left;
    if (current > MAX_UDP)
       current = MAX_UDP;
    temp =sendto(sockfd, cp, current, 0,
		  (struct sockaddr *)&their_addr, sizeof(struct sockaddr));
#ifdef SLOWDOWN
#ifndef GSM
	usleep(200000);	// slow down output from source
#endif
#endif
    //printf("%s (work) : current %d, temp %d\n",name(),current,temp); 
    //jca YIELD();
    if (temp>0){  //ignore any errors mofo
      cp += temp;
#ifdef DATA_RATE
      tot_data +=temp;//for check data rate
#endif
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
#ifdef DATA_RATE
  /************** check data rate ****************/
  struct timeval then;
  gettimeofday(&then,NULL);
  next_time =then.tv_sec*1000000 + then.tv_usec;
  printf("***********************************\n");
  printf("sending data rate (kbit/sec): %10ld\n",(unsigned long)((tot_data*8)/(next_time-this_time)*1000));
  printf("%s (work) return : %lu(output.size)\n",name(),output.size); 
  /***********************************************/
#endif
#ifdef DEBUG
  printf("%s (work) : output SampleRange [%lld, %lu]\n",name(),output.index, output.size);
  printf("%s (work) return : %lu(output.size)\n",name(),output.size);  
#endif
  printf("%s (work) return : %lu(output.size), %lu(The NumofTime)\n",name(),output.size,++numofpacket);  
  return output.size;
}
#endif
