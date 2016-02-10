/*  Modified 2000, 2001 INRIA */
/* -*- Mode: c++ -*- 
 *
 *
 *     Digital Modulator: QAM, PAM, BPSK 
 */


#ifndef _STRLDIGMOD_H_
#define _STRLDIGMOD_H_

#include "StrlInterpolatingSigProc.h"

#define TAP_RANGE            1024.0 //  = 2^TAP_RANGE_EXP 
#define TAP_RANGE_EXP          10
#define SYMBOL_FOR_ONE          1
#define MAX_SYMBOLS        100000
#define LOG_SYMBOLS             0

int power(int base,int exp){ 
  int result=1; 
  for (int i=0; i< exp; i++)
    result *= base;
  return result;
} 

template<class iType,class oType> 
class StrlDigMod : public StrlInterpolatingSigProc<iType,oType> {
protected:
  int samples_per_bit, k, num_symbols, fr_mult, freq_band, bit_rate;  /* num_symbols = a power of 2 */
  float center_freq, amplitude;                     
  float sym_phase[32], sym_ampl[32], alpha;
  unsigned int last_k_symb, buffer_mask;
  int custom_symbols;
  oType* wavetable;
  int sync_count, skip_count, sync_length, skip_length, sync_mode;
  int sync_high, sync_low;
  iType *sync_symbol;
  double* p_t;
  unsigned int buffer_length;
  virtual void initialize();
  virtual void inc_place_symbol(int[]);
  virtual void calc_prototype();
  virtual void fill_wavetable(double*);
//jca #if LOG_SYMBOLS
  char* data_ptr, *cur_data_ptr;
//jca #endif
  int symbol_count;
public:   
  virtual const char *name() { return "StrlDigMod"; }
  virtual void change_constellation(float, float, int, int, float*, float*,int);
  virtual void set_sync_symbols(int, int);
  virtual int work(VrSampleRange output, void *o[],
		   VrSampleRange inputs[], void *i[]);
  char* getOriginal() {symbol_count = 0;
	cur_data_ptr = data_ptr;
	return data_ptr;
	};
  int getNumSymbols() {return symbol_count;};
  StrlDigMod(int, float, float);
  StrlDigMod(int, float, float, int, float[], float[]);
  StrlDigMod(int, float, float, int, float[], float[], int, float, int);
};

template<class iType,class oType> int
StrlDigMod<iType,oType>::work(VrSampleRange output, void *ao[],
				VrSampleRange inputs[], void *ai[])
{
  iType **i = (iType **)ai;
  oType **o = (oType **)ao;
  int size = output.size;
  iType input_symbol; 
  oType *output_ptr;
  int j;
#ifdef DEBUG
  printf("%s (work) : output SRange [%lld, %lu]\n",name(),output.index,output.size);  
#endif
  while (size > 0) {
    //size -= samples_per_bit;
    // this code assumes that input_symbols is in range: [0..(num_symbols-1)]
	//    input_symbol = *i[0]++;
      size -= samples_per_bit;

    if(!sync_mode){
      input_symbol = *i[0]++;
      //      size -= samples_per_bit;
      //cout << skip_count << endl;
      if ((skip_count++) == skip_length-1){
	//cout << "start sync soon" << endl;
	sync_mode = 1;
	skip_count = 0;
      }
    } else {
      input_symbol = *(sync_symbol+sync_count++);
      if (sync_count==sync_length){
	sync_mode = 0;
	sync_count = 0;
      } 
    }
#ifdef COMP_VAL
   printf("in %x ",input_symbol);
#endif

#if LOG_SYMBOLS
	if (cur_data_ptr < &data_ptr[MAX_SYMBOLS])
    	*cur_data_ptr++ = input_symbol;
    symbol_count++;
#endif
if (input_symbol < 0 || input_symbol >= num_symbols) {
printf ("bad input symbol %d (max %d)\n", input_symbol, num_symbols);
input_symbol = 0;
}
    last_k_symb = ((last_k_symb * num_symbols) + (input_symbol)) & buffer_mask;
if ((last_k_symb+1) * samples_per_bit > buffer_length) {
printf ("index too large (%d+1) * %d = %d (max %d)\n", last_k_symb, samples_per_bit,
(last_k_symb+1) * samples_per_bit, buffer_length);
}

    output_ptr = wavetable + (last_k_symb * samples_per_bit); 
	j = samples_per_bit;
    while (j--)
		*o[0]++= *output_ptr++;    
#ifdef COMP_VAL
    printf("out %x ",*(--output_ptr));
    output_ptr++;
#endif
  } /* while (size-- > 0) */
#ifdef DEBUG
  printf("%s (work) return : %lu (output.size)\n",name(),output.size); 
#endif
  return output.size;
}

template<class iType,class oType> void
StrlDigMod<iType,oType>::inc_place_symbol(int place_symbol[])
{

  place_symbol[0]++;
  for(int i=0;i<k-1;i++)
    if(place_symbol[i]==num_symbols){
      place_symbol[i]=0;
      place_symbol[i+1]++;
    }
}

template<class iType,class oType> void
StrlDigMod<iType,oType>::calc_prototype()
{
  
  float time, Tb, Ts, fr_c;
  int bit_rate, out_sample_rate, tmp_i;
  const double pi = (double) M_PI;
  float tmp_a, tmp_p;

  cout << "Calc_prototype..." << endl;
  bit_rate = (int)getInputSamplingFrequencyN(0);
  out_sample_rate = (int)getSamplingFrequency();

  Tb = 1/ (double) bit_rate;
  Ts = 1/ (double) out_sample_rate;
  fr_c = freq_band * fr_mult * getInputSamplingFrequencyN(0);

  for (int symbol=0; symbol < num_symbols; symbol++){
    for (int i=0;i< k; i++){
      for (int j=0;j< samples_per_bit; j++){

	time = ((-1)*k/2*Tb) + (Ts/2) + (Ts* ((double)(i*samples_per_bit) +(double)j));

    tmp_i = (symbol*k+i)*samples_per_bit+j;
    tmp_a = sym_ampl[symbol] ;
    tmp_p = sym_phase[symbol] ;

#if 1
    p_t[tmp_i] = (double) (tmp_a
		* (cos(2*pi*fr_c*time+tmp_p))
		* (sin(pi*time/Tb)/(pi*time/Tb))
		* (cos(alpha*pi*time/Tb)/(1-((2*alpha*time/Tb)*(2*alpha*time/Tb)))) );
#endif

#if 0
	cout << "symbol: " << symbol << "    i: " << i << "    j: " << j << "  " <<
		 (double) p_t[(symbol*k+i)*samples_per_bit+j] << endl;
	cout << (double) p_t[(symbol*k+i)*samples_per_bit+j] << endl;
#endif
      }
    }
  }
}

template<class iType,class oType> void
StrlDigMod<iType,oType>::fill_wavetable(double* proto)
{  
  float temp;
  int *place_symbol;

  place_symbol = new int[k];
  for(int i=0;i<k;i++){ place_symbol[i]=0;} 
  printf("Fill wavetable...\n");

  for (int i=0;i<power(num_symbols,k);i++){
    for (int m=0;m<samples_per_bit;m++){
      temp =0.0;
      
      for (int n=0;n<k;n++){
#if 0
		cout << i << " " << m << " " << n << "     " << place_symbol[3] << " " << place_symbol[2] << " "
			<< place_symbol[1] << " " << place_symbol[0] << " " << endl;
#endif
		temp+= proto[((place_symbol[n]*k+n)*samples_per_bit)+m];
      }
      wavetable[(i)*samples_per_bit+m] = (oType) (amplitude * temp);
    }
    inc_place_symbol(place_symbol);
  }
}

template<class iType,class oType> void
StrlDigMod<iType,oType>::initialize()
{
  int num_buffers;

  printf("%s initialize...\n",name());
  if (!custom_symbols){
    num_symbols = 4;
    sym_phase[0] =  0; sym_phase[1] =  0; sym_phase[2] =  0; sym_phase[3] =  0;
    sym_ampl[0]  =  -1.0; sym_ampl[1]  =  -1.0/3.0; sym_ampl[2]  =  1.0/3.0; sym_ampl[3]  =  1.0;
  }    
  last_k_symb = 0;
    
  buffer_mask = 0;
  num_buffers = power(num_symbols,k);
  buffer_mask = (unsigned int) num_buffers-1;  

  printf("memory: %d  buffers: %d  mask: %d\n",k,num_buffers,buffer_mask);
  
//  cout << "memory: " << k << "  buffers: " << num_buffers << "  mask: " << buffer_mask << endl;

  /* allocate and create prototype and wavetable */
  /* p_t will hold prototype pulse for EACH symbol over entire k-interval period*/ 

  p_t = new double[num_symbols*k*samples_per_bit];
  
  printf("p_t is %d (num of symbols) x %d (k) x %d (samples/bit)\n",num_symbols,k ,samples_per_bit);

//  cout << "p_t is " << num_symbols << " x " << k << " x " << samples_per_bit << endl;
  calc_prototype();
  
  buffer_length = num_buffers * samples_per_bit;
  wavetable = new oType[buffer_length];
  fill_wavetable(p_t);
  printf("wavetable buffer: %u bytes\n",sizeof(oType)*buffer_length);
//  cout << "wavetable buffer: " << sizeof(oType)*buffer_length << " bytes" << endl; 

  sync_count = 0;
  skip_count = 0;
  skip_length = 42;
  sync_length = 8;
  sync_mode = 1;
  sync_symbol = new iType[sync_length];
  
  sync_symbol[0] = 0;
  sync_symbol[1] = 0;
  sync_symbol[2] = 7;
  sync_symbol[3] = 7;
  sync_symbol[4] = 7;
  sync_symbol[5] = 7;
  sync_symbol[6] = 0;
  sync_symbol[7] = 0;

//jca #if LOG_SYMBOLS
  symbol_count = 0;
  data_ptr = new char[MAX_SYMBOLS]; 
  cur_data_ptr = data_ptr;
//jca #endif

  printf("%s has finished initializing\n",name());

}


template<class iType,class oType> void
StrlDigMod<iType,oType>::change_constellation(float alph, float a, int new_ns, int new_k,
					    float sym_phs[], float sym_amp[], int fr_band)
{
  int num_buffers;

  delete wavetable;
  delete p_t;

  freq_band = fr_band; 
  k = new_k;
  num_symbols = new_ns;
  printf("num symbols: %d\n",num_symbols);
  alpha = alph;
  amplitude = a;

  for (int i=0;i<num_symbols;i++){
    sym_phase[i] = sym_phs[i];
    sym_ampl[i] = sym_amp[i];
    printf(" symbol phase: %f    symbol amplitude: %f \n ",sym_phase[i],sym_ampl[i]);
  }
  last_k_symb = 0;
    
  buffer_mask = 0;
  num_buffers = power(num_symbols,k);
  buffer_mask = (unsigned int) num_buffers-1;  

  cout << "memory: " << k << "  buffers: " << num_buffers << "  mask: " << buffer_mask << endl;

  /* allocate and create prototype and wavetable */
  /* p_t will hold prototype pulse for EACH symbol over entire k-interval period*/ 

  p_t = new double[num_symbols*k*samples_per_bit];
  cout << "p_t is " << num_symbols << " x " << k << " x " << samples_per_bit << endl;
  calc_prototype();
  
  buffer_length = num_buffers * samples_per_bit;
  wavetable = new oType[buffer_length];
  fill_wavetable(p_t);
  cout << "wavetable buffer: " << sizeof(oType)*buffer_length << " bytes" << endl; 

//jca #if LOG_SYMBOLS
  symbol_count = 0;
  data_ptr = new char[MAX_SYMBOLS]; 
  cur_data_ptr = data_ptr;
}

template<class iType,class oType> void 
StrlDigMod<iType,oType>::set_sync_symbols(int l, int h){

  sync_symbol[0] = l;
  sync_symbol[1] = l;
  sync_symbol[2] = h;
  sync_symbol[3] = h;
  sync_symbol[4] = h;
  sync_symbol[5] = h;
  sync_symbol[6] = l;
  sync_symbol[7] = l;
}


template<class iType,class oType> 
StrlDigMod<iType,oType>::StrlDigMod(int i, float fc, float a)
  :StrlInterpolatingSigProc<iType, oType>(1, i), center_freq(fc), amplitude(a)
{
  custom_symbols = 0;
  samples_per_bit = interp;
  setOutputSize(samples_per_bit);
  k = 4;
  alpha = 0.3;
  fr_mult = 0;
  freq_band = 1;
}

template<class iType,class oType> 
StrlDigMod<iType,oType>::StrlDigMod(int i, float fc, float a, int num_sym, float sym_phs[], float sym_amp[])
  :StrlInterpolatingSigProc<iType, oType>(1, i), center_freq(fc), amplitude(a)
{
  custom_symbols = 1;
  num_symbols = num_sym;
  printf("num symbols: %d\n",num_symbols);
  for (int i=0;i<num_symbols;i++){
    sym_phase[i] = sym_phs[i];
    sym_ampl[i] = sym_amp[i];
    printf(" symbol phase: %f    symbol amplitude: %f \n ",sym_phase[i],sym_ampl[i]);
  }
  samples_per_bit = interp;
  setOutputSize(samples_per_bit);
  k = 6;
  alpha = 0.3;
  fr_mult = 0;
  freq_band = 1;
  printf(" Done initialize!\n");
}

template<class iType,class oType> 
StrlDigMod<iType,oType>::StrlDigMod(int i, float fc, float am, int num_sym, float sym_phs[], float sym_amp[], int K, float a, int fr)
  :StrlInterpolatingSigProc<iType, oType>(1, i), k(K), center_freq(fc), amplitude(am),  alpha(a)
{
  custom_symbols = 1;
  num_symbols = num_sym;
  printf("num symbols: %d\n",num_symbols);
  for (int i=0;i<num_symbols;i++){
    sym_phase[i] = sym_phs[i];
    sym_ampl[i] = sym_amp[i];
    printf(" symbol phase: %f    symbol amplitude: %f \n ",sym_phase[i],sym_ampl[i]);
  }
  samples_per_bit = interp;
  setOutputSize(samples_per_bit);
  fr_mult = fr;
  freq_band = 1;
}
#endif
