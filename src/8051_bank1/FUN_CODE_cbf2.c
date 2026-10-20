/* 8051_bank1 FUN_CODE_cbf2 @ 0xcbf2  Leon2 Sub STOP (byte-exact; real size 0x46: Ghidra stopped at the
 * inline constant after LCALL ?C?LSTKXDATA).
 *
 * Stops the Small chip (Leon2 Sub): writes 0x00001003 to its core-control register 0x9F120008 through the 8051's
 * AHB bridge (FUN_CODE_beb5 writes the value in XDATA 0xA4F0 to the address in 0xA4EC), then prints
 * "Leon2 (Sub) STOP...\r\n" (CODE 0x8205, printf = FUN_CODE_2820). Counterpart of the two-phase RUN (FUN_CODE_8e61 /
 * FUN_CODE_8f5a). Part of the start-up / stop path.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern DW xdata DAT_EXTMEM_a4ec;
extern DW xdata DAT_EXTMEM_a4f0;
extern DW xdata DAT_EXTMEM_a72d;
extern DW xdata DAT_EXTMEM_a731;
extern void FUN_CODE_beb5(void);
extern void FUN_CODE_2820(void *fmt, ...) large;
void FUN_CODE_cbf2(void)
{
    DAT_EXTMEM_a72d.l = 0x9F120008;
    DAT_EXTMEM_a731.l = 0x00001003;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d;
    DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731;
    FUN_CODE_beb5();
    FUN_CODE_2820((void code *)0x8205);   /* "Leon2 (Sub) STOP...\r\n" */
}
