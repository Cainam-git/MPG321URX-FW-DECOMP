/* DRV_HDMI21_LTS_STS_InitialSettings (leon2s 0xa009b5f4-0xa009bba8, 1460 bytes), flags -mcpu=v8 -Os -g.
 * void (port), called by INIT_handler. port = param & 0xff; sel = 2 for port 0, 3 for port 1; other ports
 * return. Under bit 11 of _DAT_a8078634 prints "[HDMI21]: \x1b[36;1m%s, PortID = %d\n\x1b[m" with the
 * function name and port. In the 0xb0-byte record DAT_a807d680[port] it clears bytes +1, +2, +0x14 and +0,
 * for each lane i = 0..3 the bytes +7 + i, +0xb + i, +0xf + i and the halfwords +0x1a + 4i, +0x1c + 4i, and
 * sets byte +3 + i to DAT_a8078640; then it clears bytes +0x13, +0x2a, +0x2b, +0x34..+0x39 and the words
 * DAT_a8079074[port] and DAT_a807906c[port]. Then a fixed list of FUN_a00a7424(mode, bit, sel, reg) and
 * FUN_a00a7488(sel, reg, mask, value) register writes (0x2070..0x3070, 0x2060..0x3060, 0x2028..0x3028,
 * 0x2c34, 0x2c30, 0x2c38, 0x2c24, 0x2c20, 0x3534, 0x2068..0x3068, 0x3608, 0x3618), FUN_a00a73ac(0x15, ..)
 * and FUN_a00a73d4(n, ..) on the register block addresses in words +0, +0x0c and +0x18 of DAT_a807db00[port]
 * (+0, +4, +8, +0x60, +0x7c, +0x80, +0x90), FUN_a007ab94(sel), FUN_a0073704(sel) and FUN_a00a7424(0, 0x14, sel,
 * 0x2e60).
 * Source form: everything after the print is the static inline helper rest(unsigned char port, int sel); its
 * parameter copy is the firmware's 'mov %l4,%i0' before the lane loop (the record clears and the loop set-up
 * use the caller's %l4, every later use the copy in %i0). The lane halfwords are elements 2i and 2i + 1 of an
 * unsigned short array at +0x1a, so the scheduler sees them as a different field from the byte arrays. Source
 * store order: lane loop a07, a0b, a0f, a03, halfword 2i, halfword 2i + 1; after the loop bytes +0x13..+0x39,
 * then DAT_a8079074 and DAT_a807906c. FUN_a00a7488 takes an unsigned char first parameter.
 */
struct lts_rec {
    unsigned char b00;
    unsigned char b01;
    unsigned char b02;
    unsigned char a03[4];
    unsigned char a07[4];
    unsigned char a0b[4];
    unsigned char a0f[4];
    unsigned char b13;
    unsigned char b14;
    unsigned char _15[0x1a - 0x15];
    unsigned short p1a[8];
    unsigned char b2a;
    unsigned char b2b;
    unsigned char _2c[4];
    unsigned int w30;
    unsigned char b34;
    unsigned char b35;
    unsigned char b36;
    unsigned char b37;
    unsigned char b38;
    unsigned char b39;
    unsigned char _3a[0xb0 - 0x3a];
};
struct port_rec {
    unsigned int w00;
    unsigned int _04[2];
    unsigned int w0c;
    unsigned int _10[2];
    unsigned int w18;
    unsigned char _1c[0x34 - 0x1c];
};
extern unsigned int _DAT_a8078634;
extern unsigned char DAT_a8078640;
extern struct lts_rec DAT_a807d680[];
extern unsigned int DAT_a807906c[];
extern unsigned int DAT_a8079074[];
extern struct port_rec DAT_a807db00[];
extern const char s_a006a5b0[];
extern const char s_a00b43d0[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned char, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a73ac(unsigned int, int);
extern void FUN_a00a73d4(unsigned int, int);
extern void FUN_a007ab94(unsigned char);
extern void FUN_a0073704(unsigned char);

static inline void rest(unsigned char port, int sel)
{
    unsigned char i;

    DAT_a807d680[port].b01 = 0;
    DAT_a807d680[port].b02 = 0;
    DAT_a807d680[port].b14 = 0;
    DAT_a807d680[port].b00 = 0;
    i = 0;
    do {
        DAT_a807d680[port].a07[i] = 0;
        DAT_a807d680[port].a0b[i] = 0;
        DAT_a807d680[port].a0f[i] = 0;
        DAT_a807d680[port].a03[i] = DAT_a8078640;
        DAT_a807d680[port].p1a[i * 2] = 0;
        DAT_a807d680[port].p1a[i * 2 + 1] = 0;
        i++;
    } while (i < 4);
    DAT_a807d680[port].b13 = 0;
    DAT_a807d680[port].b2a = 0;
    DAT_a807d680[port].b2b = 0;
    DAT_a807d680[port].b34 = 0;
    DAT_a807d680[port].b35 = 0;
    DAT_a807d680[port].b36 = 0;
    DAT_a807d680[port].b37 = 0;
    DAT_a807d680[port].b38 = 0;
    DAT_a807d680[port].b39 = 0;
    DAT_a8079074[port] = 0;
    DAT_a807906c[port] = 0;
    FUN_a00a7424(0, 3, sel, 0x2070);
    FUN_a00a7424(0, 3, sel, 0x2470);
    FUN_a00a7424(0, 3, sel, 0x2870);
    FUN_a00a7424(0, 3, sel, 0x3070);
    FUN_a00a7488(sel, 0x2060, 0xffcfffff, 0);
    FUN_a00a7488(sel, 0x2460, 0xffcfffff, 0);
    FUN_a00a7488(sel, 0x2860, 0xffcfffff, 0);
    FUN_a00a7488(sel, 0x3060, 0xffcfffff, 0);
    FUN_a00a7424(0, 0x18, sel, 0x2028);
    FUN_a00a7424(0, 0x11, sel, 0x2028);
    FUN_a00a7424(0, 0x11, sel, 0x2428);
    FUN_a00a7424(0, 0x11, sel, 0x2828);
    FUN_a00a7424(0, 0x11, sel, 0x3028);
    FUN_a00a7424(0, 0x13, sel, 0x2c34);
    FUN_a00a7424(1, 0x19, sel, 0x2c34);
    FUN_a00a7424(0, 0x10, sel, 0x2c34);
    FUN_a00a7424(0, 0x11, sel, 0x2c34);
    FUN_a00a7424(0, 0x12, sel, 0x2c34);
    FUN_a00a7488(sel, 0x2c30, 0xfff0ffff, 0xb0000);
    FUN_a00a7488(sel, 0x2c30, 0xff0fffff, 0x400000);
    FUN_a00a7488(sel, 0x2c30, 0xf0ffffff, 0xd000000);
    FUN_a00a7488(sel, 0x2c30, 0x0fffffff, 0x20000000);
    FUN_a00a7424(0, 0, sel, 0x2c30);
    FUN_a00a7488(sel, 0x2c34, 0xff1fffff, 0xc00000);
    FUN_a00a7488(sel, 0x2c38, 0xfffff1ff, 0);
    FUN_a00a7488(sel, 0x2c34, 0xfffff3ff, 0);
    FUN_a00a7424(0, 0x12, sel, 0x2c34);
    FUN_a00a7488(sel, 0x2c24, 0xfcffffff, 0);
    FUN_a00a7424(0, 5, sel, 0x2c20);
    FUN_a00a7424(0, 4, sel, 0x2c20);
    FUN_a00a7488(sel, 0x3534, 0xffff00ff, 0x4000);
    FUN_a00a7488(sel, 0x2060, 0xff3fffff, 0x800000);
    FUN_a00a7488(sel, 0x2460, 0xff3fffff, 0x800000);
    FUN_a00a7488(sel, 0x2860, 0xff3fffff, 0x800000);
    FUN_a00a7488(sel, 0x3060, 0xff3fffff, 0x800000);
    FUN_a00a7488(sel, 0x2068, 0xff00ffff, 0x130000);
    FUN_a00a7488(sel, 0x2468, 0xff00ffff, 0x130000);
    FUN_a00a7488(sel, 0x2868, 0xff00ffff, 0x130000);
    FUN_a00a7488(sel, 0x3068, 0xff00ffff, 0x130000);
    FUN_a00a7424(0, 4, sel, 0x3608);
    FUN_a00a7424(0, 0x1d, sel, 0x3618);
    FUN_a00a7424(1, 0x1c, sel, 0x3618);
    FUN_a00a7488(sel, 0x3618, 0xf8ffffff, 0x3000000);
    FUN_a00a73ac(0x15, DAT_a807db00[port].w00 + 4);
    FUN_a00a73d4(0, DAT_a807db00[port].w0c + 0x60);
    FUN_a00a73d4(1, DAT_a807db00[port].w0c + 0x60);
    FUN_a00a73d4(2, DAT_a807db00[port].w0c + 0x60);
    FUN_a00a73d4(3, DAT_a807db00[port].w18 + 0x80);
    FUN_a00a73d4(4, DAT_a807db00[port].w18 + 0x80);
    FUN_a00a73d4(5, DAT_a807db00[port].w18 + 0x80);
    FUN_a00a73d4(6, DAT_a807db00[port].w18 + 0x80);
    FUN_a00a73d4(7, DAT_a807db00[port].w18 + 0x80);
    FUN_a00a73d4(0x11, DAT_a807db00[port].w18 + 0x90);
    FUN_a007ab94(sel);
    FUN_a0073704(sel);
    FUN_a00a73d4(0xb, DAT_a807db00[port].w00 + 8);
    FUN_a00a73d4(0xd, DAT_a807db00[port].w18);
    FUN_a00a7424(0, 0x14, sel, 0x2e60);
    FUN_a00a73d4(0xb, DAT_a807db00[port].w0c + 0x7c);
}

void DRV_HDMI21_LTS_STS_InitialSettings(unsigned int param_1)
{
    unsigned int port;
    int sel;

    port = param_1 & 0xff;
    if (port == 0)
        sel = 2;
    else if (port == 1)
        sel = 3;
    else
        return;
    if (_DAT_a8078634 & 0x800)
        FUN_a0073044(s_a006a5b0, s_a00b43d0, port);
    rest(port, sel);
}