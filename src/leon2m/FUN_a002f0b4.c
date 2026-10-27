/* FUN_a002f0b4 (leon2m 0xa002f0b4-0xa002f0e0, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears the word register 0xcf008330, sets bit 6 (0x40) of the word DAT_a802c9e4 and clears the word register
 * 0xcf008334. It lies between FUN_a002f088 and FUN_a002f0e0.
 */
#define REG330 (*(volatile unsigned int *)0xcf008330)
#define REG334 (*(volatile unsigned int *)0xcf008334)
extern unsigned int DAT_a802c9e4;

void FUN_a002f0b4(void)
{
    REG330 = 0;
    DAT_a802c9e4 |= 0x40;
    REG334 = 0;
}
