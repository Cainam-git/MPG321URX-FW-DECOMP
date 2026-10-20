/*
 * DRV_HDMI_ModeDetect_FSM_Complete (leon2s, 0xa009e368-0xa009e9a4, 1596 bytes), flags -mcpu=v8 -Os -g.
 * Per-port records: DAT_a807d7e0[port] (400 bytes), DAT_a807db00[port] (0x34 bytes: word 0 and word 4 are
 * register block addresses, +0x18 a register pointer), DAT_a807d650[port] (0x18 bytes, word 0 = state).
 * Prints "[MODEDET]: Port%c DRV_HDMI_ModeDetect_FSM_Complete" when bit 2 of DAT_a8078634 is set (all
 * "[MODEDET]" lines depend on that bit). When FUN_a00a03c8(port) is nonzero: byte +0x2d = 1,
 * FUN_a00a73d4(2, word 0 + 0xb4) and the flag passed to H_Total is 1; otherwise byte +0x2d = 0.
 * H_Total(port, &byte +0x18, flag) == 0: state 5, returns 0. Otherwise: DAT_a80790b0[port] = (byte +6 != 0),
 * clears DAT_a8079050[port] / DAT_a80790b8[port], bytes +4 / +5 = 1, +7 = 0, state byte +0xb = 0,
 * FUN_a00a73ac / FUN_a00a73d4(0x1c, word 4 + 0x34), byte +1 = 1, state byte +0x14 = 0, FUN_a0096aa4(port),
 * FUN_a0096ad8(port), byte +0x15c = 0. Byte +0x18 == 1: for six blocks (+0x4c, +0xbc, +0xec, +0x114,
 * +0x162, +0x184) whose last byte is 0, calls FUN_a009f738 / FUN_a009faf0 / FUN_a009fcb8 / FUN_a009fed0 /
 * FUN_a00a0268 / FUN_a00a0478(port, block); result 0 sets the two bytes before the last byte to 1, a
 * nonzero result prints "No AVI Info" / "No AUDIO Info" / "No StdSPD Info" / "No HDR Info Frame" /
 * "No AUD Stream" / "No CVTEM". Byte +0x18 != 1: FUN_a00b15ac clears the blocks +0x4c, +0xbc, +0xa4, +0xec,
 * +0x114, +0x162, +0x184 (0x58, 0x30, 0x18, 0x24, 0x48, 0x22, 5 bytes). Then prints the FRL mode (bits
 * 24..27 of register +0x90), "Pixel clock" (halfword +0x32, FUN_a00a20c4(port)) and "Color format"
 * (word +0x50), FUN_a00a73ac(0x18, word 0 + 0xb8), FUN_a00a0bfc(port), limits DAT_a8078648[port] to 10,
 * clears state byte +0xa, DRV_HDMI_Setup_IntIRQ_Events(port, 1), FUN_a00a0b10(port, 1),
 * FUN_a0097ff4(port, 0), prints "Sync Stable", FUN_a00a2cf4(port, &a, &b) with two cleared stack words,
 * DRV_HDMI_Set_AudStatus(port, 1), state 8, and with bit 0 of DAT_a8078634 prints the "Jay_ModeDet_End"
 * line with FUN_a00b2064(). Returns 1.
 * Source forms: the info tests are written 'if (call != 0) { print } else { flags }' with the higher flag
 * stored first. FUN_a00b15ac returns its destination pointer and FUN_a00a2cf4 returns int: both return
 * types change the argument set-up order before the calls.
 */
struct blk4c { unsigned int w0; unsigned int w4; unsigned char d[0x4d]; unsigned char f55, f56, f57; };
struct blka4 { unsigned char d[0x18]; };
struct blkbc { unsigned char d[0x2a]; unsigned char f2a, f2b, f2c; unsigned char _2d[3]; };
struct blkec { unsigned char d[0x20]; unsigned char f20, f21, f22; unsigned char _23; };
struct blk114 { unsigned char d[0x43]; unsigned char f43, f44, f45; unsigned char _46[2]; };
struct blk162 { unsigned char d[0x1f]; unsigned char f1f, f20, f21; };
struct blk184 { unsigned char d[2]; unsigned char f2, f3, f4; };
struct mode_rec {
    unsigned char _00;
    unsigned char f01;
    unsigned char _02[2];
    unsigned char f04;
    unsigned char f05;
    unsigned char f06;
    unsigned char f07;
    unsigned char _08[0x10];
    unsigned char f18;
    unsigned char _19[0x14];
    unsigned char f2d;
    unsigned char _2e[4];
    unsigned short f32;
    unsigned char _34[0x18];
    struct blk4c b4c;
    struct blka4 ba4;
    struct blkbc bbc;
    struct blkec bec;
    unsigned char _110[4];
    struct blk114 b114;
    unsigned char f15c;
    unsigned char _15d[5];
    struct blk162 b162;
    struct blk184 b184;
    unsigned char _189[7];
};
struct port_rec {
    unsigned int r0;
    unsigned int r4;
    unsigned int _08[4];
    volatile unsigned int *r18;
    unsigned char _1c[0x34 - 0x1c];
};
struct st_rec {
    unsigned int st;
    unsigned char _4[6];
    unsigned char fa;
    unsigned char fb;
    unsigned char _c[8];
    unsigned char f14;
    unsigned char _15[3];
};
extern struct mode_rec DAT_a807d7e0[];
extern struct port_rec DAT_a807db00[];
extern struct st_rec DAT_a807d650[];
extern unsigned int DAT_a8078634;
extern unsigned char DAT_a80790b0[];
extern unsigned char DAT_a8079050[];
extern unsigned char DAT_a80790b8[];
extern unsigned char DAT_a8078648[];

extern int FUN_a0073044(const char *, ...);
extern unsigned char FUN_a00a03c8(unsigned char);
extern void FUN_a00a73ac(unsigned int, int);
extern void FUN_a00a73d4(unsigned int, int);
extern unsigned char H_Total(unsigned char, unsigned char *, unsigned char);
extern void FUN_a0096aa4(unsigned char);
extern void FUN_a0096ad8(unsigned int);
extern unsigned char FUN_a009f738(unsigned char, struct blk4c *);
extern unsigned char FUN_a009faf0(unsigned char, struct blkbc *);
extern unsigned char FUN_a009fcb8(unsigned char, struct blkec *);
extern unsigned char FUN_a009fed0(unsigned char, struct blk114 *);
extern unsigned char FUN_a00a0268(unsigned char, struct blk162 *);
extern unsigned char FUN_a00a0478(unsigned char, struct blk184 *);
extern void *FUN_a00b15ac(unsigned char *, unsigned char, int);
extern unsigned short FUN_a00a20c4(unsigned char);
extern void FUN_a00a0bfc(unsigned int);
extern void DRV_HDMI_Setup_IntIRQ_Events(unsigned int, unsigned int);
extern void FUN_a00a0b10(unsigned int, unsigned int);
extern void FUN_a0097ff4(unsigned char, unsigned char);
extern int FUN_a00a2cf4(unsigned char, unsigned int *, unsigned int *);
extern void DRV_HDMI_Set_AudStatus(unsigned char, unsigned char);
extern unsigned int FUN_a00b2064(void);

int DRV_HDMI_ModeDetect_FSM_Complete(unsigned char port)
{
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int on = 0;

    if (DAT_a8078634 & 4)
        FUN_a0073044("[MODEDET]: Port%c DRV_HDMI_ModeDetect_FSM_Complete\n", (char)(port + 0x41));
    if (FUN_a00a03c8(port) != 0) {
        DAT_a807d7e0[port].f2d = 1;
        FUN_a00a73d4(2, DAT_a807db00[port].r0 + 0xb4);
        on = 1;
    } else
        DAT_a807d7e0[port].f2d = 0;
    if (H_Total(port, &DAT_a807d7e0[port].f18, on) == 0) {
        DAT_a807d650[port].st = 5;
        return 0;
    }
    DAT_a80790b0[port] = DAT_a807d7e0[port].f06 != 0;
    DAT_a8079050[port] = 0;
    DAT_a80790b8[port] = 0;
    DAT_a807d7e0[port].f04 = 1;
    DAT_a807d7e0[port].f05 = 1;
    DAT_a807d7e0[port].f07 = 0;
    DAT_a807d650[port].fb = 0;
    FUN_a00a73ac(0x1c, DAT_a807db00[port].r4 + 0x34);
    FUN_a00a73d4(0x1c, DAT_a807db00[port].r4 + 0x34);
    DAT_a807d7e0[port].f01 = 1;
    DAT_a807d650[port].f14 = 0;
    FUN_a0096aa4(port);
    FUN_a0096ad8(port);
    DAT_a807d7e0[port].f15c = 0;
    if (DAT_a807d7e0[port].f18 == 1) {
        if (DAT_a807d7e0[port].b4c.f57 == 0) {
            if (FUN_a009f738(port, &DAT_a807d7e0[port].b4c) != 0) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044("[MODEDET]: Port%c No AVI Info !!\n", (char)(port + 0x41));
            } else {
                DAT_a807d7e0[port].b4c.f55 = 1;
                DAT_a807d7e0[port].b4c.f56 = 1;
            }
        }
        if (DAT_a807d7e0[port].bbc.f2c == 0) {
            if (FUN_a009faf0(port, &DAT_a807d7e0[port].bbc) != 0) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044("[MODEDET]: Port%c No AUDIO Info !!\n", (char)(port + 0x41));
            } else {
                DAT_a807d7e0[port].bbc.f2a = 1;
                DAT_a807d7e0[port].bbc.f2b = 1;
            }
        }
        if (DAT_a807d7e0[port].bec.f22 == 0) {
            if (FUN_a009fcb8(port, &DAT_a807d7e0[port].bec) != 0) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044("[MODEDET]: Port%c No StdSPD Info !!\n", (char)(port + 0x41));
            } else {
                DAT_a807d7e0[port].bec.f20 = 1;
                DAT_a807d7e0[port].bec.f21 = 1;
            }
        }
        if (DAT_a807d7e0[port].b114.f45 == 0) {
            if (FUN_a009fed0(port, &DAT_a807d7e0[port].b114) != 0) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044("[MODEDET]: Port%c No HDR Info Frame !!\n", (char)(port + 0x41));
            } else {
                DAT_a807d7e0[port].b114.f43 = 1;
                DAT_a807d7e0[port].b114.f44 = 1;
            }
        }
        if (DAT_a807d7e0[port].b162.f21 == 0) {
            if (FUN_a00a0268(port, &DAT_a807d7e0[port].b162) != 0) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044("[MODEDET]: Port%c No AUD Stream !!\n", (char)(port + 0x41));
            } else {
                DAT_a807d7e0[port].b162.f1f = 1;
                DAT_a807d7e0[port].b162.f20 = 1;
            }
        }
        if (DAT_a807d7e0[port].b184.f4 == 0) {
            if (FUN_a00a0478(port, &DAT_a807d7e0[port].b184) != 0) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044("[MODEDET]: Port%c No CVTEM !!\n", (char)(port + 0x41));
            } else {
                DAT_a807d7e0[port].b184.f2 = 1;
                DAT_a807d7e0[port].b184.f3 = 1;
            }
        }
    } else {
        FUN_a00b15ac((unsigned char *)&DAT_a807d7e0[port].b4c, 0, sizeof(struct blk4c));
        FUN_a00b15ac((unsigned char *)&DAT_a807d7e0[port].bbc, 0, sizeof(struct blkbc));
        FUN_a00b15ac((unsigned char *)&DAT_a807d7e0[port].ba4, 0, sizeof(struct blka4));
        FUN_a00b15ac((unsigned char *)&DAT_a807d7e0[port].bec, 0, sizeof(struct blkec));
        FUN_a00b15ac((unsigned char *)&DAT_a807d7e0[port].b114, 0, sizeof(struct blk114));
        FUN_a00b15ac((unsigned char *)&DAT_a807d7e0[port].b162, 0, sizeof(struct blk162));
        FUN_a00b15ac((unsigned char *)&DAT_a807d7e0[port].b184, 0, sizeof(struct blk184));
    }
    FUN_a0073044("\x1b[32;1mDRV_HDMI_ModeDetect_FSM_Complete FRL mode = %ld\n\x1b[m",
                 (DAT_a807db00[port].r18[0x90 / 4] >> 24) & 0xf);
    FUN_a0073044("Pixel clock(0.1M) = %d, TMDS clock(0.1M) = %d\n", DAT_a807d7e0[port].f32, FUN_a00a20c4(port));
    FUN_a0073044("Color format = %d  (0: RGB, 1: 422, 2: 444, 3:420)\n", DAT_a807d7e0[port].b4c.w4);
    FUN_a00a73ac(0x18, DAT_a807db00[port].r0 + 0xb8);
    FUN_a00a0bfc(port);
    if (DAT_a8078648[port] > 10)
        DAT_a8078648[port] = 10;
    DAT_a807d650[port].fa = 0;
    DRV_HDMI_Setup_IntIRQ_Events(port, 1);
    FUN_a00a0b10(port, 1);
    FUN_a0097ff4(port, 0);
    if (DAT_a8078634 & 4)
        FUN_a0073044("[MODEDET]: Port%c Sync Stable !!\n", (char)(port + 0x41));
    FUN_a00a2cf4(port, &a, &b);
    DRV_HDMI_Set_AudStatus(port, 1);
    DAT_a807d650[port].st = 8;
    if (DAT_a8078634 & 1)
        FUN_a0073044("[INIT]: ## Port%c => Jay_ModeDet_End [%ld] ##\n\n", (char)(port + 0x41), FUN_a00b2064());
    return 1;
}
