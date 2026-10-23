/* 8051_bank1 FUN_CODE_9053 @ 0x9053 (248 B, 0x9053..0x914B), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_9053(off, n, p): LARGE parameters off (uint, XDATA 0xA4A9..0xA4AA), n (0xA4AB), p (generic pointer,
 * 0xA4AC..0xA4AE); local i at 0xA4AF. When off + n > 0x3C it prints "KeyDetArray OOR\r\n" (CODE 0x989D) and returns
 * when off >= 0x3C, else n = 0x3C - off. Copies p[0..n-1] to XDATA 0xA5ED + off + i, prints
 * "FillKeyDetectList (%04x) " (CODE 0x98AF) with off, each p[i] with "%02x " (CODE 0x98C9), then "\r\n" (CODE 0x98CF)
 * through FUN_CODE_2820. Caller: the LJMP at 0x21C9 (in code not yet listed in the function table). No aids.
 */
extern unsigned char xdata DAT_EXTMEM_a5ed[];
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_9053(unsigned int off, unsigned char n, unsigned char *p)
{
    unsigned char i;
    if (off + n > 0x3c) {
        FUN_CODE_2820((void code *)0x989d);   /* "KeyDetArray OOR\r\n" */
        if (off >= 0x3c) return;
        n = 0x3c - off;
    }
    for (i = 0; i < n; i++) DAT_EXTMEM_a5ed[off + i] = p[i];
    FUN_CODE_2820((void code *)0x98af, off);   /* "FillKeyDetectList (%04x) " */
    for (i = 0; i < n; i++) FUN_CODE_2820((void code *)0x98c9, p[i]);   /* "%02x " */
    FUN_CODE_2820((void code *)0x98cf);   /* "\r\n" */
}
