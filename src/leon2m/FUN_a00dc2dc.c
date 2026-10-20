/* leon2m FUN_a00dc2dc @ 0xa00dc2dc-0xa00dc3dc (64 words).
 * Reloads the 0x1fc-byte record at 0xa802d290 from the table at 0x198524 (FUN_a013c910 copy) but keeps byte +0x1e
 * and the byte pairs +0x1e2 / +0x1e3 and +0x1e6 / +0x1e7. Then the bytes +0x12, +0x13, +0x14 are limited to 100,
 * stored back and passed to FUN_a014a11c(0..2, v), followed by FUN_a00d94fc(), and FUN_a00db738() when bit 11 of
 * the word at +0xa8 is set, FUN_a00dbcf0() when it is clear.
 * The byte pairs are kept in 2-byte local structures, copied member by member (a structure assignment copies
 * them as halfwords); the limited value is an unsigned short as in FUN_a00d972c.
 */
struct Pair {
    unsigned char a;
    unsigned char b;
};
struct R290 {
    unsigned char pad0[0x12];
    unsigned char b12;
    unsigned char b13;
    unsigned char b14;
    unsigned char pad15[0x1e - 0x15];
    unsigned char b1e;
    unsigned char pad1f[0xa8 - 0x1f];
    unsigned int wa8;
    unsigned char padac[0x1e2 - 0xac];
    struct Pair p1e2;
    unsigned char pad1e4[2];
    struct Pair p1e6;
};
extern struct R290 DAT_a802d290;
extern const unsigned char DAT_00198524[];
extern void *FUN_a013c910(void *, const void *, unsigned int);
extern void FUN_a014a11c(int, unsigned char);
extern void FUN_a00d94fc(void);
extern void FUN_a00db738(void);
extern void FUN_a00dbcf0(void);

void FUN_a00dc2dc(void)
{
    struct Pair s1, s2;
    unsigned char k;

    s1.a = DAT_a802d290.p1e2.a;
    s1.b = DAT_a802d290.p1e2.b;
    s2.a = DAT_a802d290.p1e6.a;
    s2.b = DAT_a802d290.p1e6.b;
    k = DAT_a802d290.b1e;
    unsigned short v;

    FUN_a013c910(&DAT_a802d290, DAT_00198524, 0x1fc);
    DAT_a802d290.b1e = k;
    DAT_a802d290.p1e2.a = s1.a;
    DAT_a802d290.p1e2.b = s1.b;
    DAT_a802d290.p1e6.a = s2.a;
    DAT_a802d290.p1e6.b = s2.b;
    v = DAT_a802d290.b12;
    if (v > 100)
        v = 100;
    DAT_a802d290.b12 = v;
    FUN_a014a11c(0, v);
    v = DAT_a802d290.b13;
    if (v > 100)
        v = 100;
    DAT_a802d290.b13 = v;
    FUN_a014a11c(1, v);
    v = DAT_a802d290.b14;
    if (v > 100)
        v = 100;
    DAT_a802d290.b14 = v;
    FUN_a014a11c(2, v);
    FUN_a00d94fc();
    if (!(DAT_a802d290.wa8 & 0x800))
        FUN_a00dbcf0();
    else
        FUN_a00db738();
}
