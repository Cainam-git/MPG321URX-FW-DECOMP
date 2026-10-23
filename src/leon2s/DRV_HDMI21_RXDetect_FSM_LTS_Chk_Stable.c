/* DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable (leon2s 0xa0099ffc-0xa009a41c, 1056 bytes), flags -mcpu=v8 -Os -g.
 * Ports 0 and 1 only (p = (u8)port, sel = 2 / 3); returns 0. Data: DAT_a807db00 = 0x34-byte port records
 * (word +0xc = register block rc, word +0x18 = register block regs), DAT_a807d680 = 0xb0-byte records
 * (bytes b0, b1, b2, b2a, b2c, word state at 0x30), DAT_a807cc64 = 0x18-byte records (byte +1),
 * DAT_a807d648 = state words, DAT_a807d650 = 0x18-byte records (word st).
 * When the state word differs from the record's copy: prints "[HDMI21]: =%s=" with the function name (bit 11
 * of DAT_a8078634), copies it, FUN_a007a050(sel), FUN_a00a73d4(0xb, rc + 0x7c bytes), FUN_a0099560(p),
 * FUN_a0099610(p). Always MAX_CED(p) and MAX_RSED(p). Bit 4 of regs + 0x80 clear (FUN_a00a7408) and
 * DAT_a807cc64[sel] byte +1 not 1: st = 0 and that byte = 1.
 * FUN_a008d800() > 0x82 and bits 8..15 of regs word 0xb0 not 0xff: prints "cut4", state = 3, those bits =
 * 0xff, returns. Bits 24..27 of regs word 0x90 differ from b2: clears DAT_a807cc64[sel] byte +1, prints
 * "FRL_Rate Change at LTS_Stable", state = 3, and when FUN_a008d800() > 0x82 sets bits 8..15 of word 0xb0
 * to 0xff; returns. Bit 0x11 of regs + 0x90 clear and DAT_a8079052 == 0: with b0 == 3 (or 4) bits 24..27 of
 * PHY register 0x2e60 of sel (FUN_a00a7314) equal to 7 (0xf) clear b2a, else b2a counts up with a print;
 * b2a == 3 sets state 3 and clears b2 and DAT_a807cc64[sel] byte +1. b1 == 6: b2c counts up, above 200 it
 * is cleared and FUN_a00798fc(sel), FUN_a00b1794(1), FUN_a00799b8(sel) run.
 * Source forms: after the first early return the records are indexed with 'port & 0xff' (the firmware
 * re-extends the parameter); the 4-lane test is written '!= 0xf' first; DAT_a807d648 is declared unsigned
 * long (alias set: the state store then schedules after the field value in the "cut4" block); the
 * function name is a separate static string.
 */
struct Port {
    volatile unsigned int *regs0;
    unsigned char _04[8];
    volatile unsigned int *rc;
    unsigned char _10[8];
    volatile unsigned int *regs;
    unsigned char _1c[0x34 - 0x1c];
};
struct Rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char _03[0x2a - 3];
    unsigned char b2a;
    unsigned char _2b;
    unsigned char b2c;
    unsigned char _2d[3];
    unsigned int state;
    unsigned char _34[0xb0 - 0x34];
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

extern struct Port DAT_a807db00[];
extern struct Rec DAT_a807d680[];
extern unsigned long DAT_a807d648[];
extern struct eq_state DAT_a807d650[];
extern struct sel_rec DAT_a807cc64[];
extern unsigned char DAT_a8079052;
extern unsigned int DAT_a8078634;
extern const char DAT_a0067868[];

extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a008d800(void);
extern void FUN_a007a050(unsigned char);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a0099560(unsigned char);
extern void FUN_a0099610(unsigned char);
extern void MAX_CED(unsigned char);
extern void MAX_RSED(unsigned char);
extern void FUN_a00798fc(unsigned char);
extern void FUN_a00799b8(unsigned char);
extern void FUN_a00b1794(int);

static const char fn_[] = "DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable";

int DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable(unsigned int port)
{
    unsigned char p = port;
    unsigned char sel;
    unsigned char n;

    if (p == 0)
        sel = 2;
    else if (p == 1)
        sel = 3;
    else
        return 0;
    if (DAT_a807d648[p] != DAT_a807d680[p].state) {
        if (DAT_a8078634 & 0x800)
            FUN_a0073044(DAT_a0067868, fn_);
        DAT_a807d680[p].state = DAT_a807d648[p];
        FUN_a007a050(sel);
        FUN_a00a73d4(0xb, DAT_a807db00[p].rc + 0x1f);
        FUN_a0099560(p);
        FUN_a0099610(p);
    }
    MAX_CED(p);
    MAX_RSED(p);
    if (FUN_a00a7408(4, DAT_a807db00[p].regs + 0x20) == 0 && DAT_a807cc64[sel].b1 != 1) {
        DAT_a807d650[p].st = 0;
        DAT_a807cc64[sel].b1 = 1;
    }
    if (FUN_a008d800() > 0x82 && ((DAT_a807db00[p].regs[0xb0 / 4] >> 8) & 0xff) != 0xff) {
        if (DAT_a8078634 & 0x800)
            FUN_a00734c4("[HDMI21]: FRL_Rate Change/Write detect at LTS_Stable cut4\n");
        DAT_a807d648[p] = 3;
        DAT_a807db00[p].regs[0xb0 / 4] = (DAT_a807db00[p].regs[0xb0 / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }
    if (((DAT_a807db00[port & 0xff].regs[0x90 / 4] & 0xf000000) >> 24) != DAT_a807d680[port & 0xff].b2) {
        DAT_a807cc64[sel].b1 = 0;
        if (DAT_a8078634 & 0x800)
            FUN_a00734c4("[HDMI21]: FRL_Rate Change at LTS_Stable\n");
        DAT_a807d648[port & 0xff] = 3;
        if (FUN_a008d800() > 0x82)
            DAT_a807db00[port & 0xff].regs[0xb0 / 4] = (DAT_a807db00[port & 0xff].regs[0xb0 / 4] & 0xffff00ff) | 0xff00;
        return 0;
    }
    if (FUN_a00a7408(0x11, DAT_a807db00[port & 0xff].regs + 0x24) == 0 && DAT_a8079052 == 0) {
        n = DAT_a807d680[port & 0xff].b0;
        if (n == 3) {
            if (((FUN_a00a7314(sel, 0x2e60) & 0xf000000) >> 24) == 7) {
                DAT_a807d680[port & 0xff].b2a = 0;
            } else {
                DAT_a807d680[port & 0xff].b2a++;
                if (DAT_a8078634 & 0x800)
                    FUN_a0073044("[HDMI21]: Chk stable-Lane lock fail at 3 lane mode %d times\n\n",
                                 DAT_a807d680[port & 0xff].b2a);
            }
        } else if (n == 4) {
            if (((FUN_a00a7314(sel, 0x2e60) & 0xf000000) >> 24) != 0xf) {
                DAT_a807d680[port & 0xff].b2a++;
                if (DAT_a8078634 & 0x800)
                    FUN_a0073044("[HDMI21]: Chk stable-Lane lock fail at 4 lane mode %d times\n\n",
                                 DAT_a807d680[port & 0xff].b2a);
            } else {
                DAT_a807d680[port & 0xff].b2a = 0;
            }
        }
        if (DAT_a807d680[port & 0xff].b2a == 3) {
            DAT_a807d648[port & 0xff] = 3;
            DAT_a807d680[port & 0xff].b2 = 0;
            DAT_a807cc64[sel].b1 = 0;
        }
    }
    if (DAT_a807d680[port & 0xff].b1 == 6) {
        n = DAT_a807d680[port & 0xff].b2c;
        DAT_a807d680[port & 0xff].b2c = n + 1;
        if (n > 200) {
            DAT_a807d680[port & 0xff].b2c = 0;
            FUN_a00798fc(sel);
            FUN_a00b1794(1);
            FUN_a00799b8(sel);
        }
    }
    return 0;
}
