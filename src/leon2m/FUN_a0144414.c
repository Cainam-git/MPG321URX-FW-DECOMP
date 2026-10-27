/* FUN_a0144414 (leon2m 0xa0144414-0xa0144484, 112 bytes), flags -mcpu=v8 -O3 -g.
 * Returns the first index i (0..3) whose port p = bits 12..15 of the first word of 0x78-byte entry i of
 * DAT_a802df30 has byte +9 of 0x2a-byte entry p of DAT_a802e224 not equal to 5; returns 0xff when all four are 5.
 * Called by FUN_a00d4108, FUN_a00d4164, FUN_a00d41b4, FUN_a00d4250, FUN_a00d430c, FUN_a00d43b4, FUN_a00d44bc.
 */
struct Chan { unsigned int w; unsigned char p04[0x74]; };
struct E2a { unsigned char p0[9]; unsigned char b9; unsigned char pa[0x20]; };
extern struct Chan DAT_a802df30[4];
extern struct E2a DAT_a802e224[];

unsigned char FUN_a0144414(void)
{
    unsigned char i;

    for (i = 0; i < 4; i++)
        if (DAT_a802e224[(DAT_a802df30[i].w >> 12) & 0xf].b9 != 5)
            break;
    if (i == 4)
        return 0xff;
    return i;
}
