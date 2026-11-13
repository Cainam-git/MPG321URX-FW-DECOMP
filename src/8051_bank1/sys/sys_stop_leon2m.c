/* sys_stop_leon2m  (FUN_CODE_cbac)
 *
 * Stop the main processor.
 * Name basis: proven - prints 'Leon2 (Main) STOP...'; core control 0x9F020008 = 0x1003; power-off, power-
 *   saving and crash paths
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cbac @ 0xcbac  Byte-exact (real size 0x46: the inline constant after LCALL ?C?LSTKXDATA
 * is part of the routine).
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern DW xdata reg_ahb_write_addr;
extern DW xdata reg_ahb_write_value;
extern DW xdata startup_core_reg_addr;
extern DW xdata startup_core_reg_value;
extern void reg_ahb_write32(void);
extern void lib_printf517(void *fmt, ...) large;

/* Core control register of the main program's processor, and the value that stops it. */
#define LEON2M_CORE_CONTROL 0x9F020008
#define CORE_CONTROL_STOP   0x00001003

/*
 * Stop the main processor: write CORE_CONTROL_STOP to its core control
 * register through reg_ahb_write32 (address in reg_ahb_write_addr, value in
 * reg_ahb_write_value), then print "Leon2 (Main) STOP...". Counterpart of the
 * two-phase run routines startup_run_leon2m / startup_run_leon2s.
 */
void sys_stop_leon2m(void)
{
    startup_core_reg_addr.l = LEON2M_CORE_CONTROL;
    startup_core_reg_value.l = CORE_CONTROL_STOP;
    reg_ahb_write_addr = startup_core_reg_addr;
    reg_ahb_write_value = startup_core_reg_value;
    reg_ahb_write32();
    lib_printf517((void code *)0x81bf);   /* "Leon2 (Main) STOP...\r\n" */
}
