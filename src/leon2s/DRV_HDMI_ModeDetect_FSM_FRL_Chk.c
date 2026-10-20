/* DRV_HDMI_ModeDetect_FSM_FRL_Chk (leon2s 0xa009723c-0xa009740c, 464 bytes), flags -mcpu=v8 -Os -g.
 * FRL lock check of the mode-detect state machine for one port; returns 0. sel = 3 for port 1, else 2.
 * When bit 0x11 of the register word array r18 + 0x90 is set, prints "FLT_no_retrain, don't do anything"
 * (s_a0069898) and returns. Otherwise prints the function trace, clears DAT_a807d650[port].st unless the state
 * DAT_a807d648[port] is 9; if bit 5 at r18 + 0x1c is set: st = 4, cnt = 10. Else counts byte +0x3b of the
 * 0xb0-byte record ARR_a807d680[port] up to 5; then clears it and either counts the retry byte +0x3c
 * (at most 3 times: prints "FRL lock timeout", sets DAT_a8079048[port] when DAT_a807909c[port] > 700 and
 * bits 24..27 of r18[0x24] equal 2, clears st) or prints "Restart 21_RX", sets the state to 3 and clears
 * DAT_a807cc64[sel] byte +1 and record bytes +2 and +0x3c.
 * Data: DAT_a807db00 = 0x34-byte port records (word +0x18 = register block r18); DAT_a807d650 = 0x18-byte
 * records {word st, byte cnt}.
 * Compiler aid: 'for (;;) break;' before the record byte clears emits no instructions; it ends a scheduling
 * region so that the clears of bytes +2 and +0x3c come out in the firmware's order.
 */
struct port_rec {
    unsigned int _00[6];
    volatile unsigned int *r18;
    unsigned char _1c[0x34 - 0x1c];
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
extern unsigned int DAT_a807d648[];
extern struct eq_state DAT_a807d650[];
extern unsigned char ARR_a807d680[];
extern struct sel_rec DAT_a807cc64[];
extern unsigned int DAT_a807909c[];
extern unsigned char DAT_a8079048[];
extern const char s_a0069898[];
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);

int DRV_HDMI_ModeDetect_FSM_FRL_Chk(unsigned int param_1)
{
    unsigned char port;
    unsigned char sel;
    unsigned char *rec;
    unsigned char n;

    port = param_1;
    sel = 2;
    if (port == 1)
        sel = 3;
    if (FUN_a00a7408(0x11, DAT_a807db00[port].r18 + 0x24) != 0) {
        FUN_a00734c4(s_a0069898);
        return 0;
    }
    FUN_a0073044("Port%c DRV_HDMI_ModeDetect_FSM_FRL_Chk \n", (char)(param_1 + 0x41));
    if (DAT_a807d648[port] != 9)
        DAT_a807d650[port].st = 0;
    if (FUN_a00a7408(5, DAT_a807db00[port].r18 + 7) != 0) {
        DAT_a807d650[port].st = 4;
        DAT_a807d650[port].cnt = 10;
        return 0;
    }
    rec = ARR_a807d680 + port * 0xb0;
    if (++rec[0x3b] == 5) {
        n = rec[0x3c];
        rec[0x3b] = 0;
        if (n <= 2) {
            rec[0x3c] = ++n;
            FUN_a0073044("FRL lock timeout (%d), back to standby\n\n", n);
            if (DAT_a807909c[port] > 700 && ((DAT_a807db00[port].r18[0x24] >> 24) & 0xf) == 2)
                DAT_a8079048[port] = 1;
            DAT_a807d650[port].st = 0;
        } else {
            FUN_a00734c4("Restart 21_RX\n");
            DAT_a807d648[port] = 3;
            DAT_a807cc64[sel].b1 = 0;
            for (;;)
                break;
            rec[2] = 0;
            rec[0x3c] = 0;
        }
    }
    return 0;
}
