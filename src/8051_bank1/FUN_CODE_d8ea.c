/* 8051_bank1 FUN_CODE_d8ea @ 0xd8ea (32 B)
 * n = XDATA 0xD520 & 3; XDATA 0xD801 = 0x78 when n is 0, else 0x78 >> n.
 * No LCALL or LJMP to 0xD8EA occurs in the bank-1 image. Options: OPTIMIZE(8,SPEED).
 * Source form: the shifted value is written to ACC (reg51.h) and the shift reads ACC; Keil then loads A
 * ('MOV A,#78H') before the count ('MOV R0,AR7'). With the constant written in the shift, Keil loads R0 first.
 */
#include <reg51.h>

extern unsigned char xdata DAT_EXTMEM_d520;
extern unsigned char xdata DAT_EXTMEM_d801;

void FUN_CODE_d8ea(void)
{
    unsigned char n;

    n = DAT_EXTMEM_d520 & 3;
    if (n == 0) {
        DAT_EXTMEM_d801 = 0x78;
    } else {
        ACC = 0x78;
        DAT_EXTMEM_d801 = ACC >> n;
    }
}
