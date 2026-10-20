/* leon2m FUN_a00f1d48 @ 0xa00f1d48  (-mcpu=v8 -O3 -g)
 *
 * Writes a 16-bit value to two consecutive registers (low byte to reg, high byte to reg + 1) of a 0x19A31C-table
 * block. Block numbers 8 and up write the value to all eight blocks.
 * Register addressing (shared by the FUN_a00f1xxx/FUN_a00f2xxx accessor family): a register is a 32-bit word at
 * 0xCF000000 + 4 * (block base + register number), only the low 8 bits are used, so 16-bit values take two
 * consecutive registers (low byte first). Two block-base tables of eight u16 entries:
 *   0x19A31C: blocks 0..7 = 0x1A00..0x2100   -> 0xCF006800 + 0x400 * block
 *   0x19A2EC: blocks 0..7 = 0x2600, 0x2700, 0x2800, 0x2900, 0x2A00, 0x5D00, 0x2400, 0x2500
 *             -> 0xCF009800, 0xCF009C00, 0xCF00A000, 0xCF00A400, 0xCF00A800, 0xCF017400, 0xCF009000, 0xCF009400
 * The display-timing code (FUN_a01038c0 "display vtotal" check, FUN_a01070b4 panel limit check) uses them.
 */
extern unsigned short DAT_0019a31c[8];     /* block bases, see above */
void FUN_a00f1d48(unsigned char blk, unsigned char reg, unsigned short val)
{
    unsigned char i;
    unsigned int a;
    if (blk > 7) {
        for (i = 0; i <= 7; i++) {
            a = DAT_0019a31c[i] + reg;
            *(volatile unsigned int *)(0xcf000000 | (a << 2)) = (unsigned char)val;
            *(volatile unsigned int *)(0xcf000000 | ((a + 1) << 2)) = val >> 8;
        }
    } else {
        a = DAT_0019a31c[blk] + reg;
        *(volatile unsigned int *)(0xcf000000 | (a << 2)) = (unsigned char)val;
        *(volatile unsigned int *)(0xcf000000 | ((a + 1) << 2)) = val >> 8;
    }
}
