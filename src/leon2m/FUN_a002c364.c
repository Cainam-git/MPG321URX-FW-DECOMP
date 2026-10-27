/* FUN_a002c364 (leon2m 0xa002c364-0xa002c390, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Reads the word registers at p = 0xcf000000 | (r << 2) and p + 4 and returns ((p[0] & 0xff) << 8) | (p[1] & 0xff).
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a002c338 and FUN_a002c390.
 */
unsigned short FUN_a002c364(unsigned short r)
{
    volatile unsigned int *p = (volatile unsigned int *)(0xcf000000 | (r << 2));

    return ((p[0] & 0xff) << 8) | (p[1] & 0xff);
}
