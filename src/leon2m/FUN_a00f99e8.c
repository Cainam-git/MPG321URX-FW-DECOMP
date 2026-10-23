/* FUN_a00f99e8 (leon2m 0xa00f99e8-0xa00f9a00, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns bits lo..hi of x: (x << (31 - hi)) >> (31 - hi + lo). GCC writes the left shift count 31 - hi as ~hi
 * (only the low 5 bits count). Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a00f99a0 and FUN_a00f9a00. Source form: two shifts with counts 31 - hi and 31 - hi +
 * lo.
 */
unsigned int FUN_a00f99e8(unsigned int x, unsigned int hi, unsigned int lo)
{
    return (x << (31 - hi)) >> (31 - hi + lo);
}
