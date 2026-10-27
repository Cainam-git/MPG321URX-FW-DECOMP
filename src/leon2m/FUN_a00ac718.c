/* leon2m FUN_a00ac718 @ 0xa00ac718-0xa00acc40 (330 words), flags -mcpu=v8 -O3 -g. Callers include FUN_a009a198,
 * FUN_a009a2d0 and FUN_a00a2264.
 * FUN_a0146b50(0x111, 0), FUN_a0146b6c(0, 0), FUN_a00a8c88(). From id: n = 3 for 0x34 (sel = byte +0x1dd of
 * DAT_a802d290), 0x38 / 0x39 / 0x3a (sel = byte +0x1e8 / +0x1ea / +0x1ec) and 0xba; n = 2 for 0x36 (sel = byte
 * +0x1ee), 0xbd and 0xbe; n = 5 for 0x37 (sel = bit 15 of word +0x1dc); n = 6 for 0x3b; n = 7 for 0xbf when byte
 * +0x1df <= 6, else 1; otherwise n = 0 and it returns (sel starts at 7).
 * Two 15-byte buffers get FUN_a01577f4(buf, "n %d, %dh  %dm" at 0x1981c0, FUN_a0145af8(0xf / 0xe),
 * FUN_a0145af8(0xd / 0xc), FUN_a0145af8(0xb / 0xa)); byte 0 of each becomes (index of its first 0 byte) - 1.
 * For i = 0..n-1: r = FUN_a00ac138(id, i); for id 0x3b: FUN_a0146b6c(0, 0); when i is 2..4 and byte +8 is 0xd,
 * FUN_a00a31a4(0, 0x28, i * 2 + 6, 1, r, 0) for i 2 or 4, else FUN_a0146a80(0x26, i * 2 + 6, 1, 0x796, 0) and
 * FUN_a00a31a4(0, 0x26, ...); other i FUN_a00a31a4(0, 0x29, ...); then FUN_a0146b6c(1, 0) and a switch on i (jump
 * table) passing the first buffer (i = 0) or FUN_a00a3844(table, value * 29 + byte +8) to FUN_a00a31a4(0, 0x27,
 * i * 2 + 7, 0xe, ..., 0). Other ids: FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, r, 0). Finally, unless sel is 7,
 * FUN_a00a9650(sel, 0) and FUN_a0146b20(0, 0x28 / 0x29, y, 1, 0xf / 0x10, 0) with y = sel * 2 + 6 (sel <= 6) or
 * sel * 2 - 8.
 * Source form: the case blocks of the id switch in the order written (it sets the register choices); 0xbd and 0xbe
 * are separate cases with their own 'n = 2', and 'case 0x35: n = 0;' (a body equal to the default, dropped later)
 * gives the compare tree its root 0x39; the format string is the symbol s_001981c0.
 */
struct R290 { unsigned char p000[8]; unsigned char b008; unsigned char p009[0x1dc - 9];
              union { unsigned int w; unsigned char b[4]; } u1dc; unsigned char p1e0[0x1e8 - 0x1e0];
              unsigned char b1e8; unsigned char p1e9; unsigned char b1ea; unsigned char p1eb; unsigned char b1ec;
              unsigned char p1ed; unsigned char b1ee; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_00193248[], DAT_0018b5e0[];
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00a8c88(void);
extern unsigned short FUN_a0145af8(unsigned int);
extern void FUN_a01577f4(unsigned char *, const char *, ...);
extern const char s_001981c0[];
extern unsigned int FUN_a00ac138(unsigned short, unsigned char);
extern void FUN_a00a31a4(int, unsigned short, unsigned short, int, unsigned int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00ac718(unsigned short id)
{
    unsigned char b2[15] = {0};
    unsigned char b1[15] = {0};
    unsigned char n, sel, i, j, y;
    unsigned int r;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    FUN_a00a8c88();
    sel = 7;
    n = 0;
    switch (id) {
    case 0x34:
        sel = DAT_a802d290.u1dc.b[1];
        n = 3;
        break;
    case 0x35:
        n = 0;
        break;
    case 0xba:
        n = 3;
        break;
    case 0x37:
        sel = (DAT_a802d290.u1dc.w >> 15) & 1;
        n = 5;
        break;
    case 0xbe:
        n = 2;
        break;
    case 0x3b:
        n = 6;
        break;
    case 0x36:
        sel = DAT_a802d290.b1ee;
        n = 2;
        break;
    case 0xbf:
        if (DAT_a802d290.u1dc.b[3] <= 6)
            n = 7;
        else
            n = 1;
        break;
    case 0xbd:
        n = 2;
        break;
    case 0x38:
        sel = DAT_a802d290.b1e8;
        n = 3;
        break;
    case 0x39:
        sel = DAT_a802d290.b1ea;
        n = 3;
        break;
    case 0x3a:
        sel = DAT_a802d290.b1ec;
        n = 3;
        break;
    }
    if (n == 0)
        return;
    FUN_a01577f4(b1, s_001981c0, FUN_a0145af8(0xf), FUN_a0145af8(0xd), FUN_a0145af8(0xb));
    for (j = 0; j < 15; j++)
        if (b1[j] == 0)
            break;
    b1[0] = j - 1;
    FUN_a01577f4(b2, s_001981c0, FUN_a0145af8(0xe), FUN_a0145af8(0xc), FUN_a0145af8(0xa));
    for (j = 0; j < 15; j++)
        if (b2[j] == 0)
            break;
    b2[0] = j - 1;
    for (i = 0; i < n; i++) {
        r = FUN_a00ac138(id, i);
        if (id == 0x3b) {
            FUN_a0146b6c(0, 0);
            if ((unsigned char)(i - 2) <= 2 && DAT_a802d290.b008 == 0xd) {
                if (i == 2 || i == 4) {
                    FUN_a00a31a4(0, 0x28, i * 2 + 6, 1, r, 0);
                } else {
                    FUN_a0146a80(0x26, i * 2 + 6, 1, 0x796, 0);
                    FUN_a00a31a4(0, 0x26, i * 2 + 6, 1, r, 0);
                }
            } else {
                FUN_a00a31a4(0, 0x29, i * 2 + 6, 1, r, 0);
            }
            FUN_a0146b6c(1, 0);
            switch (i) {
            case 0:
                FUN_a00a31a4(0, 0x27, i * 2 + 7, 0xe, (unsigned int)b1, 0);
                break;
            case 1:
                FUN_a00a31a4(0, 0x27, i * 2 + 7, 0xe,
                             FUN_a00a3844(DAT_0018b5e0, DAT_a802d290.u1dc.b[1] * 29 + DAT_a802d290.b008), 0);
                break;
            case 2:
                FUN_a00a31a4(0, 0x27, i * 2 + 7, 0xe,
                             FUN_a00a3844(DAT_00193248, ((DAT_a802d290.u1dc.w >> 15) & 1) * 29 + DAT_a802d290.b008), 0);
                break;
            case 3:
                FUN_a00a31a4(0, 0x27, i * 2 + 7, 0xe,
                             FUN_a00a3844(DAT_00193248, DAT_a802d290.b1e8 * 29 + DAT_a802d290.b008), 0);
                break;
            case 4:
                FUN_a00a31a4(0, 0x27, i * 2 + 7, 0xe,
                             FUN_a00a3844(DAT_00193248, DAT_a802d290.b1ea * 29 + DAT_a802d290.b008), 0);
                break;
            case 5:
                FUN_a00a31a4(0, 0x27, i * 2 + 7, 0xe,
                             FUN_a00a3844(DAT_00193248, DAT_a802d290.b1ec * 29 + DAT_a802d290.b008), 0);
                break;
            }
        } else {
            FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, r, 0);
        }
    }
    if (sel == 7)
        return;
    FUN_a00a9650(sel, 0);
    if (sel <= 6)
        y = sel * 2 + 6;
    else
        y = sel * 2 - 8;
    FUN_a0146b20(0, 0x28, y, 1, 0xf, 0);
    FUN_a0146b20(0, 0x29, y, 1, 0x10, 0);
}
