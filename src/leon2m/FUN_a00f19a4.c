/* FUN_a00f19a4 (leon2m 0xa00f19a4-0xa00f19dc, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the low byte of the word register at 0xcf000000 | ((DAT_0019a2d8[c] + r) << 2), DAT_0019a2d8 a word table
 * of base indexes. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies
 * between FUN_a00f18d4 and FUN_a00f19dc.
 */
extern const unsigned int DAT_0019a2d8[];

unsigned char FUN_a00f19a4(unsigned char c, unsigned short r)
{
    return *(volatile unsigned int *)(0xcf000000 | ((DAT_0019a2d8[c] + r) << 2));
}
