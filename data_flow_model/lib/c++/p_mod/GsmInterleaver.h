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

/* la methode work() traite a l'entree chaque iteration 456 char et produit
 * a la sortie 592 char (4*148).
 * chaque 20 ms:
 *               input 456 char ------> output 592 char .
 */  

#ifndef _VRGSMINTERLEAVER_H_
#define _VRGSMINTERLEAVER_H_
       

#include <stdlib.h>
#include <string.h>

#include <StrlSigProc.h>

class GsmInterleaver : public StrlSigProc {

 protected:
  //virtual VrSigProc *getUpstreamModuleN(port p);
  char b1[592], b2[592]; // 592 = [4][148]
  //int output_bits;
 public:
  
  GsmInterleaver();
  ~GsmInterleaver();
  virtual const char *name() { return "GsmInterleaver"; }
  virtual void initialize();
  //unsigned int mapSizeUp(int inputNumber, unsigned int size);
  virtual int forecast(VrSampleRange output, VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input, VrSampleRange* output);
  virtual int work(VrSampleRange output, void *o[],
                                     VrSampleRange inputs[], void *i[]);
  void Interleave(char *, char *, char *);
  //unsigned int mapSizeUp(int inputNumber , unsigned int size);
};


GsmInterleaver::GsmInterleaver():
           StrlSigProc(1, sizeof(char), sizeof(char))
{
  // Init here the 8 148-symbols bursts (b1, b2) with the training_sequence
  memset(b1, 0, 592);
  memset(b2, 0, 592);
}

GsmInterleaver::~GsmInterleaver() {
}

void
GsmInterleaver::initialize() {

}


int
GsmInterleaver::forecast(VrSampleRange output, VrSampleRange inputs[]) 
{
  
  inputs[0].index = (output.index/592)*456;//4*148 = 592
  inputs[0].size  = (output.size/592)*456;
#ifdef DEBUG
  printf("%s (forecast): (output) SRange[%lld, %lu] => upstream(input) SRange[%lld, %lu]\n",name(),output.index, output.size, inputs[0].index,inputs[0].size);
#endif
  return 0;
}

int
GsmInterleaver::downcast(VrSampleRange input, VrSampleRange* output) 
{
  /* no history */
  output->index=(input.index/456)*592;
  output->size=(input.size/456)*592; 
#ifdef DEBUG
  printf("%s (downcast): input [%lld, %lu] => output [%lld, %lu]\n",name(),input.index,input.size,output->index, output->size);
#endif
  return 0;
}

int
GsmInterleaver::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  char **i = (char **)ai;
  unsigned char **o = (unsigned char **)ao;
  unsigned int nb_frames;
  static int spin = 1;
   
  nb_frames = inputs[0].size/456 ;
 
  for (unsigned int k=0; k<nb_frames; k++) {
    //fprintf(stderr,"Iinput[%d]: ",k);
    //for(int j=0;j<456;j++)//for debug
    //fprintf(stderr,"%x ",*(i[0]+j));
    //fprintf(stderr,"\n");
    if(spin == 1) {
      Interleave(i[0]+k*456, b1, b2);
      memcpy(o[0]+k*592, b1, 592);
    } else {
      Interleave(i[0]+k*456, b2, b1);
      memcpy(o[0]+k*592, b2, 592);
    }
    spin *= -1;
    //fprintf(stderr,"Ioutput[%d]: ",k);
    //for(int w=0;w<592;w++)//for debug
    //fprintf(stderr,"%x ",*(o[0]+w));
    //fprintf(stderr,"\n\n\n");
  }
   
  return output.size;
}

void
GsmInterleaver::Interleave(char *symbols, char *b1, char *b2)
{
  register int i;
  register char *pt0, *pt1, *pt2, *pt3, *pt4, *pt5, *pt6, *pt7;
  register char *pt_in = symbols;
  
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
    *pt0 = *pt_in++; pt0 += 2;
    *pt1 = *pt_in++; pt1 += 2;
    *pt2 = *pt_in++; pt2 += 2;
    *pt3 = *pt_in++; pt3 += 2;
    *pt4 = *pt_in++; pt4 += 2;
    *pt5 = *pt_in++; pt5 += 2;
    *pt6 = *pt_in++; pt6 += 2;
    *pt7 = *pt_in++; pt7 += 2;
  }

/* Next 4 bits */
  *pt0 = *pt_in++; pt0 = &b1[89];  // [0][89]
  *pt1 = *pt_in++; pt1 = &b1[237]; // [1][89]
  *pt2 = *pt_in++; pt2 = &b1[385]; // [2][89]
  *pt3 = *pt_in++; pt3 = &b1[533]; // [3][89]
  pt4 = &b2[88];  // [0][88]
  pt5 = &b2[236]; // [1][88]
  pt6 = &b2[384]; // [2][88]
  pt7 = &b2[532]; // [3][88]
    
  /* Next 224 bits */
  for(i=0; i<28; i++) {
    *pt0 = *pt_in++; pt0 += 2;
    *pt1 = *pt_in++; pt1 += 2;
    *pt2 = *pt_in++; pt2 += 2;
    *pt3 = *pt_in++; pt3 += 2;
    *pt4 = *pt_in++; pt4 += 2;
    *pt5 = *pt_in++; pt5 += 2;
    *pt6 = *pt_in++; pt6 += 2;
    *pt7 = *pt_in++; pt7 += 2;
  }

  /* Last 4 bits */
  *pt4 = *pt_in++; 
  *pt5 = *pt_in++; 
  *pt6 = *pt_in++; 
  *pt7 = *pt_in++; 

  return;
}



#endif
