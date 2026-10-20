/* Jay_EQ_End (leon2s 0xa009d5cc-0xa009d87c, 688 bytes), flags -mcpu=v8 -Os -g.
 * End step of the HDMI 2.1 receiver EQ sequence for port 0 or 1 (other ports return 0 at once); sel = 2 for
 * port 0, 3 for port 1. Sets/clears register bits through FUN_a00a73ac / FUN_a00a73d4 (bit n of a word array
 * reached through the 0x34-byte port record DAT_a807db00[port]), calls FUN_a009fe60(port) and, when byte +4 of
 * the 400-byte record ARR_a807d7e0[port] is 1, FUN_a009c87c(port). With c = byte +1 of the 0x18-byte record
 * DAT_a807cc64[sel], clears DAT_a80790c8[port], then:
 *   c == 1 and state word DAT_a807d648[port] == 9: sets bits 0x18/0x19 again, DAT_a807d650[port].st = 1,
 *     clears bit 0xb at rc + 0x7c, prints "PortA Run HDMI21 ModeDet", returns 1;
 *   byte +1 of DAT_a807cc64[sel] (read again) == 1 and record byte +1 == 0: eq_done(port), a debug print when
 *     bit 2 of _DAT_a8078634 is set, returns 1;
 *   otherwise eq_fail: clears record byte +1, FUN_a0096aa4(port), FUN_a0096ad8(port), returns 0.
 * Source forms: the two conditions are separate if statements (the second one rereads the byte after the
 * DAT_a80790c8 store); eq_done and eq_fail are static helpers with an unsigned char port parameter (the
 * fail path converts the raw parameter again); c is an unsigned int; st = 4 is written before cnt = 10.
 */
struct port_rec {
    volatile unsigned int *r0;
    volatile unsigned int *r4;
    volatile unsigned int *r8;
    volatile unsigned int *rc;
    unsigned int _10[4];
    volatile unsigned int *r20;
    unsigned char _24[0x34 - 0x24];
};
struct eq_state {
    unsigned int st;
    unsigned char cnt;
    unsigned char _5[0x18 - 5];
};
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0x18 - 2];
};
extern struct port_rec DAT_a807db00[];
extern unsigned char ARR_a807d7e0[];
extern struct sel_rec DAT_a807cc64[];
extern unsigned int DAT_a807d648[];
extern struct eq_state DAT_a807d650[];
extern unsigned char DAT_a80790c8[];
extern unsigned char DAT_a80790a8[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern void FUN_a009fe60(unsigned char);
extern void FUN_a009c87c(unsigned char);
extern void FUN_a0096aa4(unsigned char);
extern void FUN_a0096ad8(unsigned int);
extern unsigned int FUN_a00b2064(void);

static void eq_done(unsigned char port)
{
    unsigned char *rec = ARR_a807d7e0 + port * 400;

    DAT_a80790a8[port] = 0;
    FUN_a00a73d4(0xc, DAT_a807db00[port].r0 + 2);
    FUN_a00a73ac(0xd, DAT_a807db00[port].r0 + 2);
    FUN_a00a73d4(0xf, DAT_a807db00[port].r0 + 2);
    FUN_a0073044("EQ done %d\r\n", 1);
    rec[0x2d] = 0;
    FUN_a00a73ac(0x14, DAT_a807db00[port].r0 + 0x21);
    DAT_a807db00[port].r20[0x20] |= 7;
    FUN_a00a73d4(0xb, DAT_a807db00[port].r0 + 2);
    DAT_a807d650[port].st = 4;
    DAT_a807d650[port].cnt = 10;
    FUN_a00a73d4(0x1c, DAT_a807db00[port].r4 + 13);
}

static void eq_fail(unsigned char port)
{
    ARR_a807d7e0[port * 400 + 1] = 0;
    FUN_a0096aa4(port);
    FUN_a0096ad8(port);
}

unsigned int Jay_EQ_End(unsigned int param_1)
{
    unsigned char port;
    unsigned char sel;
    unsigned int c;

    port = param_1;
    if (port == 0)
        sel = 2;
    else if (port == 1)
        sel = 3;
    else
        return 0;
    FUN_a00a73ac(0xc, DAT_a807db00[port].r0 + 1);
    FUN_a00a73d4(0x18, DAT_a807db00[port].r4 + 12);
    FUN_a00a73d4(0x19, DAT_a807db00[port].r4 + 12);
    FUN_a009fe60(port);
    if (ARR_a807d7e0[port * 400 + 4] == 1)
        FUN_a009c87c(port);
    c = DAT_a807cc64[sel].b1;
    DAT_a80790c8[port] = 0;
    if (c == 1 && DAT_a807d648[port] == 9) {
        FUN_a00a73ac(0x18, DAT_a807db00[port].r4 + 12);
        FUN_a00a73ac(0x19, DAT_a807db00[port].r4 + 12);
        DAT_a807d650[port].st = 1;
        FUN_a00a73d4(0xb, DAT_a807db00[port].rc + 0x1f);
        FUN_a0073044("PortA Run HDMI21 ModeDet %d \n", 0xde);
        return 1;
    }
    if (DAT_a807cc64[sel].b1 == 1 && ARR_a807d7e0[port * 400 + 1] == 0) {
        eq_done(port);
        if (_DAT_a8078634 & 4)
            FUN_a0073044("[MODEDET]: ## Port%c => Jay_EQ_End [%ld] ##\n\n", (char)(param_1 + 0x41),
                         FUN_a00b2064());
        return 1;
    }
    eq_fail(param_1);
    return 0;
}
