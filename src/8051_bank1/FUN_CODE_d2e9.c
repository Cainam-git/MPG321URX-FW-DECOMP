/* 8051_bank1 FUN_CODE_d2e9 @ 0xd2e9
 * res = 0; res |= 5a39(); res |= 82d2(); if res == 0: XDATA 0xA629 = 1, else if 0xA629 == 0: res = 0; return res.
 * res is the LARGE local at XDATA 0xA473. The firmware's 'LCALL 5a39 / MOV A,R7 / MOV DPTR' order comes from
 * 'res |= 5a39()' after 'res = 0' (Keil folds 0 | R7 into MOV A,R7 before the store); 'res = 5a39()' puts MOV DPTR first.
 * Callers 0x4102, 0x41c8 (FUN_CODE_3fe7).
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE (MATCH exact None 52/52).
 */
extern unsigned char xdata DAT_EXTMEM_a629;
unsigned char FUN_CODE_5a39(void);
unsigned char FUN_CODE_82d2(void);
unsigned char FUN_CODE_d2e9(void)
{
    unsigned char res;
    res = 0;
    res |= FUN_CODE_5a39();
    res |= FUN_CODE_82d2();
    if (res == 0) DAT_EXTMEM_a629 = 1;
    else if (DAT_EXTMEM_a629 == 0) res = 0;
    return res;
}
