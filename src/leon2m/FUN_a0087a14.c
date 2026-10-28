/* leon2m FUN_a0087a14 @ 0xa0087a14-0xa0087d5c, flags -mcpu=v8 -O3 -g.
 * Prints s_000ffd40 ("SetThemeMode = %d -> HDR_Type = %d\r\n") with mode and FUN_a00d7d48(). Entry 'mode' of the
 * 0x20-byte table DAT_000ff710: bytes 0..5, 8, 6, 7, 0xc, 0xb, 0xa, 9, 0xd and 0x10 go to FUN_a01471a0(0, item, byte)
 * for items 0..13 and 15; when bit 31 of word +0x11c of DAT_a802d290 is clear, FUN_a014737c(0, 2, 0, 0) and
 * FUN_a01474b0(0, entry pointer +0x14); then FUN_a0147560(0, pointer +0x18) and FUN_a0147610(0, pointer +0x1c).
 * When FUN_a0080320(1) == 1 the same calls follow with first argument 1 and the same bytes.
 * Source form: both bit-31 tests are 'w11c & m' with a local m = 0x80000000; the first byte is read as
 *   t[mode].b[0], the others through r = t + mode; each round is 'if (!(w & m)) { 737c; 74b0; }' followed by the
 *   two common calls; the format string is the symbol s_000ffd40.
 * Compiler aid: 'for (;;) break;' as the first statement emits no instructions; its loop notes change how cse
 *   treats the following code, so the round-1 test loads the word into %o5 and the 0x80000000 constant into %g1
 *   as in the firmware.
 */
struct Theme {
    unsigned char b[0x14];
    const void *p14;
    const void *p18;
    const void *p1c;
};
extern const struct Theme DAT_000ff710[];
extern int FUN_a00df170(const char *fmt, ...);
extern int FUN_a00d7d48(void);
extern void FUN_a01471a0(unsigned char ch, unsigned char item, unsigned char v);
extern void FUN_a014737c(unsigned char ch, unsigned char mode, unsigned char a, unsigned char b);
extern void FUN_a01474b0(unsigned char ch, const void *p);
extern void FUN_a0147560(unsigned char ch, const void *p);
extern void FUN_a0147610(unsigned char ch, const void *p);
extern unsigned char FUN_a0080320(unsigned char port);

struct R290 { unsigned char p000[0x11c]; unsigned int w11c; };
extern struct R290 DAT_a802d290;

extern char s_000ffd40[];

void FUN_a0087a14(unsigned char mode)
{
    const struct Theme *t, *r;
    unsigned int m = 0x80000000;
    unsigned char v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v15;

    for (;;) break;

    FUN_a00df170(s_000ffd40, mode, FUN_a00d7d48());
    t = DAT_000ff710;
    v0 = t[mode].b[0];
    FUN_a01471a0(0, 0, v0);
    r = t + mode;
    v1 = r->b[1];
    FUN_a01471a0(0, 1, v1);
    v2 = r->b[2];
    FUN_a01471a0(0, 2, v2);
    v3 = r->b[3];
    FUN_a01471a0(0, 3, v3);
    v4 = r->b[4];
    FUN_a01471a0(0, 4, v4);
    v5 = r->b[5];
    FUN_a01471a0(0, 5, v5);
    v6 = r->b[8];
    FUN_a01471a0(0, 6, v6);
    v7 = r->b[6];
    FUN_a01471a0(0, 7, v7);
    v8 = r->b[7];
    FUN_a01471a0(0, 8, v8);
    v9 = r->b[0xc];
    FUN_a01471a0(0, 9, v9);
    v10 = r->b[0xb];
    FUN_a01471a0(0, 10, v10);
    v11 = r->b[0xa];
    FUN_a01471a0(0, 11, v11);
    v12 = r->b[9];
    FUN_a01471a0(0, 12, v12);
    v13 = r->b[0xd];
    FUN_a01471a0(0, 13, v13);
    v15 = r->b[0x10];
    FUN_a01471a0(0, 15, v15);
    if (!(DAT_a802d290.w11c & m)) {
        FUN_a014737c(0, 2, 0, 0);
        FUN_a01474b0(0, r->p14);
    }
    FUN_a0147560(0, r->p18);
    FUN_a0147610(0, r->p1c);
    if (FUN_a0080320(1) != 1)
        return;
    FUN_a01471a0(1, 0, v0);
    FUN_a01471a0(1, 1, v1);
    FUN_a01471a0(1, 2, v2);
    FUN_a01471a0(1, 3, v3);
    FUN_a01471a0(1, 4, v4);
    FUN_a01471a0(1, 5, v5);
    FUN_a01471a0(1, 6, v6);
    FUN_a01471a0(1, 7, v7);
    FUN_a01471a0(1, 8, v8);
    FUN_a01471a0(1, 9, v9);
    FUN_a01471a0(1, 10, v10);
    FUN_a01471a0(1, 11, v11);
    FUN_a01471a0(1, 12, v12);
    FUN_a01471a0(1, 13, v13);
    FUN_a01471a0(1, 15, v15);
    if (!(DAT_a802d290.w11c & m)) {
        FUN_a014737c(1, 2, 0, 0);
        FUN_a01474b0(1, r->p14);
    }
    FUN_a0147560(1, r->p18);
    FUN_a0147610(1, r->p1c);
}
