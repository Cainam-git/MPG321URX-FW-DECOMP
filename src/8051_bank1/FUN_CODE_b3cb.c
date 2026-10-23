/* 8051_bank1 FUN_CODE_b3cb @ 0xB3CB..0xB456 (139 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_b3cb(off, n, p): LARGE parameters off (uint, XDATA 0xA4A9..0xA4AA), n (0xA4AB), p (generic pointer,
 * 0xA4AC..0xA4AE); i is kept in R7. When off + n > 0x1E it prints "SetZPArry OOR\r\n" (CODE 0xDDC6), returns
 * when off >= 0x1E, else n = 0x1E - off. Then copies p[0..n-1] to XDATA 0xA62F + off + i (the 30 bytes of the
 * 3-byte table at 0xA62F that FUN_CODE_52be and FUN_CODE_a57e read). Same shape as FUN_CODE_9053 and
 * FUN_CODE_a819. Caller: the tail LJMP at 0x21DF in FUN_CODE_1c3c (record type 9). No aids.
 */
extern unsigned char xdata DAT_EXTMEM_a62f[];
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_b3cb(unsigned int off, unsigned char n, unsigned char *p)
{
    unsigned char i;
    if (off + n > 0x1e) {
        FUN_CODE_2820((void code *)0xddc6);   /* "SetZPArry OOR\r\n" */
        if (off >= 0x1e) return;
        n = 0x1e - off;
    }
    for (i = 0; i < n; i++) DAT_EXTMEM_a62f[off + i] = p[i];
}
