/*
 * FUN_a00d6b98 (leon2s, 0xa00d6b98-0xa00d6c98, 256 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Code facts: v = (src[0] >> 4) - 1 (int), n = (u8)(v / 2 rounded up for odd v). Copies a 19-byte block
 * from src + n + 3 into dst: dst[0] low 7 bits, dst[1] high nibble, dst[2..17] (u8 loop), and the dst[0x12]
 * fields 0x40, 0x20, 0x10, 0x08, 0x07 one RMW each (src[n + 0x15] re-read for each, dst[0x12] kept in a
 * register). Same code shape as FUN_a00d72d8.
 * Forms: the masked source byte of the 0x7f, 0xf0, 0x40 and 0x07 fields is a u32 temp in its own declaration
 * (src-before-dst operand order); the 0x20 / 0x10 / 0x08 fields are plain expressions.
 */
void FUN_a00d6b98(unsigned char *dst, unsigned char *src)
{
    int v;
    unsigned char n, i;

    v = (src[0] >> 4) - 1;
    n = v / 2;
    if (v & 1)
        n = v / 2 + 1;
    { unsigned int t = src[n + 3] & 0x7f; dst[0] = (dst[0] & 0x80) | t; }
    { unsigned int t = src[n + 4] & 0xf0; dst[1] = (dst[1] & 0x0f) | t; }
    for (i = 0; i < 16; i++)
        dst[i + 2] = src[n + i + 5];
    { unsigned int t = src[n + 0x15] & 0x40; dst[0x12] = (dst[0x12] & 0xbf) | t; }
    dst[0x12] = (dst[0x12] & 0xdf) | (src[n + 0x15] & 0x20);
    dst[0x12] = (dst[0x12] & 0xef) | (src[n + 0x15] & 0x10);
    dst[0x12] = (dst[0x12] & 0xf7) | (src[n + 0x15] & 0x08);
    { unsigned int t = src[n + 0x15] & 0x07; dst[0x12] = (dst[0x12] & 0xf8) | t; }
}
