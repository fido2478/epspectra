/* sscc : C CODE OF SORTED EQUATIONS DRM - INLINE MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define _true 1
#define _false 0
#define __DRM_GENERIC_TEST(TEST) return TEST;
typedef void (*__DRM_APF)();
static __DRM_APF *__DRM_PActionArray;

#include "UDP_FLOW.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _CHECKSAMPLESIZE_DEFINED
#ifndef CHECKSAMPLESIZE
extern integer CHECKSAMPLESIZE();
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __DRM_V0;
static boolean __DRM_V1;
static boolean __DRM_V2;
static boolean __DRM_V3;
static boolean __DRM_V4;
static boolean __DRM_V5;
static boolean __DRM_V6;
static boolean __DRM_V7;
static boolean __DRM_V8;
static boolean __DRM_V9;
static boolean __DRM_V10;
static boolean __DRM_V11;
static boolean __DRM_V12;
static char __DRM_V13[STRLEN];
static boolean __DRM_V14;
static boolean __DRM_V15;
static boolean __DRM_V16;
static char __DRM_V17[STRLEN];


/* INPUT FUNCTIONS */

void DRM_I_User_Quit () {
__DRM_V0 = _true;
}
void DRM_I_Source_module () {
__DRM_V1 = _true;
}
void DRM_I_Coder_module () {
__DRM_V2 = _true;
}
void DRM_I_Mod_module () {
__DRM_V3 = _true;
}
void DRM_I_Summer_module () {
__DRM_V4 = _true;
}
void DRM_I_Scopesink_module () {
__DRM_V5 = _true;
}
void DRM_I_Sink_module () {
__DRM_V6 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __DRM_A1 \
__DRM_V0
#define __DRM_A2 \
__DRM_V1
#define __DRM_A3 \
__DRM_V2
#define __DRM_A4 \
__DRM_V3
#define __DRM_A5 \
__DRM_V4
#define __DRM_A6 \
__DRM_V5
#define __DRM_A7 \
__DRM_V6

/* OUTPUT ACTIONS */

#define __DRM_A8 \
DRM_O_Source_module()
#define __DRM_A9 \
DRM_O_Coder_module()
#define __DRM_A10 \
DRM_O_Mod_module()
#define __DRM_A11 \
DRM_O_Summer_module()
#define __DRM_A12 \
DRM_O_Scopesink_module()
#define __DRM_A13 \
DRM_O_Sink_module()

/* ASSIGNMENTS */

#define __DRM_A14 \
__DRM_V0 = _false
#define __DRM_A15 \
__DRM_V1 = _false
#define __DRM_A16 \
__DRM_V2 = _false
#define __DRM_A17 \
__DRM_V3 = _false
#define __DRM_A18 \
__DRM_V4 = _false
#define __DRM_A19 \
__DRM_V5 = _false
#define __DRM_A20 \
__DRM_V6 = _false
#define __DRM_A21 \
__DRM_V7 = _true
#define __DRM_A22 \
__DRM_V8 = _false
#define __DRM_A23 \
__DRM_V9 = _true
#define __DRM_A24 \
__DRM_V8 = _true
#define __DRM_A25 \
__DRM_V8 = _false
#define __DRM_A26 \
__DRM_V10 = _false
#define __DRM_A27 \
__DRM_V11 = _true
#define __DRM_A28 \
__DRM_V10 = _true
#define __DRM_A29 \
__DRM_V10 = _false
#define __DRM_A30 \
__DRM_V12 = _false
#define __DRM_A31 \
__DRM_V12 = _true
#define __DRM_A32 \
__DRM_V12 = _false
#define __DRM_A33 \
__DRM_V14 = _false
#define __DRM_A34 \
__DRM_V15 = _true
#define __DRM_A35 \
__DRM_V14 = _true
#define __DRM_A36 \
__DRM_V14 = _false
#define __DRM_A37 \
__DRM_V16 = _false
#define __DRM_A38 \
__DRM_V16 = _true
#define __DRM_A39 \
__DRM_V16 = _false

/* PROCEDURE CALLS */

/* CONDITIONS */

#define __DRM_A40 \
__DRM_V8
#define __DRM_A41 \
CHECKSAMPLESIZE()>=0
#define __DRM_A42 \
__DRM_V10
#define __DRM_A43 \
CHECKSAMPLESIZE()>=0
#define __DRM_A44 \
__DRM_V12
#define __DRM_A45 \
CHECKSAMPLESIZE()>=0
#define __DRM_A46 \
__DRM_V14
#define __DRM_A47 \
CHECKSAMPLESIZE()>=0
#define __DRM_A48 \
__DRM_V16
#define __DRM_A49 \
CHECKSAMPLESIZE()>=0

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __DRM_A50 \

#define __DRM_A51 \

#define __DRM_A52 \

#define __DRM_A53 \

#define __DRM_A54 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int DRM_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __DRM__reset_input () {
__DRM_V0 = _false;
__DRM_V1 = _false;
__DRM_V2 = _false;
__DRM_V3 = _false;
__DRM_V4 = _false;
__DRM_V5 = _false;
__DRM_V6 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __DRM_R[76] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int DRM () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[217];
E[0] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__DRM_A2)||__DRM_R[0];
if (E[0]) {
__DRM_A8;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A8\n");
#endif
}
E[1] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__DRM_A3)||__DRM_R[0];
if (E[1]) {
__DRM_A9;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A9\n");
#endif
}
E[2] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__DRM_A4)||__DRM_R[0];
if (E[2]) {
__DRM_A10;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A10\n");
#endif
}
E[3] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__DRM_A5)||__DRM_R[0];
if (E[3]) {
__DRM_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A11\n");
#endif
}
E[4] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__DRM_A6)||__DRM_R[0];
if (E[4]) {
__DRM_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A12\n");
#endif
}
E[5] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__DRM_A7)||__DRM_R[0];
if (E[5]) {
__DRM_A13;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A13\n");
#endif
}
E[6] = __DRM_R[2]||__DRM_R[4]||__DRM_R[3]||__DRM_R[1];
E[7] = __DRM_R[9]||__DRM_R[10]||__DRM_R[11];
E[8] = __DRM_R[5]||__DRM_R[6]||__DRM_R[13]||__DRM_R[8]||__DRM_R[15]||__DRM_R[14]||__DRM_R[7]||__DRM_R[12]||E[7];
E[9] = __DRM_R[17]||__DRM_R[16];
E[10] = E[8]||E[9];
E[11] = __DRM_R[40]||__DRM_R[41]||__DRM_R[42];
E[12] = __DRM_R[21]||__DRM_R[22];
E[13] = __DRM_R[23]||__DRM_R[24];
E[14] = E[12]||E[13]||__DRM_R[25];
E[15] = __DRM_R[26]||__DRM_R[27];
E[16] = __DRM_R[28]||__DRM_R[29];
E[17] = E[15]||E[16]||__DRM_R[30];
E[18] = __DRM_R[31]||__DRM_R[32];
E[19] = __DRM_R[33]||__DRM_R[34];
E[20] = E[18]||E[19]||__DRM_R[35];
E[21] = E[14]||E[17]||E[20]||__DRM_R[36]||__DRM_R[37]||__DRM_R[38]||__DRM_R[39];
E[22] = __DRM_R[18]||__DRM_R[44]||__DRM_R[20]||__DRM_R[43]||E[11]||__DRM_R[46]||__DRM_R[45]||__DRM_R[19]||E[21];
E[23] = __DRM_R[48]||__DRM_R[47];
E[24] = E[22]||E[23];
E[25] = __DRM_R[49]||__DRM_R[53]||__DRM_R[51]||__DRM_R[50]||__DRM_R[52];
E[26] = __DRM_R[55]||__DRM_R[54];
E[27] = E[25]||E[26];
E[28] = __DRM_R[60]||__DRM_R[61]||__DRM_R[62];
E[29] = __DRM_R[56]||__DRM_R[57]||__DRM_R[64]||__DRM_R[59]||__DRM_R[66]||__DRM_R[65]||__DRM_R[58]||__DRM_R[63]||E[28];
E[30] = __DRM_R[68]||__DRM_R[67];
E[31] = E[29]||E[30];
E[32] = __DRM_R[69]||__DRM_R[73]||__DRM_R[71]||__DRM_R[70]||__DRM_R[72];
E[33] = __DRM_R[75]||__DRM_R[74];
E[34] = E[32]||E[33];
E[35] = E[6]||E[10]||E[24]||E[27]||E[31]||E[34];
E[36] = E[35]&&!(__DRM_R[0]);
E[37] = E[36]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__DRM_A1));
E[38] = __DRM_R[2]&&E[37];
E[39] = __DRM_R[13]&&E[37];
E[40] = __DRM_R[44]&&E[37];
E[41] = __DRM_R[64]&&E[37];
E[42] = __DRM_R[3]&&E[37];
E[43] = __DRM_R[17]&&E[37];
if (__DRM_R[0]) {
__DRM_A22;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A22\n");
#endif
}
if (__DRM_R[0]) {
__DRM_A50;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A50\n");
#endif
}
E[44] = (E[43]&&E[39])||__DRM_R[0];
E[45] = __DRM_R[5]&&E[37];
E[46] = E[45]&&E[38];
E[47] = __DRM_R[11]&&E[37];
E[48] = E[7]&&!(__DRM_R[9]);
E[49] = E[7]&&!(__DRM_R[10]);
E[50] = (E[7]&&!(__DRM_R[11]))||E[47];
E[51] = __DRM_R[14]&&E[37];
E[52] = __DRM_R[48]&&E[37];
if (__DRM_R[0]) {
__DRM_A26;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A26\n");
#endif
}
if (__DRM_R[0]) {
__DRM_A51;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A51\n");
#endif
}
E[53] = (E[52]&&E[40])||__DRM_R[0];
E[54] = __DRM_R[18]&&E[37];
E[55] = E[54]&&E[39];
E[56] = __DRM_R[39]&&E[37];
E[57] = E[21]&&!(E[14]);
E[58] = E[21]&&!(E[17]);
E[59] = E[21]&&!(E[20]);
E[60] = E[21]&&!(__DRM_R[36]);
E[61] = E[21]&&!(__DRM_R[37]);
E[62] = E[21]&&!(__DRM_R[38]);
E[63] = (E[21]&&!(__DRM_R[39]))||E[56];
E[64] = __DRM_R[45]&&E[37];
E[65] = __DRM_R[55]&&E[37];
E[66] = __DRM_R[53]&&E[37];
if (__DRM_R[0]) {
__DRM_A30;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A30\n");
#endif
}
if (__DRM_R[0]) {
__DRM_A52;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A52\n");
#endif
}
E[67] = (E[65]&&E[66])||__DRM_R[0];
E[68] = __DRM_R[49]&&E[37];
E[69] = E[68]&&E[40];
E[70] = __DRM_R[54]&&E[37];
__DRM_R[55] = (E[67]&&E[69])||(__DRM_R[55]&&E[65]&&!(E[66]))||(E[70]&&E[69]);
E[65] = __DRM_R[68]&&E[37];
if (__DRM_R[0]) {
__DRM_A33;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A33\n");
#endif
}
if (__DRM_R[0]) {
__DRM_A53;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A53\n");
#endif
}
E[71] = (E[65]&&E[41])||__DRM_R[0];
E[72] = __DRM_R[56]&&E[37];
E[73] = E[72]&&E[40];
E[74] = __DRM_R[62]&&E[37];
E[75] = E[28]&&!(__DRM_R[60]);
E[76] = E[28]&&!(__DRM_R[61]);
E[77] = (E[28]&&!(__DRM_R[62]))||E[74];
E[78] = __DRM_R[65]&&E[37];
E[79] = __DRM_R[75]&&E[37];
E[80] = __DRM_R[73]&&E[37];
if (__DRM_R[0]) {
__DRM_A37;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A37\n");
#endif
}
if (__DRM_R[0]) {
__DRM_A54;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A54\n");
#endif
}
E[81] = (E[79]&&E[80])||__DRM_R[0];
E[82] = __DRM_R[69]&&E[37];
E[83] = E[82]&&E[41];
E[84] = __DRM_R[74]&&E[37];
__DRM_R[75] = (E[81]&&E[83])||(__DRM_R[75]&&E[79]&&!(E[80]))||(E[84]&&E[83]);
E[79] = __DRM_R[65]&&E[78]&&!(__DRM_R[75]);
E[85] = E[79]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 47\n"),
#endif
__DRM_A47);
E[86] = E[79]&&!(E[85]);
if (E[86]) {
__DRM_A36;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A36\n");
#endif
}
if (__DRM_R[0]) {
__DRM_A34;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A34\n");
#endif
}
E[87] = E[86]||__DRM_R[0];
E[74] = (E[74]&&E[75]&&E[76]&&E[28]&&E[77])||(E[87]&&!(__DRM_R[0]));
E[88] = __DRM_R[71]&&E[37];
E[89] = E[88]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 49\n"),
#endif
__DRM_A49);
E[88] = E[88]&&!(E[89]);
if (E[88]) {
__DRM_A39;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A39\n");
#endif
}
E[90] = E[40]&&E[88];
E[91] = E[74]&&E[90];
E[92] = E[74]&&E[40];
E[93] = (E[74]&&!(E[40]))||E[92];
E[94] = E[74]&&E[88];
E[95] = (E[74]&&!(E[88]))||E[94];
E[90] = E[74]&&!(E[90]);
E[96] = __DRM_R[60]&&E[37];
E[97] = E[96]&&E[88];
E[98] = __DRM_R[61]&&E[37];
E[99] = E[98]&&E[40];
E[96] = __DRM_R[60]&&E[96]&&!(E[88]);
E[75] = E[75]||E[96];
E[98] = __DRM_R[61]&&E[98]&&!(E[40]);
E[76] = E[76]||E[98];
E[100] = (E[91]&&E[93]&&E[95]&&(E[90]||E[91])&&E[74])||((E[97]||E[99])&&(E[75]||E[97])&&(E[76]||E[99])&&E[28]&&E[77]);
E[101] = E[73]||E[100];
E[102] = __DRM_R[67]&&E[37];
__DRM_R[68] = (E[71]&&E[101])||(__DRM_R[68]&&E[65]&&!(E[41]))||(E[102]&&E[101]);
E[65] = __DRM_R[55]||__DRM_R[68];
E[103] = __DRM_R[45]&&E[64]&&!(E[65]);
E[104] = E[103]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 43\n"),
#endif
__DRM_A43);
E[105] = E[103]&&!(E[104]);
if (E[105]) {
__DRM_A29;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A29\n");
#endif
}
if (__DRM_R[0]) {
__DRM_A27;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A27\n");
#endif
}
E[106] = E[105]||__DRM_R[0];
E[56] = (E[56]&&E[57]&&E[58]&&E[59]&&E[60]&&E[61]&&E[62]&&E[21]&&E[63])||(E[106]&&!(__DRM_R[0]));
E[107] = __DRM_R[51]&&E[37];
E[108] = E[107]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 45\n"),
#endif
__DRM_A45);
E[107] = E[107]&&!(E[108]);
if (E[107]) {
__DRM_A32;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A32\n");
#endif
}
E[109] = E[39]&&E[107]&&E[86];
E[110] = E[56]&&E[109];
E[111] = E[56]&&E[39];
E[112] = (E[56]&&!(E[39]))||E[111];
E[113] = E[56]&&E[107];
E[114] = (E[56]&&!(E[107]))||E[113];
E[115] = E[56]&&E[86];
E[116] = (E[56]&&!(E[86]))||E[115];
E[117] = E[39]&&E[107];
E[118] = E[56]&&E[117];
E[117] = (E[56]&&!(E[117]))||E[118];
E[119] = E[39]&&E[86];
E[120] = E[56]&&E[119];
E[119] = (E[56]&&!(E[119]))||E[120];
E[121] = E[107]&&E[86];
E[122] = E[56]&&E[121];
E[121] = (E[56]&&!(E[121]))||E[122];
E[109] = E[56]&&!(E[109]);
E[123] = __DRM_R[22]&&E[37];
E[124] = E[123]&&E[86];
E[125] = __DRM_R[24]&&E[37];
E[126] = E[125]&&E[107];
E[127] = __DRM_R[25]&&E[37];
E[128] = E[107]&&E[86];
E[129] = E[127]&&E[128];
E[130] = __DRM_R[21]&&E[37];
E[131] = __DRM_R[21]&&E[130]&&!(E[107]);
E[123] = (E[130]&&E[107])||(__DRM_R[22]&&E[123]&&!(E[86]));
E[12] = (E[14]&&!(E[12]))||E[131]||E[123];
E[130] = __DRM_R[23]&&E[37];
E[132] = __DRM_R[23]&&E[130]&&!(E[86]);
E[125] = (E[130]&&E[86])||(__DRM_R[24]&&E[125]&&!(E[107]));
E[13] = (E[14]&&!(E[13]))||E[132]||E[125];
E[128] = __DRM_R[25]&&E[127]&&!(E[128]);
E[14] = (E[14]&&!(__DRM_R[25]))||E[128];
E[127] = (E[124]||E[126]||E[129])&&(E[12]||E[124])&&(E[13]||E[126])&&(E[14]||E[129]);
E[130] = __DRM_R[27]&&E[37];
E[133] = E[130]&&E[86];
E[134] = __DRM_R[29]&&E[37];
E[135] = E[134]&&E[39];
E[136] = __DRM_R[30]&&E[37];
E[137] = E[39]&&E[86];
E[138] = E[136]&&E[137];
E[139] = __DRM_R[26]&&E[37];
E[140] = __DRM_R[26]&&E[139]&&!(E[39]);
E[130] = (E[139]&&E[39])||(__DRM_R[27]&&E[130]&&!(E[86]));
E[15] = (E[17]&&!(E[15]))||E[140]||E[130];
E[139] = __DRM_R[28]&&E[37];
E[141] = __DRM_R[28]&&E[139]&&!(E[86]);
E[134] = (E[139]&&E[86])||(__DRM_R[29]&&E[134]&&!(E[39]));
E[16] = (E[17]&&!(E[16]))||E[141]||E[134];
E[137] = __DRM_R[30]&&E[136]&&!(E[137]);
E[17] = (E[17]&&!(__DRM_R[30]))||E[137];
E[136] = (E[133]||E[135]||E[138])&&(E[15]||E[133])&&(E[16]||E[135])&&(E[17]||E[138]);
E[139] = __DRM_R[32]&&E[37];
E[142] = E[139]&&E[107];
E[143] = __DRM_R[34]&&E[37];
E[144] = E[143]&&E[39];
E[145] = __DRM_R[35]&&E[37];
E[146] = E[39]&&E[107];
E[147] = E[145]&&E[146];
E[148] = __DRM_R[31]&&E[37];
E[149] = __DRM_R[31]&&E[148]&&!(E[39]);
E[139] = (E[148]&&E[39])||(__DRM_R[32]&&E[139]&&!(E[107]));
E[18] = (E[20]&&!(E[18]))||E[149]||E[139];
E[148] = __DRM_R[33]&&E[37];
E[150] = __DRM_R[33]&&E[148]&&!(E[107]);
E[143] = (E[148]&&E[107])||(__DRM_R[34]&&E[143]&&!(E[39]));
E[19] = (E[20]&&!(E[19]))||E[150]||E[143];
E[146] = __DRM_R[35]&&E[145]&&!(E[146]);
E[20] = (E[20]&&!(__DRM_R[35]))||E[146];
E[145] = (E[142]||E[144]||E[147])&&(E[18]||E[142])&&(E[19]||E[144])&&(E[20]||E[147]);
E[148] = __DRM_R[36]&&E[37];
E[151] = E[148]&&E[86];
E[152] = __DRM_R[37]&&E[37];
E[153] = E[152]&&E[107];
E[154] = __DRM_R[38]&&E[37];
E[155] = E[154]&&E[39];
E[14] = (E[131]||E[123]||E[132]||E[125]||E[128])&&E[12]&&E[13]&&E[14];
E[57] = E[57]||E[14];
E[17] = (E[140]||E[130]||E[141]||E[134]||E[137])&&E[15]&&E[16]&&E[17];
E[58] = E[58]||E[17];
E[20] = (E[149]||E[139]||E[150]||E[143]||E[146])&&E[18]&&E[19]&&E[20];
E[59] = E[59]||E[20];
E[148] = __DRM_R[36]&&E[148]&&!(E[86]);
E[60] = E[60]||E[148];
E[152] = __DRM_R[37]&&E[152]&&!(E[107]);
E[61] = E[61]||E[152];
E[154] = __DRM_R[38]&&E[154]&&!(E[39]);
E[62] = E[62]||E[154];
E[19] = (E[110]&&E[112]&&E[114]&&E[116]&&E[117]&&E[119]&&E[121]&&(E[109]||E[110])&&E[56])||((E[127]||E[136]||E[145]||E[151]||E[153]||E[155])&&(E[57]||E[127])&&(E[58]||E[136])&&(E[59]||E[145])&&(E[60]||E[151])&&(E[61]||E[153])&&(E[62]||E[155])&&E[21]&&E[63]);
E[18] = E[55]||E[19];
E[16] = __DRM_R[47]&&E[37];
__DRM_R[48] = (E[53]&&E[18])||(__DRM_R[48]&&E[52]&&!(E[40]))||(E[16]&&E[18]);
E[52] = __DRM_R[14]&&E[51]&&!(__DRM_R[48]);
E[15] = E[52]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 41\n"),
#endif
__DRM_A41);
E[13] = E[52]&&!(E[15]);
if (E[13]) {
__DRM_A25;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A25\n");
#endif
}
if (__DRM_R[0]) {
__DRM_A23;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A23\n");
#endif
}
E[12] = E[13]||__DRM_R[0];
E[47] = (E[47]&&E[48]&&E[49]&&E[7]&&E[50])||(E[12]&&!(__DRM_R[0]));
E[156] = E[38]&&E[105];
E[157] = E[47]&&E[156];
E[158] = E[47]&&E[38];
E[159] = (E[47]&&!(E[38]))||E[158];
E[160] = E[47]&&E[105];
E[161] = (E[47]&&!(E[105]))||E[160];
E[156] = E[47]&&!(E[156]);
E[162] = __DRM_R[9]&&E[37];
E[163] = E[162]&&E[105];
E[164] = __DRM_R[10]&&E[37];
E[165] = E[164]&&E[38];
E[162] = __DRM_R[9]&&E[162]&&!(E[105]);
E[48] = E[48]||E[162];
E[164] = __DRM_R[10]&&E[164]&&!(E[38]);
E[49] = E[49]||E[164];
E[166] = (E[157]&&E[159]&&E[161]&&(E[156]||E[157])&&E[47])||((E[163]||E[165])&&(E[48]||E[163])&&(E[49]||E[165])&&E[7]&&E[50]);
E[167] = E[46]||E[166];
E[168] = __DRM_R[16]&&E[37];
__DRM_R[17] = (E[44]&&E[167])||(__DRM_R[17]&&E[43]&&!(E[39]))||(E[168]&&E[167]);
E[43] = __DRM_R[3]&&E[42]&&!(__DRM_R[17]);
E[169] = __DRM_R[0]||E[13];
E[170] = __DRM_R[7]&&E[37];
E[171] = (E[39]&&E[43])||(E[170]&&E[43]);
E[172] = __DRM_R[19]&&E[37];
E[173] = (E[40]&&E[52])||(E[172]&&E[52]);
E[174] = E[66]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 44\n"),
#endif
__DRM_A44);
E[66] = E[66]&&!(E[174]);
E[175] = __DRM_R[50]&&E[37];
__DRM_R[51] = E[174]||(E[66]&&E[103])||(E[175]&&E[103]);
E[174] = __DRM_R[58]&&E[37];
E[176] = (E[41]&&E[103])||(E[174]&&E[103]);
E[177] = E[80]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 48\n"),
#endif
__DRM_A48);
E[80] = E[80]&&!(E[177]);
E[178] = __DRM_R[70]&&E[37];
__DRM_R[71] = E[177]||(E[80]&&E[79])||(E[178]&&E[79]);
E[177] = __DRM_R[6]&&E[37];
E[179] = E[177]&&E[105];
E[180] = E[46]||E[179]||E[166];
E[181] = E[163]||E[165]||E[157];
E[182] = E[55]||E[19];
E[183] = E[182]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 42\n"),
#endif
__DRM_A42);
E[184] = E[107]&&E[86];
E[185] = E[183]&&E[184];
E[186] = E[183]&&E[107];
E[187] = (E[183]&&!(E[107]))||E[186];
E[188] = E[183]&&E[86];
E[189] = (E[183]&&!(E[86]))||E[188];
E[184] = E[183]&&!(E[184]);
E[190] = E[185]&&E[187]&&E[189]&&(E[184]||E[185])&&E[183];
E[191] = __DRM_R[42]&&E[37];
E[192] = E[11]&&!(__DRM_R[40]);
E[193] = E[11]&&!(__DRM_R[41]);
E[194] = (E[11]&&!(__DRM_R[42]))||E[191];
if (E[104]) {
__DRM_A28;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A28\n");
#endif
}
E[195] = E[104]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 42\n"),
#endif
__DRM_A42);
E[191] = (E[191]&&E[192]&&E[193]&&E[11]&&E[194])||E[195];
E[196] = E[107]&&E[86];
E[197] = E[191]&&E[196];
E[198] = E[191]&&E[107];
E[199] = (E[191]&&!(E[107]))||E[198];
E[200] = E[191]&&E[86];
E[201] = (E[191]&&!(E[86]))||E[200];
E[196] = E[191]&&!(E[196]);
E[202] = __DRM_R[40]&&E[37];
E[203] = E[202]&&E[86];
E[204] = __DRM_R[41]&&E[37];
E[205] = E[204]&&E[107];
E[202] = __DRM_R[40]&&E[202]&&!(E[86]);
E[192] = E[192]||E[202];
E[204] = __DRM_R[41]&&E[204]&&!(E[107]);
E[193] = E[193]||E[204];
E[206] = (E[197]&&E[199]&&E[201]&&(E[196]||E[197])&&E[191])||((E[203]||E[205])&&(E[192]||E[203])&&(E[193]||E[205])&&E[11]&&E[194]);
E[19] = E[55]||E[190]||E[206]||E[19];
E[55] = E[124]||E[126]||E[129]||E[133]||E[135]||E[138]||E[142]||E[144]||E[147]||E[151]||E[153]||E[155]||E[110];
E[207] = E[203]||E[205]||E[197]||E[185];
if (E[108]) {
__DRM_A31;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A31\n");
#endif
}
E[208] = E[69]||E[108];
E[209] = __DRM_R[57]&&E[37];
E[210] = E[209]&&E[88];
E[211] = E[73]||E[210]||E[100];
E[212] = E[97]||E[99]||E[91];
if (E[89]) {
__DRM_A38;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A38\n");
#endif
}
E[213] = E[83]||E[89];
E[36] = E[36]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__DRM_A1);
E[36] = E[36];
if (__DRM_R[0]) {
__DRM_A21;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A21\n");
#endif
}
E[214] = E[43]||__DRM_R[0];
E[215] = __DRM_R[1]&&E[37];
__DRM_R[2] = (E[214]&&E[169])||(E[215]&&E[169]);
E[216] = __DRM_R[4]&&E[37];
__DRM_R[4] = (E[38]&&__DRM_R[17])||(__DRM_R[4]&&E[216]&&__DRM_R[17]);
__DRM_R[3] = (E[216]&&!(__DRM_R[17]))||(__DRM_R[3]&&E[42]&&__DRM_R[17])||(E[38]&&!(__DRM_R[17]));
__DRM_R[1] = (E[214]&&!(E[169]))||(__DRM_R[1]&&E[215]&&!(E[169]));
E[169] = __DRM_R[2]||__DRM_R[4]||__DRM_R[3]||__DRM_R[1];
__DRM_R[5] = (E[12]&&__DRM_R[0])||(__DRM_R[5]&&E[45]&&!(E[38]));
E[166] = E[46]||E[166];
E[46] = E[166]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 40\n"),
#endif
__DRM_A40);
E[166] = E[166]&&!(E[46]);
E[38] = E[166]&&E[180];
E[166] = E[166]&&!(E[180]);
E[45] = E[46]||E[38]||E[166];
if (E[15]) {
__DRM_A24;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A24\n");
#endif
}
E[12] = E[15]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 40\n"),
#endif
__DRM_A40);
E[177] = E[12]||(__DRM_R[6]&&E[177]&&!(E[105]));
E[179] = E[179]||(E[15]&&!(E[12]));
E[215] = __DRM_R[12]&&E[37];
E[214] = (E[179]&&E[180])||(E[215]&&E[180]);
E[42] = __DRM_R[8]&&E[37];
E[216] = __DRM_R[15]&&E[37];
__DRM_R[15] = (E[42]&&__DRM_R[48])||(__DRM_R[15]&&E[216]&&__DRM_R[48]);
__DRM_R[14] = (E[216]&&!(__DRM_R[48]))||(__DRM_R[14]&&E[51]&&__DRM_R[48])||(E[42]&&!(__DRM_R[48]));
__DRM_R[7] = (E[39]&&!(E[43]))||(__DRM_R[7]&&E[170]&&!(E[43]));
E[180] = (E[179]&&!(E[180]))||(__DRM_R[12]&&E[215]&&!(E[180]));
E[215] = E[177]||E[214]||E[171]||__DRM_R[15]||__DRM_R[14]||__DRM_R[7]||E[180];
E[50] = ((E[158]||E[160]||E[47])&&E[159]&&E[161]&&E[156]&&E[47])||((E[162]||E[164])&&E[48]&&E[49]&&E[7]&&E[50]);
__DRM_R[16] = (E[44]&&!(E[167]))||(__DRM_R[16]&&E[168]&&!(E[167]));
E[9] = (__DRM_R[5]||E[45]||E[215]||E[50]||__DRM_R[17]||__DRM_R[16])&&((E[10]&&!(E[8]))||__DRM_R[5]||E[45]||E[215]||E[50])&&((E[10]&&!(E[9]))||__DRM_R[17]||__DRM_R[16]);
__DRM_R[18] = (E[106]&&__DRM_R[0])||(__DRM_R[18]&&E[54]&&!(E[39]));
E[182] = E[190]||(E[182]&&!(E[183]));
E[190] = E[182]&&E[19];
E[182] = E[182]&&!(E[19]);
E[184] = E[190]||E[182]||((E[186]||E[188]||E[183])&&E[187]&&E[189]&&E[184]&&E[183]);
E[206] = E[206]||(E[104]&&!(E[195]));
E[189] = __DRM_R[43]&&E[37];
E[187] = (E[206]&&E[19])||(E[189]&&E[19]);
E[39] = __DRM_R[20]&&E[37];
E[54] = __DRM_R[46]&&E[37];
__DRM_R[46] = (E[39]&&E[65])||(__DRM_R[46]&&E[54]&&E[65]);
__DRM_R[45] = (E[54]&&!(E[65]))||(__DRM_R[45]&&E[64]&&E[65])||(E[39]&&!(E[65]));
E[19] = (E[206]&&!(E[19]))||(__DRM_R[43]&&E[189]&&!(E[19]));
__DRM_R[19] = (E[40]&&!(E[52]))||(__DRM_R[19]&&E[172]&&!(E[52]));
E[194] = E[187]||E[173]||__DRM_R[46]||__DRM_R[45]||E[19]||((E[198]||E[200]||E[191])&&E[199]&&E[201]&&E[196]&&E[191])||((E[202]||E[204])&&E[192]&&E[193]&&E[11]&&E[194])||__DRM_R[19];
E[63] = ((E[111]||E[113]||E[115]||E[118]||E[120]||E[122]||E[56])&&E[112]&&E[114]&&E[116]&&E[117]&&E[119]&&E[121]&&E[109]&&E[56])||((E[14]||E[17]||E[20]||E[148]||E[152]||E[154])&&E[57]&&E[58]&&E[59]&&E[60]&&E[61]&&E[62]&&E[21]&&E[63]);
__DRM_R[47] = (E[53]&&!(E[18]))||(__DRM_R[47]&&E[16]&&!(E[18]));
E[23] = (__DRM_R[18]||E[184]||E[194]||E[63]||__DRM_R[48]||__DRM_R[47])&&((E[24]&&!(E[22]))||__DRM_R[18]||E[184]||E[194]||E[63])&&((E[24]&&!(E[23]))||__DRM_R[48]||__DRM_R[47]);
__DRM_R[49] = __DRM_R[0]||E[107]||(__DRM_R[49]&&E[68]&&!(E[40]));
E[68] = __DRM_R[52]&&E[37];
__DRM_R[53] = E[208]||(E[68]&&E[208]);
__DRM_R[50] = (E[66]&&!(E[103]))||(__DRM_R[50]&&E[175]&&!(E[103]));
__DRM_R[52] = __DRM_R[52]&&E[68]&&!(E[208]);
E[208] = __DRM_R[53]||__DRM_R[51]||__DRM_R[50]||__DRM_R[52];
__DRM_R[54] = (E[67]&&!(E[69]))||(__DRM_R[54]&&E[70]&&!(E[69]));
E[26] = (__DRM_R[49]||E[208]||__DRM_R[55]||__DRM_R[54])&&((E[27]&&!(E[25]))||__DRM_R[49]||E[208])&&((E[27]&&!(E[26]))||__DRM_R[55]||__DRM_R[54]);
__DRM_R[56] = (E[87]&&__DRM_R[0])||(__DRM_R[56]&&E[72]&&!(E[40]));
E[100] = E[73]||E[100];
E[73] = E[100]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 46\n"),
#endif
__DRM_A46);
E[100] = E[100]&&!(E[73]);
E[40] = E[100]&&E[211];
E[100] = E[100]&&!(E[211]);
E[72] = E[73]||E[40]||E[100];
if (E[85]) {
__DRM_A35;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A35\n");
#endif
}
E[87] = E[85]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 46\n"),
#endif
__DRM_A46);
E[209] = E[87]||(__DRM_R[57]&&E[209]&&!(E[88]));
E[210] = E[210]||(E[85]&&!(E[87]));
E[208] = __DRM_R[63]&&E[37];
E[25] = (E[210]&&E[211])||(E[208]&&E[211]);
E[69] = __DRM_R[59]&&E[37];
E[70] = __DRM_R[66]&&E[37];
__DRM_R[66] = (E[69]&&__DRM_R[75])||(__DRM_R[66]&&E[70]&&__DRM_R[75]);
__DRM_R[65] = (E[70]&&!(__DRM_R[75]))||(__DRM_R[65]&&E[78]&&__DRM_R[75])||(E[69]&&!(__DRM_R[75]));
__DRM_R[58] = (E[41]&&!(E[103]))||(__DRM_R[58]&&E[174]&&!(E[103]));
E[211] = (E[210]&&!(E[211]))||(__DRM_R[63]&&E[208]&&!(E[211]));
E[208] = E[209]||E[25]||E[176]||__DRM_R[66]||__DRM_R[65]||__DRM_R[58]||E[211];
E[77] = ((E[92]||E[94]||E[74])&&E[93]&&E[95]&&E[90]&&E[74])||((E[96]||E[98])&&E[75]&&E[76]&&E[28]&&E[77]);
__DRM_R[67] = (E[71]&&!(E[101]))||(__DRM_R[67]&&E[102]&&!(E[101]));
E[30] = (__DRM_R[56]||E[72]||E[208]||E[77]||__DRM_R[68]||__DRM_R[67])&&((E[31]&&!(E[29]))||__DRM_R[56]||E[72]||E[208]||E[77])&&((E[31]&&!(E[30]))||__DRM_R[68]||__DRM_R[67]);
__DRM_R[69] = __DRM_R[0]||E[88]||(__DRM_R[69]&&E[82]&&!(E[41]));
E[37] = __DRM_R[72]&&E[37];
__DRM_R[73] = E[213]||(E[37]&&E[213]);
__DRM_R[70] = (E[80]&&!(E[79]))||(__DRM_R[70]&&E[178]&&!(E[79]));
__DRM_R[72] = __DRM_R[72]&&E[37]&&!(E[213]);
E[213] = __DRM_R[73]||__DRM_R[71]||__DRM_R[70]||__DRM_R[72];
__DRM_R[74] = (E[81]&&!(E[83]))||(__DRM_R[74]&&E[84]&&!(E[83]));
E[33] = (__DRM_R[69]||E[213]||__DRM_R[75]||__DRM_R[74])&&((E[34]&&!(E[32]))||__DRM_R[69]||E[213])&&((E[34]&&!(E[33]))||__DRM_R[75]||__DRM_R[74]);
E[33] = (E[169]||E[9]||E[23]||E[26]||E[30]||E[33])&&(E[35]||__DRM_R[0])&&((E[35]&&!(E[6]))||E[169])&&((E[35]&&!(E[10]))||E[9])&&((E[35]&&!(E[24]))||E[23])&&((E[35]&&!(E[27]))||E[26])&&((E[35]&&!(E[31]))||E[30])&&((E[35]&&!(E[34]))||E[33]);
E[12] = E[46]||E[12];
__DRM_R[6] = E[46]||E[177];
E[177] = E[163]||E[165];
E[46] = E[163]||E[165];
__DRM_R[9] = (E[158]&&!(E[157]))||(E[162]&&!(E[165]));
__DRM_R[10] = (E[160]&&!(E[157]))||(E[164]&&!(E[163]));
__DRM_R[11] = E[47]&&!(E[157]);
__DRM_R[12] = E[180]||E[166];
__DRM_R[13] = E[214]||E[38];
E[195] = E[183]||E[195];
E[38] = E[136]||E[145]||E[151]||E[153]||E[155];
E[214] = E[127]||E[145]||E[151]||E[153]||E[155];
E[166] = E[127]||E[136]||E[151]||E[153]||E[155];
E[180] = E[127]||E[136]||E[145]||E[151]||E[153]||E[155];
E[157] = E[127]||E[136]||E[145]||E[151]||E[153]||E[155];
E[47] = E[38]||E[126]||E[129];
E[129] = E[38]||E[124]||E[129];
__DRM_R[21] = (E[111]&&!(E[110]))||(E[131]&&!(E[47]));
__DRM_R[22] = E[123]&&!(E[47]);
__DRM_R[23] = (E[111]&&!(E[110]))||(E[132]&&!(E[129]));
__DRM_R[24] = E[125]&&!(E[129]);
__DRM_R[25] = (E[111]&&!(E[110]))||(E[128]&&!((E[38]||E[124]||E[126])));
E[126] = E[214]||E[135]||E[138];
E[138] = E[214]||E[133]||E[138];
__DRM_R[26] = (E[113]&&!(E[110]))||(E[140]&&!(E[126]));
__DRM_R[27] = E[130]&&!(E[126]);
__DRM_R[28] = (E[113]&&!(E[110]))||(E[141]&&!(E[138]));
__DRM_R[29] = E[134]&&!(E[138]);
__DRM_R[30] = (E[113]&&!(E[110]))||(E[137]&&!((E[214]||E[133]||E[135])));
E[135] = E[166]||E[144]||E[147];
E[147] = E[166]||E[142]||E[147];
__DRM_R[31] = (E[115]&&!(E[110]))||(E[149]&&!(E[135]));
__DRM_R[32] = E[139]&&!(E[135]);
__DRM_R[33] = (E[115]&&!(E[110]))||(E[150]&&!(E[147]));
__DRM_R[34] = E[143]&&!(E[147]);
__DRM_R[35] = (E[115]&&!(E[110]))||(E[146]&&!((E[166]||E[142]||E[144])));
__DRM_R[36] = (E[118]&&!(E[110]))||(E[148]&&!((E[127]||E[136]||E[145]||E[153]||E[155])));
__DRM_R[37] = (E[120]&&!(E[110]))||(E[152]&&!((E[127]||E[136]||E[145]||E[151]||E[155])));
__DRM_R[38] = (E[122]&&!(E[110]))||(E[154]&&!((E[127]||E[136]||E[145]||E[151]||E[153])));
__DRM_R[39] = E[56]&&!(E[110]);
E[110] = E[203]||E[205];
E[56] = E[203]||E[205];
__DRM_R[40] = (E[186]&&!(E[185]))||(E[202]&&!(E[205]))||(E[198]&&!(E[197]));
__DRM_R[41] = (E[188]&&!(E[185]))||(E[204]&&!(E[203]))||(E[200]&&!(E[197]));
__DRM_R[42] = (E[183]&&!(E[185]))||(E[191]&&!(E[197]));
__DRM_R[43] = E[19]||E[182];
__DRM_R[44] = E[190]||E[187];
E[87] = E[73]||E[87];
__DRM_R[57] = E[73]||E[209];
E[209] = E[97]||E[99];
E[73] = E[97]||E[99];
__DRM_R[60] = (E[92]&&!(E[91]))||(E[96]&&!(E[99]));
__DRM_R[61] = (E[94]&&!(E[91]))||(E[98]&&!(E[97]));
__DRM_R[62] = E[74]&&!(E[91]);
__DRM_R[63] = E[211]||E[100];
__DRM_R[64] = E[25]||E[40];
__DRM_R[0] = !(_true);
__DRM_R[8] = E[171];
__DRM_R[20] = E[173];
__DRM_R[59] = E[176];
__DRM__reset_input();
return E[33];
}

/* AUTOMATON RESET */

int DRM_reset () {
__DRM_R[0] = _true;
__DRM_R[1] = _false;
__DRM_R[2] = _false;
__DRM_R[3] = _false;
__DRM_R[4] = _false;
__DRM_R[5] = _false;
__DRM_R[6] = _false;
__DRM_R[7] = _false;
__DRM_R[8] = _false;
__DRM_R[9] = _false;
__DRM_R[10] = _false;
__DRM_R[11] = _false;
__DRM_R[12] = _false;
__DRM_R[13] = _false;
__DRM_R[14] = _false;
__DRM_R[15] = _false;
__DRM_R[16] = _false;
__DRM_R[17] = _false;
__DRM_R[18] = _false;
__DRM_R[19] = _false;
__DRM_R[20] = _false;
__DRM_R[21] = _false;
__DRM_R[22] = _false;
__DRM_R[23] = _false;
__DRM_R[24] = _false;
__DRM_R[25] = _false;
__DRM_R[26] = _false;
__DRM_R[27] = _false;
__DRM_R[28] = _false;
__DRM_R[29] = _false;
__DRM_R[30] = _false;
__DRM_R[31] = _false;
__DRM_R[32] = _false;
__DRM_R[33] = _false;
__DRM_R[34] = _false;
__DRM_R[35] = _false;
__DRM_R[36] = _false;
__DRM_R[37] = _false;
__DRM_R[38] = _false;
__DRM_R[39] = _false;
__DRM_R[40] = _false;
__DRM_R[41] = _false;
__DRM_R[42] = _false;
__DRM_R[43] = _false;
__DRM_R[44] = _false;
__DRM_R[45] = _false;
__DRM_R[46] = _false;
__DRM_R[47] = _false;
__DRM_R[48] = _false;
__DRM_R[49] = _false;
__DRM_R[50] = _false;
__DRM_R[51] = _false;
__DRM_R[52] = _false;
__DRM_R[53] = _false;
__DRM_R[54] = _false;
__DRM_R[55] = _false;
__DRM_R[56] = _false;
__DRM_R[57] = _false;
__DRM_R[58] = _false;
__DRM_R[59] = _false;
__DRM_R[60] = _false;
__DRM_R[61] = _false;
__DRM_R[62] = _false;
__DRM_R[63] = _false;
__DRM_R[64] = _false;
__DRM_R[65] = _false;
__DRM_R[66] = _false;
__DRM_R[67] = _false;
__DRM_R[68] = _false;
__DRM_R[69] = _false;
__DRM_R[70] = _false;
__DRM_R[71] = _false;
__DRM_R[72] = _false;
__DRM_R[73] = _false;
__DRM_R[74] = _false;
__DRM_R[75] = _false;
__DRM__reset_input();
return 0;
}
