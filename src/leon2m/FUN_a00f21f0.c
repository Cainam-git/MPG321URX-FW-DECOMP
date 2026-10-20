/* leon2m FUN_a00f21f0 @ 0xa00f21f0  MATCH (-mcpu=v8 -O3 -g, twin of FUN_a00f1ce4)
 * Reads a 16-bit value from two consecutive registers (low byte at reg, high byte at reg + 1, low read first) of a
 * 0x19A2FC-table block; block numbers 8 and up read block 0. Register = 32-bit word at 0xCF000000 + 4 * (base + reg),
 * low 8 bits used. Table 0x19A2FC: blocks 0..7 = 0x1AB0..0x21B0 -> 0xCF006AC0 + 0x400 * block.
 * Used by FUN_a0120b38 (register 0x14/0x15 = the input frame-period counter for the vfreq measurement).
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
