/* "SAXORT STRL Compiler version 3.0 compiled on Fri Apr 6 11:18:16 MET DST 2001" */

/* automaton kernel code*/
#include <stdlib.h>
#include <stdio.h>
#include "PERF_STRL1_strlcc.h"
#define SIZEOFINT 32
#define B_SET_VECTOR_MASK(i) ((unsigned int)1 << i)
#define B_RES_VECTOR_MASK(i) (~((unsigned int)1 << i))
#define BIT_SET(b_vector, bit_number) b_vector[(bit_number) / SIZEOFINT] |= B_SET_VECTOR_MASK((bit_number) % SIZEOFINT)
#define BIT_RESET(b_vector, bit_number) b_vector[(bit_number) / SIZEOFINT] &= ~B_SET_VECTOR_MASK((bit_number) % SIZEOFINT)
#define BIT_VALUE(b_vector, bit_number) b_vector[(bit_number) / SIZEOFINT] & B_SET_VECTOR_MASK((bit_number) % SIZEOFINT)

#define SET_ON(point) current_point_bit_vector[point / SIZEOFINT] |= B_SET_VECTOR_MASK(point % SIZEOFINT)
#define SET_OFF(point) current_point_bit_vector[point / SIZEOFINT] &= ~B_SET_VECTOR_MASK(point % SIZEOFINT)
#define IS_ON(point) (current_point_bit_vector[point / SIZEOFINT] & B_SET_VECTOR_MASK(point % SIZEOFINT))
#define SET_PAUSE_ON(point) next_point_bit_vector[point / SIZEOFINT] |= B_SET_VECTOR_MASK(point % SIZEOFINT)
#define SET_PAUSE_OFF(point) next_point_bit_vector[point / SIZEOFINT] &= ~B_SET_VECTOR_MASK(point % SIZEOFINT)
#define IS_PAUSE_ON(point) (next_point_bit_vector[point / SIZEOFINT] & B_SET_VECTOR_MASK(point % SIZEOFINT))

#define HALT_POINT_NUM 142
#define HALT_POINT_VECTOR_SIZE ((HALT_POINT_NUM-1)/(int)SIZEOFINT)+1
static unsigned int current_point_bit_vector[HALT_POINT_VECTOR_SIZE];
static unsigned int next_point_bit_vector[HALT_POINT_VECTOR_SIZE];

#define SIGNAL_NUM 65
#define SIGNAL_VECTOR_SIZE ((SIGNAL_NUM-1)/(int)SIZEOFINT)+1
static unsigned int signal_bit_vector[SIGNAL_VECTOR_SIZE];
#define EMIT(signal) signal_bit_vector[signal / SIZEOFINT] |= B_SET_VECTOR_MASK(signal % SIZEOFINT)
#define CLEAR_SIGNAL(signal) signal_bit_vector[signal / SIZEOFINT] &= B_RES_VECTOR_MASK(signal % SIZEOFINT)
#define IS_SIGNAL(signal,pre_level) (signal_bit_vector[signal / SIZEOFINT] & B_SET_VECTOR_MASK(signal % SIZEOFINT))


typedef  int boolean;
typedef  int integer;
#ifndef STRLEN 
#define STRLEN 81 
#endif 
typedef char *string;
#define _integer(x,y) (*x) = (y)
#define _boolean(x,y) (*x) = (y)
#define _float(x,y) (*x) = (y)
#define _double(x,y) (*x) = (y)
#define _string(x,y) strcpy((*x),(y))
#define _eq_integer(x,y) ((x) == (y))
#define _eq_boolean(x,y) ((x) == (y))
#define _eq_float(x,y) ((x) == (y))
#define _eq_double(x,y) ((x) == (y))
#define _eq_string(x,y) (!strcmp((x),(y)))
#define _string_to_text(x) (x)
#define _text_to_string(x,y) (strcpy((*x),(y)))

#define SIG_ID_Exception_GOTO_UNMARK_432 64
#define SIG_ID_Exception_EXIT_FUNC_431 63
static StrlSampleSize ID_Variable_complete_var_430 ;
static StrlSampleIndex ID_Variable_temp_index_429 ;
static integer ID_Variable_not_complete_flag_428 ;
static integer ID_Variable_not_source_427 ;
#define SIG_ID_Exception_EXIT_FUNC_426 62
static UnsignedInt ID_Variable_temp_unsigned_425 ;
static StrlSampleIndex ID_Variable_temp_index_424 ;
static integer ID_Variable_temp_int_423 ;
static integer ID_Variable_dataNotReadyUpstream_422 ;
static integer ID_Variable_dataMarkedUpstream_421 ;
static integer ID_Variable_Flag_420 ;
static integer ID_Variable_requestSize_419 ;
static StrlSampleIndex ID_Variable_tempWP_418 ;
static StrlSampleIndex ID_Variable_desiredWP_417 ;
static StrlSampleIndex ID_Variable_pendingWP_416 ;
static StrlSampleRange ID_Variable_MY_Sample_Range_415 ;
static StrlSampleRange ID_Variable_testrange_414 ;
#define SIG_ID_Signal_My_Sample_Range_413 61
static StrlSampleRange ID_Signal_My_Sample_Range_413 ;
#define SIG_ID_Exception_GOTO_UNMARK_412 60
#define SIG_ID_Exception_EXIT_FUNC_411 59
static StrlSampleSize ID_Variable_complete_var_410 ;
static StrlSampleIndex ID_Variable_temp_index_409 ;
static integer ID_Variable_not_complete_flag_408 ;
static integer ID_Variable_not_source_407 ;
#define SIG_ID_Exception_EXIT_FUNC_406 58
static UnsignedInt ID_Variable_temp_unsigned_405 ;
static StrlSampleIndex ID_Variable_temp_index_404 ;
static integer ID_Variable_temp_int_403 ;
static integer ID_Variable_dataNotReadyUpstream_402 ;
static integer ID_Variable_dataMarkedUpstream_401 ;
static integer ID_Variable_Flag_400 ;
static integer ID_Variable_requestSize_399 ;
static StrlSampleIndex ID_Variable_tempWP_398 ;
static StrlSampleIndex ID_Variable_desiredWP_397 ;
static StrlSampleIndex ID_Variable_pendingWP_396 ;
static StrlSampleRange ID_Variable_MY_Sample_Range_395 ;
static StrlSampleRange ID_Variable_testrange_394 ;
#define SIG_ID_Signal_b_on_393 57
#define SIG_ID_Signal_broadcast_on_392 56
#define SIG_ID_Signal_My_Sample_Range_391 55
static StrlSampleRange ID_Signal_My_Sample_Range_391 ;
#define SIG_ID_Exception_GOTO_UNMARK_390 54
#define SIG_ID_Exception_EXIT_FUNC_389 53
static StrlSampleSize ID_Variable_complete_var_388 ;
static StrlSampleIndex ID_Variable_temp_index_387 ;
static integer ID_Variable_not_complete_flag_386 ;
static integer ID_Variable_not_source_385 ;
#define SIG_ID_Exception_EXIT_FUNC_384 52
static UnsignedInt ID_Variable_temp_unsigned_383 ;
static StrlSampleIndex ID_Variable_temp_index_382 ;
static integer ID_Variable_temp_int_381 ;
static integer ID_Variable_dataNotReadyUpstream_380 ;
static integer ID_Variable_dataMarkedUpstream_379 ;
static integer ID_Variable_Flag_378 ;
static integer ID_Variable_requestSize_377 ;
static StrlSampleIndex ID_Variable_tempWP_376 ;
static StrlSampleIndex ID_Variable_desiredWP_375 ;
static StrlSampleIndex ID_Variable_pendingWP_374 ;
static StrlSampleRange ID_Variable_MY_Sample_Range_373 ;
static StrlSampleRange ID_Variable_testrange_372 ;
#define SIG_ID_Signal_My_Sample_Range_371 51
static StrlSampleRange ID_Signal_My_Sample_Range_371 ;
#define SIG_ID_Exception_GOTO_UNMARK_370 50
#define SIG_ID_Exception_EXIT_FUNC_369 49
static StrlSampleSize ID_Variable_complete_var_368 ;
static StrlSampleIndex ID_Variable_temp_index_367 ;
static integer ID_Variable_not_complete_flag_366 ;
static integer ID_Variable_not_source_365 ;
#define SIG_ID_Exception_EXIT_FUNC_364 48
static UnsignedInt ID_Variable_temp_unsigned_363 ;
static StrlSampleIndex ID_Variable_temp_index_362 ;
static integer ID_Variable_temp_int_361 ;
static integer ID_Variable_dataNotReadyUpstream_360 ;
static integer ID_Variable_dataMarkedUpstream_359 ;
static integer ID_Variable_Flag_358 ;
static integer ID_Variable_requestSize_357 ;
static StrlSampleIndex ID_Variable_tempWP_356 ;
static StrlSampleIndex ID_Variable_desiredWP_355 ;
static StrlSampleIndex ID_Variable_pendingWP_354 ;
static StrlSampleRange ID_Variable_MY_Sample_Range_353 ;
static StrlSampleRange ID_Variable_testrange_352 ;
#define SIG_ID_Signal_b_on_351 47
#define SIG_ID_Signal_broadcast_on_350 46
#define SIG_ID_Signal_My_Sample_Range_349 45
static StrlSampleRange ID_Signal_My_Sample_Range_349 ;
#define SIG_ID_Exception_GOTO_UNMARK_348 44
#define SIG_ID_Exception_EXIT_FUNC_347 43
static StrlSampleSize ID_Variable_complete_var_346 ;
static StrlSampleIndex ID_Variable_temp_index_345 ;
static integer ID_Variable_not_complete_flag_344 ;
static integer ID_Variable_not_source_343 ;
#define SIG_ID_Exception_EXIT_FUNC_342 42
static UnsignedInt ID_Variable_temp_unsigned_341 ;
static StrlSampleIndex ID_Variable_temp_index_340 ;
static integer ID_Variable_temp_int_339 ;
static integer ID_Variable_dataNotReadyUpstream_338 ;
static integer ID_Variable_dataMarkedUpstream_337 ;
static integer ID_Variable_Flag_336 ;
static integer ID_Variable_requestSize_335 ;
static StrlSampleIndex ID_Variable_tempWP_334 ;
static StrlSampleIndex ID_Variable_desiredWP_333 ;
static StrlSampleIndex ID_Variable_pendingWP_332 ;
static StrlSampleRange ID_Variable_MY_Sample_Range_331 ;
static StrlSampleRange ID_Variable_testrange_330 ;
#define SIG_ID_Signal_b_on_328 41
#define SIG_ID_Signal_broadcast_on_327 40
#define SIG_ID_Signal_My_Sample_Range_326 39
static StrlSampleRange ID_Signal_My_Sample_Range_326 ;
#define SIG_ID_Exception_GOTO_UNMARK_325 38
#define SIG_ID_Exception_EXIT_FUNC_324 37
static StrlSampleSize ID_Variable_complete_var_323 ;
static StrlSampleIndex ID_Variable_temp_index_322 ;
static integer ID_Variable_not_complete_flag_321 ;
static integer ID_Variable_not_source_320 ;
#define SIG_ID_Exception_EXIT_FUNC_309 36
static UnsignedInt ID_Variable_temp_unsigned_308 ;
static StrlSampleIndex ID_Variable_temp_index_307 ;
static integer ID_Variable_temp_int_306 ;
static integer ID_Variable_dataNotReadyUpstream_305 ;
static integer ID_Variable_dataMarkedUpstream_304 ;
static integer ID_Variable_Flag_303 ;
static integer ID_Variable_requestSize_302 ;
static StrlSampleIndex ID_Variable_desiredWP_301 ;
static StrlSampleIndex ID_Variable_pendingWP_300 ;
static StrlSampleRange ID_Variable_MY_Sample_Range_299 ;
static StrlSampleRange ID_Variable_testrange_298 ;
#define SIG_ID_Signal_My_Sample_Range_281 35
static StrlSampleRange ID_Signal_My_Sample_Range_281 ;
static StrlSampleIndex ID_Variable_WP_SCOPESINK_97 ;
static StrlSampleIndex ID_Variable_WP_SINK_96 ;
static string ID_Variable_nameofsink_95  = NULL;
static string ID_Variable_nameofscopesink_94  = NULL;
static string ID_Variable_nameofsummer_93  = NULL;
static string ID_Variable_nameofmod_92  = NULL;
static string ID_Variable_nameofcoder_91  = NULL;
static string ID_Variable_nameofsource_90  = NULL;
#define SIG_ID_Signal_end_compute_sink_89 34
static integer ID_Signal_end_compute_sink_89 ;
#define SIG_ID_Signal_broadcast_compute_88 33
static integer ID_Signal_broadcast_compute_88 ;
#define SIG_ID_Signal_ret_port_c1_87 32
static integer ID_Signal_ret_port_c1_87 ;
#define SIG_ID_Signal_ret_port_c2_86 31
static integer ID_Signal_ret_port_c2_86 ;
#define SIG_ID_Signal_ret_port_c3_85 30
static integer ID_Signal_ret_port_c3_85 ;
#define SIG_ID_Signal_ret_port_c4_84 29
static integer ID_Signal_ret_port_c4_84 ;
#define SIG_ID_Signal_ret_port_1_83 28
static integer ID_Signal_ret_port_1_83 ;
#define SIG_ID_Signal_ret_port_2_82 27
static integer ID_Signal_ret_port_2_82 ;
#define SIG_ID_Signal_ret_port_3_81 26
static integer ID_Signal_ret_port_3_81 ;
#define SIG_ID_Signal_ret_port_4_80 25
static integer ID_Signal_ret_port_4_80 ;
#define SIG_ID_Signal_sig_port_4_79 24
#define SIG_ID_Signal_sig_port_3_78 23
#define SIG_ID_Signal_sig_port_2_77 22
#define SIG_ID_Signal_sig_port_1_76 21
#define SIG_ID_Signal_mark_data_scopesink_75 20
#define SIG_ID_Signal_mark_data_sink_74 19
#ifndef INITIAL_UNSIGNEDINT
extern UnsignedInt INITIAL_UNSIGNEDINT;
#endif
#define DEF_TPD 2.600000e+03
#define CENTER_FREQ_MULT 4
#define ALPHA 6.000000e-01
#define K 2
#define CONST_NUM 5
#define NUM_SYMB 16
#define AMPL 80
#define OUTPUT_SYMBOL_BITS 4
#define IN_RATE 2000
#define OUT_RATE 400000
#ifndef INITIAL_RANGE
extern StrlSampleRange INITIAL_RANGE;
#endif
#ifndef INITIAL_SIZE
extern StrlSampleSize INITIAL_SIZE;
#endif
#ifndef INITIAL_INDEX
extern StrlSampleIndex INITIAL_INDEX;
#endif
#define SIG_ID_Output_Sink_module_57 18
static string ID_Output_Sink_module_57  = NULL;
#define SIG_ID_Output_Scopesink_module_56 17
static string ID_Output_Scopesink_module_56  = NULL;
#define SIG_ID_Output_Summer_module_55 16
static string ID_Output_Summer_module_55  = NULL;
#define SIG_ID_Output_Mod_module_54 15
static string ID_Output_Mod_module_54  = NULL;
#define SIG_ID_Output_Coder_module_53 14
static string ID_Output_Coder_module_53  = NULL;
#define SIG_ID_Output_Source_module_52 13
static string ID_Output_Source_module_52  = NULL;
#define SIG_ID_InputOutput_SINK_MYMARKEDDATA_51 12
static StrlSampleRange ID_InputOutput_SINK_MYMARKEDDATA_51 ;
#define SIG_ID_InputOutput_SCOPESINK_MYMARKEDDATA_50 11
static StrlSampleRange ID_InputOutput_SCOPESINK_MYMARKEDDATA_50 ;
#define SIG_ID_InputOutput_SUMMER_MYMARKEDDATA_49 10
static StrlSampleRange ID_InputOutput_SUMMER_MYMARKEDDATA_49 ;
#define SIG_ID_InputOutput_MOD_MYMARKEDDATA_48 9
static StrlSampleRange ID_InputOutput_MOD_MYMARKEDDATA_48 ;
#define SIG_ID_InputOutput_CODER_MYMARKEDDATA_47 8
static StrlSampleRange ID_InputOutput_CODER_MYMARKEDDATA_47 ;
#define SIG_ID_InputOutput_SOURCE_MYMARKEDDATA_46 7
static StrlSampleRange ID_InputOutput_SOURCE_MYMARKEDDATA_46 ;
#define SIG_ID_InputOutput_SINK_SRANGE_45 6
static StrlSampleRange ID_InputOutput_SINK_SRANGE_45 ;
#define SIG_ID_InputOutput_SCOPESINK_SRANGE_44 5
static StrlSampleRange ID_InputOutput_SCOPESINK_SRANGE_44 ;
#define SIG_ID_InputOutput_SUMMER_SRANGE_43 4
static StrlSampleRange ID_InputOutput_SUMMER_SRANGE_43 ;
#define SIG_ID_InputOutput_MOD_SRANGE_42 3
static StrlSampleRange ID_InputOutput_MOD_SRANGE_42 ;
#define SIG_ID_InputOutput_CODER_SRANGE_41 2
static StrlSampleRange ID_InputOutput_CODER_SRANGE_41 ;
#define SIG_ID_InputOutput_SOURCE_SRANGE_40 1
static StrlSampleRange ID_InputOutput_SOURCE_SRANGE_40 ;
#define SIG_ID_Input_user_Quit_39 0
#ifndef _StrlSampleSize
extern  void _StrlSampleSize(StrlSampleSize*,StrlSampleSize);
#endif
#ifndef _StrlSampleSize
extern  int _eq_StrlSampleSize(StrlSampleSize,StrlSampleSize);
#endif
#ifndef _StrlSampleSize_to_text
extern  char* _StrlSampleSize_to_text(StrlSampleSize);
#endif
#ifndef  _text_to_StrlSampleSize
extern  void _text_to_StrlSampleSize(StrlSampleSize*,char *);
#endif
#ifndef _StrlSampleIndex
extern  void _StrlSampleIndex(StrlSampleIndex*,StrlSampleIndex);
#endif
#ifndef _StrlSampleIndex
extern  int _eq_StrlSampleIndex(StrlSampleIndex,StrlSampleIndex);
#endif
#ifndef _StrlSampleIndex_to_text
extern  char* _StrlSampleIndex_to_text(StrlSampleIndex);
#endif
#ifndef  _text_to_StrlSampleIndex
extern  void _text_to_StrlSampleIndex(StrlSampleIndex*,char *);
#endif
#ifndef _StrlSampleRange
extern  void _StrlSampleRange(StrlSampleRange*,StrlSampleRange);
#endif
#ifndef _StrlSampleRange
extern  int _eq_StrlSampleRange(StrlSampleRange,StrlSampleRange);
#endif
#ifndef _StrlSampleRange_to_text
extern  char* _StrlSampleRange_to_text(StrlSampleRange);
#endif
#ifndef  _text_to_StrlSampleRange
extern  void _text_to_StrlSampleRange(StrlSampleRange*,char *);
#endif
#ifndef _Debug4Var
extern  void _Debug4Var(Debug4Var*,Debug4Var);
#endif
#ifndef _Debug4Var
extern  int _eq_Debug4Var(Debug4Var,Debug4Var);
#endif
#ifndef _Debug4Var_to_text
extern  char* _Debug4Var_to_text(Debug4Var);
#endif
#ifndef  _text_to_Debug4Var
extern  void _text_to_Debug4Var(Debug4Var*,char *);
#endif
#ifndef _UnsignedInt
extern  void _UnsignedInt(UnsignedInt*,UnsignedInt);
#endif
#ifndef _UnsignedInt
extern  int _eq_UnsignedInt(UnsignedInt,UnsignedInt);
#endif
#ifndef _UnsignedInt_to_text
extern  char* _UnsignedInt_to_text(UnsignedInt);
#endif
#ifndef  _text_to_UnsignedInt
extern  void _text_to_UnsignedInt(UnsignedInt*,char *);
#endif
#ifndef GET_SOURCE
extern string GET_SOURCE(string, integer);
#endif
#ifndef GET_CODER
extern string GET_CODER(integer);
#endif
#ifndef GET_MOD_F
extern string GET_MOD_F(integer, float, integer, integer, integer, integer, float, integer);
#endif
#ifndef GET_SUMMER
extern string GET_SUMMER();
#endif
#ifndef GET_SINK
extern string GET_SINK(string, integer);
#endif
#ifndef GET_SCOPESINK_F
extern string GET_SCOPESINK_F(float, integer, integer, integer, integer);
#endif
#ifndef CHOOSESINK
extern integer CHOOSESINK(StrlSampleIndex, StrlSampleIndex);
#endif
#ifndef GETMARKEDWP
extern StrlSampleIndex GETMARKEDWP(string);
#endif
#ifndef GET_S_RANGE
extern StrlSampleRange GET_S_RANGE(string);
#endif
#ifndef GETWP
extern StrlSampleIndex GETWP(string);
#endif
#ifndef GET_OUTPUTSIZE
extern UnsignedInt GET_OUTPUTSIZE(string);
#endif
#ifndef ADD_INDEX_SIZE
extern StrlSampleIndex ADD_INDEX_SIZE(StrlSampleRange);
#endif
#ifndef CMPSAMPLEINDEX
extern integer CMPSAMPLEINDEX(StrlSampleIndex, StrlSampleIndex);
#endif
#ifndef CMPSAMPLEINDEX1
extern integer CMPSAMPLEINDEX1(StrlSampleIndex, StrlSampleIndex);
#endif
#ifndef GETINDEX
extern StrlSampleIndex GETINDEX(StrlSampleRange);
#endif
#ifndef SUBTRACT_A_B
extern integer SUBTRACT_A_B(StrlSampleIndex, StrlSampleIndex);
#endif
#ifndef ROUNDUP_REQUESTSIZE
extern integer ROUNDUP_REQUESTSIZE(integer, UnsignedInt);
#endif
#ifndef SET_SAMPLERANGE
extern StrlSampleRange SET_SAMPLERANGE(StrlSampleIndex, integer);
#endif
#ifndef GET_NUMBERINPUTS
extern integer GET_NUMBERINPUTS(string);
#endif
#ifndef FORECASTS
extern StrlSampleRange FORECASTS(StrlSampleRange, string);
#endif
#ifndef REAL_MARK_DATA
extern integer REAL_MARK_DATA(StrlSampleIndex, integer, integer, StrlSampleRange, string);
#endif
#ifndef CHECK_MYWRITERLL
extern integer CHECK_MYWRITERLL(string);
#endif
#ifndef CHECK_MYMARKEDDATA_SIZE
extern integer CHECK_MYMARKEDDATA_SIZE(string);
#endif
#ifndef REALCOMPUTEDATA
extern StrlSampleSize REALCOMPUTEDATA(string, integer);
#endif
#ifndef CMPSAMPLESIZE
extern integer CMPSAMPLESIZE(StrlSampleSize, StrlSampleSize);
#endif
#ifndef GET_MYMARKEDINDEX
extern StrlSampleIndex GET_MYMARKEDINDEX(string);
#endif
#ifndef GET_MYMARKEDSIZE
extern StrlSampleSize GET_MYMARKEDSIZE(string);
#endif
#ifndef ADD_SAMPLEINDEX
extern StrlSampleIndex ADD_SAMPLEINDEX(StrlSampleIndex, StrlSampleSize);
#endif
#ifndef GET_MYMARKEDDATA
extern StrlSampleRange GET_MYMARKEDDATA(string);
#endif
#ifndef CHKMINRP
extern StrlSampleIndex CHKMINRP(StrlSampleIndex, StrlSampleRange, string);
#endif
#ifndef CONNECT_MODULES
extern void CONNECT_MODULES(string, string, integer);
#endif
#ifndef INITIAL_SINK
extern void INITIAL_SINK(string);
#endif
#ifndef INITGUI_MAIN_START
extern void INITGUI_MAIN_START();
#endif
#ifndef RUN_GUI_MAIN
extern void RUN_GUI_MAIN();
#endif
#ifndef INIT_PERF_GRAPH
extern void INIT_PERF_GRAPH();
#endif
#ifndef START_PERF_GRAPH
extern void START_PERF_GRAPH();
#endif
#ifndef STOP_PERF_GRAPH
extern void STOP_PERF_GRAPH();
#endif
#ifndef LOCALINCAWAITTICK
extern void LOCALINCAWAITTICK(string);
#endif
#ifndef SET_MARKEDWP
extern void SET_MARKEDWP(string, StrlSampleIndex);
#endif
#ifndef WRITEDATA
extern void WRITEDATA(string, integer);
#endif

extern void PERF_STRL1_O_Sink_module(string);
extern void PERF_STRL1_O_Scopesink_module(string);
extern void PERF_STRL1_O_Summer_module(string);
extern void PERF_STRL1_O_Mod_module(string);
extern void PERF_STRL1_O_Coder_module(string);
extern void PERF_STRL1_O_Source_module(string);
extern void PERF_STRL1_O_SINK_MYMARKEDDATA(StrlSampleRange);
void PERF_STRL1_I_SINK_MYMARKEDDATA(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_SINK_MYMARKEDDATA_51);_StrlSampleRange(&ID_InputOutput_SINK_MYMARKEDDATA_51,value);PERF_STRL1_O_SINK_MYMARKEDDATA(value);}
extern void PERF_STRL1_O_SCOPESINK_MYMARKEDDATA(StrlSampleRange);
void PERF_STRL1_I_SCOPESINK_MYMARKEDDATA(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_SCOPESINK_MYMARKEDDATA_50);_StrlSampleRange(&ID_InputOutput_SCOPESINK_MYMARKEDDATA_50,value);PERF_STRL1_O_SCOPESINK_MYMARKEDDATA(value);}
extern void PERF_STRL1_O_SUMMER_MYMARKEDDATA(StrlSampleRange);
void PERF_STRL1_I_SUMMER_MYMARKEDDATA(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_SUMMER_MYMARKEDDATA_49);_StrlSampleRange(&ID_InputOutput_SUMMER_MYMARKEDDATA_49,value);PERF_STRL1_O_SUMMER_MYMARKEDDATA(value);}
extern void PERF_STRL1_O_MOD_MYMARKEDDATA(StrlSampleRange);
void PERF_STRL1_I_MOD_MYMARKEDDATA(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_MOD_MYMARKEDDATA_48);_StrlSampleRange(&ID_InputOutput_MOD_MYMARKEDDATA_48,value);PERF_STRL1_O_MOD_MYMARKEDDATA(value);}
extern void PERF_STRL1_O_CODER_MYMARKEDDATA(StrlSampleRange);
void PERF_STRL1_I_CODER_MYMARKEDDATA(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_CODER_MYMARKEDDATA_47);_StrlSampleRange(&ID_InputOutput_CODER_MYMARKEDDATA_47,value);PERF_STRL1_O_CODER_MYMARKEDDATA(value);}
extern void PERF_STRL1_O_SOURCE_MYMARKEDDATA(StrlSampleRange);
void PERF_STRL1_I_SOURCE_MYMARKEDDATA(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_SOURCE_MYMARKEDDATA_46);_StrlSampleRange(&ID_InputOutput_SOURCE_MYMARKEDDATA_46,value);PERF_STRL1_O_SOURCE_MYMARKEDDATA(value);}
extern void PERF_STRL1_O_SINK_SRANGE(StrlSampleRange);
void PERF_STRL1_I_SINK_SRANGE(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_SINK_SRANGE_45);_StrlSampleRange(&ID_InputOutput_SINK_SRANGE_45,value);PERF_STRL1_O_SINK_SRANGE(value);}
extern void PERF_STRL1_O_SCOPESINK_SRANGE(StrlSampleRange);
void PERF_STRL1_I_SCOPESINK_SRANGE(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_SCOPESINK_SRANGE_44);_StrlSampleRange(&ID_InputOutput_SCOPESINK_SRANGE_44,value);PERF_STRL1_O_SCOPESINK_SRANGE(value);}
extern void PERF_STRL1_O_SUMMER_SRANGE(StrlSampleRange);
void PERF_STRL1_I_SUMMER_SRANGE(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_SUMMER_SRANGE_43);_StrlSampleRange(&ID_InputOutput_SUMMER_SRANGE_43,value);PERF_STRL1_O_SUMMER_SRANGE(value);}
extern void PERF_STRL1_O_MOD_SRANGE(StrlSampleRange);
void PERF_STRL1_I_MOD_SRANGE(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_MOD_SRANGE_42);_StrlSampleRange(&ID_InputOutput_MOD_SRANGE_42,value);PERF_STRL1_O_MOD_SRANGE(value);}
extern void PERF_STRL1_O_CODER_SRANGE(StrlSampleRange);
void PERF_STRL1_I_CODER_SRANGE(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_CODER_SRANGE_41);_StrlSampleRange(&ID_InputOutput_CODER_SRANGE_41,value);PERF_STRL1_O_CODER_SRANGE(value);}
extern void PERF_STRL1_O_SOURCE_SRANGE(StrlSampleRange);
void PERF_STRL1_I_SOURCE_SRANGE(StrlSampleRange value) {EMIT(SIG_ID_InputOutput_SOURCE_SRANGE_40);_StrlSampleRange(&ID_InputOutput_SOURCE_SRANGE_40,value);PERF_STRL1_O_SOURCE_SRANGE(value);}
void PERF_STRL1_I_user_Quit() {EMIT(SIG_ID_Input_user_Quit_39);}

static void Point_0() {
	CLEAR_SIGNAL(SIG_ID_Signal_mark_data_sink_74);
	CLEAR_SIGNAL(SIG_ID_Signal_mark_data_scopesink_75);
	CLEAR_SIGNAL(SIG_ID_Signal_sig_port_1_76);
	CLEAR_SIGNAL(SIG_ID_Signal_sig_port_2_77);
	CLEAR_SIGNAL(SIG_ID_Signal_sig_port_3_78);
	CLEAR_SIGNAL(SIG_ID_Signal_sig_port_4_79);
	_integer(&ID_Signal_ret_port_4_80,0);
	CLEAR_SIGNAL(SIG_ID_Signal_ret_port_4_80);
	_integer(&ID_Signal_ret_port_3_81,0);
	CLEAR_SIGNAL(SIG_ID_Signal_ret_port_3_81);
	_integer(&ID_Signal_ret_port_2_82,0);
	CLEAR_SIGNAL(SIG_ID_Signal_ret_port_2_82);
	_integer(&ID_Signal_ret_port_1_83,0);
	CLEAR_SIGNAL(SIG_ID_Signal_ret_port_1_83);
	_integer(&ID_Signal_ret_port_c4_84,0);
	CLEAR_SIGNAL(SIG_ID_Signal_ret_port_c4_84);
	_integer(&ID_Signal_ret_port_c3_85,0);
	CLEAR_SIGNAL(SIG_ID_Signal_ret_port_c3_85);
	_integer(&ID_Signal_ret_port_c2_86,0);
	CLEAR_SIGNAL(SIG_ID_Signal_ret_port_c2_86);
	_integer(&ID_Signal_ret_port_c1_87,0);
	CLEAR_SIGNAL(SIG_ID_Signal_ret_port_c1_87);
	_integer(&ID_Signal_broadcast_compute_88,0);
	CLEAR_SIGNAL(SIG_ID_Signal_broadcast_compute_88);
	_integer(&ID_Signal_end_compute_sink_89,0);
	CLEAR_SIGNAL(SIG_ID_Signal_end_compute_sink_89);
	_StrlSampleIndex(&ID_Variable_WP_SINK_96,INITIAL_INDEX);
	_StrlSampleIndex(&ID_Variable_WP_SCOPESINK_97,INITIAL_INDEX);
	if (IS_SIGNAL(SIG_ID_Input_user_Quit_39,0)) {
	} else {
		_string(&ID_Variable_nameofsource_90,GET_SOURCE("tmp.gz", 1));
		_string(&ID_Variable_nameofcoder_91,GET_CODER(4));
		_string(&ID_Variable_nameofmod_92,GET_MOD_F(200, 6.500000e+04, 80, 16, 5, 2, 6.000000e-01, 4));
		_string(&ID_Variable_nameofsummer_93,GET_SUMMER());
		_string(&ID_Variable_nameofscopesink_94,GET_SCOPESINK_F((2.600000e+03 / 2.000000e+00), -128, 128, 500, 1));
		_string(&ID_Variable_nameofsink_95,GET_SINK("localhost", 5001));
		_string(&ID_Output_Source_module_52,ID_Variable_nameofsource_90);
		PERF_STRL1_O_Source_module(ID_Output_Source_module_52); EMIT(SIG_ID_Output_Source_module_52);
		_string(&ID_Output_Coder_module_53,ID_Variable_nameofcoder_91);
		PERF_STRL1_O_Coder_module(ID_Output_Coder_module_53); EMIT(SIG_ID_Output_Coder_module_53);
		_string(&ID_Output_Mod_module_54,ID_Variable_nameofmod_92);
		PERF_STRL1_O_Mod_module(ID_Output_Mod_module_54); EMIT(SIG_ID_Output_Mod_module_54);
		_string(&ID_Output_Summer_module_55,ID_Variable_nameofsummer_93);
		PERF_STRL1_O_Summer_module(ID_Output_Summer_module_55); EMIT(SIG_ID_Output_Summer_module_55);
		_string(&ID_Output_Scopesink_module_56,ID_Variable_nameofscopesink_94);
		PERF_STRL1_O_Scopesink_module(ID_Output_Scopesink_module_56); EMIT(SIG_ID_Output_Scopesink_module_56);
		_string(&ID_Output_Sink_module_57,ID_Variable_nameofsink_95);
		PERF_STRL1_O_Sink_module(ID_Output_Sink_module_57); EMIT(SIG_ID_Output_Sink_module_57);
		CONNECT_MODULES(ID_Variable_nameofscopesink_94, ID_Variable_nameofmod_92, 400000);
		CONNECT_MODULES(ID_Variable_nameofsink_95, ID_Variable_nameofsummer_93, 400000);
		CONNECT_MODULES(ID_Variable_nameofsummer_93, ID_Variable_nameofmod_92, 400000);
		CONNECT_MODULES(ID_Variable_nameofmod_92, ID_Variable_nameofcoder_91, 2000);
		CONNECT_MODULES(ID_Variable_nameofcoder_91, ID_Variable_nameofsource_90, 1000);
		INITIAL_SINK(ID_Output_Sink_module_57);
		INITIAL_SINK(ID_Output_Scopesink_module_56);
		INIT_PERF_GRAPH();
		START_PERF_GRAPH();
		INITGUI_MAIN_START();
		_integer(&ID_Signal_end_compute_sink_89,1);
		EMIT(SIG_ID_Signal_end_compute_sink_89);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_281,INITIAL_RANGE);
		CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_281);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_326,INITIAL_RANGE);
		CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_326);
		CLEAR_SIGNAL(SIG_ID_Signal_broadcast_on_327);
		CLEAR_SIGNAL(SIG_ID_Signal_b_on_328);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_349,INITIAL_RANGE);
		CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_349);
		CLEAR_SIGNAL(SIG_ID_Signal_broadcast_on_350);
		CLEAR_SIGNAL(SIG_ID_Signal_b_on_351);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_371,INITIAL_RANGE);
		CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_371);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_391,INITIAL_RANGE);
		CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_391);
		CLEAR_SIGNAL(SIG_ID_Signal_broadcast_on_392);
		CLEAR_SIGNAL(SIG_ID_Signal_b_on_393);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_413,INITIAL_RANGE);
		CLEAR_SIGNAL(SIG_ID_Signal_My_Sample_Range_413);
		current_point_bit_vector[0] |= 0x80000000; current_point_bit_vector[1] |= 0x800000; current_point_bit_vector[2] |= 0x21214300; current_point_bit_vector[3] |= 0x2; /* On:  #31 #55 #72 #73 #78 #80 #85 #88 #93 #97*/
		next_point_bit_vector[0] |= 0x2; /* PauseOn:  #1*/
	}
}

static void Point_1() {
	if (IS_SIGNAL(SIG_ID_Input_user_Quit_39,0)) {
		current_point_bit_vector[0] &= ~0xfffff7fc; current_point_bit_vector[1] &= ~0xf1ffdff1; current_point_bit_vector[2] &= ~0xe363471f; current_point_bit_vector[3] &= ~0x308a659e; current_point_bit_vector[4] &= ~0x1580; /* Off:  #2 #3 #4 #5 #6 #7 #8 #9 #10 #12 #13 #14 #15 #16 #17 #18 #19 #20 #21 #22 #23 #24 #25 #26 #27 #28 #29 #30 #31 #32 #36 #37 #38 #39 #40 #41 #42 #43 #44 #46 #47 #48 #49 #50 #51 #52 #53 #54 #55 #56 #60 #61 #62 #63 #64 #65 #66 #67 #68 #72 #73 #74 #78 #80 #81 #85 #86 #88 #89 #93 #94 #95 #97 #98 #99 #100 #103 #104 #106 #109 #110 #113 #115 #119 #124 #125 #135 #136 #138 #140*/
	} else {
		next_point_bit_vector[0] |= 0x2; /* PauseOn:  #1*/
	}
}

static void Point_2() {
	if ((CHOOSESINK(ID_Variable_WP_SINK_96, ID_Variable_WP_SCOPESINK_97) > 0)) {
		_StrlSampleRange(&ID_InputOutput_SCOPESINK_SRANGE_44,GET_S_RANGE(ID_Variable_nameofscopesink_94));
		PERF_STRL1_O_SCOPESINK_SRANGE(ID_InputOutput_SCOPESINK_SRANGE_44); EMIT(SIG_ID_InputOutput_SCOPESINK_SRANGE_44);
		EMIT(SIG_ID_Signal_mark_data_scopesink_75);
		current_point_bit_vector[2] |= 0x40; /* On:  #70*/
	} else {
		_StrlSampleRange(&ID_InputOutput_SINK_SRANGE_45,GET_S_RANGE(ID_Variable_nameofsink_95));
		PERF_STRL1_O_SINK_SRANGE(ID_InputOutput_SINK_SRANGE_45); EMIT(SIG_ID_InputOutput_SINK_SRANGE_45);
		EMIT(SIG_ID_Signal_mark_data_sink_74);
		current_point_bit_vector[2] |= 0x40; /* On:  #70*/
	}
}

static void Point_3() {
	_integer(&ID_Signal_ret_port_4_80,2);
	EMIT(SIG_ID_Signal_ret_port_4_80);
	EMIT(SIG_ID_Exception_EXIT_FUNC_309);
	current_point_bit_vector[4] |= 0x80; /* On:  #135*/
}

static void Point_4() {
	_integer(&ID_Signal_ret_port_4_80,-1);
	EMIT(SIG_ID_Signal_ret_port_4_80);
	EMIT(SIG_ID_Exception_EXIT_FUNC_309);
	current_point_bit_vector[4] |= 0x80; /* On:  #135*/
}

static void Point_5() {
	_integer(&ID_Signal_ret_port_4_80,-2);
	EMIT(SIG_ID_Signal_ret_port_4_80);
	EMIT(SIG_ID_Exception_EXIT_FUNC_309);
	current_point_bit_vector[4] |= 0x80; /* On:  #135*/
}

static void Point_6() {
	_integer(&ID_Signal_ret_port_4_80,ID_Variable_dataNotReadyUpstream_305);
	EMIT(SIG_ID_Signal_ret_port_4_80);
	EMIT(SIG_ID_Exception_EXIT_FUNC_309);
	current_point_bit_vector[4] |= 0x80; /* On:  #135*/
}

static void Point_7() {
	_integer(&ID_Signal_ret_port_c4_84,0);
	EMIT(SIG_ID_Signal_ret_port_c4_84);
	EMIT(SIG_ID_Exception_EXIT_FUNC_324);
	current_point_bit_vector[3] |= 0x1; /* On:  #96*/
}

static void Point_8() {
	_integer(&ID_Signal_ret_port_c4_84,0);
	EMIT(SIG_ID_Signal_ret_port_c4_84);
	EMIT(SIG_ID_Exception_EXIT_FUNC_324);
	current_point_bit_vector[3] |= 0x1; /* On:  #96*/
}

static void Point_9() {
	_StrlSampleSize(&ID_Variable_complete_var_323,REALCOMPUTEDATA(ID_Output_Source_module_52, ID_Variable_not_source_320));
	if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Source_module_52), ID_Variable_complete_var_323) > 0)) {
		_integer(&ID_Variable_not_complete_flag_321,(ID_Variable_not_complete_flag_321 - 1));
	}
	if ((ID_Variable_not_complete_flag_321 < 0)) {
		_StrlSampleIndex(&ID_Variable_temp_index_322,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Source_module_52), ID_Variable_complete_var_323));
		LOCALINCAWAITTICK(ID_Output_Source_module_52);
		next_point_bit_vector[0] |= 0x400; /* PauseOn:  #10*/
	} else {
		current_point_bit_vector[0] |= 0x800; /* On:  #11*/
	}
}

static void Point_10() {
	SET_MARKEDWP(ID_Output_Source_module_52, ID_Variable_temp_index_322);
	current_point_bit_vector[0] |= 0x800; /* On:  #11*/
}

static void Point_11() {
	WRITEDATA(ID_Output_Source_module_52, ID_Variable_not_source_320);
	_StrlSampleIndex(&ID_Variable_temp_index_322,GETWP(ID_Output_Source_module_52));
	_StrlSampleRange(&ID_InputOutput_SOURCE_MYMARKEDDATA_46,GET_MYMARKEDDATA(ID_Output_Source_module_52));
	PERF_STRL1_O_SOURCE_MYMARKEDDATA(ID_InputOutput_SOURCE_MYMARKEDDATA_46); EMIT(SIG_ID_InputOutput_SOURCE_MYMARKEDDATA_46);
	_integer(&ID_Signal_ret_port_c4_84,ID_Variable_not_complete_flag_321);
	EMIT(SIG_ID_Signal_ret_port_c4_84);
	LOCALINCAWAITTICK(ID_Output_Source_module_52);
	next_point_bit_vector[0] |= 0x1000; /* PauseOn:  #12*/
}

static void Point_12() {
	current_point_bit_vector[3] |= 0x1; /* On:  #96*/
}

static void Point_13() {
	_integer(&ID_Signal_ret_port_3_81,2);
	EMIT(SIG_ID_Signal_ret_port_3_81);
	EMIT(SIG_ID_Exception_EXIT_FUNC_342);
	current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
}

static void Point_14() {
	_integer(&ID_Signal_ret_port_3_81,-1);
	EMIT(SIG_ID_Signal_ret_port_3_81);
	EMIT(SIG_ID_Exception_EXIT_FUNC_342);
	current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
}

static void Point_15() {
	_integer(&ID_Signal_ret_port_3_81,-2);
	EMIT(SIG_ID_Signal_ret_port_3_81);
	EMIT(SIG_ID_Exception_EXIT_FUNC_342);
	current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
}

static void Point_16() {
	_integer(&ID_Signal_ret_port_3_81,0);
	EMIT(SIG_ID_Signal_ret_port_3_81);
	EMIT(SIG_ID_Exception_EXIT_FUNC_342);
	current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
}

static void Point_17() {
	_integer(&ID_Signal_ret_port_3_81,0);
	EMIT(SIG_ID_Signal_ret_port_3_81);
	EMIT(SIG_ID_Exception_EXIT_FUNC_342);
	current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
}

static void Point_18() {
	_integer(&ID_Signal_ret_port_3_81,ID_Variable_dataNotReadyUpstream_338);
	EMIT(SIG_ID_Signal_ret_port_3_81);
	EMIT(SIG_ID_Exception_EXIT_FUNC_342);
	current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
}

static void Point_19() {
	_integer(&ID_Signal_ret_port_c3_85,0);
	EMIT(SIG_ID_Signal_ret_port_c3_85);
	EMIT(SIG_ID_Exception_EXIT_FUNC_347);
	current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
}

static void Point_20() {
	_integer(&ID_Signal_ret_port_c3_85,0);
	EMIT(SIG_ID_Signal_ret_port_c3_85);
	EMIT(SIG_ID_Exception_EXIT_FUNC_347);
	current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
}

static void Point_21() {
	_integer(&ID_Signal_ret_port_c3_85,ID_Variable_not_complete_flag_344);
	EMIT(SIG_ID_Signal_ret_port_c3_85);
	current_point_bit_vector[2] |= 0x800000; /* On:  #87*/
}

static void Point_22() {
	_integer(&ID_Signal_ret_port_2_82,2);
	EMIT(SIG_ID_Signal_ret_port_2_82);
	EMIT(SIG_ID_Exception_EXIT_FUNC_364);
	current_point_bit_vector[3] |= 0x200; /* On:  #105*/
}

static void Point_23() {
	_integer(&ID_Signal_ret_port_2_82,-1);
	EMIT(SIG_ID_Signal_ret_port_2_82);
	EMIT(SIG_ID_Exception_EXIT_FUNC_364);
	current_point_bit_vector[3] |= 0x200; /* On:  #105*/
}

static void Point_24() {
	_integer(&ID_Signal_ret_port_2_82,-2);
	EMIT(SIG_ID_Signal_ret_port_2_82);
	EMIT(SIG_ID_Exception_EXIT_FUNC_364);
	current_point_bit_vector[3] |= 0x200; /* On:  #105*/
}

static void Point_25() {
	_integer(&ID_Signal_ret_port_2_82,0);
	EMIT(SIG_ID_Signal_ret_port_2_82);
	EMIT(SIG_ID_Exception_EXIT_FUNC_364);
	current_point_bit_vector[3] |= 0x200; /* On:  #105*/
}

static void Point_26() {
	_integer(&ID_Signal_ret_port_2_82,0);
	EMIT(SIG_ID_Signal_ret_port_2_82);
	EMIT(SIG_ID_Exception_EXIT_FUNC_364);
	current_point_bit_vector[3] |= 0x200; /* On:  #105*/
}

static void Point_27() {
	_integer(&ID_Signal_ret_port_2_82,ID_Variable_dataNotReadyUpstream_360);
	EMIT(SIG_ID_Signal_ret_port_2_82);
	EMIT(SIG_ID_Exception_EXIT_FUNC_364);
	current_point_bit_vector[3] |= 0x200; /* On:  #105*/
}

static void Point_28() {
	_integer(&ID_Signal_ret_port_c2_86,0);
	EMIT(SIG_ID_Signal_ret_port_c2_86);
	EMIT(SIG_ID_Exception_EXIT_FUNC_369);
	current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
}

static void Point_29() {
	_integer(&ID_Signal_ret_port_c2_86,0);
	EMIT(SIG_ID_Signal_ret_port_c2_86);
	EMIT(SIG_ID_Exception_EXIT_FUNC_369);
	current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
}

static void Point_30() {
	_integer(&ID_Signal_ret_port_c2_86,ID_Variable_not_complete_flag_366);
	EMIT(SIG_ID_Signal_ret_port_c2_86);
	current_point_bit_vector[2] |= 0x8000; /* On:  #79*/
}

static void Point_31() {
	if (IS_SIGNAL(SIG_ID_Signal_mark_data_scopesink_75,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_371,ID_InputOutput_SCOPESINK_SRANGE_44);
		EMIT(SIG_ID_Signal_My_Sample_Range_371);
		_StrlSampleRange(&ID_Variable_testrange_372,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_373,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_374,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_375,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_376,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_377,0);
		_integer(&ID_Variable_Flag_378,0);
		_integer(&ID_Variable_dataMarkedUpstream_379,0);
		_integer(&ID_Variable_dataNotReadyUpstream_380,0);
		_integer(&ID_Variable_temp_int_381,0);
		_StrlSampleIndex(&ID_Variable_temp_index_382,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_383,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_384);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_373,ID_Signal_My_Sample_Range_371);
		_StrlSampleIndex(&ID_Variable_pendingWP_374,GETMARKEDWP(ID_Output_Scopesink_module_56));
		_StrlSampleIndex(&ID_Variable_desiredWP_375,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_373));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_375, GETWP(ID_Output_Scopesink_module_56)) <= 0)) {
			current_point_bit_vector[1] |= 0x8; /* On:  #35*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_374, GETINDEX(ID_Variable_MY_Sample_Range_373)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_376,CHKMINRP(ID_Variable_pendingWP_374, ID_Variable_MY_Sample_Range_373, ID_Output_Scopesink_module_56));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_376, INITIAL_INDEX) <= 0)) {
					current_point_bit_vector[1] |= 0x4; /* On:  #34*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_374,ID_Variable_tempWP_376);
					goto L235;
				}
			} else {
L235:
				_integer(&ID_Variable_requestSize_377,SUBTRACT_A_B(ID_Variable_desiredWP_375, ID_Variable_pendingWP_374));
				if ((ID_Variable_requestSize_377 <= 0)) {
					current_point_bit_vector[1] |= 0x2; /* On:  #33*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_383,GET_OUTPUTSIZE(ID_Output_Scopesink_module_56));
					_integer(&ID_Variable_requestSize_377,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_377, ID_Variable_temp_unsigned_383));
					_StrlSampleRange(&ID_Variable_testrange_372,SET_SAMPLERANGE(ID_Variable_pendingWP_374, ID_Variable_requestSize_377));
					_StrlSampleRange(&ID_InputOutput_MOD_SRANGE_42,FORECASTS(ID_Variable_testrange_372, ID_Output_Scopesink_module_56));
					PERF_STRL1_O_MOD_SRANGE(ID_InputOutput_MOD_SRANGE_42); EMIT(SIG_ID_InputOutput_MOD_SRANGE_42);
					current_point_bit_vector[1] |= 0x1; current_point_bit_vector[3] |= 0x2000; /* On:  #32 #109*/
				}
			}
		}
	} else {
		next_point_bit_vector[0] |= 0x80000000; /* PauseOn:  #31*/
	}
}

static void Point_32() {
	EMIT(SIG_ID_Signal_sig_port_2_77);
	next_point_bit_vector[1] |= 0x1; /* PauseOn:  #32*/
}

static void Point_33() {
	LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
	next_point_bit_vector[1] |= 0x40; /* PauseOn:  #38*/
}

static void Point_34() {
	LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
	next_point_bit_vector[1] |= 0x20; /* PauseOn:  #37*/
}

static void Point_35() {
	LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
	next_point_bit_vector[1] |= 0x10; /* PauseOn:  #36*/
}

static void Point_36() {
	_integer(&ID_Signal_broadcast_compute_88,2);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_384);
	current_point_bit_vector[3] |= 0x4000; /* On:  #110*/
}

static void Point_37() {
	_integer(&ID_Signal_broadcast_compute_88,-1);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_384);
	current_point_bit_vector[3] |= 0x4000; /* On:  #110*/
}

static void Point_38() {
	_integer(&ID_Signal_broadcast_compute_88,-2);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_384);
	current_point_bit_vector[3] |= 0x4000; /* On:  #110*/
}

static void Point_39() {
	_integer(&ID_Signal_broadcast_compute_88,0);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_384);
	current_point_bit_vector[3] |= 0x4000; /* On:  #110*/
}

static void Point_40() {
	_integer(&ID_Signal_broadcast_compute_88,0);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_384);
	current_point_bit_vector[3] |= 0x4000; /* On:  #110*/
}

static void Point_41() {
	_integer(&ID_Signal_broadcast_compute_88,ID_Variable_dataNotReadyUpstream_380);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_384);
	current_point_bit_vector[3] |= 0x4000; /* On:  #110*/
}

static void Point_42() {
	_integer(&ID_Signal_end_compute_sink_89,0);
	EMIT(SIG_ID_Signal_end_compute_sink_89);
	EMIT(SIG_ID_Exception_EXIT_FUNC_389);
	current_point_bit_vector[1] |= 0x2000; /* On:  #45*/
}

static void Point_43() {
	_integer(&ID_Signal_end_compute_sink_89,0);
	EMIT(SIG_ID_Signal_end_compute_sink_89);
	EMIT(SIG_ID_Exception_EXIT_FUNC_389);
	current_point_bit_vector[1] |= 0x2000; /* On:  #45*/
}

static void Point_44() {
	_integer(&ID_Signal_end_compute_sink_89,ID_Variable_not_complete_flag_386);
	EMIT(SIG_ID_Signal_end_compute_sink_89);
	current_point_bit_vector[1] |= 0x2000; /* On:  #45*/
}

static void Point_45() {
	if (IS_SIGNAL(SIG_ID_Signal_mark_data_scopesink_75,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_371,ID_InputOutput_SCOPESINK_SRANGE_44);
		EMIT(SIG_ID_Signal_My_Sample_Range_371);
		_StrlSampleRange(&ID_Variable_testrange_372,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_373,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_374,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_375,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_376,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_377,0);
		_integer(&ID_Variable_Flag_378,0);
		_integer(&ID_Variable_dataMarkedUpstream_379,0);
		_integer(&ID_Variable_dataNotReadyUpstream_380,0);
		_integer(&ID_Variable_temp_int_381,0);
		_StrlSampleIndex(&ID_Variable_temp_index_382,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_383,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_384);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_373,ID_Signal_My_Sample_Range_371);
		_StrlSampleIndex(&ID_Variable_pendingWP_374,GETMARKEDWP(ID_Output_Scopesink_module_56));
		_StrlSampleIndex(&ID_Variable_desiredWP_375,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_373));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_375, GETWP(ID_Output_Scopesink_module_56)) <= 0)) {
			LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
			next_point_bit_vector[1] |= 0x10; /* PauseOn:  #36*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_374, GETINDEX(ID_Variable_MY_Sample_Range_373)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_376,CHKMINRP(ID_Variable_pendingWP_374, ID_Variable_MY_Sample_Range_373, ID_Output_Scopesink_module_56));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_376, INITIAL_INDEX) <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
					next_point_bit_vector[1] |= 0x20; /* PauseOn:  #37*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_374,ID_Variable_tempWP_376);
					goto L307;
				}
			} else {
L307:
				_integer(&ID_Variable_requestSize_377,SUBTRACT_A_B(ID_Variable_desiredWP_375, ID_Variable_pendingWP_374));
				if ((ID_Variable_requestSize_377 <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
					next_point_bit_vector[1] |= 0x40; /* PauseOn:  #38*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_383,GET_OUTPUTSIZE(ID_Output_Scopesink_module_56));
					_integer(&ID_Variable_requestSize_377,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_377, ID_Variable_temp_unsigned_383));
					_StrlSampleRange(&ID_Variable_testrange_372,SET_SAMPLERANGE(ID_Variable_pendingWP_374, ID_Variable_requestSize_377));
					_StrlSampleRange(&ID_InputOutput_MOD_SRANGE_42,FORECASTS(ID_Variable_testrange_372, ID_Output_Scopesink_module_56));
					PERF_STRL1_O_MOD_SRANGE(ID_InputOutput_MOD_SRANGE_42); EMIT(SIG_ID_InputOutput_MOD_SRANGE_42);
					EMIT(SIG_ID_Signal_sig_port_2_77);
					current_point_bit_vector[3] |= 0x2000000; /* On:  #121*/
					next_point_bit_vector[1] |= 0x1; /* PauseOn:  #32*/
				}
			}
		}
	} else {
		next_point_bit_vector[0] |= 0x80000000; /* PauseOn:  #31*/
	}
}

static void Point_46() {
	_integer(&ID_Signal_ret_port_1_83,2);
	EMIT(SIG_ID_Signal_ret_port_1_83);
	EMIT(SIG_ID_Exception_EXIT_FUNC_406);
	current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
}

static void Point_47() {
	_integer(&ID_Signal_ret_port_1_83,-1);
	EMIT(SIG_ID_Signal_ret_port_1_83);
	EMIT(SIG_ID_Exception_EXIT_FUNC_406);
	current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
}

static void Point_48() {
	_integer(&ID_Signal_ret_port_1_83,-2);
	EMIT(SIG_ID_Signal_ret_port_1_83);
	EMIT(SIG_ID_Exception_EXIT_FUNC_406);
	current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
}

static void Point_49() {
	_integer(&ID_Signal_ret_port_1_83,0);
	EMIT(SIG_ID_Signal_ret_port_1_83);
	EMIT(SIG_ID_Exception_EXIT_FUNC_406);
	current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
}

static void Point_50() {
	_integer(&ID_Signal_ret_port_1_83,0);
	EMIT(SIG_ID_Signal_ret_port_1_83);
	EMIT(SIG_ID_Exception_EXIT_FUNC_406);
	current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
}

static void Point_51() {
	_integer(&ID_Signal_ret_port_1_83,ID_Variable_dataNotReadyUpstream_402);
	EMIT(SIG_ID_Signal_ret_port_1_83);
	EMIT(SIG_ID_Exception_EXIT_FUNC_406);
	current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
}

static void Point_52() {
	_integer(&ID_Signal_ret_port_c1_87,0);
	EMIT(SIG_ID_Signal_ret_port_c1_87);
	EMIT(SIG_ID_Exception_EXIT_FUNC_411);
	current_point_bit_vector[2] |= 0x80; /* On:  #71*/
}

static void Point_53() {
	_integer(&ID_Signal_ret_port_c1_87,0);
	EMIT(SIG_ID_Signal_ret_port_c1_87);
	EMIT(SIG_ID_Exception_EXIT_FUNC_411);
	current_point_bit_vector[2] |= 0x80; /* On:  #71*/
}

static void Point_54() {
	_integer(&ID_Signal_ret_port_c1_87,ID_Variable_not_complete_flag_408);
	EMIT(SIG_ID_Signal_ret_port_c1_87);
	current_point_bit_vector[2] |= 0x80; /* On:  #71*/
}

static void Point_55() {
	if (IS_SIGNAL(SIG_ID_Signal_mark_data_sink_74,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_413,ID_InputOutput_SINK_SRANGE_45);
		EMIT(SIG_ID_Signal_My_Sample_Range_413);
		_StrlSampleRange(&ID_Variable_testrange_414,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_415,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_416,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_417,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_418,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_419,0);
		_integer(&ID_Variable_Flag_420,0);
		_integer(&ID_Variable_dataMarkedUpstream_421,0);
		_integer(&ID_Variable_dataNotReadyUpstream_422,0);
		_integer(&ID_Variable_temp_int_423,0);
		_StrlSampleIndex(&ID_Variable_temp_index_424,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_425,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_426);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_415,ID_Signal_My_Sample_Range_413);
		_StrlSampleIndex(&ID_Variable_pendingWP_416,GETMARKEDWP(ID_Output_Sink_module_57));
		_StrlSampleIndex(&ID_Variable_desiredWP_417,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_415));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_417, GETWP(ID_Output_Sink_module_57)) <= 0)) {
			current_point_bit_vector[1] |= 0x8000000; /* On:  #59*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_416, GETINDEX(ID_Variable_MY_Sample_Range_415)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_418,CHKMINRP(ID_Variable_pendingWP_416, ID_Variable_MY_Sample_Range_415, ID_Output_Sink_module_57));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_418, INITIAL_INDEX) <= 0)) {
					current_point_bit_vector[1] |= 0x4000000; /* On:  #58*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_416,ID_Variable_tempWP_418);
					goto L377;
				}
			} else {
L377:
				_integer(&ID_Variable_requestSize_419,SUBTRACT_A_B(ID_Variable_desiredWP_417, ID_Variable_pendingWP_416));
				if ((ID_Variable_requestSize_419 <= 0)) {
					current_point_bit_vector[1] |= 0x2000000; /* On:  #57*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_425,GET_OUTPUTSIZE(ID_Output_Sink_module_57));
					_integer(&ID_Variable_requestSize_419,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_419, ID_Variable_temp_unsigned_425));
					_StrlSampleRange(&ID_Variable_testrange_414,SET_SAMPLERANGE(ID_Variable_pendingWP_416, ID_Variable_requestSize_419));
					_StrlSampleRange(&ID_InputOutput_SUMMER_SRANGE_43,FORECASTS(ID_Variable_testrange_414, ID_Output_Sink_module_57));
					PERF_STRL1_O_SUMMER_SRANGE(ID_InputOutput_SUMMER_SRANGE_43); EMIT(SIG_ID_InputOutput_SUMMER_SRANGE_43);
					current_point_bit_vector[1] |= 0x1000000; current_point_bit_vector[3] |= 0x10000000; /* On:  #56 #124*/
				}
			}
		}
	} else {
		next_point_bit_vector[1] |= 0x800000; /* PauseOn:  #55*/
	}
}

static void Point_56() {
	EMIT(SIG_ID_Signal_sig_port_1_76);
	next_point_bit_vector[1] |= 0x1000000; /* PauseOn:  #56*/
}

static void Point_57() {
	LOCALINCAWAITTICK(ID_Output_Sink_module_57);
	next_point_bit_vector[1] |= 0x40000000; /* PauseOn:  #62*/
}

static void Point_58() {
	LOCALINCAWAITTICK(ID_Output_Sink_module_57);
	next_point_bit_vector[1] |= 0x20000000; /* PauseOn:  #61*/
}

static void Point_59() {
	LOCALINCAWAITTICK(ID_Output_Sink_module_57);
	next_point_bit_vector[1] |= 0x10000000; /* PauseOn:  #60*/
}

static void Point_60() {
	_integer(&ID_Signal_broadcast_compute_88,2);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_426);
	current_point_bit_vector[3] |= 0x20000000; /* On:  #125*/
}

static void Point_61() {
	_integer(&ID_Signal_broadcast_compute_88,-1);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_426);
	current_point_bit_vector[3] |= 0x20000000; /* On:  #125*/
}

static void Point_62() {
	_integer(&ID_Signal_broadcast_compute_88,-2);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_426);
	current_point_bit_vector[3] |= 0x20000000; /* On:  #125*/
}

static void Point_63() {
	_integer(&ID_Signal_broadcast_compute_88,0);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_426);
	current_point_bit_vector[3] |= 0x20000000; /* On:  #125*/
}

static void Point_64() {
	_integer(&ID_Signal_broadcast_compute_88,0);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_426);
	current_point_bit_vector[3] |= 0x20000000; /* On:  #125*/
}

static void Point_65() {
	_integer(&ID_Signal_broadcast_compute_88,ID_Variable_dataNotReadyUpstream_422);
	EMIT(SIG_ID_Signal_broadcast_compute_88);
	EMIT(SIG_ID_Exception_EXIT_FUNC_426);
	current_point_bit_vector[3] |= 0x20000000; /* On:  #125*/
}

static void Point_66() {
	_integer(&ID_Signal_end_compute_sink_89,0);
	EMIT(SIG_ID_Signal_end_compute_sink_89);
	EMIT(SIG_ID_Exception_EXIT_FUNC_431);
	current_point_bit_vector[2] |= 0x20; /* On:  #69*/
}

static void Point_67() {
	_integer(&ID_Signal_end_compute_sink_89,0);
	EMIT(SIG_ID_Signal_end_compute_sink_89);
	EMIT(SIG_ID_Exception_EXIT_FUNC_431);
	current_point_bit_vector[2] |= 0x20; /* On:  #69*/
}

static void Point_68() {
	_integer(&ID_Signal_end_compute_sink_89,ID_Variable_not_complete_flag_428);
	EMIT(SIG_ID_Signal_end_compute_sink_89);
	current_point_bit_vector[2] |= 0x20; /* On:  #69*/
}

static void Point_69() {
	if (IS_SIGNAL(SIG_ID_Signal_mark_data_sink_74,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_413,ID_InputOutput_SINK_SRANGE_45);
		EMIT(SIG_ID_Signal_My_Sample_Range_413);
		_StrlSampleRange(&ID_Variable_testrange_414,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_415,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_416,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_417,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_418,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_419,0);
		_integer(&ID_Variable_Flag_420,0);
		_integer(&ID_Variable_dataMarkedUpstream_421,0);
		_integer(&ID_Variable_dataNotReadyUpstream_422,0);
		_integer(&ID_Variable_temp_int_423,0);
		_StrlSampleIndex(&ID_Variable_temp_index_424,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_425,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_426);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_415,ID_Signal_My_Sample_Range_413);
		_StrlSampleIndex(&ID_Variable_pendingWP_416,GETMARKEDWP(ID_Output_Sink_module_57));
		_StrlSampleIndex(&ID_Variable_desiredWP_417,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_415));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_417, GETWP(ID_Output_Sink_module_57)) <= 0)) {
			LOCALINCAWAITTICK(ID_Output_Sink_module_57);
			next_point_bit_vector[1] |= 0x10000000; /* PauseOn:  #60*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_416, GETINDEX(ID_Variable_MY_Sample_Range_415)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_418,CHKMINRP(ID_Variable_pendingWP_416, ID_Variable_MY_Sample_Range_415, ID_Output_Sink_module_57));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_418, INITIAL_INDEX) <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Sink_module_57);
					next_point_bit_vector[1] |= 0x20000000; /* PauseOn:  #61*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_416,ID_Variable_tempWP_418);
					goto L449;
				}
			} else {
L449:
				_integer(&ID_Variable_requestSize_419,SUBTRACT_A_B(ID_Variable_desiredWP_417, ID_Variable_pendingWP_416));
				if ((ID_Variable_requestSize_419 <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Sink_module_57);
					next_point_bit_vector[1] |= 0x40000000; /* PauseOn:  #62*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_425,GET_OUTPUTSIZE(ID_Output_Sink_module_57));
					_integer(&ID_Variable_requestSize_419,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_419, ID_Variable_temp_unsigned_425));
					_StrlSampleRange(&ID_Variable_testrange_414,SET_SAMPLERANGE(ID_Variable_pendingWP_416, ID_Variable_requestSize_419));
					_StrlSampleRange(&ID_InputOutput_SUMMER_SRANGE_43,FORECASTS(ID_Variable_testrange_414, ID_Output_Sink_module_57));
					PERF_STRL1_O_SUMMER_SRANGE(ID_InputOutput_SUMMER_SRANGE_43); EMIT(SIG_ID_InputOutput_SUMMER_SRANGE_43);
					EMIT(SIG_ID_Signal_sig_port_1_76);
					current_point_bit_vector[3] |= 0x8000000; /* On:  #123*/
					next_point_bit_vector[1] |= 0x1000000; /* PauseOn:  #56*/
				}
			}
		}
	} else {
		next_point_bit_vector[1] |= 0x800000; /* PauseOn:  #55*/
	}
}

static void Point_70() {
	if (IS_SIGNAL(SIG_ID_Signal_end_compute_sink_89,0)) {
		RUN_GUI_MAIN();
		_StrlSampleIndex(&ID_Variable_WP_SCOPESINK_97,GETMARKEDWP(ID_Variable_nameofscopesink_94));
		_StrlSampleIndex(&ID_Variable_WP_SINK_96,GETMARKEDWP(ID_Variable_nameofsink_95));
		next_point_bit_vector[0] |= 0x4; /* PauseOn:  #2*/
	} else {
		next_point_bit_vector[2] |= 0x100; /* PauseOn:  #72*/
	}
}

static void Point_71() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_1_76,0)) {
		EMIT(SIG_ID_Signal_broadcast_on_392);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_391,ID_InputOutput_SUMMER_SRANGE_43);
		EMIT(SIG_ID_Signal_My_Sample_Range_391);
		_StrlSampleRange(&ID_Variable_testrange_394,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_395,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_396,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_397,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_398,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_399,0);
		_integer(&ID_Variable_Flag_400,0);
		_integer(&ID_Variable_dataMarkedUpstream_401,0);
		_integer(&ID_Variable_dataNotReadyUpstream_402,0);
		_integer(&ID_Variable_temp_int_403,0);
		_StrlSampleIndex(&ID_Variable_temp_index_404,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_405,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_406);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_395,ID_Signal_My_Sample_Range_391);
		_StrlSampleIndex(&ID_Variable_pendingWP_396,GETMARKEDWP(ID_Output_Summer_module_55));
		_StrlSampleIndex(&ID_Variable_desiredWP_397,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_395));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_397, GETWP(ID_Output_Summer_module_55)) <= 0)) {
			LOCALINCAWAITTICK(ID_Output_Summer_module_55);
			next_point_bit_vector[1] |= 0x4000; /* PauseOn:  #46*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_396, GETINDEX(ID_Variable_MY_Sample_Range_395)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_398,CHKMINRP(ID_Variable_pendingWP_396, ID_Variable_MY_Sample_Range_395, ID_Output_Summer_module_55));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_398, INITIAL_INDEX) <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Summer_module_55);
					next_point_bit_vector[1] |= 0x8000; /* PauseOn:  #47*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_396,ID_Variable_tempWP_398);
					goto L491;
				}
			} else {
L491:
				_integer(&ID_Variable_requestSize_399,SUBTRACT_A_B(ID_Variable_desiredWP_397, ID_Variable_pendingWP_396));
				if ((ID_Variable_requestSize_399 <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Summer_module_55);
					next_point_bit_vector[1] |= 0x10000; /* PauseOn:  #48*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_405,GET_OUTPUTSIZE(ID_Output_Summer_module_55));
					_integer(&ID_Variable_requestSize_399,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_399, ID_Variable_temp_unsigned_405));
					_StrlSampleRange(&ID_Variable_testrange_394,SET_SAMPLERANGE(ID_Variable_pendingWP_396, ID_Variable_requestSize_399));
					_StrlSampleRange(&ID_InputOutput_MOD_SRANGE_42,FORECASTS(ID_Variable_testrange_394, ID_Output_Summer_module_55));
					PERF_STRL1_O_MOD_SRANGE(ID_InputOutput_MOD_SRANGE_42); EMIT(SIG_ID_InputOutput_MOD_SRANGE_42);
					EMIT(SIG_ID_Signal_sig_port_2_77);
					current_point_bit_vector[3] |= 0x4000000; /* On:  #122*/
					next_point_bit_vector[2] |= 0x400; /* PauseOn:  #74*/
				}
			}
		}
	} else {
		next_point_bit_vector[2] |= 0x200; /* PauseOn:  #73*/
	}
}

static void Point_72() {
	if (IS_SIGNAL(SIG_ID_Signal_end_compute_sink_89,0)) {
		RUN_GUI_MAIN();
		_StrlSampleIndex(&ID_Variable_WP_SCOPESINK_97,GETMARKEDWP(ID_Variable_nameofscopesink_94));
		_StrlSampleIndex(&ID_Variable_WP_SINK_96,GETMARKEDWP(ID_Variable_nameofsink_95));
		next_point_bit_vector[0] |= 0x4; /* PauseOn:  #2*/
	} else {
		next_point_bit_vector[2] |= 0x100; /* PauseOn:  #72*/
	}
}

static void Point_73() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_1_76,0)) {
		EMIT(SIG_ID_Signal_broadcast_on_392);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_391,ID_InputOutput_SUMMER_SRANGE_43);
		EMIT(SIG_ID_Signal_My_Sample_Range_391);
		_StrlSampleRange(&ID_Variable_testrange_394,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_395,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_396,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_397,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_398,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_399,0);
		_integer(&ID_Variable_Flag_400,0);
		_integer(&ID_Variable_dataMarkedUpstream_401,0);
		_integer(&ID_Variable_dataNotReadyUpstream_402,0);
		_integer(&ID_Variable_temp_int_403,0);
		_StrlSampleIndex(&ID_Variable_temp_index_404,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_405,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_406);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_395,ID_Signal_My_Sample_Range_391);
		_StrlSampleIndex(&ID_Variable_pendingWP_396,GETMARKEDWP(ID_Output_Summer_module_55));
		_StrlSampleIndex(&ID_Variable_desiredWP_397,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_395));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_397, GETWP(ID_Output_Summer_module_55)) <= 0)) {
			current_point_bit_vector[2] |= 0x2000; /* On:  #77*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_396, GETINDEX(ID_Variable_MY_Sample_Range_395)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_398,CHKMINRP(ID_Variable_pendingWP_396, ID_Variable_MY_Sample_Range_395, ID_Output_Summer_module_55));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_398, INITIAL_INDEX) <= 0)) {
					current_point_bit_vector[2] |= 0x1000; /* On:  #76*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_396,ID_Variable_tempWP_398);
					goto L532;
				}
			} else {
L532:
				_integer(&ID_Variable_requestSize_399,SUBTRACT_A_B(ID_Variable_desiredWP_397, ID_Variable_pendingWP_396));
				if ((ID_Variable_requestSize_399 <= 0)) {
					current_point_bit_vector[2] |= 0x800; /* On:  #75*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_405,GET_OUTPUTSIZE(ID_Output_Summer_module_55));
					_integer(&ID_Variable_requestSize_399,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_399, ID_Variable_temp_unsigned_405));
					_StrlSampleRange(&ID_Variable_testrange_394,SET_SAMPLERANGE(ID_Variable_pendingWP_396, ID_Variable_requestSize_399));
					_StrlSampleRange(&ID_InputOutput_MOD_SRANGE_42,FORECASTS(ID_Variable_testrange_394, ID_Output_Summer_module_55));
					PERF_STRL1_O_MOD_SRANGE(ID_InputOutput_MOD_SRANGE_42); EMIT(SIG_ID_InputOutput_MOD_SRANGE_42);
					current_point_bit_vector[2] |= 0x400; current_point_bit_vector[3] |= 0x20000; /* On:  #74 #113*/
				}
			}
		}
	} else {
		next_point_bit_vector[2] |= 0x200; /* PauseOn:  #73*/
	}
}

static void Point_74() {
	EMIT(SIG_ID_Signal_sig_port_2_77);
	next_point_bit_vector[2] |= 0x400; /* PauseOn:  #74*/
}

static void Point_75() {
	LOCALINCAWAITTICK(ID_Output_Summer_module_55);
	next_point_bit_vector[1] |= 0x10000; /* PauseOn:  #48*/
}

static void Point_76() {
	LOCALINCAWAITTICK(ID_Output_Summer_module_55);
	next_point_bit_vector[1] |= 0x8000; /* PauseOn:  #47*/
}

static void Point_77() {
	LOCALINCAWAITTICK(ID_Output_Summer_module_55);
	next_point_bit_vector[1] |= 0x4000; /* PauseOn:  #46*/
}

static void Point_78() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_on_392,0)) {
		current_point_bit_vector[2] &= ~0x80400000; /* Off:  #86 #95*/
		next_point_bit_vector[2] |= 0x4000; /* PauseOn:  #78*/
		if (IS_SIGNAL(SIG_ID_Signal_sig_port_2_77,0)) {
		} else {
			current_point_bit_vector[2] |= 0x80000000; /* On:  #95*/
			next_point_bit_vector[2] |= 0x400000; /* PauseOn:  #86*/
		}
	} else {
		next_point_bit_vector[2] |= 0x4000; /* PauseOn:  #78*/
	}
}

static void Point_79() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_2_77,0)) {
		EMIT(SIG_ID_Signal_broadcast_on_350);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_349,ID_InputOutput_MOD_SRANGE_42);
		EMIT(SIG_ID_Signal_My_Sample_Range_349);
		_StrlSampleRange(&ID_Variable_testrange_352,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_353,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_354,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_355,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_356,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_357,0);
		_integer(&ID_Variable_Flag_358,0);
		_integer(&ID_Variable_dataMarkedUpstream_359,0);
		_integer(&ID_Variable_dataNotReadyUpstream_360,0);
		_integer(&ID_Variable_temp_int_361,0);
		_StrlSampleIndex(&ID_Variable_temp_index_362,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_363,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_364);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_353,ID_Signal_My_Sample_Range_349);
		_StrlSampleIndex(&ID_Variable_pendingWP_354,GETMARKEDWP(ID_Output_Mod_module_54));
		_StrlSampleIndex(&ID_Variable_desiredWP_355,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_353));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_355, GETWP(ID_Output_Mod_module_54)) <= 0)) {
			LOCALINCAWAITTICK(ID_Output_Mod_module_54);
			next_point_bit_vector[0] |= 0x400000; /* PauseOn:  #22*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_354, GETINDEX(ID_Variable_MY_Sample_Range_353)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_356,CHKMINRP(ID_Variable_pendingWP_354, ID_Variable_MY_Sample_Range_353, ID_Output_Mod_module_54));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_356, INITIAL_INDEX) <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Mod_module_54);
					next_point_bit_vector[0] |= 0x800000; /* PauseOn:  #23*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_354,ID_Variable_tempWP_356);
					goto L573;
				}
			} else {
L573:
				_integer(&ID_Variable_requestSize_357,SUBTRACT_A_B(ID_Variable_desiredWP_355, ID_Variable_pendingWP_354));
				if ((ID_Variable_requestSize_357 <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Mod_module_54);
					next_point_bit_vector[0] |= 0x1000000; /* PauseOn:  #24*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_363,GET_OUTPUTSIZE(ID_Output_Mod_module_54));
					_integer(&ID_Variable_requestSize_357,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_357, ID_Variable_temp_unsigned_363));
					_StrlSampleRange(&ID_Variable_testrange_352,SET_SAMPLERANGE(ID_Variable_pendingWP_354, ID_Variable_requestSize_357));
					_StrlSampleRange(&ID_InputOutput_CODER_SRANGE_41,FORECASTS(ID_Variable_testrange_352, ID_Output_Mod_module_54));
					PERF_STRL1_O_CODER_SRANGE(ID_InputOutput_CODER_SRANGE_41); EMIT(SIG_ID_InputOutput_CODER_SRANGE_41);
					EMIT(SIG_ID_Signal_sig_port_3_78);
					current_point_bit_vector[3] |= 0x40; /* On:  #102*/
					next_point_bit_vector[2] |= 0x20000; /* PauseOn:  #81*/
				}
			}
		}
	} else {
		next_point_bit_vector[2] |= 0x10000; /* PauseOn:  #80*/
	}
}

static void Point_80() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_2_77,0)) {
		EMIT(SIG_ID_Signal_broadcast_on_350);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_349,ID_InputOutput_MOD_SRANGE_42);
		EMIT(SIG_ID_Signal_My_Sample_Range_349);
		_StrlSampleRange(&ID_Variable_testrange_352,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_353,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_354,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_355,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_356,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_357,0);
		_integer(&ID_Variable_Flag_358,0);
		_integer(&ID_Variable_dataMarkedUpstream_359,0);
		_integer(&ID_Variable_dataNotReadyUpstream_360,0);
		_integer(&ID_Variable_temp_int_361,0);
		_StrlSampleIndex(&ID_Variable_temp_index_362,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_363,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_364);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_353,ID_Signal_My_Sample_Range_349);
		_StrlSampleIndex(&ID_Variable_pendingWP_354,GETMARKEDWP(ID_Output_Mod_module_54));
		_StrlSampleIndex(&ID_Variable_desiredWP_355,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_353));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_355, GETWP(ID_Output_Mod_module_54)) <= 0)) {
			current_point_bit_vector[2] |= 0x100000; /* On:  #84*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_354, GETINDEX(ID_Variable_MY_Sample_Range_353)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_356,CHKMINRP(ID_Variable_pendingWP_354, ID_Variable_MY_Sample_Range_353, ID_Output_Mod_module_54));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_356, INITIAL_INDEX) <= 0)) {
					current_point_bit_vector[2] |= 0x80000; /* On:  #83*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_354,ID_Variable_tempWP_356);
					goto L609;
				}
			} else {
L609:
				_integer(&ID_Variable_requestSize_357,SUBTRACT_A_B(ID_Variable_desiredWP_355, ID_Variable_pendingWP_354));
				if ((ID_Variable_requestSize_357 <= 0)) {
					current_point_bit_vector[2] |= 0x40000; /* On:  #82*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_363,GET_OUTPUTSIZE(ID_Output_Mod_module_54));
					_integer(&ID_Variable_requestSize_357,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_357, ID_Variable_temp_unsigned_363));
					_StrlSampleRange(&ID_Variable_testrange_352,SET_SAMPLERANGE(ID_Variable_pendingWP_354, ID_Variable_requestSize_357));
					_StrlSampleRange(&ID_InputOutput_CODER_SRANGE_41,FORECASTS(ID_Variable_testrange_352, ID_Output_Mod_module_54));
					PERF_STRL1_O_CODER_SRANGE(ID_InputOutput_CODER_SRANGE_41); EMIT(SIG_ID_InputOutput_CODER_SRANGE_41);
					current_point_bit_vector[2] |= 0x20000; current_point_bit_vector[3] |= 0x100; /* On:  #81 #104*/
				}
			}
		}
	} else {
		next_point_bit_vector[2] |= 0x10000; /* PauseOn:  #80*/
	}
}

static void Point_81() {
	EMIT(SIG_ID_Signal_sig_port_3_78);
	next_point_bit_vector[2] |= 0x20000; /* PauseOn:  #81*/
}

static void Point_82() {
	LOCALINCAWAITTICK(ID_Output_Mod_module_54);
	next_point_bit_vector[0] |= 0x1000000; /* PauseOn:  #24*/
}

static void Point_83() {
	LOCALINCAWAITTICK(ID_Output_Mod_module_54);
	next_point_bit_vector[0] |= 0x800000; /* PauseOn:  #23*/
}

static void Point_84() {
	LOCALINCAWAITTICK(ID_Output_Mod_module_54);
	next_point_bit_vector[0] |= 0x400000; /* PauseOn:  #22*/
}

static void Point_85() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_on_350,0)) {
		current_point_bit_vector[2] &= ~0x40000000; current_point_bit_vector[3] &= ~0x10; /* Off:  #94 #100*/
		next_point_bit_vector[2] |= 0x200000; /* PauseOn:  #85*/
		if (IS_SIGNAL(SIG_ID_Signal_sig_port_3_78,0)) {
		} else {
			current_point_bit_vector[3] |= 0x10; /* On:  #100*/
			next_point_bit_vector[2] |= 0x40000000; /* PauseOn:  #94*/
		}
	} else {
		next_point_bit_vector[2] |= 0x200000; /* PauseOn:  #85*/
	}
}

static void Point_86() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_2_77,0)) {
		current_point_bit_vector[2] &= ~0x80000000; /* Off:  #95*/
	} else {
		next_point_bit_vector[2] |= 0x400000; /* PauseOn:  #86*/
	}
}

static void Point_87() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_3_78,0)) {
		EMIT(SIG_ID_Signal_broadcast_on_327);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_326,ID_InputOutput_CODER_SRANGE_41);
		EMIT(SIG_ID_Signal_My_Sample_Range_326);
		_StrlSampleRange(&ID_Variable_testrange_330,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_331,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_332,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_333,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_334,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_335,0);
		_integer(&ID_Variable_Flag_336,0);
		_integer(&ID_Variable_dataMarkedUpstream_337,0);
		_integer(&ID_Variable_dataNotReadyUpstream_338,0);
		_integer(&ID_Variable_temp_int_339,0);
		_StrlSampleIndex(&ID_Variable_temp_index_340,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_341,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_342);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_331,ID_Signal_My_Sample_Range_326);
		_StrlSampleIndex(&ID_Variable_pendingWP_332,GETMARKEDWP(ID_Output_Coder_module_53));
		_StrlSampleIndex(&ID_Variable_desiredWP_333,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_331));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_333, GETWP(ID_Output_Coder_module_53)) <= 0)) {
			LOCALINCAWAITTICK(ID_Output_Coder_module_53);
			next_point_bit_vector[0] |= 0x2000; /* PauseOn:  #13*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_332, GETINDEX(ID_Variable_MY_Sample_Range_331)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_334,CHKMINRP(ID_Variable_pendingWP_332, ID_Variable_MY_Sample_Range_331, ID_Output_Coder_module_53));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_334, INITIAL_INDEX) <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Coder_module_53);
					next_point_bit_vector[0] |= 0x4000; /* PauseOn:  #14*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_332,ID_Variable_tempWP_334);
					goto L652;
				}
			} else {
L652:
				_integer(&ID_Variable_requestSize_335,SUBTRACT_A_B(ID_Variable_desiredWP_333, ID_Variable_pendingWP_332));
				if ((ID_Variable_requestSize_335 <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Coder_module_53);
					next_point_bit_vector[0] |= 0x8000; /* PauseOn:  #15*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_341,GET_OUTPUTSIZE(ID_Output_Coder_module_53));
					_integer(&ID_Variable_requestSize_335,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_335, ID_Variable_temp_unsigned_341));
					_StrlSampleRange(&ID_Variable_testrange_330,SET_SAMPLERANGE(ID_Variable_pendingWP_332, ID_Variable_requestSize_335));
					_StrlSampleRange(&ID_InputOutput_SOURCE_SRANGE_40,FORECASTS(ID_Variable_testrange_330, ID_Output_Coder_module_53));
					PERF_STRL1_O_SOURCE_SRANGE(ID_InputOutput_SOURCE_SRANGE_40); EMIT(SIG_ID_InputOutput_SOURCE_SRANGE_40);
					EMIT(SIG_ID_Signal_sig_port_4_79);
					current_point_bit_vector[3] |= 0x20; /* On:  #101*/
					next_point_bit_vector[2] |= 0x2000000; /* PauseOn:  #89*/
				}
			}
		}
	} else {
		next_point_bit_vector[2] |= 0x1000000; /* PauseOn:  #88*/
	}
}

static void Point_88() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_3_78,0)) {
		EMIT(SIG_ID_Signal_broadcast_on_327);
		_StrlSampleRange(&ID_Signal_My_Sample_Range_326,ID_InputOutput_CODER_SRANGE_41);
		EMIT(SIG_ID_Signal_My_Sample_Range_326);
		_StrlSampleRange(&ID_Variable_testrange_330,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_331,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_332,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_333,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_tempWP_334,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_335,0);
		_integer(&ID_Variable_Flag_336,0);
		_integer(&ID_Variable_dataMarkedUpstream_337,0);
		_integer(&ID_Variable_dataNotReadyUpstream_338,0);
		_integer(&ID_Variable_temp_int_339,0);
		_StrlSampleIndex(&ID_Variable_temp_index_340,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_341,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_342);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_331,ID_Signal_My_Sample_Range_326);
		_StrlSampleIndex(&ID_Variable_pendingWP_332,GETMARKEDWP(ID_Output_Coder_module_53));
		_StrlSampleIndex(&ID_Variable_desiredWP_333,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_331));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_333, GETWP(ID_Output_Coder_module_53)) <= 0)) {
			current_point_bit_vector[2] |= 0x10000000; /* On:  #92*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_332, GETINDEX(ID_Variable_MY_Sample_Range_331)) < 0)) {
				_StrlSampleIndex(&ID_Variable_tempWP_334,CHKMINRP(ID_Variable_pendingWP_332, ID_Variable_MY_Sample_Range_331, ID_Output_Coder_module_53));
				if ((CMPSAMPLEINDEX(ID_Variable_tempWP_334, INITIAL_INDEX) <= 0)) {
					current_point_bit_vector[2] |= 0x8000000; /* On:  #91*/
				} else {
					_StrlSampleIndex(&ID_Variable_pendingWP_332,ID_Variable_tempWP_334);
					goto L688;
				}
			} else {
L688:
				_integer(&ID_Variable_requestSize_335,SUBTRACT_A_B(ID_Variable_desiredWP_333, ID_Variable_pendingWP_332));
				if ((ID_Variable_requestSize_335 <= 0)) {
					current_point_bit_vector[2] |= 0x4000000; /* On:  #90*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_341,GET_OUTPUTSIZE(ID_Output_Coder_module_53));
					_integer(&ID_Variable_requestSize_335,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_335, ID_Variable_temp_unsigned_341));
					_StrlSampleRange(&ID_Variable_testrange_330,SET_SAMPLERANGE(ID_Variable_pendingWP_332, ID_Variable_requestSize_335));
					_StrlSampleRange(&ID_InputOutput_SOURCE_SRANGE_40,FORECASTS(ID_Variable_testrange_330, ID_Output_Coder_module_53));
					PERF_STRL1_O_SOURCE_SRANGE(ID_InputOutput_SOURCE_SRANGE_40); EMIT(SIG_ID_InputOutput_SOURCE_SRANGE_40);
					current_point_bit_vector[2] |= 0x2000000; current_point_bit_vector[3] |= 0x4; /* On:  #89 #98*/
				}
			}
		}
	} else {
		next_point_bit_vector[2] |= 0x1000000; /* PauseOn:  #88*/
	}
}

static void Point_89() {
	EMIT(SIG_ID_Signal_sig_port_4_79);
	next_point_bit_vector[2] |= 0x2000000; /* PauseOn:  #89*/
}

static void Point_90() {
	LOCALINCAWAITTICK(ID_Output_Coder_module_53);
	next_point_bit_vector[0] |= 0x8000; /* PauseOn:  #15*/
}

static void Point_91() {
	LOCALINCAWAITTICK(ID_Output_Coder_module_53);
	next_point_bit_vector[0] |= 0x4000; /* PauseOn:  #14*/
}

static void Point_92() {
	LOCALINCAWAITTICK(ID_Output_Coder_module_53);
	next_point_bit_vector[0] |= 0x2000; /* PauseOn:  #13*/
}

static void Point_93() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_on_327,0)) {
		current_point_bit_vector[3] &= ~0x88; /* Off:  #99 #103*/
		next_point_bit_vector[2] |= 0x20000000; /* PauseOn:  #93*/
		if (IS_SIGNAL(SIG_ID_Signal_sig_port_4_79,0)) {
		} else {
			current_point_bit_vector[3] |= 0x80; /* On:  #103*/
			next_point_bit_vector[3] |= 0x8; /* PauseOn:  #99*/
		}
	} else {
		next_point_bit_vector[2] |= 0x20000000; /* PauseOn:  #93*/
	}
}

static void Point_94() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_3_78,0)) {
		current_point_bit_vector[3] &= ~0x10; /* Off:  #100*/
	} else {
		next_point_bit_vector[2] |= 0x40000000; /* PauseOn:  #94*/
	}
}

static void Point_95() {
	EMIT(SIG_ID_Signal_b_on_393);
	next_point_bit_vector[2] |= 0x80000000; /* PauseOn:  #95*/
}

static void Point_96() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_4_79,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_281,ID_InputOutput_SOURCE_SRANGE_40);
		EMIT(SIG_ID_Signal_My_Sample_Range_281);
		_StrlSampleRange(&ID_Variable_testrange_298,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_299,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_300,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_301,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_302,0);
		_integer(&ID_Variable_Flag_303,0);
		_integer(&ID_Variable_dataMarkedUpstream_304,0);
		_integer(&ID_Variable_dataNotReadyUpstream_305,0);
		_integer(&ID_Variable_temp_int_306,0);
		_StrlSampleIndex(&ID_Variable_temp_index_307,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_308,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_309);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_299,ID_Signal_My_Sample_Range_281);
		_StrlSampleIndex(&ID_Variable_pendingWP_300,GETMARKEDWP(ID_Output_Source_module_52));
		_StrlSampleIndex(&ID_Variable_desiredWP_301,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_299));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_301, GETWP(ID_Output_Source_module_52)) <= 0)) {
			LOCALINCAWAITTICK(ID_Output_Source_module_52);
			next_point_bit_vector[0] |= 0x8; /* PauseOn:  #3*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_300, GETINDEX(ID_Variable_MY_Sample_Range_299)) < 0)) {
				LOCALINCAWAITTICK(ID_Output_Source_module_52);
				next_point_bit_vector[0] |= 0x10; /* PauseOn:  #4*/
			} else {
				_integer(&ID_Variable_requestSize_302,SUBTRACT_A_B(ID_Variable_desiredWP_301, ID_Variable_pendingWP_300));
				if ((ID_Variable_requestSize_302 <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Source_module_52);
					next_point_bit_vector[0] |= 0x20; /* PauseOn:  #5*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_308,GET_OUTPUTSIZE(ID_Output_Source_module_52));
					_integer(&ID_Variable_requestSize_302,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_302, ID_Variable_temp_unsigned_308));
					_StrlSampleRange(&ID_Variable_testrange_298,SET_SAMPLERANGE(ID_Variable_pendingWP_300, ID_Variable_requestSize_302));
					if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_305,0))) {
						LOCALINCAWAITTICK(ID_Output_Source_module_52);
						next_point_bit_vector[0] |= 0x40; /* PauseOn:  #6*/
					} else {
						_integer(&ID_Variable_temp_int_306,REAL_MARK_DATA(ID_Variable_pendingWP_300, ID_Variable_requestSize_302, ID_Variable_dataMarkedUpstream_304, INITIAL_RANGE, ID_Output_Source_module_52));
						_integer(&ID_Signal_ret_port_4_80,ID_Variable_temp_int_306);
						EMIT(SIG_ID_Signal_ret_port_4_80);
						current_point_bit_vector[4] |= 0x1; /* On:  #128*/
					}
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x2; /* PauseOn:  #97*/
	}
}

static void Point_97() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_4_79,0)) {
		_StrlSampleRange(&ID_Signal_My_Sample_Range_281,ID_InputOutput_SOURCE_SRANGE_40);
		EMIT(SIG_ID_Signal_My_Sample_Range_281);
		_StrlSampleRange(&ID_Variable_testrange_298,INITIAL_RANGE);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_299,INITIAL_RANGE);
		_StrlSampleIndex(&ID_Variable_pendingWP_300,INITIAL_INDEX);
		_StrlSampleIndex(&ID_Variable_desiredWP_301,INITIAL_INDEX);
		_integer(&ID_Variable_requestSize_302,0);
		_integer(&ID_Variable_Flag_303,0);
		_integer(&ID_Variable_dataMarkedUpstream_304,0);
		_integer(&ID_Variable_dataNotReadyUpstream_305,0);
		_integer(&ID_Variable_temp_int_306,0);
		_StrlSampleIndex(&ID_Variable_temp_index_307,INITIAL_INDEX);
		_UnsignedInt(&ID_Variable_temp_unsigned_308,INITIAL_UNSIGNEDINT);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_309);
		_StrlSampleRange(&ID_Variable_MY_Sample_Range_299,ID_Signal_My_Sample_Range_281);
		_StrlSampleIndex(&ID_Variable_pendingWP_300,GETMARKEDWP(ID_Output_Source_module_52));
		_StrlSampleIndex(&ID_Variable_desiredWP_301,ADD_INDEX_SIZE(ID_Variable_MY_Sample_Range_299));
		if ((CMPSAMPLEINDEX1(ID_Variable_desiredWP_301, GETWP(ID_Output_Source_module_52)) <= 0)) {
			LOCALINCAWAITTICK(ID_Output_Source_module_52);
			next_point_bit_vector[0] |= 0x8; /* PauseOn:  #3*/
		} else {
			if ((CMPSAMPLEINDEX(ID_Variable_pendingWP_300, GETINDEX(ID_Variable_MY_Sample_Range_299)) < 0)) {
				LOCALINCAWAITTICK(ID_Output_Source_module_52);
				next_point_bit_vector[0] |= 0x10; /* PauseOn:  #4*/
			} else {
				_integer(&ID_Variable_requestSize_302,SUBTRACT_A_B(ID_Variable_desiredWP_301, ID_Variable_pendingWP_300));
				if ((ID_Variable_requestSize_302 <= 0)) {
					LOCALINCAWAITTICK(ID_Output_Source_module_52);
					next_point_bit_vector[0] |= 0x20; /* PauseOn:  #5*/
				} else {
					_UnsignedInt(&ID_Variable_temp_unsigned_308,GET_OUTPUTSIZE(ID_Output_Source_module_52));
					_integer(&ID_Variable_requestSize_302,ROUNDUP_REQUESTSIZE(ID_Variable_requestSize_302, ID_Variable_temp_unsigned_308));
					_StrlSampleRange(&ID_Variable_testrange_298,SET_SAMPLERANGE(ID_Variable_pendingWP_300, ID_Variable_requestSize_302));
					if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_305,0))) {
						LOCALINCAWAITTICK(ID_Output_Source_module_52);
						next_point_bit_vector[0] |= 0x40; /* PauseOn:  #6*/
					} else {
						_integer(&ID_Variable_temp_int_306,REAL_MARK_DATA(ID_Variable_pendingWP_300, ID_Variable_requestSize_302, ID_Variable_dataMarkedUpstream_304, INITIAL_RANGE, ID_Output_Source_module_52));
						_integer(&ID_Signal_ret_port_4_80,ID_Variable_temp_int_306);
						EMIT(SIG_ID_Signal_ret_port_4_80);
						current_point_bit_vector[4] |= 0x80; /* On:  #135*/
					}
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x2; /* PauseOn:  #97*/
	}
}

static void Point_98() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_4_80,0)) {
		_integer(&ID_Variable_Flag_336,ID_Signal_ret_port_4_80);
		next_point_bit_vector[2] &= ~0x2000000; /* PauseOff:  #89*/
		if (_eq_integer(ID_Variable_Flag_336,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_338,0))) {
				LOCALINCAWAITTICK(ID_Output_Coder_module_53);
				next_point_bit_vector[0] |= 0x10000; /* PauseOn:  #16*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_337,1);
				goto L786;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_336,0)) {
				LOCALINCAWAITTICK(ID_Output_Coder_module_53);
				next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
			} else {
				if (_eq_integer(ID_Variable_Flag_336,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_338,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_336,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_338,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_338,-2);
						}
					}
				}
L786:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_338,0))) {
					LOCALINCAWAITTICK(ID_Output_Coder_module_53);
					next_point_bit_vector[0] |= 0x40000; /* PauseOn:  #18*/
				} else {
					_integer(&ID_Variable_temp_int_339,REAL_MARK_DATA(ID_Variable_pendingWP_332, ID_Variable_requestSize_335, ID_Variable_dataMarkedUpstream_337, ID_InputOutput_SOURCE_SRANGE_40, ID_Output_Coder_module_53));
					LOCALINCAWAITTICK(ID_Output_Coder_module_53);
					_integer(&ID_Signal_ret_port_3_81,ID_Variable_temp_int_339);
					EMIT(SIG_ID_Signal_ret_port_3_81);
					current_point_bit_vector[3] |= 0x400000; /* On:  #118*/
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x4; /* PauseOn:  #98*/
	}
}

static void Point_99() {
	if (IS_SIGNAL(SIG_ID_Signal_sig_port_4_79,0)) {
		current_point_bit_vector[3] &= ~0x80; /* Off:  #103*/
	} else {
		next_point_bit_vector[3] |= 0x8; /* PauseOn:  #99*/
	}
}

static void Point_100() {
	EMIT(SIG_ID_Signal_b_on_351);
	next_point_bit_vector[3] |= 0x10; /* PauseOn:  #100*/
}

static void Point_101() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_4_80,0)) {
		_integer(&ID_Variable_Flag_336,ID_Signal_ret_port_4_80);
		next_point_bit_vector[2] &= ~0x2000000; /* PauseOff:  #89*/
		if (_eq_integer(ID_Variable_Flag_336,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_338,0))) {
				LOCALINCAWAITTICK(ID_Output_Coder_module_53);
				next_point_bit_vector[0] |= 0x10000; /* PauseOn:  #16*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_337,1);
				goto L810;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_336,0)) {
				LOCALINCAWAITTICK(ID_Output_Coder_module_53);
				next_point_bit_vector[0] |= 0x20000; /* PauseOn:  #17*/
			} else {
				if (_eq_integer(ID_Variable_Flag_336,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_338,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_336,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_338,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_338,-2);
						}
					}
				}
L810:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_338,0))) {
					LOCALINCAWAITTICK(ID_Output_Coder_module_53);
					next_point_bit_vector[0] |= 0x40000; /* PauseOn:  #18*/
				} else {
					_integer(&ID_Variable_temp_int_339,REAL_MARK_DATA(ID_Variable_pendingWP_332, ID_Variable_requestSize_335, ID_Variable_dataMarkedUpstream_337, ID_InputOutput_SOURCE_SRANGE_40, ID_Output_Coder_module_53));
					LOCALINCAWAITTICK(ID_Output_Coder_module_53);
					_integer(&ID_Signal_ret_port_3_81,ID_Variable_temp_int_339);
					EMIT(SIG_ID_Signal_ret_port_3_81);
					current_point_bit_vector[3] |= 0x1000000; /* On:  #120*/
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x4; /* PauseOn:  #98*/
	}
}

static void Point_102() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_3_81,0)) {
		_integer(&ID_Variable_Flag_358,ID_Signal_ret_port_3_81);
		next_point_bit_vector[2] &= ~0x20000; /* PauseOff:  #81*/
		if (_eq_integer(ID_Variable_Flag_358,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_360,0))) {
				LOCALINCAWAITTICK(ID_Output_Mod_module_54);
				next_point_bit_vector[0] |= 0x2000000; /* PauseOn:  #25*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_359,1);
				goto L830;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_358,0)) {
				LOCALINCAWAITTICK(ID_Output_Mod_module_54);
				next_point_bit_vector[0] |= 0x4000000; /* PauseOn:  #26*/
			} else {
				if (_eq_integer(ID_Variable_Flag_358,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_360,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_358,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_360,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_360,-2);
						}
					}
				}
L830:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_360,0))) {
					LOCALINCAWAITTICK(ID_Output_Mod_module_54);
					next_point_bit_vector[0] |= 0x8000000; /* PauseOn:  #27*/
				} else {
					_integer(&ID_Variable_temp_int_361,REAL_MARK_DATA(ID_Variable_pendingWP_354, ID_Variable_requestSize_357, ID_Variable_dataMarkedUpstream_359, ID_InputOutput_CODER_SRANGE_41, ID_Output_Mod_module_54));
					LOCALINCAWAITTICK(ID_Output_Mod_module_54);
					_integer(&ID_Signal_ret_port_2_82,ID_Variable_temp_int_361);
					EMIT(SIG_ID_Signal_ret_port_2_82);
					if (IS_SIGNAL(SIG_ID_Signal_b_on_351,0)) {
						current_point_bit_vector[4] |= 0x8; /* On:  #131*/
					} else {
						if (IS_SIGNAL(SIG_ID_Signal_ret_port_c3_85,0)) {
							current_point_bit_vector[4] |= 0x10; /* On:  #132*/
						} else {
							next_point_bit_vector[3] |= 0x400; /* PauseOn:  #106*/
						}
					}
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x100; /* PauseOn:  #104*/
	}
}

static void Point_103() {
	EMIT(SIG_ID_Signal_b_on_328);
	next_point_bit_vector[3] |= 0x80; /* PauseOn:  #103*/
}

static void Point_104() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_3_81,0)) {
		_integer(&ID_Variable_Flag_358,ID_Signal_ret_port_3_81);
		next_point_bit_vector[2] &= ~0x20000; /* PauseOff:  #81*/
		if (_eq_integer(ID_Variable_Flag_358,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_360,0))) {
				current_point_bit_vector[3] |= 0x1000; /* On:  #108*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_359,1);
				goto L852;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_358,0)) {
				LOCALINCAWAITTICK(ID_Output_Mod_module_54);
				next_point_bit_vector[0] |= 0x4000000; /* PauseOn:  #26*/
			} else {
				if (_eq_integer(ID_Variable_Flag_358,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_360,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_358,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_360,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_360,-2);
						}
					}
				}
L852:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_360,0))) {
					current_point_bit_vector[3] |= 0x800; /* On:  #107*/
				} else {
					_integer(&ID_Variable_temp_int_361,REAL_MARK_DATA(ID_Variable_pendingWP_354, ID_Variable_requestSize_357, ID_Variable_dataMarkedUpstream_359, ID_InputOutput_CODER_SRANGE_41, ID_Output_Mod_module_54));
					LOCALINCAWAITTICK(ID_Output_Mod_module_54);
					_integer(&ID_Signal_ret_port_2_82,ID_Variable_temp_int_361);
					EMIT(SIG_ID_Signal_ret_port_2_82);
					current_point_bit_vector[3] |= 0x200; /* On:  #105*/
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x100; /* PauseOn:  #104*/
	}
}

static void Point_105() {
	if (IS_SIGNAL(SIG_ID_Signal_b_on_351,0)) {
		current_point_bit_vector[4] |= 0x400; /* On:  #138*/
	} else {
		current_point_bit_vector[3] |= 0x400; /* On:  #106*/
	}
}

static void Point_106() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_c3_85,0)) {
		current_point_bit_vector[4] |= 0x800; /* On:  #139*/
	} else {
		next_point_bit_vector[3] |= 0x400; /* PauseOn:  #106*/
	}
}

static void Point_107() {
	LOCALINCAWAITTICK(ID_Output_Mod_module_54);
	next_point_bit_vector[0] |= 0x8000000; /* PauseOn:  #27*/
}

static void Point_108() {
	LOCALINCAWAITTICK(ID_Output_Mod_module_54);
	next_point_bit_vector[0] |= 0x2000000; /* PauseOn:  #25*/
}

static void Point_109() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_2_82,0)) {
		_integer(&ID_Variable_Flag_378,ID_Signal_ret_port_2_82);
		next_point_bit_vector[1] &= ~0x1; /* PauseOff:  #32*/
		if (_eq_integer(ID_Variable_Flag_378,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_380,0))) {
				current_point_bit_vector[3] |= 0x10000; /* On:  #112*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_379,1);
				goto L876;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_378,0)) {
				LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
				next_point_bit_vector[1] |= 0x100; /* PauseOn:  #40*/
			} else {
				if (_eq_integer(ID_Variable_Flag_378,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_380,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_378,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_380,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_380,-2);
						}
					}
				}
L876:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_380,0))) {
					current_point_bit_vector[3] |= 0x8000; /* On:  #111*/
				} else {
					_integer(&ID_Variable_temp_int_381,REAL_MARK_DATA(ID_Variable_pendingWP_374, ID_Variable_requestSize_377, ID_Variable_dataMarkedUpstream_379, ID_InputOutput_MOD_SRANGE_42, ID_Output_Scopesink_module_56));
					LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
					_integer(&ID_Signal_broadcast_compute_88,ID_Variable_temp_int_381);
					EMIT(SIG_ID_Signal_broadcast_compute_88);
					current_point_bit_vector[3] |= 0x4000; /* On:  #110*/
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x2000; /* PauseOn:  #109*/
	}
}

static void Point_110() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_c2_86,0)) {
		_integer(&ID_Variable_not_source_385,0);
		_integer(&ID_Variable_not_complete_flag_386,0);
		_StrlSampleIndex(&ID_Variable_temp_index_387,INITIAL_INDEX);
		_StrlSampleSize(&ID_Variable_complete_var_388,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_389);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_390);
		if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Scopesink_module_56),0)) {
			LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
			next_point_bit_vector[1] |= 0x400; /* PauseOn:  #42*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Scopesink_module_56),0)) {
				LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
				next_point_bit_vector[1] |= 0x800; /* PauseOn:  #43*/
			} else {
				_integer(&ID_Variable_not_source_385,1);
				_StrlSampleSize(&ID_Variable_complete_var_388,REALCOMPUTEDATA(ID_Output_Scopesink_module_56, ID_Variable_not_source_385));
				if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Scopesink_module_56), ID_Variable_complete_var_388) > 0)) {
					_integer(&ID_Variable_not_complete_flag_386,(ID_Variable_not_complete_flag_386 - 1));
				}
				if ((ID_Variable_not_complete_flag_386 < 0)) {
					_StrlSampleIndex(&ID_Variable_temp_index_387,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Scopesink_module_56), ID_Variable_complete_var_388));
					SET_MARKEDWP(ID_Output_Scopesink_module_56, ID_Variable_temp_index_387);
				}
				WRITEDATA(ID_Output_Scopesink_module_56, ID_Variable_not_source_385);
				_StrlSampleIndex(&ID_Variable_temp_index_387,GETWP(ID_Output_Scopesink_module_56));
				_StrlSampleRange(&ID_InputOutput_SCOPESINK_MYMARKEDDATA_50,GET_MYMARKEDDATA(ID_Output_Scopesink_module_56));
				PERF_STRL1_O_SCOPESINK_MYMARKEDDATA(ID_InputOutput_SCOPESINK_MYMARKEDDATA_50); EMIT(SIG_ID_InputOutput_SCOPESINK_MYMARKEDDATA_50);
				LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
				next_point_bit_vector[1] |= 0x1000; /* PauseOn:  #44*/
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x4000; /* PauseOn:  #110*/
	}
}

static void Point_111() {
	LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
	next_point_bit_vector[1] |= 0x200; /* PauseOn:  #41*/
}

static void Point_112() {
	LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
	next_point_bit_vector[1] |= 0x80; /* PauseOn:  #39*/
}

static void Point_113() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_2_82,0)) {
		_integer(&ID_Variable_Flag_400,ID_Signal_ret_port_2_82);
		next_point_bit_vector[2] &= ~0x400; /* PauseOff:  #74*/
		if (_eq_integer(ID_Variable_Flag_400,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_402,0))) {
				current_point_bit_vector[3] |= 0x200000; /* On:  #117*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_401,1);
				goto L920;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_400,0)) {
				LOCALINCAWAITTICK(ID_Output_Summer_module_55);
				next_point_bit_vector[1] |= 0x40000; /* PauseOn:  #50*/
			} else {
				if (_eq_integer(ID_Variable_Flag_400,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_402,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_400,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_402,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_402,-2);
						}
					}
				}
L920:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_402,0))) {
					current_point_bit_vector[3] |= 0x100000; /* On:  #116*/
				} else {
					_integer(&ID_Variable_temp_int_403,REAL_MARK_DATA(ID_Variable_pendingWP_396, ID_Variable_requestSize_399, ID_Variable_dataMarkedUpstream_401, ID_InputOutput_MOD_SRANGE_42, ID_Output_Summer_module_55));
					LOCALINCAWAITTICK(ID_Output_Summer_module_55);
					_integer(&ID_Signal_ret_port_1_83,ID_Variable_temp_int_403);
					EMIT(SIG_ID_Signal_ret_port_1_83);
					current_point_bit_vector[3] |= 0x40000; /* On:  #114*/
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x20000; /* PauseOn:  #113*/
	}
}

static void Point_114() {
	if (IS_SIGNAL(SIG_ID_Signal_b_on_393,0)) {
		current_point_bit_vector[4] |= 0x1000; /* On:  #140*/
	} else {
		current_point_bit_vector[3] |= 0x80000; /* On:  #115*/
	}
}

static void Point_115() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_c2_86,0)) {
		current_point_bit_vector[4] |= 0x2000; /* On:  #141*/
	} else {
		next_point_bit_vector[3] |= 0x80000; /* PauseOn:  #115*/
	}
}

static void Point_116() {
	LOCALINCAWAITTICK(ID_Output_Summer_module_55);
	next_point_bit_vector[1] |= 0x80000; /* PauseOn:  #51*/
}

static void Point_117() {
	LOCALINCAWAITTICK(ID_Output_Summer_module_55);
	next_point_bit_vector[1] |= 0x20000; /* PauseOn:  #49*/
}

static void Point_118() {
	if (IS_SIGNAL(SIG_ID_Signal_b_on_328,0)) {
		current_point_bit_vector[4] |= 0x100; /* On:  #136*/
	} else {
		current_point_bit_vector[3] |= 0x800000; /* On:  #119*/
	}
}

static void Point_119() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_c4_84,0)) {
		current_point_bit_vector[4] |= 0x200; /* On:  #137*/
	} else {
		next_point_bit_vector[3] |= 0x800000; /* PauseOn:  #119*/
	}
}

static void Point_120() {
	if (IS_SIGNAL(SIG_ID_Signal_b_on_328,0)) {
		current_point_bit_vector[4] |= 0x2; /* On:  #129*/
	} else {
		if (IS_SIGNAL(SIG_ID_Signal_ret_port_c4_84,0)) {
			current_point_bit_vector[4] |= 0x4; /* On:  #130*/
		} else {
			next_point_bit_vector[3] |= 0x800000; /* PauseOn:  #119*/
		}
	}
}

static void Point_121() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_2_82,0)) {
		_integer(&ID_Variable_Flag_378,ID_Signal_ret_port_2_82);
		next_point_bit_vector[1] &= ~0x1; /* PauseOff:  #32*/
		if (_eq_integer(ID_Variable_Flag_378,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_380,0))) {
				LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
				next_point_bit_vector[1] |= 0x80; /* PauseOn:  #39*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_379,1);
				goto L952;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_378,0)) {
				LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
				next_point_bit_vector[1] |= 0x100; /* PauseOn:  #40*/
			} else {
				if (_eq_integer(ID_Variable_Flag_378,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_380,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_378,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_380,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_380,-2);
						}
					}
				}
L952:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_380,0))) {
					LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
					next_point_bit_vector[1] |= 0x200; /* PauseOn:  #41*/
				} else {
					_integer(&ID_Variable_temp_int_381,REAL_MARK_DATA(ID_Variable_pendingWP_374, ID_Variable_requestSize_377, ID_Variable_dataMarkedUpstream_379, ID_InputOutput_MOD_SRANGE_42, ID_Output_Scopesink_module_56));
					LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
					_integer(&ID_Signal_broadcast_compute_88,ID_Variable_temp_int_381);
					EMIT(SIG_ID_Signal_broadcast_compute_88);
					if (IS_SIGNAL(SIG_ID_Signal_ret_port_c2_86,0)) {
						_integer(&ID_Variable_not_source_385,0);
						_integer(&ID_Variable_not_complete_flag_386,0);
						_StrlSampleIndex(&ID_Variable_temp_index_387,INITIAL_INDEX);
						_StrlSampleSize(&ID_Variable_complete_var_388,INITIAL_SIZE);
						CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_389);
						CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_390);
						if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Scopesink_module_56),0)) {
							LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
							next_point_bit_vector[1] |= 0x400; /* PauseOn:  #42*/
						} else {
							if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Scopesink_module_56),0)) {
								LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
								next_point_bit_vector[1] |= 0x800; /* PauseOn:  #43*/
							} else {
								_integer(&ID_Variable_not_source_385,1);
								_StrlSampleSize(&ID_Variable_complete_var_388,REALCOMPUTEDATA(ID_Output_Scopesink_module_56, ID_Variable_not_source_385));
								if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Scopesink_module_56), ID_Variable_complete_var_388) > 0)) {
									_integer(&ID_Variable_not_complete_flag_386,(ID_Variable_not_complete_flag_386 - 1));
								}
								if ((ID_Variable_not_complete_flag_386 < 0)) {
									_StrlSampleIndex(&ID_Variable_temp_index_387,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Scopesink_module_56), ID_Variable_complete_var_388));
									SET_MARKEDWP(ID_Output_Scopesink_module_56, ID_Variable_temp_index_387);
								}
								WRITEDATA(ID_Output_Scopesink_module_56, ID_Variable_not_source_385);
								_StrlSampleIndex(&ID_Variable_temp_index_387,GETWP(ID_Output_Scopesink_module_56));
								_StrlSampleRange(&ID_InputOutput_SCOPESINK_MYMARKEDDATA_50,GET_MYMARKEDDATA(ID_Output_Scopesink_module_56));
								PERF_STRL1_O_SCOPESINK_MYMARKEDDATA(ID_InputOutput_SCOPESINK_MYMARKEDDATA_50); EMIT(SIG_ID_InputOutput_SCOPESINK_MYMARKEDDATA_50);
								LOCALINCAWAITTICK(ID_Output_Scopesink_module_56);
								next_point_bit_vector[1] |= 0x1000; /* PauseOn:  #44*/
							}
						}
					} else {
						next_point_bit_vector[3] |= 0x4000; /* PauseOn:  #110*/
					}
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x2000; /* PauseOn:  #109*/
	}
}

static void Point_122() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_2_82,0)) {
		_integer(&ID_Variable_Flag_400,ID_Signal_ret_port_2_82);
		next_point_bit_vector[2] &= ~0x400; /* PauseOff:  #74*/
		if (_eq_integer(ID_Variable_Flag_400,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_402,0))) {
				LOCALINCAWAITTICK(ID_Output_Summer_module_55);
				next_point_bit_vector[1] |= 0x20000; /* PauseOn:  #49*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_401,1);
				goto L995;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_400,0)) {
				LOCALINCAWAITTICK(ID_Output_Summer_module_55);
				next_point_bit_vector[1] |= 0x40000; /* PauseOn:  #50*/
			} else {
				if (_eq_integer(ID_Variable_Flag_400,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_402,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_400,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_402,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_402,-2);
						}
					}
				}
L995:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_402,0))) {
					LOCALINCAWAITTICK(ID_Output_Summer_module_55);
					next_point_bit_vector[1] |= 0x80000; /* PauseOn:  #51*/
				} else {
					_integer(&ID_Variable_temp_int_403,REAL_MARK_DATA(ID_Variable_pendingWP_396, ID_Variable_requestSize_399, ID_Variable_dataMarkedUpstream_401, ID_InputOutput_MOD_SRANGE_42, ID_Output_Summer_module_55));
					LOCALINCAWAITTICK(ID_Output_Summer_module_55);
					_integer(&ID_Signal_ret_port_1_83,ID_Variable_temp_int_403);
					EMIT(SIG_ID_Signal_ret_port_1_83);
					if (IS_SIGNAL(SIG_ID_Signal_b_on_393,0)) {
						current_point_bit_vector[4] |= 0x20; /* On:  #133*/
					} else {
						if (IS_SIGNAL(SIG_ID_Signal_ret_port_c2_86,0)) {
							current_point_bit_vector[4] |= 0x40; /* On:  #134*/
						} else {
							next_point_bit_vector[3] |= 0x80000; /* PauseOn:  #115*/
						}
					}
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x20000; /* PauseOn:  #113*/
	}
}

static void Point_123() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_1_83,0)) {
		_integer(&ID_Variable_Flag_420,ID_Signal_ret_port_1_83);
		next_point_bit_vector[1] &= ~0x1000000; /* PauseOff:  #56*/
		if (_eq_integer(ID_Variable_Flag_420,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_422,0))) {
				LOCALINCAWAITTICK(ID_Output_Sink_module_57);
				next_point_bit_vector[1] |= 0x80000000; /* PauseOn:  #63*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_421,1);
				goto L1017;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_420,0)) {
				LOCALINCAWAITTICK(ID_Output_Sink_module_57);
				next_point_bit_vector[2] |= 0x1; /* PauseOn:  #64*/
			} else {
				if (_eq_integer(ID_Variable_Flag_420,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_422,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_420,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_422,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_422,-2);
						}
					}
				}
L1017:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_422,0))) {
					LOCALINCAWAITTICK(ID_Output_Sink_module_57);
					next_point_bit_vector[2] |= 0x2; /* PauseOn:  #65*/
				} else {
					_integer(&ID_Variable_temp_int_423,REAL_MARK_DATA(ID_Variable_pendingWP_416, ID_Variable_requestSize_419, ID_Variable_dataMarkedUpstream_421, ID_InputOutput_SUMMER_SRANGE_43, ID_Output_Sink_module_57));
					LOCALINCAWAITTICK(ID_Output_Sink_module_57);
					_integer(&ID_Signal_broadcast_compute_88,ID_Variable_temp_int_423);
					EMIT(SIG_ID_Signal_broadcast_compute_88);
					if (IS_SIGNAL(SIG_ID_Signal_ret_port_c1_87,0)) {
						_integer(&ID_Variable_not_source_427,0);
						_integer(&ID_Variable_not_complete_flag_428,0);
						_StrlSampleIndex(&ID_Variable_temp_index_429,INITIAL_INDEX);
						_StrlSampleSize(&ID_Variable_complete_var_430,INITIAL_SIZE);
						CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_431);
						CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_432);
						if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Sink_module_57),0)) {
							LOCALINCAWAITTICK(ID_Output_Sink_module_57);
							next_point_bit_vector[2] |= 0x4; /* PauseOn:  #66*/
						} else {
							if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Sink_module_57),0)) {
								LOCALINCAWAITTICK(ID_Output_Sink_module_57);
								next_point_bit_vector[2] |= 0x8; /* PauseOn:  #67*/
							} else {
								_integer(&ID_Variable_not_source_427,1);
								_StrlSampleSize(&ID_Variable_complete_var_430,REALCOMPUTEDATA(ID_Output_Sink_module_57, ID_Variable_not_source_427));
								if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Sink_module_57), ID_Variable_complete_var_430) > 0)) {
									_integer(&ID_Variable_not_complete_flag_428,(ID_Variable_not_complete_flag_428 - 1));
								}
								if ((ID_Variable_not_complete_flag_428 < 0)) {
									_StrlSampleIndex(&ID_Variable_temp_index_429,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Sink_module_57), ID_Variable_complete_var_430));
									SET_MARKEDWP(ID_Output_Sink_module_57, ID_Variable_temp_index_429);
								}
								WRITEDATA(ID_Output_Sink_module_57, ID_Variable_not_source_427);
								_StrlSampleIndex(&ID_Variable_temp_index_429,GETWP(ID_Output_Sink_module_57));
								_StrlSampleRange(&ID_InputOutput_SINK_MYMARKEDDATA_51,GET_MYMARKEDDATA(ID_Output_Sink_module_57));
								PERF_STRL1_O_SINK_MYMARKEDDATA(ID_InputOutput_SINK_MYMARKEDDATA_51); EMIT(SIG_ID_InputOutput_SINK_MYMARKEDDATA_51);
								LOCALINCAWAITTICK(ID_Output_Sink_module_57);
								next_point_bit_vector[2] |= 0x10; /* PauseOn:  #68*/
							}
						}
					} else {
						next_point_bit_vector[3] |= 0x20000000; /* PauseOn:  #125*/
					}
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x10000000; /* PauseOn:  #124*/
	}
}

static void Point_124() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_1_83,0)) {
		_integer(&ID_Variable_Flag_420,ID_Signal_ret_port_1_83);
		next_point_bit_vector[1] &= ~0x1000000; /* PauseOff:  #56*/
		if (_eq_integer(ID_Variable_Flag_420,1)) {
			if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_422,0))) {
				current_point_bit_vector[3] |= 0x80000000; /* On:  #127*/
			} else {
				_integer(&ID_Variable_dataMarkedUpstream_421,1);
				goto L1059;
			}
		} else {
			if (_eq_integer(ID_Variable_Flag_420,0)) {
				LOCALINCAWAITTICK(ID_Output_Sink_module_57);
				next_point_bit_vector[2] |= 0x1; /* PauseOn:  #64*/
			} else {
				if (_eq_integer(ID_Variable_Flag_420,-1)) {
					_integer(&ID_Variable_dataNotReadyUpstream_422,-1);
				} else {
					if (_eq_integer(ID_Variable_Flag_420,-2)) {
						if (_eq_integer(ID_Variable_dataNotReadyUpstream_422,0)) {
						} else {
							_integer(&ID_Variable_dataNotReadyUpstream_422,-2);
						}
					}
				}
L1059:
				if (!(_eq_integer(ID_Variable_dataNotReadyUpstream_422,0))) {
					current_point_bit_vector[3] |= 0x40000000; /* On:  #126*/
				} else {
					_integer(&ID_Variable_temp_int_423,REAL_MARK_DATA(ID_Variable_pendingWP_416, ID_Variable_requestSize_419, ID_Variable_dataMarkedUpstream_421, ID_InputOutput_SUMMER_SRANGE_43, ID_Output_Sink_module_57));
					LOCALINCAWAITTICK(ID_Output_Sink_module_57);
					_integer(&ID_Signal_broadcast_compute_88,ID_Variable_temp_int_423);
					EMIT(SIG_ID_Signal_broadcast_compute_88);
					current_point_bit_vector[3] |= 0x20000000; /* On:  #125*/
				}
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x10000000; /* PauseOn:  #124*/
	}
}

static void Point_125() {
	if (IS_SIGNAL(SIG_ID_Signal_ret_port_c1_87,0)) {
		_integer(&ID_Variable_not_source_427,0);
		_integer(&ID_Variable_not_complete_flag_428,0);
		_StrlSampleIndex(&ID_Variable_temp_index_429,INITIAL_INDEX);
		_StrlSampleSize(&ID_Variable_complete_var_430,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_431);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_432);
		if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Sink_module_57),0)) {
			LOCALINCAWAITTICK(ID_Output_Sink_module_57);
			next_point_bit_vector[2] |= 0x4; /* PauseOn:  #66*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Sink_module_57),0)) {
				LOCALINCAWAITTICK(ID_Output_Sink_module_57);
				next_point_bit_vector[2] |= 0x8; /* PauseOn:  #67*/
			} else {
				_integer(&ID_Variable_not_source_427,1);
				_StrlSampleSize(&ID_Variable_complete_var_430,REALCOMPUTEDATA(ID_Output_Sink_module_57, ID_Variable_not_source_427));
				if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Sink_module_57), ID_Variable_complete_var_430) > 0)) {
					_integer(&ID_Variable_not_complete_flag_428,(ID_Variable_not_complete_flag_428 - 1));
				}
				if ((ID_Variable_not_complete_flag_428 < 0)) {
					_StrlSampleIndex(&ID_Variable_temp_index_429,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Sink_module_57), ID_Variable_complete_var_430));
					SET_MARKEDWP(ID_Output_Sink_module_57, ID_Variable_temp_index_429);
				}
				WRITEDATA(ID_Output_Sink_module_57, ID_Variable_not_source_427);
				_StrlSampleIndex(&ID_Variable_temp_index_429,GETWP(ID_Output_Sink_module_57));
				_StrlSampleRange(&ID_InputOutput_SINK_MYMARKEDDATA_51,GET_MYMARKEDDATA(ID_Output_Sink_module_57));
				PERF_STRL1_O_SINK_MYMARKEDDATA(ID_InputOutput_SINK_MYMARKEDDATA_51); EMIT(SIG_ID_InputOutput_SINK_MYMARKEDDATA_51);
				LOCALINCAWAITTICK(ID_Output_Sink_module_57);
				next_point_bit_vector[2] |= 0x10; /* PauseOn:  #68*/
			}
		}
	} else {
		next_point_bit_vector[3] |= 0x20000000; /* PauseOn:  #125*/
	}
}

static void Point_126() {
	LOCALINCAWAITTICK(ID_Output_Sink_module_57);
	next_point_bit_vector[2] |= 0x2; /* PauseOn:  #65*/
}

static void Point_127() {
	LOCALINCAWAITTICK(ID_Output_Sink_module_57);
	next_point_bit_vector[1] |= 0x80000000; /* PauseOn:  #63*/
}

static void Point_128() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_compute_88,0)) {
		_integer(&ID_Variable_not_source_320,0);
		_integer(&ID_Variable_not_complete_flag_321,0);
		_StrlSampleIndex(&ID_Variable_temp_index_322,INITIAL_INDEX);
		_StrlSampleSize(&ID_Variable_complete_var_323,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_324);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_325);
		if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Source_module_52),0)) {
			LOCALINCAWAITTICK(ID_Output_Source_module_52);
			next_point_bit_vector[0] |= 0x80; /* PauseOn:  #7*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Source_module_52),0)) {
				LOCALINCAWAITTICK(ID_Output_Source_module_52);
				next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
			} else {
				LOCALINCAWAITTICK(ID_Output_Source_module_52);
				next_point_bit_vector[0] |= 0x200; /* PauseOn:  #9*/
			}
		}
	} else {
		next_point_bit_vector[4] |= 0x80; /* PauseOn:  #135*/
	}
}

static void Point_129() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_compute_88,0)) {
		current_point_bit_vector[4] |= 0x4; /* On:  #130*/
	} else {
		next_point_bit_vector[4] |= 0x100; /* PauseOn:  #136*/
	}
}

static void Point_130() {
	_integer(&ID_Variable_not_source_343,0);
	_integer(&ID_Variable_not_complete_flag_344,0);
	_StrlSampleIndex(&ID_Variable_temp_index_345,INITIAL_INDEX);
	_StrlSampleSize(&ID_Variable_complete_var_346,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_347);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_348);
	if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Coder_module_53),0)) {
		LOCALINCAWAITTICK(ID_Output_Coder_module_53);
		next_point_bit_vector[0] |= 0x80000; /* PauseOn:  #19*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Coder_module_53),0)) {
			LOCALINCAWAITTICK(ID_Output_Coder_module_53);
			next_point_bit_vector[0] |= 0x100000; /* PauseOn:  #20*/
		} else {
			_integer(&ID_Variable_not_source_343,1);
			_StrlSampleSize(&ID_Variable_complete_var_346,REALCOMPUTEDATA(ID_Output_Coder_module_53, ID_Variable_not_source_343));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Coder_module_53), ID_Variable_complete_var_346) > 0)) {
				_integer(&ID_Variable_not_complete_flag_344,(ID_Variable_not_complete_flag_344 - 1));
			}
			if ((ID_Variable_not_complete_flag_344 < 0)) {
				_StrlSampleIndex(&ID_Variable_temp_index_345,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Coder_module_53), ID_Variable_complete_var_346));
				SET_MARKEDWP(ID_Output_Coder_module_53, ID_Variable_temp_index_345);
			}
			WRITEDATA(ID_Output_Coder_module_53, ID_Variable_not_source_343);
			_StrlSampleIndex(&ID_Variable_temp_index_345,GETWP(ID_Output_Coder_module_53));
			_StrlSampleRange(&ID_InputOutput_CODER_MYMARKEDDATA_47,GET_MYMARKEDDATA(ID_Output_Coder_module_53));
			PERF_STRL1_O_CODER_MYMARKEDDATA(ID_InputOutput_CODER_MYMARKEDDATA_47); EMIT(SIG_ID_InputOutput_CODER_MYMARKEDDATA_47);
			LOCALINCAWAITTICK(ID_Output_Coder_module_53);
			next_point_bit_vector[0] |= 0x200000; /* PauseOn:  #21*/
		}
	}
}

static void Point_131() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_compute_88,0)) {
		current_point_bit_vector[4] |= 0x10; /* On:  #132*/
	} else {
		next_point_bit_vector[4] |= 0x400; /* PauseOn:  #138*/
	}
}

static void Point_132() {
	_integer(&ID_Variable_not_source_365,0);
	_integer(&ID_Variable_not_complete_flag_366,0);
	_StrlSampleIndex(&ID_Variable_temp_index_367,INITIAL_INDEX);
	_StrlSampleSize(&ID_Variable_complete_var_368,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_369);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_370);
	if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Mod_module_54),0)) {
		LOCALINCAWAITTICK(ID_Output_Mod_module_54);
		next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Mod_module_54),0)) {
			LOCALINCAWAITTICK(ID_Output_Mod_module_54);
			next_point_bit_vector[0] |= 0x20000000; /* PauseOn:  #29*/
		} else {
			_integer(&ID_Variable_not_source_365,1);
			_StrlSampleSize(&ID_Variable_complete_var_368,REALCOMPUTEDATA(ID_Output_Mod_module_54, ID_Variable_not_source_365));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Mod_module_54), ID_Variable_complete_var_368) > 0)) {
				_integer(&ID_Variable_not_complete_flag_366,(ID_Variable_not_complete_flag_366 - 1));
			}
			if ((ID_Variable_not_complete_flag_366 < 0)) {
				_StrlSampleIndex(&ID_Variable_temp_index_367,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Mod_module_54), ID_Variable_complete_var_368));
				SET_MARKEDWP(ID_Output_Mod_module_54, ID_Variable_temp_index_367);
			}
			WRITEDATA(ID_Output_Mod_module_54, ID_Variable_not_source_365);
			_StrlSampleIndex(&ID_Variable_temp_index_367,GETWP(ID_Output_Mod_module_54));
			_StrlSampleRange(&ID_InputOutput_MOD_MYMARKEDDATA_48,GET_MYMARKEDDATA(ID_Output_Mod_module_54));
			PERF_STRL1_O_MOD_MYMARKEDDATA(ID_InputOutput_MOD_MYMARKEDDATA_48); EMIT(SIG_ID_InputOutput_MOD_MYMARKEDDATA_48);
			LOCALINCAWAITTICK(ID_Output_Mod_module_54);
			next_point_bit_vector[0] |= 0x40000000; /* PauseOn:  #30*/
		}
	}
}

static void Point_133() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_compute_88,0)) {
		current_point_bit_vector[4] |= 0x40; /* On:  #134*/
	} else {
		next_point_bit_vector[4] |= 0x1000; /* PauseOn:  #140*/
	}
}

static void Point_134() {
	_integer(&ID_Variable_not_source_407,0);
	_integer(&ID_Variable_not_complete_flag_408,0);
	_StrlSampleIndex(&ID_Variable_temp_index_409,INITIAL_INDEX);
	_StrlSampleSize(&ID_Variable_complete_var_410,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_411);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_412);
	if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Summer_module_55),0)) {
		LOCALINCAWAITTICK(ID_Output_Summer_module_55);
		next_point_bit_vector[1] |= 0x100000; /* PauseOn:  #52*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Summer_module_55),0)) {
			LOCALINCAWAITTICK(ID_Output_Summer_module_55);
			next_point_bit_vector[1] |= 0x200000; /* PauseOn:  #53*/
		} else {
			_integer(&ID_Variable_not_source_407,1);
			_StrlSampleSize(&ID_Variable_complete_var_410,REALCOMPUTEDATA(ID_Output_Summer_module_55, ID_Variable_not_source_407));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Summer_module_55), ID_Variable_complete_var_410) > 0)) {
				_integer(&ID_Variable_not_complete_flag_408,(ID_Variable_not_complete_flag_408 - 1));
			}
			if ((ID_Variable_not_complete_flag_408 < 0)) {
				_StrlSampleIndex(&ID_Variable_temp_index_409,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Summer_module_55), ID_Variable_complete_var_410));
				SET_MARKEDWP(ID_Output_Summer_module_55, ID_Variable_temp_index_409);
			}
			WRITEDATA(ID_Output_Summer_module_55, ID_Variable_not_source_407);
			_StrlSampleIndex(&ID_Variable_temp_index_409,GETWP(ID_Output_Summer_module_55));
			_StrlSampleRange(&ID_InputOutput_SUMMER_MYMARKEDDATA_49,GET_MYMARKEDDATA(ID_Output_Summer_module_55));
			PERF_STRL1_O_SUMMER_MYMARKEDDATA(ID_InputOutput_SUMMER_MYMARKEDDATA_49); EMIT(SIG_ID_InputOutput_SUMMER_MYMARKEDDATA_49);
			LOCALINCAWAITTICK(ID_Output_Summer_module_55);
			next_point_bit_vector[1] |= 0x400000; /* PauseOn:  #54*/
		}
	}
}

static void Point_135() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_compute_88,0)) {
		_integer(&ID_Variable_not_source_320,0);
		_integer(&ID_Variable_not_complete_flag_321,0);
		_StrlSampleIndex(&ID_Variable_temp_index_322,INITIAL_INDEX);
		_StrlSampleSize(&ID_Variable_complete_var_323,INITIAL_SIZE);
		CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_324);
		CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_325);
		if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Source_module_52),0)) {
			LOCALINCAWAITTICK(ID_Output_Source_module_52);
			next_point_bit_vector[0] |= 0x80; /* PauseOn:  #7*/
		} else {
			if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Source_module_52),0)) {
				LOCALINCAWAITTICK(ID_Output_Source_module_52);
				next_point_bit_vector[0] |= 0x100; /* PauseOn:  #8*/
			} else {
				LOCALINCAWAITTICK(ID_Output_Source_module_52);
				next_point_bit_vector[0] |= 0x200; /* PauseOn:  #9*/
			}
		}
	} else {
		next_point_bit_vector[4] |= 0x80; /* PauseOn:  #135*/
	}
}

static void Point_136() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_compute_88,0)) {
		current_point_bit_vector[4] |= 0x200; /* On:  #137*/
	} else {
		next_point_bit_vector[4] |= 0x100; /* PauseOn:  #136*/
	}
}

static void Point_137() {
	_integer(&ID_Variable_not_source_343,0);
	_integer(&ID_Variable_not_complete_flag_344,0);
	_StrlSampleIndex(&ID_Variable_temp_index_345,INITIAL_INDEX);
	_StrlSampleSize(&ID_Variable_complete_var_346,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_347);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_348);
	if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Coder_module_53),0)) {
		LOCALINCAWAITTICK(ID_Output_Coder_module_53);
		next_point_bit_vector[0] |= 0x80000; /* PauseOn:  #19*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Coder_module_53),0)) {
			LOCALINCAWAITTICK(ID_Output_Coder_module_53);
			next_point_bit_vector[0] |= 0x100000; /* PauseOn:  #20*/
		} else {
			_integer(&ID_Variable_not_source_343,1);
			_StrlSampleSize(&ID_Variable_complete_var_346,REALCOMPUTEDATA(ID_Output_Coder_module_53, ID_Variable_not_source_343));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Coder_module_53), ID_Variable_complete_var_346) > 0)) {
				_integer(&ID_Variable_not_complete_flag_344,(ID_Variable_not_complete_flag_344 - 1));
			}
			if ((ID_Variable_not_complete_flag_344 < 0)) {
				_StrlSampleIndex(&ID_Variable_temp_index_345,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Coder_module_53), ID_Variable_complete_var_346));
				SET_MARKEDWP(ID_Output_Coder_module_53, ID_Variable_temp_index_345);
			}
			WRITEDATA(ID_Output_Coder_module_53, ID_Variable_not_source_343);
			_StrlSampleIndex(&ID_Variable_temp_index_345,GETWP(ID_Output_Coder_module_53));
			_StrlSampleRange(&ID_InputOutput_CODER_MYMARKEDDATA_47,GET_MYMARKEDDATA(ID_Output_Coder_module_53));
			PERF_STRL1_O_CODER_MYMARKEDDATA(ID_InputOutput_CODER_MYMARKEDDATA_47); EMIT(SIG_ID_InputOutput_CODER_MYMARKEDDATA_47);
			LOCALINCAWAITTICK(ID_Output_Coder_module_53);
			next_point_bit_vector[0] |= 0x200000; /* PauseOn:  #21*/
		}
	}
}

static void Point_138() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_compute_88,0)) {
		current_point_bit_vector[4] |= 0x800; /* On:  #139*/
	} else {
		next_point_bit_vector[4] |= 0x400; /* PauseOn:  #138*/
	}
}

static void Point_139() {
	_integer(&ID_Variable_not_source_365,0);
	_integer(&ID_Variable_not_complete_flag_366,0);
	_StrlSampleIndex(&ID_Variable_temp_index_367,INITIAL_INDEX);
	_StrlSampleSize(&ID_Variable_complete_var_368,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_369);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_370);
	if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Mod_module_54),0)) {
		LOCALINCAWAITTICK(ID_Output_Mod_module_54);
		next_point_bit_vector[0] |= 0x10000000; /* PauseOn:  #28*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Mod_module_54),0)) {
			LOCALINCAWAITTICK(ID_Output_Mod_module_54);
			next_point_bit_vector[0] |= 0x20000000; /* PauseOn:  #29*/
		} else {
			_integer(&ID_Variable_not_source_365,1);
			_StrlSampleSize(&ID_Variable_complete_var_368,REALCOMPUTEDATA(ID_Output_Mod_module_54, ID_Variable_not_source_365));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Mod_module_54), ID_Variable_complete_var_368) > 0)) {
				_integer(&ID_Variable_not_complete_flag_366,(ID_Variable_not_complete_flag_366 - 1));
			}
			if ((ID_Variable_not_complete_flag_366 < 0)) {
				_StrlSampleIndex(&ID_Variable_temp_index_367,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Mod_module_54), ID_Variable_complete_var_368));
				SET_MARKEDWP(ID_Output_Mod_module_54, ID_Variable_temp_index_367);
			}
			WRITEDATA(ID_Output_Mod_module_54, ID_Variable_not_source_365);
			_StrlSampleIndex(&ID_Variable_temp_index_367,GETWP(ID_Output_Mod_module_54));
			_StrlSampleRange(&ID_InputOutput_MOD_MYMARKEDDATA_48,GET_MYMARKEDDATA(ID_Output_Mod_module_54));
			PERF_STRL1_O_MOD_MYMARKEDDATA(ID_InputOutput_MOD_MYMARKEDDATA_48); EMIT(SIG_ID_InputOutput_MOD_MYMARKEDDATA_48);
			LOCALINCAWAITTICK(ID_Output_Mod_module_54);
			next_point_bit_vector[0] |= 0x40000000; /* PauseOn:  #30*/
		}
	}
}

static void Point_140() {
	if (IS_SIGNAL(SIG_ID_Signal_broadcast_compute_88,0)) {
		current_point_bit_vector[4] |= 0x2000; /* On:  #141*/
	} else {
		next_point_bit_vector[4] |= 0x1000; /* PauseOn:  #140*/
	}
}

static void Point_141() {
	_integer(&ID_Variable_not_source_407,0);
	_integer(&ID_Variable_not_complete_flag_408,0);
	_StrlSampleIndex(&ID_Variable_temp_index_409,INITIAL_INDEX);
	_StrlSampleSize(&ID_Variable_complete_var_410,INITIAL_SIZE);
	CLEAR_SIGNAL(SIG_ID_Exception_EXIT_FUNC_411);
	CLEAR_SIGNAL(SIG_ID_Exception_GOTO_UNMARK_412);
	if (_eq_integer(CHECK_MYWRITERLL(ID_Output_Summer_module_55),0)) {
		LOCALINCAWAITTICK(ID_Output_Summer_module_55);
		next_point_bit_vector[1] |= 0x100000; /* PauseOn:  #52*/
	} else {
		if (_eq_integer(CHECK_MYMARKEDDATA_SIZE(ID_Output_Summer_module_55),0)) {
			LOCALINCAWAITTICK(ID_Output_Summer_module_55);
			next_point_bit_vector[1] |= 0x200000; /* PauseOn:  #53*/
		} else {
			_integer(&ID_Variable_not_source_407,1);
			_StrlSampleSize(&ID_Variable_complete_var_410,REALCOMPUTEDATA(ID_Output_Summer_module_55, ID_Variable_not_source_407));
			if ((CMPSAMPLESIZE(GET_MYMARKEDSIZE(ID_Output_Summer_module_55), ID_Variable_complete_var_410) > 0)) {
				_integer(&ID_Variable_not_complete_flag_408,(ID_Variable_not_complete_flag_408 - 1));
			}
			if ((ID_Variable_not_complete_flag_408 < 0)) {
				_StrlSampleIndex(&ID_Variable_temp_index_409,ADD_SAMPLEINDEX(GET_MYMARKEDINDEX(ID_Output_Summer_module_55), ID_Variable_complete_var_410));
				SET_MARKEDWP(ID_Output_Summer_module_55, ID_Variable_temp_index_409);
			}
			WRITEDATA(ID_Output_Summer_module_55, ID_Variable_not_source_407);
			_StrlSampleIndex(&ID_Variable_temp_index_409,GETWP(ID_Output_Summer_module_55));
			_StrlSampleRange(&ID_InputOutput_SUMMER_MYMARKEDDATA_49,GET_MYMARKEDDATA(ID_Output_Summer_module_55));
			PERF_STRL1_O_SUMMER_MYMARKEDDATA(ID_InputOutput_SUMMER_MYMARKEDDATA_49); EMIT(SIG_ID_InputOutput_SUMMER_MYMARKEDDATA_49);
			LOCALINCAWAITTICK(ID_Output_Summer_module_55);
			next_point_bit_vector[1] |= 0x400000; /* PauseOn:  #54*/
		}
	}
}


int PERF_STRL1() {
	unsigned int i = 0;
	unsigned int *current_point_ptr;
	unsigned int var;
	char self;
	
	current_point_ptr = current_point_bit_vector;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_0();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_1();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_2();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_3();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_4();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_5();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_6();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_7();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_8();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_9();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_10();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_11();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_12();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_13();
		}
		if ((*current_point_ptr) & 0x4000) {
			Point_14();
		}
		if ((*current_point_ptr) & 0x8000) {
			Point_15();
		}
		if ((*current_point_ptr) & 0x10000) {
			Point_16();
		}
		if ((*current_point_ptr) & 0x20000) {
			Point_17();
		}
		if ((*current_point_ptr) & 0x40000) {
			Point_18();
		}
		if ((*current_point_ptr) & 0x80000) {
			Point_19();
		}
		if ((*current_point_ptr) & 0x100000) {
			Point_20();
		}
		if ((*current_point_ptr) & 0x200000) {
			Point_21();
		}
		if ((*current_point_ptr) & 0x400000) {
			Point_22();
		}
		if ((*current_point_ptr) & 0x800000) {
			Point_23();
		}
		if ((*current_point_ptr) & 0x1000000) {
			Point_24();
		}
		if ((*current_point_ptr) & 0x2000000) {
			Point_25();
		}
		if ((*current_point_ptr) & 0x4000000) {
			Point_26();
		}
		if ((*current_point_ptr) & 0x8000000) {
			Point_27();
		}
		if ((*current_point_ptr) & 0x10000000) {
			Point_28();
		}
		if ((*current_point_ptr) & 0x20000000) {
			Point_29();
		}
		if ((*current_point_ptr) & 0x40000000) {
			Point_30();
		}
		if ((*current_point_ptr) & 0x80000000) {
			Point_31();
		}
	}
	current_point_ptr++;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_32();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_33();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_34();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_35();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_36();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_37();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_38();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_39();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_40();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_41();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_42();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_43();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_44();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_45();
		}
		if ((*current_point_ptr) & 0x4000) {
			Point_46();
		}
		if ((*current_point_ptr) & 0x8000) {
			Point_47();
		}
		if ((*current_point_ptr) & 0x10000) {
			Point_48();
		}
		if ((*current_point_ptr) & 0x20000) {
			Point_49();
		}
		if ((*current_point_ptr) & 0x40000) {
			Point_50();
		}
		if ((*current_point_ptr) & 0x80000) {
			Point_51();
		}
		if ((*current_point_ptr) & 0x100000) {
			Point_52();
		}
		if ((*current_point_ptr) & 0x200000) {
			Point_53();
		}
		if ((*current_point_ptr) & 0x400000) {
			Point_54();
		}
		if ((*current_point_ptr) & 0x800000) {
			Point_55();
		}
		if ((*current_point_ptr) & 0x1000000) {
			Point_56();
		}
		if ((*current_point_ptr) & 0x2000000) {
			Point_57();
		}
		if ((*current_point_ptr) & 0x4000000) {
			Point_58();
		}
		if ((*current_point_ptr) & 0x8000000) {
			Point_59();
		}
		if ((*current_point_ptr) & 0x10000000) {
			Point_60();
		}
		if ((*current_point_ptr) & 0x20000000) {
			Point_61();
		}
		if ((*current_point_ptr) & 0x40000000) {
			Point_62();
		}
		if ((*current_point_ptr) & 0x80000000) {
			Point_63();
		}
	}
	current_point_ptr++;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_64();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_65();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_66();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_67();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_68();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_69();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_70();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_71();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_72();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_73();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_74();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_75();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_76();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_77();
		}
		if ((*current_point_ptr) & 0x4000) {
			Point_78();
		}
		if ((*current_point_ptr) & 0x8000) {
			Point_79();
		}
		if ((*current_point_ptr) & 0x10000) {
			Point_80();
		}
		if ((*current_point_ptr) & 0x20000) {
			Point_81();
		}
		if ((*current_point_ptr) & 0x40000) {
			Point_82();
		}
		if ((*current_point_ptr) & 0x80000) {
			Point_83();
		}
		if ((*current_point_ptr) & 0x100000) {
			Point_84();
		}
		if ((*current_point_ptr) & 0x200000) {
			Point_85();
		}
		if ((*current_point_ptr) & 0x400000) {
			Point_86();
		}
		if ((*current_point_ptr) & 0x800000) {
			Point_87();
		}
		if ((*current_point_ptr) & 0x1000000) {
			Point_88();
		}
		if ((*current_point_ptr) & 0x2000000) {
			Point_89();
		}
		if ((*current_point_ptr) & 0x4000000) {
			Point_90();
		}
		if ((*current_point_ptr) & 0x8000000) {
			Point_91();
		}
		if ((*current_point_ptr) & 0x10000000) {
			Point_92();
		}
		if ((*current_point_ptr) & 0x20000000) {
			Point_93();
		}
		if ((*current_point_ptr) & 0x40000000) {
			Point_94();
		}
		if ((*current_point_ptr) & 0x80000000) {
			Point_95();
		}
	}
	current_point_ptr++;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_96();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_97();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_98();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_99();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_100();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_101();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_102();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_103();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_104();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_105();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_106();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_107();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_108();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_109();
		}
		if ((*current_point_ptr) & 0x4000) {
			Point_110();
		}
		if ((*current_point_ptr) & 0x8000) {
			Point_111();
		}
		if ((*current_point_ptr) & 0x10000) {
			Point_112();
		}
		if ((*current_point_ptr) & 0x20000) {
			Point_113();
		}
		if ((*current_point_ptr) & 0x40000) {
			Point_114();
		}
		if ((*current_point_ptr) & 0x80000) {
			Point_115();
		}
		if ((*current_point_ptr) & 0x100000) {
			Point_116();
		}
		if ((*current_point_ptr) & 0x200000) {
			Point_117();
		}
		if ((*current_point_ptr) & 0x400000) {
			Point_118();
		}
		if ((*current_point_ptr) & 0x800000) {
			Point_119();
		}
		if ((*current_point_ptr) & 0x1000000) {
			Point_120();
		}
		if ((*current_point_ptr) & 0x2000000) {
			Point_121();
		}
		if ((*current_point_ptr) & 0x4000000) {
			Point_122();
		}
		if ((*current_point_ptr) & 0x8000000) {
			Point_123();
		}
		if ((*current_point_ptr) & 0x10000000) {
			Point_124();
		}
		if ((*current_point_ptr) & 0x20000000) {
			Point_125();
		}
		if ((*current_point_ptr) & 0x40000000) {
			Point_126();
		}
		if ((*current_point_ptr) & 0x80000000) {
			Point_127();
		}
	}
	current_point_ptr++;
	if (*current_point_ptr) {
		if ((*current_point_ptr) & 0x1) {
			Point_128();
		}
		if ((*current_point_ptr) & 0x2) {
			Point_129();
		}
		if ((*current_point_ptr) & 0x4) {
			Point_130();
		}
		if ((*current_point_ptr) & 0x8) {
			Point_131();
		}
		if ((*current_point_ptr) & 0x10) {
			Point_132();
		}
		if ((*current_point_ptr) & 0x20) {
			Point_133();
		}
		if ((*current_point_ptr) & 0x40) {
			Point_134();
		}
		if ((*current_point_ptr) & 0x80) {
			Point_135();
		}
		if ((*current_point_ptr) & 0x100) {
			Point_136();
		}
		if ((*current_point_ptr) & 0x200) {
			Point_137();
		}
		if ((*current_point_ptr) & 0x400) {
			Point_138();
		}
		if ((*current_point_ptr) & 0x800) {
			Point_139();
		}
		if ((*current_point_ptr) & 0x1000) {
			Point_140();
		}
		if ((*current_point_ptr) & 0x2000) {
			Point_141();
		}
	}
	current_point_ptr++;
	{
		int i;
		
		for (i = 0 ; i < SIGNAL_VECTOR_SIZE; i++) signal_bit_vector[i] = 0;
		for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) current_point_bit_vector[i] = next_point_bit_vector[i];
		for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) next_point_bit_vector[i] = 0;
	}
	return 1;
}

int PERF_STRL1_reset() {
	int i,j;
	
	if (!ID_Variable_nameofsink_95) ID_Variable_nameofsink_95 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofscopesink_94) ID_Variable_nameofscopesink_94 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofsummer_93) ID_Variable_nameofsummer_93 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofmod_92) ID_Variable_nameofmod_92 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofcoder_91) ID_Variable_nameofcoder_91 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Variable_nameofsource_90) ID_Variable_nameofsource_90 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Output_Sink_module_57) ID_Output_Sink_module_57 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Output_Scopesink_module_56) ID_Output_Scopesink_module_56 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Output_Summer_module_55) ID_Output_Summer_module_55 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Output_Mod_module_54) ID_Output_Mod_module_54 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Output_Coder_module_53) ID_Output_Coder_module_53 = (string) calloc(STRLEN,sizeof(char));
	if (!ID_Output_Source_module_52) ID_Output_Source_module_52 = (string) calloc(STRLEN,sizeof(char));
	for (i = 0 ; i < SIGNAL_VECTOR_SIZE; i++) signal_bit_vector[i] = 0;
	for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) current_point_bit_vector[i] = next_point_bit_vector[i];
	for (i = 0 ; i < HALT_POINT_VECTOR_SIZE; i++) next_point_bit_vector[i] = 0;
	BIT_SET(current_point_bit_vector, 0);
}
