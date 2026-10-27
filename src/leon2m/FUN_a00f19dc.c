/* FUN_a00f19dc (leon2m 0xa00f19dc-0xa00f1a18, 60 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes the byte v to the word register at 0xcf000000 | ((DAT_0019a2d8[c] + r) << 2), DAT_0019a2d8 a word table of
 * base indexes. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies
 * between FUN_a00f19a4 and FUN_a00f1a18.
 */
extern const unsigned int DAT_0019a2d8[];

void FUN_a00f19dc(unsigned char c, unsigned short r, unsigned char v)
{
    *(volatile unsigned int *)(0xcf000000 | ((DAT_0019a2d8[c] + r) << 2)) = v;
}
