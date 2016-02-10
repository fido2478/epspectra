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

#ifndef _STRLPERFGRAPH_H_
#define _STRLPERFGRAPH_H_

#ifdef PERFMON
#include <StrlCycleCount.h>
#define  MAXGRAPHMODULES 50
class StrlSigProc;

class StrlPerfGraph {
private:

  StrlSigProc **modules;
  const char *labels[MAXGRAPHMODULES];
  int num_modules;
  char *title;
  float cpu_mhz;

public: 
  StrlPerfGraph() : num_modules(0), title("Performance Numbers"), cpu_mhz(0){};
  StrlPerfGraph(char *t) : num_modules(0), title(t) {};
  void setTitle(char *t) {title=t;}
  void add(const char *name, StrlSigProc *m);
  void outputGraph(double seconds);
  void print_stats();
  void globalSTARTcount();
  void globalSTOPcount();
  void AwaitTSTARTcount();
  void AwaitTSTOPcount();
  void InreaseNUMTick();
  void gnu_sample_modules(double seconds);
};

extern StrlCycleCount *overhead;

#endif /* PERFMON */

#endif  /* _STRLPERFGRAPH_H_ */
