/* 8051_bank1 FUN_CODE_abc4 @ 0xabc4 (151 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Forces b to the form 0xA0 | (b & 0x0E) (b is first reset to 0xA0 when (b & 0xF1) != 0xA0), takes v = 0x33 when
 * bit 0 of c is set and 0x13 otherwise, and for each set bit of m (bit 0..6) writes the register pair
 * F01C/F01D, F01E/F01F, F085/F086, F087/F088, F099/F09A, F0A3/F0A4, F076/F077: first = (first & 0xC0) | v,
 * second = b. The same seven registers as FUN_CODE_c59a / FUN_CODE_c87f. m is copied to R4.
 * Only caller: the command switch FUN_CODE_224f, command 1 (bytes 1, 2, 3), followed by FUN_CODE_c59a.
 * 'c &= 1; ... (c == 1)' gives the firmware's 'ANL A,#1 / CJNE A,#1' ('(c & 1) == 1' compiles to JNB ACC.0);
 * the '?:' result is built in R7 and copied to R6.
 */
extern unsigned char xdata DAT_EXTMEM_f01c, DAT_EXTMEM_f01d, DAT_EXTMEM_f01e, DAT_EXTMEM_f01f, DAT_EXTMEM_f085, DAT_EXTMEM_f086, DAT_EXTMEM_f087, DAT_EXTMEM_f088, DAT_EXTMEM_f099, DAT_EXTMEM_f09a, DAT_EXTMEM_f0a3, DAT_EXTMEM_f0a4, DAT_EXTMEM_f076, DAT_EXTMEM_f077;

void FUN_CODE_abc4(unsigned char m, unsigned char b, unsigned char c)
{
    unsigned char v;

    if ((b & 0xf1) != 0xa0) b = 0xa0;
    b = (b & 0x0e) | 0xa0;
    c &= 1;
    v = (c == 1) ? 0x33 : 0x13;
    if (m & 0x01) { DAT_EXTMEM_f01c = (DAT_EXTMEM_f01c & 0xc0) | v; DAT_EXTMEM_f01d = b; }
    if (m & 0x02) { DAT_EXTMEM_f01e = (DAT_EXTMEM_f01e & 0xc0) | v; DAT_EXTMEM_f01f = b; }
    if (m & 0x04) { DAT_EXTMEM_f085 = (DAT_EXTMEM_f085 & 0xc0) | v; DAT_EXTMEM_f086 = b; }
    if (m & 0x08) { DAT_EXTMEM_f087 = (DAT_EXTMEM_f087 & 0xc0) | v; DAT_EXTMEM_f088 = b; }
    if (m & 0x10) { DAT_EXTMEM_f099 = (DAT_EXTMEM_f099 & 0xc0) | v; DAT_EXTMEM_f09a = b; }
    if (m & 0x20) { DAT_EXTMEM_f0a3 = (DAT_EXTMEM_f0a3 & 0xc0) | v; DAT_EXTMEM_f0a4 = b; }
    if (m & 0x40) { DAT_EXTMEM_f076 = (DAT_EXTMEM_f076 & 0xc0) | v; DAT_EXTMEM_f077 = b; }
}
