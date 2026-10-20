/* FUN_a00add48 (leon2s 0xa00add48-0xa00add8c, 68 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns 9 for a == 2; otherwise byte b of the 4-byte row a of DAT_a8078768 when a * 4 + b <= 4 (signed int),
 * else byte 0 of that row. Called from FUN_a00adf84, FUN_a00af8bc and FUN_a00af94c.
 */
extern unsigned char DAT_a8078768[][4];

unsigned char FUN_a00add48(unsigned char a, unsigned char b)
{
    if (a == 2)
        return 9;
    if (a * 4 + b > 4)
        return DAT_a8078768[a][0];
    return DAT_a8078768[a][b];
}
