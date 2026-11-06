/* leon2s FSM_MODE_DETECT_STANDBY @ 0xa00977e8-0xa0097ed0, flags -mcpu=v8 -Os -g.
 * One call for port index 'port' (the name FSM_MODE_DETECT_STANDBY comes from the firmware string s_a0069b78).
 * Data: register block pointer DAT_a807db00[p].r0 (0x34-byte entries); stored record DAT_a807d7e0[p]
 * (400-byte entries: b6 at +6, b19 at +0x19, htot/vtot/de/deline halfwords at +0x1a..+0x20); state entry
 * DAT_a807d650[port] (24 bytes: state word +0, counter byte +5, bytes +6 and +9); shift byte DAT_a80790a8[p];
 * limit byte DAT_a8078648[p]; retry byte DAT_a80790e0[p]; DAT_a807cc64[sel] (24 bytes: b1 at +1, h8 at +8).
 *   sel = 3 for port 1, else 2. FUN_a00a73d4(0xc, r0 + 1); htot = (r0[0x38/4] >> 16) << shift,
 *   vtot = r0[0x3c/4], de = (r0[0x4c/4] >> 16) << shift, deline = r0[0x50/4]; clk = FUN_a0097680(p, 0);
 *   prints the new (s_a00699c8) and the stored values (s_a0069a08). Stored htot 0x6b4 with new htot 0x35a and
 *   both vtot values 0x106..0x107: stored htot = new htot. FUN_a00974ec(p).
 *   Match when (FUN_a00a03c8(p) == 0, b6 != 0 or |vtot diff| <= 5, |de diff| <= 1, |deline diff| <= 1, deline,
 *   de, stored htot and stored vtot nonzero) or (FUN_a00a03c8(p) == 1, b6 != 0 or |vtot diff| <= 5,
 *   |deline diff| <= 1, deline != 0, |de diff| <= 1): counter++, print s_a0069a48 when bit 2 of DAT_a8078634.
 *   Otherwise counter = 0; FUN_a00a7408(0xb, r0 + 2) != 0: state = 0, print s_a0069a78. Else
 *   FUN_a007517c(sel) != 0: FUN_a0077e68(sel, 0) (print s_a0069aa0 under bit 2); else when ++retry > 1:
 *   FUN_a0077e68(sel, 1) (print s_a0069ad8 under bit 2) and retry = 0; then state = 0,
 *   DAT_a807cc64[sel].b1 = 0, print s_a0069b08.
 *   The stored record gets the new four values. diff = |FUN_a00a2750(p) - clk|, stable when diff <= 0x28;
 *   clk in 101..0x4587: FUN_a00977cc(p, clk). Not stable: print s_a0069b58 with FUN_a00a2750(p), and
 *   counter = 0 when counter > 3 and diff > 500.
 *   counter > limit and stable: when ARR_a807d680[p][1] != 0 and
 *   |(((FUN_a00a2750(p) * b19) >> 3) << ((r0[2] & 0xc0) >> 6)) - h8 * 10| > 500: print s_a0069b78 (bit 2),
 *   state = 0, return 1. Otherwise FUN_a0077e68(sel & 3, 0), retry = 0, state = 6, byte +6 = 10,
 *   byte +9 = 0xf, print s_a0069bd0 with FUN_a00a2750(p), return 1. Else return 0.
 * Source form: an unsigned int parameter copied into the u8 local port ('port = param_1;'), as in the sibling
 *   DRV_HDMI_ModeDetect_FSM_FRL_Chk; sel = 2, then 3 when port_is_1(port), a static helper with the body of the
 *   firmware's own FUN_a008f4d0 ('r = 0; if (port == 1) r = 1; return r & 1;'), inlined (fw 0xa00977f0
 *   'xor; cmp; addx; mov 3; sub' and the copy into sel); the register block read as DAT_a807db00[port].r0[...]
 *   in each expression; the prints pass (char)(port + 'A'); the limit test written 'counter > lim'.
 */
struct port_rec {
    volatile unsigned int *r0;
    unsigned char _04[0x34 - 4];
};
struct eq_state {
    unsigned int st;
    unsigned char _4;
    unsigned char cnt;
    unsigned char b6;
    unsigned char _7[2];
    unsigned char b9;
    unsigned char _a[0x18 - 0xa];
};
struct mode_rec {
    unsigned char _00[6];
    unsigned char b6;
    unsigned char _07[0x19 - 7];
    unsigned char b19;
    unsigned short htot;
    unsigned short vtot;
    unsigned short de;
    unsigned short deline;
    unsigned char _22[400 - 0x22];
};
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[6];
    unsigned short h8;
    unsigned char _a[0x18 - 0xa];
};

extern struct port_rec DAT_a807db00[];
extern struct eq_state DAT_a807d650[];
extern struct mode_rec DAT_a807d7e0[];
extern struct sel_rec DAT_a807cc64[];
extern unsigned char ARR_a807d680[][0xb0];
extern unsigned char DAT_a8078648[];
extern unsigned char DAT_a80790a8[];
extern unsigned char DAT_a80790e0[];
extern unsigned int DAT_a8078634;
extern const char s_a00699c8[], s_a0069a08[], s_a0069a48[], s_a0069a78[], s_a0069aa0[], s_a0069ad8[],
    s_a0069b08[], s_a0069b58[], s_a0069b78[], s_a0069bd0[];

extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern unsigned short FUN_a0097680(unsigned char, unsigned char);
extern int FUN_a0073044(const char *, ...);
extern int abs(int);
extern void FUN_a00974ec(unsigned char);
extern unsigned char FUN_a00a03c8(unsigned char);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern unsigned char FUN_a007517c(unsigned int);
extern void FUN_a0077e68(unsigned int, unsigned char);
extern unsigned short FUN_a00a2750(unsigned int);
extern void FUN_a00977cc(unsigned char, unsigned short);

static unsigned char port_is_1(unsigned char port)
{
    unsigned char r = 0;
    if (port == 1)
        r = 1;
    return r & 1;
}

int FSM_MODE_DETECT_STANDBY(unsigned int param_1)
{
    unsigned char port;
    unsigned char sel;
    unsigned char stable;
    unsigned char lim;
    unsigned short htot, vtot, de, deline;
    unsigned short clk, diff;

    port = param_1;
    stable = 0;
    lim = DAT_a8078648[port];
    sel = 2;
    if (port_is_1(port))
        sel = 3;
    FUN_a00a73d4(0xc, DAT_a807db00[port].r0 + 1);
    htot = (DAT_a807db00[port].r0[0x38 / 4] >> 16) << DAT_a80790a8[port];
    vtot = DAT_a807db00[port].r0[0x3c / 4];
    de = (DAT_a807db00[port].r0[0x4c / 4] >> 16) << DAT_a80790a8[port];
    deline = DAT_a807db00[port].r0[0x50 / 4];
    clk = FUN_a0097680(port, 0);
    FUN_a0073044(s_a00699c8, (char)(port + 'A'), htot, vtot, de, deline);
    FUN_a0073044(s_a0069a08, (char)(port + 'A'), DAT_a807d7e0[port].htot, DAT_a807d7e0[port].vtot,
                 DAT_a807d7e0[port].de, DAT_a807d7e0[port].deline);
    if (DAT_a807d7e0[port].htot == 0x6b4 && htot == 0x35a && (unsigned short)(vtot - 0x106) <= 1 &&
        (unsigned short)(DAT_a807d7e0[port].vtot - 0x106) <= 1)
        DAT_a807d7e0[port].htot = htot;
    FUN_a00974ec(port);
    if ((FUN_a00a03c8(port) == 0 &&
         (DAT_a807d7e0[port].b6 != 0 ||
          (abs(DAT_a807d7e0[port].vtot - vtot) <= 5)) &&
         abs(DAT_a807d7e0[port].de - de) <= 1 &&
         abs(DAT_a807d7e0[port].deline - deline) <= 1 && deline != 0 &&
         de != 0 && DAT_a807d7e0[port].htot != 0 && DAT_a807d7e0[port].vtot != 0) ||
        (FUN_a00a03c8(port) == 1 &&
         (DAT_a807d7e0[port].b6 != 0 ||
          (abs(DAT_a807d7e0[port].vtot - vtot) <= 5)) &&
         abs(DAT_a807d7e0[port].deline - deline) <= 1 && deline != 0 &&
         abs(DAT_a807d7e0[port].de - de) <= 1)) {
        DAT_a807d650[port].cnt++;
        if (DAT_a8078634 & 4)
            FUN_a0073044(s_a0069a48, (char)(port + 'A'), DAT_a807d650[port].cnt);
    } else {
        DAT_a807d650[port].cnt = 0;
        if (FUN_a00a7408(0xb, DAT_a807db00[port].r0 + 2) != 0) {
            DAT_a807d650[port].st = 0;
            FUN_a0073044(s_a0069a78, (char)(port + 'A'));
        } else {
            if (FUN_a007517c(sel)) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044(s_a0069aa0, (char)(port + 'A'));
                FUN_a0077e68(sel, 0);
            } else if (++DAT_a80790e0[port] > 1) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044(s_a0069ad8, (char)(port + 'A'));
                FUN_a0077e68(sel, 1);
                DAT_a80790e0[port] = 0;
            }
            DAT_a807d650[port].st = 0;
            DAT_a807cc64[sel].b1 = 0;
            FUN_a0073044(s_a0069b08, (char)(port + 'A'));
        }

    }
    DAT_a807d7e0[port].deline = deline;
    DAT_a807d7e0[port].htot = htot;
    DAT_a807d7e0[port].vtot = vtot;
    DAT_a807d7e0[port].de = de;

    diff = abs(FUN_a00a2750(port) - clk);
    if (diff <= 0x28)
        stable = 1;
    if ((unsigned short)(clk - 101) <= 0x4522)
        FUN_a00977cc(port, clk);
    if (!stable) {
        FUN_a0073044(s_a0069b58, FUN_a00a2750(port));
        if (DAT_a807d650[port].cnt > 3 && diff > 500)
            DAT_a807d650[port].cnt = 0;
    }
    if (DAT_a807d650[port].cnt > lim && stable) {
        if (ARR_a807d680[port][1] != 0) {
            if (abs((((int)(FUN_a00a2750(port) * DAT_a807d7e0[port].b19) >> 3) << ((DAT_a807db00[port].r0[2] & 0xc0) >> 6)) -
                    DAT_a807cc64[sel].h8 * 10) > 500) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044(s_a0069b78, DAT_a807cc64[sel].h8);
                DAT_a807d650[port].st = 0;
                return 1;
            }
        }
        FUN_a0077e68(sel & 3, 0);
        DAT_a80790e0[port] = 0;
        DAT_a807d650[port].st = 6;
        DAT_a807d650[port].b6 = 10;
        DAT_a807d650[port].b9 = 0xf;

        FUN_a0073044(s_a0069bd0, FUN_a00a2750(port));
        return 1;
    }
    return 0;
}
