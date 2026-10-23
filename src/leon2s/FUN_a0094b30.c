/* FUN_a0094b30 (leon2s 0xa0094b30-0xa0094c54, 292 bytes, including the ret/restore tail), flags -mcpu=v8 -Os -g.
 * Does nothing unless 11 <= v <= 0x1ec (unsigned v - 11 <= 0x1e1). Stores v in DAT_a80785e8 and writes the
 * low and high bytes of v + 0x400, 0x400 - v, v + 0x3f8 (twice) and v + 0x3f4 with FUN_a00a8054(port, 4, k, byte)
 * to k = 0x14/0x15, 0x16/0x17, 0x1c/0x1d, 0x1e/0x1f and 0x20/0x21 (the last call is a sibling call).
 * Source form: the four sums are assigned after the range test and the store.
 */
extern unsigned int DAT_a80785e8;
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a0094b30(unsigned char port, unsigned int v)
{
    unsigned int a, b, c, d;

    if (v - 11 > 0x1e1)
        return;
    DAT_a80785e8 = v;
    a = v + 0x400;
    b = 0x400 - v;
    c = v + 0x3f8;
    d = v + 0x3f4;
    FUN_a00a8054(port, 4, 0x14, a);
    FUN_a00a8054(port, 4, 0x15, a >> 8);
    FUN_a00a8054(port, 4, 0x16, b);
    FUN_a00a8054(port, 4, 0x17, b >> 8);
    FUN_a00a8054(port, 4, 0x1c, c);
    FUN_a00a8054(port, 4, 0x1d, c >> 8);
    FUN_a00a8054(port, 4, 0x1e, c);
    FUN_a00a8054(port, 4, 0x1f, c >> 8);
    FUN_a00a8054(port, 4, 0x20, d);
    FUN_a00a8054(port, 4, 0x21, d >> 8);
}
