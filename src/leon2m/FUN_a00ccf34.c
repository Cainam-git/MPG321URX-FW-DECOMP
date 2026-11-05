/* leon2m FUN_a00ccf34 @ 0xa00ccf34-0xa00ce348 (1285 words), flags -mcpu=v8 -O3 -g.
 * unsigned char FUN_a00ccf34(port, cmd): FUN_a00df170(s_001982e0, cmd, port), then a switch on cmd (jump table at
 * 0x0005a654 for 0..0x99; larger values give 0). Most commands return the result of one handler call
 * FUN_a00c....(port) or 0. Thirty handlers are inlined here; they are written as the static functions cmdNN (their
 * standalone copies: 15 FUN_a00c93e0, 16 FUN_a00c9470, 22 FUN_a00c0ff4, 28 FUN_a00cce80, 30 FUN_a00ccef4,
 * 48 FUN_a00c0d10, 51 FUN_a00c0c74, 55 FUN_a00c3ec8, 56 FUN_a00c3e3c, 64 FUN_a00c17e8, 65 FUN_a00c1704,
 * 66 FUN_a00c16b0, 67 FUN_a00c165c, 68 FUN_a00c1608, 70 FUN_a00c9500, 72 FUN_a00cbe2c, 74 FUN_a00cbe64,
 * 76 FUN_a00c135c, 77 FUN_a00c12b4, 81 FUN_a00c1188, 106 FUN_a00c1100, 107 FUN_a00c122c, 114 FUN_a00c9df4,
 * 115 FUN_a00ca380, 118 FUN_a00cae64, 119 FUN_a00cadd4, 120 FUN_a00cab68, 129 FUN_a00cb3a8, 135 FUN_a00c1078,
 * 136 FUN_a00c9e9c). Most of them read byte +9 of the port record (DAT_a802d040 / DAT_a802d098 / DAT_a802d0d0 for
 * port 2 / 3 / other) through rd9() or the three digits +7..+9 through parse3() (a copy of FUN_a00bae38), return
 * 0xff for an out-of-range digit, store the value into a field of DAT_a802d290 or a byte global and end with
 * FUN_a00baa6c(port), FUN_a00ba950(port), FUN_a00bab80(port, 6), returning 0.
 * After the switch: when cmd != 0x8c, the result is 0 and FUN_a0090fcc() is neither 0x106 nor 0x109 (one call per
 * test), FUN_a0090fd8() is called. The result is returned as unsigned char.
 * Caller: FUN_a00ce348.
 * Source form: the inlined handlers as static functions with early returns; the order of the inlined-handler case
 * bodies in the switch decides the register names of the inlined code; in cmd81 +0x1ac is written before +0x1ae.
 */
struct D290 {
    unsigned char p000[8];
    unsigned char b008;                 /* 0xa802d298 */
    unsigned char p009[3];
    unsigned char b00c;                 /* 0xa802d29c */
    unsigned char p00d[0x1f - 0xd];
    unsigned char b01f;                 /* 0xa802d2af */
    unsigned char p020[0x4b - 0x20];
    unsigned char b04b, b04c;           /* 0xa802d2db */
    unsigned char p04d[0xa8 - 0x4d];
    union { unsigned int w; struct { unsigned int : 16, b15 : 1, : 2, b12 : 1, : 5, b6 : 1, : 6; } f; } w0a8;
    union { unsigned int w; struct { unsigned int : 9, b22 : 1, : 22; } f; } w0ac;
    unsigned char p0b0[0x174 - 0xb0];
    union { unsigned int w; unsigned char b[4]; struct { unsigned int : 16, b15 : 1, : 15; } f; } w174;
    unsigned char p178[0x17c - 0x178];
    unsigned char b17c;                 /* 0xa802d40c */
    unsigned char p17d[0x18a - 0x17d];
    unsigned char b18a, b18b, b18c, b18d;   /* 0xa802d41a */
    unsigned char p18e[0x1ac - 0x18e];
    unsigned short h1ac, h1ae;          /* 0xa802d43c */
    unsigned char p1b0[0x1dc - 0x1b0];
    union { unsigned int w; unsigned char b[4]; struct { unsigned int : 16, b15 : 1, : 15; } f; } u1dc;
    unsigned char b1e0, b1e1;           /* 0xa802d470 */
    unsigned char p1e2[0x1e8 - 0x1e2];
    unsigned char b1e8;                 /* 0xa802d478 */
    unsigned char p1e9[0x1ec - 0x1e9];
    union { unsigned int w; unsigned char b[4]; struct { unsigned int : 24, b7 : 1, : 7; } f; } u1ec;
};
extern struct D290 DAT_a802d290;
extern unsigned char DAT_a802cffd, DAT_a802d298;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern const char s_001982e0[];
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a0090fd8(void);
extern void FUN_a00b88cc(void);
extern void FUN_a00baa6c(unsigned char port);
extern void FUN_a00ba950(unsigned char port);
extern void FUN_a00bab80(unsigned char port, unsigned char len);
extern void FUN_a00d934c(void);
extern void FUN_a00d93c8(void);
extern void FUN_a00d4888(void);
extern void FUN_a00dc3dc(void);
extern void FUN_a00d5eac(unsigned char flag);
extern void FUN_a00d9978(void);
extern void FUN_a014b4b4(int, int);
extern void FUN_a00db12c(unsigned char);
extern void FUN_a00dab08(void);
extern void FUN_a00dab20(void);
extern void FUN_a00dac00(void);
extern void FUN_a00db690(void);
extern int FUN_a00c0de0(unsigned char port);
extern int FUN_a00c1400(unsigned char port);
extern int FUN_a00c18cc(unsigned char port);
extern int FUN_a00c1adc(unsigned char port);
extern int FUN_a00c1d54(unsigned char port);
extern int FUN_a00c2180(unsigned char port);
extern int FUN_a00c25ac(unsigned char port);
extern int FUN_a00c29d8(unsigned char port);
extern int FUN_a00c2bd8(unsigned char port);
extern int FUN_a00c2f08(unsigned char port);
extern int FUN_a00c3180(unsigned char port);
extern int FUN_a00c3380(unsigned char port);
extern int FUN_a00c35d0(unsigned char port);
extern int FUN_a00c3820(unsigned char port);
extern int FUN_a00c3a30(unsigned char port);
extern int FUN_a00c3c14(unsigned char port);
extern int FUN_a00c3f54(unsigned char port);
extern int FUN_a00c4144(unsigned char port);
extern int FUN_a00c4430(unsigned char port);
extern int FUN_a00c46d4(unsigned char port);
extern int FUN_a00c49b8(unsigned char port);
extern int FUN_a00c4ec4(unsigned char port);
extern int FUN_a00c5478(unsigned char port);
extern int FUN_a00c573c(unsigned char port);
extern int FUN_a00c5a00(unsigned char port);
extern int FUN_a00c5c18(unsigned char port);
extern int FUN_a00c5e40(unsigned char port);
extern int FUN_a00c604c(unsigned char port);
extern int FUN_a00c6228(unsigned char port);
extern int FUN_a00c6424(unsigned char port);
extern int FUN_a00c6690(unsigned char port);
extern int FUN_a00c68d8(unsigned char port);
extern int FUN_a00c762c(unsigned char port);
extern int FUN_a00c7818(unsigned char port);
extern int FUN_a00c7a5c(unsigned char port);
extern int FUN_a00c7e3c(unsigned char port);
extern int FUN_a00c8410(unsigned char port);
extern int FUN_a00c8614(unsigned char port);
extern int FUN_a00c8818(unsigned char port);
extern int FUN_a00c8a44(unsigned char port);
extern int FUN_a00c8c38(unsigned char port);
extern int FUN_a00c91dc(unsigned char port);
extern int FUN_a00c95a4(unsigned char port);
extern int FUN_a00c9788(unsigned char port);
extern int FUN_a00c9980(unsigned char port);
extern int FUN_a00c9be0(unsigned char port);
extern int FUN_a00c9f44(unsigned char port);
extern int FUN_a00ca158(unsigned char port);
extern int FUN_a00ca410(unsigned char port);
extern int FUN_a00ca644(unsigned char port);
extern int FUN_a00ca878(unsigned char port);
extern int FUN_a00cabf8(unsigned char port);
extern int FUN_a00caf0c(unsigned char port);
extern int FUN_a00cb1c8(unsigned char port);
extern int FUN_a00cb438(unsigned char port);
extern int FUN_a00cb618(unsigned char port);
extern int FUN_a00cb7f4(unsigned char port);
extern int FUN_a00cb9d4(unsigned char port);
extern int FUN_a00cbbb0(unsigned char port);
extern int FUN_a00cbe9c(unsigned char port);
extern int FUN_a00cc140(unsigned char port);
extern int FUN_a00cc760(unsigned char port);
extern int FUN_a00cc9c0(unsigned char port);
extern int FUN_a00ccc20(unsigned char port);

extern unsigned char FUN_a00bae38(unsigned char port);

static unsigned char parse3(unsigned char port)
{
    unsigned char h, t, o;
    unsigned short r;

    if (port == 2) {
        h = DAT_a802d040[7];
        t = DAT_a802d040[8];
        o = DAT_a802d040[9];
    } else if (port == 3) {
        h = DAT_a802d098[7];
        t = DAT_a802d098[8];
        o = DAT_a802d098[9];
    } else {
        h = DAT_a802d0d0[7];
        t = DAT_a802d0d0[8];
        o = DAT_a802d0d0[9];
    }
    if (h < '0' || h > '1')
        return 0xff;
    if (t < '0' || t > '9')
        return 0xff;
    if (o < '0' || o > '9')
        return 0xff;
    h -= '0';
    t -= '0';
    o -= '0';
    r = h * 100 + t * 10 + o;
    return r;
}

static unsigned char rd9(unsigned char port)
{
    unsigned char c;

    if (port == 2)
        c = DAT_a802d040[9];
    else if (port == 3)
        c = DAT_a802d098[9];
    else
        c = DAT_a802d0d0[9];
    return c;
}

static int cmd15(unsigned char port)
{
    if (rd9(port) != '1')
        return 0xff;
    if (DAT_a802d290.b01f == 0)
        return 0xff;
    FUN_a00d934c();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd16(unsigned char port)
{
    if (rd9(port) != '1')
        return 0xff;
    if (DAT_a802d290.b01f == 0)
        return 0xff;
    FUN_a00d93c8();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd22(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd28(unsigned char port)
{
    DAT_a802d298 = rd9(port) - '0';
    FUN_a00d4888();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd30(unsigned char port)
{
    FUN_a0090fd8();
    FUN_a00dc3dc();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd48(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.w0a8.f.b12 = v;
    FUN_a0090fd8();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd51(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 4)
        return 0xff;
    DAT_a802cffd = v;
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd55(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 2)
        return 0xff;
    DAT_a802d290.b04b = v;
    FUN_a00d5eac(1);
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd56(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 2)
        return 0xff;
    DAT_a802d290.b04c = v;
    FUN_a00d5eac(1);
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd64(unsigned char port)
{
    unsigned char v = parse3(port);

    if (v > 0x1e)
        return 0xff;
    DAT_a802d290.b00c = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd65(unsigned char port)
{
    unsigned char v = parse3(port);

    if (v > 0xb)
        return 0xff;
    DAT_a802d290.b18a = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd66(unsigned char port)
{
    unsigned char v = FUN_a00bae38(port);

    if (v > 0xb)
        return 0xff;
    DAT_a802d290.b18b = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd67(unsigned char port)
{
    unsigned char v = FUN_a00bae38(port);

    if (v > 0xb)
        return 0xff;
    DAT_a802d290.b18c = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd68(unsigned char port)
{
    unsigned char v = FUN_a00bae38(port);

    if (v > 0xb)
        return 0xff;
    DAT_a802d290.b18d = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd70(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.w0a8.f.b6 = v;
    FUN_a00d9978();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd72(unsigned char port)
{
    FUN_a014b4b4(0xfe, 1);
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd74(unsigned char port)
{
    FUN_a014b4b4(0xfe, 1);
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd76(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.w0a8.f.b15 = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd77(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.w0ac.f.b22 = v;
    FUN_a0090fd8();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd81(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    if (v == 1) {
        DAT_a802d290.h1ac = 0x750;
        DAT_a802d290.h1ae = 0x402;
    }
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd106(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 2)
        return 0xff;
    DAT_a802d290.b17c = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd107(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.w174.b[3] = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd114(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.u1ec.f.b7 = v;
    FUN_a00db12c(0);
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd115(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 2)
        return 0xff;
    DAT_a802d290.u1dc.b[1] = v;
    FUN_a00dab08();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd118(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.u1dc.f.b15 = v;
    FUN_a00dab20();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd119(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.b1e0 = v;
    FUN_a00dab20();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd120(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.b1e1 = v;
    FUN_a00dab20();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd129(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.b1e8 = v;
    FUN_a00dac00();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd135(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.u1ec.b[2] = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

static int cmd136(unsigned char port)
{
    unsigned char v = rd9(port) - '0';

    if (v > 1)
        return 0xff;
    DAT_a802d290.w174.f.b15 = v;
    FUN_a00db690();
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}

unsigned char FUN_a00ccf34(unsigned char port, unsigned char cmd)
{
    int r;
    unsigned char ret;

    FUN_a00df170(s_001982e0, cmd, port);
    r = 0;
    switch (cmd) {
    case 0:
        r = FUN_a00c0de0(port);
        break;
    case 1:
        r = FUN_a00c18cc(port);
        break;
    case 2:
        r = 0;
        break;
    case 3:
        r = FUN_a00c6424(port);
        break;
    case 4:
        r = FUN_a00c6690(port);
        break;
    case 5:
        r = FUN_a00c762c(port);
        break;
    case 6:
        r = 0;
        break;
    case 7:
        r = 0;
        break;
    case 8:
        r = FUN_a00c7a5c(port);
        break;
    case 9:
        r = FUN_a00c8818(port);
        break;
    case 10:
        r = FUN_a00c8614(port);
        break;
    case 11:
        r = FUN_a00c1400(port);
        break;
    case 15:
        r = cmd15(port);
        break;
    case 12:
        r = FUN_a00c8410(port);
        break;
    case 13:
        r = FUN_a00c8a44(port);
        break;
    case 14:
        r = FUN_a00c91dc(port);
        break;
    case 74:
        r = cmd74(port);
        break;
    case 17:
        r = FUN_a00c5a00(port);
        break;
    case 18:
        r = FUN_a00cc760(port);
        break;
    case 19:
        r = FUN_a00cc9c0(port);
        break;
    case 20:
        r = FUN_a00ccc20(port);
        break;
    case 16:
        r = cmd16(port);
        break;
    case 21:
        r = FUN_a00c573c(port);
        break;
    case 23:
        r = 0;
        break;
    case 24:
        r = 0;
        break;
    case 25:
        r = 0;
        break;
    case 26:
        r = 0;
        break;
    case 27:
        r = 0;
        break;
    case 29:
        r = 0;
        break;
    case 31:
        r = 0;
        break;
    case 32:
        r = 0;
        break;
    case 22:
        r = cmd22(port);
        break;
    case 33:
        r = 0;
        break;
    case 34:
        r = 0;
        break;
    case 35:
        r = 0;
        break;
    case 28:
        r = cmd28(port);
        break;
    case 36:
        r = 0;
        break;
    case 38:
        r = 0;
        break;
    case 39:
        r = 0;
        break;
    case 40:
        r = 0;
        break;
    case 41:
        r = FUN_a00c35d0(port);
        break;
    case 48:
        r = cmd48(port);
        break;
    case 51:
        r = cmd51(port);
        break;
    case 55:
        r = cmd55(port);
        break;
    case 42:
        r = FUN_a00c3380(port);
        break;
    case 43:
        r = FUN_a00c1adc(port);
        break;
    case 44:
        r = FUN_a00c3820(port);
        break;
    case 45:
        r = FUN_a00c3a30(port);
        break;
    case 46:
        r = FUN_a00c3c14(port);
        break;
    case 47:
        r = FUN_a00c4144(port);
        break;
    case 49:
        r = FUN_a00c3180(port);
        break;
    case 50:
        r = FUN_a00c2f08(port);
        break;
    case 52:
        r = FUN_a00c2bd8(port);
        break;
    case 56:
        r = cmd56(port);
        break;
    case 53:
        r = FUN_a00c29d8(port);
        break;
    case 54:
        r = FUN_a00c46d4(port);
        break;
    case 57:
        r = FUN_a00c4430(port);
        break;
    case 72:
        r = cmd72(port);
        break;
    case 58:
        r = 0;
        break;
    case 64:
        r = cmd64(port);
        break;
    case 59:
        r = FUN_a00c4ec4(port);
        break;
    case 60:
        r = FUN_a00c5478(port);
        break;
    case 65:
        r = cmd65(port);
        break;
    case 61:
        r = FUN_a00c5c18(port);
        break;
    case 62:
        r = FUN_a00c5e40(port);
        break;
    case 63:
        r = FUN_a00c604c(port);
        break;
    case 66:
        r = cmd66(port);
        break;
    case 67:
        r = cmd67(port);
        break;
    case 69:
        r = FUN_a00c6228(port);
        break;
    case 71:
        r = FUN_a00c95a4(port);
        break;
    case 73:
        r = 0;
        break;
    case 80:
        r = FUN_a00c7818(port);
        break;
    case 91:
        r = FUN_a00c9788(port);
        break;
    case 68:
        r = cmd68(port);
        break;
    case 70:
        r = cmd70(port);
        break;
    case 109:
        r = FUN_a00c3f54(port);
        break;
    case 113:
        r = FUN_a00c9be0(port);
        break;
    case 116:
        r = FUN_a00ca644(port);
        break;
    case 117:
        r = FUN_a00ca410(port);
        break;
    case 121:
        r = FUN_a00cabf8(port);
        break;
    case 122:
        r = FUN_a00caf0c(port);
        break;
    case 127:
        r = FUN_a00cbbb0(port);
        break;
    case 76:
        r = cmd76(port);
        break;
    case 77:
        r = cmd77(port);
        break;
    case 128:
        r = FUN_a00c9980(port);
        break;
    case 130:
        r = FUN_a00cb1c8(port);
        break;
    case 131:
        r = FUN_a00cb618(port);
        break;
    case 81:
        r = cmd81(port);
        break;
    case 132:
        r = FUN_a00cb438(port);
        break;
    case 133:
        r = FUN_a00cb9d4(port);
        break;
    case 134:
        r = FUN_a00cb7f4(port);
        break;
    case 138:
        r = FUN_a00c9f44(port);
        break;
    case 139:
        r = FUN_a00ca158(port);
        break;
    case 107:
        r = cmd107(port);
        break;
    case 141:
        r = FUN_a00c68d8(port);
        break;
    case 106:
        r = cmd106(port);
        break;
    case 114:
        r = cmd114(port);
        break;
    case 136:
        r = cmd136(port);
        break;
    case 115:
        r = cmd115(port);
        break;
    case 142:
        r = FUN_a00c49b8(port);
        break;
    case 143:
        r = FUN_a00c7e3c(port);
        break;
    case 118:
        r = cmd118(port);
        break;
    case 119:
        r = cmd119(port);
        break;
    case 120:
        r = cmd120(port);
        break;
    case 135:
        r = cmd135(port);
        break;
    case 145:
        r = FUN_a00cbe9c(port);
        break;
    case 146:
        r = FUN_a00cc140(port);
        break;
    case 147:
        r = FUN_a00c8c38(port);
        break;
    case 30:
        r = cmd30(port);
        break;
    case 148:
        r = FUN_a00c25ac(port);
        break;
    case 149:
        r = FUN_a00c2180(port);
        break;
    case 150:
        r = FUN_a00c1d54(port);
        break;
    case 151:
        r = FUN_a00ca878(port);
        break;
    case 153:
        r = 0;
        break;
    case 129:
        r = cmd129(port);
        break;
    }
    ret = r;
    if (cmd != 0x8c) {
        if (ret == 0) {
            if (FUN_a0090fcc() != 0x106) {
                if (FUN_a0090fcc() != 0x109)
                    FUN_a0090fd8();
            }
        }
    }
    return ret;
}
