/* FUN_a00c601c (leon2s 0xa00c601c-0xa00c6730, 1812 bytes), flags -mcpu=v8 -Os -g.
 * void. Returns at once unless func_0xa0f803d4(n) is nonzero for one of n = 0, 1, 2. Then for p = 0..5 over the
 * 16-byte records DAT_a807d5c8[p] (word 0 with bits 23, 22, 21; bytes +2, +3, +4) and the 0x18-byte records
 * DAT_a8078bb0[k] (word 0 with bits 31, 23, 22, 20; byte +0x14):
 * - for n = 0, 1 (FUN_a00c5fb0(func_0xa0fa1c38(n))) and n = 2 (FUN_a00c5fb0(func_0xa0f958f0(0))), when
 *   func_0xa0f803d4(n) is nonzero: bit n of byte +4 is set when that result equals p and bit 31 of
 *   DAT_a8078bb0[n] is set, else cleared.
 * - byte +4 zero: when it differs from byte +2, FUN_a00c5f18(p, 0), bit 22 cleared, byte +2 = byte +4; next p.
 * - byte +4 differs from byte +2: DAT_a80788d2 |= 1 << p (0x10 for p 4, 0x20 for p 5); p <= 1:
 *   func_0xa0fb7e14(p, 0x305, 7, 1); p 2, 3: window writes 0xa6/0xa4/0xa5 = 9/0/1, func_0xa0fb7e14(p, 0xa7, 4, 1),
 *   0xa6 = 1, func_0xa0fb7e14(p, 0xa7, 3, 1); FUN_a00c5f18(p, 1) when byte +2 is 0; bit 22 cleared; byte +2 =
 *   byte +4.
 * - byte +4 nonzero: the changed flag is set; for k = 0..2 with bit k of byte +4 set and bit 31 of
 *   DAT_a8078bb0[k] set: func_0xa0f93648(5 / 6 / 0) == 1 ors the port bit into DAT_a80788d2 and sets the hit
 *   flag; then bit 23 of DAT_a8078bb0[k] clear: bit 22 of the record cleared, changed flag cleared, loop ends;
 *   else bit 22 of DAT_a8078bb0[k] = bit 23 of the record and, when that is set, bit 22 set, byte +0x14 of
 *   DAT_a8078bb0[2] = byte +3 (p > 3) or 1 when k is 2, and bit 20 = bit 21 of the record.
 * - changed flag set and bit 22 clear: p <= 3: FUN_a00c4e4c(p) nonzero calls FUN_a00c5c30(p), else
 *   FUN_a00c4e70(p) and bit 22 set; p > 3: FUN_a00c55c8(p) and bit 22 set. Bit 22 set: FUN_a00c59e0(p) (p <= 3)
 *   or FUN_a00c5ae4(p). p <= 3: FUN_a00c5c30(p).
 * - hit flag set: bit 22 cleared; p <= 3: when bit 4 of register 0x30 is set, register 5 is written with
 *   v | 9, then v (v = register 5), then 0 to 0x2f and 0x30; p > 3: func_0xa0fb6c98(p - 4, 0x30, 0x80, 1),
 *   0 to 0x2aa / 0x2ab, func_0xa0fb6c98(p - 4, 0x30, 0x80, 0).
 * The changed flag starts at 0 once and keeps its value across p; "p > 5" ends the function after the k loop.
 * Source forms: the k = 0..2 calls are a switch of three calls (merged by cross-jumping); separate byte locals
 * for the port bit of the first and of the second block; the register read func_0xa0fb7e98 is declared with an
 * unsigned char result (the callee returns the low byte) and v is an unsigned char.
 */
struct bits16 {
    unsigned int _31 : 8;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int _0 : 21;
};
struct rec16 {
    union { unsigned int w; struct bits16 f; unsigned char b[4]; } u;
    unsigned char b4;
    unsigned char _5[11];
};
struct bits24 {
    unsigned int _31 : 8;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int _21 : 1;
    unsigned int b20 : 1;
    unsigned int _0 : 20;
};
struct rec24 {
    union { unsigned int w; struct bits24 f; } u;
    unsigned char _4[0x10];
    unsigned char b14;
    unsigned char _15[3];
};
extern struct rec16 DAT_a807d5c8[];
extern struct rec24 DAT_a8078bb0[];
extern unsigned char DAT_a80788d2;
extern unsigned char func_0xa0f803d4(unsigned char);
extern unsigned char func_0xa0fa1c38(unsigned char);
extern unsigned char func_0xa0f958f0(unsigned char);
extern int func_0xa0f93648(unsigned char);
extern unsigned char func_0xa0fb7e98(unsigned char, unsigned short);
extern void func_0xa0fb7dd0(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb7e14(unsigned char, unsigned short, unsigned char, unsigned char);
extern void func_0xa0fb6c00(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char FUN_a00c5fb0(unsigned char);
extern void FUN_a00c5f18(unsigned char, unsigned char);
extern unsigned char FUN_a00c4e4c(unsigned char);
extern void FUN_a00c4e70(unsigned char);
extern void FUN_a00c55c8(unsigned char);
extern void FUN_a00c59e0(unsigned char);
extern void FUN_a00c5ae4(unsigned char);
extern void FUN_a00c5c30(unsigned char);

void FUN_a00c601c(void)
{
    unsigned char changed = 0;
    unsigned char hit;
    unsigned char p, k, m, q, bit;
    unsigned char v;

    if (!func_0xa0f803d4(0) && !func_0xa0f803d4(1) && !func_0xa0f803d4(2))
        return;
    for (p = 0; p <= 5; p++) {
        if (func_0xa0f803d4(0)) {
            if (p == FUN_a00c5fb0(func_0xa0fa1c38(0)) && DAT_a8078bb0[0].u.w >> 31)
                DAT_a807d5c8[p].b4 |= 1;
            else
                DAT_a807d5c8[p].b4 &= ~1;
        }
        if (func_0xa0f803d4(1)) {
            if (p == FUN_a00c5fb0(func_0xa0fa1c38(1)) && DAT_a8078bb0[1].u.w >> 31)
                DAT_a807d5c8[p].b4 |= 2;
            else
                DAT_a807d5c8[p].b4 &= ~2;
        }
        if (func_0xa0f803d4(2)) {
            if (p == FUN_a00c5fb0(func_0xa0f958f0(0)) && DAT_a8078bb0[2].u.w >> 31)
                DAT_a807d5c8[p].b4 |= 4;
            else
                DAT_a807d5c8[p].b4 &= ~4;
        }
        if (DAT_a807d5c8[p].b4 == 0) {
            if (DAT_a807d5c8[p].b4 != DAT_a807d5c8[p].u.b[2]) {
                FUN_a00c5f18(p, 0);
                DAT_a807d5c8[p].u.f.b22 = 0;
                DAT_a807d5c8[p].u.b[2] = DAT_a807d5c8[p].b4;
            }
            continue;
        }
        if (DAT_a807d5c8[p].b4 != DAT_a807d5c8[p].u.b[2]) {
            bit = 1 << p;
            if (p > 3)
                bit = (p == 4) ? 0x10 : 0x20;
            DAT_a80788d2 |= bit;
            if (p <= 1) {
                func_0xa0fb7e14(p, 0x305, 7, 1);
            } else if (p <= 3) {
                func_0xa0fb7dd0(p, 0xa6, 9);
                func_0xa0fb7dd0(p, 0xa4, 0);
                func_0xa0fb7dd0(p, 0xa5, 1);
                func_0xa0fb7e14(p, 0xa7, 4, 1);
                func_0xa0fb7dd0(p, 0xa6, 1);
                func_0xa0fb7e14(p, 0xa7, 3, 1);
            }
            if (DAT_a807d5c8[p].u.b[2] == 0)
                FUN_a00c5f18(p, 1);
            DAT_a807d5c8[p].u.f.b22 = 0;
            DAT_a807d5c8[p].u.b[2] = DAT_a807d5c8[p].b4;
        }
        hit = 0;
        if (DAT_a807d5c8[p].b4 != 0) {
            m = 1 << p;
            changed = 1;
            if (p > 3) {
                if (p == 4)
                    m = 0x10;
                else
                    m = 0x20;
            }
            for (k = 0; k <= 2; k++) {
                if ((DAT_a807d5c8[p].b4 >> k) & 1) {
                    if (DAT_a8078bb0[k].u.w >> 31) {
                        switch (k) {
                        case 0:
                            if (func_0xa0f93648(5) == 1) {
                                DAT_a80788d2 |= m;
                                hit = 1;
                            }
                            break;
                        case 1:
                            if (func_0xa0f93648(6) == 1) {
                                DAT_a80788d2 |= m;
                                hit = 1;
                            }
                            break;
                        case 2:
                            if (func_0xa0f93648(0) == 1) {
                                DAT_a80788d2 |= m;
                                hit = 1;
                            }
                            break;
                        }
                    }
                }
                if ((DAT_a807d5c8[p].b4 >> k) & 1) {
                    if (DAT_a8078bb0[k].u.w >> 31) {
                        if (DAT_a8078bb0[k].u.f.b23 != 1) {
                            DAT_a807d5c8[p].u.f.b22 = 0;
                            changed = 0;
                            break;
                        }
                        DAT_a8078bb0[k].u.f.b22 = DAT_a807d5c8[p].u.f.b23;
                        if (DAT_a807d5c8[p].u.f.b23) {
                            DAT_a8078bb0[k].u.f.b22 = 1;
                            if (k == 2) {
                                if (p > 3)
                                    DAT_a8078bb0[k].b14 = DAT_a807d5c8[p].u.b[3];
                                else
                                    DAT_a8078bb0[k].b14 = 1;
                            }
                            DAT_a8078bb0[k].u.f.b20 = DAT_a807d5c8[p].u.f.b21;
                        }
                    }
                }
            }
        }
        if (p > 5)
            return;
        if (changed && !DAT_a807d5c8[p].u.f.b22) {
            if (p <= 3) {
                if (!FUN_a00c4e4c(p)) {
                    FUN_a00c4e70(p);
                    DAT_a807d5c8[p].u.f.b22 = 1;
                } else {
                    FUN_a00c5c30(p);
                }
            } else {
                FUN_a00c55c8(p);
                DAT_a807d5c8[p].u.f.b22 = 1;
            }
        }
        if (DAT_a807d5c8[p].u.f.b22) {
            if (p <= 3)
                FUN_a00c59e0(p);
            else
                FUN_a00c5ae4(p);
        }
        if (p <= 3)
            FUN_a00c5c30(p);
        if (hit) {
            DAT_a807d5c8[p].u.f.b22 = 0;
            if (p <= 3) {
                if (func_0xa0fb7e98(p, 0x30) & 0x10) {
                    v = func_0xa0fb7e98(p, 5);
                    func_0xa0fb7dd0(p, 5, v | 9);
                    func_0xa0fb7dd0(p, 5, v);
                }
                func_0xa0fb7dd0(p, 0x2f, 0);
                func_0xa0fb7dd0(p, 0x30, 0);
            } else {
                q = p - 4;
                func_0xa0fb6c98(q, 0x30, 0x80, 1);
                func_0xa0fb6c00(q, 0x2aa, 0);
                func_0xa0fb6c00(q, 0x2ab, 0);
                func_0xa0fb6c98(q, 0x30, 0x80, 0);
            }
        }
    }
}
