/* FUN_a00f1100 (leon2m 0xa00f1100-0xa00f1150, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the byte DAT_a802b746 for c = 2 or 6, the byte DAT_a802b742 for c = 3 or 7, otherwise 0. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00f0b58 and
 * FUN_a00f1150. Source form: an if/else chain over 2, 3, 6, 7 (GCC merges the identical arms).
 */
extern unsigned char DAT_a802b746, DAT_a802b742;
unsigned char FUN_a00f1100(unsigned char c)
{
    unsigned char r = 0;
    if (c == 2)
        r = DAT_a802b746;
    else if (c == 3)
        r = DAT_a802b742;
    else if (c == 6)
        r = DAT_a802b746;
    else if (c == 7)
        r = DAT_a802b742;
    return r;
}
