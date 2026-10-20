/* FUN_a011aee4: block blk of the second register family (register n at 0xcf000000 + 4 * n, block base =
 * halfword table 0xa8027aa8[blk], byte helpers that treat blk > 1 as 0). c == 0 and d == 0: registers
 * base + 0x8e and base + 0x8f are written 0. Otherwise bits 6-7 of base + 0xcf are ORed with e & 3,
 * base + 0x8e = (c & 0xf) << 4 | (d & 0xf) and base + 0x8f = 0x80 | (a & 7) << 4 | (b & 0xf).
 * Caller: FUN_a014654c. The helpers are defined here because GCC inlines them at -O3.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

static unsigned char rd8(unsigned char blk, unsigned char reg)
{
    if (blk > 1) blk = 0;
    return R(DAT_a8027aa8[blk] + reg);
}

static void wr8(unsigned char blk, unsigned char reg, unsigned char v)
{
    if (blk > 1) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = v;
}

void FUN_a011aee4(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e,
                  unsigned char blk)
{
    if (c == 0 && d == 0) {
        wr8(blk, 0x8e, 0);
        wr8(blk, 0x8f, 0);
    } else {
        wr8(blk, 0xcf, rd8(blk, 0xcf) | ((e & 3) << 6));
        wr8(blk, 0x8e, ((c & 0xf) << 4) | (d & 0xf));
        wr8(blk, 0x8f, ((a & 7) << 4) | (b & 0xf) | 0x80);
    }
}
