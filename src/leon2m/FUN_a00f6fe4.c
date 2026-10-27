/* leon2m FUN_a00f6fe4 @ 0xa00f6fe4 (-mcpu=v8 -O3 -g). Called by FUN_a00f793c, FUN_a012e6c0, FUN_a013ae00,
 * FUN_a013b4e8, FUN_a013b544, FUN_a013b5a0, FUN_a013b5fc and FUN_a0150b8c.
 * Parameters (en, mode, m, mask). m points to 12 halfwords: three rows of three values followed by one row value
 * (m[0..2], m[3]; m[4..6], m[7]; m[8..10], m[11]). When m is 0 a local default table is used: rows
 * {0x100, 0, 0, 0x80}, {0, 0x100, 0, 0x80}, {0, 0, 0x100, 0x80}.
 * Bit 6 of 0xcf00e984 = en != 0; mode 1 sets bit 7, mode 0 clears it. For mask bits 0, 1, 2:
 * 0xcf00e984 = (0xcf00e984 & 0xf1) | 0, 2, 4, then the low and high bytes of the three values of row 0, 1, 2 are
 * written to 0xcf00e98c..0xcf00e9a0. For mask bits 4, 5, 6: 0xcf00e984 = (0xcf00e984 & 0xf0) | 1, 3, 5, then the
 * row value (m[3], m[7], m[11]) is written to 0xcf00e9a4. Then calls func_0x4008e2a4() and sets bit 3 of 0xcf00e984.
 * Source form: each element is a union of the halfword and its two bytes (low byte read with ldub, high byte as
 * w >> 8); the default table has an incomplete initialiser, so it is cleared first and the non-zero values stored.
 * Compiler aid: 'for (;;) break;' after the table emits no instructions; it ends the scheduling region of the table
 * set-up, which keeps the two halves of the zero register pair in the order clr %o4, clr %o5.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void func_0x4008e2a4(void);
union C { unsigned short w; struct { unsigned char hi, lo; } b; };

void FUN_a00f6fe4(unsigned char en, int mode, union C *m, unsigned int mask)
{
    union C def[12] = {[0] = {0x100}, [3] = {0x80}, [5] = {0x100}, [7] = {0x80}, [10] = {0x100}, [11] = {0x80}};

    for (;;)
        break;
    if (m == 0)
        m = def;
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
        R(0xcf00e98c) = m[0].b.lo;
        R(0xcf00e990) = m[0].w >> 8;
        R(0xcf00e994) = m[1].b.lo;
        R(0xcf00e998) = m[1].w >> 8;
        R(0xcf00e99c) = m[2].b.lo;
        R(0xcf00e9a0) = m[2].w >> 8;
    }
    if (mask & 2) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf1) | 2;
        R(0xcf00e98c) = m[4].b.lo;
        R(0xcf00e990) = m[4].w >> 8;
        R(0xcf00e994) = m[5].b.lo;
        R(0xcf00e998) = m[5].w >> 8;
        R(0xcf00e99c) = m[6].b.lo;
        R(0xcf00e9a0) = m[6].w >> 8;
    }
    if (mask & 4) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf1) | 4;
        R(0xcf00e98c) = m[8].b.lo;
        R(0xcf00e990) = m[8].w >> 8;
        R(0xcf00e994) = m[9].b.lo;
        R(0xcf00e998) = m[9].w >> 8;
        R(0xcf00e99c) = m[10].b.lo;
        R(0xcf00e9a0) = m[10].w >> 8;
    }
    if (mask & 0x10) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf0) | 1;
        R(0xcf00e9a4) = m[3].w;
    }
    if (mask & 0x20) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf0) | 3;
        R(0xcf00e9a4) = m[7].w;
    }
    if (mask & 0x40) {
        R(0xcf00e984) = (R(0xcf00e984) & 0xf0) | 5;
        R(0xcf00e9a4) = m[11].w;
    }
    func_0x4008e2a4();
    R(0xcf00e984) |= 8;
}
