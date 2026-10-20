/* 8051_bank1 FUN_CODE_d6e7 @ 0xd6e7 (no draft)
 * bit: bit 6 of XDATA 0x5407 set, and XDATA 0x5409 != 0 and 0x5408 != 0 (each as a 0/1 char: MOV R7/R6,#1 or #0, then
 * MOV A,R6 / ANL A,R7). The temp t gives the firmware's ANL A,#40H / JZ; 'if (x & 0x40)' gives JNB ACC.6
 * (same lever as the accepted FUN_CODE_db7d; '(unsigned int)(x & 0x40)' also matches).
 * Only caller 0x540c (FUN_CODE_52be).
 * Byte-exact with OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC); MATCH exact None 40/40).
 */
extern unsigned char xdata DAT_EXTMEM_5407, DAT_EXTMEM_5408, DAT_EXTMEM_5409;
bit FUN_CODE_d6e7(void)
{
    unsigned char a, b;
    unsigned char t;
    t = DAT_EXTMEM_5407 & 0x40;
    if (t != 0) {
        a = DAT_EXTMEM_5409 ? 1 : 0;
        b = DAT_EXTMEM_5408 ? 1 : 0;
        if (b & a) return 1;
    }
    return 0;
}
