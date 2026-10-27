/* 8051_bank1 FUN_CODE_ab2c @ 0xab2c (152 B)
 * FUN_CODE_ab2c(sel, p, v): sel in R7, p in R4:R5 (high byte R4, low byte R5), v in R3. XDATA int 0xA774 =
 * p >> 8 when XDATA 0xD511 is 0x20, otherwise 1 << (p >> 8). For sel 0, the low / high byte of 0xA774 go to
 * XDATA 0xF405 / 0xF406 and 0x6500[low byte of p] = v; for other sel, to 0xF407 / 0xF408 and 0x6600[low byte of p] = v.
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: before each shift the value 1 is written to ACC (reg51.h); Keil then knows A = 1 and the shift
 * starts 'MOV A,#01H; MOV R6,#00H; MOV R0,AR7'. Each branch has its own count local (c, d).
 */
#include <reg51.h>
extern unsigned char xdata DAT_EXTMEM_d511;
extern unsigned int xdata DAT_EXTMEM_a774;
extern unsigned char xdata DAT_EXTMEM_f405, DAT_EXTMEM_f406, DAT_EXTMEM_f407, DAT_EXTMEM_f408;
extern unsigned char xdata DAT_EXTMEM_6500[256];
extern unsigned char xdata DAT_EXTMEM_6600[256];

void FUN_CODE_ab2c(unsigned char sel, unsigned int p, unsigned char v)
{
    unsigned char c, d;

    if (sel == 0) {
        if (DAT_EXTMEM_d511 == 0x20) {
            DAT_EXTMEM_a774 = p >> 8;
        } else {
            c = p >> 8;
            ACC = 1;
            DAT_EXTMEM_a774 = 1 << c;
        }
        DAT_EXTMEM_f405 = DAT_EXTMEM_a774;
        DAT_EXTMEM_f406 = DAT_EXTMEM_a774 >> 8;
        DAT_EXTMEM_6500[(unsigned char)p] = v;
    } else {
        if (DAT_EXTMEM_d511 == 0x20) {
            DAT_EXTMEM_a774 = p >> 8;
        } else {
            d = p >> 8;
            ACC = 1;
            DAT_EXTMEM_a774 = 1 << d;
        }
        DAT_EXTMEM_f407 = DAT_EXTMEM_a774;
        DAT_EXTMEM_f408 = DAT_EXTMEM_a774 >> 8;
        DAT_EXTMEM_6600[(unsigned char)p] = v;
    }
}
