/* FUN_a0110084 (leon2m 0xa0110084-0xa01100a4, 32 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns bit 0 of the word register 0xd0032000 (0 or 1). Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a010fe50 and FUN_a01100a4. Source form: r = 0; if (REG &
 * 1) r = 1; return r & 1; (the and 1 sits in the retl delay slot).
 */
#define REG (*(volatile unsigned int *)0xd0032000)

unsigned char FUN_a0110084(void)
{
    unsigned char r = 0;

    if (REG & 1)
        r = 1;
    return r & 1;
}
