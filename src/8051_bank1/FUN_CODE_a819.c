/* 8051_bank1 FUN_CODE_a819 @ 0xA819..0xA8BB (162 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_a819(off, n, p): LARGE parameters off (uint, XDATA 0xA4A9..0xA4AA), n (0xA4AB), p (generic pointer,
 * 0xA4AC..0xA4AE); i is kept in R7. When off + n > 0x12 it prints "CutPwArray OOR %d %d\r\n" (CODE 0xCEE6) with
 * off and n, returns when off >= 0x12, else n = 0x12 - off. Then copies p[0..n-1] to XDATA 0xA6AF + off + i.
 * Same shape as FUN_CODE_9053 (limit 0x3C, 0xA5ED). Caller: the tail LJMP at 0x21F5 in FUN_CODE_1c3c (type 10).
 * The print arguments are passed as unsigned int. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_a6af[];
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_a819(unsigned int off, unsigned char n, unsigned char *p)
{
    unsigned char i;
    if (off + n > 0x12) {
        FUN_CODE_2820((void code *)0xcee6, off, (unsigned int)n);   /* "CutPwArray OOR %d %d\r\n" */
        if (off >= 0x12) return;
        n = 0x12 - off;
    }
    for (i = 0; i < n; i++) DAT_EXTMEM_a6af[off + i] = p[i];
}
