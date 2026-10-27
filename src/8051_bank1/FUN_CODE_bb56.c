/* 8051_bank1 FUN_CODE_bb56 @ 0xbb56 (116 B)
 * FUN_CODE_bb56(sel, p): sel in R7, p in R4:R5 (high byte R4, low byte R5). w = p >> 8 when XDATA 0xD511 is 0x20,
 * otherwise w = 1 << (p >> 8). For sel 0, w goes to XDATA 0xF405 (low byte) / 0xF406 (high byte) and 0xD50B = 0x85;
 * for other sel, w goes to 0xF407 / 0xF408 and 0xD50B = 0x86. Then 0xD50C = low byte of p; returns XDATA 0xD50D.
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: before each shift the value 1 is written to ACC (reg51.h); Keil then knows A = 1 and the shift
 * starts 'MOV A,#01H; MOV R6,#00H; MOV R0,AR7'. Each branch has its own count local (c, d).
 */
#include <reg51.h>
extern unsigned char xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_f405, DAT_EXTMEM_f406, DAT_EXTMEM_f407, DAT_EXTMEM_f408;
extern unsigned char xdata DAT_EXTMEM_d50b, DAT_EXTMEM_d50c, DAT_EXTMEM_d50d;

unsigned char FUN_CODE_bb56(unsigned char sel, unsigned int p)
{
    unsigned int w;
    unsigned char c, d;

    if (sel == 0) {
        if (DAT_EXTMEM_d511 == 0x20) {
            w = p >> 8;
        } else {
            c = p >> 8;
            ACC = 1;
            w = 1 << c;
        }
        DAT_EXTMEM_f405 = w;
        DAT_EXTMEM_f406 = w >> 8;
        DAT_EXTMEM_d50b = 0x85;
    } else {
        if (DAT_EXTMEM_d511 == 0x20) {
            w = p >> 8;
        } else {
            d = p >> 8;
            ACC = 1;
            w = 1 << d;
        }
        DAT_EXTMEM_f407 = w;
        DAT_EXTMEM_f408 = w >> 8;
        DAT_EXTMEM_d50b = 0x86;
    }
    DAT_EXTMEM_d50c = p;
    return DAT_EXTMEM_d50d;
}
