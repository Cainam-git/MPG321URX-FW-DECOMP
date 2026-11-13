/* sys_stop_leon2s  (FUN_CODE_cbf2)
 *
 * Stop the input processor.
 * Name basis: proven - prints 'Leon2 (Sub) STOP...'; core control = 0x1003 (twin of sys_stop_leon2m)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cbf2 @ 0xcbf2  Byte-exact (real size 0x46: the inline constant after LCALL ?C?LSTKXDATA
 * is part of the routine).
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern DW xdata reg_ahb_write_addr;
extern DW xdata reg_ahb_write_value;
extern DW xdata startup_core_reg_addr;
extern DW xdata startup_core_reg_value;
extern void reg_ahb_write32(void);
extern void lib_printf517(void *fmt, ...) large;

/* Core control register of the input program's processor, and the value that stops it. */
#define LEON2S_CORE_CONTROL 0x9F120008
#define CORE_CONTROL_STOP   0x00001003

/*
 * Stop the input processor: twin of sys_stop_leon2m with the core control
 * register of the other processor; prints "Leon2 (Sub) STOP...".
 */
void sys_stop_leon2s(void)
{
    startup_core_reg_addr.l = LEON2S_CORE_CONTROL;
    startup_core_reg_value.l = CORE_CONTROL_STOP;
    reg_ahb_write_addr = startup_core_reg_addr;
    reg_ahb_write_value = startup_core_reg_value;
    reg_ahb_write32();
    lib_printf517((void code *)0x8205);   /* "Leon2 (Sub) STOP...\r\n" */
}
