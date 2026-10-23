/* 8051_bank2 FUN_CODE_d393 @ 0xD393..0xD426 (147 bytes)
 * Options: OPTIMIZE(8,SPEED) LARGE. Only caller: FUN_CODE_a36c, command 0x11 (tail LJMP at 0xA3B8) with
 * a = XDATA 0xF19E and b = XDATA 0xF19F.
 * Parameters a (XDATA 0x08EE) and b (unsigned int, 0x08EF). An index a above 8 is replaced by 7. With
 * k = CODE 0xE543[a] (the 8-byte table 0x0C, 0x18, 0x20, 0x30, 0x40, 0x60, 0x60, 0xC0) it writes
 * TH1 = -(k * 2000000 / 384 / (b * 100)) (?C?LMUL, ?C?ULDIV, ?C?IMUL; b * 100 is an unsigned int product) and
 * XDATA 0x09D0 (unsigned int) = (float)k * 8.0e8 / 6.4e7 (?C?FCASTC, ?C?FPMUL, ?C?FPDIV, ?C?CASTF).
 */
#include <reg51.h>
extern unsigned char code DAT_CODE_e543[];
extern unsigned int xdata DAT_EXTMEM_09d0;

void FUN_CODE_d393(unsigned char a, unsigned int b)
{
    if (a > 8) a = 7;
    TH1 = -(unsigned char)((unsigned long)DAT_CODE_e543[a] * 2000000 / 384 / (b * 100));
    DAT_EXTMEM_09d0 = (float)DAT_CODE_e543[a] * 8.0e8 / 6.4e7;
}
