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


/* for UDP_RX modules */
#include "../lib/include/datatype.h"
#include "../lib/strl/src/SOURCE.h"
#include "../lib/strl/i_mod/P_MOD.h"
#include "../lib/strl/snk/SINK.h"
#include "../lib/strl/submod/FIT_RANGE.h"
#include "../lib/strl/submod/COMP_DATA.h"
#include "../lib/strl/submod/GET_SAMPLE_RANGE.h"
#include "../lib/strl/submod/INITIALIZE_SINK.h"

int UDP_RX();
char* GET_UDPSOURCE(int);
char* GET_FILTER(int,int,float,float);
char* GET_NOISE();
char* GET_CXPLOTSINK();
float GET_SYMPERIODofFILTER();
void SET_SYMPERIOD(float);
void SET_SYMTIMING(float);
