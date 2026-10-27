/* FUN_a011cd80 (leon2m 0xa011cd80-0xa011cdb8, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Reads the word register 0xcf01178c (c = 0) or 0xcf0117a0 (c non-zero), runs a delay loop of 0xa0 nops and returns
 * the low byte of the value read. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a011cd10 and FUN_a011cdb8. Source form: one register read in each arm of the if/else.
 */
unsigned char FUN_a011cd80(unsigned char c)
{
    unsigned int v;
    int i;

    if (c == 0)
        v = *(volatile unsigned int *)0xcf01178c;
    else
        v = *(volatile unsigned int *)0xcf0117a0;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
    return v;
}
