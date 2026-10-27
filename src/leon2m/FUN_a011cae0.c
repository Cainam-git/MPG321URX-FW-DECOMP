/* FUN_a011cae0 (leon2m 0xa011cae0-0xa011cc44, 356 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * For the word register r at 0xcf000000 + 4 * (DAT_a8027aa8[c] + 0x80) (c above 1 counting as 0) writes back the
 * low byte of: (r & 0x1f) for mode 0, (r & 0x1f) | 0x80 for mode 1, (r & 0x1f) | 0x60 for mode 2, r | 0xe0 for mode
 * 3; other modes do nothing. Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 * It lies between FUN_a011ca58 and FUN_a011cc44. Source form: static rd/wr helpers inlined per case (rd clamps c
 * with "if (c > 1) c = 0", wr with a separate k).
 */
extern unsigned short DAT_a8027aa8[];

static unsigned char rd(unsigned char c)
{
    if (c > 1)
        c = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((DAT_a8027aa8[c] + 0x80) << 2));
}

static void wr(unsigned char c, unsigned char v)
{
    unsigned char k = c;

    if (c > 1)
        k = 0;
    *(volatile unsigned int *)(0xcf000000 | ((DAT_a8027aa8[k] + 0x80) << 2)) = v;
}

void FUN_a011cae0(unsigned char c, unsigned int mode)
{
    switch (mode) {
    case 0:
        wr(c, rd(c) & 0x1f);
        break;
    case 1:
        wr(c, (rd(c) & 0x1f) | 0x80);
        break;
    case 2:
        wr(c, (rd(c) & 0x1f) | 0x60);
        break;
    case 3:
        wr(c, rd(c) | 0xe0);
        break;
    }
}
