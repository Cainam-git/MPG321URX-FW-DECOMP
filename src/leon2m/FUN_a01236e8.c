/* FUN_a01236e8 (leon2m 0xa01236e8-0xa0123744, 92 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes c to the word register 0xcf03c668 and 0x70 to 0xcf03c660, waits until 0xcf03c660 no longer reads 0x70,
 * then writes 7 (c = 0) or 0xf to the word registers 0xcf01c100 and 0xcf01c500. Called by gap. It lies between
 * FUN_a012367c and FUN_a0123744. Source form: both register writes in each arm of the if/else.
 */
#define REG668 (*(volatile unsigned int *)0xcf03c668)
#define REG660 (*(volatile unsigned int *)0xcf03c660)
#define REGA (*(volatile unsigned int *)0xcf01c100)
#define REGB (*(volatile unsigned int *)0xcf01c500)
void FUN_a01236e8(unsigned char c)
{
    REG668 = c;
    REG660 = 0x70;
    while (REG660 == 0x70)
        ;
    if (c == 0) {
        REGA = 7;
        REGB = 7;
    } else {
        REGA = 0xf;
        REGB = 0xf;
    }
}
