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

#ifndef _GSMCHANNELCODER_H_
#define _GSMCHANNELCODER_H_
       

#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h> 
#include <StrlSigProc.h>

#define POLYA   0x19
#define POLYB   0x1b

class GsmChannelCoder : public StrlSigProc {

 protected:

  static unsigned char b2d_word[];
  static unsigned char b2d_shift[]; 
  static unsigned char Partab[];
  //int output_bits;

 public:
  
  GsmChannelCoder();
  ~GsmChannelCoder();
  virtual void initialize();
  virtual const char *name() { return "GsmChannelCoder"; }
  //unsigned int mapSizeUp(int inputNumber, unsigned int size);
  virtual int forecast (VrSampleRange output, VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input, VrSampleRange* output);
  virtual int work(VrSampleRange output, void *o[],
		   VrSampleRange inputs[], void *i[]);
  void reorder_b2d(unsigned char *, unsigned char *);
  void encode_symbols(unsigned short *, unsigned char *);
  int  find_edc(unsigned char *);
};

#ifdef DEBUG
// debug 
//void show(unsigned char t[33]) {
//int i;
  
//for(i=0; i<33; i++) {
//  printf("%x, ", t[i]);
//  if(i % 10 == 9)
//    printf("\n");
//}
//printf("\n");
//}
// /debug
#endif
unsigned char 
GsmChannelCoder::Partab[] = {
  0, 1, 1, 0, 1, 0, 0, 1, 
  1, 0, 0, 1, 0, 1, 1, 0, 
  1, 0, 0, 1, 0, 1, 1, 0, 
  0, 1, 1, 0, 1, 0, 0, 1, 
};

/* b2d_word[i] = (b2d[i] / 8)) */
unsigned char 
GsmChannelCoder::b2d_word[] = {
  0,   6,  13,  20,  27,   0,   1,   2, 
  0,   1,   1,   2,   5,  12,  19,  26, 
  6,  13,  20,  27,   1,   3,   3,   5, 
  12,  19,  26,   5,  12,  19,  26,   4, 
  11,  18,  25,   4,  11,  18,  25,   6, 
  13,  20,  27,   0,   2,   4,   4,  11, 
  18,  25,   3,   3,   5,  12,  19,  26, 
  4,  11,  18,  25,   5,  12,  19,  26, 
  0,   1,   1,   4,   2,   2,   3,   5, 
  12,  19,  26,   6,  13,  20,  27,   6, 
  7,   7,   8,   8,   8,   9,   9,   9, 
  10,  10,  11,  11,  13,  14,  14,  15, 
  15,  15,  16,  16,  16,  17,  17,  18, 
  18,  20,  21,  21,  22,  22,  22,  23, 
  23,  23,  24,  24,  25,  25,  27,  28, 
  28,  29,  29,  29,  30,  30,  30,  31, 
  31,  32,  32,   5,  12,  19,  26,   6, 
  13,  20,  27,   6,   7,   7,   7,   8, 
  8,   9,   9,   9,  10,  10,  10,  11, 
  13,  14,  14,  14,  15,  15,  16,  16, 
  16,  17,  17,  17,  18,  20,  21,  21, 
  21,  22,  22,  23,  23,  23,  24,  24, 
  24,  25,  27,  28,  28,  28,  29,  29, 
  30,  30,  30,  31,  31,  31,  32,   0, 
  0,   1,   3,   3,   4,   4,   1,   2, 
  2,   2,   5,  12,  19,  26,   6,   7, 
  7,   7,   8,   8,   8,   9,   9,  10, 
  10,  10,  11,  13,  14,  14,  14,  15, 
  15,  15,  16,  16,  17,  17,  17,  18, 
  20,  21,  21,  21,  22,  22,  22,  23, 
  23,  24,  24,  24,  25,  27,  28,  28, 
  28,  29,  29,  29,  30,  30,  31,  31, 
  31,  32,   0,   3, 
};



/* b2d_shift[i] = (7 - ( b2d[i] % 8)) */
unsigned char 
GsmChannelCoder::b2d_shift[] = {
  2,   3,   3,   3,   3,   3,   4,   7, 
  4,   5,   0,   2,   5,   5,   5,   5, 
  4,   4,   4,   4,   6,   6,   2,   6, 
  6,   6,   6,   7,   7,   7,   7,   0, 
  0,   0,   0,   1,   1,   1,   1,   5, 
  5,   5,   5,   5,   3,   7,   2,   2, 
  2,   2,   7,   3,   3,   3,   3,   3, 
  3,   3,   3,   3,   1,   1,   1,   1, 
  6,   7,   1,   4,   4,   0,   0,   4, 
  4,   4,   4,   6,   6,   6,   6,   0, 
  5,   2,   7,   4,   1,   6,   3,   0, 
  5,   2,   7,   4,   0,   5,   2,   7, 
  4,   1,   6,   3,   0,   5,   2,   7, 
  4,   0,   5,   2,   7,   4,   1,   6, 
  3,   0,   5,   2,   7,   4,   0,   5, 
  2,   7,   4,   1,   6,   3,   0,   5, 
  2,   7,   4,   2,   2,   2,   2,   7, 
  7,   7,   7,   1,   6,   3,   0,   5, 
  2,   7,   4,   1,   6,   3,   0,   5, 
  1,   6,   3,   0,   5,   2,   7,   4, 
  1,   6,   3,   0,   5,   1,   6,   3, 
  0,   5,   2,   7,   4,   1,   6,   3, 
  0,   5,   1,   6,   3,   0,   5,   2, 
  7,   4,   1,   6,   3,   0,   5,   7, 
  0,   2,   4,   1,   5,   6,   3,   5, 
  6,   1,   0,   0,   0,   0,   2,   7, 
  4,   1,   6,   3,   0,   5,   2,   7, 
  4,   1,   6,   2,   7,   4,   1,   6, 
  3,   0,   5,   2,   7,   4,   1,   6, 
  2,   7,   4,   1,   6,   3,   0,   5, 
  2,   7,   4,   1,   6,   2,   7,   4, 
  1,   6,   3,   0,   5,   2,   7,   4, 
  1,   6,   1,   5, 
};



GsmChannelCoder::GsmChannelCoder():
                         StrlSigProc(1, sizeof(char), sizeof(char)){

}

GsmChannelCoder::~GsmChannelCoder() {
}


int
GsmChannelCoder::forecast(VrSampleRange output, VrSampleRange inputs[]) 
{
  /* no history */
  inputs[0].index = (output.index/456)*33; // 33 ------> 456 (evry 20ms)
  inputs[0].size  = (output.size/456)*33;  
#ifdef DEBUG
  printf("%s (forecast): (output) SRange[%lld, %lu] => upstream(input) SRange[%lld, %lu]\n",name(),output.index, output.size, inputs[0].index,inputs[0].size);
#endif
  return 0;
}

int
GsmChannelCoder::downcast(VrSampleRange input, VrSampleRange* output) 
{
  /* no history */
  output->index=(input.index/33)*456; // 33 ------> 456 (evry 20ms)
  output->size=(input.size/33)*456; 
#ifdef DEBUG
  printf("%s (downcast): input [%lld, %lu] => output [%lld, %lu]\n",name(),input.index,input.size,output->index, output->size);
#endif
  return 0;
}


// input: 33 bytes = 264 bits (we need 260 bits) ----> output: 456 bytes 
int
GsmChannelCoder::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  unsigned  char **i = (unsigned char **)ai;
  unsigned  char **o = (unsigned char **)ao;
  unsigned char d_bits_coder[33];
  unsigned int nb_blocs;
   
  nb_blocs = inputs[0].size/33 ;
  //if (inputs[0].size % 33 !=0)
  //fprintf(stderr,
  //        "GsmChannelCoder::work'Unvalid length of data\n");
  for (unsigned int k=0; k<nb_blocs; k++) {
    
    // Reorder the 260-bit GSM frame according to priority-bits
    reorder_b2d(i[0]+k*33, d_bits_coder);
    // debug
#ifdef BEBUG
    printf("fChannelCoder:in(%d):\n", inputs[0].index + k*33); show(i[0]+k*33);
#endif
    // Encode a 260-bit GSM frame into 456 symbols
    // with convolutional and error detecting codes 
    encode_symbols((unsigned short *)d_bits_coder, o[0]+k*456);              
  }
  return output.size;
}

void
GsmChannelCoder::reorder_b2d(unsigned char *in, unsigned char *out)
{
  unsigned char *pt_out;
  register int i, j;
  register int cpt=0;

  pt_out = out;
  *pt_out = 0;
  in[32] &= 0xf0;// firas
  
  for(i=0; i<32; i++) {
    for(j=7; j>=0; j--) {
      *pt_out |= (((in[b2d_word[cpt]] >> b2d_shift[cpt]) & 0x01) << j);
      cpt ++;
    }
    *++pt_out = 0;
  }
  for(j=7; j>=4; j--) {
    *pt_out |= (((in[b2d_word[cpt]] >> b2d_shift[cpt]) & 0x01) << j);
    cpt ++;
  }
  return;
}


void
GsmChannelCoder::encode_symbols(unsigned short *data, unsigned char *symbols)
{

  register int i, j;
  unsigned char encstate=0;
  int bit, edc;
  int count=0;
  register unsigned short *pt_data=data;
  unsigned char *ptc_data;

  edc=find_edc((unsigned char *)data);

  {
    int k;
    for(k=0; k<17; k++)
      data[k] = htons(data[k]);
  }
  ptc_data = (unsigned char *)(data+16);
  *ptc_data &= 0xf0;
  


  /* 
   * 1. Convert the first 91 bits into convolutional symbols.
   *    u(k) = d(2k), k in [0, 90]
   */

  /* First 88 data bits (88) -> 176 symbols */
  /* u(0) -> u(87) -- c(0) -> c(175) */
  for(i=0; i<11; i++) {
    for(j=15; j>0; j-=2) {
      bit = ((*pt_data >> j) & 1);
      encstate = (encstate << 1) | bit;
      symbols[count++] = Partab[encstate & POLYA];
      symbols[count++] = Partab[encstate & POLYB];
    }
    pt_data++;
  }

  /* Next 3 data bits (88+3=91) -> 176 + 6 = 182 symbols */
  /* u(88) -> u(90) -- c(176) -> c(181) */
  bit = ((*pt_data >> 15) & 1);
  encstate = (encstate << 1) | bit;
  symbols[count++] = Partab[encstate & POLYA];
  symbols[count++] = Partab[encstate & POLYB];
  bit = ((*pt_data >> 13) & 1);
  encstate = (encstate << 1) | bit;
  symbols[count++] = Partab[encstate & POLYA];
  symbols[count++] = Partab[encstate & POLYB];
  bit = ((*pt_data >> 11) & 1);
  encstate = (encstate << 1) | bit;
  symbols[count++] = Partab[encstate & POLYA];
  symbols[count++] = Partab[encstate & POLYB];



  /*
   * 2. Append the 3 Parity bits and convert them 
   *    into 6 convolutional symbols. 
   *    (91+3=94)-> 182 + 6 = 188 symbols.
   */
  /* u(91)->u(93) -- c(182) -> c(187) */
  encstate = (encstate << 1) | ((edc >> 2) & 0x01);
  symbols[count++] = Partab[encstate & POLYA];
  symbols[count++] = Partab[encstate & POLYB];
  
  encstate = (encstate << 1) | ((edc >> 1) & 0x01);
  symbols[count++] = Partab[encstate & POLYA];
  symbols[count++] = Partab[encstate & POLYB];

  encstate = (encstate << 1) | (edc & 0x01);
  symbols[count++] = Partab[encstate & POLYA];
  symbols[count++] = Partab[encstate & POLYB];


  /* 
   * 2. Convert the next 91 bits into convolutional symbols.
   *    u(184-k) = d(2k+1), k in [0, 90]
   */

  pt_data = &data[11];

  /* First 3 bits (94+3=97)-> 188 + 6 = 194 symbols */
  /* u(94) -> u(96) -- c(188) -> c(193) */
  for(j=10; j<=14; j+=2) { 
    bit = ((*pt_data >> j) & 1);
    encstate = (encstate << 1) | bit;
    symbols[count++] = Partab[encstate & POLYA];
    symbols[count++] = Partab[encstate & POLYB];
  }
  pt_data--;

  /* Next 88 bits (97+88=185) -> 194 + 176 = 370 symbols */
  /* u(97) -> u(184) -- c(194) -> c(369) */
  for(i=0; i<11; i++) { 
    for(j=0; j<=14; j+=2) {
      bit = ((*pt_data >> j) & 1);
      encstate = (encstate << 1) | bit;
      symbols[count++] = Partab[encstate & POLYA];
      symbols[count++] = Partab[encstate & POLYB];
    }
    pt_data--;
  }

  
  /* 
   * 3. Add 4 tail (null) bits (185+4=189) -> 370 + 8 = 378 symbols 
   */
  /* u(185) -> u(188) -- c(370) -> c(377) */
  for(i=0; i<4; i++) {
    encstate = encstate << 1;
    symbols[count++] = Partab[encstate & POLYA];
    symbols[count++] = Partab[encstate & POLYB];
  }
  
  /*
   * 4. Add the 78 unprotected bits (Type II).
   */
  
  pt_data = &data[11];
  
  /* First 10 bits -> 378 + 10 = 388 symbols */
  /* d(182) -> d(191) -- c(378) -> c(387) */
  for(j=9; j>=0; j--) {
    symbols[count++] = ((*pt_data >> j) & 1);
  }
  pt_data++;
  /* Next 64 bits  -> 388 + 64 = 452 symbols */
  /* d(192) -> d(255) -- c(388) -> c(451) */
  for(i=12; i<16; i++){  
    for(j=15; j>=0; j--) {
      symbols[count++] = ((*pt_data >> j) & 1);
    }
    pt_data++;
  }
  /* Last 4 bits -> 452 + 4 = 456 symbols */
  /* d(256) -> d(259) -- c(452) -> c(455) */
  for(j=15; j>=12; j--) {
    symbols[count++] = ((*pt_data >> j) & 1);
  }
  return;
}
   

int
GsmChannelCoder::find_edc(unsigned char *data)
{
  
  register int i, j;
  int P0, P1, P2, Q;
  int edc;
  
  P0 = P1 = P2 = Q = 0;

  /* First 48 data bits */
  for(i=0; i<6; i++) {
    for(j=7; j>=0; j--) {
      P2 = P1;
      P1 = Q ^ P0;
      P0 = Q ^ ((*data >> j) & 1);
      Q = P2;
    }
    data ++;
  }
  /* 2 last data bits */
  P2 = P1;
  P1 = Q ^ P0;
  P0 = Q ^ ((*data >> 7) & 1);
  /* Q = P2; */
  edc = ((P2 ^ ((*data >> 6) & 1)) << 2); /* P0 */
  edc |= ((P2 ^ P0) << 1); /* P1 */
  edc |= P1; /* P2 */
  return (edc);
}

void
GsmChannelCoder::initialize() {
  
}


#endif
