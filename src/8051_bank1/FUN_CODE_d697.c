/* 8051_bank1 FUN_CODE_d697 @ 0xd697 (no draft)
 * Ring-buffer read: when FUN_CODE_dce3() == 0, r = XDATA 0xA566[XDATA 0xA565] and the index 0xA565 steps on,
 * wrapping at 0x80; otherwise r = 0xFF. Returns r.
 * r lives in R6 only with REGFILE(R.ORC) (without it Keil puts r in DATA: 57 %).
 * Callers 0x3be7 (FUN_CODE_38a7), 0x82ee (FUN_CODE_82d2).
 * Byte-exact with OPTIMIZE(8,SPEED) REGFILE(R.ORC) (also level 7 with REGFILE; MATCH exact None 40/40).
 */
extern unsigned char xdata DAT_EXTMEM_a565;
extern unsigned char xdata DAT_EXTMEM_a566[];
unsigned char FUN_CODE_dce3(void);
unsigned char FUN_CODE_d697(void)
{
    unsigned char r;
    if (FUN_CODE_dce3() == 0) {
        r = DAT_EXTMEM_a566[DAT_EXTMEM_a565];
        DAT_EXTMEM_a565++;
        if (DAT_EXTMEM_a565 == 0x80) DAT_EXTMEM_a565 = 0;
    } else r = 0xff;
    return r;
}
