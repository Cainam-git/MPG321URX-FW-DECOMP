/* DRV_HDMI_EQScan_FSM_PHY_DPHY (leon2s 0xa007cea4-0xa007cfec, 328 bytes), flags -mcpu=v8 -Os -g.
 * Under bit 1 of _DAT_a8078634 prints s_a0067b38 with 'A' + port and the function name. FUN_a00a7424(1, 7, port,
 * 0x1e90), FUN_a00a7488(port, 0x1f08, -8, 4). For the halfword h at +8 of the 0x18-byte record ARR_a807cc64[port]:
 * h < 100, < 160, < 300 and (h <= 600 with FUN_a007b2a0(port) != 0, or FUN_a007b2a0(port) == 0 through the
 * h < 300 arm) each do FUN_a00a7424(0, 2, port, 0x1e90) and FUN_a00a7488(port, 0x119c, 0xff00ffff, 0); h > 600
 * prints s_a0067a98 (bit 1). Then word 0 of ARR_a807ccc4[port] = 3; returns 0.
 * Source form: each h arm written in full (crossjumping shares the tails) and the h <= 600 arm reaches the h < 300
 * arm through 'goto' when FUN_a007b2a0 returns 0, as in DRV_HDMI_EQScan_FSM_PHY_PLL; the format strings are the
 * firmware's own objects (s_a0067a98 is shared with DRV_HDMI_EQScan_FSM_PHY_EQ).
 */
struct sel_rec {
    unsigned char b[8];
    unsigned short h8;
    unsigned char _a[0x18 - 0xa];
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct sel_rec ARR_a807cc64[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a00734c4(const char *);
extern unsigned char FUN_a007b2a0(unsigned char);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern char s_a0067b38[], s_a0067a98[];
static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_DPHY";

int DRV_HDMI_EQScan_FSM_PHY_DPHY(unsigned char port)
{
    unsigned short h = ARR_a807cc64[port].h8;

    if (_DAT_a8078634 & 2)
        FUN_a0073044(s_a0067b38, (char)(port + 'A'), fn_);
    FUN_a00a7424(1, 7, port, 0x1e90);
    FUN_a00a7488(port, 0x1f08, -8, 4);
    if (h < 100) {
        FUN_a00a7424(0, 2, port, 0x1e90);
        FUN_a00a7488(port, 0x119c, 0xff00ffff, 0);
    } else if (h < 160) {
        FUN_a00a7424(0, 2, port, 0x1e90);
        FUN_a00a7488(port, 0x119c, 0xff00ffff, 0);
    } else if (h < 300) {
l300:
        FUN_a00a7424(0, 2, port, 0x1e90);
        FUN_a00a7488(port, 0x119c, 0xff00ffff, 0);
    } else if (h <= 600) {
        if (!FUN_a007b2a0(port))
            goto l300;
        FUN_a00a7424(0, 2, port, 0x1e90);
        FUN_a00a7488(port, 0x119c, 0xff00ffff, 0);
    } else {
        if (_DAT_a8078634 & 2)
            FUN_a00734c4(s_a0067a98);
    }
    ARR_a807ccc4[port].w0 = 3;
    return 0;
}
