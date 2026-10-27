/* FUN_a002c42c (leon2m 0xa002c42c-0xa002c464, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Read-modify-write of the word register at 0xcf000000 | (r << 2): clears the bits of mask, ors in v and writes the
 * low halfword of the result. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a002c3f4 and FUN_a002c464.
 */
void FUN_a002c42c(unsigned short r, unsigned char v, unsigned char mask)
{
    volatile unsigned int *p = (volatile unsigned int *)(0xcf000000 | (r << 2));

    *p = (unsigned short)((*p & ~mask) | v);
}
