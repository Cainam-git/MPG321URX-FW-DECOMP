/* leon2m FUN_a0127c78 @ 0xa0127c78-0xa0129598  OLED panel power / sensing state machine.
 * Flags -mcpu=v8 -O3 -g -msoft-float (also matches without -g); 1608 words.
 * Source form: the two blink parity tests are written 'if (n % 2 == 1)' instead of 'if (n & 1)' (state 1 sub 6,
 * state 2 sub 3; 'n & 1' gives another block order). Same meaning (n is an unsigned char, n % 2 == 1 <=> n & 1). Why
 * it matters: gcc 3.4's branch predictor saw two symmetric 'call' and two symmetric 'early return' hints on that
 * test (50/50), so bb-reorder broke the tie by edge order and put the shared zero-colour block in state 2. 'x % 2 ==
 * 1' reaches the predictor as a compare with the non-zero constant 1 (the modulo is only simplified to btst later,
 * in combine), so the 'opcode values nonequal' heuristic gives 71 % to the colour arm; the zero block then lands
 * after state 1's test like in the firmware.
 *
 * What it does: one step per call (called from the main loop and the OSD/power code: FUN_a0080490, FUN_a0081ea8,
 * FUN_a0085984; no arguments, no return value). Dispatches on the state byte S.state at 0xA802D896 (0..4, else
 * returns). State block S (struct OledState) at 0xA802D896; shared panel state block G = DAT_a802d290; Scff4 =
 * 0xA802CFF4 (bits 0x6000 of its +4 halfword = DPMS/fake-sleep mode, 2 = standby).
 *   state 0 RecoverOFF: recover_mode (FUN_a0127b24 inlined) -> if 2 && S.b9 && !S.b10, run sub 0/1 then enter
 *     state 2 ("Go to OFFSENSING"); else if S.c.h == 1 go state 4.
 *   state 1 ELSENSING: per-second tick (count/blink); sub 0..7 (jump table, bodies 7,6,4,3,2,5,0,1 in the firmware).
 *   state 2 OFFSENSING: per-second tick; sub 0..4.   state 3 QSM: sub 0..3.   state 4 power off: sub 0..2.
 *   Blink (state 1 sub 6, state 2 sub 3): every 500 ms, 7 steps, odd step = colour 0/0/0, even step = 0xff/0xff/0xff
 *     (state 1) or 0xff/0x10/0 (state 2) via FUN_a00da860 (an empty stub in FW.021: retl; nop).
 * ROW-PICKER CALL #1  FUN_a00dac38(0,1,0) @0xA0128E50: state 2, sub 4, >500 ms, S.target==0 ("OFFSENSING DONE !Goto
 *   Display"), and (FUN_a0143db8(0) || G.b1d5). CALL #2 @0xA01290B4: state 1, sub 7, S.target==0 ("ELSENING DONE
 *   !Goto Display"), and FUN_a0143c14(0)==10. Both are the "sensing done -> back to display" step after a power-off
 *   cycle; FUN_a0127c78 never checks the input signal.
 * Globals touched: DAT_a802d896 (S), DAT_a802d290 (G, +0x1d5, +0x1e2..+0x1e7, +0x1f4 word/+0x1f6 half),
 *   DAT_a802cff4 (dpms bits), DAT_a802d888/DAT_a802d890 (I2C buffers of the inlined helpers).
 *
 * Six small helpers of this file are on their own (-mcpu=v8 -O3 -msoft-float):
 *   FUN_a01268cc OLED set OFF Sensing, FUN_a0126938 EL sensing, FUN_a0126a4c OLEDIIC_getTempSensing (needs NO -g),
 *   FUN_a0127a34 OFF-sensing-time-due, FUN_a0127ab8 QSM-record-valid, FUN_a0127b24 recover-mode.
 * The S and G field names are descriptive labels, not firmware names.
 */
/* leon2m FUN_a0127c78 OLED power / panel state machine */
struct OledState {
    unsigned char state;            /* +0x00 */
    unsigned char sub;              /* +0x01 */
    unsigned short t2;              /* +0x02 */
    unsigned short t4;              /* +0x04 */
    unsigned short cnt;             /* +0x06 */
    unsigned char b8, b9, ba, bb;   /* +0x08 */
    union { unsigned char b; unsigned short h; } c;   /* +0x0c */
    unsigned char be;               /* +0x0e */
    unsigned char target;           /* +0x0f */
    unsigned char b10, b11, b12, b13;   /* +0x10 */
    unsigned short h14;             /* +0x14 */
    unsigned char b16;              /* +0x16 */
};
struct G290 {
    unsigned char p000[0x1d5];
    unsigned char b1d5;
    unsigned char p1d6[0x1e2 - 0x1d6];
    unsigned char b1e2, b1e3, b1e4, b1e5, b1e6, b1e7;
    unsigned char p1e8[0x1f4 - 0x1e8];
    union { unsigned int w; struct { unsigned short hi, lo; } h; } u1f4;
};
struct Scff4 { unsigned short h000, h002; unsigned short f15:1, dpms:2, f0:13; };

extern struct OledState DAT_a802d896;
extern struct G290 DAT_a802d290;
extern struct Scff4 DAT_a802cff4;
extern unsigned char DAT_a802d888[2], DAT_a802d890[2];
#define S DAT_a802d896
#define G DAT_a802d290

extern char s_001a4540[], s_001a4568[], s_001a4590[], s_001a45b0[];
extern char s_001a4ac0[], s_001a4ae0[], s_001a4b20[], s_001a4b38[], s_001a4b58[], s_001a4b70[], s_001a4b98[],
    s_001a4bb8[], s_001a4be8[], s_001a4bf8[], s_001a4c08[], s_001a4c18[], s_001a4c28[], s_001a4c48[], s_001a4c60[],
    s_001a4c70[], s_001a4cb0[], s_001a4cd0[], s_001a4ce8[], s_001a4d08[], s_001a4d28[], s_001a4d48[], s_001a4d58[],
    s_001a4d68[], s_001a4d78[], s_001a4da0[], s_001a4dc0[], s_001a4de0[], s_001a4df8[], s_001a4e08[];

extern int FUN_a00df170();
extern unsigned short func_0x4008d594(unsigned short);
extern unsigned short func_0x4008d588(void);
extern void func_0x4008d1a0(int ms);
extern unsigned short FUN_a0145af8(unsigned int);
extern void FUN_a0145c5c(unsigned int, unsigned short);
extern void FUN_a0145360(int);
extern int FUN_a014aed0();
extern void FUN_a014512c(unsigned int, unsigned int);
extern unsigned char FUN_a0143c14(unsigned char);
extern unsigned char FUN_a0143db8(unsigned char);
extern void FUN_a0143da8(void);
extern void FUN_a0148268(int, int);
extern void FUN_a0148500(void);
extern void FUN_a0124850(void), FUN_a0124874(void), FUN_a0124890(void);
extern void FUN_a0124a68(void), FUN_a0124ab0(void), FUN_a0124af8(void), FUN_a0124b40(void);
extern unsigned char FUN_a01248c8(void);
extern unsigned char FUN_a012493c(void);
extern void FUN_a0125988(void), FUN_a0125c34(void), FUN_a0125ca4(void), FUN_a0125cac(void);
extern void FUN_a0125aac(void), FUN_a0125ac8(void);
extern void FUN_a0126704(unsigned char);
extern void FUN_a00da850(int, int, int);
extern void FUN_a00da860(int, int, int);
extern void FUN_a00da868(int, int, int);
extern void FUN_a00d9978(void), FUN_a00d99a8(void);
extern void FUN_a0081ea8(unsigned int);
extern void FUN_a008ee6c(int, int);
extern int FUN_a00fe47c(void);
extern void FUN_a00fe44c(unsigned short);
extern int FUN_a0106ba8();
extern void FUN_a0090fd8(void);
extern unsigned short FUN_a0147724(void);
extern unsigned short FUN_a0147740(unsigned short);
extern void FUN_a014dd10(void);
extern unsigned short FUN_a0147aa0();
extern unsigned short FUN_a0147ae8();
extern void FUN_a00dac38(unsigned int, int, unsigned char);

void FUN_a01268cc(unsigned char v)      /* OLED set OFF Sensing (reg 0xC0) */
{
    DAT_a802d890[0] = 0;
    DAT_a802d890[1] = v;
    if (!FUN_a01248c8()) return;
    FUN_a00df170(s_001a4540, v);
    FUN_a0147aa0(0x60, 2, 0xc0, 5, 0, DAT_a802d890, 2, 1);
}

void FUN_a0126938(unsigned char v)      /* OLED set EL sensing (reg 0xC2) */
{
    DAT_a802d890[0] = 0;
    DAT_a802d890[1] = v;
    if (!FUN_a01248c8()) return;
    FUN_a00df170(s_001a4568, v);
    FUN_a0147aa0(0x60, 2, 0xc2, 5, 0, DAT_a802d890, 2, 1);
}

unsigned short FUN_a0126a4c(void)       /* OLEDIIC_getTempSensing: reg 0x08 * 0.0625 */
{
    unsigned short raw, t;
    if (FUN_a01248c8())
        FUN_a0147ae8(0x60, 2, 8, 5, 0, DAT_a802d888, 2);
    raw = (DAT_a802d888[0] << 8) | DAT_a802d888[1];
    FUN_a00df170(s_001a4590, raw);
    t = raw * 0.0625;
    FUN_a00df170(s_001a45b0, t);
    return t;
}

static void oled_wait500(void)
{
    unsigned short start = FUN_a0147724();
    while (FUN_a0147740(start) < 500)
        FUN_a014dd10();
}

unsigned char FUN_a0127a34(void)        /* OFF-sensing time due */
{
    unsigned char r;
    if (FUN_a0145af8(0x10) == 0) {
        if (FUN_a0145af8(0xd) >= 4) r = 1; else r = 0;
    } else {
        if (FUN_a0145af8(0xd) * 60 + FUN_a0145af8(0xb) > 19) r = 1; else r = 0;
    }
    return r;
}

unsigned char FUN_a0127ab8(void)        /* QSM record valid */
{
    unsigned char f;
    if (G.u1f4.h.lo == 0x55aa && G.b1d5 != 0 && FUN_a0145af8(0x11) == 1) {
        S.b9 = 1;
        S.target = 0;
        f = 1;
    } else
        f = 0;
    return f;
}

unsigned char FUN_a0127b24(void)        /* recover mode: 2 = go OFF sensing */
{
    unsigned char m;
    if (S.ba == 1) m = 2;
    else if (FUN_a0127a34() == 1) m = 2;
    else if (FUN_a0127ab8() == 1 && FUN_a0145af8(0xd) * 60 + FUN_a0145af8(0xb) >= 0) m = 2;
    else m = 0;
    return m;
}

void FUN_a0127c78(void)
{
    unsigned char n; int mode;

    switch (S.state) {
    case 0:
        mode = FUN_a0127b24();
        if (mode == 2 && S.b9 == 1 && S.b10 == 0) {
            if (S.sub == 0) {
                FUN_a00df170(s_001a4d08);
                FUN_a00df170(s_001a4d28, FUN_a0127a34(), S.b9, S.ba, S.b10);
                if (G.b1e4 == 0) G.b1e6 = 1;
                FUN_a014aed0(0x30, &G, 0, 0x1fc);
                FUN_a00fe44c(FUN_a00fe47c() | 0x120);
                FUN_a0106ba8(0);
                FUN_a0106ba8(1);
                FUN_a0106ba8(2);
                FUN_a0106ba8(3);
                S.t4 = func_0x4008d588();
                S.sub = 1;
            } else if (S.sub == 1) {
                FUN_a00df170(s_001a4c28);
                if (func_0x4008d594(S.t4) > 10) {
                    FUN_a0124ab0();
                    FUN_a0124b40();
                    FUN_a00df170(s_001a4c48);
                    FUN_a014512c(0, 0);
                    S.b8 = 1;
                    S.ba = 0;
                    S.sub = 0;
                    S.state = mode;
                    S.t2 = func_0x4008d588();
                    S.t4 = func_0x4008d588();
                    S.b13 = 1;
                    S.h14 = 0;
                    S.b16 = 0;
                    S.cnt = 0;
                    FUN_a0125988();
                    FUN_a00d9978();
                    FUN_a00da850(0, 0, 0);
                    func_0x4008d1a0(5);
                    FUN_a0125c34();
                    FUN_a008ee6c(0xff, 1);
                    FUN_a008ee6c(0x40, 0);
                }
            }
        } else if (S.c.h == 1) {
            FUN_a00df170(s_001a4b38);
            S.state = 4;
            S.sub = 0;
        }
        break;

    case 1:
        if (func_0x4008d594(S.t2) > 1000) {
            S.t2 = func_0x4008d588();
            S.cnt++;
            S.h14++;
            if (S.b13 == 1) {
                if (S.b8 == 1) {
                    FUN_a0124ab0();
                    S.b8 = 0;
                } else {
                    FUN_a0124a68();
                    S.b8 = 1;
                }
            }
            FUN_a00da868(0xd89, S.h14, S.state);
        }
        switch (S.sub) {
        case 0:
            if (G.b1e5 == 0) G.b1e7 = 1;
            FUN_a014aed0(0x30, &G, 0, 0x1fc);
            if (S.cnt > 900) {
                FUN_a0124850();
                S.sub = 1;
                S.cnt = 0;
                FUN_a00df170(s_001a4c18);
            }
            break;
        case 1:
            if (S.cnt > 1) {
                S.cnt = 0;
                FUN_a0124890();
                if (FUN_a0126a4c() > 45) {
                    S.sub = 6;
                    S.target = 2;
                    FUN_a0124ab0();
                    FUN_a0124b40();
                    FUN_a00df170(s_001a4b98, FUN_a0126a4c());
                } else {
                    FUN_a0126704(0);
                    FUN_a0148500();
                    oled_wait500();
                    FUN_a01268cc(1);
                    S.sub = 2;
                    FUN_a00df170(s_001a4d58);
                }
            }
            break;
        case 2:
            if (FUN_a012493c() || S.cnt > 370) {
                S.sub = 3;
                oled_wait500();
                FUN_a0124874();
                S.cnt = 0;
                FUN_a0124a68();
                FUN_a0124b40();
                FUN_a00df170(s_001a4bf8);
            }
            break;
        case 3:
            if (S.cnt > 2100) {
                FUN_a0124850();
                S.sub = 4;
                S.cnt = 0;
                FUN_a00df170(s_001a4be8);
            }
            break;
        case 4:
            if (S.cnt > 1) {
                S.cnt = 0;
                FUN_a0124890();
                if (FUN_a0126a4c() > 45) {
                    S.sub = 6;
                    FUN_a0124ab0();
                    FUN_a0124b40();
                } else {
                    S.sub = 5;
                    FUN_a0126938(1);
                    FUN_a00df170(s_001a4d68);
                }
            }
            break;
        case 5:
            if (FUN_a012493c() || S.cnt > 95) {
                S.t2 = func_0x4008d588();
                S.sub = 6;
                S.cnt = 0;
                FUN_a00df170(s_001a4c08);
            }
            break;
        case 6:
            if (func_0x4008d594(S.t2) > 500) {
                FUN_a0124874();
                S.t2 = func_0x4008d588();
                n = S.b16 + 1;
                if (n < 8) {
                    S.b16 = n;
                    if (n % 2 == 1) FUN_a00da860(0, 0, 0);
                    else FUN_a00da860(0xff, 0xff, 0xff);
                } else {
                    S.sub = 7;
                    S.h14 = 0;
                    S.b16 = 0;
                    if (S.target == 0) FUN_a00d99a8();
                    FUN_a00df170(s_001a4d48);
                }
            }
            break;
        case 7:
            if (S.target == 0) {
                FUN_a00df170(s_001a4ac0);
                FUN_a0145c5c(0xc, 0);
                FUN_a0145c5c(0xa, 0);
                FUN_a0145c5c(0xd, 0);
                FUN_a0145c5c(0xb, 0);
                FUN_a0145c5c(0xe, FUN_a0145af8(0xe) + 1);
                FUN_a0145360(1);
                FUN_a0124b40();
                FUN_a0124a68();
                FUN_a014512c(0, 1);
                G.b1e7 = 0;
                G.b1e3 = 0;
                if (G.b1e5 == 1) G.b1e5 = 0;
                FUN_a014aed0(0x30, &G, 0, 0x1fc);
                if (FUN_a0143c14(0) == 10) {
                    FUN_a00dac38(0, 1, 0);
                    FUN_a0148268(0, 3);
                    FUN_a0148268(1, 3);
                } else {
                    FUN_a014512c(1, 1);
                }
                S.sub = 0;
                S.state = 0;
            } else if (S.target == 1 || S.target == 2) {
                FUN_a00df170(s_001a4bb8);
                FUN_a0145c5c(0xc, 0);
                FUN_a0145c5c(0xa, 0);
                FUN_a0145c5c(0xd, 0);
                FUN_a0145c5c(0xb, 0);
                FUN_a0145c5c(0xe, FUN_a0145af8(0xe) + 1);
                FUN_a0145360(1);
                S.c.b = 1;
                S.state = 0;
                S.sub = 0;
                S.t4 = func_0x4008d588();
                S.b11 = 2;
                G.b1e7 = 0;
                G.b1e3 = 0;
                if (G.b1e5 == 1) G.b1e5 = 0;
                FUN_a014aed0(0x30, &G, 0, 0x1fc);
                if (S.target == 1) {
                    if (DAT_a802cff4.dpms == 2) {
                        FUN_a00df170(s_001a4df8);
                        FUN_a0124ab0();
                        FUN_a0124af8();
                        FUN_a0125ac8();
                        FUN_a0090fd8();
                        FUN_a014512c(0, 1);
                        FUN_a008ee6c(0xff, 0);
                        FUN_a00fe44c(FUN_a00fe47c() & 0xfedf);
                    } else {
                        FUN_a0081ea8(3);
                        FUN_a014512c(0, 1);
                    }
                }
                if (S.target == 2) FUN_a0081ea8(1);
            }
            break;
        }
        break;

    case 2:
        if (func_0x4008d594(S.t2) > 1000) {
            S.t2 = func_0x4008d588();
            S.cnt++;
            S.h14++;
            if (S.b13 == 1) {
                if (S.b8 == 1) {
                    FUN_a0124b40();
                    S.b8 = 0;
                } else {
                    FUN_a0124af8();
                    S.b8 = 1;
                }
            }
            FUN_a00da868(0x226, S.h14, S.state);
        }
        switch (S.sub) {
        case 0: {
            unsigned short lim;
            if (G.u1f4.h.lo == 0x55aa && G.b1d5 != 0 && FUN_a0145af8(0x11) == 1) lim = 5;
            else lim = 180;
            if (S.cnt > lim) {
                FUN_a014512c(1, 1);
                if (FUN_a0126a4c() > 45) {
                    S.target = 2;
                    S.sub = 4;
                    FUN_a00df170(s_001a4b98, FUN_a0126a4c());
                } else {
                    FUN_a0126704(0);
                    FUN_a0148500();
                    func_0x4008d1a0(500);
                    FUN_a0125ca4();
                    FUN_a01268cc(1);
                    S.sub = 1;
                    S.cnt = 0;
                }
            }
            break;
        }
        case 1:
            if (FUN_a012493c() == 1 || S.cnt > 370) {
                S.sub = 2;
                S.t2 = func_0x4008d588();
            }
            break;
        case 2:
            if (!FUN_a012493c() || func_0x4008d594(S.t2) > 1000) {
                FUN_a014512c(0, 1);
                FUN_a0125cac();
                S.t2 = func_0x4008d588();
                S.sub = 3;
            }
            break;
        case 3:
            if (func_0x4008d594(S.t2) > 500) {
                S.t2 = func_0x4008d588();
                n = S.b16 + 1;
                if (n < 8) {
                    S.b16 = n;
                    if (n % 2 == 1) FUN_a00da860(0, 0, 0);
                    else FUN_a00da860(0xff, 0x10, 0);
                } else {
                    S.sub = 4;
                    S.h14 = 0;
                    S.b16 = 0;
                    if (S.target == 0) FUN_a00d99a8();
                }
            }
            break;
        case 4:
            if (func_0x4008d594(S.t2) > 500) {
                S.b13 = 0;
                if (S.target == 0) {
                    FUN_a00df170(s_001a4ce8);
                    if (!FUN_a0143db8(0) && G.b1d5 == 0) {
                        DAT_a802cff4.dpms = 2;
                        S.target = 1;
                    } else {
                        FUN_a0148268(0, 0);
                        FUN_a0148268(1, 0);
                        FUN_a0143da8();
                        FUN_a0145c5c(0xd, 0);
                        FUN_a0145c5c(0xb, 0);
                        if (FUN_a0145af8(0x11) == 0) FUN_a0145c5c(0xf, FUN_a0145af8(0xf) + 1);
                        FUN_a0145c5c(0x11, 0);
                        FUN_a0145360(1);
                        G.b1e6 = 0;
                        G.b1e2 = 0;
                        if (G.b1e4 == 1) G.b1e4 = 0;
                        FUN_a014aed0(0x30, &G, 0, 0x1fc);
                        if (G.u1f4.w & 0x40000000) FUN_a0124a68();
                        else FUN_a0124ab0();
                        FUN_a0124b40();
                        FUN_a014512c(0, 1);
                        FUN_a00dac38(0, 1, 0);
                        if (G.u1f4.h.lo == 0x55aa && G.b1d5 != 0) FUN_a014512c(1, 0);
                        S.sub = 0;
                        S.b9 = 0;
                        S.state = 0;
                        FUN_a008ee6c(0xff, 0);
                        FUN_a00fe44c(FUN_a00fe47c() & 0xfedf);
                    }
                } else if (S.target == 1) {
                    FUN_a00df170(s_001a4d78);
                    FUN_a0145c5c(0xd, 0);
                    FUN_a0145c5c(0xb, 0);
                    if (FUN_a0145af8(0x11) == 0) FUN_a0145c5c(0xf, FUN_a0145af8(0xf) + 1);
                    FUN_a0145c5c(0x11, 0);
                    FUN_a0145360(1);
                    G.b1e6 = 0;
                    G.b1e2 = 0;
                    if (G.b1e4 == 1) G.b1e4 = 0;
                    FUN_a014aed0(0x30, &G, 0, 0x1fc);
                    S.b9 = 0;
                    S.t4 = func_0x4008d588();
                    S.b11 = 2;
                    FUN_a0143da8();
                    if (DAT_a802cff4.dpms == 2) {
                        FUN_a00df170(s_001a4df8);
                        if (FUN_a0143c14(0) > 4) {
                            if (G.u1f4.w & 0x40000000) FUN_a0124a68();
                            else FUN_a0124ab0();
                            FUN_a0124b40();
                            FUN_a0125aac();
                            DAT_a802cff4.dpms = 0;
                        } else {
                            if (G.u1f4.w & 0x40000000) {
                                FUN_a0124ab0();
                                FUN_a0124af8();
                            } else {
                                FUN_a0124ab0();
                                FUN_a0124b40();
                            }
                            FUN_a0125ac8();
                        }
                        FUN_a0090fd8();
                        FUN_a014512c(0, 1);
                        S.sub = 0;
                        S.state = 0;
                        FUN_a008ee6c(0xff, 0);
                        FUN_a00fe44c(FUN_a00fe47c() & 0xfedf);
                    } else {
                        S.sub = 0;
                        S.state = 0;
                    }
                    FUN_a0081ea8(3);
                } else if (S.target == 2) {
                    FUN_a00df170(s_001a4b70);
                    FUN_a0145c5c(0xd, 0);
                    FUN_a0145c5c(0xb, 0);
                    if (FUN_a0145af8(0x11) != 1 || G.u1f4.h.lo != 0x55aa)
                        FUN_a0145c5c(0xf, FUN_a0145af8(0xf) + 1);
                    FUN_a0145c5c(0x11, 0);
                    FUN_a0145360(1);
                    G.b1e6 = 0;
                    G.b1e2 = 0;
                    if (G.b1e4 == 1) G.b1e4 = 0;
                    FUN_a014aed0(0x30, &G, 0, 0x1fc);
                    S.c.b = 1;
                    S.sub = 0;
                    S.state = 0;
                    S.t4 = func_0x4008d588();
                    FUN_a0081ea8(1);
                }
            }
            break;
        }
        break;

    case 3:
        switch (S.sub) {
        case 0:
            if (func_0x4008d594(S.t4) > 10) {
                FUN_a00df170(s_001a4c60);
                FUN_a014512c(1, 1);
                S.t4 = func_0x4008d588();
                S.sub = 1;
            }
            break;
        case 1:
            if (func_0x4008d594(S.t4) > 1000) {
                FUN_a00df170(s_001a4cb0);
                FUN_a01268cc(0);
                S.t4 = func_0x4008d588();
                S.sub = 2;
            }
            break;
        case 2:
            if (func_0x4008d594(S.t4) > 10) {
                FUN_a00df170(s_001a4cd0);
                FUN_a014512c(0, 1);
                S.t4 = func_0x4008d588();
                S.sub = 3;
            }
            break;
        case 3:
            if (func_0x4008d594(S.t4) > 15) {
                S.state = 0;
                S.b10 = 1;
                S.sub = 0;
                if (S.target == 1 || S.target == 2) {
                    FUN_a00df170(s_001a4b58);
                    FUN_a0081ea8(1);
                }
            }
            break;
        }
        break;

    case 4:
        switch (S.sub) {
        case 0:
            FUN_a00df170(s_001a4c70);
            S.sub = 1;
            break;
        case 1:
            FUN_a00df170(s_001a4ae0);
            S.sub = 2;
            S.t4 = func_0x4008d588();
            break;
        case 2:
            if (func_0x4008d594(S.t4) > 10) {
                S.sub = 0;
                S.t4 = func_0x4008d588();
                S.state = 0;
                S.c.b = 1;
                if (S.target == 1) {
                    FUN_a00df170(s_001a4da0, FUN_a0145af8(0xd));
                    mode = FUN_a0127a34();
                    if (mode == 1) {
                        S.b12 = mode;
                        DAT_a802cff4.dpms = 2;
                        FUN_a00df170(s_001a4e08);
                        FUN_a0081ea8(3);
                    } else if (DAT_a802cff4.dpms == 2) {
                        FUN_a00df170(s_001a4dc0);
                    } else {
                        FUN_a0081ea8(3);
                    }
                    FUN_a00df170(s_001a4de0);
                }
                if (S.target == 2) {
                    FUN_a00df170(s_001a4b20);
                    FUN_a0081ea8(1);
                }
            }
            break;
        }
        break;
    }
}
