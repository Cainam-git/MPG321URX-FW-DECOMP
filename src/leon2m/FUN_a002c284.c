/* FUN_a002c284 (leon2m 0xa002c284-0xa002c2a0, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Reads the aligned word that contains address a (a & ~3) and returns the low byte of that word shifted right by (a
 * & 3) * 8. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a002c268 and FUN_a002c2a0. Source form: the word is read into a local before the shift.
 */
unsigned char FUN_a002c284(unsigned int a)
{
    unsigned int w = *(unsigned int *)(a & ~3u);

    return w >> ((a & 3) * 8);
}
