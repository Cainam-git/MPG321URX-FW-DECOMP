/* leon2m FUN_a009f42c @ 0xa009f42c-0xa00a012c (832 words), flags -mcpu=v8 -O3 -g (also matches with -msoft-float).
 * No arguments; called by FUN_a0087430 and FUN_a00a012c (both pass no arguments). It steps the state in
 * _DAT_a802afec on ms timers and port states, counts down the T+0x1a0..0x1a2 timer (b1a2 59..0, then b1a1 - 1) and
 * the 1000 ms aff2 countdown; it reads no refresh rate (details below).
 * What it does (S = DAT_a802cff4 system flags, T = DAT_a802d290 settings record, state = _DAT_a802afec;
 * func_0x4008d594(t) = ms since tick t, FUN_a0147724 / func_0x4008d588 = tick now):
 *   0. return when FUN_a0082c4c() == 1 or S.h4 bits 13-14 are set.
 *   1. ok = every port 0..3 is off (FUN_a0080320(i) == 0) or in port state 4 (FUN_a0143c14(i) == 4). ok and
 *      FUN_a0082c4c() == 0: state 0 / 0x10d with S.h4 bit 9 -> FUN_a008d2e0, FUN_a008ad20, (DAT_a802d284 == 0x3f)
 *      FUN_a008b2bc, afe8 = now; state 0x113 and more than 17000 ms since afe8 -> (S.h4 bit 15: set bit 10,
 *      FUN_a00808ac(4, 0)), state 0, FUN_a00b5080(), state 0x114.
 *   2. state 0x111: every 100 ms d03a = now.
 *   3. port 0 in state 10, S.h0 bit 8, FUN_a0143e70(0) == 0 and one of T.b190, T+0xa8 bit 12, T.b1a0 (timer
 *      hours), T+0xac bit 22: state 0 -> FUN_a00a5e68(1), state 0x106 (and d036 = now if S.h0 bit 14); state 0x106
 *      -> FUN_a00a5e68(0), (T.b17b == 2) FUN_a00ba184(0), d03c = now, FUN_a00d47b0(); state 0x108 and T.b17b == 2
 *      -> FUN_a00ba184(0).
 *   4. S.h0 bit 14 (timer running): every 1000 ms count the T+0x1a0..0x1a2 timer (b1a2 seconds-like 59..0, then
 *      b1a1 - 1) while b1a0 != 0 and b1a1/b1a2 not both 0; clear bit 14 when b1a1 = b1a2 = 0.
 *   5. port 0 in state 10, S.h0 bit 8, low half of state != 0x10a, T.h1f6 != 0x55aa (else d038 = now, aff0 = 0):
 *      after 30000 ms S.hc = 1; after 29000 ms with S.hc == 0 once FUN_a00daa7c(); with S.hc != 0: S.h10 = index
 *      from FUN_a0127a08 against FUN_a0145af8(0xd) (or (0xd value * 60 + 0xb value) / 20 when FUN_a0145af8(0x10)),
 *      then (no FUN_a012792c / FUN_a0127944 / S.h14 bit 15) a FUN_a00b1654(x, y) change -> aff1,
 *      FUN_a00b1700(aff1, 3), state 0x10f, d03c = now; else FUN_a009f184().
 *   6. state switch: 0/0x111/0x113/0x112/0x115 (0x112 tested twice in the fw chain) -> d03c = now, FUN_a00d47b0;
 *      0x10e, 0x10d (DAT_a802d465 != 0), 0x10b (> 3000 ms) -> (S.h4 bit 15: bit 10, FUN_a00808ac(4, 0)), state 0,
 *      FUN_a00b5080; 0x10c: d03c refresh after 100 ms; 0x116: after T.b0c seconds T.b1aa = 0, FUN_a009b59c; 0x10f
 *      (> 3000 ms): as 0x10b, then S.h0 bit 9 -> clear it, d03c = now, state 0x10f, FUN_a00b8668; 0x10a (> 60000
 *      ms): T+0x1dc bits 31/30 both set -> S.he bit 15 from S.h12 == 5 / S.h10 == 4 and DAT_a8025c56, DAT_a8025c55
 *      2 -> 0, (S.b3f, c55 == 0, he bit 15 clear) c55 = 1, FUN_a00b2d04(); else (bit 31 clear: state 0x35)
 *      FUN_a00b1004(7, state - 0x35); then set bits 31/30, T.b1e5 = T.b1e4 = 0; other states: (<= 0xe5, 100 ms)
 *      FUN_a00b37a4; every 1000 ms: aff2 countdown; states 0x106/0xe1/0xe6/0x41/0x81 with aff2 == 0 ->
 *      0xe1/0xe6/0x41: aff2 = T.b0c, c55 = T.b13e / T.b13f, T.b1a3 = 0/1/2, state 0x108, FUN_a00b5080, 2x
 *      func_0x4008e2a4, FUN_a00a6b98(0/1/2, 1, 0); 0x81: FUN_a009811c, FUN_a00d47b0; any other state: copy the
 *      T.t197/t19b row of T.b1a0 into b1a1/b1a2 (new b1a0), S.h4 bit 15 -> bit 10, FUN_a00db1ac, DAT_a802b08e |=
 *      2, FUN_a00d4998, state 0, FUN_a00b5080, FUN_a0083c20() -> state 0x10c, FUN_a00b87d4.
 *   Refresh rate: nothing here reads the rate. It only reads the per-port state (state 10 / 4 from FUN_a0143c14),
 *   the state in _DAT_a802afec and ms timers; an input mode reaches it only through the port state values.
 * Source form (the exact build depends on each of these):
 *   - int return for FUN_a0127a08; the T+0x1dc word as bit-fields b31/b30; the timer arm tests 'b1a2 != 0' first;
 *     'if (t != afea) if (t != 0)' nested; the 5-state set test is an inlined early-return function in_set().
 *   1. The 1000 ms countdown is 'if (aff2 != 0) aff2--; if (aff2 == 0) { ... }' with no early return. With 'if
 *      (aff2 != 0 && --aff2 != 0) return;' predict.c gives the return edge PRED_EARLY_RETURN (67 %), the rest of
 *      the default path gets about half the frequency, and bb-reorder's triangle rule (bb-reorder.c:596, integer
 *      frequencies: 2 * freq(arm) >= EDGE_FREQUENCY(skip)) then fails, so both S.h4 bit-15 arms go out of line.
 *      Same code, only the prediction changes.
 *   2. The S.he bit-15 value is one '||' condition '(h12 == 5 && c56 == 1) || (h10 == 4 && c56 == 0)' (the fw has
 *      one shared set path).
 *   3. S.h0 is a bit-field word (b14 timer running, b9, b8). With the mask form the 0x4000 constant of the 0x106
 *      arm is materialised next to its use; the bit-field form gives the fw 'sethi 0x4000' in the first call's
 *      delay slot (call-saved %l0).
 *   4. The 0x10a arm is written 'if (!(b31 && b30)) { 0x35 / FUN_a00b1004 path } else { he.b15 path }', and the
 *      in-set test 'if (!in_set(AFEC)) { t-row path } else { 0xe1/0xe6/0x41/0x81 arms }'. rnreg LRU ticks follow
 *      the source arm order; the other order breaks the rename chain from the h12 == 5 test on, and reorg then
 *      deletes the 0x81 test's reloads as redundant (the fw reloads aff2 and the state in every test).
 *   5. Statement orders (all stores are to different RAM bytes, so the order is free in C): timer else-arm 'b1a2 =
 *      0x3b' before 'b1a1--'; 0xe1 arm c55 before aff2; b1e4 before b1e5.
 * Register-allocation forms (the last 38 words):
 *   6. aff2 HIGH (fw %o2 from 0xa009f84c; %o1 with other statement orders): local-alloc gives the 0xe6 arm's b0c
 *      value (aff2 = b0c) %o2, a hard conflict for the global aff2 HIGH pseudo, which then takes %o1. The 0xe6 arm
 *      'aff2 = b0c; b1a3 = 1; c55 = b13f; AFEC = 0x108;' and the 0xe1 arm 'aff2 = b0c; c55 = b13e; AFEC = 0x108;
 *      b1a3 = 0;' give the fw arms and free %o2 (all stores go to different RAM bytes, so the order is free in C;
 *      sched2 puts them back in the fw order). The same orders give the afea sethi order at 0xa009f8a0 (reorg
 *      fills the in-set branch delay slot with the first insn whose register is dead at the target: with aff2 HIGH
 *      in %o2 that is the afea sethi, not the SET sethi).
 *   7. t-row (row address fw %i2, t fw %o3, t19b value fw %o4): local-alloc of the t-row block sorts its
 *      quantities by int(floor_log2(refs) * freq / (death - birth) * 10), ties by birth order (local-alloc.c
 *      QTY_CMP_PRI, qty_compare_1); each takes the first free of %g1 %o5 %o4 %o3 .. over a +-2 widened lifetime.
 *      With the stores 'b1a1 = t197[t]; b1a2 = t19b[t]; afea = t;' sched1 gives the order lduh c4000 ior ld19b
 *      ld197 st1a2 stafea st1a1 sth, where the t19b value gets %o4 before the row address, which then gets %o3
 *      (and t prefers it). That order alone makes the t byte (QI) live 16 insns instead of 15 (global priority 1 <
 *      2 of the SET pointer, so the two swap %o1/%o2); reading afea into 'unsigned char a' before the t load ('if
 *      (t != a)') keeps t's life at 15 insns, so t is allocated first (%o2) and the SET pointer gets %o1, as in
 *      the fw.
 * Compiler aids: none. No volatile (all RAM globals).
 */
struct Sys {
    struct { unsigned short b15 : 1, b14 : 1, x10 : 4, b9 : 1, b8 : 1, lo : 8; } s0;
    unsigned short h2;
    struct { unsigned short b15 : 1, m : 2, b12 : 1, b11 : 1, b10 : 1, b9 : 1, b8 : 1, b7 : 1, low : 7; } h4;
    unsigned short h6, h8, ha;
    unsigned short hc;
    struct { unsigned short b15 : 1, rest : 15; } he;
    unsigned short h10, h12;
    struct { unsigned short b15 : 1, rest : 15; } h14;
    unsigned char pad16[0x3f - 0x16];
    unsigned char b3f;
};
struct Set {
    unsigned char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d[0xa8 - 0xd];
    unsigned int wa8, wac;
    unsigned char padb0[0x13e - 0xb0];
    unsigned char b13e, b13f;
    unsigned char pad140[0x17b - 0x140];
    unsigned char b17b;
    unsigned char pad17c[0x190 - 0x17c];
    unsigned char b190;
    unsigned char pad191[0x197 - 0x191];
    unsigned char t197[4];
    unsigned char t19b[4];
    unsigned char pad19f;
    union { unsigned int w; unsigned char b[4]; } u1a0;
    unsigned char pad1a4[0x1aa - 0x1a4];
    unsigned char b1aa;
    unsigned char pad1ab[0x1dc - 0x1ab];
    struct { unsigned int b31 : 1, b30 : 1, rest : 30; } w1dc;
    unsigned char b1e0[4];
    unsigned char b1e4, b1e5;
    unsigned char pad1e6[0x1f6 - 0x1e6];
    unsigned short h1f6;
};
extern struct Sys DAT_a802cff4;
extern struct Set DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802afea, DAT_a802aff0, DAT_a802aff1, DAT_a802d284, DAT_a802d465, DAT_a802b08e;
extern unsigned char DAT_a8025c55, DAT_a8025c56;
extern unsigned short DAT_a802afe8, DAT_a802aff2, DAT_a802d036, DAT_a802d038, DAT_a802d03a, DAT_a802d03c;

extern unsigned char FUN_a0082c4c(void);
extern unsigned char FUN_a0080320(unsigned char port);
extern unsigned char FUN_a0143c14(unsigned char ch);
extern unsigned char FUN_a0143e70(unsigned char ch);
extern unsigned short FUN_a0147724(void);
extern unsigned short FUN_a0145af8(unsigned int id);
extern int FUN_a0127a00(void);
extern int FUN_a0127a08(unsigned char i);
extern unsigned char FUN_a012792c(void);
extern unsigned char FUN_a0127944(void);
extern unsigned char FUN_a00b1654(unsigned char a, unsigned char b);
extern void FUN_a00b1700(unsigned char v, unsigned char mode);
extern void FUN_a00b1004(unsigned char a, unsigned char b);
extern unsigned char FUN_a0083c20(void);
extern void FUN_a00808ac(int, int);
extern void FUN_a00a5e68(unsigned char on);
extern void FUN_a00ba184(unsigned char v);
extern void FUN_a00a6b98(unsigned char a, unsigned char b, unsigned char c);
extern void FUN_a008d2e0(void);
extern void FUN_a008ad20(void);
extern void FUN_a008b2bc(void);
extern void FUN_a00b5080(void);
extern void FUN_a00d47b0(void);
extern void FUN_a00daa7c(void);
extern void FUN_a009f184(void);
extern void FUN_a00b2d04(void);
extern void FUN_a00db1ac(void);
extern void FUN_a00d4998(void);
extern void FUN_a00b87d4(void);
extern void FUN_a00b37a4(void);
extern void FUN_a009b59c(void);
extern void FUN_a009811c(void);
extern void FUN_a00b8668(void);
extern void func_0x4008e2a4(void);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);

#define AFEC _DAT_a802afec
static int in_set(unsigned int s)
{
    if (s == 0x106)
        return 1;
    if (s == 0xe1)
        return 1;
    if (s == 0xe6)
        return 1;
    if (s == 0x41)
        return 1;
    if (s == 0x81)
        return 1;
    return 0;
}
#define SYS DAT_a802cff4
#define SET DAT_a802d290

void FUN_a009f42c(void)
{
    unsigned char ok, i;

    if (FUN_a0082c4c() == 1)
        return;
    if (SYS.h4.m)
        return;
    ok = 1;
    for (i = 0; i < 4; i++) {
        if (FUN_a0080320(i) && FUN_a0143c14(i) != 4) {
            ok = 0;
            break;
        }
    }
    if (ok && !FUN_a0082c4c()) {
        if ((AFEC == 0 || AFEC == 0x10d) && SYS.h4.b9) {
            FUN_a008d2e0();
            FUN_a008ad20();
            if (DAT_a802d284 == 0x3f)
                FUN_a008b2bc();
            DAT_a802afe8 = FUN_a0147724();
        }
        if (AFEC == 0x113 && func_0x4008d594(DAT_a802afe8) > 17000) {
            if (SYS.h4.b15) {
                SYS.h4.b10 = 1;
                FUN_a00808ac(4, 0);
            }
            AFEC = 0;
            FUN_a00b5080();
            AFEC = 0x114;
        }
    }
    if (AFEC == 0x111 && func_0x4008d594(DAT_a802d03a) > 100)
        DAT_a802d03a = FUN_a0147724();
    if (FUN_a0143c14(0) == 10 && SYS.s0.b8 && !FUN_a0143e70(0)
        && (SET.b190 || (SET.wa8 & 0x1000) || SET.u1a0.b[0] || (SET.wac & 0x400000))) {
        if (AFEC == 0) {
            func_0x4008e2a4();
            func_0x4008e2a4();
            AFEC = 0x106;
            FUN_a00a5e68(1);
            if (SYS.s0.b14)
                DAT_a802d036 = FUN_a0147724();
        } else if (AFEC == 0x106) {
            FUN_a00a5e68(0);
            if (SET.b17b == 2)
                FUN_a00ba184(0);
            DAT_a802d03c = FUN_a0147724();
            FUN_a00d47b0();
        } else if (AFEC == 0x108 && SET.b17b == 2)
            FUN_a00ba184(0);
    }
    if (SYS.s0.b14) {
        if (func_0x4008d594(DAT_a802d036) > 1000) {
            DAT_a802d036 = FUN_a0147724();
            if (SET.u1a0.b[0] && (SET.u1a0.w & 0xffff00)) {
                if (SET.u1a0.b[2] != 0)
                    SET.u1a0.b[2]--;
                else {
                    SET.u1a0.b[2] = 0x3b;
                    SET.u1a0.b[1]--;
                }
            }
        }
        if ((SET.u1a0.w & 0xffff00) == 0)
            SYS.s0.b14 = 0;
    }
    if (FUN_a0143c14(0) == 10 && SYS.s0.b8 && (unsigned short)AFEC != 0x10a && SET.h1f6 != 0x55aa) {
        if (func_0x4008d594(DAT_a802d038) > 30000 && SYS.hc == 0)
            SYS.hc = 1;
        if (func_0x4008d594(DAT_a802d038) > 29000 && SYS.hc == 0 && DAT_a802aff0 == 0) {
            FUN_a00daa7c();
            DAT_a802aff0 = 1;
        }
        if (SYS.hc != 0) {
            unsigned char x, y;

            if (FUN_a0145af8(0x10) == 0) {
                unsigned char n;
                for (n = 0; n < FUN_a0127a00(); n++)
                    if (FUN_a0127a08(n) > FUN_a0145af8(0xd))
                        break;
                SYS.h10 = n;
            } else
                SYS.h10 = (FUN_a0145af8(0xd) * 60 + FUN_a0145af8(0xb)) / 20;
            if (!FUN_a012792c() && !FUN_a0127944() && !SYS.h14.b15) {
                x = FUN_a0145af8(0xd);
                y = FUN_a0145af8(0xb);
                if (FUN_a00b1654(x, y) != DAT_a802aff1 && FUN_a00b1654(x, y)) {
                    DAT_a802aff1 = FUN_a00b1654(x, y);
                    FUN_a00b1700(DAT_a802aff1, 3);
                    AFEC = 0x10f;
                    DAT_a802d03c = func_0x4008d588();
                } else
                    FUN_a009f184();
            }
        }
    } else {
        DAT_a802d038 = FUN_a0147724();
        DAT_a802aff0 = 0;
    }
    if (AFEC == 0 || AFEC == 0x111 || AFEC == 0x113 || AFEC == 0x112 || AFEC == 0x115 || AFEC == 0x112) {
        DAT_a802d03c = FUN_a0147724();
        FUN_a00d47b0();
    } else if (AFEC == 0x10e) {
        if (DAT_a802d465) {
            if (SYS.h4.b15) {
                SYS.h4.b10 = 1;
                FUN_a00808ac(4, 0);
            }
            AFEC = 0;
            FUN_a00b5080();
        }
    } else if (AFEC == 0x10d) {
        if (DAT_a802d465) {
            if (SYS.h4.b15) {
                SYS.h4.b10 = 1;
                FUN_a00808ac(4, 0);
            }
            AFEC = 0;
            FUN_a00b5080();
        }
    } else if (AFEC == 0x10c) {
        if (func_0x4008d594(DAT_a802d03c) > 100)
            DAT_a802d03c = func_0x4008d588();
    } else if (AFEC == 0x10b) {
        if (func_0x4008d594(DAT_a802d03c) > 3000) {
            if (SYS.h4.b15) {
                SYS.h4.b10 = 1;
                FUN_a00808ac(4, 0);
            }
            AFEC = 0;
            FUN_a00b5080();
        }
    } else if (AFEC == 0x116) {
        if (func_0x4008d594(DAT_a802d03c) > SET.b0c * 1000) {
            SET.b1aa = 0;
            FUN_a009b59c();
        }
    } else if (AFEC == 0x10f) {
        if (func_0x4008d594(DAT_a802d03c) > 3000) {
            if (SYS.h4.b15) {
                SYS.h4.b10 = 1;
                FUN_a00808ac(4, 0);
            }
            AFEC = 0;
            FUN_a00b5080();
            if (SYS.s0.b9) {
                SYS.s0.b9 = 0;
                DAT_a802d03c = func_0x4008d588();
                AFEC = 0x10f;
                FUN_a00b8668();
            }
        }
    } else if (AFEC == 0x10a) {
        if (func_0x4008d594(DAT_a802d03c) > 60000) {
            if (!(SET.w1dc.b31 && SET.w1dc.b30)) {
                if (!SET.w1dc.b31)
                    AFEC = 0x35;
                FUN_a00b1004(7, AFEC - 0x35);
            } else {
                if ((SYS.h12 == 5 && DAT_a8025c56 == 1) || (SYS.h10 == 4 && DAT_a8025c56 == 0))
                    SYS.he.b15 = 1;
                else
                    SYS.he.b15 = 0;
                if (DAT_a8025c55 == 2)
                    DAT_a8025c55 = 0;
                if (SYS.b3f && DAT_a8025c55 == 0 && !SYS.he.b15)
                    DAT_a8025c55 = 1;
                FUN_a00b2d04();
            }
            SET.w1dc.b31 = 1;
            SET.w1dc.b30 = 1;
            SET.b1e4 = 0;
            SET.b1e5 = 0;
        }
    } else {
        if (AFEC <= 0xe5 && func_0x4008d594(DAT_a802d03a) > 100) {
            DAT_a802d03a = FUN_a0147724();
            FUN_a00b37a4();
        }
        if (func_0x4008d594(DAT_a802d03c) > 1000) {
            DAT_a802d03c = FUN_a0147724();
            if (DAT_a802aff2 != 0)
                DAT_a802aff2--;
            if (DAT_a802aff2 == 0) {
                if (!in_set(AFEC)) {
                    unsigned char a = DAT_a802afea;
                    unsigned char t = SET.u1a0.b[0];
                    if (t != a)
                    if (t != 0) {
                        SET.u1a0.b[1] = SET.t197[t];
                        SET.u1a0.b[2] = SET.t19b[t];
                        DAT_a802afea = t;
                        SYS.s0.b14 = 1;
                    }
                    if (SYS.h4.b15) {
                        SYS.h4.b15 = 0;
                        SYS.h4.b10 = 1;
                        FUN_a00808ac(4, 0);
                    }
                    FUN_a00db1ac();
                    DAT_a802b08e |= 2;
                    FUN_a00d4998();
                    if (SYS.h4.b15) {
                        SYS.h4.b10 = 1;
                        FUN_a00808ac(4, 0);
                    }
                    AFEC = 0;
                    FUN_a00b5080();
                    if (FUN_a0083c20()) {
                        AFEC = 0x10c;
                        FUN_a00b87d4();
                    }
                } else {
                    if (DAT_a802aff2 == 0 && AFEC == 0xe1) {
                        DAT_a802aff2 = SET.b0c;
                        DAT_a8025c55 = SET.b13e;
                        AFEC = 0x108;
                        SET.u1a0.b[3] = 0;
                        FUN_a00b5080();
                        func_0x4008e2a4();
                        func_0x4008e2a4();
                        FUN_a00a6b98(0, 1, 0);
                    } else if (DAT_a802aff2 == 0 && AFEC == 0xe6) {
                        DAT_a802aff2 = SET.b0c;
                        SET.u1a0.b[3] = 1;
                        DAT_a8025c55 = SET.b13f;
                        AFEC = 0x108;
                        FUN_a00b5080();
                        func_0x4008e2a4();
                        func_0x4008e2a4();
                        FUN_a00a6b98(1, 1, 0);
                    } else if (DAT_a802aff2 == 0 && AFEC == 0x41) {
                        DAT_a802aff2 = SET.b0c;
                        SET.u1a0.b[3] = 2;
                        AFEC = 0x108;
                        FUN_a00b5080();
                        func_0x4008e2a4();
                        func_0x4008e2a4();
                        FUN_a00a6b98(2, 1, 0);
                    } else if (DAT_a802aff2 == 0 && AFEC == 0x81) {
                        FUN_a009811c();
                        FUN_a00d47b0();
                    }
                }
            }
        }
    }
}
