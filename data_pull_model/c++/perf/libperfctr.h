/*
 * Library interface to Linux x86 Performance-Monitoring Counters driver.
 *
 * Copyright (C) 1999  Mikael Pettersson
 */
#ifndef __LIB_PERFCTR_H
#define __LIB_PERFCTR_H

#include "perfctr.h"

extern int perfctr_info(struct perfctr_info*);
extern int perfctr_enable(struct perfctr_control*);
extern int perfctr_disable();
extern int perfctr_read(struct perfctr_state*);
extern int perfctr_print_info();

/*** Everything following this point was added by brettv@mit.edu 6/24/99 ***/
/* mostly stolen from libpperf package v0.5: */
/* pperf is maintained by M. Patrick Goda.  Information about pperf
   and pperf source code is available at
   <http://qso.lanl.gov/~mpg/pperf.html>.

   Since pperf is in its infancy, bug reports are greatly appreciated
  and can be reported to <loki@lanl.gov>.
*/

/* Define available events in Event structure. */

typedef struct {
  int id;
  int rflag;
  unsigned int opcode;
  char name[40];
  char desc[120];
} Events;

extern Events p6_events[];
extern Events p5_events[];
/* Event defines for easier use of events. */

#define CLOCKS -1

/* Pentium Events */

#define P5_MEM_DATA_READ 0 
#define P5_MEM_DATA_WRITE 1 
#define P5_TLB_MISS 2 
#define P5_MEM_DATA_RM 3 
#define P5_MEM_DATA_WM 4 
#define P5_WRITE_HIT_ME 5 
#define P5_DATA_CACHE_WB 6 
#define P5_EXT_SNOOPS 7 
#define P5_DATA_CACHE_SNOOP_HITS 8 
#define P5_MEM_ACCS_BOTH_PIPES 9 
#define P5_BANK_CONFLICTS 10 
#define P5_MISAL_MEM_REF 11 
#define P5_CODE_READ 12 
#define P5_CODE_TLB_MISS 13 
#define P5_CODE_CACHE_MISS 14 
#define P5_SEG_REG_LOAD 15 
#define P5_SEG_DESC_CACHE_ACCS 16 
#define P5_SEG_DESC_CACHE_HIT 17 
#define P5_BRANCHES 18 
#define P5_BTB_HITS 19 
#define P5_BRANCH_OR_BTB_HIT 20 
#define P5_PIPELINE_FLUSH 21 
#define P5_INS_EXE_B_PIPES 22 
#define P5_INS_EXE_V_PIPE 23 
#define P5_CLKS_BUS_CYCLE 24 
#define P5_PIPE_STL_FWB 25 
#define P5_PIPE_STL_WDR 26 
#define P5_PIPE_STL_WME 27 
#define P5_LOCKED_BUS 28 
#define P5_IO_READ_WRITE 29 
#define P5_NON_CACHE_MEM_REF 30 
#define P5_PIPE_STL_AGI 31 
#define P5_FLOPS 32 
#define P5_BRK_DR0 33 
#define P5_BRK_DR1 34 
#define P5_BRK_DR2 35 
#define P5_BRK_DR3 36 
#define P5_HDW_INT 37 
#define P5_MEM_READ_WRITE_HIT 38 
#define P5_MEM_READ_WRITE_MISS 39 
#define P5_CLOCKS -1

/* Pentium Pro/PII Events */

#define P6_DATA_MEM_REFS 0 
#define P6_DCU_LINES_IN 1 
#define P6_DCU_M_LINES_IN 2 
#define P6_DCU_M_LINES_OUT 3 
#define P6_DCU_MISS_OUTSTANDING 4 
#define P6_IFU_IFETCH 5 
#define P6_IFU_IFETCH_MISS 6 
#define P6_ITLB_MISS 7 
#define P6_IFU_MEM_STALL 8 
#define P6_ILD_STALL 9 
#define P6_L2_IFETCH 10 
#define P6_L2_LD 11 
#define P6_L2_ST 12 
#define P6_L2_LINES_IN 13 
#define P6_L2_LINES_OUT 14 
#define P6_L2_M_LINES_INM 15 
#define P6_L2_M_LINES_OUTM 16 
#define P6_L2_RQSTS 17 
#define P6_L2_ADS 18 
#define P6_L2_DBUS_BUSY 19 
#define P6_L2_DMUS_BUSY_RD 20 
#define P6_BUS_DRDY_CLOCKS 21 
#define P6_BUS_LOCK_CLOCKS 22 
#define P6_BUS_REQ_OUTSTANDING 23 
#define P6_BUS_TRAN_BRD 24 
#define P6_BUS_TRAN_RFO 25 
#define P6_BUS_TRANS_WB 26 
#define P6_BUS_TRAN_IFETCH 27 
#define P6_BUS_TRAN_INVAL 28 
#define P6_BUS_TRAN_PWR 29 
#define P6_BUS_TRANS_P 30 
#define P6_BUS_TRANS_IO 31 
#define P6_BUS_TRANS_DEF 32 
#define P6_BUS_TRAN_BURST 33 
#define P6_BUS_TRAN_ANY 34 
#define P6_BUS_TRAN_MEM 35 
#define P6_BUS_DATA_RCV 36 
#define P6_BUS_BNR_DRV 37 
#define P6_BUS_HIT_DRV 38 
#define P6_BUS_HITM_DRV 39 
#define P6_BUS_SNOOP_STALL 40 
#define P6_COMP_FLOP_RET 41 
#define P6_FLOPS 42 
#define P6_FP_ASSIST 43 
#define P6_MUL 44 
#define P6_DIV 45 
#define P6_CYCLES_DIV_BUSY 46 
#define P6_LD_BLOCKS 47 
#define P6_SB_DRAINS 48 
#define P6_MISALIGN_MEM_REF 49 
#define P6_INST_RETIRED 50 
#define P6_UOPS_RETIRED 51 
#define P6_INST_DECODER 52 
#define P6_HW_INT_RX 53 
#define P6_CYCLES_INT_MASKED 54 
#define P6_CYCLES_INT_PENDING_AND_MASKED 55 
#define P6_BR_INST_RETIRED 56 
#define P6_BR_MISS_PRED_RETIRED 57 
#define P6_BR_TAKEN_RETIRED 58 
#define P6_BR_MISS_PRED_TAKEN_RET 59 
#define P6_BR_INST_DECODED 60 
#define P6_BTB_MISSES 61 
#define P6_BR_BOGUS 62 
#define P6_BACLEARS 63 
#define P6_RESOURCE_STALLS 64 
#define P6_PARTIAL_RAT_STALLS 65 
#define P6_SEGMENT_REG_LOADS 66 
#define P6_CPU_CLK_UNHALTED 67 
#define P6_CLOCKS -1

/* C Code Declarations */
#ifdef __cplusplus
extern "C" {
#endif

extern int start_counters( int event0, int event1 );
#ifdef __cplusplus
}
#endif

#endif /* __LIB_PERFCTR_H */

