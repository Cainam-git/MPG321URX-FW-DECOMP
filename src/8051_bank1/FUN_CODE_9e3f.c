/* 8051_bank1 FUN_CODE_9e3f @ 0x9e3f (197 B)
 * FUN_CODE_9e3f(ch, reg, v, f): ch in R7 (copied to R1), reg in R4:R5 (high byte R4, low byte R5), v in R3, f in
 * the LARGE parameter slot XDATA 0xA47A; local w at 0xA47B..0xA47C. w = reg >> 8 when XDATA 0xD511 is 0x20,
 * otherwise 1 << (reg >> 8). For ch 0, the low / high byte of w go to XDATA 0xF405 / 0xF406 and 0xD50B = 0x85;
 * for other ch, to 0xF407 / 0xF408 and 0xD50B = 0x86. Then 0xD50C = low byte of reg, t = XDATA 0xD50D with the
 * bits of v set (f == 1) or cleared (otherwise), and t is stored to 0x6500 (ch 0) or 0x6600 at the low byte of reg.
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: before each shift the value 1 is written to ACC (reg51.h); Keil then knows A = 1 and the shift
 * starts 'MOV A,#01H; MOV R6,#00H; MOV R0,AR7'. Each branch has its own count local (n, d).
 */
#include <reg51.h>

extern unsigned char xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_f405, DAT_EXTMEM_f406, DAT_EXTMEM_f407, DAT_EXTMEM_f408;
extern unsigned char xdata DAT_EXTMEM_d50b, DAT_EXTMEM_d50c, DAT_EXTMEM_d50d;
extern unsigned char xdata DAT_EXTMEM_6500[256];
extern unsigned char xdata DAT_EXTMEM_6600[256];

void FUN_CODE_9e3f(unsigned char ch, unsigned int reg, unsigned char v, unsigned char f)
{
    unsigned char c, n, d, t;
    unsigned int w;

    c = ch;
    if (c == 0) {
        if (DAT_EXTMEM_d511 == 0x20) {
            w = (unsigned char)(reg >> 8);
        } else {
            n = reg >> 8;
            ACC = 1;
            w = 1 << n;
        }
        DAT_EXTMEM_f405 = (unsigned char)w;
        DAT_EXTMEM_f406 = w >> 8;
        DAT_EXTMEM_d50b = 0x85;
    } else {
        if (DAT_EXTMEM_d511 == 0x20) {
            w = (unsigned char)(reg >> 8);
        } else {
            d = reg >> 8;
            ACC = 1;
            w = 1 << d;
        }
        DAT_EXTMEM_f407 = (unsigned char)w;
        DAT_EXTMEM_f408 = w >> 8;
        DAT_EXTMEM_d50b = 0x86;
    }
    DAT_EXTMEM_d50c = (unsigned char)reg;
    t = DAT_EXTMEM_d50d;
    if (f == 1) t |= v;
    else t &= ~v;
    if (c == 0) DAT_EXTMEM_6500[(unsigned char)reg] = t;
    else DAT_EXTMEM_6600[(unsigned char)reg] = t;
}
