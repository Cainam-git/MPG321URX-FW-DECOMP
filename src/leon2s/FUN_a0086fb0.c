/* leon2s FUN_a0086fb0 @ 0xa0086fb0-0xa0087074 (196 bytes, 49 words)
 * Flags: -mcpu=v8 -Os -g.
 * void (u8 *p, int mode, u8 *out1, u8 *out2). mode &= 0xf (signed compares). out1 = the maximum of p[8..9]
 * and out2 the maximum of p[0xc..0xd] when mode > 1. When mode == 4 they cover p[8..0xb] and p[0xc..0xf].
 * When mode <= 1 they are p[8] and p[0xc].
 * Source form: every step is written 'if (v < p[k]) v = p[k];', so each load is its own block-local value;
 * the firmware gives them fresh registers (%i2, %i1, %i0) and re-masks both sides with and 0xff. One shared
 * temp variable gives one global register instead. 'p[k] > v' gives the same code as 'v < p[k]'.
 */
void FUN_a0086fb0(unsigned char *p, int mode, unsigned char *out1, unsigned char *out2)
{
    unsigned char v1 = p[8];
    unsigned char v2 = p[0xc];

    mode &= 0xf;
    if (mode > 1) {
        if (v1 < p[9])
            v1 = p[9];
        if (v2 < p[0xd])
            v2 = p[0xd];
        if (mode == 4) {
            if (v1 < p[0xa])
                v1 = p[0xa];
            if (v1 < p[0xb])
                v1 = p[0xb];
            if (v2 < p[0xe])
                v2 = p[0xe];
            if (v2 < p[0xf])
                v2 = p[0xf];
        }
    }
    *out1 = v1;
    *out2 = v2;
}
