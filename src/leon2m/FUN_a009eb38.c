/* leon2m FUN_a009eb38 @ 0xa009eb38-0xa009f184 (1612 bytes), called by FUN_a008a210.
 * Handles one event value ev passed by FUN_a008a210 (S = DAT_a802cff4, T = DAT_a802d290, state = _DAT_a802afec):
 *   1. returns unless some i in 0..3 has FUN_a0080320(i) != 0 and FUN_a0143c14(i) != 0, and returns when bits 13..14
 *      of S+4 are 1.
 *   2. ev bits 6..7 = 0: t = byte table 0x1080b8[ev & 0x3f]; unless t == 0x1e or the pointer
 *      DAT_a80241b0[t] is 0: calls it, d03c = func_0x4008d588(), FUN_a0091094(). Bits 6..7 = 1 continue below,
 *      other values return.
 *   3. state 0x113 / 0x114 with T.b1d5 != 0 and byte S+6 == 1: FUN_a008ad20(), FUN_a008b2bc() when
 *      DAT_a802d284 == 0x3f, afe8 = FUN_a0147724().
 *   4. t = byte table 0x1080f8[ev & 0x3f]; t == 7: calls the pointer _DAT_a8024244 (when non-zero) and
 *      FUN_a0091094(); t == 6 returns.
 *   5. ok = no port i with FUN_a0080320(i) != 0 and FUN_a0143c14(i) != 4. With ok and (bit 9 of T word 0 or
 *      T.b1d5 != 0): when T.h1f6 == 0x55aa, T.b1d6 == 0x55, t in 1..4, FUN_a0146dfc(0) == 0 and T.b1d5 == 0:
 *      T.b1e = FUN_a014459c(2 / 3 / 1 / 0 for t 1 / 2 / 3 / 4), FUN_a00d9238(), FUN_a00808ac(4, 0),
 *      DAT_a802b08e |= 2, return. Else (t != 6) state 0x114: FUN_a008d2e0() and, as for state 0x113,
 *      d03c = func_0x4008d588(), FUN_a00d47b0(), FUN_a008ad20(), FUN_a008b2bc() when d284 == 0x3f,
 *      afe8 = FUN_a0147724(), return. State 0 with bit 14 of T word 0 and T.b1d5 == 0: FUN_a010385c(0),
 *      FUN_a0145fe8(0, 0, 0, 0, 0), FUN_a014512c(1, 0), FUN_a0080bd8(1), bit 7 of S+4 set, state 0x111,
 *      FUN_a008d2f8(), FUN_a008ee6c(0xff, 0). Otherwise the pointer DAT_a802422c[state][t] (6 per state) is
 *      called when non-zero, then d03c = func_0x4008d588(), FUN_a00d47b0(), FUN_a0091094().
 *   6. Without that: state 0 or 0x10d, FUN_a0143c14(0) <= 4, (bit 9 of T word 0 clear or FUN_a0145af8(2) == 1)
 *      and t < 5 or t == 8: FUN_a010385c(0), func_0x4008e2a4(), (bit 15 of S+4: set bit 10, FUN_a00808ac(4, 0)),
 *      state 0, FUN_a00b5080(); when FUN_a0143c14(1) != 10 and the state is still 0: FUN_a0145fe8(0, 0, 0, 0, 0),
 *      FUN_a0143804(0x3ff), FUN_a014512c(1, 1), bit 12 of S+0x18 set, func_0x4008d1a0(400); then
 *      FUN_a0080bd8(1), FUN_a008ee6c(0xff, 0), FUN_a00869b0(4, 8000), FUN_a00869b0(0xb, 10000), state 0xfe,
 *      FUN_a00b5d10(), FUN_a00a45a8(), aff2 = 0x14, bits 14 and 15 of S+0x3e set. Otherwise the
 *      DAT_a802422c[state][t] call as above, with FUN_a00d47b0() skipped when bit 15 of S+0x3e is set.
 * Source form: the two ev bits 6..7 cases are tests of (ev & 0xc0) with the 0x40 case first; the state 0x114 arm
 * jumps into the state 0x113 arm (goto); the redundant 't != 6' test and the four separate FUN_a014459c calls
 * are written as in the firmware.
 * Compiler aid: __builtin_expect on the S+4 bits 13..14 test (emits no instructions; it changes the predicted
 * probability of that early return, which places the ev bits 6..7 = 0 call path and the 0x55aa block in front of the
 * 0x40 path as in the firmware).
 */
struct Sys {
    unsigned short h0;
    unsigned short h2;
    struct { unsigned short b15 : 1, m : 2, b12 : 1, b11 : 1, b10 : 1, b9 : 1, b8 : 1, b7 : 1, low : 7; } h4;
    unsigned char b6, b7;
    unsigned char pad08[0x18 - 0x08];
    unsigned short h18;
    unsigned char pad1a[0x3e - 0x1a];
    struct { unsigned short b15 : 1, b14 : 1, rest : 14; } h3e;
};
struct Set {
    unsigned int w0;
    unsigned char pad04[0x1e - 0x04];
    unsigned char b1e;
    unsigned char pad1f[0x1d5 - 0x1f];
    unsigned char b1d5, b1d6;
    unsigned char pad1d7[0x1f6 - 0x1d7];
    unsigned short h1f6;
};
extern struct Sys DAT_a802cff4;
extern struct Set DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned short DAT_a802afe8, DAT_a802aff2, DAT_a802d03c;
extern unsigned char DAT_a802d284, DAT_a802b08e;
extern const unsigned char DAT_001080b8[], DAT_001080f8[];
extern void (*DAT_a80241b0[])(void);
extern void (*DAT_a802422c[][6])(void);
extern void (*_DAT_a8024244)(void);

extern unsigned char FUN_a0080320(unsigned char port);
extern unsigned char FUN_a0143c14(unsigned char ch);
extern unsigned short FUN_a0147724(void);
extern unsigned short FUN_a0145af8(unsigned int id);
extern unsigned char FUN_a0146dfc(int);
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a008d2e0(void);
extern void FUN_a008ad20(void);
extern void FUN_a008b2bc(void);
extern void FUN_a00b5080(void);
extern void FUN_a00d47b0(void);
extern void FUN_a00d9238(void);
extern void FUN_a00808ac(int, int);
extern void FUN_a010385c(int);
extern void FUN_a0145fe8(int, int, int, int, int);
extern void FUN_a014512c(unsigned int, unsigned int);
extern void FUN_a0080bd8(int);
extern void FUN_a008d2f8(void);
extern void FUN_a008ee6c(int, int);
extern void FUN_a0143804(unsigned short);
extern void FUN_a00869b0(int, int);
extern void FUN_a00b5d10(void);
extern void FUN_a00a45a8(void);
extern void FUN_a0091094(void);
extern void func_0x4008e2a4(void);
extern void func_0x4008d1a0(int ms);
extern unsigned short func_0x4008d588(void);

#define AFEC _DAT_a802afec
#define SYS DAT_a802cff4
#define SET DAT_a802d290

void FUN_a009eb38(unsigned int ev)
{
    unsigned char ok, i, t;

    ok = 1;
    for (i = 0; i < 4; i++) {
        if (FUN_a0080320(i) && FUN_a0143c14(i)) {
            ok = 0;
            break;
        }
    }
    if (ok)
        return;
    if (__builtin_expect(SYS.h4.m == 1, 0))
        return;
    if ((ev & 0xc0) == 0x40) {
        if ((AFEC == 0x113 || AFEC == 0x114) && SET.b1d5 != 0 && SYS.b6 == 1) {
            FUN_a008ad20();
            if (DAT_a802d284 == 0x3f)
                FUN_a008b2bc();
            DAT_a802afe8 = FUN_a0147724();
        }
        t = DAT_001080f8[ev & 0x3f];
        if (t == 7) {
            if (_DAT_a8024244 == 0)
                return;
            _DAT_a8024244();
            FUN_a0091094();
            return;
        }
        if (t == 6)
            return;
        ok = 1;
        for (i = 0; i < 4; i++) {
            if (FUN_a0080320(i) && FUN_a0143c14(i) != 4) {
                ok = 0;
                break;
            }
        }
        if (ok && ((SET.w0 & 0x200) || SET.b1d5 != 0)) {
            if (SET.h1f6 == 0x55aa && SET.b1d6 == 0x55 && (unsigned char)(t - 1) <= 3 && FUN_a0146dfc(0) == 0
                && SET.b1d5 == 0) {
                if (t == 1)
                    SET.b1e = FUN_a014459c(2);
                else if (t == 2)
                    SET.b1e = FUN_a014459c(3);
                else if (t == 3)
                    SET.b1e = FUN_a014459c(1);
                else if (t == 4)
                    SET.b1e = FUN_a014459c(0);
                FUN_a00d9238();
                FUN_a00808ac(4, 0);
                DAT_a802b08e |= 2;
                return;
            }
            if (t != 6) {
                if (AFEC == 0x114) {
                    FUN_a008d2e0();
                    goto l113;
                }
                if (AFEC == 0x113) {
                l113:
                    DAT_a802d03c = func_0x4008d588();
                    FUN_a00d47b0();
                    FUN_a008ad20();
                    if (DAT_a802d284 == 0x3f)
                        FUN_a008b2bc();
                    DAT_a802afe8 = FUN_a0147724();
                    return;
                }
            }
            if (AFEC == 0 && (SET.w0 & 0x4000) && SET.b1d5 == 0) {
                FUN_a010385c(0);
                FUN_a0145fe8(0, 0, 0, 0, 0);
                FUN_a014512c(1, 0);
                FUN_a0080bd8(1);
                SYS.h4.b7 = 1;
                AFEC = 0x111;
                FUN_a008d2f8();
                FUN_a008ee6c(0xff, 0);
                return;
            }
            if (DAT_a802422c[AFEC][t] == 0)
                return;
            DAT_a802422c[AFEC][t]();
            DAT_a802d03c = func_0x4008d588();
            FUN_a00d47b0();
            FUN_a0091094();
            return;
        }
        if ((AFEC == 0 || AFEC == 0x10d) && FUN_a0143c14(0) <= 4
            && (!(SET.w0 & 0x200) || FUN_a0145af8(2) == 1) && (t < 5 || t == 8)) {
            FUN_a010385c(0);
            func_0x4008e2a4();
            if (SYS.h4.b15) {
                SYS.h4.b10 = 1;
                FUN_a00808ac(4, 0);
            }
            AFEC = 0;
            FUN_a00b5080();
            if (FUN_a0143c14(1) != 10 && AFEC == 0) {
                FUN_a0145fe8(0, 0, 0, 0, 0);
                FUN_a0143804(0x3ff);
                FUN_a014512c(1, 1);
                SYS.h18 |= 0x1000;
                func_0x4008d1a0(400);
            }
            FUN_a0080bd8(1);
            FUN_a008ee6c(0xff, 0);
            FUN_a00869b0(4, 8000);
            FUN_a00869b0(0xb, 10000);
            AFEC = 0xfe;
            FUN_a00b5d10();
            FUN_a00a45a8();
            DAT_a802aff2 = 0x14;
            SYS.h3e.b14 = 1;
            SYS.h3e.b15 = 1;
            return;
        }
        if (DAT_a802422c[AFEC][t] == 0)
            return;
        DAT_a802422c[AFEC][t]();
        DAT_a802d03c = func_0x4008d588();
        if (SYS.h3e.b15) {
            FUN_a0091094();
            return;
        }
        FUN_a00d47b0();
        FUN_a0091094();
        return;
    }
    if ((ev & 0xc0) != 0)
        return;
    t = DAT_001080b8[ev & 0x3f];
    if (t == 0x1e)
        return;
    if (DAT_a80241b0[t] == 0)
        return;
    DAT_a80241b0[t]();
    DAT_a802d03c = func_0x4008d588();
    FUN_a0091094();
}
