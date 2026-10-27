/* leon2m FUN_a00a8c88 @ 0xa00a8c88-0xa00a8ee8 (152 words), flags -mcpu=v8 -O3 -g. Called by many FUN_a009xxxx /
 * FUN_a00axxxx / FUN_a00bxxxx functions.
 * func_0x4008e2a4(); then for rows i = 5..0x14: a = 0xc for row 0x14, else 0xe; FUN_a0146b20(0, 0x27, i, a, 0, 0)
 * and FUN_a0146a80(0x27, i, a, 0x796, 0); for row 0xc, when FUN_a0090fcc() returns above 0x33 or a second call
 * returns at most 0x3b, and byte 0xa802d290+8 is 0xd, also FUN_a0146b20(0, 0x26, 0xc, 1, 0, 0) and
 * FUN_a0146a80(0x26, 0xc, 1, 0x796, 0). Then FUN_a0146b20(0, 0x2d, 0x15, 2, 0, 0), FUN_a0146c40(5, 0, 0),
 * FUN_a0146c40(4, 0, 0); when the value of FUN_a0090fcc() is in one of the sets 63..64, {67, 237..239}, 68..69,
 * 231..236, {111, 204}, 122..124, 205..207, 208..211, 216..220, 130..131, 212..215, FUN_a00b3ed0(0, 0x27, 1, 0xe)
 * is tail-called.
 * Source form: the value test is a static helper with one 'return 1' per set and a final 'return 0' (inlined);
 * a set of two disjoint parts is one || test, so GCC evaluates both parts as flag values.
 */
struct R290 { unsigned char p000[8]; unsigned char b08; };
extern struct R290 DAT_a802d290;
extern void func_0x4008e2a4(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);

static unsigned char sup(unsigned int v)
{
    if (v >= 63 && v <= 64)
        return 1;
    if (v == 67 || (v >= 237 && v <= 239))
        return 1;
    if (v >= 68 && v <= 69)
        return 1;
    if (v >= 231 && v <= 236)
        return 1;
    if (v == 111 || v == 204)
        return 1;
    if (v >= 122 && v <= 124)
        return 1;
    if (v >= 205 && v <= 207)
        return 1;
    if (v >= 208 && v <= 211)
        return 1;
    if (v >= 216 && v <= 220)
        return 1;
    if (v >= 130 && v <= 131)
        return 1;
    if (v >= 212 && v <= 215)
        return 1;
    return 0;
}

void FUN_a00a8c88(void)
{
    unsigned char i, a, f;
    unsigned int v;

    func_0x4008e2a4();
    for (i = 5; i <= 0x14; i++) {
        a = i == 0x14 ? 0xc : 0xe;
        FUN_a0146b20(0, 0x27, i, a, 0, 0);
        FUN_a0146a80(0x27, i, a, 0x796, 0);
        if ((FUN_a0090fcc() > 0x33 || FUN_a0090fcc() <= 0x3b) && i == 0xc && DAT_a802d290.b08 == 0xd) {
            FUN_a0146b20(0, 0x26, 0xc, 1, 0, 0);
            FUN_a0146a80(0x26, 0xc, 1, 0x796, 0);
        }
    }
    FUN_a0146b20(0, 0x2d, 0x15, 2, 0, 0);
    FUN_a0146c40(5, 0, 0);
    FUN_a0146c40(4, 0, 0);
    v = FUN_a0090fcc();
    f = sup(v);
    if (f)
        FUN_a00b3ed0(0, 0x27, 1, 0xe);
}
