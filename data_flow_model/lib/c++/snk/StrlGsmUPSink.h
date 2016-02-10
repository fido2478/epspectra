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
 * modified FileSink
 */

#ifndef _STRLGSMUPSINK_H_
#define _STRLGSMUPSINK_H_

#include <StrlSink.h>
#include <fstream.h>
#include<string.h>

//StrlGsmUPSink appends raw data to a file.
//  default filename is "tmp"

template<class iType> 
class StrlGsmUPSink : public StrlSink<iType> {
protected:
  FILE* fp;
  char* filename;

public:
  virtual const char *name() { return "StrlGsmUPSink"; }
  virtual int work(VrSampleRange output, 
		   VrSampleRange inputs[], void *i[]);
  virtual void initialize() {
    if(fp != NULL) fclose(fp);
    if((fp=fopen(filename,"w")) < 0) {
      cout << "Error opening file, errno = " << errno << endl;
      exit(1);
    }
  }

  StrlGsmUPSink(char* file) {
    filename=new char[strlen(file)];
    strcpy(filename,file);
    fp = NULL;
    //fp = fopen(file,"w");    
  }

  StrlGsmUPSink() {
    filename="tmp.dat";
    fp = NULL;
  }

  //this doesn't take effect until module is re-initialize
  //  is this appropriate?
  void setFilename (char *file) {
    delete filename;
    filename=new char[strlen(filename)];
    strcpy(filename,file);
  }
  char *getFilename () {
    char *f=new char[strlen(filename)];
    return strcpy(f,filename);
  }

  virtual ~StrlGsmUPSink() {
    if(fp!=NULL) fclose(fp);
    delete filename;
  }

};

template<class iType> int
StrlGsmUPSink<iType>::work(VrSampleRange output, 
			VrSampleRange inputs[], void *ai[]) {
  iType **i = (iType **)ai;

  //  int total = 0;
  int count = 0;

  count =  fwrite(i[0],sizeof(iType),output.size,fp);
  while ((count < 0) && (errno == EAGAIN)) {
    YIELD();
    count =  fwrite(i[0],sizeof(iType),output.size,fp);
  }

  if(count<0) {
    fprintf(stderr, "StrlConnect.fileWrite(): error writing to file\n");
    exit(1);
  } else {
    if((unsigned int) count!=output.size)
      fprintf(stderr, "StrlConnect.fileWrite(): warning: not all bytes written\n");
    
  }
#ifdef DEBUG
  printf("%s (work) : output SampleRange [%lld, %lu]\n",name(),output.index, output.size);
  printf("%s (work) : write %lu times by as many as %d, and count %d\n",name(),output.size, sizeof(iType),count);  
#endif
  return count;

}

#endif















