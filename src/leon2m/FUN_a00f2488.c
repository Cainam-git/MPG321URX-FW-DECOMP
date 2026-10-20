/* leon2m FUN_a00f2488 @ 0xa00f2488  (hand; byte-exact at -mcpu=v8 -O3 -g)
 *
 * Writes a 16-bit value (low byte to reg, high byte to reg + 1) to a 0x19A2EC-table block. Block 8 writes all
 * eight blocks. For blocks 6 and up, reg 0xA0 and reg 0xBE write only the low byte to the single registers 0x60
 * and 0x5D. (Block numbers above 8 are not range-checked: they index past the eight-entry table.)
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
void FUN_a00f2488(unsigned char blk, unsigned char reg, unsigned short val)
{
    unsigned char i; unsigned int a;
    if (blk == 8) { for (i = 0; i <= 7; i++) { a = DAT_0019a2ec[i] + reg; R(a) = (unsigned char)val; R(a + 1) = val >> 8; } }
    else if (blk <= 5) { a = DAT_0019a2ec[blk] + reg; R(a) = (unsigned char)val; R(a + 1) = val >> 8; }
    else if (reg == 0xa0) R(DAT_0019a2ec[blk] + 0x60) = (unsigned char)val;
    else if (reg == 0xbe) R(DAT_0019a2ec[blk] + 0x5d) = (unsigned char)val;
    else { a = DAT_0019a2ec[blk] + reg; R(a) = (unsigned char)val; R(a + 1) = val >> 8; }
}
