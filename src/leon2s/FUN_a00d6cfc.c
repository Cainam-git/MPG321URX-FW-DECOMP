/* FUN_a00d6cfc (leon2s, 0xa00d6cfc-0xa00d6dac, 176 bytes, 44 words, leaf).
 * Flags: -mcpu=v8 -Os -g. Judge: jf 100.00 match=True, rawcmp_l2s 0/44 mismatches.
 * Code facts: n = (param_2[0] >> 4) - 1; half = n / 2 (signed) rounded up when n is odd;
 * p = param_2 + (u8)half. Into the u16 words of param_1: w0 bits 8..14 = p[3] & 0x7f,
 * w0 bits 4..7 = p[4] & 0xf0, w0 bits 0..3 = p[4] & 0x0f (w0 is kept in a register, three sth),
 * w1 bits 8..14 = p[5] & 0x7f, w2 = p[6] << 8 | p[7]. Twin layout of FUN_a00d76f4 (reverse packing).
 * Draft behaviour bug fixed: the low-nibble store used the 0xf0-masked byte again (the fw uses
 * p[4] & 0x0f); written without the draft's dead temporaries; void. Aids: none.
 */
void FUN_a00d6cfc(unsigned short *param_1, unsigned char *param_2)
{
    unsigned int n;
    short half;
    unsigned char *p;

    n = (*param_2 >> 4) - 1;
    half = (int)n / 2;
    if ((n & 1) != 0)
        half = half + 1;
    p = param_2 + (half & 0xff);
    *param_1 = (*param_1 & 0x80ff) | ((p[3] & 0x7f) << 8);
    *param_1 = (*param_1 & 0xff0f) | (p[4] & 0xf0);
    *param_1 = (*param_1 & 0xfff0) | (p[4] & 0x0f);
    param_1[1] = (param_1[1] & 0x80ff) | ((p[5] & 0x7f) << 8);
    param_1[2] = (p[6] << 8) | p[7];
}
