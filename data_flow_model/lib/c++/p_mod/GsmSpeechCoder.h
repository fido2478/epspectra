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

#ifndef _VRGSMSPEECHCODER_H_
#define _VRGSMSPEECHCODER_H_
       

#include <StrlSigProc.h>

extern "C" {
#include <gsm.h>
}

class GsmSpeechCoder : public StrlSigProc {

 protected:
          
  unsigned char *buf_remain;// *******
  int len_remain;
  static unsigned short u2s[];

 public:

  int opt_fast;
  gsm r_coder;
  GsmSpeechCoder();
  ~GsmSpeechCoder();
  virtual void initialize();
  virtual const char *name() { return "GsmSpeechCoder"; }
  //unsigned int mapSizeUp(int inputNumber, unsigned int size);
  virtual int forecast (VrSampleRange output, VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input, VrSampleRange* output);
  virtual int work(VrSampleRange output, void *o[],
		   VrSampleRange inputs[], void *i[]);
  //gsm gsm_create(void);
  //void gsm_destroy(gsm );
  //int gsm_option(gsm , int , int*);
  //void gsm_encode(gsm , gsm_signal* , gsm_byte*);
  //void Gsm_Coder(struct gsm_state*, word*, word*, word*, word*, word*,word*,
  //	 word*);
  //void Gsm_Preprocess(struct gsm_state*, word*, word*);	 
};


extern "C" {
  gsm gsm_create();
  void gsm_destroy (struct gsm_state *);
  int gsm_option(gsm, int, int *);
  void gsm_encode (gsm, gsm_signal *, gsm_byte *);
}

//extern FILE	*in, *out;

unsigned short
GsmSpeechCoder::u2s[] = {
  33280, 34308, 35336, 36364, 37393, 38421, 39449, 40477,
  41505, 42534, 43562, 44590, 45618, 46647, 47675, 48703,
  49474, 49988, 50503, 51017, 51531, 52045, 52559, 53073,
  53587, 54101, 54616, 55130, 55644, 56158, 56672, 57186,
  57572, 57829, 58086, 58343, 58600, 58857, 59114, 59371,
  59628, 59885, 60142, 60399, 60656, 60913, 61171, 61428,
  61620, 61749, 61877, 62006, 62134, 62263, 62392, 62520,
  62649, 62777, 62906, 63034, 63163, 63291, 63420, 63548,
  63645, 63709, 63773, 63838, 63902, 63966, 64030, 64095,
  64159, 64223, 64287, 64352, 64416, 64480, 64544, 64609,
  64657, 64689, 64721, 64753, 64785, 64818, 64850, 64882,
  64914, 64946, 64978, 65010, 65042, 65075, 65107, 65139,
  65163, 65179, 65195, 65211, 65227, 65243, 65259, 65275,
  65291, 65308, 65324, 65340, 65356, 65372, 65388, 65404,
  65416, 65424, 65432, 65440, 65448, 65456, 65464, 65472,
  65480, 65488, 65496, 65504, 65512, 65520, 65528,     0,
  32256, 31228, 30200, 29172, 28143, 27115, 26087, 25059,
  24031, 23002, 21974, 20946, 19918, 18889, 17861, 16833,
  16062, 15548, 15033, 14519, 14005, 13491, 12977, 12463,
  11949, 11435, 10920, 10406,  9892,  9378,  8864,  8350,
  7964,  7707,  7450,  7193,  6936,  6679,  6422,  6165, 
  5908,  5651,  5394,  5137,  4880,  4623,  4365,  4108, 
  3916,  3787,  3659,  3530,  3402,  3273,  3144,  3016, 
  2887, 2759,  2630,  2502,  2373,  2245,  2116,  1988, 
  1891,  1827,  1763,  1698,  1634,  1570,  1506,  1441, 
  1377,  1313,  1249,  1184,  1120,  1056,   992,   927, 
  879,   847,   815,   783,   751,   718,   686,   654,
  622,   590,   558,   526,   494,   461,   429,   397,
  373,   357,   341,   325,   309,   293,   277,   261,
  245,   228,   212,   196,   180,   164,   148,   132,
  120,   112,   104,    96,    88,    80,    72,    64,
  56,    48,    40,    32,    24,    16,    8,      0
};

#define	U2S(x)	(u2s[  (unsigned  char)(x)       ])
#ifdef DEBUG
// debug ici 
void show(unsigned char t[33]); 
void show2(unsigned char t[160]) {
  int i;
  
  for(i=0; i<160; i++) {
    printf("%x, ", t[i]);
    if(i % 32 == 31)
      printf("\n");
  }
  printf("\n");
}
// fin debug
#endif
GsmSpeechCoder::GsmSpeechCoder():
                  StrlSigProc(1, sizeof(char), sizeof(char))
{
  buf_remain = new unsigned char[160];// ******
  len_remain = 0;

  // Init the Speech GSM Coder
  if(!(r_coder = gsm_create())) {
    perror("gsm_create");
  }
  (void)gsm_option(r_coder, GSM_OPT_FAST, &opt_fast);
}

GsmSpeechCoder::~GsmSpeechCoder() {
  delete buf_remain;
  gsm_destroy(r_coder);
}

void
GsmSpeechCoder::initialize() {
  
}

int
GsmSpeechCoder::forecast(VrSampleRange output, VrSampleRange inputs[]) 
{
  /* no history */
  inputs[0].index = (output.index/33)*160; // 160 ---> 33 (evry 20ms)
  inputs[0].size  = (output.size/33)*160;  
#ifdef DEBUG
  printf("%s (forecast): (output) SRange[%lld, %lu] => upstream(input) SRange[%lld, %lu]\n",name(),output.index, output.size, inputs[0].index,inputs[0].size);
#endif
  return 0;
}

int
GsmSpeechCoder::downcast(VrSampleRange input, VrSampleRange* output) 
{
  /* no history */
  output->index=(input.index/160)*33; // 33 ------> 456 (evry 20ms)
  output->size=(input.size/160)*33; 
#ifdef DEBUG
  printf("%s (downcast): input [%lld, %lu] => output [%lld, %lu]\n",name(),input.index,input.size,output->index, output->size);
#endif
  return 0;
}

int
GsmSpeechCoder::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  
  unsigned int len;
  unsigned int offset=0; 
  register unsigned int inc=33; // 260/8 + 1 (a la sortie)
  unsigned char *pt;//    ******
  gsm_signal buf[160]; // c'est "short int"
 
  unsigned  char **i = (unsigned char **)ai;
  unsigned  char **o = (unsigned char **)ao;

  unsigned int len_tot = inputs[0].size;
  //unsigned int nb_bursts = (len_tot + len_remain)/160;

  
  //printf("len_remain= %d\n", len_remain);

  if(len_remain != 0) {
    memcpy((void *)&buf_remain[len_remain],
	   (void *) i[0], 160-len_remain);
    // Encode a 20 ms u-law encoded speech into a 260-bit GSM frame.
    // (gsm_signal *) is (short int *)
    // (gsm_byte *) is (unsigned char *)
    {
      for(int k=0; k<160; k++)
	buf[k] = U2S(buf_remain[k]);
    }
    gsm_encode(r_coder, (gsm_signal *)buf, 
    	       (gsm_byte *)o[0]);
    len = len_tot - 160 + len_remain;
    offset += inc;
  } else {
    len = len_tot;
  }
  while(len >= 160) {
    pt = (unsigned char *)(i[0] + len_tot - len);// ********
    // debug ici
    //printf ("gsm_encode i[%d]:\n",inputs[0].index + len_tot - len);
    //show2(pt);
    // fin debug

    {
      for(int k=0; k<160; k++)
	buf[k] = U2S(*pt++);
#ifdef DEBUG
      // debug ici
      //printf ("inter1 buf[%d]:\n",inputs[0].index + len_tot - len);
      //      show2((unsigned char*)buf);
      // fin debug
#endif
    }
    gsm_encode(r_coder, (gsm_signal *)buf, (gsm_byte *)(o[0] + offset));
    // debug here 
    //printf ("gsm_encode o[%d]:\n",output.index + offset);show(o[0] + offset);
    offset += inc;
    len -= 160;
  }
  // Save in buf_remain the len samples.
  pt = (unsigned char *)(i[0] + len_tot - len);// ********
  memcpy((void *)buf_remain, (gsm_signal *)pt, len);
  len_remain = len;
  //printf("save %d remaining bytes\n", len);

 
  return output.size;
}


#endif
