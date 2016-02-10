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

#include "UDP_FLOW.icopt.h"

/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _CHECK_MYWRITERLL_DEFINED
#ifndef CHECK_MYWRITERLL
extern integer CHECK_MYWRITERLL();
#endif
#endif
#ifndef _CHECK_MYMARKEDDATA_SIZE_DEFINED
#ifndef CHECK_MYMARKEDDATA_SIZE
extern integer CHECK_MYMARKEDDATA_SIZE();
#endif
#endif
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
CHECK_MYWRITERLL()==0
#define __DRM_A41 \
CHECK_MYMARKEDDATA_SIZE()==0
#define __DRM_A42 \
__DRM_V8
#define __DRM_A43 \
CHECKSAMPLESIZE()>=0
#define __DRM_A44 \
CHECK_MYWRITERLL()==0
#define __DRM_A45 \
CHECK_MYMARKEDDATA_SIZE()==0
#define __DRM_A46 \
__DRM_V10
#define __DRM_A47 \
CHECKSAMPLESIZE()>=0
#define __DRM_A48 \
CHECK_MYWRITERLL()==0
#define __DRM_A49 \
CHECK_MYMARKEDDATA_SIZE()==0
#define __DRM_A50 \
__DRM_V12
#define __DRM_A51 \
CHECKSAMPLESIZE()>=0
#define __DRM_A52 \
CHECK_MYWRITERLL()==0
#define __DRM_A53 \
CHECK_MYMARKEDDATA_SIZE()==0
#define __DRM_A54 \
__DRM_V14
#define __DRM_A55 \
CHECKSAMPLESIZE()>=0
#define __DRM_A56 \
CHECK_MYWRITERLL()==0
#define __DRM_A57 \
CHECK_MYMARKEDDATA_SIZE()==0
#define __DRM_A58 \
__DRM_V16
#define __DRM_A59 \
CHECKSAMPLESIZE()>=0
#define __DRM_A60 \
CHECK_MYWRITERLL()==0
#define __DRM_A61 \
CHECK_MYMARKEDDATA_SIZE()==0

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __DRM_A62 \

#define __DRM_A63 \

#define __DRM_A64 \

#define __DRM_A65 \

#define __DRM_A66 \


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

static __SSC_BIT_TYPE __DRM_R[45] = {_false,
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
 _true,
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

static __SSC_BIT_TYPE E[49];
E[0] = __DRM_R[33]||__DRM_R[14];
E[1] = __DRM_R[16]||__DRM_R[15]||__DRM_R[24]||__DRM_R[25]||E[0]||__DRM_R[37]||__DRM_R[34]||__DRM_R[27]||__DRM_R[20];
E[2] = !(E[1])||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__DRM_A1);
E[3] = (!(__DRM_R[44])&&!(__DRM_R[42])&&!(__DRM_R[43]))||E[2];
E[4] = E[2]||!(__DRM_R[24]);
E[5] = E[2]||!(__DRM_R[38]);
E[6] = !(E[5])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 59\n"),
#endif
__DRM_A59);
E[6] = E[5]||!(E[6]);
E[7] = E[5]||!(E[6]);
E[8] = E[2]||!(__DRM_R[23]);
E[9] = E[7]||E[8];
E[0] = (__DRM_R[34]&&!(E[7]))||(!(E[8])&&E[0])||!(E[9]);
E[10] = (!(__DRM_R[32])&&!(E[3])&&E[4])||E[0]||!(E[8]);
E[11] = E[10]||E[2]||!(__DRM_R[26]);
if (__DRM_R[36]) {
__DRM_A33;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A33\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A65;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A65\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A34;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A34\n");
#endif
}
if (!(E[7])) {
__DRM_A39;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A39\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A37;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A37\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A66;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A66\n");
#endif
}
E[12] = E[2]||!(__DRM_R[27]);
E[13] = !(E[12])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 55\n"),
#endif
__DRM_A55);
E[13] = E[12]||!(E[13]);
E[14] = E[12]||!(E[13]);
if (!(E[14])) {
__DRM_A36;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A36\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A30;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A30\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A64;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A64\n");
#endif
}
E[15] = !(E[11])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 47\n"),
#endif
__DRM_A47);
E[16] = E[11]||E[15];
if (__DRM_R[36]) {
__DRM_A26;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A26\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A63;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A63\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A27;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A27\n");
#endif
}
E[17] = E[2]||!(__DRM_R[21]);
E[18] = !(E[17])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 51\n"),
#endif
__DRM_A51);
E[18] = E[17]||!(E[18]);
E[17] = E[17]||!(E[18]);
if (!(E[17])) {
__DRM_A32;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A32\n");
#endif
}
if (!(E[16])) {
__DRM_A29;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A29\n");
#endif
}
E[19] = __DRM_R[5]||__DRM_R[2];
E[20] = !(E[3])||E[2]||!(__DRM_R[5]);
E[21] = __DRM_R[22]||__DRM_R[12];
E[22] = (__DRM_R[12]&&!(E[17]))||!((!(__DRM_R[8])&&E[17])||(!(__DRM_R[17])&&!(E[21]))||E[14]);
E[23] = !(E[20])||E[22];
E[24] = (!(__DRM_R[31])&&E[8])||E[23]||E[2];
E[25] = E[19]||E[24]||__DRM_R[1]||!(__DRM_R[42])||__DRM_R[0]||__DRM_R[3]||__DRM_R[6]||__DRM_R[7];
E[26] = !(E[25])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 43\n"),
#endif
__DRM_A43);
E[27] = E[25]||!(E[26]);
if (!(E[27])) {
__DRM_A24;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A24\n");
#endif
}
E[28] = !(E[27])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 42\n"),
#endif
__DRM_A42);
if (__DRM_R[36]) {
__DRM_A22;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A22\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A62;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A62\n");
#endif
}
if (__DRM_R[36]) {
__DRM_A23;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A23\n");
#endif
}
E[26] = E[25]||E[26];
if (!(E[26])) {
__DRM_A25;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A25\n");
#endif
}
E[29] = E[2]||!(__DRM_R[43]);
E[30] = (__DRM_R[3]&&!(E[16]))||!(E[29]||__DRM_R[4]);
E[31] = E[30]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 42\n"),
#endif
__DRM_A42);
E[32] = (__DRM_R[0]&&!(E[2])&&E[16])||(E[28]&&!(E[27]))||(E[31]&&E[30]);
E[33] = E[2]||!(__DRM_R[4])||__DRM_R[3];
__DRM_R[4] = !(E[26])||!(E[33]);
E[34] = __DRM_R[36]||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__DRM_A6);
if (E[34]) {
__DRM_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A12\n");
#endif
}
__DRM_R[6] = (!(E[28])&&!(E[27]))||(__DRM_R[6]&&!(E[2]));
__DRM_R[3] = (__DRM_R[3]&&!(E[2])&&E[16])||!(E[33]);
E[31] = (__DRM_R[0]&&!(E[16]))||(!(E[31])&&E[30]);
E[28] = E[23]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 46\n"),
#endif
__DRM_A46);
__DRM_R[18] = (__DRM_R[18]&&!(__DRM_R[5])&&!(E[2]))||E[30];
E[30] = E[2]||__DRM_R[18]||!(__DRM_R[44]);
E[35] = !(E[19])||E[30];
E[36] = (__DRM_R[13]&&!(E[2]))||!(E[8]);
E[37] = E[25]||!(E[36]);
E[38] = !(E[37])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 48\n"),
#endif
__DRM_A48);
E[38] = !(E[38])&&!(E[37])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 49\n"),
#endif
__DRM_A49);
E[15] = E[11]||!(E[15]);
if (!(E[15])) {
__DRM_A28;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A28\n");
#endif
}
E[39] = !(E[15])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 46\n"),
#endif
__DRM_A46);
E[40] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 54\n"),
#endif
__DRM_A54);
E[41] = E[2]||!(__DRM_R[40]);
E[42] = !(E[41])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 58\n"),
#endif
__DRM_A58);
__DRM_R[38] = (!(__DRM_R[30])&&E[5]&&!(E[12]))||(E[42]&&!(E[41]));
E[41] = __DRM_R[38]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 60\n"),
#endif
__DRM_A60);
if (!(E[13])) {
__DRM_A35;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A35\n");
#endif
}
E[42] = !(E[13])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 54\n"),
#endif
__DRM_A54);
E[12] = E[2]||!(__DRM_R[39]);
E[5] = !(E[12])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 50\n"),
#endif
__DRM_A50);
__DRM_R[21] = (!(__DRM_R[28])&&!(__DRM_R[21])&&!(E[11]))||(E[5]&&!(E[12]));
E[12] = __DRM_R[21]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 52\n"),
#endif
__DRM_A52);
__DRM_R[2] = !(E[2])&&E[30]&&E[19];
E[41] = !(E[41])&&__DRM_R[38]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 61\n"),
#endif
__DRM_A61);
E[12] = !(E[12])&&__DRM_R[21]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 53\n"),
#endif
__DRM_A53);
if (!(E[6])) {
__DRM_A38;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A38\n");
#endif
}
if (!(E[18])) {
__DRM_A31;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A31\n");
#endif
}
E[19] = __DRM_R[9]||__DRM_R[8];
__DRM_R[29] = (__DRM_R[29]&&!(__DRM_R[10])&&!(E[2])&&!(E[19])&&!(E[21]))||!(E[16]);
__DRM_R[7] = !(E[2])&&E[24]&&(__DRM_R[1]||__DRM_R[7]);
E[21] = (__DRM_R[15]&&!(E[2]))||!(E[4]);
E[5] = E[11]||!(E[21]);
E[43] = !(E[5])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 56\n"),
#endif
__DRM_A56);
E[43] = !(E[43])&&!(E[5])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 57\n"),
#endif
__DRM_A57);
E[44] = E[2]||!(E[8]);
__DRM_R[14] = (__DRM_R[14]&&!(E[44]))||__DRM_R[36];
E[42] = E[13]||E[42];
__DRM_R[16] = (__DRM_R[16]&&!(E[2]))||!(E[42]);
__DRM_R[39] = !(E[18])||!(E[8]);
__DRM_R[40] = !(E[6])||!(E[4]);
E[39] = (__DRM_R[11]&&!(__DRM_R[35])&&!(__DRM_R[19])&&!(E[2]))||(E[39]&&!(E[15]));
__DRM_R[26] = (!(E[2])&&!(E[10])&&__DRM_R[41])||(__DRM_R[26]&&E[10]);
__DRM_R[28] = (__DRM_R[28]&&!(E[44]))||!(E[17])||__DRM_R[36];
__DRM_R[30] = (!(__DRM_R[24])&&__DRM_R[30]&&!(E[2]))||!(E[7])||__DRM_R[36];
__DRM_R[31] = !(E[24])||__DRM_R[36];
__DRM_R[32] = (__DRM_R[32]&&!(E[2])&&!(E[0]))||!(E[4])||__DRM_R[36];
E[4] = !(E[14])||E[2];
__DRM_R[8] = (__DRM_R[29]&&!(E[17]))||(__DRM_R[8]&&!(E[4]));
__DRM_R[10] = (__DRM_R[10]&&!(E[2])&&E[17])||(__DRM_R[29]&&!(E[14]));
E[24] = __DRM_R[36]||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__DRM_A3);
if (E[24]) {
__DRM_A9;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A9\n");
#endif
}
E[45] = E[23]||E[39];
E[46] = E[14]||E[17];
E[39] = (!(E[28])&&!(E[39]))||!(E[45])||!(E[46]);
E[47] = (!(E[39])&&!(E[17]))||(__DRM_R[19]&&!(E[4]));
E[42] = (__DRM_R[20]&&!(E[2])&&E[7])||(E[42]&&!(E[13]))||(E[40]&&E[0]);
E[48] = (__DRM_R[22]&&!(E[4]))||(__DRM_R[5]&&__DRM_R[29]);
__DRM_R[23] = (__DRM_R[35]&&!(E[17]))||(!(E[28])&&E[23])||(!(E[46])&&E[45])||(__DRM_R[19]&&!(E[14]));
__DRM_R[9] = (!(E[22])&&E[19]&&!(E[14]))||(__DRM_R[9]&&!(E[2]));
__DRM_R[24] = (__DRM_R[20]&&!(E[7]))||(!(E[40])&&E[0]);
__DRM_R[12] = (__DRM_R[22]&&!(E[22])&&!(E[14]))||(__DRM_R[12]&&!(E[22])&&!(E[4]));
__DRM_R[13] = E[36]&&E[25];
__DRM_R[37] = (!(__DRM_R[33])&&!(__DRM_R[34])&&__DRM_R[37]&&!(E[4])&&E[9])||!(E[14]);
__DRM_R[33] = (__DRM_R[37]&&!(E[7]))||(__DRM_R[33]&&!(E[44]));
__DRM_R[34] = (__DRM_R[34]&&!(E[2])&&E[7])||(!(E[8])&&__DRM_R[37]);
__DRM_R[35] = (__DRM_R[35]&&!(E[2])&&E[17])||(!(E[39])&&!(E[14]));
__DRM_R[15] = E[21]&&E[11];
__DRM_R[17] = (__DRM_R[5]&&E[19]&&!(E[4]))||(__DRM_R[17]&&!(E[4]));
__DRM_R[27] = __DRM_R[25]&&!(E[2]);
E[4] = __DRM_R[36]||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__DRM_A4);
if (E[4]) {
__DRM_A10;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A10\n");
#endif
}
E[1] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__DRM_A1)&&E[1];
E[1] = E[1];
if (__DRM_R[36]) {
__DRM_A21;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A21\n");
#endif
}
E[19] = !(E[29])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 40\n"),
#endif
__DRM_A40);
E[29] = !(E[19])&&!(E[29])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 41\n"),
#endif
__DRM_A41);
E[19] = !(E[35])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 44\n"),
#endif
__DRM_A44);
E[19] = !(E[19])&&!(E[35])&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 45\n"),
#endif
__DRM_A45);
E[8] = !(E[44])||!(E[8])||__DRM_R[36];
__DRM_R[41] = (E[10]&&__DRM_R[41])||!(E[37]);
E[37] = __DRM_R[36]||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__DRM_A2);
if (E[37]) {
__DRM_A8;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A8\n");
#endif
}
__DRM_R[43] = !(E[26])||__DRM_R[36];
__DRM_R[42] = (__DRM_R[42]&&!(E[2])&&!(__DRM_R[43]))||!(E[30]);
__DRM_R[44] = (__DRM_R[44]&&E[30]&&!(E[3]))||!(E[20])||!(E[33]);
E[33] = __DRM_R[36]||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__DRM_A5);
if (E[33]) {
__DRM_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A11\n");
#endif
}
E[20] = __DRM_R[36]||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__DRM_A7);
if (E[20]) {
__DRM_A13;
#ifdef TRACE_ACTION
fprintf(stderr, "__DRM_A13\n");
#endif
}
__DRM_R[0] = E[32];
__DRM_R[1] = !(E[35]);
__DRM_R[5] = E[31];
__DRM_R[11] = !(E[39]);
__DRM_R[19] = E[47];
__DRM_R[20] = E[42];
__DRM_R[22] = E[48];
__DRM_R[25] = !(E[5]);
__DRM_R[36] = !(_true);
__DRM__reset_input();
return E[8];
}

/* AUTOMATON RESET */

int DRM_reset () {
__DRM_R[0] = _false;
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
__DRM_R[36] = _true;
__DRM_R[37] = _false;
__DRM_R[38] = _false;
__DRM_R[39] = _false;
__DRM_R[40] = _false;
__DRM_R[41] = _false;
__DRM_R[42] = _false;
__DRM_R[43] = _false;
__DRM_R[44] = _false;
__DRM__reset_input();
return 0;
}
