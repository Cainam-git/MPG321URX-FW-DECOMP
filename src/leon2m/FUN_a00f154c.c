/* leon2m FUN_a00f154c @ 0xa00f154c (-mcpu=v8 -O3 -g)
 * Stable 16-bit register read, same form as FUN_a00f2708: reads a with rd16(blk, reg), then while a second read
 * differs from a and fewer than 5 retries were made, reads a again; returns the last a.
 * rd16 (a static helper, inlined three times) reads register reg and reg + 1 (low byte, high byte) of block blk,
 * register n of block b being the word at 0xCF000000 + 4 * (DAT_a8026a7e[b] + n); blk 4 and above read block 0.
 * No direct callers found.
 */
extern unsigned short DAT_a8026a7e[4];

static unsigned short rd16(unsigned char blk, unsigned short reg)
{
    unsigned int lo, hi, a;

    if (blk >= 4) blk = 0;
    a = DAT_a8026a7e[blk] + reg;
    lo = *(volatile unsigned int *)(0xcf000000 | (a << 2));
    hi = *(volatile unsigned int *)(0xcf000000 | ((a + 1) << 2));
    return (hi << 8) | (lo & 0xff);
}

unsigned short FUN_a00f154c(unsigned char blk, unsigned short reg)
{
    unsigned short a;
    unsigned char n = 0;

    a = rd16(blk, reg);
    for (; a != rd16(blk, reg) && n < 5; n++)
        a = rd16(blk, reg);
    return a;
}
