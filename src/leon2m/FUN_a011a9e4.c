/* FUN_a011a9e4: programs one of three register pairs in block blk of the second register family (register n at
 * 0xcf000000 + 4 * n, block base = halfword table 0xa8027aa8[blk]). Register base + 0x30 is written 0 (byte
 * write that treats blk > 1 as 0), then bits 0x2f and bit 4 = (b & 1) are set in it (FUN_a01191fc, no block
 * check). sel 0 / 1 / 2: register base + 0x31 / 0x32 / 0x33 = (e & 0x1f) | ((c & 1) << 7) and register
 * base + 0x34 / 0x35 / 0x36 = d; other sel values stop after base + 0x30. Caller: FUN_a014692c.
 * The helpers are defined here because GCC inlines them at -O3; sel is tested with an if/else chain.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

static void wr8(unsigned char blk, unsigned char reg, unsigned char v)
{
    if (blk > 1) blk = 0;
    R(DAT_a8027aa8[blk] + reg) = v;
}

void FUN_a011a9e4(unsigned char sel, unsigned int b, unsigned int c, unsigned char d, unsigned int e,
                  unsigned char blk)
{
    wr8(blk, 0x30, 0);
    FUN_a01191fc(blk, 0x30, 0x2f, 1);
    FUN_a01191fc(blk, 0x30, (b & 1) << 4, 1);
    if (sel == 0) {
        wr8(blk, 0x31, (e & 0x1f) | ((c & 1) << 7));
        wr8(blk, 0x34, d);
    } else if (sel == 1) {
        wr8(blk, 0x32, (e & 0x1f) | ((c & 1) << 7));
        wr8(blk, 0x35, d);
    } else if (sel == 2) {
        wr8(blk, 0x33, (e & 0x1f) | ((c & 1) << 7));
        wr8(blk, 0x36, d);
    }
}
