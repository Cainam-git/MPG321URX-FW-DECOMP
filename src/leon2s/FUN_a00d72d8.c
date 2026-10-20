/*
 * FUN_a00d72d8 (leon2s, 0xa00d72d8-0xa00d73b4, 220 bytes, leaf), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/55.
 * Code facts: v = (src[0] >> 4) - 1 (int), n = (u8)(v / 2 rounded up for odd v). Copies a 10-byte block
 * from src + n + 3 into dst: dst[0] low 7 bits, dst[1], dst[2..8] (u8 loop), and the dst[9] fields
 * 0xc0, 0x20, 0x18, 0x04 one RMW each (src[n + 0xc] re-read for each, dst[9] kept in a register).
 * Forms: the masked source byte of the 0x7f, 0xc0 and 0x04 fields is a u32 temp in its own
 * declaration (fw 'and 0xc0' instead of QImode 'and -64', and the src-before-dst operand order); the
 * 0x20 / 0x18 fields are plain expressions.
 * Aids: none.
 */
void FUN_a00d72d8(unsigned char *dst, unsigned char *src)
{
    int v;
    unsigned char n, i;

    v = (src[0] >> 4) - 1;
    n = v / 2;
    if (v & 1)
        n = v / 2 + 1;
    { unsigned int t = src[n + 3] & 0x7f; dst[0] = (dst[0] & 0x80) | t; }
    dst[1] = src[n + 4];
    for (i = 0; i < 7; i++)
        dst[i + 2] = src[n + i + 5];
    { unsigned int t = src[n + 0xc] & 0xc0; dst[9] = (dst[9] & 0x3f) | t; }
    dst[9] = (dst[9] & 0xdf) | (src[n + 0xc] & 0x20);
    dst[9] = (dst[9] & 0xe7) | (src[n + 0xc] & 0x18);
    { unsigned int t = src[n + 0xc] & 4; dst[9] = (dst[9] & 0xfb) | t; }
}
