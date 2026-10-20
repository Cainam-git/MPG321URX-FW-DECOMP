/* 8051_bank1 FUN_CODE_ce4b @ 0xce4b (60 B)  Byte-exact with OPTIMIZE(7,SPEED).
 * Calls FUN_CODE_cd07, loads Timer 0 from XDATA 0xA773 (TL0) and 0xA772 (TH0), calls FUN_CODE_9975(0x1D, 4800),
 * sets bit 3 of XDATA 0xDD09, pulses bit 2 of XDATA 0xF3D1 (set, five NOPs, clear) and writes 0x0F to 0xF3DB.
 * Callers: FUN_CODE_3fe7 (0x4284) and FUN_CODE_d987 (0xD98A).
 * FUN_CODE_9975 is a LARGE function: its first parameter arrives in R7 (stored at XDATA 0xA4B9), the 32-bit
 * second parameter in its XDATA parameter block at 0xA4BA, written with ?C?LSTKXDATA and the inline constant
 * 00 00 12 C0. 0xF3D1 is volatile: the clear re-reads it after the NOPs.
 */
#include <intrins.h>
sfr TL0 = 0x8A;
sfr TH0 = 0x8C;
extern unsigned char xdata DAT_EXTMEM_a773, DAT_EXTMEM_a772, DAT_EXTMEM_dd09, DAT_EXTMEM_f3db;
extern unsigned char volatile xdata DAT_EXTMEM_f3d1;
extern void FUN_CODE_cd07(void);
extern void FUN_CODE_9975(unsigned char a, unsigned long b) large;

void FUN_CODE_ce4b(void)
{
    FUN_CODE_cd07();
    TL0 = DAT_EXTMEM_a773;
    TH0 = DAT_EXTMEM_a772;
    FUN_CODE_9975(0x1d, 4800);
    DAT_EXTMEM_dd09 |= 0x08;
    DAT_EXTMEM_f3d1 |= 0x04;
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    DAT_EXTMEM_f3d1 &= ~0x04;
    DAT_EXTMEM_f3db = 0x0f;
}
