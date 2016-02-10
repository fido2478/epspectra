/* Modified 2000, 2001 INRIA */

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

#ifndef _STRLFILESOURCE_H_
#define _STRLFILESOURCE_H_

//#include <rdtsc.h>
#include "StrlSource.h"
#include <fstream.h>

template<class oType>
class StrlFileSource : public StrlSource<oType> {
protected:
  FILE* fp;
  int repeat;
#ifdef _PERF
  struct timeval dt; 
  unsigned long long time1, time2;
  int first_iteration; //for performance
  //  tsc tsc1,tsc2;  //for performance
#endif
  virtual void initialize();
public:
  virtual const char *name() { return "StrlFileSource"; }
  virtual int work(VrSampleRange output, void *o[]);
  StrlFileSource(char* file, int repeat = 0);
  virtual ~StrlFileSource();
};

template<class oType> int
StrlFileSource<oType>::work(VrSampleRange output, void *ao[])
{
  oType **o= (oType **)ao;
  int i;
  int return_size;
  int size = output.size;
  int index;
#ifdef DEBUG
  printf("%s (work) : output SampleRange [%lld, %lu]\n",name(),output.index,output.size); 
#endif
#ifdef _PERF
  if (first_iteration){
    //    RDTSC(tsc1);
    gettimeofday(&dt,NULL);
    time1 = dt.tv_sec * 1000000 + dt.tv_usec;
    first_iteration=0;
  } 

  unsigned long long threshold=10000;
  if ((output.index+output.size)>threshold) {
    //    RDTSC(tsc2);
    gettimeofday(&dt,NULL);
    time2 = dt.tv_sec * 1000000 + dt.tv_usec;
    printf("sample data : %lld, %lld (dt)\n",output.index, (time2-time1));
    //    printf("%fcycles\n", CLOCK_CYCLES(tsc1,tsc2));
    exit(1);
  }
#endif

  if (feof(fp)) {
     cout <<"end of file, ctrl-C to exit"<<endl;
     while (1)
		;
     exit(0);
  }
#if 1
  index = 0;
#ifdef PERFMON
  if(sizeof(oType)!=sizeof(complex))
    for (i=0;i<size;i++)
      *o[0]++=(oType)random();
  else
    for (i=0;i<size;i++){
      *o[0]++=(0,1);}
  return_size = i / sizeof(oType);
  size -= return_size;
  index += return_size;
#else
  while(size) {
  	i = fread(&o[0][index],sizeof(oType),size,fp);
  	return_size = i / sizeof(oType);
	size -= return_size;
	index += return_size;
  	if (size <= 0  || (!repeat))
		break;
	if (fseek(fp, 0, SEEK_SET) == -1) {
		fprintf(stderr, "[%s] fseek failed\n", __FILE__);
		exit(-1);
	}
#ifdef COM_VAL
	printf("out %d ",i);
#endif
  }
#endif
#ifdef DEBUG
  printf("%s (work) return : %lu (output.size)\n",name(),output.size);
#endif
  return output.size;
#else
  while(1) {
  	i = fread(o[0],sizeof(oType),output.size,fp);
  	return_size = i / sizeof(oType);
  	if (return_size > 0 || (!repeat))
		break;
	if (fseek(fp, 0, SEEK_SET) == -1) {
		fprintf(stderr, "[%s] fseek failed\n", __FILE__);
		exit(-1);
	}
  }
#ifdef DEBUG
  printf("%s (work) return : %lu (output.size)\n",name(),output.size);
#endif
  return return_size;
#endif
}

template<class oType> void
StrlFileSource<oType>::initialize() {
#ifdef _PERF
  first_iteration=1; //for performance
#endif
  printf("%s has nothing to initialize.\n",name());
}

template<class oType>
StrlFileSource<oType>::StrlFileSource(char* filename, int arg_repeat = 0)
{
  repeat = arg_repeat;
  if((fp = fopen(filename,"r"))==NULL) {
    fprintf(stderr, "Could not open %s\n", filename);
    exit(1);
  }
}

template<class oType>
StrlFileSource<oType>::~StrlFileSource()
{
  fclose(fp);
}
#endif
