/* FUN_a002e658 (leon2m 0xa002e658-0xa002e69c, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the low byte of the word register at 0xcf000000 | ((DAT_a8027aa8[c] + k) << 2), c above 1 counting as 0
 * (DAT_a8027aa8 a halfword table of base indexes). Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a002e46c and FUN_a002e69c.
 */
extern unsigned short DAT_a8027aa8[];

unsigned char FUN_a002e658(unsigned char c, unsigned char k)
{
    if (c > 1)
        c = 0;
    return *(volatile unsigned int *)(0xcf000000 | ((DAT_a8027aa8[c] + k) << 2));
}
