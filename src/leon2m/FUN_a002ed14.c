/* FUN_a002ed14 (leon2m 0xa002ed14-0xa002ef0c, 504 bytes), flags -mcpu=v8 -O3 -g.
 * With s = byte DAT_a802c9d0[blk] and t = byte DAT_a802c9d8[blk], computes the 16-bit products x0 = x * s,
 * x1 = (w + 1) * s, y0 = y * t and y1 = (h + 1) * t. Writes registers 3 and 4 = low bytes of x0 and x1,
 * 5 = bits 8..11 of x0 | bits 8..11 of x1 << 4, 9 = bits 12..13 of x0 | bits 12..13 of x1 << 4, and the same for
 * y0/y1 in registers 6, 7, 8 and 10 of register block blk (register 0xcf000000 + 4 * (DAT_a8027aa8[blk] + reg),
 * block 0 when blk >= 2). No call to it was found in the image. It is FUN_a002e764 without the final call of
 * FUN_a002e2a4.
 * Source form: the write is a static helper inlined eight times, its value parameter unsigned short with the
 * low-byte arguments cast to unsigned char; x and y are unsigned short; the products are computed in the order
 * x0, x1, y0, y1.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
extern unsigned char DAT_a802c9d0[];
extern unsigned char DAT_a802c9d8[];

static void wr(unsigned char blk, unsigned char reg, unsigned short val)
{
    if (blk >= 2) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = val;
}

void FUN_a002ed14(unsigned short x, unsigned short y, unsigned short w, unsigned short h, unsigned char blk)
{
    unsigned short x0, x1, y0, y1;

    x0 = x * DAT_a802c9d0[blk];
    x1 = (w + 1) * DAT_a802c9d0[blk];
    y0 = y * DAT_a802c9d8[blk];
    y1 = (h + 1) * DAT_a802c9d8[blk];
    wr(blk, 3, (unsigned char)x0);
    wr(blk, 4, (unsigned char)x1);
    wr(blk, 5, ((x0 >> 8) & 0xf) | ((x1 >> 4) & 0xf0));
    wr(blk, 9, ((x0 >> 12) & 3) | ((x1 >> 8) & 0x30));
    wr(blk, 6, (unsigned char)y0);
    wr(blk, 7, (unsigned char)y1);
    wr(blk, 8, ((y0 >> 8) & 0xf) | ((y1 >> 4) & 0xf0));
    wr(blk, 10, ((y0 >> 12) & 3) | ((y1 >> 8) & 0x30));
}
