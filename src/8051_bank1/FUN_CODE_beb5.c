/* 8051_bank1 FUN_CODE_beb5 @ 0xbeb5  AHB bridge 32-bit write (OPTIMIZE(8,SPEED) LARGE)
 *
 * void FUN_CODE_beb5(DW addr, DW val): writes one 32-bit word to the SPARC side's AHB bus through the PBus-to-AHB
 * bridge. Bridge not ready (XDATA 0xCD8C bit 0 clear): prints "PBus to AHB bridge Error!!\r\n" (CODE 0xDA1D) and
 * writes nothing. Else: address LSB first to 0xCD80..0xCD83, data LSB first to 0xCD84..0xCD87, start with 0xCD8C =
 * 0x80, wait (NOP loop) for bit 0. LARGE model: parameters at XDATA 0xA4EC (addr) and 0xA4F0 (val). Twin of the read
 * FUN_CODE_bcad (start code 0x40). Used by the Leon2 RUN / STOP routines on the core-control registers.
 * Generic bus helper on the start-up path.
 */
#include <intrins.h>
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern volatile unsigned char xdata DAT_EXTMEM_cd80, DAT_EXTMEM_cd81, DAT_EXTMEM_cd82, DAT_EXTMEM_cd83;
extern volatile unsigned char xdata DAT_EXTMEM_cd84, DAT_EXTMEM_cd85, DAT_EXTMEM_cd86, DAT_EXTMEM_cd87, DAT_EXTMEM_cd8c;
extern void FUN_CODE_2820(void *fmt, ...) large;
void FUN_CODE_beb5(DW addr, DW val)
{
    if (!(unsigned int)(DAT_EXTMEM_cd8c & 1)) {
        FUN_CODE_2820((void code *)0xda1d);   /* "PBus to AHB bridge Error!!\r\n" */
    } else {
        DAT_EXTMEM_cd80 = addr.b[3];
        DAT_EXTMEM_cd81 = addr.b[2];
        DAT_EXTMEM_cd82 = addr.b[1];
        DAT_EXTMEM_cd83 = addr.b[0];
        DAT_EXTMEM_cd84 = val.b[3];
        DAT_EXTMEM_cd85 = val.b[2];
        DAT_EXTMEM_cd86 = val.b[1];
        DAT_EXTMEM_cd87 = val.b[0];
        DAT_EXTMEM_cd8c = 0x80;
        while (!(unsigned int)(DAT_EXTMEM_cd8c & 1)) _nop_();
    }
}
