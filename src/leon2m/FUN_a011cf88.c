/* leon2m FUN_a011cf88 @ 0xa011cf88-0xa011d0a8 (72 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/72 mismatches.
 * What it does: returns a chip version code 0x80..0x84 built from the hardware ID register
 * 0xcf011444 and its valid flag 0xcf011440 (both read fresh at every test, so volatile):
 *   ID 0x16 and valid == 1 -> copies 8 bytes from 0x9f1b0600 into a zeroed local buffer and
 *                             returns 0x81 when byte 6 == 1, else 0x80;
 *   ID 0x1e and valid -> 0x82;  ID 0x1f and valid -> 0x83;  ID 0x17 and valid -> 0x84;
 *   anything else (or valid != 1) -> 0x84.
 * Callers: FUN_a013dc6c state 8/10 ('if (FUN_a011cf88() > 0x82)' and 'if (FUN_a011cf88() <= 0x82)
 * lim = min(lim, DAT_a802d6a4->h50)'), FUN_a0107e44 and FUN_a0109bbc. So the 60 Hz cap (the h50
 * limit of the panel mode table) applies only to chip codes 0x80, 0x81 and 0x82; whether the cap applies
 * is decided by this chip version alone, not by the input timing.
 * Fix vs the autoc draft (61 %): the 8-byte copy is an inlined static helper rd8(dst, src, n) with a
 * u8 counter (the same loop is in FUN_a011d0a8): it keeps the fw [idx + base] addressing and the
 * 'cmp 8; bcs,a' loop test; an open-coded loop gives a strength-reduced giv. Aids: none.
 */
#define ID_REG  (*(volatile unsigned int *)0xcf011444)
#define ID_OK   (*(volatile unsigned int *)0xcf011440)

static void rd8(unsigned char *d, const unsigned char *s, unsigned char n)
{
    unsigned char i;
    for (i = 0; i < n; i++)
        d[i] = s[i];
}

unsigned char FUN_a011cf88(void)
{
    unsigned char buf[8] = {0};
    unsigned char i;
    unsigned char r;

    r = 0x84;
    if (ID_REG == 0x16 && ID_OK == 1) {
        rd8(buf, (const unsigned char *)0x9f1b0600, 8);
        r = buf[6] == 1 ? 0x81 : 0x80;
    } else if (ID_REG == 0x1e && ID_OK == 1) {
        r = 0x82;
    } else if (ID_REG == 0x1f && ID_OK == 1) {
        r = 0x83;
    } else if (ID_REG == 0x17 && ID_OK == 1) {
        r = 0x84;
    }
    return r;
}
