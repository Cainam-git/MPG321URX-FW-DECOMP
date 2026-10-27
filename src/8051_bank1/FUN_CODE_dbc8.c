/* 8051_bank1 FUN_CODE_dbc8 @ 0xdbc8 (23 B)
 * Clears bit n of the XDATA byte 0xA0F3: DAT_EXTMEM_a0f3 = old & ~(1 << n). FUN_CODE_dee2 returns the same byte.
 * Options: OPTIMIZE(7,SPEED) (also level 8).
 * Source form: the old byte is read into a local first; the 1 is written to ACC (reg51.h) and the shift reads
 * ACC, so Keil loads A ('MOV A,#01H') before the count ('MOV R0,AR7').
 */
#include <reg51.h>

extern unsigned char xdata DAT_EXTMEM_a0f3;

void FUN_CODE_dbc8(unsigned char n)
{
    unsigned char t;

    t = DAT_EXTMEM_a0f3;
    ACC = 1;
    DAT_EXTMEM_a0f3 = t & ~(ACC << n);
}
