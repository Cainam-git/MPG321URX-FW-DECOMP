/* FUN_a01011c0 (leon2m 0xa01011c0-0xa010128c, 204 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when c is 2, 3, 8, 9, 0xe, 0xf, 0x14, 0x15, 0x1c, 0x1d, 0x22 or 0x23, otherwise 0. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a01010f4 and FUN_a010128c.
 * Source form: one || chain; 8 and 9 are tested as (unsigned char)(c - 8) < 2 (same form as FUN_a0101028).
 */
int FUN_a01011c0(unsigned char c)
{
    if ((unsigned char)(c - 8) < 2 || c == 2 || c == 3 || c == 0xe || c == 0xf || c == 0x14 || c == 0x15 ||
        c == 0x1c || c == 0x1d || c == 0x22 || c == 0x23)
        return 1;
    return 0;
}
