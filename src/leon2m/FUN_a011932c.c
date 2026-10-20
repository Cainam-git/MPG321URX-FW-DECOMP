/* FUN_a011932c: writes a 24-bit value v into one of three register groups of block blk (0/1) of the second
 * register family (register n at 0xcf000000 + 4 * n, block base = halfword table 0xa8027aa8[blk]).
 * sel 0xa0: low/high byte of v to base + 0x88/0x89, bits 16-23 to base + 0xf0.
 * sel 0xb0: the same to base + 0x8a/0x8b and base + 0xf1.
 * sel 0xc0 / 0xc1: bit 7 of register base + 0x9f is set / cleared first (FUN_a01191fc, no block check), then
 * the same writes to base + 0x8c/0x8d and base + 0xf2. Any other sel writes nothing.
 * The 16-bit write is FUN_a011919c and the byte write a separate helper; both treat blk > 1 as 0, and
 * GCC inlines all three helpers, so the block check is repeated for every access.
 * The mask passed for register 0x9f is the int ~0x7f (0xffffff80): the firmware ORs -128 before the byte
 * truncation; only bit 7 reaches the register.
 * Callers: FUN_a0146370.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

static void wr16(unsigned int a, unsigned short v) { R(a) = (unsigned char)v; R(a + 1) = (unsigned char)(v >> 8); }

void FUN_a011919c(unsigned char blk, unsigned char reg, unsigned short v)
{
    if (blk > 1) blk = 0;
    wr16(DAT_a8027aa8[blk] + reg, v);
}

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

void FUN_a011932c(unsigned int sel, unsigned int v, unsigned char blk)
{
    switch (sel) {
    case 0xa0:
        FUN_a011919c(blk, 0x88, v);
        wr8(blk, 0xf0, v >> 16);
        break;
    case 0xb0:
        FUN_a011919c(blk, 0x8a, v);
        wr8(blk, 0xf1, v >> 16);
        break;
    case 0xc0:
        FUN_a01191fc(blk, 0x9f, ~0x7f, 1);
        FUN_a011919c(blk, 0x8c, v);
        wr8(blk, 0xf2, v >> 16);
        break;
    case 0xc1:
        FUN_a01191fc(blk, 0x9f, ~0x7f, 0);
        FUN_a011919c(blk, 0x8c, v);
        wr8(blk, 0xf2, v >> 16);
        break;
    }
}
