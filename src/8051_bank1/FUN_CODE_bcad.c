/* 8051_bank1 FUN_CODE_bcad @ 0xbcad  AHB bridge 32-bit read (byte-exact with OPTIMIZE(8,SPEED) LARGE)
 *
 * DW FUN_CODE_bcad(DW addr): reads one 32-bit word from the SPARC side's AHB bus through the helper chip's PBus-to-AHB
 * bridge. If the bridge is not ready (XDATA 0xCD8C bit 0 clear) it prints "PBus to AHB bridge Error!!\r\n" (CODE
 * 0xDA1D) and returns its result buffer unchanged; else it writes the address LSB first to 0xCD80..0xCD83, starts the
 * read with 0xCD8C = 0x40, waits (NOP loop) until bit 0 is set again and collects the data from 0xCD88..0xCD8B (LSB
 * first). LARGE model: the parameter lives at XDATA 0xA4E7, the returned union at 0xA4EB (Keil returns a pointer).
 * Used by the Leon2 RUN routines (FUN_CODE_8e61 / 8f5a) on the core-control registers 0x9F020008 / 0x9F120008.
 * Idiom: the ready test is written '(unsigned int)(reg & 1)', which Keil compiles to ANL A,#1 / JNZ, not JB.
 * Generic bus helper on the start-up path.
 */
#include <intrins.h>
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern volatile unsigned char xdata DAT_EXTMEM_cd80, DAT_EXTMEM_cd81, DAT_EXTMEM_cd82, DAT_EXTMEM_cd83;
extern volatile unsigned char xdata DAT_EXTMEM_cd88, DAT_EXTMEM_cd89, DAT_EXTMEM_cd8a, DAT_EXTMEM_cd8b, DAT_EXTMEM_cd8c;
extern void FUN_CODE_2820(void *fmt, ...) large;
DW FUN_CODE_bcad(DW addr)
{
    DW r;
    if (!(unsigned int)(DAT_EXTMEM_cd8c & 1)) {
        FUN_CODE_2820((void code *)0xda1d);   /* "PBus to AHB bridge Error!!\r\n" */
    } else {
        DAT_EXTMEM_cd80 = addr.b[3];
        DAT_EXTMEM_cd81 = addr.b[2];
        DAT_EXTMEM_cd82 = addr.b[1];
        DAT_EXTMEM_cd83 = addr.b[0];
        DAT_EXTMEM_cd8c = 0x40;
        while (!(unsigned int)(DAT_EXTMEM_cd8c & 1)) _nop_();
        r.b[3] = DAT_EXTMEM_cd88;
        r.b[2] = DAT_EXTMEM_cd89;
        r.b[1] = DAT_EXTMEM_cd8a;
        r.b[0] = DAT_EXTMEM_cd8b;
    }
    return r;
}
