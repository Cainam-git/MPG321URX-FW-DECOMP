/* FUN_a00d787c (leon2s, 0xa00d787c-0xa00d78d8, 92 bytes, 23 words, leaf).
 * Flags: -mcpu=v8 -Os -g. Judge: jf 100.00 match=True, rawcmp_l2s 0/23 mismatches.
 * Code facts: copies a 24-byte block param_1 -> param_2: byte 0 & 0x7f, byte 1 & 0xf8, byte 2 & 0xf9,
 * byte 3 as is, then bytes 4..23 in a u8 loop (i = 0..0x13).
 * Fix vs draft: bytes 1 and 2 are masked in an unsigned int temporary in separate statements
 * (fw 'and 0xf8' / 'and 0xf9'); a direct 'dst = src & 0xf8' is narrowed to a QImode and with the
 * sign-extended constant (-8 / -7). Byte 0 (0x7f) is the same either way. Aids: none.
 */
void FUN_a00d787c(unsigned char *param_1, unsigned char *param_2)
{
    unsigned char bVar1;
    unsigned int t;

    *param_2 = *param_1 & 0x7f;
    t = param_1[1];
    t &= 0xf8;
    param_2[1] = t;
    t = param_1[2];
    t &= 0xf9;
    param_2[2] = t;
    param_2[3] = param_1[3];

    bVar1 = 0;
    do {
        param_2[(bVar1 & 0xff) + 4] = param_1[(bVar1 & 0xff) + 4];
        bVar1 = bVar1 + 1;
    } while ((bVar1 & 0xff) <= 0x13);
}
