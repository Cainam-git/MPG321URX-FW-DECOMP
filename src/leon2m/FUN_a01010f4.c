/* FUN_a01010f4 (leon2m 0xa01010f4-0xa01011c0, 204 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when c is 4, 5, 10, 11, 0x10, 0x11, 0x16, 0x17, 0x1e, 0x1f, 0x24 or 0x25, otherwise 0. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0101028 and
 * FUN_a01011c0. Source form: one || chain; 10 and 11 are tested as (unsigned char)(c - 10) < 2 (same form as
 * FUN_a0101028).
 */
int FUN_a01010f4(unsigned char c)
{
    if ((unsigned char)(c - 10) < 2 || c == 4 || c == 5 || c == 0x10 || c == 0x11 || c == 0x16 || c == 0x17 ||
        c == 0x1e || c == 0x1f || c == 0x24 || c == 0x25)
        return 1;
    return 0;
}
