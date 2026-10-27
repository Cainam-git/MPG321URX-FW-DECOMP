/* FUN_a002f0e0 (leon2m 0xa002f0e0-0xa002f10c, 44 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Clears the word register 0xcf008730, sets bit 7 (0x80) of the word DAT_a802c9e4 and clears the word register
 * 0xcf008734. It lies between FUN_a002f0b4 and FUN_a002f10c.
 */
#define REG330 (*(volatile unsigned int *)0xcf008730)
#define REG334 (*(volatile unsigned int *)0xcf008734)
extern unsigned int DAT_a802c9e4;

void FUN_a002f0e0(void)
{
    REG330 = 0;
    DAT_a802c9e4 |= 0x80;
    REG334 = 0;
}
