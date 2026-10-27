/* FUN_a012ad80 (leon2m 0xa012ad80-0xa012adac, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Packs four two-bit values: returns ((a & 3) << 6) | ((b & 3) << 4) | ((c & 3) << 2) | (d & 3). Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a012ad6c and
 * FUN_a012adac.
 */
unsigned int FUN_a012ad80(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    return ((a & 3) << 6) | ((b & 3) << 4) | ((c & 3) << 2) | (d & 3);
}
