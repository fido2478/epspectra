/*
 * Library interface to Linux x86 Performance-Monitoring Counters driver.
 *
 * Copyright (C) 1999  Mikael Pettersson
 */
#include "perfctr.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "libperfctr.h"

static int perfctr_fd = -1;	/* to force initialization */

#define CHECK_INIT() \
do { \
  if( perfctr_fd < 0 && perfctr_init() < 0 ) \
    return -1; \
} while(0)

static int have_direct_access;
#ifdef THREADS
#include <pthread.h>
static pthread_key_t current_control;
static pthread_key_t base;
/* Multiple threads should work.... */
#else
static struct perfctr_control current_control;
static struct perfctr_counters base; /* updated by kernel */
#endif

#define rdtsc(low,high) __asm__ __volatile__("rdtsc" : "=a"(low), "=d"(high))
#define rdpmc(ctr,low,high) __asm__ __volatile__("rdpmc" : "=a"(low), "=d"(high) : "c"(ctr))

/*** Stuff following this point was added by brettv@mit.edu 6/24/99 ***/
/* mostly stolen from libpperf package v0.5: */
/* pperf is maintained by M. Patrick Goda.  Information about pperf
   and pperf source code is available at
   <http://qso.lanl.gov/~mpg/pperf.html>.

   Since pperf is in its infancy, bug reports are greatly appreciated
  and can be reported to <loki@lanl.gov>.
*/

static const char *events_format_string(unsigned events_format);

Events p6_events[] = {
  /* Data Cache Unit (DCU) */
  {0,2,0x43,"data_mem_refs","all memory references, cachable and non"},
  {1,2,0x45,"dcu_lines_in","total lines allocated in the DCU"},
  {2,2,0x46,"dcu_m_lines_in","number of M state lines allocated in DCU"},
  {3,2,0x47,"dcu_m_lines_out","number of M lines evicted from the DCU"},
  {4,2,0x48,"dcu_miss_outstanding","number of cycles while DCU miss outstanding"},
  /* Intruction Fetch Unit (IFU) */
  {5,2,0x80,"ifu_ifetch","number of non/cachable instruction fetches"},
  {6,2,0x81,"ifu_ifetch_miss","number of instruction fetch misses"},
  {7,2,0x85,"itlb_miss","number of ITLB misses"},
  {8,2,0x86,"ifu_mem_stall","cycles instruction fetch pipe is stalled"},
  {9,2,0x87,"ild_stall","cycles instruction length decoder is stalled"},
  /* L2 Cache */
  {10,2,0x28,"l2_ifetch","number of L2 instruction fetches"},
  {11,2,0x29,"l2_ld","number of L2 data loads"},
  {12,2,0x2a,"l2_st","number of L2 data stores"},
  {13,2,0x24,"l2_lines_in","number of allocated lines in L2"},
  {14,2,0x26,"l2_lines_out","number of recovered lines from L2"},
  {15,2,0x25,"l2_m_lines_inm","number of modified lines allocated in L2"},
  {16,2,0x27,"l2_m_lines_outm","number of modified lines removed from L2"},
  {17,2,0x2e,"l2_rqsts","number of L2 requests"},
  {18,2,0x21,"l2_ads","number of L2 address strobes"},
  {19,2,0x22,"l2_dbus_busy","number of cycles data bus was busy"},
  {20,2,0x23,"l2_dmus_busy_rd","cycles data bus was busy in xfer from L2 to CPU"},
  /* External Bus Logic (EBL) */
  {21,2,0x62,"bus_drdy_clocks","number of clocks DRDY is asserted"},
  {22,2,0x63,"bus_lock_clocks","number of clocks LOCK is asserted"},
  {23,2,0x60,"bus_req_outstanding","number of outstanding bus requests"},
  {24,2,0x65,"bus_tran_brd","number of burst read transactions"},
  {25,2,0x66,"bus_tran_rfo","number of read for ownership transactions"},
  {26,2,0x67,"bus_trans_wb","number of write back transactions"},
  {27,2,0x68,"bus_tran_ifetch","number of instruction fetch transactions"},
  {28,2,0x69,"bus_tran_inval","number of invalidate transactions"},
  {29,2,0x6a,"bus_tran_pwr","number of partial write transactions"},
  {30,2,0x6b,"bus_trans_p","number of partial transactions"},
  {31,2,0x6c,"bus_trans_io","number of I/O transactions"},
  {32,2,0x6d,"bus_trans_def","number of deferred transactions"},
  {33,2,0x6e,"bus_tran_burst","number of burst transactions"},
  {34,2,0x70,"bus_tran_any","number of all transactions"},
  {35,2,0x6f,"bus_tran_mem","number of memory transactions"},
  {36,2,0x64,"bus_data_rcv","bus cycles this processor is receiving data"},
  {37,2,0x61,"bus_bnr_drv","bus cycles this processor is driving BNR pin"},
  {38,2,0x7a,"bus_hit_drv","bus cycles this processor is driving HIT pin"},
  {39,2,0x7b,"bus_hitm_drv","bus cycles this processor is driving HITM pin"},
  {40,2,0x7e,"bus_snoop_stall","cycles during bus snoop stall"},
  /* Floating Point Unit (FPU) */
  {41,0,0xc1,"comp_flop_ret","number of computational FP operations retired"},
  {42,0,0x10,"flops","number of computational FP operations executed"},
  {43,1,0x11,"fp_assist","number of FP execptions handled by microcode"},
  {44,1,0x12,"mul","number of multiplies"},
  {45,1,0x13,"div","number of divides"},
  {46,0,0x14,"cycles_div_busy","cycles divider is busy"},
  /* Memory Ordering */
  {47,2,0x03,"ld_blocks","number of store buffer blocks"},
  {48,2,0x04,"sb_drains","number of store buffer drain cycles"},
  {49,2,0x05,"misalign_mem_ref","number of misaligned data memory references"},
  /* Instruction Decoding and Retirement */
  {50,2,0xc0,"inst_retired","number of instructions retired"},
  {51,2,0xc2,"uops_retired","number of UOPs retired"},
  {52,2,0xd0,"inst_decoder","number of instructions decoded"},
  /* Interrupts */
  {53,2,0xc8,"hw_int_rx","number of hardware interrupts received"},
  {54,2,0xc6,"cycles_int_masked","cycles interrupts are disabled"},
  {55,2,0xc7,"cycles_int_pending_and_masked","cycles interrupts are disabled with pending interrupts"},
  /* Branches */
  {56,2,0xc4,"br_inst_retired","number of branch instructions retired"},
  {57,2,0xc5,"br_miss_pred_retired","number of mispredicted bracnhes retired"},
  {58,2,0xc9,"br_taken_retired","number of taken branches retired"},
  {59,2,0xca,"br_miss_pred_taken_ret","number of taken mispredictions branches retired"},
  {60,2,0xe0,"br_inst_decoded","number of branch instructions decoded"},
  {61,2,0xe2,"btb_misses","number of branches that miss the BTB"},
  {62,2,0xe4,"br_bogus","number of bogus branches"},
  {63,2,0xe6,"baclears","number of times BACLEAR is asserted"},
  /* Stalls */
  {64,2,0xa2,"resource_stalls","cycles during resource related stalls"},
  {65,2,0xd2,"partial_rat_stalls","cycles or events for partial stalls"},
  /* Segment Register Loads */
  {66,2,0x06,"segment_reg_loads","number of segment register loads"},
  /* Clocks */
  {67,2,0x79,"cpu_clk_unhalted","clocks processor is not halted"}};

Events p5_events[] = {
  {0,2,0x00,"mem_data_read","data read hits"},
  {1,2,0x01,"mem_data_write","data write hits"},
  {2,2,0x02,"tlb_miss","data TLB misses"},
  {3,2,0x03,"mem_data_rm","data read misses"},
  {4,2,0x04,"mem_data_wm","data write misses"},
  {5,2,0x05,"write_hit_me","writes (hits) to M/E"},
  {6,2,0x06,"data_cache_wb","data cache lines written back"},
  {7,2,0x07,"ext_snoops","external snoops"},
  {8,2,0x08,"data_cache_snoop_hits","data cache snoop hits"},
  {9,2,0x09,"mem_accs_both_pipes","memory accesses in both pipes"},
  {10,2,0x0A,"bank_conflicts","bank conflicts"},
  {11,2,0x0B,"misal_mem_ref","misaligned data memory references"},
  {12,2,0x0C,"code_read","code reads"},
  {13,2,0x0D,"code_tlb_miss","code TLB misses"},
  {14,2,0x0E,"code_cache_miss","code cache misses"},
  {15,2,0x0F,"seg_reg_load","segment register loaded"},
  {16,2,0x10,"seg_desc_cache_accs","segment descriptor cache accesses"},
  {17,2,0x11,"seg_desc_cache_hit","segment descriptor cache hits"},
  {18,2,0x12,"branches","branches"},
  {19,2,0x13,"btb_hits","BTB hits"},
  {20,2,0x14,"branch_or_btb_hit","taken branches or BTB hits"},
  {21,2,0x15,"pipeline_flush","pipeline flushes"},
  {22,2,0x16,"ins_exe_b_pipes","instructions executed in both pipes"},
  {23,2,0x17,"ins_exe_v_pipe","instructions executed in V-pipe"},
  {24,2,0x18,"clks_bus_cycle","clocks while bus cycle in progress"},
  {25,2,0x19,"pipe_stl_fwb","pipe stalled by full write buffers"},
  {26,2,0x1A,"pipe_stl_wdr","pipe stalled by waiting for data reads"},
  {27,2,0x1B,"pipe_stl_wme","pipe stalled by writes to M/E"},
  {28,2,0x1C,"locked_bus","locked bus cycles"},
  {29,2,0x1D,"io_read_write","I/O read or write cycles"},
  {30,2,0x1E,"non-cache_mem_ref","non-cacheable memory references"},
  {31,2,0x1F,"pipe_stl_agi","pipeline stalled by AGI"},
  {32,2,0x22,"flops","floating-point operations"},
  {33,2,0x23,"brk_dr0","breakpoint matches on DR0"},
  {34,2,0x24,"brk_dr1","breakpoint matches on DR1"},
  {35,2,0x25,"brk_dr2","breakpoint matches on DR2"},
  {36,2,0x26,"brk_dr3","breakpoint matches on DR3"},
  {37,2,0x27,"hdw_int","hardware interrupts"},
  {38,2,0x28,"mem_read_write_hit","data reads or writes"},
  {39,2,0x29,"mem_read_write_miss","data read/write misses"}};

static int num_events;
static Events *events;

/*** end brettv ***/

static int perfctr_init(void)
{
    struct perfctr_info info;

    if( (perfctr_fd = open("/dev/perfctr", O_RDONLY)) < 0 )
	return -1;
    if( ioctl(perfctr_fd, PERFCTR_INFO, &info) < 0 )
	return -1;
    /* This will be false for pre-MMX P5 (no rdpmc) and
     * WinChip processors (enabling perfctrs disables rdtsc).
     */
    have_direct_access = info.have_rdpmc && info.have_rdtsc;

    /*** Added by brettv@mit.edu, see above ***/
    switch( info.events_format ) {
    case PERFCTR_EVENTS_INTEL_P5:
    case PERFCTR_EVENTS_INTEL_P5MMX:
    case PERFCTR_EVENTS_CYRIX_MII:
      //P5
      num_events=40;
      events=p5_events;
      break;
    case PERFCTR_EVENTS_INTEL_P6:
    case PERFCTR_EVENTS_INTEL_PII:
      //P6
      num_events=68;
      events=p6_events;
      break;
    default:
      fprintf(stderr, "Architecture (events_format %u) not supported\n", info.events_format);
      perfctr_fd=-1;
      return -1;
    }
#ifdef THREADS
    if(pthread_key_create(&base, NULL)!=0 ||
       pthread_key_create(&current_control, NULL)!=0) {
	 fprintf(stderr,"libperfctr: Could not create thread specific variable.\n");
	 return -1;
    }
#endif

  /*** end section added by brettv ***/
  return 0;
}

int perfctr_info(struct perfctr_info *info)
{
    CHECK_INIT();
    return ioctl(perfctr_fd, PERFCTR_INFO, info);
}

int perfctr_enable(struct perfctr_control *control)
{
    struct perfctr_enable enable;

    CHECK_INIT();
    enable.control = *control;
#ifdef THREADS
    enable.user=(perfctr_counters *) pthread_getspecific(base);
    if(enable.user == 0) {
      //init thread specific data
      pthread_setspecific(base,(void *) new perfctr_counters);
      pthread_setspecific(current_control,(void *) new perfctr_control);
      enable.user=(perfctr_counters *) pthread_getspecific(base);
    }
    perfctr_control *pcontrol=(perfctr_control *) pthread_getspecific(current_control);
    *pcontrol=*control;
#else
    current_control = *control;
    enable.user = &base;
#endif
    if( ioctl(perfctr_fd, PERFCTR_ENABLE, &enable) < 0 ) {
#ifdef THREADS
      pcontrol->evntsel[0] = 0;
#else
      current_control.evntsel[0] = 0;
#endif
	return -1;
    }
    return 0;
}

int perfctr_disable()
{
  struct perfctr_control control = {{0,0}};
  return perfctr_enable(&control);
}


int perfctr_read(struct perfctr_state *state)
{
    CHECK_INIT();
#ifdef THREADS
    if( have_direct_access && ((perfctr_control *) pthread_getspecific(current_control))->evntsel[0] ) {
#else
    if( have_direct_access && current_control.evntsel[0] ) {
#endif
	perfctr_uint64_t tsc_start, tsc, pmc[2];
#ifdef THREADS
	perfctr_counters *pbase = (perfctr_counters *) pthread_getspecific(base);
#endif
	do {
#ifdef THREADS
	    tsc_start = pbase->tsc_start;
#else
	    tsc_start = base.tsc_start;
#endif
	    rdtsc(tsc.u32[0], tsc.u32[1]);
	    rdpmc(0, pmc[0].u32[0], pmc[0].u32[1]);
	    rdpmc(1, pmc[1].u32[0], pmc[1].u32[1]);
#ifdef THREADS
	    state->counters.tsc.u64 = pbase->tsc.u64 + (tsc.u64 - tsc_start.u64);
	    state->counters.pmc[0].u64 = pbase->pmc[0].u64 + pmc[0].u64;
	    state->counters.pmc[1].u64 = pbase->pmc[1].u64 + pmc[1].u64;
	} while( tsc_start.u32[0] != pbase->tsc_start.u32[0] );
#else
	    state->counters.tsc.u64 = base.tsc.u64 + (tsc.u64 - tsc_start.u64);
	    state->counters.pmc[0].u64 = base.pmc[0].u64 + pmc[0].u64;
	    state->counters.pmc[1].u64 = base.pmc[1].u64 + pmc[1].u64;
	} while( tsc_start.u32[0] != base.tsc_start.u32[0] );
#endif
	state->counters.tsc_start = tsc_start;
#ifdef THREADS
	state->control = *((perfctr_control *) pthread_getspecific(current_control));
	state->user = pbase;
#else
	state->control = current_control;
	state->user = &base;
#endif
	return 0;
    } else
	return ioctl(perfctr_fd, PERFCTR_READ, state);
}

/*** Added by brettv@mit.edu, see above ***/

//pass in the #defs from libperfctr.h as events
//use CLOCKS if you want to measure clocks
//measures everything only in CPL=3, ie user-space 
int start_counters( int event0, int event1 )
{
  int cpl0,cpl1;
  unsigned int umask0 = 0x0, umask1 = 0x0;
  struct perfctr_control control;
  struct perfctr_info info;
  
  cpl0 = cpl1 =2; //user space events  

  CHECK_INIT();

  if( ioctl(perfctr_fd, PERFCTR_INFO, &info) < 0 )
    return -1;

  //CLOCKS
  if(event0 < 0) {
    event0=0;
    cpl0=6; //user space clocks
  }
  if(event1 < 0) {
    event1=0;
    cpl1=6; //user space clocks
  }

  /* Sanity check- have been asked for non-existent events? */
  if (event0 > num_events)
    {
      fprintf(stderr,"error: Fatal error.  No event %d defined for %s.\n",
	      event0,events_format_string(info.events_format));
      exit(0);
    }
  if (event1 > num_events)
    {
      fprintf(stderr,"error: Fatal error.  No event %d defined for %s.\n",
	      event1,events_format_string(info.events_format));
      exit(0);
    }

  if(events==p5_events) {
    /* 
     * 
     * Pentium:
     *     
     *     Both events are selected with a single event selection
     *     register (CESR).
     *     
     *     3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 
     *     1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
     *     
     *     x x x x x x P [ C ] [    E    ] x x x x x x P [ C ] [    E    ]
     *     x x x x x x C [ C ] [    S    ] x x x x x x C [ C ] [    S    ]
     *     x x x x x x 1 [ 1 ] [    1    ] x x x x x x 0 [ 0 ] [    0    ]
     *     
     *     xxx: RESERVED
     *     PC1, PC0: 0=(Event Increment) 1=(Event Overflow)
     *     CC1, CC0: CPL Level to Monitor, possibilities are
     *               000 = Count Nothing
     *               001 = Count Event while CPL = 0,1,2
     *               010 = Count Event while CPL = 3
     *               011 = Count Event while CPL = 0,1,2,3
     *               100 = Count Nothing
     *               101 = Count Clocks while CPL = 0,1,2
     *               110 = Count Clocks while CPL = 3
     *               111 = Count Clocks while CPL = 0,1,2,3
     *               Here we only use 000, 001, 010 and 011.
     *     ES1, ES0: Event selection code, see .h file
     *     
     */

    /* Broken
       
    control.evntsel[0] = (events[event0].opcode) ^ (cpl0 << 6) ^ (0 << 9) ^
      (events[event1].opcode << 16) ^ (cpl1 << 22) ^ (0 << 25);

      control.evntsel[1] = 0;
    */
    fprintf(stderr,"Pentium performance monitoring support not complete.\n");
    exit(-1);

  } else {

    /* Pentium Pro/II:
     *     
     *     Each event is specified seperately in an EVENTSEL register.
     *     
     *     3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 
     *     1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
     *     
     *     [      C      ] I x x I B O O U [      U      ] [      E      ]
     *     [      M      ] N x x N P D S S [      M      ] [      V      ]
     *     [      K      ] V x x T 0 M P P [      K      ] [      T      ]
     *     
     *     xxx: RESERVED
     *     CMK: Counter Mask
     *     INV: Inverts CMK, 0=(Inverted) 1=(Non-Inverted)
     *     INT: APIC Signalling of counter overflow 1=(Enable) 0=(Disable)
     *     BP0: Signal Overflow via BP0 pin 1=(Enable) 0=(Disable)
     *     ODM: Occurance/Duration Mode Select 1=(Occurance) 0=(Duration)
     *     OSP: Count events while CPL=0 1=(Enable) 0=(Disable)
     *     USP: Count events while CPL=1,2,3 1=(Enable) 0=(Disable)
     *     UMK: Unit Mask (Used for MESI protocol events)
     *     EVT: Event selection code, see events.c
     */

    /* If we are checking an L2 event that requires a mask, then set
     *     the mask to count all MESI events.
     */

    if (event0 == 10 || event0 == 11 || event0 == 12 || event0 == 17)
      umask0 = 0xf;
    
    if (event1 == 10 || event1 == 11 || event1 == 12 || event1 == 17)
      umask1 = 0xf;
      
    /* To use CPL = 0,1,2,3 consistently, we need to reverse bits
     *     for CPL = 1 and CPL = 2
     */      

    if (cpl0 == 1 || cpl0 == 2)
      cpl0 = ~cpl0 & 0x3;

    if (cpl1 == 1 || cpl1 == 2)
      cpl1 = ~cpl1 & 0x3;

    control.evntsel[0] = (events[event0].opcode) ^ (umask0 << 8) ^ (cpl0 << 16) ^
      (0 << 18) ^ (0 << 19) ^ (0 << 20) ^ (1 << 22) ^ (0 << 24); //enable
    
    control.evntsel[1] = (events[event1].opcode) ^ (umask1 << 8) ^ (cpl1 << 16) ^
      (0 << 18) ^ (0 << 19) ^ (0 << 20) ^ (0 << 22) ^ (0 << 24);

  }

  /* To look at what values we passed. */
#ifdef DEBUG
  printf("Event0 (Passed %d):\n",event0);
  printf("\t%d %d 0x%x %s %s\n",events[event0].id,events[event0].rflag,
	 events[event0].opcode,events[event0].name,events[event0].desc);

  printf("Event1 (Passed %d):\n",event1);
  printf("\t%d %d 0x%x %s %s\n",events[event1].id,events[event1].rflag,
	 events[event1].opcode,events[event1].name,events[event1].desc);

  printf("CPL0: %d  CPL1: %d \n",cpl0,cpl1);

  printf("es0: 0x%x\n",control.evntsel[0]);
  printf("es1: 0x%x\n",control.evntsel[1]);
#endif

  if( perfctr_enable(&control) < 0 ) {
    return -1;
  }

  return 0;
}

/**** Based on test-perfctr.c from perfctr v0.2 package ***/
static const char *events_format_string(unsigned events_format)
{
    switch( events_format ) {
      case PERFCTR_EVENTS_INTEL_P5:
	return "Intel Pentium";
      case PERFCTR_EVENTS_INTEL_P5MMX:
	return "Intel Pentium MMX";
      case PERFCTR_EVENTS_INTEL_P6:
	return "Intel Pentium Pro";
      case PERFCTR_EVENTS_INTEL_PII:
	return "Intel Pentium II";
      case PERFCTR_EVENTS_CYRIX_MII:
	return "Cyrix MII";
      default:
	return "?";
    }
}
int perfctr_print_info(void)
{
  struct perfctr_info info;
  CHECK_INIT();

  if( ioctl(perfctr_fd, PERFCTR_INFO, &info) < 0 )
    return -1;
  fprintf(stderr,"\nPerfCtr Info:\n");
  fprintf(stderr,"-------------\n");
  fprintf(stderr,"driver major_version\t\t%u\n", info.major_version);
  fprintf(stderr,"driver minor_version\t\t%u\n", info.minor_version);
  fprintf(stderr,"events_format\t\t%u (%s)\n",
	 info.events_format,
	 events_format_string(info.events_format));
  fprintf(stderr,"have_rdpmc\t\t%u\n", info.have_rdpmc);
  fprintf(stderr,"have_rdtsc\t\t%u\n", info.have_rdtsc);
  return 0;
}
/*** end section added by brettv ***/
