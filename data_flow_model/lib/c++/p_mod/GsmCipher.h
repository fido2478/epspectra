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

/* VrBits2Symbols.h pris comme origine */

/* Ce module fait le traitement de 592 bits: en GSM.
 *  il fait le traitement en composant le 592 char en 4 tranches de 148
 *  chacune et en appliquant a chaque tranche le CipherBurst() .
 *  alors 
 *        input 592 char -------> output 592 char  (chaque 20 ms)
 */ 

#ifndef _VRGSMCIPHER_H_
#define _VRGSMCIPHER_H_
       

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <StrlSigProc.h>


class GsmCipher : public StrlSigProc {
 public:
  char key[114];
  GsmCipher();
  ~GsmCipher();
  virtual const char *name() { return "GsmCipher"; }
  virtual void initialize();
  // virtual int forecast (VrSampleRange output, VrSampleRange inputs[]);
  virtual int work(VrSampleRange output, void *o[],
                                     VrSampleRange inputs[], void *i[]);
  void CipherBurst(char *, char *, char *);
  void InitKey(char *);
};
 

GsmCipher::GsmCipher():StrlSigProc(1, sizeof(char), sizeof(char))
{
  // output_bits = bits;
  InitKey(key);
}

GsmCipher::~GsmCipher() {
}

void
GsmCipher::initialize() {
  // InitKey(key);
}

int
GsmCipher::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
   char **i = (char **)ai;
   char **o = (char **)ao;
   int nb_bursts;
   
   
   nb_bursts = inputs[0].size/592;//4*148
   for (int j=0; j<nb_bursts; j++) {
     for(int k=0; k<4; k++)
       CipherBurst(i[0] + j*592 + k*148, o[0]+ j*592 + k*148, key);
   }
   return output.size;
}

void
GsmCipher::CipherBurst(char *in, char *out, char *key) {

  register int i;
  register char *pt_in, *pt_out;
  register char *pt_key = key;
 
  out[0] = in[0];
  out[1] = in[1];
  out[2] = in[2];
  pt_in  = &in[3];
  pt_out = &out[3];
  for(i=0; i<57; i++) {
    *pt_out++ = *pt_in++ ^ *pt_key++;
  }
  memcpy(&out[60], &in[60], 28);

  pt_in = &in[88];
  pt_out = &out[88];
  for(i=0; i<57; i++) {
    *pt_out++ = *pt_in++ ^ *pt_key++;
  }
  out[145] = in[145];
  out[146] = in[146];
  out[147] = in[147];

  return;
}

// Select a random key for now
void
GsmCipher::InitKey(char *key) {
  register int i;
  int seed=5555;
 
  srand(seed);
  for (i=0; i<114; i++)
    key[i] = rand() % 2; 
}

#endif
