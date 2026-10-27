/* FUN_a002c2f0 (leon2m 0xa002c2f0-0xa002c318, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the low byte of the word register at 0xcf000000 | ((r + k) << 2), r a halfword and k a byte index.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a002c2d4 and FUN_a002c318.
 */
unsigned char FUN_a002c2f0(unsigned short r, unsigned char k)
{
    return *(volatile unsigned int *)(0xcf000000 | ((r + k) << 2));
}
