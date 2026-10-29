/* FUN_a002e960 (leon2m 0xa002e960-0xa002ed14, 948 bytes), flags -mcpu=v8 -O3 -g.
 * Writes the registers 3..10 of register block blk from (x0, y0, x1, y1) as FUN_a002ed14 does from its
 * products, after a transform selected by o = bits 2..3 of byte DAT_a802c9b0 for blk 0, bits 4..5 otherwise.
 * W = byte DAT_a802c9c0[blk] * halfword DAT_a802c9ca[blk], H = byte DAT_a802c9b8[blk] * byte DAT_a802c9c8[blk],
 * pad = (bits 0..2 of register 0xad) + 1 when bit 7 of register 0xaa is set, else 0 (registers read through
 * 0xcf000000 + 4 * (DAT_a8027aa8[blk] + reg), block 0 when blk >= 2). o 1: x0 = H - y1, x1 = H - y0 - pad,
 * y0 = old x0, y1 = old x1. o 2: x0 = W - x1, x1 = W - old x0 - pad, y0 = H - y1, y1 = H - old y0 - pad.
 * o 3: x0 = y0, x1 = y1, y0 = W - old x1, y1 = W - old x0 - pad. Each first value (x0 in o 1 and 2, y0 in o 2
 * and 3) has pad subtracted only when it is at least pad. No call to it was found in the image.
 * Source form: the four table values are read into unsigned int locals before the pad and o tests and multiplied
 * in each case; the parameters are updated in place, old values still needed kept in two temporaries (in o 2
 * the y0 copy is taken after the x pair is done); the write helper takes an unsigned short value with the
 * low-byte arguments cast to unsigned char.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
extern unsigned char DAT_a802c9b0;
extern unsigned char DAT_a802c9b8[], DAT_a802c9c0[], DAT_a802c9c8[];
extern unsigned short DAT_a802c9ca[];

static unsigned char rd(unsigned char blk, unsigned char reg)
{
    if (blk >= 2) blk = 0;
    return R(DAT_a8027aa8[blk] + reg);
}

static void wr(unsigned char blk, unsigned char reg, unsigned short val)
{
    if (blk >= 2) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = val;
}

void FUN_a002e960(unsigned short x0, unsigned short y0, unsigned short x1, unsigned short y1, unsigned char blk)
{
    unsigned int wb, wc, hb, hc;
    unsigned short t0, t1;
    unsigned char pad;
    int o;

    wb = DAT_a802c9c0[blk];
    wc = DAT_a802c9ca[blk];
    hb = DAT_a802c9b8[blk];
    hc = DAT_a802c9c8[blk];
    pad = 0;
    if (rd(blk, 0xaa) & 0x80)
        pad = (rd(blk, 0xad) & 7) + 1;
    if (blk == 0)
        o = (DAT_a802c9b0 & 0xc) >> 2;
    else
        o = (DAT_a802c9b0 & 0x30) >> 4;
    switch (o) {
    case 1:
        t0 = x0;
        t1 = x1;
        x0 = hb * hc - y1;
        if (x0 >= pad)
            x0 -= pad;
        x1 = hb * hc - y0 - pad;
        y0 = t0;
        y1 = t1;
        break;
    case 2:
        t0 = x0;
        x0 = wb * wc - x1;
        if (x0 >= pad)
            x0 -= pad;
        x1 = wb * wc - t0 - pad;
        t1 = y0;
        y0 = hb * hc - y1;
        if (y0 >= pad)
            y0 -= pad;
        y1 = hb * hc - t1 - pad;
        break;
    case 3:
        t0 = x0;
        t1 = x1;
        x0 = y0;
        x1 = y1;
        y0 = wb * wc - t1;
        if (y0 >= pad)
            y0 -= pad;
        y1 = wb * wc - t0 - pad;
        break;
    }
    wr(blk, 3, (unsigned char)x0);
    wr(blk, 4, (unsigned char)x1);
    wr(blk, 5, ((x0 >> 8) & 0xf) | ((x1 >> 4) & 0xf0));
    wr(blk, 9, ((x0 >> 12) & 3) | ((x1 >> 8) & 0x30));
    wr(blk, 6, (unsigned char)y0);
    wr(blk, 7, (unsigned char)y1);
    wr(blk, 8, ((y0 >> 8) & 0xf) | ((y1 >> 4) & 0xf0));
    wr(blk, 10, ((y0 >> 12) & 3) | ((y1 >> 8) & 0x30));
}
