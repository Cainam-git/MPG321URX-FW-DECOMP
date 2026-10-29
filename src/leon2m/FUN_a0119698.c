/* leon2m FUN_a0119698 @ 0xa0119698-0xa01198a0 (130 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a0146298 (five calls).
 * Reads the low 6 bits v of register (DAT_a8027aa8[0] + blk) (registers word-spaced at 0xcf000000 + 4 * n), then by
 * mode 0..4 (jump table at 0xb9148) stores a byte pair into DAT_a802c9c0[blk] / DAT_a802c9b8[blk] (0xa/0x10, 0xa/0x12,
 * 0xc/0x10, 0xc/0x12, 0x18/0x24) and updates registers 0xa2/0xa3 of block blk through the inlined FUN_a01191fc:
 * mode 0..2 set (v | 0xffffffc0), (v | 0x40) or (v | 0xffffff80) in 0xa2; mode 3 writes v to register 0xa2 of
 * block blk (block 0 when blk > 1); mode 0..3 clear 0xffffffc0 in 0xa3, mode 4 sets it. Other modes do nothing.
 * Source form: FUN_a01191fc is defined in this file (copy of its own source) and a static 8-bit write helper with
 * an 'unsigned int' value parameter clamps blk; case blocks in ascending order.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
extern unsigned char DAT_a802c9c0[];
extern unsigned char DAT_a802c9b8[];

void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

static void wr8(unsigned char blk, unsigned char reg, unsigned int v)
{
    if (blk > 1)
        blk = 0;
    R(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

void FUN_a0119698(unsigned int mode, unsigned char blk)
{
    unsigned int v = R(DAT_a8027aa8[0] + blk) & 0x3f;

    switch (mode) {
    case 0:
        DAT_a802c9c0[blk] = 0xa;
        DAT_a802c9b8[blk] = 0x10;
        FUN_a01191fc(blk, 0xa2, v | 0xffffffc0, 1);
        FUN_a01191fc(blk, 0xa3, 0xffffffc0, 0);
        break;
    case 1:
        DAT_a802c9c0[blk] = 0xa;
        DAT_a802c9b8[blk] = 0x12;
        FUN_a01191fc(blk, 0xa2, v | 0x40, 1);
        FUN_a01191fc(blk, 0xa3, 0xffffffc0, 0);
        break;
    case 2:
        DAT_a802c9c0[blk] = 0xc;
        DAT_a802c9b8[blk] = 0x10;
        FUN_a01191fc(blk, 0xa2, v | 0xffffff80, 1);
        FUN_a01191fc(blk, 0xa3, 0xffffffc0, 0);
        break;
    case 3:
        DAT_a802c9c0[blk] = 0xc;
        DAT_a802c9b8[blk] = 0x12;
        wr8(blk, 0xa2, v);
        FUN_a01191fc(blk, 0xa3, 0xffffffc0, 0);
        break;
    case 4:
        DAT_a802c9c0[blk] = 0x18;
        DAT_a802c9b8[blk] = 0x24;
        FUN_a01191fc(blk, 0xa3, 0xffffffc0, 1);
        break;
    }
}
