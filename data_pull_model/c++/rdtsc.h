#ifndef _P_EVENTS_H_
#define _P_EVENTS_H_

struct ub64 {
  unsigned long hi;
  unsigned long lo;
};

typedef struct ub64 ub64;
typedef ub64 tsc;

#define RDTSC(x) \
        asm volatile(".byte 0x0f;.byte 0x31" : "=a"((x).lo),"=d"((x).hi) )


#define CLOCK_CYCLES(x,y) \
        ((y).lo>(x).lo ? \
        (((y).hi-(x).hi)*(4294967296.)) + ((y).lo-(x).lo) : \
        (((y).hi-(x).hi-1)*(4294967296.)) + (4294967296.+(y).lo)-(x).lo)

#endif _P_EVENTS_H_
