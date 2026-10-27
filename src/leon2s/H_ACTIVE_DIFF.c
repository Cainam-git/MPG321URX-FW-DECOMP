/* H_ACTIVE_DIFF (leon2s 0xa009cb34-0xa009d2f8, 1988 bytes), flags -mcpu=v8 -Os -g. Called by FUN_a009d2f8.
 * unsigned char (port): p = low byte of port; p 0 / 1 selects record 2 / 3 of ARR_a807cc64 (0x18 bytes), any
 * other p returns 0. Timing values (names from the firmware's own print strings):
 *   FUN_a00a03c8(p) != 0: from the register block at word +0x2c of ARR_a807db00[p] (0x34 bytes):
 *     H_ACTIVE = (reg 0xc bits 24..31) << 8 + reg 0x10 bits 0..7, V_ACTIVE = (reg 0xc bits 8..15) << 8 + reg 0xc
 *     bits 16..23, H_TOTAL = H_ACTIVE + three 16-bit sums of bytes of regs 0x84 / 0x88 / 0x8c;
 *     the block at word 0 is read at +0x64 once and +0x60 three times (values not used);
 *     V_TOTAL = FUN_a009c09c(p, byte +0x19 of DAT_a807d7e0[p]).
 *   otherwise from the block at word 0: H_TOTAL = (reg 0x38 >> 16) << DAT_a80790a8[p], V_TOTAL = reg 0x3c,
 *     H_ACTIVE = (reg 0x4c >> 16) << DAT_a80790a8[p], V_ACTIVE = reg 0x50 (all kept as unsigned short).
 * DAT_a807d7e0[p] (0x190 bytes) keeps the stored values: +0x1a H_TOTAL, +0x1c V_TOTAL, +0x1e H_ACTIVE, +0x20
 * V_ACTIVE. When DAT_a80790b0[p] differs from (byte +6 != 0): a 1 -> 0 change stores V_TOTAL at +0x1c and prints
 * it; DAT_a80790b0[p] takes the new value. A change is detected when (+0x2d == 0, +6 == 0 and |V_TOTAL diff| > 5),
 * (|H_ACTIVE diff| > 1 and +0x2d == 0), |V_ACTIVE diff| > 1, (u8)FUN_a0097ed0(p) != byte +0x18, byte +0xa of
 * DAT_a807d650[p] (0x18 bytes) == 1, or byte +0x18a == 1. Then: sets bit (2 + p) of register 0xcf03c890,
 * FUN_a00b1948(); when |H_ACTIVE diff| > 1 and |H_TOTAL diff| > 5 and both stored values are exactly twice or
 * exactly half the new ones, stores the new H_TOTAL / H_ACTIVE, prints the "Jay debug" line and returns 0.
 * No change: returns 0. Otherwise, with bit 2 of _DAT_a8078634, prints each difference above its limit, the
 * HDMI/DVI change and the +0xa flag; byte +0x14 of DAT_a807d650[p] == 0 prints "HDMI 21 Port%c modechange" and
 * clears byte 1 of the ARR_a807cc64 record; byte +0x18a == 1 is cleared with that byte and printed;
 * FUN_a009c87c(p); byte +2 != 0: prints "Connected", FUN_a00a0b10(p, 0), DRV_HDMI_Setup_IntIRQ_Events(p, 0);
 * else prints "Not Connected". Returns 1.
 * Source form: the register blocks are read through ARR_a807db00[p] in every expression (no pointer locals);
 * H_TOTAL is written 's2 + (hact + s1) + s3'; the timing locals are unsigned short; the print tests repeat
 * the abs() expressions; the H_TOTAL store comes before the H_ACTIVE store. The register blocks are hardware
 * registers (volatile).
 */
struct port_rec {
    volatile unsigned int *r0;
    unsigned char _04[0x28];
    volatile unsigned int *r2c;
    unsigned char _30[4];
};
struct mode_rec {
    unsigned char _00[2];
    unsigned char f02;
    unsigned char _03[3];
    unsigned char f06;
    unsigned char _07[0x11];
    unsigned char f18;
    unsigned char f19;
    unsigned short h1a;
    unsigned short h1c;
    unsigned short h1e;
    unsigned short h20;
    unsigned char _22[0xb];
    unsigned char f2d;
    unsigned char _2e[0x18a - 0x2e];
    unsigned char f18a;
    unsigned char _18b[5];
};
struct st_rec {
    unsigned int st;
    unsigned char _4[6];
    unsigned char fa;
    unsigned char _b[9];
    unsigned char f14;
    unsigned char _15[3];
};
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0x16];
};
extern struct port_rec ARR_a807db00[];
extern struct mode_rec DAT_a807d7e0[];
extern struct st_rec DAT_a807d650[];
extern struct sel_rec ARR_a807cc64[];
extern unsigned char DAT_a80790a8[];
extern unsigned char DAT_a80790b0[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern unsigned char FUN_a00a03c8(unsigned char);
extern unsigned int FUN_a009c09c(unsigned char, unsigned char);
extern unsigned int FUN_a0097ed0(unsigned int);
extern void FUN_a00b1948(void);
extern void FUN_a009c87c(unsigned int);
extern void FUN_a00a0b10(unsigned int, unsigned int);
extern void DRV_HDMI_Setup_IntIRQ_Events(unsigned int, unsigned int);

#define R_C890 (*(volatile unsigned int *)0xcf03c890)

unsigned char H_ACTIVE_DIFF(unsigned int port)
{
    unsigned char p = port;
    unsigned char idx;
    unsigned short htot, vtot, hact, vact;
    unsigned int s1, s2, s3;
    unsigned int v0, v1, v2, v3;
    unsigned char changed;

    if (p == 0)
        idx = 2;
    else if (p == 1)
        idx = 3;
    else
        return 0;

    if (FUN_a00a03c8(p)) {
        hact = ((ARR_a807db00[p].r2c[0xc / 4] >> 24) << 8) + (ARR_a807db00[p].r2c[0x10 / 4] & 0xff);
        vact = (((ARR_a807db00[p].r2c[0xc / 4] >> 8) & 0xff) << 8) + ((ARR_a807db00[p].r2c[0xc / 4] >> 16) & 0xff);
        s1 = (((ARR_a807db00[p].r2c[0x88 / 4] >> 16) & 0xff) << 8) + ((ARR_a807db00[p].r2c[0x88 / 4] >> 8) & 0xff);
        s2 = ((ARR_a807db00[p].r2c[0x88 / 4] & 0xff) << 8) + (ARR_a807db00[p].r2c[0x84 / 4] >> 24);
        v0 = ARR_a807db00[p].r0[0x64 / 4];
        v1 = ARR_a807db00[p].r0[0x60 / 4];
        v2 = ARR_a807db00[p].r0[0x60 / 4];
        v3 = ARR_a807db00[p].r0[0x60 / 4];
        s3 = ((ARR_a807db00[p].r2c[0x8c / 4] & 0xff) << 8) + (ARR_a807db00[p].r2c[0x88 / 4] >> 24);
        htot = s2 + (hact + s1) + s3;
        vtot = FUN_a009c09c(p, DAT_a807d7e0[p].f19);
    } else {
        htot = (ARR_a807db00[p].r0[0x38 / 4] >> 16) << DAT_a80790a8[p];
        vtot = ARR_a807db00[p].r0[0x3c / 4];
        hact = (ARR_a807db00[p].r0[0x4c / 4] >> 16) << DAT_a80790a8[p];
        vact = ARR_a807db00[p].r0[0x50 / 4];
    }
    if (DAT_a80790b0[p] != (DAT_a807d7e0[p].f06 != 0)) {
        if (DAT_a80790b0[p] == 1 && DAT_a807d7e0[p].f06 == 0) {
            DAT_a807d7e0[p].h1c = vtot;
            FUN_a0073044("free sync to non free sync Vtotal %d\r\n", vtot);
        }
        DAT_a80790b0[p] = DAT_a807d7e0[p].f06 != 0;
    }
    changed = 0;
    if ((DAT_a807d7e0[port & 0xff].f2d == 0 && DAT_a807d7e0[port & 0xff].f06 == 0
         && __builtin_abs(DAT_a807d7e0[port & 0xff].h1c - vtot) > 5)
        || (__builtin_abs(DAT_a807d7e0[port & 0xff].h1e - hact) > 1
            && DAT_a807d7e0[port & 0xff].f2d == 0)
        || __builtin_abs(DAT_a807d7e0[port & 0xff].h20 - vact) > 1
        || (unsigned char)FUN_a0097ed0(port & 0xff) != DAT_a807d7e0[port & 0xff].f18
        || DAT_a807d650[port & 0xff].fa == 1
        || DAT_a807d7e0[port & 0xff].f18a == 1) {
        R_C890 |= 4 << (port & 0xff);
        FUN_a00b1948();
        changed = 1;
        if (__builtin_abs(DAT_a807d7e0[port & 0xff].h1e - hact) > 1
            && __builtin_abs(DAT_a807d7e0[port & 0xff].h1a - htot) > 5) {
            if (DAT_a807d7e0[port & 0xff].h1e == hact * 2
                && DAT_a807d7e0[port & 0xff].h1a == htot * 2)
                changed = 0;
            else if (DAT_a807d7e0[port & 0xff].h1e == hact >> 1
                     && DAT_a807d7e0[port & 0xff].h1a == htot >> 1)
                changed = 0;
            if (changed == 0) {
                DAT_a807d7e0[port & 0xff].h1a = htot;
                DAT_a807d7e0[port & 0xff].h1e = hact;
                FUN_a0073044("## Jay debug ==> Port%c Enter Our Expection ##\n", (char)(port + 'A'));
            }
        }
    }
    if (changed == 0)
        return 0;

    if (__builtin_abs(DAT_a807d7e0[port & 0xff].h1a - htot) > 5 && (_DAT_a8078634 & 4))
        FUN_a0073044("[MODEDET]: Port%c H_TOTAL_DIFF = %d\n", (char)(port + 'A'),
                     __builtin_abs(DAT_a807d7e0[port & 0xff].h1a - htot));
    if (__builtin_abs(DAT_a807d7e0[port & 0xff].h1c - vtot) > 5 && (_DAT_a8078634 & 4))
        FUN_a0073044("[MODEDET]: Port%c V_TOTAL_DIFF = %d\n", (char)(port + 'A'),
                     __builtin_abs(DAT_a807d7e0[port & 0xff].h1c - vtot));
    if (__builtin_abs(DAT_a807d7e0[port & 0xff].h1e - hact) > 1 && (_DAT_a8078634 & 4))
        FUN_a0073044("[MODEDET]: Port%c H_ACTIVE_DIFF = %d\n", (char)(port + 'A'),
                     __builtin_abs(DAT_a807d7e0[port & 0xff].h1e - hact));
    if (__builtin_abs(DAT_a807d7e0[port & 0xff].h20 - vact) > 1 && (_DAT_a8078634 & 4))
        FUN_a0073044("[MODEDET]: Port%c V_ACTIVE_DIFF = %d\n", (char)(port + 'A'),
                     __builtin_abs(DAT_a807d7e0[port & 0xff].h20 - vact));
    if (DAT_a807d7e0[port & 0xff].f18 != (unsigned char)FUN_a0097ed0(port & 0xff) && (_DAT_a8078634 & 4))
        FUN_a0073044("[MODEDET]: Port%c HDMI/DVI Changed = %d to %d\n", (char)(port + 'A'),
                     DAT_a807d7e0[port & 0xff].f18, (unsigned char)FUN_a0097ed0(port & 0xff));
    if (DAT_a807d650[port & 0xff].fa == 1 && (_DAT_a8078634 & 4))
        FUN_a0073044("[MODEDET]: Port%c Int Set Mode Change\n", (char)(port + 'A'));
    if (DAT_a807d650[port & 0xff].f14 == 0) {
        FUN_a0073044("HDMI 21 Port%c modechange\r\n", (char)(port + 'A'));
        ARR_a807cc64[idx].b1 = 0;
    }
    if (DAT_a807d7e0[port & 0xff].f18a == 1) {
        DAT_a807d7e0[port & 0xff].f18a = 0;
        ARR_a807cc64[idx].b1 = 0;
        if (_DAT_a8078634 & 4)
            FUN_a0073044("[MODEDET]: Port%c Mode Change : scramble abnormal \n", (char)(port + 'A'));
    }
    FUN_a009c87c(port & 0xff);
    if (DAT_a807d7e0[port & 0xff].f02 != 0) {
        if (_DAT_a8078634 & 4)
            FUN_a0073044("[MODEDET]: Port%c Connected, Call Sync Lost & Internal Mute\n", (char)(port + 'A'));
        FUN_a00a0b10(port & 0xff, 0);
        DRV_HDMI_Setup_IntIRQ_Events(port & 0xff, 0);
    } else {
        if (_DAT_a8078634 & 4)
            FUN_a0073044("[MODEDET]: Port%c Not Connected, Bypass Sync Lost\n", (char)(port + 'A'));
    }
    return 1;
}
