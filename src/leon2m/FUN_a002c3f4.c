/* FUN_a002c3f4 (leon2m 0xa002c3f4-0xa002c42c, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes v & 0xff to the word register at p = 0xcf000000 | ((r + k) << 2) and v >> 8 to p + 4 (v a halfword).
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a002c3c8 and FUN_a002c42c.
 */
void FUN_a002c3f4(unsigned short r, unsigned char k, unsigned short v)
{
    volatile unsigned int *p = (volatile unsigned int *)(0xcf000000 | ((r + k) << 2));

    p[0] = v & 0xff;
    p[1] = v >> 8;
}
