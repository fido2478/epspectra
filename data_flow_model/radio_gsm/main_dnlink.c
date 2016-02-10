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


#include <stdio.h>
#include <sys/time.h>
#include "GSM_DNLINK.h"
/***************************************
 * main() starts from here
 ***************************************/

main(int argc,char** argv){
  char *addr=(char *)malloc(sizeof(char[16]));
  if (argc < 2)
    strcpy(addr,"localhost");
  else
    strcpy(addr,argv[1]);
  DNLINK();
  DNLINK_I_IP_Addr(addr);
  DNLINK();
  DNLINK_I_InitRange("0 1600");
    while(1)
    DNLINK();
  /*free(addr);*/
}
