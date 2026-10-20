/* FUN_a011a378: clears one bit in block blk of the second register family (register n at 0xcf000000 + 4 * n,
 * block base = halfword table 0xa8027aa8[blk], no block check) through FUN_a01191fc; counterpart of FUN_a011a1b0:
 * bit 0..3 -> bits 1..4 of register base + 0x80, bit 4..7 -> bits 4..7 of register base + 0xa5;
 * any other bit value clears all of them (mask 0x1e in base + 0x80, mask 0xf0 in base + 0xa5).
 * FUN_a01191fc is defined here because GCC inlines it at -O3. Bit 7 is passed as the char constant (char)0x80
 * (sign-extended, as in FUN_a011a1b0). Callers: FUN_a0146c40.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

void FUN_a011a378(unsigned int bit, unsigned char blk)
{
    switch (bit) {
    case 0:
        FUN_a01191fc(blk, 0x80, 2, 0);
        break;
    case 1:
        FUN_a01191fc(blk, 0x80, 4, 0);
        break;
    case 2:
        FUN_a01191fc(blk, 0x80, 8, 0);
        break;
    case 3:
        FUN_a01191fc(blk, 0x80, 0x10, 0);
        break;
    case 4:
        FUN_a01191fc(blk, 0xa5, 0x10, 0);
        break;
    case 5:
        FUN_a01191fc(blk, 0xa5, 0x20, 0);
        break;
    case 6:
        FUN_a01191fc(blk, 0xa5, 0x40, 0);
        break;
    case 7:
        FUN_a01191fc(blk, 0xa5, (char)0x80, 0);
        break;
    default:
        FUN_a01191fc(blk, 0x80, 0x1e, 0);
        FUN_a01191fc(blk, 0xa5, 0xf0, 0);
        break;
    }
}
