/* FUN_a01085a4 (leon2m 0xa01085a4-0xa01085f8, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When c is 0 and bit 4 of the word register 0xcf011a00 is set, replaces *p with *p / ((register 0xcf0116d0 & 0x7f)
 * + 1) + 1. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0108544 and FUN_a01085f8.
 */
#define REGA (*(volatile unsigned int *)0xcf011a00)
#define REGB (*(volatile unsigned int *)0xcf0116d0)

void FUN_a01085a4(unsigned char c, unsigned int *p)
{
    if (c == 0 && (REGA & 0x10))
        *p = *p / ((REGB & 0x7f) + 1) + 1;
}
