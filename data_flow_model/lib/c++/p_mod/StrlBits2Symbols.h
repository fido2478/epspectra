/* Modified 2000, 2001 INRIA */

/* -*- Mode: c++ -*-  */


#ifndef _STRLBITS2SYMBOLS_H_
#define _STRLBITS2SYMBOLS_H_

#include <StrlSigProc.h>


class StrlBits2Symbols : public StrlSigProc {
protected:
  int valid_bits, output_bits;
  u_char current_data;
public:
  virtual const char *name() {return "StrlBits2Symbols";} //Hahnsang added
  virtual void initialize();
  virtual int forecast(VrSampleRange output,VrSampleRange inputs[]);
  virtual int downcast(VrSampleRange input, VrSampleRange* output);
  StrlBits2Symbols(int);
  virtual void setOutputBits(int b){ output_bits = b; current_data = 0x0; valid_bits =0;};
                                       // bug here -> doesn't deal with state properly
  virtual int work(VrSampleRange output, void *o[], VrSampleRange inputs[], void *i[]);
};

int StrlBits2Symbols::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  char **i = (char **)ai;
  char **o = (char **)ao;
  int size = output.size, bits_done;
  u_char out;
#ifdef DEBUG
  printf("%s (work) : output SRange [%lld, %lu]\n",name(),output.index,output.size);
#endif
  while(size-- > 0) {


    bits_done = 0;
    out = 0x00;

    while (bits_done < output_bits){
    
      if (valid_bits == 0) {
      
	current_data = *i[0]++;
#ifdef COMP_VAL
	printf("in %x ", current_data);
#endif
	valid_bits = 8;
      }
    
      out = (out<<1) + (current_data>>7);  /* msb from current_data becomes lsb of output */
      current_data = current_data << 1;
      valid_bits--;
      bits_done++;    
    }
#ifdef COMP_VAL
    printf("out %x ", out);
#endif
    //if (out > 16) printf("***** Bad result here: size = %d\n", size);
    *o[0]++ = out;
  //printf("%s (work) : size %d, out %x\n",name(),size,out); 
  }
#ifdef DEBUG
  printf("%s (work) return : %lu (output.size)\n",name(),output.size); 
#endif
  return output.size;
}

int StrlBits2Symbols::forecast(VrSampleRange output,VrSampleRange inputs[])
{
  for(unsigned int i=0;i<numberInputs;i++) {
    inputs[i].index=output.index/2;
    inputs[i].size=output.size/2;
  }
  return 0;
}  
int StrlBits2Symbols::downcast(VrSampleRange input, VrSampleRange* output) {
  /* 1:1 ratio with no history */
  output->index=input.index*2; /* ! do not subtract history ! */
  output->size=input.size*2; /* + history */
#ifdef DEBUG
  printf("%s (downcast): input [%lld, %lu] => output [%lld, %lu]\n",name(),input.index,input.size,output->index, output->size);
#endif
  return 0;
}  
void StrlBits2Symbols::initialize()
{
  valid_bits = 0;
  //cout<<"In the "<<name()<<" initialize valid_bits as "<<valid_bits<<endl;
  printf("%s initialize valid_bits as %d.\n",name(),valid_bits);
}


StrlBits2Symbols::StrlBits2Symbols(int bits)
  : StrlSigProc(1, sizeof(char), sizeof(char))
{
  output_bits = bits;
}


#endif
