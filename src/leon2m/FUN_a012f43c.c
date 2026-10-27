/* FUN_a012f43c (leon2m 0xa012f43c-0xa012f7a8, 876 bytes), flags -mcpu=v8 -O3 -g.
 * Callers include FUN_a012f7a8 and FUN_a012fc04.
 * k = port field (bits 12..15) of channel record DAT_a802df30[ch] for ch <= 3, else 0xff (same-file copy of
 * FUN_a012f3b4). When the three-bit code of DAT_a802e1a7 (same-file copy of FUN_a012f3ec, switch with the jump
 * table at 0xa012f16c, run-time address 0xcf16c) is 1 and ch is 0, or otherwise when k <= 7: if byte +0x0a of the
 * 42-byte record DAT_a802e224[k] differs from v or force is non-zero, then FUN_a0106ba8(k) when FUN_a0104c34(k)
 * returns 0, FUN_a0142ed0(k, v, force), FUN_a013d018(ch or 0, k, 1), FUN_a0138bf8(v) for k == 0,
 * FUN_a0137b5c(FUN_a0142168(v), 0, 1 << k) when FUN_a011cf88() > 0x82 and k <= 3, and FUN_a01216f8(k).
 * Then for ch <= 3 byte +0x76 of DAT_a802df30[ch] = 8 / 4 / 0x10 / 0x20 for v = 0x61 / 0x51 / 0x71 / 0x81, else 0.
 * Source form: the two arms repeat the same steps (FUN_a013d018 gets 0 in the first, ch in the second); the case
 * order 0x71, 0x81, 0x51, 0x61, default of the last switch gives the firmware register names.
 */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x76 - 0x04];
    unsigned char b76;
    unsigned char p77;
};
struct Port { unsigned char b00, b01, b02; unsigned char p03[7]; unsigned char b0a; unsigned char rest[0x2a - 0x0b]; };
extern struct Chan DAT_a802df30[4];
extern struct Port DAT_a802e224[];
extern unsigned char DAT_a802e1a7;
extern unsigned char FUN_a0104c34(unsigned char blk);
extern void FUN_a0106ba8(unsigned char);
extern void FUN_a0142ed0(unsigned char p, unsigned char m, unsigned char force);
extern void FUN_a013d018(unsigned char ch, unsigned char src, unsigned char force);
extern void FUN_a0138bf8(unsigned char param_1);
extern unsigned char FUN_a011cf88(void);
extern unsigned char FUN_a0142168(unsigned char t);
extern void FUN_a0137b5c(unsigned char ch, unsigned char a, unsigned char b);
extern void FUN_a01216f8(unsigned char ch);

static unsigned char chport(unsigned char c)
{
    unsigned char r = 0xff;
    if (c <= 3)
        r = DAT_a802df30[c].u.b.port;
    return r;
}

static unsigned char mode(void)
{
    unsigned char r;

    switch (DAT_a802e1a7) {
    default:
        r = 1;
        break;
    case 0:
        r = 1;
        break;
    case 4:
    case 7:
        r = 4;
        break;
    case 3:
    case 6:
        r = 3;
        break;
    case 1:
    case 2:
    case 5:
        r = 2;
        break;
    }
    return r & 7;
}

void FUN_a012f43c(unsigned char ch, unsigned char v, unsigned char force)
{
    unsigned char k, p;

    k = chport(ch);
    if (mode() == 1 && ch == 0) {
        p = k;
        if (DAT_a802e224[p].b0a != v || force) {
            if (FUN_a0104c34(p) == 0)
                FUN_a0106ba8(p);
            FUN_a0142ed0(p, v, force);
            FUN_a013d018(0, p, 1);
            if (p == 0)
                FUN_a0138bf8(v);
            if (FUN_a011cf88() > 0x82 && p < 4)
                FUN_a0137b5c(FUN_a0142168(v), 0, 1 << p);
            FUN_a01216f8(p);
        }
    } else {
        p = k;
        if (p > 7)
            return;
        if (DAT_a802e224[p].b0a != v || force) {
            if (FUN_a0104c34(p) == 0)
                FUN_a0106ba8(p);
            FUN_a0142ed0(p, v, force);
            FUN_a013d018(ch, p, 1);
            if (p == 0)
                FUN_a0138bf8(v);
            if (FUN_a011cf88() > 0x82 && p < 4)
                FUN_a0137b5c(FUN_a0142168(v), 0, 1 << p);
            FUN_a01216f8(p);
        }
        if (ch > 3)
            return;
    }
    switch (v) {
    case 0x71:
        DAT_a802df30[ch].b76 = 0x10;
        break;
    case 0x81:
        DAT_a802df30[ch].b76 = 0x20;
        break;
    case 0x51:
        DAT_a802df30[ch].b76 = 4;
        break;
    case 0x61:
        DAT_a802df30[ch].b76 = 8;
        break;
    default:
        DAT_a802df30[ch].b76 = 0;
        break;
    }
}
