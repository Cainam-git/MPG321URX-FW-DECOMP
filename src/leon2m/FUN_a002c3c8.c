/* FUN_a002c3c8 (leon2m 0xa002c3c8-0xa002c3f4, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes v & 0xff to the word register at p = 0xcf000000 | (r << 2) and v >> 8 to p + 4 (v a halfword). Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a002c390 and
 * FUN_a002c3f4.
 */
void FUN_a002c3c8(unsigned short r, unsigned short v)
{
    volatile unsigned int *p = (volatile unsigned int *)(0xcf000000 | (r << 2));

    p[0] = v & 0xff;
    p[1] = v >> 8;
}
