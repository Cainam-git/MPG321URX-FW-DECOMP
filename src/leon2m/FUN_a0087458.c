/* leon2m FUN_a0087458 @ 0xa0087458-0xa00874c8 (28 words), flags -mcpu=v8 -O3 -g.
 * Returns 0 unless FUN_a0143c14(0) is above 8. Then r = 2 when 0x54 <= x < 0x118, r = 3 when bit 7 of the word
 * 0xa802d338 is set (this test follows the range test and overrides it), else 0; the result is r, or 0 when
 * FUN_a00d7d48() returns nonzero. Callers include FUN_a00d8bd8, FUN_a00d8c1c and FUN_a00dbcf0.
 * Source form: two separate ifs for r (the fw returns to the bit test after r = 2); r and the result are
 * separate unsigned int variables, the result set to r after the FUN_a00d7d48 test (fw 'and %l0,%o2,%i0').
 */
extern unsigned char FUN_a0143c14(unsigned char ch);
extern int FUN_a00d7d48(void);
extern unsigned int _DAT_a802d338;

int FUN_a0087458(unsigned short x)
{
    unsigned int r = 0;
    unsigned int ret = 0;

    if (FUN_a0143c14(0) > 8) {
        if (x >= 0x54 && x < 0x118)
            r = 2;
        if (_DAT_a802d338 & 0x80)
            r = 3;
        if (FUN_a00d7d48())
            r = 0;
        ret = r;
    }
    return ret;
}
