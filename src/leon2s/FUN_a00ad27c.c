/* FUN_a00ad27c (leon2s 0xa00ad27c-0xa00ad320, 164 bytes), flags -mcpu=v8 -Os -g.
 * Returns 0 when the low byte of FUN_a00856d0(port) is 1. Otherwise reads b = FUN_a0085684(port) and
 * counts how many of the bit pairs 0x11, 0x22, 0x44 and 0x88 are both set in b; returns 1 when the
 * count is not 0, else 0.
 * Source form: the count is a byte incremented by four separate ifs (GCC turns the last three into
 * subx/add sequences and keeps a branch for the first one).
 */
extern int FUN_a00856d0(unsigned char);
extern unsigned char FUN_a0085684(unsigned char);

unsigned char FUN_a00ad27c(unsigned char port)
{
    unsigned char r = 0;
    unsigned char b, n;

    if ((unsigned char)FUN_a00856d0(port) == 1)
        return 0;
    b = FUN_a0085684(port);
    n = 0;
    if ((b & 0x11) == 0x11)
        n++;
    if ((b & 0x22) == 0x22)
        n++;
    if ((b & 0x44) == 0x44)
        n++;
    if ((b & 0x88) == 0x88)
        n++;
    if (n)
        r = 1;
    return r;
}
