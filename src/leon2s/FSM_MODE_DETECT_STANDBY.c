/* leon2s FSM_MODE_DETECT_STANDBY @ 0xa00977e8-0xa0097ed0, flags -mcpu=v8 -Os -g.
 * One step for input port 'port' (the name FSM_MODE_DETECT_STANDBY comes from the firmware string s_a0069b78).
 * Data: register block pointer DAT_a807db00[p].r0 (0x34-byte entries); stored timing record DAT_a807d7e0[p]
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
 * Source form: K&R definition with an unsigned char parameter (passed as int, zero-extended per use); the
 *   register block read as DAT_a807db00[p].r0[...] in each expression; the first two prints pass
 *   (char)(p + 'A'), the later ones (char)(port + 'A'); 'p = port' again after the match test; sel set
 *   through an int t; the limit test written 'counter > lim'.
 * Compiler aids (no instructions): 'port = p;' after 'p = port;' gives port a second definition, so the
 *   later uses of port zero-extend the raw argument register again, as in the firmware; 'clk = 0;' in the
 *   port 1 arm is a dead store (clk is set from FUN_a0097680 before any use) that keeps the if/else a branch
 *   until after combine, which gives the firmware's 'xor; cmp; addx; mov 3; sub' and the copy into sel.
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

int FSM_MODE_DETECT_STANDBY(port)
unsigned char port;
{
    unsigned char p;
    unsigned char sel;
    int t;
    unsigned char stable;
    unsigned char lim;
    unsigned short htot, vtot, de, deline;
    unsigned short clk, diff;

    p = port;
    stable = 0;
    port = p;
    lim = DAT_a8078648[p];
    if (p == 1) {
        t = 3;
        clk = 0;
    } else
        t = 2;
    sel = t;
    FUN_a00a73d4(0xc, DAT_a807db00[p].r0 + 1);
    htot = (DAT_a807db00[p].r0[0x38 / 4] >> 16) << DAT_a80790a8[p];
    vtot = DAT_a807db00[p].r0[0x3c / 4];
    de = (DAT_a807db00[p].r0[0x4c / 4] >> 16) << DAT_a80790a8[p];
    deline = DAT_a807db00[p].r0[0x50 / 4];
    clk = FUN_a0097680(p, 0);
    FUN_a0073044(s_a00699c8, (char)(p + 'A'), htot, vtot, de, deline);
    FUN_a0073044(s_a0069a08, (char)(p + 'A'), DAT_a807d7e0[p].htot, DAT_a807d7e0[p].vtot,
                 DAT_a807d7e0[p].de, DAT_a807d7e0[p].deline);
    if (DAT_a807d7e0[p].htot == 0x6b4 && htot == 0x35a && (unsigned short)(vtot - 0x106) <= 1 &&
        (unsigned short)(DAT_a807d7e0[p].vtot - 0x106) <= 1)
        DAT_a807d7e0[p].htot = htot;
    FUN_a00974ec(p);
    if ((FUN_a00a03c8(p) == 0 &&
         (DAT_a807d7e0[p].b6 != 0 ||
          (abs(DAT_a807d7e0[p].vtot - vtot) <= 5)) &&
         abs(DAT_a807d7e0[p].de - de) <= 1 &&
         abs(DAT_a807d7e0[p].deline - deline) <= 1 && deline != 0 &&
         de != 0 && DAT_a807d7e0[p].htot != 0 && DAT_a807d7e0[p].vtot != 0) ||
        (FUN_a00a03c8(p) == 1 &&
         (DAT_a807d7e0[p].b6 != 0 ||
          (abs(DAT_a807d7e0[p].vtot - vtot) <= 5)) &&
         abs(DAT_a807d7e0[p].deline - deline) <= 1 && deline != 0 &&
         abs(DAT_a807d7e0[p].de - de) <= 1)) {
        DAT_a807d650[port].cnt++;
        if (DAT_a8078634 & 4)
            FUN_a0073044(s_a0069a48, (char)(port + 'A'), DAT_a807d650[port].cnt);
    } else {
        DAT_a807d650[p].cnt = 0;
        if (FUN_a00a7408(0xb, DAT_a807db00[p].r0 + 2) != 0) {
            DAT_a807d650[p].st = 0;
            FUN_a0073044(s_a0069a78, (char)(port + 'A'));
        } else {
            if (FUN_a007517c(sel)) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044(s_a0069aa0, (char)(port + 'A'));
                FUN_a0077e68(sel, 0);
            } else if (++DAT_a80790e0[p] > 1) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044(s_a0069ad8, (char)(port + 'A'));
                FUN_a0077e68(sel, 1);
                DAT_a80790e0[p] = 0;
            }
            DAT_a807d650[p].st = 0;
            DAT_a807cc64[sel].b1 = 0;
            FUN_a0073044(s_a0069b08, (char)(port + 'A'));
        }

    }
    p = port;
    DAT_a807d7e0[p].deline = deline;
    DAT_a807d7e0[p].htot = htot;
    DAT_a807d7e0[p].vtot = vtot;
    DAT_a807d7e0[p].de = de;

    diff = abs(FUN_a00a2750(p) - clk);
    if (diff <= 0x28)
        stable = 1;
    if ((unsigned short)(clk - 101) <= 0x4522)
        FUN_a00977cc(p, clk);
    if (!stable) {
        FUN_a0073044(s_a0069b58, FUN_a00a2750(p));
        if (DAT_a807d650[p].cnt > 3 && diff > 500)
            DAT_a807d650[p].cnt = 0;
    }
    if (DAT_a807d650[p].cnt > lim && stable) {
        if (ARR_a807d680[p][1] != 0) {
            if (abs((((int)(FUN_a00a2750(p) * DAT_a807d7e0[p].b19) >> 3) << ((DAT_a807db00[p].r0[2] & 0xc0) >> 6)) -
                    DAT_a807cc64[sel].h8 * 10) > 500) {
                if (DAT_a8078634 & 4)
                    FUN_a0073044(s_a0069b78, DAT_a807cc64[sel].h8);
                DAT_a807d650[p].st = 0;
                return 1;
            }
        }
        FUN_a0077e68(sel & 3, 0);
        DAT_a80790e0[p] = 0;
        DAT_a807d650[p].st = 6;
        DAT_a807d650[p].b6 = 10;
        DAT_a807d650[p].b9 = 0xf;

        FUN_a0073044(s_a0069bd0, FUN_a00a2750(p));
        return 1;
    }
    return 0;
}
