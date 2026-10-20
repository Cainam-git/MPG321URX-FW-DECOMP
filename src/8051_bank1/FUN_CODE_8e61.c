/* 8051_bank1 FUN_CODE_8e61 @ 0x8e61  Leon2 Main RUN (byte-exact with OPTIMIZE(8,SPEED); real
 * size 0xF9: Ghidra stopped after the first LCALL ?C?LSTKXDATA because the 4-byte constant follows the call inline).
 *
 * Starts the Big chip (Leon2 Main) in two phases through its core-control register 0x9F020008, using the helper
 * chip's AHB bus bridge: FUN_CODE_bcad() reads the 32-bit AHB word whose address is in XDATA 0xA4E7 (returns the
 * value as a 4-byte struct), FUN_CODE_beb5() writes the value in 0xA4F0 to the address in 0xA4EC.
 *   phase 1: ctrl |= 0x00001000;   phase 2: ctrl &= ~0x00001003 (clears bits 0, 1 and 12);
 * then prints "Leon2 (Main) RUN...\r\n" (CODE 0x81A9, printf = FUN_CODE_2820). The 341CQPX reference names
 * 0x00001003 the STOP value and describes this two-phase RUN. 0xA72D / 0xA731 hold the address and the value.
 * Part of the Big chip start-up path on the helper chip.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern DW xdata DAT_EXTMEM_a4e7;
extern DW xdata DAT_EXTMEM_a4ec;
extern DW xdata DAT_EXTMEM_a4f0;
extern DW xdata DAT_EXTMEM_a72d;
extern DW xdata DAT_EXTMEM_a731;
extern DW FUN_CODE_bcad(void);
extern void FUN_CODE_beb5(void);
extern void FUN_CODE_2820(void *fmt, ...) large;
void FUN_CODE_8e61(void)
{
    DAT_EXTMEM_a72d.l = 0x9F020008;
    DAT_EXTMEM_a4e7 = DAT_EXTMEM_a72d;
    DAT_EXTMEM_a731 = FUN_CODE_bcad();
    DAT_EXTMEM_a731.l |= 0x1000;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d;
    DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731;
    FUN_CODE_beb5();
    DAT_EXTMEM_a72d.l = 0x9F020008;
    DAT_EXTMEM_a4e7 = DAT_EXTMEM_a72d;
    DAT_EXTMEM_a731 = FUN_CODE_bcad();
    DAT_EXTMEM_a731.l &= ~0x1003;
    DAT_EXTMEM_a4ec = DAT_EXTMEM_a72d;
    DAT_EXTMEM_a4f0 = DAT_EXTMEM_a731;
    FUN_CODE_beb5();
    FUN_CODE_2820((void code *)0x81a9);   /* "Leon2 (Main) RUN...\r\n" */
}
