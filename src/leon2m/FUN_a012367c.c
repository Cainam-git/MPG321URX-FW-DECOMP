/* FUN_a012367c (leon2m 0xa012367c-0xa01236e8, 108 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes the four bytes of v (high byte first) to the word registers 0xcf03c670, 0xcf03c674, 0xcf03c678,
 * 0xcf03c67c, writes 0xff to 0xcf03c664 and 0x31 to 0xcf03c660, then waits until 0xcf03c660 no longer reads 0x31.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0123654 and FUN_a01236e8.
 */
#define R670 (*(volatile unsigned int *)0xcf03c670)
#define R674 (*(volatile unsigned int *)0xcf03c674)
#define R678 (*(volatile unsigned int *)0xcf03c678)
#define R67C (*(volatile unsigned int *)0xcf03c67c)
#define R664 (*(volatile unsigned int *)0xcf03c664)
#define R660 (*(volatile unsigned int *)0xcf03c660)

void FUN_a012367c(unsigned int v)
{
    R670 = v >> 24;
    R674 = (v >> 16) & 0xff;
    R678 = (v >> 8) & 0xff;
    R67C = v & 0xff;
    R664 = 0xff;
    R660 = 0x31;
    while (R660 == 0x31)
        ;
}
