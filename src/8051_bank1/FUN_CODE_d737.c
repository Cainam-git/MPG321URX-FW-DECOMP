/* 8051_bank1 FUN_CODE_d737 @ 0xd737
 * 'using 3' read: sel 0 -> XDATA 0x4D00[idx], sel 1 -> XDATA 0x4E00[idx], else r unset (the firmware returns R6 of
 * bank 3 as it is: MOV R7,1EH). Keil 'using 3' entry PUSH PSW / MOV PSW,#18H. Twin: FUN_CODE_d884 (write).
 * LARGE gives the second test MOV A,R7 / CJNE A,#01H (SMALL: CJNE R7: 51 %); the bases must be array symbols
 * (MOV A,#LOW sym / ADD A,R5).
 * Callers 0x35ed, 0x3654, 0x366e, 0x3694, 0x36bd, 0x37b5, 0x37c6, 0x37e0, 0x3806 (FUN_CODE_34c8), 0x9463 (FUN_CODE_942e).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata DAT_EXTMEM_4d00[];
extern unsigned char xdata DAT_EXTMEM_4e00[];
unsigned char FUN_CODE_d737(unsigned char sel, unsigned char idx) using 3
{
    unsigned char r;
    if (sel == 0) r = DAT_EXTMEM_4d00[idx];
    else if (sel == 1) r = DAT_EXTMEM_4e00[idx];
    return r;
}
