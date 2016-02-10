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

struct ub64 {
  u_int32_t hi;
  u_int32_t lo;
};

typedef struct ub64 ub64;
typedef ub64 tsc;

#define RDTSC(x) \
        asm volatile(".byte 0x0f;.byte 0x31" : "=a"((x).lo),"=d"((x).hi) )


#define CLOCK_CYCLES(x,y) \
        ((y).lo>(x).lo ? \
        (((y).hi-(x).hi)*(4294967296.)) + ((y).lo-(x).lo) : \
        (((y).hi-(x).hi-1)*(4294967296.)) + (4294967296.+(y).lo)-(x).lo)
