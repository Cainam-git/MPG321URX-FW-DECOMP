/* leon2m FUN_a00f2298 @ 0xa00f2298  (hand; byte-exact at -mcpu=v8 -O3 -g)
 *
 * Writes the 8-bit value val to register reg of a 0x19A2EC-table block; block 8 writes all eight blocks, block
 * numbers above 8 do nothing. Register = 32-bit word at 0xCF000000 + 4 * (block base + reg). Table 0x19A2EC:
 * blocks 0..7 = 0x2600, 0x2700, 0x2800, 0x2900, 0x2A00, 0x5D00, 0x2400, 0x2500 -> 0xCF009800, 0xCF009C00,
 * 0xCF00A000, 0xCF00A400, 0xCF00A800, 0xCF017400, 0xCF009000, 0xCF009400 (same family as FUN_a00f2254 /
 * FUN_a00f25f8 / FUN_a00f2488 / FUN_a00f232c). Used by the output path setup (FUN_a0105150, FUN_a0106d64,
 * FUN_a01062e0) and the display timing code.
 */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))   /* register at 0xCF000000 + 4 * a */
extern unsigned short DAT_0019a2ec[8];     /* block bases */
void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val)
{
    unsigned char i;
    if (blk == 8) { for (i = 0; i <= 7; i++) R(DAT_0019a2ec[i] + reg) = val; }
    else if (blk <= 7) R(DAT_0019a2ec[blk] + reg) = val;
}
