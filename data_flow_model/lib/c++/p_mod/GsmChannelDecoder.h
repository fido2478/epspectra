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

#ifndef _VRGSMCHANNELDECODER_H_
#define _VRGSCHANNELDECODER_H_
       

#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <StrlSigProc.h>

#define	POLYA	0x19
#define	POLYB	0x1b

#define K        5 /* 1 + G(D) degree */
#define K1       4 /* K - 1 */
#define K2       3 /* K - 2 */
#define MAXN    16 /* 2^(K - 1) */
#define MAXN2    8 /* 2^(K - 2) */

class GsmChannelDecoder : public StrlSigProc {

 protected:

  static unsigned char d2b_word[];
  static unsigned char d2b_shift[]; 
  static int mettab[2][256];
  //int output_bits;

 public:
  
  GsmChannelDecoder();
  ~GsmChannelDecoder();
  virtual void initialize();
  virtual const char *name() { return "GsmChannelDecoder"; }
  //unsigned int mapSizeUp(int inputNumber, unsigned int size);
  virtual int forecast (VrSampleRange output, VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input, VrSampleRange* output);
  virtual int work(VrSampleRange output, void *o[],
		   VrSampleRange inputs[], void *i[]);
  void reorder_d2b(unsigned char *, unsigned char *);
  virtual int viterbi(unsigned long *, unsigned char *, unsigned char *,
		      unsigned int ,int (*)[256]);
  void decode_symbols(unsigned char *, unsigned short *);
  int  find_edc(unsigned char *);
};

#ifdef DEBUG
// debug 
//void show(unsigned char t[33]);
// /debug
#endif

struct state {
  unsigned long path;	/* Decoded path to this state */
  long metric;		/* Cumulative metric to this state */
};

GsmChannelDecoder::GsmChannelDecoder():
  StrlSigProc(1, sizeof(char), sizeof(char)){

}

GsmChannelDecoder::~GsmChannelDecoder() {
}

int
GsmChannelDecoder::forecast(VrSampleRange output, VrSampleRange inputs[]) 
{
  /* no history */
  inputs[0].index = (output.index/33)*456; // 456 -------> 33 (evry 20ms)
  inputs[0].size  = (output.size/33)*456; 
#ifdef DEBUG
  printf("%s (forecast): (output) SRange[%lld, %lu] => upstream(input) SRange[%lld, %lu]\n",name(),output.index, output.size, inputs[0].index,inputs[0].size);
#endif
  return 0;
}

int
GsmChannelDecoder::downcast(VrSampleRange input, VrSampleRange* output) 
{
  /* no history */
  output->index=(input.index/456)*33; // 456 ------> 33 (evry 20ms)
  output->size=(input.size/456)*33; 
#ifdef DEBUG
  printf("%s (downcast): input [%lld, %lu] => output [%lld, %lu]\n",name(),input.index,input.size,output->index, output->size);
#endif
  return 0;
}

int
GsmChannelDecoder::work(VrSampleRange output, void *ao[],
			  VrSampleRange inputs[], void *ai[])
{
  unsigned  char **i = (unsigned char **)ai;
  unsigned  char **o = (unsigned char **)ao;
  unsigned char d_bits_decoder[33];
  unsigned int nb_blocs;
   
  nb_blocs = inputs[0].size/456;
  //if (inputs[0].size % 456 !=0)
  //fprintf(stderr,
  //        "GsmChannelDecoder::work'Unvalid length of data\n");
  for (unsigned int k=0; k<nb_blocs; k++) {
    // Decode symbols[] into 260-bit GSM frame
    decode_symbols((unsigned char *)(i[0] + k*456),
		   (unsigned short *)d_bits_decoder);
    // Retrieve the b bits from the d bits
    reorder_d2b(d_bits_decoder, o[0] + k*33);
#ifdef DEBUG
    // debug
    //printf("fChannelDeCoder:out(%d):\n", output.index +k*33);show(o[0]+k*33);       
#endif
  }
  return output.size;
}

void
GsmChannelDecoder::reorder_d2b(unsigned char *in, unsigned char *out)
{
  unsigned char *pt_out;
  register int i, j;
  register int cpt=0;

  pt_out = out;
  *pt_out = 0;

  for(i=0; i<32; i++) {
    for(j=7; j>=0; j--) {
      *pt_out |= (((in[d2b_word[cpt]] >> d2b_shift[cpt]) & 0x01) << j);
      cpt ++;
    }
    *++pt_out = 0;
  }
  for(j=7; j>=4; j--) {
    *pt_out |= (((in[d2b_word[cpt]] >> d2b_shift[cpt]) & 0x01) << j);
    cpt ++;
  }
  return;
}

void
GsmChannelDecoder::decode_symbols(unsigned char *symbols, unsigned short *outdata)
{
#define THRES(x) ((x) > 127 ? 1 : 0)
#define GET_BIT(data, bit) (((data)[(bit) / 8] >> (7 - ((bit) % 8))) & 0x01)
  int nbits=192; /* 185 valids + 7 null bits (189 is a pb with viterbi.c) */
  unsigned long metric;
  int edc=0, dec_edc;
  register int i, j, k;
  int count, cpt;
  unsigned char decdata[33];
  unsigned short d_short;
  unsigned char u_byte;

  {
    register int i;
    
    for(i=0; i<456; i++) {
      if((unsigned char)symbols[i])
	symbols[i] = 255;
    }
  }

  viterbi(&metric, decdata, symbols, nbits, mettab);

  /* Retrieve the d bits from the output of the Viterbi 
   * Convolutional decoder.
   */
  
  /* First even bits from d(0->180) corresponding to u(0->90) */
  /* u(0->87) */
  for(i=0; i<11; i++) {
    d_short = 0;
    u_byte = decdata[i];
    for(j=0,k=1; j<8; j++, k+=2) {
      d_short |= (((u_byte >> j) & 0x01) << k);
    }
    outdata[i] = d_short;
  }
  /* u(88->90) */
  d_short = 0;
  u_byte = decdata[i];
  for(j=7,k=15; j>=5; j--, k-=2) {
    d_short |= (((u_byte >> j) & 0x01) << k);
  }
  outdata[11] = d_short;
  
  /* u(91->93) = P0, P1, P2 -- Error Detecting Code */
  for(j=4; j>=2; j--) {
    edc |= (((u_byte >> j) & 0x01) << (j-2));
  }
  
  /* Then, odd bits from d(1->181) corresponding to u(94->184) */
  
  /* u(97->184) */
  cpt = 184;
  for(i=0; i<11; i++) {
    d_short = 0;
    for(k=14; k>=0; k-=2, cpt--) {
      d_short |= (GET_BIT(decdata, cpt) << k);
    }
    outdata[i] |= d_short;
  }
  /* u(94->96) */
  cpt=96;
  d_short=0;
  for(k=14; k>=10; k-=2, cpt--) {
    d_short |= (GET_BIT(decdata, cpt) << k);
  }
  outdata[11] |= d_short;
  
  /* Process the local error detecting code from the re-ordered input d */
  dec_edc = find_edc((unsigned char *)outdata);
  /*
    if(dec_edc ^ edc)
    printf("error ! orig= %d, decoded = %d\n", edc, dec_edc);
  */
  
  /* symbols[378->455] contains the 78 unprotected Type II bits */
  
  /* symbols[378->387] */
  count = 378;
  d_short = 0;
  for(i=9; i>=0; i--) { /* 10 bits -> 10 symbols */
    d_short |= (THRES(symbols[count]) << i);
    count ++;
  }
  outdata[11] |= d_short;
  
  /* symbols[388->451] */
  for(i=12; i<16; i++) { /* 64 bits -> 64 symbols */
    d_short = 0;
    for(j=15; j>=0; j--) { 
      d_short |= (THRES(symbols[count]) << j);
      /*  printf("c:%d, THRES(symbols[count]):0x%x d_short: 0x%x\n",count, THRES(symbols[count]), d_short); */
      count ++;
    }
    outdata[i] = d_short;
  }

  /* symbols[452->455] */
  d_short = 0;
  for(j=15; j>=12; j--) { /* 4 bits -> 4 symbols */
    d_short |= (THRES(symbols[count]) << j);
    count ++;
  }
  outdata[16] = d_short;

  {
    int k;
    for(k=0; k<17; k++)
      outdata[k] = htons(outdata[k]);
  }

  return;
}

#define	BUTTERFLY(i,sym) { \
	/* ACS for 0 branch */\
	m0 = state[i].metric + mets[sym];	        /* 2*i */\
	m1 = state[i+MAXN2].metric + mets[3^sym];	/* 2*i + MAXN */\
	if(m0 > m1){\
		next[2*i].metric = m0;\
		next[2*i].path = state[i].path << 1;\
	} else {\
		next[2*i].metric = m1;\
		next[2*i].path = (state[i+MAXN2].path << 1)|1;\
	}\
	/* ACS for 1 branch */\
	m0 -= mets[sym] - mets[3^sym];	/* 2*i + 1 */\
	m1 += mets[sym] - mets[3^sym];	/* 2*i + MAXN + 1 */\
	if(m0 > m1){\
		next[2*i+1].metric = m0;\
		next[2*i+1].path = state[i].path << 1;\
	} else {\
		next[2*i+1].metric = m1;\
		next[2*i+1].path = (state[i+MAXN2].path << 1)|1;\
	}\
}


int
GsmChannelDecoder::viterbi(
			     unsigned long *metric,	/* Final path metric (returned value) */
			     unsigned char *data,	/* Decoded output data */
			     unsigned char *symbols,	/* Raw deinterleaved input symbols */
			     unsigned int nbits,	/* Number of output bits */
			     int mettab[2][256]	/* Metric table, [sent sym][rx symbol] */
			     ){
  unsigned int bitcnt = 0;
  int mets[4];
  long bestmetric;
  int beststate,i;
  struct state state0[MAXN],state1[MAXN],*state,*next;
  int m0,m1;

  state = state0;
  next = state1;

  /* Initialize starting metrics to prefer 0 state */
  state[0].metric = 0;
  for(i=1; i<MAXN; i++)
    state[i].metric = -999999;
  state[0].path = 0;
  
  for(bitcnt = 0; bitcnt < nbits; bitcnt++){
    /* Read input symbol pair and compute all possible branch
     * metrics
     */
    mets[0] = mettab[0][symbols[0]] + mettab[0][symbols[1]];
    mets[3] = mettab[1][symbols[0]] + mettab[1][symbols[1]];
    
    /* These macro calls were generated by genbut.c
     * and rearranged by hand for speed
     */
    
    BUTTERFLY(0,0);
    BUTTERFLY(2,0);
    BUTTERFLY(4,3);
    BUTTERFLY(6,3);
    
    mets[1] = mettab[0][symbols[0]] + mettab[1][symbols[1]];
    mets[2] = mettab[1][symbols[0]] + mettab[0][symbols[1]];
    symbols += 2;

    BUTTERFLY(1,1);
    BUTTERFLY(3,1);
    BUTTERFLY(5,2);
    BUTTERFLY(7,2);
    
    /* Swap current and next states */
    if(bitcnt & 1){
      state = state0;
      next = state1;
    } else {
      state = state1;
      next = state0;
    }
    if(bitcnt > nbits-7){
      /* In tail, poison non-zero nodes */
      for(i=1;i<MAXN;i += 2)
	state[i].metric = -9999999;
    }
    /* Produce output every 8 bits once path memory is full */
    if((bitcnt % 8) == K2 && bitcnt > 32){
      /* Find current best path */
      bestmetric = state[0].metric;
      beststate = 0;
      for(i=1;i<MAXN;i++){
	if(state[i].metric > bestmetric){
	  bestmetric = state[i].metric;
	  beststate = i;
	}
      }
#ifdef	notdef
      printf("metrics[%d] = %d state = %lx\n",beststate,
	     state[beststate].metric,state[beststate].path);
#endif
      *data++ = state[beststate].path >> 24;
    }
    
  }
  /* Output remaining bits from 0 state */
  if((i = bitcnt % 8) != K1)
    state[0].path <<= K1-i;
  
  *data++ = state[0].path >> 24;
  *data++ = state[0].path >> 16;
  *data++ = state[0].path >> 8;
  *data = state[0].path;
  
  *metric = state[0].metric;
  return 0;
}



/* find_edc(): retrieve the 3-bit Error Detecting Code from the
 *             50-bit input data.
 *             (EDC = remainder of P(X) divided by G(X)
 *             with P(X) = 50-bit input data coefficients
 *                  G(X) = X^3 + X + 1 
 */
int
GsmChannelDecoder::find_edc(unsigned char *data)
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

/* d2b_word[i] = (d2b[i] / 8)) */
unsigned char
GsmChannelDecoder::d2b_word[] = {
  23,   8,   5,   1,   0,   0,  32,  24, 
  8,   2,   1,   0,  24,  24,   8,   1, 
  0,  25,  24,   8,   5,   1,  25,   8, 
  6,   2,  32,  24,   6,   2,  24,   8, 
  5,  24,  24,   8,   7,   5,   4,   3, 
  3,   2,   1,   8,   6,  16,   7,  25, 
  16,   9,   4,   2,   0,  25,  17,   9, 
  25,  17,  10,  26,  17,  10,  26,  17, 
  10,  26,  17,  10,  26,  18,  10,  26, 
  18,  10,  26,  18,  10,  26,  18,  10, 
  26,  18,  11,  27,  18,  11,  27,  18, 
  11,  27,  18,  11,   7,   5,   4,   4, 
  3,   3,   1,   9,   6,  16,   7,  25, 
  17,   9,   5,   2,   0,  27,  19,  11, 
  27,  19,  11,  27,  19,  11,  27,  19, 
  11,  27,  19,  12,  28,  19,  12,  28, 
  19,  12,  28,  19,  12,  28,  20,  12, 
  28,  20,  12,  28,  20,  12,  28,  20, 
  12,  28,  20,  13,   7,   6,   4,   4, 
  3,   3,   1,   9,   6,  16,   7,  25, 
  17,   9,   5,   2,   0,  29,  20,  13, 
  29,  20,  13,  29,  20,  13,  29,  21, 
  13,  29,  21,  13,  29,  21,  13,  29, 
  21,  13,  29,  21,  14,  30,  21,  14, 
  30,  21,  14,  30,  21,  14,  30,  22, 
  14,  30,  22,  14,   7,   6,   4,   4, 
  3,   3,   1,   9,   6,  16,   7,  25, 
  17,   9,   5,   2,   0,  30,  22,  14, 
  30,  22,  14,  30,  22,  15,  31,  22, 
  15,  31,  22,  15,  31,  22,  15,  31, 
  23,  15,  31,  23,  15,  31,  23,  15, 
  31,  23,  15,  31,  23,  16,  32,  23, 
  16,  32,  23,  16, 
};
 


/* d2b_shift[i] = (7 - ( d2b[i] % 8)) */
unsigned char
GsmChannelDecoder::d2b_shift[] = {
  0,   7,   4,   7,   2,   7,   5,   7, 
  6,   3,   6,   1,   1,   6,   5,   5, 
  0,   7,   0,   3,   3,   4,   6,   2, 
  5,   2,   4,   5,   4,   1,   4,   1, 
  2,   2,   3,   4,   7,   1,   4,   0, 
  4,   0,   3,   0,   3,   4,   3,   5, 
  0,   4,   0,   7,   6,   1,   4,   0, 
  0,   3,   7,   7,   2,   6,   6,   1, 
  5,   5,   0,   4,   4,   7,   3,   3, 
  6,   2,   2,   5,   1,   1,   4,   0, 
  0,   3,   7,   7,   2,   6,   6,   1, 
  5,   5,   0,   4,   6,   0,   3,   7, 
  3,   7,   2,   7,   2,   3,   2,   4, 
  7,   3,   7,   6,   5,   4,   7,   3, 
  3,   6,   2,   2,   5,   1,   1,   4, 
  0,   0,   3,   7,   7,   2,   6,   6, 
  1,   5,   5,   0,   4,   4,   7,   3, 
  3,   6,   2,   2,   5,   1,   1,   4, 
  0,   0,   3,   7,   5,   7,   2,   6, 
  2,   6,   1,   6,   1,   2,   1,   3, 
  6,   2,   6,   5,   4,   7,   2,   6, 
  6,   1,   5,   5,   0,   4,   4,   7, 
  3,   3,   6,   2,   2,   5,   1,   1, 
  4,   0,   0,   3,   7,   7,   2,   6, 
  6,   1,   5,   5,   0,   4,   4,   7, 
  3,   3,   6,   2,   4,   6,   1,   5, 
  1,   5,   0,   5,   0,   1,   0,   2, 
  5,   1,   5,   4,   3,   2,   5,   1, 
  1,   4,   0,   0,   3,   7,   7,   2, 
  6,   6,   1,   5,   5,   0,   4,   4, 
  7,   3,   3,   6,   2,   2,   5,   1, 
  1,   4,   0,   0,   3,   7,   7,   2, 
  6,   6,   1,   5, 
};

int
GsmChannelDecoder::mettab[2][256] = {
  {  4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    4, 
     4,    4,    4,    4,    4,    4,    4,    3, 
     3,    3,    3,    3,    2,    2,    1,    1, 
     0,   -1,   -2,   -3,   -4,   -5,   -6,   -7, 
     -8,  -10,  -11,  -12,  -14,  -15,  -17,  -18, 
     -19,  -21,  -22,  -24,  -25,  -27,  -28,  -29, 
     -31,  -32,  -34,  -35,  -37,  -38,  -40,  -41, 
     -42,  -44,  -45,  -47,  -48,  -50,  -51,  -53, 
     -54,  -56,  -57,  -58,  -60,  -61,  -63,  -64, 
     -66,  -67,  -69,  -70,  -72,  -73,  -74,  -76, 
     -77,  -79,  -80,  -82,  -83,  -85,  -86,  -88, 
     -89,  -90,  -92,  -93,  -95,  -96,  -98,  -99, 
     -101, -102, -104, -105, -106, -108, -109, -111, 
     -112, -114, -115, -117, -118, -119, -121, -122, 
     -124, -125, -127, -128, -130, -131, -133, -134, 
     -135, -137, -138, -140, -141, -143, -144, -146, 
     -147, -149, -150, -151, -153, -154, -156, -157, 
     -159, -160, -161, -163, -164, -166, -167, -169, 
     -171, -173, -172, -175, -177, -177, -177, -190, 
  },
  { -191, -181, -179, -177, -176, -175, -173, -172, 
    -170, -169, -167, -166, -165, -163, -162, -160, 
    -159, -157, -156, -154, -153, -151, -150, -149, 
    -147, -146, -144, -143, -141, -140, -138, -137, 
    -135, -134, -133, -131, -130, -128, -127, -125, 
    -124, -122, -121, -119, -118, -117, -115, -114, 
    -112, -111, -109, -108, -106, -105, -104, -102, 
    -101,  -99,  -98,  -96,  -95,  -93,  -92,  -90, 
    -89,  -88,  -86,  -85,  -83,  -82,  -80,  -79, 
    -77,  -76,  -74,  -73,  -72,  -70,  -69,  -67, 
    -66,  -64,  -63,  -61,  -60,  -58,  -57,  -56, 
    -54,  -53,  -51,  -50,  -48,  -47,  -45,  -44, 
    -42,  -41,  -40,  -38,  -37,  -35,  -34,  -32, 
    -31,  -29,  -28,  -27,  -25,  -24,  -22,  -21, 
    -19,  -18,  -17,  -15,  -14,  -12,  -11,  -10, 
    -8,   -7,   -6,   -5,   -4,   -3,   -2,   -1, 
    0,    1,    1,    2,    2,    3,    3,    3, 
    3,    3,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4, 
    4,    4,    4,    4,    4,    4,    4,    4 
  }
};




void
GsmChannelDecoder::initialize() {

}


#endif
