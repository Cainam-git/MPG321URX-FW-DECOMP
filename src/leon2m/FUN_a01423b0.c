/* FUN_a01423b0 (leon2m 0xa01423b0-0xa01423dc, 44 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 0 for c = 0, 1 for c = 1 and 3 for any other value. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a01423a8 and FUN_a01423dc. Source form: r = 3 as default,
 * a switch for cases 0 and 1, return r & 3.
 */
unsigned char FUN_a01423b0(unsigned char c)
{
    unsigned char r = 3;
    switch (c) { case 0: r = 0; break; case 1: r = 1; break; }
    return r & 3;
}
