/* FUN_a002c464 (leon2m 0xa002c464-0xa002c4a8, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Read-modify-write of the word register at 0xcf000000 | ((r + k) << 2): clears the bits of mask, ors in v and
 * writes the low halfword of the result. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a002c42c and FUN_a002c4a8.
 */
void FUN_a002c464(unsigned short r, unsigned char k, unsigned char v, unsigned char mask)
{
    volatile unsigned int *p = (volatile unsigned int *)(0xcf000000 | ((r + k) << 2));

    *p = (unsigned short)((*p & ~mask) | v);
}
