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

/* -*- Mode: c++ -*-
 *
 */

#ifndef _STRLGSMUPSOURCE_H_
#define _STRLGSMUPSOURCE_H_
#define __volatile__

#include <StrlSource.h>

#include <string.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/wait.h>
#include <arpa/inet.h>
#include <iostream.h>
#include <netinet/in.h>

#define MAX_UDP_SIZE	3000
template<class oType> 
class StrlGsmUPSource : public StrlSource<oType> {
protected:
  int sockfd;
  struct sockaddr_in my_addr;    /* my address information */
  struct sockaddr_in their_addr; /* connector's address information */
  virtual void initialize() { }
  unsigned char tempbuf[MAX_UDP_SIZE];
  int tempbuf_index, tempbuf_size;
public: 
  virtual const char *name() { return "StrlGsmUPSource"; }
  virtual int work(VrSampleRange output, void *o[]);
  StrlGsmUPSource(int);
  virtual ~StrlGsmUPSource() {}
};
    
template<class oType> int
StrlGsmUPSource<oType>::work(VrSampleRange output, void *ao[])
{
  oType **o= (oType **)ao;
  unsigned int addr_len = sizeof(struct sockaddr);
  int size = output.size * sizeof(oType);
  unsigned char *cp = (unsigned char *)o[0];
  int temp;
#ifdef DEBUG
  printf("%s (work) : output SampleRange [%lld, %lu]\n",name(),output.index, output.size);    
#endif
//  printf ("[%s] work %d\n", __FILE__, output.size);
  while (size > 0) {
   if (tempbuf_size > 0) {
      *cp++ = tempbuf[tempbuf_index++];
      tempbuf_size--;
      size--;
      continue;
   }
   if (size < MAX_UDP_SIZE) {
      tempbuf_index = 0;
      tempbuf_size = recvfrom(sockfd, tempbuf, sizeof(tempbuf), 0,
          (struct sockaddr *)&their_addr, &addr_len);
      continue;
   }
   temp = recvfrom(sockfd, cp, size, 0,
       (struct sockaddr *)&their_addr, &addr_len);
   if (temp > 0){
     printf ("received %d bytes from %s\n", temp, inet_ntoa(their_addr.sin_addr) );
     size -= temp;
     cp += temp;
   }
   else {
     printf ("[%s:%d] error in recvfrom %d\n", __FILE__, __LINE__, errno);
     break;
   }
  }
#ifdef DEBUG
  printf("%s (work) return: output.size %d\n",name(),(int)output.size); 
#endif
  return (int)output.size;
}

template<class oType> 
StrlGsmUPSource<oType>::StrlGsmUPSource(int port)
{
  tempbuf_index = 0;
  tempbuf_size = 0;
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }
  my_addr.sin_family = AF_INET;         /* host byte order */
  my_addr.sin_port
 = htons(
port
);     /* short, network byte order */
  my_addr.sin_addr.s_addr = INADDR_ANY; /* auto-fill with my IP */
  bzero(&(my_addr.sin_zero), 8);        /* zero the rest of the struct */

  if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))  == -1) {
    perror("bind");
    exit(1);
  }
}
#endif
