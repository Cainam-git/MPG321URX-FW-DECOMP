/* leon2s FUN_a00870a4 @ 0xa00870a4-0xa0087110 (27 words), flags -mcpu=v8 -Os -g.
 * Leaf; r = 7; mode & 0xf == 4 -> 4 when caps[4] & 0x11 == 0x11 and caps[5] & 0x11 == 0x11; mode == 2 -> 4
 * when caps[4] & 0x11 == 0x11; other modes -> 4 when bit 0 of caps[4] is set.
 * Returns u8 (firmware 'and 7' = the nonzero-bits form of the u8 extension of 4|7).
 * Source form: u8 return and result; one && chain for mode 4.
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
