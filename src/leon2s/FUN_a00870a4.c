/* leon2s FUN_a00870a4 @ 0xa00870a4-0xa0087110 (27 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/27 mismatches.
 * Code facts: leaf; r = 7; mode & 0xf == 4 -> 4 when caps[4] & 0x11 == 0x11 and caps[5] & 0x11 ==
 * 0x11; mode == 2 -> 4 when caps[4] & 0x11 == 0x11; other modes -> 4 when bit 0 of caps[4] is set.
 * Returns u8 (fw 'and 7' = the nonzero-bits form of the u8 extension of 4|7).
 * Fixes vs the autoc draft (50.00): u8 return/result (the draft returned int), one && chain for
 * mode 4. Aids: none.
 */
unsigned char FUN_a00870a4(unsigned int mode, unsigned char *caps)
{
    unsigned char r = 7;

    if ((mode & 0xf) == 4) {
        if ((caps[4] & 0x11) == 0x11 && (caps[5] & 0x11) == 0x11)
            r = 4;
    } else if ((mode & 0xf) == 2) {
        if ((caps[4] & 0x11) == 0x11)
            r = 4;
    } else if (caps[4] & 1)
        r = 4;
    return r;
}
