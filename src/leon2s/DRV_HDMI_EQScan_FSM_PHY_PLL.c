/* DRV_HDMI_EQScan_FSM_PHY_PLL (leon2s 0xa007e7c0-0xa007ebd0, 1040 bytes), flags -mcpu=v8 -Os -g.
 * u8 port; returns 1, or 0 on the retry-limit path. v = halfword +8 of the 24-byte record DAT_a807cc64[port].
 * Prints DAT_a0067058 with (char)(port + 'A') and the function name when bit 1 of _DAT_a8078634 is set.
 * Register writes go through FUN_a00a7424 (value, bit, port, register) and FUN_a00a7488 (port, register,
 * keep mask, value): bits 0x15..0x17 of 0x1c04/0x1c00 of port 0 cleared; r = FUN_a0073520(port), when set
 * bits 0, 1, 8 of 0x3600 cleared; 0x1028 bits 24..31 = 0x30, 0x1034 bits 16..23 = 0xf0, 0x1014 bits 16..23 =
 * 0x8c, bit 0x12 of 0x1c04 set, 0x1014 bits 16..23 = 0x8d.
 * By v: v < 100 / v < 160: 0x1008 bits 24..31 = 0x2b / 0x1b, bit 8 of 0x100c set, 0x100c bits 9..10 = 3, and
 * 0x3608 bits 16..23 = 5 when r. v < 300 (also v <= 600 when FUN_a007b2a0(port) is 0): 0x1b, bit 8 of 0x100c,
 * bits 9..10 = 2, 0x3608 = 5 when FUN_a0073520(port) (called again). v <= 600: 0x1014 bits 16..23 = 0xfd,
 * 0x1008 = 0x3b, bit 8 of 0x100c, then with r: 0x100c bits 9..10 = 1, 0x3608 = 0xc and bit 8 of 0x3600
 * set, else 0x100c bits 9..10 = 0. v > 600: prints the clock out of range; when FUN_a007b2a0(port) and
 * FUN_a007d054(port) are set, byte +0x896 of the 0x898-byte record ARR_a807a9f0[port] counts up and above 3
 * it prints "clear scramble bit and ratio bit", clears word 0 of ARR_a807ccc4[port] and the counter, prints
 * "go to FSM_EQSCAN_PHY_INIT 5" and returns 0.
 * Otherwise word 0 of the 12-byte record ARR_a807ccc4[port] = 2.
 * Source forms: each v arm written in full (crossjumping shares the tails); the v <= 600 arm reaches the
 * v < 300 arm through 'goto' when FUN_a007b2a0 returns 0; _DAT_a8078634 is declared unsigned long (the
 * alias set orders its reload after the record address setup in the retry-limit path).
 */
struct Rec24 { unsigned char _0[8]; unsigned short h8; unsigned char _a[0xe]; };
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
struct EqRec { unsigned char _0[0x896]; unsigned char b896; unsigned char _897; };
extern struct Rec24 DAT_a807cc64[];
extern struct Rec12 ARR_a807ccc4[];
extern struct EqRec ARR_a807a9f0[];
extern unsigned long _DAT_a8078634;
extern unsigned char DAT_a0067058[];
extern int FUN_a0073044(const void *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned char FUN_a007b2a0(unsigned char);
extern unsigned char FUN_a007d054(unsigned char);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_PLL";

int DRV_HDMI_EQScan_FSM_PHY_PLL(unsigned char port)
{
    unsigned short v = DAT_a807cc64[port].h8;
    unsigned char r;
    unsigned char n;

    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067058, (char)(port + 'A'), fn_);
    FUN_a00a7424(0, 0x15, 0, 0x1c04);
    FUN_a00a7424(0, 0x16, 0, 0x1c00);
    FUN_a00a7424(0, 0x17, 0, 0x1c00);
    r = FUN_a0073520(port);
    if (r) {
        FUN_a00a7424(0, 0, port, 0x3600);
        FUN_a00a7424(0, 1, port, 0x3600);
        FUN_a00a7424(0, 8, port, 0x3600);
    }
    FUN_a00a7488(port, 0x1028, 0xffffff, 0x30000000);
    FUN_a00a7488(port, 0x1034, 0xff00ffff, 0xf00000);
    FUN_a00a7488(port, 0x1014, 0xff00ffff, 0x8c0000);
    FUN_a00a7424(1, 0x12, port, 0x1c04);
    FUN_a00a7488(port, 0x1014, 0xff00ffff, 0x8d0000);
    if (v < 100) {
        FUN_a00a7488(port, 0x1008, 0xffffff, 0x2b000000);
        FUN_a00a7424(1, 8, port, 0x100c);
        FUN_a00a7488(port, 0x100c, 0xfffff9ff, 0x600);
        if (r)
            FUN_a00a7488(port, 0x3608, 0xff00ffff, 0x50000);
    } else if (v < 160) {
        FUN_a00a7488(port, 0x1008, 0xffffff, 0x1b000000);
        FUN_a00a7424(1, 8, port, 0x100c);
        FUN_a00a7488(port, 0x100c, 0xfffff9ff, 0x600);
        if (r)
            FUN_a00a7488(port, 0x3608, 0xff00ffff, 0x50000);
    } else if (v < 300) {
l300:
        FUN_a00a7488(port, 0x1008, 0xffffff, 0x1b000000);
        FUN_a00a7424(1, 8, port, 0x100c);
        FUN_a00a7488(port, 0x100c, 0xfffff9ff, 0x400);
        if (FUN_a0073520(port))
            FUN_a00a7488(port, 0x3608, 0xff00ffff, 0x50000);
    } else if (v <= 600) {
        if (!FUN_a007b2a0(port))
            goto l300;
        FUN_a00a7488(port, 0x1014, 0xff00ffff, 0xfd0000);
        FUN_a00a7488(port, 0x1008, 0xffffff, 0x3b000000);
        FUN_a00a7424(1, 8, port, 0x100c);
        if (r) {
            FUN_a00a7488(port, 0x100c, 0xfffff9ff, 0x200);
            FUN_a00a7488(port, 0x3608, 0xff00ffff, 0xc0000);
            FUN_a00a7424(1, 8, port, 0x3600);
        } else {
            FUN_a00a7488(port, 0x100c, 0xfffff9ff, 0);
        }
    } else {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044("[EQ]: HDMI Mode : Phy EQ Clk = %d, out clk range!!!\n", v);
        if (FUN_a007b2a0(port) && FUN_a007d054(port)) {
            n = ARR_a807a9f0[port].b896;
            ARR_a807a9f0[port].b896 = n + 1;
            if (n > 3) {
                if ((_DAT_a8078634 & 2) != 0)
                    FUN_a00734c4("[EQ]: \nclear scramble bit and ratio bit");
                ARR_a807ccc4[port].w0 = 0;
                ARR_a807a9f0[port].b896 = 0;
                if ((_DAT_a8078634 & 2) != 0)
                    FUN_a0073044("[EQ]: go to FSM_EQSCAN_PHY_INIT %d\r\n", 5);
                return 0;
            }
        }
    }
    ARR_a807ccc4[port].w0 = 2;
    return 1;
}
