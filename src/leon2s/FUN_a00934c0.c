/* FUN_a00934c0 (leon2s 0xa00934c0-0xa0094308, 3656 bytes), flags -mcpu=v8 -Os -g.
 * port (0 or 1, other values return 0) and mode; returns 1. Register writes go through FUN_a00a8054(port, 0, reg,
 * byte) and FUN_a00a80cc(port, 0, reg, mask, value); sel is 1 for modes 6, 10 and 14, else 0.
 * First part by mode: 8/10/12/14 store FUN_a00a657c (8, 10) or FUN_a00a69b4 (12, 14) in the reader pointer
 * _DAT_a807d5b8, then write 0x9b to 0x124 and 6 / 0x80 to 0x12f / 0x11d when bit 1 of reader(sel, 0x12a) is set
 * and reader(sel, 0x280) == 9, else 0x2b, 4 and 2; then FUN_a00931fc(sel, port). 4/6: the same 0x2b, 4, 2 writes
 * when bits 2..4 of FUN_a00a6bb8(sel, 0x51) are all set, else 0x2b and 6; then FUN_a009332c(sel, port). Other
 * modes: FUN_a0093164(port), 0x2b and 6.
 * Second part: 8/10/12/14 set the reader again (index 0..3), write 0x101, and read two 24-bit values v (regs
 * 0x103..0x105 or 0x106..0x108 by bit 3 of reader 0x100) and w (0x109..0x10b or 0x10c..0x10e by bit 4, at least
 * 0x7d). Modes 12/14 with FUN_a00a29b0(sel) == 1: t = (v >> 7) * DAT_a00b407c[min(FUN_a00735e8(index), 6)] /
 * (w / 125) * 8, n = the first of the 18 entries of DAT_a00b408a within 8 of t, and v = one of the 6-word rows
 * of DAT_a00b40b0 (n / 6 other than 1 or 2), DAT_a00b4110 (1) or DAT_a00b4140 (2), row chosen by
 * FUN_a009193c(port) (2..4, 5, 6, else; for DAT_a00b4110 4..6 or else), column n % 6. Otherwise t from
 * FUN_a0090fb4(sel) * 10 (modes 8, 10) or FUN_a00a20c4(sel) the same way, and v = 0x1000 .. 0xc000 when t lies in
 * one of twelve 17-wide windows. v is written to 0x105, 0x104, 0x103. 4/6 write 0x101, read two 24-bit pairs
 * from regs 0x82..0x87 with bit 5 of reg 0x81 clear and set (restored afterwards), return 1 when a divisor is 0,
 * scale them by bits 0..1 of reg 0x80, pick row k / 6 (quotient f in 436..446: 0, 475..485: 2, else 1) and
 * column k % 6 (five limits on the second quotient) and write the words DAT_a00b41a0[k] and DAT_a00b41e8[k] to 0x103..0x105 and 0x106..0x108. Other modes write 0x101 and
 * 0, 0x18, 0 to 0x103..0x105.
 * Source form: old-style parameter declarations; both mode dispatches are switches with grouped cases; the
 * row selections are switches with the default case first; each scaling arm computes both quotients itself;
 * the 24-bit values of the 4/6 path are built in three statements.
 */
typedef unsigned char (*RdFn)(unsigned char, unsigned short);

extern RdFn _DAT_a807d5b8;
extern const unsigned short DAT_a00b407c[];
extern const unsigned short DAT_a00b408a[];
extern const unsigned int DAT_a00b40b0[4][6];
extern const unsigned int DAT_a00b4110[2][6];
extern const unsigned int DAT_a00b4140[4][6];
extern const unsigned int DAT_a00b41a0[];
extern const unsigned int DAT_a00b41e8[];
extern unsigned char FUN_a00a657c(unsigned char, unsigned short);
extern unsigned char FUN_a00a69b4(unsigned char, unsigned short);
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00931fc(unsigned int, unsigned char);
extern void FUN_a009332c(unsigned int, unsigned char);
extern void FUN_a0093164(unsigned char);
extern unsigned char FUN_a00a29b0(unsigned char);
extern unsigned char FUN_a00735e8(unsigned char);
extern unsigned char FUN_a009193c(unsigned char);
extern unsigned short FUN_a0090fb4(unsigned char);
extern unsigned short FUN_a00a20c4(unsigned char);
extern int abs(int);

unsigned int FUN_a00934c0(port, mode)
    unsigned char port, mode;
{
    unsigned char sel = 0;
    unsigned char idx = 0;
    unsigned char k, n, i, j, b;
    unsigned short t;
    unsigned int v, w, n1, d1, n2, d2, f;
    int g;

    if (port > 1)
        return 0;
    switch (mode) {
    case 8:
    case 10:
    case 12:
    case 14:
        if (mode == 8)
            _DAT_a807d5b8 = FUN_a00a657c;
        else if (mode == 10) {
            _DAT_a807d5b8 = FUN_a00a657c;
            sel = 1;
        } else if (mode == 12)
            _DAT_a807d5b8 = FUN_a00a69b4;
        else if (mode == 14) {
            _DAT_a807d5b8 = FUN_a00a69b4;
            sel = 1;
        }
        if ((_DAT_a807d5b8(sel, 0x12a) & 2) && _DAT_a807d5b8(sel, 0x280) == 9) {
            FUN_a00a8054(port, 0, 0x124, 0x9b);
            FUN_a00a80cc(port, 0, 0x12f, 6, 0);
            FUN_a00a80cc(port, 0, 0x11d, 0x80, 1);
        } else {
            FUN_a00a8054(port, 0, 0x124, 0x2b);
            FUN_a00a80cc(port, 0, 0x12f, 4, 0);
            FUN_a00a80cc(port, 0, 0x12f, 2, 0);
        }
        FUN_a00931fc(sel, port);
        break;
    case 4:
    case 6:
        if (mode == 4)
            sel = 0;
        else if (mode == 6)
            sel = 1;
        if ((FUN_a00a6bb8(sel, 0x51) & 0x1c) == 0x1c) {
            FUN_a00a8054(port, 0, 0x124, 0x2b);
            FUN_a00a80cc(port, 0, 0x12f, 4, 0);
            FUN_a00a80cc(port, 0, 0x12f, 2, 0);
        } else {
            FUN_a00a8054(port, 0, 0x124, 0x2b);
            FUN_a00a80cc(port, 0, 0x12f, 6, 0);
        }
        FUN_a009332c(sel, port);
        break;
    default:
        FUN_a0093164(port);
        FUN_a00a8054(port, 0, 0x124, 0x2b);
        FUN_a00a80cc(port, 0, 0x12f, 6, 0);
        break;
    }
    switch (mode) {
    case 8:
    case 10:
    case 12:
    case 14:
        if (mode == 8) {
            _DAT_a807d5b8 = FUN_a00a657c;
            sel = 0;
            idx = 0;
        } else if (mode == 10) {
            _DAT_a807d5b8 = FUN_a00a657c;
            sel = 1;
            idx = 1;
        } else if (mode == 12) {
            _DAT_a807d5b8 = FUN_a00a69b4;
            sel = 0;
            idx = 2;
        } else if (mode == 14) {
            _DAT_a807d5b8 = FUN_a00a69b4;
            sel = 1;
            idx = 3;
        }
        FUN_a00a80cc(port, 0, 0x101, 2, 1);
        if (_DAT_a807d5b8(sel, 0x100) & 8)
            v = (_DAT_a807d5b8(sel, 0x105) << 16) + (_DAT_a807d5b8(sel, 0x104) << 8) + _DAT_a807d5b8(sel, 0x103);
        else
            v = (_DAT_a807d5b8(sel, 0x108) << 16) + (_DAT_a807d5b8(sel, 0x107) << 8) + _DAT_a807d5b8(sel, 0x106);
        if (_DAT_a807d5b8(sel, 0x100) & 0x10)
            w = (_DAT_a807d5b8(sel, 0x10b) << 16) + (_DAT_a807d5b8(sel, 0x10a) << 8) + _DAT_a807d5b8(sel, 0x109);
        else
            w = (_DAT_a807d5b8(sel, 0x10e) << 16) + (_DAT_a807d5b8(sel, 0x10d) << 8) + _DAT_a807d5b8(sel, 0x10c);
        if (w < 0x7d)
            w = 0x7d;
        if ((mode == 12 || mode == 14) && FUN_a00a29b0(sel) == 1) {
            k = FUN_a00735e8(idx & 3);
            if (k > 6)
                k = 6;
            t = (v >> 7) * DAT_a00b407c[k] / (w / 125) << 3;
            for (n = 0; n < 0x12; n++)
                if (abs(t - DAT_a00b408a[n]) <= 8)
                    break;
            switch (n / 6) {
            default:
                    switch (FUN_a009193c(port)) {
                    default:
                        v = DAT_a00b40b0[0][n % 6];
                        break;
                    case 2:
                    case 3:
                    case 4:
                        v = DAT_a00b40b0[1][n % 6];
                        break;
                    case 5:
                        v = DAT_a00b40b0[2][n % 6];
                        break;
                    case 6:
                        v = DAT_a00b40b0[3][n % 6];
                        break;
                    }
                break;
            case 1:
                    switch (FUN_a009193c(port)) {
                    default:
                        v = DAT_a00b4110[0][n % 6];
                        break;
                    case 4:
                    case 5:
                    case 6:
                        v = DAT_a00b4110[1][n % 6];
                        break;
                    }
                break;
            case 2:
                    switch (FUN_a009193c(port)) {
                    default:
                        v = DAT_a00b4140[0][n % 6];
                        break;
                    case 2:
                    case 3:
                    case 4:
                        v = DAT_a00b4140[1][n % 6];
                        break;
                    case 5:
                        v = DAT_a00b4140[2][n % 6];
                        break;
                    case 6:
                        v = DAT_a00b4140[3][n % 6];
                        break;
                    }
                break;
            }
        } else {
            if (mode == 8 || mode == 10)
                t = (v >> 7) * FUN_a0090fb4(sel) * 10 / (w / 125) << 3;
            else
                t = (v >> 7) * FUN_a00a20c4(sel) / (w / 125) << 3;
            if (t >= 312 && t <= 328)
                v = 0x1000;
            else if (t >= 632 && t <= 648)
                v = 0x2000;
            else if (t >= 1272 && t <= 1288)
                v = 0x4000;
            else if (t >= 2552 && t <= 2568)
                v = 0x8000;
            else if (t >= 433 && t <= 449)
                v = 0x1880;
            else if (t >= 874 && t <= 890)
                v = 0x3100;
            else if (t >= 1756 && t <= 1772)
                v = 0x6200;
            else if (t >= 3520 && t <= 3536)
                v = 0xc400;
            else if (t >= 472 && t <= 488)
                v = 0x1800;
            else if (t >= 952 && t <= 968)
                v = 0x3000;
            else if (t >= 1912 && t <= 1928)
                v = 0x6000;
            else if (t >= 3832 && t <= 3848)
                v = 0xc000;
        }
        FUN_a00a8054(port, 0, 0x105, (v >> 16) & 0xff);
        FUN_a00a8054(port, 0, 0x104, (v >> 8) & 0xff);
        FUN_a00a8054(port, 0, 0x103, v & 0xff);
        break;
    case 4:
    case 6:
        if (mode == 4)
            sel = 0;
        else if (mode == 6)
            sel = 1;
        FUN_a00a80cc(port, 0, 0x101, 2, 1);
        b = FUN_a00a6bb8(sel, 0x81);
        FUN_a00a6c00(sel, 0x81, b & 0xdf);
        n1 = FUN_a00a6bb8(sel, 0x82);
        n1 = n1 << 8 | FUN_a00a6bb8(sel, 0x83);
        n1 = n1 << 8 | FUN_a00a6bb8(sel, 0x84);
        d1 = FUN_a00a6bb8(sel, 0x85);
        d1 = d1 << 8 | FUN_a00a6bb8(sel, 0x86);
        d1 = d1 << 8 | FUN_a00a6bb8(sel, 0x87);
        FUN_a00a6c00(sel, 0x81, b | 0x20);
        n2 = FUN_a00a6bb8(sel, 0x82);
        n2 = n2 << 8 | FUN_a00a6bb8(sel, 0x83);
        n2 = n2 << 8 | FUN_a00a6bb8(sel, 0x84);
        d2 = FUN_a00a6bb8(sel, 0x85);
        d2 = d2 << 8 | FUN_a00a6bb8(sel, 0x86);
        d2 = d2 << 8 | FUN_a00a6bb8(sel, 0x87);
        if (d1 == 0 || d2 == 0)
            return 1;
        if ((FUN_a00a6bb8(sel, 0x80) & 3) == 0) {
            f = (n2 * 0x18b820 >> 9) / d2;
            g = n1 * 0x654 / d1 * 2;
        } else if ((FUN_a00a6bb8(sel, 0x80) & 3) == 1) {
            f = (n2 * 2700000 >> 9) / d2;
            g = n1 * 0xa8c / d1 * 2;
        } else {
            f = (n2 * 5400000 >> 9) / d2;
            g = n1 * 0x1518 / d1 * 2;
        }
        FUN_a00a6c00(sel, 0x81, b);
        if (f >= 436 && f <= 446)
            i = 0;
        else if (f >= 475 && f <= 485)
            i = 2;
        else
            i = 1;
        if (g <= 0x104)
            j = 0;
        else if (g <= 0x195)
            j = 1;
        else if (g <= 0x280)
            j = 2;
        else if (g <= 0x456)
            j = 3;
        else if (g <= 0x8b1)
            j = 4;
        else
            j = 5;
        FUN_a00a8054(port, 0, 0x103, DAT_a00b41a0[i * 6 + j] & 0xff);
        FUN_a00a8054(port, 0, 0x104, (DAT_a00b41a0[i * 6 + j] >> 8) & 0xff);
        FUN_a00a8054(port, 0, 0x105, (DAT_a00b41a0[i * 6 + j] >> 16) & 0xff);
        FUN_a00a8054(port, 0, 0x106, DAT_a00b41e8[i * 6 + j] & 0xff);
        FUN_a00a8054(port, 0, 0x107, (DAT_a00b41e8[i * 6 + j] >> 8) & 0xff);
        FUN_a00a8054(port, 0, 0x108, (DAT_a00b41e8[i * 6 + j] >> 16) & 0xff);
        break;
    default:
        FUN_a00a80cc(port, 0, 0x101, 2, 1);
        FUN_a00a8054(port, 0, 0x103, 0);
        FUN_a00a8054(port, 0, 0x104, 0x18);
        FUN_a00a8054(port, 0, 0x105, 0);
        break;
    }
    return 1;
}
