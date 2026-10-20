/* leon2m FUN_a00f25f8 @ 0xa00f25f8  (-mcpu=v8 -O3 -g)
 *
 * Reads a 16-bit value (low byte at reg, high byte at reg + 1, low read first) from a 0x19A2EC-table block.
 * Block numbers 8 and up read block 0. For blocks 6 and 7, reg 0xA0 and reg 0xBE are remapped to the single
 * registers 0x60 and 0x5D (returned whole, truncated to 16 bits).
 * Register addressing (shared by the FUN_a00f1xxx/FUN_a00f2xxx accessor family): a register is a 32-bit word at
 * 0xCF000000 + 4 * (block base + register number), only the low 8 bits are used, so 16-bit values take two
 * consecutive registers (low byte first). Block bases for this function come from the table at 0x19A2EC:
 *   blocks 0..7 = 0x2600, 0x2700, 0x2800, 0x2900, 0x2A00, 0x5D00, 0x2400, 0x2500
 *   -> 0xCF009800, 0xCF009C00, 0xCF00A000, 0xCF00A400, 0xCF00A800, 0xCF017400, 0xCF009000, 0xCF009400
 * Blocks 6 and 7 have a different layout: their registers 0xA0 and 0xBE are single 8-bit registers at 0x60 and
 * 0x5D. The display-timing code (FUN_a01038c0 "display vtotal" check, FUN_a01070b4 panel limit check) uses
 * these blocks.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))   /* register at 0xCF000000 + 4 * a */
extern unsigned short DAT_0019a2ec[8];     /* block bases, see above */
unsigned short FUN_a00f25f8(unsigned char blk, unsigned char reg)
{
    unsigned short v; unsigned int a, lo, hi;
    if (blk > 7) blk = 0;
    if (blk <= 5) { a = DAT_0019a2ec[blk] + reg; lo = R(a); hi = R(a + 1); v = (hi << 8) | (lo & 0xff); }
    else if (reg == 0xa0) v = R(DAT_0019a2ec[blk] + 0x60);
    else if (reg == 0xbe) v = R(DAT_0019a2ec[blk] + 0x5d);
    else { a = DAT_0019a2ec[blk] + reg; lo = R(a); hi = R(a + 1); v = (hi << 8) | (lo & 0xff); }
    return v;
}
