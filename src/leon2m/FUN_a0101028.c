/* FUN_a0101028 (leon2m 0xa0101028-0xa01010f4, 204 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when c is 6, 7, 12, 13, 0x12, 0x13, 0x18, 0x19, 0x20, 0x21, 0x26 or 0x27, otherwise 0. Called by
 * FUN_a013dc6c. It lies between FUN_a0100e6c and FUN_a01010f4. Source form: one || chain; 12 and 13 are tested as
 * (unsigned char)(c - 12) < 2.
 */
int FUN_a0101028(unsigned char c)
{
    if ((unsigned char)(c - 12) < 2 || c == 6 || c == 7 || c == 0x12 || c == 0x13 || c == 0x18 || c == 0x19 ||
        c == 0x20 || c == 0x21 || c == 0x26 || c == 0x27)
        return 1;
    return 0;
}
