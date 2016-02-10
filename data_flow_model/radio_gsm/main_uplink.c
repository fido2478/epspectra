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
#include "GSM_UPLINK.h"

/***************************************
 * main() starts from here
 ***************************************/

#include <sys/time.h>

main(int argc,char** argv){
  UPLINK();
  UPLINK_I_InitRange("0 35520");
  while(1)
    UPLINK();
}
