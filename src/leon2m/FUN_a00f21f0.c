/* leon2m FUN_a00f21f0 @ 0xa00f21f0 (-mcpu=v8 -O3 -g)
 * With a = halfword blk of the table at 0x19A2FC + reg (blk 8 and up use entry 0) and R(x) the register word at
 * 0xCF000000 | (x << 2), returns (R(a + 1) << 8) | (R(a) & 0xff) as 16 bits; R(a) is read first. The table holds
 * 0x1AB0 .. 0x21B0 (registers 0xCF006AC0 + 0x400 * blk). Same code as FUN_a00f1ce4 with another table.
 * Called from FUN_a00f36b8, FUN_a0120a18, FUN_a0120b38, FUN_a0120c90 and FUN_a0120de4.
 */
extern unsigned short DAT_0019a2fc[8];     /* block bases */

unsigned short FUN_a00f21f0(unsigned char blk, unsigned char reg)
{
    unsigned int lo, hi, a;
    if (blk >= 8) blk = 0;
    a = DAT_0019a2fc[blk] + reg;
    lo = *(volatile unsigned int *)(0xcf000000 | (a << 2));
    hi = *(volatile unsigned int *)(0xcf000000 | ((a + 1) << 2));
    return (hi << 8) | (lo & 0xff);
}
