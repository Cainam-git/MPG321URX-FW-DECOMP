/* leon2m FUN_a013ae00 @ 0xa013ae00-0xa013b42c, flags -mcpu=v8 -O3 -g -msoft-float (the float arithmetic is libgcc
 * soft-float calls: __floatsisf, __mulsf3, __extendsfdf2, __adddf3, __fixdfsi).
 * Called with the byte p by FUN_a008ef48 (p = 0x80) and by FUN_a013b42c, FUN_a013b44c, FUN_a013b46c, FUN_a013b4a4,
 * FUN_a013b684, FUN_a014bcf0, FUN_a014c7bc (p = byte 0xa802a460).
 * What it does, all values Q12 (x * 4096) unless noted:
 *   - stores p to the byte 0xa802a460 (the store of FUN_a013adf4, written as a call of an inlined static copy);
 *   - h (3x3 int): row 0 and column 0 zero; w = a462 * a461 >> 7 when the signed byte a461 (0xa802a461) is >= 0,
 *     else a462 * (256 - a461) / 128 (a462 = byte 0xa802a462), kept as unsigned short; with t = byte 0xa802cbbd:
 *     h[1][1] = ((w << 5) * T(t + 0x40) + 0x800) >> 12, h[1][2] = ((w << 5) * T(t) + 0x800) >> 12,
 *     h[2][1] = (-T(t) * (w << 5) + 0x800) >> 12, h[2][2] = (T(t + 0x40) * (w << 5) + 0x800) >> 12, where T(x) reads
 *     the 65-word table at 0x1a56b4 (0, 100, ..., 4096) by x & 0xc0: 0x00 -> tab[i], 0x40 -> tab[64 - i],
 *     0x80 -> -tab[i], else -tab[64 - i], i = x & 0x3f;
 *   - m1 = h x A (A = 3x3 words at 0x1a5690), each entry (sum + 0x800) >> 12; then row 0 of m1 is replaced by
 *     (A[0][j] * (a461 << 5) + 0x800) >> 12;
 *   - m2 = B x m1 (B = 3x3 words at 0x1a566c), same rounding; each m2 entry becomes
 *     (int)((float)m2 * (float)p * 0.0078125f + 0.5);
 *   - out (3 rows of 4 halfwords, the 4th unused): s = (((m2 + 8) >> 4) * (halfword 0xa802a46c[row] << 4) + 0x800)
 *     >> 12, a negative s stored as ((s ^ 0xffff) + 1) | 0xf400;
 *   - FUN_a00f6fe4(bit 0 of byte 0xa802cbbc, bit 1 of it, out, 7).
 * Source form: T and the 3x3 product are static helpers inlined by GCC (the product as mul3(a, b, r): GCC then
 * keeps the bases of a and r in registers in that order); the arrays are declared m2, m1, h, out (the firmware's
 * stack order fp-48, fp-88, fp-128, fp-152); the a462 byte is read into a local before the sign test, and the
 * test is written 'a461 >= 0' first; 'w << 5' and 'a461 << 5' (a multiplication by 32 is reassociated by GCC);
 * p is converted as (float)(int)p (an unsigned char operand gives a signed conversion plus a 256.0f correction).
 * The table at 0x1a56b4 and the byte 0xa802cbbd are declared as DAT_001a56b4_w and _DAT_a802cbbd: these spellings
 * set the GCSE hash order of their address registers, which decides the register allocation of the T block
 * (%o7 for 0xa802cbbd, %o1 for w << 16, %o0 for the table address).
 */
extern unsigned char DAT_a802a460;
extern signed char DAT_a802a461;
extern unsigned char DAT_a802a462;
extern unsigned short DAT_a802a46c[];
extern unsigned char DAT_a802cbbc;
extern unsigned char _DAT_a802cbbd;
extern const int DAT_001a5690[3][3];
extern const int DAT_001a566c[3][3];
extern const int DAT_001a56b4_w[];
union C { unsigned short w; struct { unsigned char hi, lo; } b; };
extern void FUN_a00f6fe4(unsigned char en, int mode, union C *m, unsigned int mask);

static void FUN_a013adf4(unsigned char v)
{
    DAT_a802a460 = v;
}

static int tq(unsigned char a)
{
    unsigned char i = a & 0x3f;

    switch (a & 0xc0) {
    case 0x00:
        return DAT_001a56b4_w[i];
    case 0x40:
        return DAT_001a56b4_w[0x40 - i];
    case 0x80:
        return -DAT_001a56b4_w[i];
    default:
        return -DAT_001a56b4_w[0x40 - i];
    }
}

static void mul3(const int (*a)[3], const int (*b)[3], int (*r)[3])
{
    unsigned char i, j, k;
    int s;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            s = 0;
            for (k = 0; k < 3; k++)
                s += a[i][k] * b[k][j];
            r[i][j] = (s + 0x800) >> 12;
        }
    }
}

void FUN_a013ae00(unsigned char p)
{
    int m2[3][3];
    int m1[3][3];
    int h[3][3];
    unsigned short out[3][4];
    unsigned char i, j;
    unsigned char g;
    unsigned short w;
    int s;

    FUN_a013adf4(p);
    for (i = 0; i < 3; i++)
        h[i][0] = 0;
    for (i = 0; i < 3; i++)
        h[0][i] = 0;
    g = DAT_a802a462;
    if (DAT_a802a461 >= 0)
        w = g * (unsigned char)DAT_a802a461 >> 7;
    else
        w = g * (0x100 - (unsigned char)DAT_a802a461) / 128;
    h[1][1] = ((w << 5) * tq(_DAT_a802cbbd + 0x40) + 0x800) >> 12;
    h[1][2] = ((w << 5) * tq(_DAT_a802cbbd) + 0x800) >> 12;
    h[2][1] = (-tq(_DAT_a802cbbd) * (w << 5) + 0x800) >> 12;
    h[2][2] = (tq(_DAT_a802cbbd + 0x40) * (w << 5) + 0x800) >> 12;
    mul3(h, DAT_001a5690, m1);
    for (j = 0; j < 3; j++)
        m1[0][j] = (DAT_001a5690[0][j] * ((unsigned char)DAT_a802a461 << 5) + 0x800) >> 12;
    mul3(DAT_001a566c, m1, m2);
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            m2[i][j] = (int)((float)m2[i][j] * (float)(int)p * 0.0078125f + 0.5);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            s = (((m2[i][j] + 8) >> 4) * (DAT_a802a46c[i] << 4) + 0x800) >> 12;
            if (s < 0)
                s = ((s ^ 0xffff) + 1) | 0xf400;
            out[i][j] = s;
        }
    }
    FUN_a00f6fe4(DAT_a802cbbc & 1, (DAT_a802cbbc >> 1) & 1, (union C *)out, 7);
}
