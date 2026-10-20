/* leon2m FUN_a00f1a18 @ 0xa00f1a18  register bit set/clear, 0x19A2D8 block table
 * Flags: -mcpu=v8 -O3 -g.
 *
 * Read-modify-write of register reg of block blk: v = register; set == 1 -> v |= mask, else v &= ~mask; the low
 * 8 bits of v are written back. Block bases are the 32-bit words of the table at 0x0019A2D8; the register is the
 * 32-bit word at 0xCF000000 + 4 * (base + reg) (same addressing as the FUN_a00f1xxx accessor family). reg is a
 * 16-bit register number here. No direct callers found (called through a pointer or unused).
 * Family note (code fact): this is the single-block body that FUN_a00f1b5c / FUN_a00f2068 / FUN_a00f232c /
 * FUN_a00f2ca8 / FUN_a010d914 repeat per block (with u8 reg and 16-bit tables); those are still unmatched.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned int DAT_0019a2d8[];
void FUN_a00f1a18(unsigned char blk, unsigned short reg, unsigned int mask, unsigned char set)
{
    unsigned int v = R(DAT_0019a2d8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    R(DAT_0019a2d8[blk] + reg) = (unsigned char)v;
}
