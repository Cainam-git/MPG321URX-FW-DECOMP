/* FUN_a002f088 (leon2m 0xa002f088-0xa002f0b4, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears the word register 0xcf007b30, sets bit 4 (0x10) of the word DAT_a802c9e4 and clears the word register
 * 0xcf007b34. It lies between FUN_a002f04c and FUN_a002f0b4.
 */
#define REG330 (*(volatile unsigned int *)0xcf007b30)
#define REG334 (*(volatile unsigned int *)0xcf007b34)
extern unsigned int DAT_a802c9e4;

void FUN_a002f088(void)
{
    REG330 = 0;
    DAT_a802c9e4 |= 0x10;
    REG334 = 0;
}
