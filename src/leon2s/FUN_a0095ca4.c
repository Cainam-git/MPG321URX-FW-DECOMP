/*
 * FUN_a0095ca4 (leon2s, 0xa0095ca4-0xa0095d34, 144 bytes), flags -mcpu=v8 -Os -g.
 * Code facts: p = 0x9f1b0200 + port * 0x200 (a 0x200-byte buffer per port, written as the symbol
 * DAT_9f1b0200[][0x200]). FUN_a0091db4(port, p, 0x80, 0) reads block 0; n = min(p[0x7f], 3) (u8);
 * then for u8 i < n: FUN_a0091db4(port, p + 0x80*(i+1), 0x80, (i << 7) + 0x80). The pointer is advanced
 * by 0x80 before the 'n == 0' return (fw add in the bleu delay slot) and after each call. The fw's
 * double 'be' = the n == 0 return plus the loop's entry test.
 * Aids: none.
 */
extern unsigned char DAT_9f1b0200[][0x200];
extern void FUN_a0091db4(unsigned int, unsigned char *, unsigned int, unsigned int);

void FUN_a0095ca4(unsigned char param_1)
{
    unsigned char *p;
    unsigned char n, i;

    p = DAT_9f1b0200[param_1];
    FUN_a0091db4(param_1, p, 0x80, 0);
    n = p[0x7f];
    p += 0x80;
    if (n > 3)
        n = 3;
    if (n == 0)
        return;
    for (i = 0; i < n; i++) {
        FUN_a0091db4(param_1, p, 0x80, (i << 7) + 0x80);
        p += 0x80;
    }
}
