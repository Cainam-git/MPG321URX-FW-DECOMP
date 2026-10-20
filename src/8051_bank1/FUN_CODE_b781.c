/* 8051_bank1 FUN_CODE_b781 @ 0xb781 (129 B, byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * Returns an unsigned long built from XDATA 0xA800..0xAFFF: v = 0; generic pointer p = XDATA 0xA800; four passes
 * k = 0..3, each summing 0x200 bytes *p++ into the unsigned char s (?C?ILDIX post-increment, ?C?CLDPTR read) and
 * then shifting v left by s + 8 (?C?LSHL). LARGE locals: k at XDATA 0xA4B3, s at 0xA4B4, v at 0xA4B5..0xA4B8,
 * p at 0xA4B9..0xA4BB; the 0x200 counter is kept in R6:R7. Callers: LCALL at 0x21B0 and 0x2448.
 * Source form: p is set from an extern array symbol (MOV A,#LOW DAT_EXTMEM_a800); a constant-cast address gives
 * CLR A for the low byte. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_a800[];

unsigned long FUN_CODE_b781(void)
{
    unsigned char k, s;
    unsigned long v;
    unsigned char *p;
    unsigned int j;
    v = 0;
    p = DAT_EXTMEM_a800;
    for (k = 0; k < 4; k++) {
        s = 0;
        for (j = 0; j < 0x200; j++) s += *p++;
        v <<= s + 8;
    }
    return v;
}
