/* leon2m FUN_a00f6fe4 @ 0xa00f6fe4 (-mcpu=v8 -O3 -g). Called by FUN_a00f793c, FUN_a012e6c0, FUN_a013ae00,
 * FUN_a013b4e8, FUN_a013b544, FUN_a013b5a0, FUN_a013b5fc and FUN_a0150b8c.
 * Parameters (en, mode, m, mask). m points to 12 halfwords: three rows of three values followed by one row value
 * (m[0..2], m[3]; m[4..6], m[7]; m[8..10], m[11]). When m is 0 a local default table is used: rows
 * {0x100, 0, 0, 0x80}, {0, 0x100, 0, 0x80}, {0, 0, 0x100, 0x80}.
 * Bit 6 of 0xcf00e984 = en != 0; mode 1 sets bit 7, mode 0 clears it. For mask bits 0, 1, 2:
 * 0xcf00e984 = (0xcf00e984 & 0xf1) | 0, 2, 4, then the low and high bytes of the three values of row 0, 1, 2 are
 * written to 0xcf00e98c..0xcf00e9a0. For mask bits 4, 5, 6: 0xcf00e984 = (0xcf00e984 & 0xf0) | 1, 3, 5, then the
 * row value (m[3], m[7], m[11]) is written to 0xcf00e9a4. Then calls func_0x4008e2a4() and sets bit 3 of 0xcf00e984.
 * Source form: m and the default table are the union of 12 halfwords and 6 words of the getter FUN_a00f72cc; the
 * default is a const local with a complete initialiser, written like table m0 of the caller FUN_a0150b8c (GCC
 * clears it with three std of zero, then stores the non-zero halfwords); the low byte is read as h & 0xff (ldub).
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void func_0x4008e2a4(void);
union P { unsigned short h[12]; unsigned int w[6]; };

void FUN_a00f6fe4(unsigned char en, int mode, const union P *m, unsigned int mask)
{
    const union P def = { {0x100, 0, 0, 0x80, 0, 0x100, 0, 0x80, 0, 0, 0x100, 0x80} };

    if (m == 0)
        m = &def;
    if (en)
        R(0xcf00e984) |= 0x40;
    else
        R(0xcf00e984) &= ~0x40;
    if (mode == 1)
        R(0xcf00e984) |= 0x80;
    else if (mode == 0)
        R(0xcf00e984) &= ~0x80;
    if (mask & 1) {
        R(0xcf00e984) &= 0xf1;
        R(0xcf00e98c) = m->h[0] & 0xff;
        R(0xcf00e990) = m->h[0] >> 8;
        R(0xcf00e994) = m->h[1] & 0xff;
        R(0xcf00e998) = m->h[1] >> 8;
        R(0xcf00e99c) = m->h[2] & 0xff;
        R(0xcf00e9a0) = m->h[2] >> 8;
    }
    if (mask & 2) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf1) | 2;
        R(0xcf00e98c) = m->h[4] & 0xff;
        R(0xcf00e990) = m->h[4] >> 8;
        R(0xcf00e994) = m->h[5] & 0xff;
        R(0xcf00e998) = m->h[5] >> 8;
        R(0xcf00e99c) = m->h[6] & 0xff;
        R(0xcf00e9a0) = m->h[6] >> 8;
    }
    if (mask & 4) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf1) | 4;
        R(0xcf00e98c) = m->h[8] & 0xff;
        R(0xcf00e990) = m->h[8] >> 8;
        R(0xcf00e994) = m->h[9] & 0xff;
        R(0xcf00e998) = m->h[9] >> 8;
        R(0xcf00e99c) = m->h[10] & 0xff;
        R(0xcf00e9a0) = m->h[10] >> 8;
    }
    if (mask & 0x10) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf0) | 1;
        R(0xcf00e9a4) = m->h[3];
    }
    if (mask & 0x20) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf0) | 3;
        R(0xcf00e9a4) = m->h[7];
    }
    if (mask & 0x40) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf0) | 5;
        R(0xcf00e9a4) = m->h[11];
    }
    func_0x4008e2a4();
    R(0xcf00e984) |= 8;
}
