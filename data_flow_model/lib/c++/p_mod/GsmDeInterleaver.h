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

#ifndef _VRGSMDEINTERLEAVER_H_
#define _VRGSMDEINTERLEAVER_H_
       

#include <stdlib.h>
#include <string.h>

#include <StrlSigProc.h>

class GsmDeInterleaver : public StrlSigProc {

 protected:

 public:
  
  GsmDeInterleaver();
  ~GsmDeInterleaver();
  virtual const char *name() { return "GsmDeInterleaver"; }
  virtual void initialize();
  //unsigned int mapSizeUp(int inputNumber, unsigned int size);
  virtual int forecast (VrSampleRange output, VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input, VrSampleRange* output);
  virtual int work(VrSampleRange output, void *o[],
                                     VrSampleRange inputs[], void *i[]);
  void DeInterleave(char *, char *, char *);
};

GsmDeInterleaver::GsmDeInterleaver():
           StrlSigProc(1, sizeof(char), sizeof(char)){
}

GsmDeInterleaver::~GsmDeInterleaver() {
}

void
GsmDeInterleaver::initialize() {

}

int
GsmDeInterleaver::forecast(VrSampleRange output, VrSampleRange inputs[]) 
{
  inputs[0].index = (output.index/456)*592;//592= 4*148;
  inputs[0].size  = (output.size/456)*592;
#ifdef DEBUG
  printf("%s (forecast): (output) SRange[%lld, %lu] => upstream(input) SRange[%lld, %lu]\n",name(),output.index, output.size, inputs[0].index,inputs[0].size);
#endif
  return 0;
}

int
GsmDeInterleaver::downcast(VrSampleRange input, VrSampleRange* output) 
{
  /* no history */
  output->index=(input.index/592)*456;
  output->size=(input.size/592)*456; 
#ifdef DEBUG
  printf("%s (downcast): input [%lld, %lu] => output [%lld, %lu]\n",name(),input.index,input.size,output->index, output->size);
#endif
  return 0;
}

int
GsmDeInterleaver::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
   char **i = (char **)ai;
   char **o = (char **)ao;
   unsigned int nb_frames;
   static char buf_mem[592];// 4*148
   static int first = 1;
   int offset_in = 0;
   int offset_out = 0;
   
   nb_frames = inputs[0].size/592;
   // Store the 4 first bursts received (de-interleaving needs 8 bursts)
   if(first) {
    memcpy(buf_mem, i[0], 592);
    offset_in = 592;
    nb_frames--;
    first = 0;
    }
 
  if(nb_frames) {
    //fprintf(stderr,"Dinput[0]: ");
    //for(int w=0;w<592;w++)//for debug
    //fprintf(stderr,"%x ",*(i[0]+w));
    //fprintf(stderr,"\n");
    //fprintf(stderr,"Doutput[0]: ");
     DeInterleave(buf_mem, i[0] + offset_in, o[0] + offset_out);
     //for(int j=0;j<456;j++)//for debug
     //fprintf(stderr,"%x ",*(o[0]+j));
     //fprintf(stderr,"\n");
    offset_out += 456;
    nb_frames--;

     if(nb_frames) {
      // For the remaining bursts (4 bursts = 20ms data)
      for(unsigned int j=0; j<nb_frames; j++) {
	//fprintf(stderr,"Dinput[%d]: ",j+1);
	//for(int w=0;w<592;w++)//for debug
	//fprintf(stderr,"%x ",*(i[0]+w)); 
	//fprintf(stderr,"\n");
	DeInterleave(i[0] +offset_in, i[0] + offset_in + 592, o[0] + offset_out);
	offset_in += 592;
	offset_out += 456;
	//fprintf(stderr,"Doutput[%d]: ",j+1);
	//for(int j=0;j<456;j++)//for debug
	//fprintf(stderr,"%x ",*(o[0]+j));
	//fprintf(stderr,"\n\n\n");
      }
      // Store the last 20 ms data
      memcpy(buf_mem, i[0] + offset_in, 592);
    } else {
      memcpy(buf_mem, i[0] + offset_in, 592);
    }
  }
  return output.size;
}

void
GsmDeInterleaver::DeInterleave(char *b1, char *b2, char *symbols)
{
  register int i;
  register char *pt0, *pt1, *pt2, *pt3, *pt4, *pt5, *pt6, *pt7;
  register char *pt_out = symbols;
  
  pt0 = &b1[3];   // [0][3]
  pt1 = &b1[151]; // [1][3]
  pt2 = &b1[299]; // [2][3]
  pt3 = &b1[447]; // [3][3]
  pt4 = &b2[4];   // [0][4]
  pt5 = &b2[152]; // [1][4]
  pt6 = &b2[300]; // [2][4]
  pt7 = &b2[448]; // [3][4]

 
  /* First 224 bits */
  for(i=0; i<28; i++) {
    *pt_out++ = *pt0; pt0 += 2;
    *pt_out++ = *pt1; pt1 += 2;
    *pt_out++ = *pt2; pt2 += 2;
    *pt_out++ = *pt3; pt3 += 2;
    *pt_out++ = *pt4; pt4 += 2;
    *pt_out++ = *pt5; pt5 += 2;
    *pt_out++ = *pt6; pt6 += 2;
    *pt_out++ = *pt7; pt7 += 2;
  }
  
  /* Next 4 bits */
  *pt_out++ = *pt0; pt0 = &b1[89];  // [0][89]
  *pt_out++ = *pt1; pt1 = &b1[237]; // [1][89]
  *pt_out++ = *pt2; pt2 = &b1[385]; // [2][89]
  *pt_out++ = *pt3; pt3 = &b1[533]; // [3][89]
  pt4 = &b2[88];  // [0][88]
  pt5 = &b2[236]; // [1][88]
  pt6 = &b2[384]; // [2][88]
  pt7 = &b2[532]; // [3][88]
 
  /* Next 224 bits */
  for(i=0; i<28; i++) {
    *pt_out++ = *pt0; pt0 += 2;
    *pt_out++ = *pt1; pt1 += 2;
    *pt_out++ = *pt2; pt2 += 2;
    *pt_out++ = *pt3; pt3 += 2;
    *pt_out++ = *pt4; pt4 += 2;
    *pt_out++ = *pt5; pt5 += 2;
    *pt_out++ = *pt6; pt6 += 2;
    *pt_out++ = *pt7; pt7 += 2;
  }
 
  /* Last 4 bits */
  *pt_out++ = *pt4;
  *pt_out++ = *pt5;
  *pt_out++ = *pt6;
  *pt_out++ = *pt7;
  /*
  {
    register int i;

    for(i=0; i<456; i++) {
      if(symbols[i])
	symbols[i] = 255;
    }
  }
  */
  return;
}


#endif
