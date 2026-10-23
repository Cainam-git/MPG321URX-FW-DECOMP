/* leon2s DRV_HDMI_EQScan_FSM_PHY_PICDR @ 0xa007c4b8-0xa007cea4 (2540 bytes), flags -mcpu=v8 -Os -g.
 * u8 port; returns 0. v = the halfword at offset 8 of the 24-byte record DAT_a807cc64[port]. With bit 1 of
 * _DAT_a8078634 set it prints DAT_a0067ac0 with (char)(port + 'A') and the function name. Fixed PHY register
 * writes through FUN_a00a7488 (port, register, keep mask, value) and FUN_a00a7424 (value, bit, port,
 * register): 0x3534, 0x1154, the 0x1104/0x1108 pairs of the three 0x400-spaced channels, 0x114c, 0x115c.
 * Then by v: v < 100, v < 160, v < 300, v <= 600 (only when FUN_a007b2a0(port) is non-zero; else the v < 300
 * settings are used), each arm writing 0x1014/0x1414/0x1814 bits 24..31, bit 0x1a of 0x1f40, the 0x1018
 * channel fields, 0x1f00 bits 8..15, 0x1160 bits 24..27 and bits 0x1c..0x1e, 0x11f0 low byte and 0x11f4
 * (v & 0x3ff or (v >> 1) & 0x3ff with a debug print s_a0067ae0 below 160, 0x8000 / 0xf000 above); in the
 * v < 300 arm bits 24..25 of 0x1160 are 3 when FUN_a00a7468(6, 0, 0x1e80) returns 1. v > 600 prints
 * s_a0067b10 (FUN_a00734c4) and skips them. Then 0x1f44 low 6 bits = 0x1f (v <= 300) or 0x3f when
 * FUN_a0073520(port) is non-zero, bit 0 of 0x1140 cleared and of 0x1540/0x1940 set, 0x1c00 low byte cleared,
 * FUN_a00b1794(1), and word 0 of the 12-byte record ARR_a807ccc4[port] = 4.
 * Source form: compare chain v < 100 / 160 / 300 / <= 600; the v <= 600 arm reaches the v < 300 arm through
 * 'goto' when FUN_a007b2a0 returns 0 (the firmware re-extends port at that join); the 0x1f44 test written as
 * 'v <= 300' first.
 */
struct Rec24 { unsigned char _0[8]; unsigned short h8; unsigned char _a[0xe]; };
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct Rec24 DAT_a807cc64[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned int _DAT_a8078634;
extern unsigned char DAT_a0067ac0[];
extern char s_a0067ae0[], s_a0067b10[];
extern int FUN_a0073044(const void *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned char FUN_a007b2a0(unsigned char);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b1794(unsigned short);

extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
int DRV_HDMI_EQScan_FSM_PHY_PICDR(unsigned char port)
{
    unsigned short v = DAT_a807cc64[port].h8;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067ac0, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PICDR");
    FUN_a00a7488(port, 0x3534, 0xffff00ff, 0x4000);
    FUN_a00a7488(port, 0x1154, 0xffffff, 0x2000000);
    FUN_a00a7488(port, 0x1104, 0xffffff00, 3);
    FUN_a00a7488(port, 0x1108, 0xffffff00, 5);
    FUN_a00a7488(port, 0x1108, 0xffff00ff, 0x100);
    FUN_a00a7488(port, 0x1504, 0xffffff00, 3);
    FUN_a00a7488(port, 0x1508, 0xffffff00, 5);
    FUN_a00a7488(port, 0x1508, 0xffff00ff, 0x100);
    FUN_a00a7488(port, 0x1904, 0xffffff00, 3);
    FUN_a00a7488(port, 0x1908, 0xffffff00, 5);
    FUN_a00a7488(port, 0x1908, 0xffff00ff, 0x100);
    FUN_a00a7488(port, 0x1154, 0xffffff00, 0xf0);
    FUN_a00a7488(port, 0x1154, 0xffffe0ff, 0);
    FUN_a00a7488(port, 0x114c, 0xffff00ff, 0x600);
    FUN_a00a7488(port, 0x115c, 0xfffcffff, 0);
    FUN_a00a7424(1, 0x12, port, 0x115c);
    FUN_a00a7424(0, 0x13, port, 0x115c);
    FUN_a00a7424(0, 0x14, port, 0x115c);
    FUN_a00a7424(0, 0x15, port, 0x115c);
    FUN_a00a7424(1, 0x16, port, 0x115c);
    if (v < 100) {
        FUN_a00a7488(port, 0x1014, 0xffffff, 0xf3000000);
        FUN_a00a7488(port, 0x1414, 0xffffff, 0xf3000000);
        FUN_a00a7488(port, 0x1814, 0xffffff, 0xf3000000);
        FUN_a00a7424(0, 0x1a, port, 0x1f40);
        FUN_a00a7488(port, 0x1018, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1018, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x1418, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1418, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x1818, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1818, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x1f00, 0xffff00ff, 0);
        FUN_a00a7488(port, 0x1160, 0xfcffffff, 0);
        FUN_a00a7488(port, 0x1160, 0xf3ffffff, 0x4000000);
        FUN_a00a7424(0, 0x1c, port, 0x1160);
        FUN_a00a7424(1, 0x1d, port, 0x1160);
        FUN_a00a7424(1, 0x1e, port, 0x1160);
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0067ae0, (char)(port + 'A'), v);
        FUN_a00a7488(port, 0x11f0, 0xffffff00, 0);
        FUN_a00a7488(port, 0x11f4, 0xfffffc00, v & 0x3ff);
    } else if (v < 160) {
        FUN_a00a7488(port, 0x1014, 0xffffff, 0xf7000000);
        FUN_a00a7488(port, 0x1414, 0xffffff, 0xf7000000);
        FUN_a00a7488(port, 0x1814, 0xffffff, 0xf7000000);
        FUN_a00a7424(1, 0x1a, port, 0x1f40);
        FUN_a00a7488(port, 0x1018, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1018, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x1418, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1418, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x1818, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1818, 0xff9fffff, 0x400000);
        FUN_a00a7488(port, 0x1f00, 0xffff00ff, 0x700);
        FUN_a00a7488(port, 0x1160, 0xfcffffff, 0);
        FUN_a00a7488(port, 0x1160, 0xf3ffffff, 0x4000000);
        FUN_a00a7424(0, 0x1c, port, 0x1160);
        FUN_a00a7424(1, 0x1d, port, 0x1160);
        FUN_a00a7424(1, 0x1e, port, 0x1160);
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0067ae0, (char)(port + 'A'), v >> 1);
        FUN_a00a7488(port, 0x11f0, 0xffffff00, 0);
        FUN_a00a7488(port, 0x11f4, 0xfffffc00, (v >> 1) & 0x3ff);
    } else if (v < 300) {
l300:
        FUN_a00a7488(port, 0x1014, 0xffffff, 0xf7000000);
        FUN_a00a7488(port, 0x1414, 0xffffff, 0xf7000000);
        FUN_a00a7488(port, 0x1814, 0xffffff, 0xf7000000);
        FUN_a00a7424(1, 0x1a, port, 0x1f40);
        FUN_a00a7488(port, 0x1018, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1018, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x1418, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1418, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x1818, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1818, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x1f00, 0xffff00ff, 0x700);
        if (FUN_a00a7468(6, 0, 0x1e80) == 1)
            FUN_a00a7488(port, 0x1160, 0xfcffffff, 0x3000000);
        else
            FUN_a00a7488(port, 0x1160, 0xfcffffff, 0);
        FUN_a00a7488(port, 0x1160, 0xf3ffffff, 0x4000000);
        FUN_a00a7424(0, 0x1c, port, 0x1160);
        FUN_a00a7424(1, 0x1d, port, 0x1160);
        FUN_a00a7424(1, 0x1e, port, 0x1160);
        FUN_a00a7488(port, 0x11f0, 0xffffff00, 0x80);
        FUN_a00a7488(port, 0x11f4, 0xffff0fff, 0x8000);
    } else if (v <= 600) {
        if (!FUN_a007b2a0(port))
            goto l300;
        FUN_a00a7488(port, 0x1014, 0xffffff, 0xf7000000);
        FUN_a00a7488(port, 0x1414, 0xffffff, 0xf7000000);
        FUN_a00a7488(port, 0x1814, 0xffffff, 0xf7000000);
        FUN_a00a7424(1, 0x1a, port, 0x1f40);
        FUN_a00a7488(port, 0x3534, 0xffff00ff, 0x4000);
        FUN_a00a7488(port, 0x1018, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1018, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x1418, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1418, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x1818, 0xffe0ffff, 0x40000);
        FUN_a00a7488(port, 0x1818, 0xff9fffff, 0x200000);
        FUN_a00a7488(port, 0x1f00, 0xffff00ff, 0x700);
        FUN_a00a7488(port, 0x1160, 0xfcffffff, 0x3000000);
        FUN_a00a7488(port, 0x1160, 0xf3ffffff, 0x4000000);
        FUN_a00a7424(0, 0x1c, port, 0x1160);
        FUN_a00a7424(1, 0x1d, port, 0x1160);
        FUN_a00a7424(1, 0x1e, port, 0x1160);
        FUN_a00a7488(port, 0x11f0, 0xffffff00, 0x80);
        FUN_a00a7488(port, 0x11f4, 0xffff0fff, 0xf000);
    } else {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a00734c4(s_a0067b10);
    }
    if (FUN_a0073520(port)) {
        if (v <= 300)
            FUN_a00a7488(port, 0x1f44, 0xffffffc0, 0x1f);
        else
            FUN_a00a7488(port, 0x1f44, 0xffffffc0, 0x3f);
    }
    FUN_a00a7424(0, 0x0, port, 0x1140);
    FUN_a00a7424(1, 0x0, port, 0x1540);
    FUN_a00a7424(1, 0x0, port, 0x1940);
    FUN_a00a7488(port, 0x1c00, 0xffffff00, 0);
    FUN_a00b1794(1);
    ARR_a807ccc4[port].w0 = 4;
    return 0;
}
