/* FUN_a002c2d4 (leon2m 0xa002c2d4-0xa002c2f0, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns the low byte of the word register at 0xcf000000 | (r << 2), r a halfword index. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a002c2a0 and FUN_a002c2f0.
 * Source form: an unsigned short parameter shifted into a volatile word address.
 */
unsigned char FUN_a002c2d4(unsigned short r)
{
    return *(volatile unsigned int *)(0xcf000000 | (r << 2));
}
