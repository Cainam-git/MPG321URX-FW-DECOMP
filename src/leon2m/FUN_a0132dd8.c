/* FUN_a0132dd8 (leon2m 0xa0132dd8-0xa0132e1c, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Finds the first shift i (0..7) for which c >> i equals 1 (8 when none does) and returns the byte ((b & 1) << 4) |
 * i. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0132d44 and FUN_a0132e1c. Source form: the result is assigned to an unsigned char local before the return.
 */
unsigned char FUN_a0132dd8(unsigned char c, unsigned char b)
{
    unsigned char r;
    unsigned char i;

    for (i = 0; i < 8; i++)
        if ((c >> i) == 1)
            break;
    r = ((b & 1) << 4) | i;
    return r;
}
