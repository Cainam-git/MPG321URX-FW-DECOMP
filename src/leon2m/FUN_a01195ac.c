/* FUN_a01195ac: register sequence on block blk of the second register family (register n at
 * 0xcf000000 + 4 * n, block base = halfword table 0xa8027aa8[blk]): clears bit 7 of register base + 0
 * (FUN_a01191fc, no block check), calls func_0x4008e2a4(), writes 0 to register base + 0xce (byte write that
 * treats blk > 1 as 0), sets bit 0 of register base + 0xcf (FUN_a01191fc), then calls the delay
 * func_0x4008d1a0(0x28) in tail position. Called from FUN_a0146108.
 * The same-file helpers are defined here because GCC inlines them at -O3.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];
extern void func_0x4008e2a4(void);
extern void func_0x4008d1a0(int ms);

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

void FUN_a01195ac(unsigned char blk)
{
    FUN_a01191fc(blk, 0, 0x80, 0);
    func_0x4008e2a4();
    wr8(blk, 0xce, 0);
    FUN_a01191fc(blk, 0xcf, 1, 1);
    func_0x4008d1a0(0x28);
}
