/* leon2m FUN_a00a5e68 @ 0xa00a5e68-0xa00a6b98 (3376 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Callers: FUN_a009811c (on = 1), FUN_a009f42c (on = 1 / 0), FUN_a0090fac. D = the record at 0xA802D290.
 * n = FUN_a014837c(0) / 24 + 1; returns at once when bit 10 of the u16 at 0xA802CFF4 is set.
 * Position pairs: (x0, y0) from byte D+0x13e and (x1, y1) from byte D+0x13f: 0 -> (2, 2) / (2, 6); 1 -> x =
 * (FUN_a014837c(0) - 0xf0 / 0x150) / 24 (signed), y = 2 / 6; 2 -> (2, 0x35) / (2, 0x31); 3 -> x as for 1,
 * y = 0x35 / 0x31; other -> (D+0x1a5 * 3, D+0x1a6 * 2) / (D+0x1a7 * 3, D+0x1a8 * 2); x2 = (FUN_a014837c(0) -
 * 0x238) / 24.
 * on != 0: FUN_a00b5080(), FUN_a00b50d8(3), FUN_a00b52f8(n, 0x3d, 0x802), FUN_a014654c(0, 0, 0);
 * FUN_a00a5908(x2, 0x13, 1) when bit 22 of word D+0xac is set; when byte D+0x190 != 0 the fixed call sequence
 * FUN_a0146dc0(0, 1) .. FUN_a014654c(u16 D+0x1ac, u16 D+0x1ae, 1), one of FUN_a00a2b1c / 2b3c / 2b5c / 2b7c /
 * 2b9c / 2bbc by (D+0x190 - 1) % 6, rows FUN_a0146a80(0, i, 4, 0x1702 (D+0x17b == 1) or 0x1802 (== 0), 1) for
 * i < 3 (else FUN_a00ba184(1)), FUN_a0146b20(0, c, r, 1, r * 4 + c, 1) for r < 3, c < 4, FUN_a0146dc0(1, 1);
 * the FUN_a00b32e4 call groups at (x1, y1) when byte D+0x1a0 != 0 and at (x0, y0) when bit 12 of word D+0xa8 is
 * set. Then (any on): when D+0x1a0 != 0 and not (x1 + 0xb > x0, x0 + 8 > x1, y1 + 3 > y0, y0 + 3 > y1 and bit 12
 * of D+0xa8 set), for rows r < 3: FUN_a0146a80(x1 + 1, y1 + r, 10, 0xb80a, 0) and for c < 2 FUN_a0146b20 at
 * x1 + c + 1 / 3 / 5 / 7 / 9 with values (d * 3 + r) * 2 + c + 0x30 for the decimal digits d of bytes D+0x1a1
 * (tens, ones) and D+0x1a2 (tens, ones) and r * 2 + c + 0x6c at x1 + c + 5; when bit 12 of D+0xa8 is set, the
 * same for the hundreds, tens and ones of v = FUN_a00d8b38() at x0 + 1 / 3 / 5 (FUN_a0146a80 widths 2 and 4;
 * for v < 100 the hundreds use 0xbb0a and value r * 2 + c + 0x30); when bit 22 of D+0xac and bit 7 of D+0xa8 are
 * set and FUN_a00d8b38() != byte 0xA802B08C: FUN_a00b88e0(x2, 0x13) unless ((x0 >= e && x0 < e + 6) ||
 * (x0 + 8 >= e && x0 < e)) and y0 <= 0x1e <= y0 + 3 (e = (u16)(x2 + 8)), then 0xA802B08C = FUN_a00d8b38().
 * on != 0 ends with FUN_a0146dc0(1, 0).
 * Source form: the position selections set y before the inner tests and x = 2 in the 0 and 2 arms (if-conversion
 * moves those arms above their branches); the overlap test uses '&' between the two compares of its second term,
 * the 0x1e limit in an unsigned short local on the left of its second compare, and an empty then-branch; the
 * D+0x17b rows and the 3 x 4 cell loop pass the byte counters through static helpers with unsigned short
 * parameters (row17 / row18, cell(c, r, r, c) with the r * 4 + c sum from two byte parameters); the hundreds digit
 * arm 'v >= 100' is written first.
 */
struct R290 {
    unsigned char p000[0xd];
    unsigned char b00d, b00e;
    unsigned char p00f[0xa8 - 0xf];
    unsigned int wa8;
    unsigned int wac;
    unsigned char p0b0[0x13e - 0xb0];
    unsigned char b13e, b13f;
    unsigned char p140[0x17b - 0x140];
    unsigned char b17b;
    unsigned char p17c[0x190 - 0x17c];
    unsigned char b190;
    unsigned char p191[0x1a0 - 0x191];
    unsigned char b1a0, b1a1, b1a2;
    unsigned char p1a3[2];
    unsigned char b1a5, b1a6, b1a7, b1a8;
    unsigned char p1a9[3];
    unsigned short h1ac, h1ae;
};
extern struct R290 DAT_a802d290;
extern unsigned short DAT_a802cff4;
extern unsigned char DAT_a802b08c;
extern unsigned short FUN_a014837c(unsigned char p);
extern void FUN_a00b5080(void);
extern void FUN_a00b50d8(unsigned char mode);
extern int FUN_a00b52f8(int, int, int);
extern void FUN_a014654c(unsigned short, unsigned short, unsigned char);
extern void FUN_a00a5908(unsigned short x, unsigned short y, unsigned char mode);
extern void FUN_a0146dc0(unsigned char, unsigned char);
extern void FUN_a0146298(unsigned char n, unsigned char v);
extern void FUN_a0146354(unsigned char, unsigned char, unsigned char);
extern void FUN_a0146c40(unsigned char ch, unsigned char on, unsigned char blk);
extern void FUN_a0146648(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);
extern void FUN_a014613c(unsigned short, unsigned char, unsigned int);
extern void FUN_a0146518(unsigned short a, unsigned short b, unsigned char c);
extern void FUN_a0146ab0(unsigned short, unsigned char);
extern void FUN_a0146108(unsigned char);
extern void FUN_a00a2b1c(void);
extern void FUN_a00a2b3c(void);
extern void FUN_a00a2b5c(void);
extern void FUN_a00a2b7c(void);
extern void FUN_a00a2b9c(void);
extern void FUN_a00a2bbc(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00ba184(int force);
extern void FUN_a00b32e4(unsigned char dir, unsigned char inc, unsigned short c, unsigned short x, unsigned char y,
                         unsigned char n, unsigned char ch);
extern unsigned short FUN_a00d8b38(void);
extern void FUN_a00b88e0(unsigned short x, unsigned short y);

static void row17(unsigned short y)
{
    FUN_a0146a80(0, y, 4, 0x1702, 1);
}

static void row18(unsigned short y)
{
    FUN_a0146a80(0, y, 4, 0x1802, 1);
}

static void cell(unsigned short c, unsigned short r, unsigned char k, unsigned char j)
{
    FUN_a0146b20(0, c, r, 1, k * 4 + j, 1);
}

void FUN_a00a5e68(unsigned char on)
{
    unsigned short n, x0, x1, x2, v;
    unsigned char y0, y1, r, c, k;
    int t;

    n = FUN_a014837c(0) / 24 + 1;
    if (DAT_a802cff4 & 0x400)
        return;
    if (DAT_a802d290.b13e == 0) {
        x0 = 2;
        y0 = 2;
    } else {
        y0 = 2;
        if (DAT_a802d290.b13e == 1) {
            t = FUN_a014837c(0) - 0xf0;
            x0 = t / 24;
        } else if (DAT_a802d290.b13e == 2) {
            x0 = 2;
            y0 = 0x35;
        } else {
            y0 = 0x35;
            if (DAT_a802d290.b13e == 3) {
                t = FUN_a014837c(0) - 0xf0;
                x0 = t / 24;
            } else {
                x0 = DAT_a802d290.b1a5 * 3;
                y0 = DAT_a802d290.b1a6 * 2;
            }
        }
    }
    if (DAT_a802d290.b13f == 0) {
        x1 = 2;
        y1 = 6;
    } else {
        y1 = 6;
        if (DAT_a802d290.b13f == 1) {
            t = FUN_a014837c(0) - 0x150;
            x1 = t / 24;
        } else if (DAT_a802d290.b13f == 2) {
            x1 = 2;
            y1 = 0x31;
        } else {
            y1 = 0x31;
            if (DAT_a802d290.b13f == 3) {
                t = FUN_a014837c(0) - 0x150;
                x1 = t / 24;
            } else {
                x1 = DAT_a802d290.b1a7 * 3;
                y1 = DAT_a802d290.b1a8 * 2;
            }
        }
    }
    t = FUN_a014837c(0) - 0x238;
    x2 = t / 24;
    if (on) {
        FUN_a00b5080();
        FUN_a00b50d8(3);
        FUN_a00b52f8(n, 0x3d, 0x802);
        FUN_a014654c(0, 0, 0);
        if (DAT_a802d290.wac & 0x400000)
            FUN_a00a5908(x2, 0x13, 1);
        if (DAT_a802d290.b190 != 0) {
            FUN_a0146dc0(0, 1);
            FUN_a0146298(4, 1);
            FUN_a0146354(0x18, 0x24, 1);
            FUN_a0146c40(8, 0, 1);
            FUN_a0146648(0, 0, 0, 0, 1);
            FUN_a014613c(4, 3, 1);
            FUN_a0146518(DAT_a802d290.b00d, DAT_a802d290.b00e, 1);
            FUN_a0146ab0(0x792, 1);
            FUN_a0146108(1);
            FUN_a014654c(DAT_a802d290.h1ac, DAT_a802d290.h1ae, 1);
            t = (DAT_a802d290.b190 - 1) % 6;
            if (t == 0)
                FUN_a00a2b1c();
            else if (t == 1)
                FUN_a00a2b3c();
            else if (t == 2)
                FUN_a00a2b5c();
            else if (t == 3)
                FUN_a00a2b7c();
            else if (t == 4)
                FUN_a00a2b9c();
            else if (t == 5)
                FUN_a00a2bbc();
            if (DAT_a802d290.b17b == 1) {
                for (r = 0; r < 3; r++)
                    row17(r);
            } else if (DAT_a802d290.b17b == 0) {
                for (r = 0; r < 3; r++)
                    row18(r);
            } else
                FUN_a00ba184(1);
            for (r = 0; r < 3; r++)
                for (c = 0; c < 4; c++)
                    cell(c, r, r, c);
            FUN_a0146dc0(1, 1);
        }
        if (DAT_a802d290.b1a0 != 0) {
            for (k = 0; k < 3; k++)
                FUN_a00b32e4(1, 0, 0x792, x1, y1 + k, 0xc, 0);
            for (k = 0; k < 2; k++) {
                FUN_a00b32e4(0, 0, 0xb80a, x1, y1 + k * 2, 1, k * 2 + 7);
                FUN_a00b32e4(1, 0, 0xb80a, x1 + 1, y1 + k * 2, 10, k + 0xb);
                FUN_a00b32e4(0, 0, 0xb80a, x1 + 0xb, y1 + k * 2, 1, k * 2 + 8);
            }
            FUN_a00b32e4(0, 0, 0x8a2, x1, y1 + 1, 1, 7);
            FUN_a00b32e4(0, 0, 0x8a2, x1 + 0xb, y1 + 1, 1, 8);
        }
        if (DAT_a802d290.wa8 & 0x1000) {
            for (k = 0; k < 2; k++) {
                FUN_a00b32e4(0, 0, 0xb80a, x0, y0 + k * 2, 1, k * 2 + 7);
                FUN_a00b32e4(0, 0, 0xb80a, x0 + 7, y0 + k * 2, 1, k * 2 + 8);
            }
            FUN_a00b32e4(0, 0, 0x8a2, x0, y0 + 1, 1, 7);
            FUN_a00b32e4(0, 0, 0x8a2, x0 + 7, y0 + 1, 1, 8);
        }
    }
    if (DAT_a802d290.b1a0 != 0) {
        if (!(x1 + 0xb > x0 && x0 + 8 > x1 && y1 + 3 > y0 && y0 + 3 > y1 && (DAT_a802d290.wa8 & 0x1000))) {
            for (r = 0; r < 3; r++) {
                FUN_a0146a80(x1 + 1, y1 + r, 10, 0xb80a, 0);
                for (c = 0; c < 2; c++) {
                    FUN_a0146b20(0, x1 + c + 1, y1 + r, 1, ((DAT_a802d290.b1a1 / 10) * 3 + r) * 2 + c + 0x30, 0);
                    FUN_a0146b20(0, x1 + c + 3, y1 + r, 1, ((DAT_a802d290.b1a1 % 10) * 3 + r) * 2 + c + 0x30, 0);
                    FUN_a0146b20(0, x1 + c + 5, y1 + r, 1, r * 2 + c + 0x6c, 0);
                    FUN_a0146b20(0, x1 + c + 7, y1 + r, 1, ((DAT_a802d290.b1a2 / 10) * 3 + r) * 2 + c + 0x30, 0);
                    FUN_a0146b20(0, x1 + c + 9, y1 + r, 1, ((DAT_a802d290.b1a2 % 10) * 3 + r) * 2 + c + 0x30, 0);
                }
            }
        }
    }
    if (DAT_a802d290.wa8 & 0x1000) {
        unsigned char h, d, o;

        v = FUN_a00d8b38();
        h = v / 100;
        d = (v % 100) / 10;
        o = v % 10;
        if (v >= 100) {
            for (r = 0; r < 3; r++) {
                FUN_a0146a80(x0 + 1, y0 + r, 2, 0xb80a, 0);
                for (c = 0; c < 2; c++)
                    FUN_a0146b20(0, x0 + c + 1, y0 + r, 1, (h * 3 + r) * 2 + c + 0x30, 0);
            }
        } else {
            for (r = 0; r < 3; r++) {
                FUN_a0146a80(x0 + 1, y0 + r, 2, 0xbb0a, 0);
                for (c = 0; c < 2; c++)
                    FUN_a0146b20(0, x0 + c + 1, y0 + r, 1, r * 2 + c + 0x30, 0);
            }
        }
        for (r = 0; r < 3; r++) {
            FUN_a0146a80(x0 + 3, y0 + r, 4, 0xb80a, 0);
            for (c = 0; c < 2; c++) {
                FUN_a0146b20(0, x0 + c + 3, y0 + r, 1, (d * 3 + r) * 2 + c + 0x30, 0);
                FUN_a0146b20(0, x0 + c + 5, y0 + r, 1, (o * 3 + r) * 2 + c + 0x30, 0);
            }
        }
    }
    if ((DAT_a802d290.wac & 0x400000) && (DAT_a802d290.wa8 & 0x80) && FUN_a00d8b38() != DAT_a802b08c) {
        unsigned short e = x2 + 8;
        unsigned short yy = 0x1e;

        if (((x0 >= e && x0 < e + 6) || ((x0 + 8 >= e) & (x0 < e))) && y0 <= yy && yy <= y0 + 3)
            ;
        else
            FUN_a00b88e0(x2, 0x13);
        DAT_a802b08c = FUN_a00d8b38();
    }
    if (on)
        FUN_a0146dc0(1, 0);
}

