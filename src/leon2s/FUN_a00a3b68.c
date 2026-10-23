/* FUN_a00a3b68 (leon2s 0xa00a3b68-0xa00a4238, 1744 bytes), flags -mcpu=v8 -Os -g.
 * Port step of the state that prints "DRV_HDMI21_TXDetect_FSM_LTS_3" (port = (u8)param_1). Copies the 8-byte
 * ROM table DAT_a00b4d14 to the stack (FUN_a00b15d8, the copy is not read afterwards). If ARR_a807db6c[port] !=
 * ARR_a807873c[port]: prints DAT_a006bb98 with port and copies the word. n = 3 when ARR_a80791fc[port] < 3,
 * else 4. Byte counter ARR_a80791e8[port] is incremented; when its old value is > 200, ARR_a80791a8[port] == 0 and
 * ARR_a8078728[port] == 1: prints the "LTS3 MAX timeout" line, db6c[port] = 6, counter = 0.
 * If (u8)FUN_a0091bac(port) == 0: prints "TX setting is not ready" and returns 0. st = FUN_a0091d64(port, 0x10).
 * st bit 3: r = FUN_a0091d64(port, 0x35), printed with r & 0x80 and r & 0x20; DAT_a80791e2 = 1 / 2 / 3 / 0 for
 * the first set bit of r among 1, 2, 3; FUN_a00a3578(port, DAT_a80791e2); ARR_a80791a8[port] = (r bit 5);
 * FUN_a0091cf4(port, 0x10, 8). Without st bit 5 it returns 0 here.
 * FUN_a00a80cc(port, 1, 0x39, 0x10, ARR_a8078720[port] != 0); v = FUN_a0091d64(port, 0x42) << 8 |
 * FUN_a0091d64(port, 0x41) (bytes kept in the 2-byte local b); vals[k] = nibble k of v for k < n.
 * v == 0 (or n == 3 and v & 0xfff == 0): FUN_a00a8054(port, 4, 0xd, 0x20), FUN_a0094ac4(port, 1), db6c = 5;
 * v == 0xffff (or n == 3 and the low 12 bits all set): db6c = 4; both clear the counter.
 * Otherwise: bits 8..14 of register 0xce00340c (port 0) or 0xce00370c are cleared through FUN_a0061528 /
 * FUN_a0061534, FUN_a00a80cc(port, 1, 0x39, 2, ARR_a8078718[port] != 0), FUN_a00a80cc(port, 1, 0x3c, 0xc,
 * ARR_a8078710[port] == 0), then for each lane k < n with q = vals[k]:
 * - q == 0xe: ffe = 1; once per call: i = ARR_a80791f0[port] + 1; if i <= ARR_a80791f4[port]:
 *   f0[port] = i % (f4[port] + 1), prints DAT_a006bce8 with k, FUN_a00a3578(port, DAT_a80791e2); else prints
 *   DAT_a006bd88 with k. Then prints DAT_a006bd38 with port, k.
 * - q 1..8: for q 5..8 FUN_a00a80cc(port, 1, 0x3b, 0x20, 1), ffe = 1, FUN_a00a80cc(port, 1, 0x3b, 0x10, 0);
 *   q == 3 with ARR_a80791a8[port] == 0 prints DAT_a006bdc8 with k; otherwise lane k writes its nibble with
 *   FUN_a00a8184(port, 4, 0xe0 + k / 2, 0xf or 0xf0, value) and FUN_a00a80cc(port, 1, 0x50, 1 << k, 0).
 * - other q: prints DAT_a006be10 with port, k, (u8)q.
 * Then FUN_a00a338c(port, ffe). Every path after the 0x20 test ends with FUN_a0091cf4(port, 0x10, 0x20).
 * Returns 0.
 * Source form: the parameter is unsigned int; port is a u8 copy, assigned again after the st bit 5 test and
 * inside the once-block (the firmware masks %i0 again there); the later uses mask the parameter in place.
 * n is written 3 + (x >= 3) (subx form); the 0/1 call arguments are separate calls per arm.
 */
extern int FUN_a0073044(const char *, ...);
extern void *FUN_a00b15d8(void *, const void *, unsigned int);
extern unsigned int FUN_a0091bac(unsigned char);
extern unsigned char FUN_a0091d64(unsigned int, unsigned int);
extern void FUN_a0091cf4(unsigned int, unsigned int, unsigned int);
extern void FUN_a00a3578(unsigned char, int);
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void FUN_a00a8184(unsigned char, unsigned char, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern void FUN_a0094ac4(unsigned char, unsigned char);
extern void FUN_a00a338c(unsigned char, unsigned char);
extern unsigned int FUN_a0061528(volatile unsigned int *);
extern void FUN_a0061534(volatile unsigned int *, unsigned int);

extern const unsigned char DAT_a00b4d14[];
extern const char DAT_a006bb98[];
extern const char DAT_a006bbe0[];
extern const char DAT_a006bc38[];
extern const char DAT_a006bc80[];
extern const char DAT_a006bce8[];
extern const char DAT_a006bd38[];
extern const char DAT_a006bd88[];
extern const char DAT_a006bdc8[];
extern const char DAT_a006be10[];

#define REG_340C ((volatile unsigned int *)0xce00340c)
#define REG_370C ((volatile unsigned int *)0xce00370c)

extern unsigned int ARR_a807db6c[];
extern unsigned int ARR_a807873c[];
extern unsigned int ARR_a80791fc[];
extern unsigned int ARR_a80791f4[];
extern unsigned char ARR_a80791e8[];
extern unsigned char ARR_a80791a8[];
extern unsigned char ARR_a8078728[];
extern unsigned char ARR_a8078720[];
extern unsigned char ARR_a8078718[];
extern unsigned char ARR_a8078710[];
extern unsigned char ARR_a80791f0[];
extern unsigned char DAT_a80791e2;

int FUN_a00a3b68(unsigned int param_1)
{
    unsigned char b[2] = { 0 };
    int vals[4] = { 0 };
    unsigned char tab[8];
    unsigned char port;
    unsigned char n;
    unsigned char st;
    unsigned char r;
    unsigned char i;
    unsigned char ffe;
    unsigned char once;
    unsigned short v;
    unsigned int idx;

    FUN_a00b15d8(tab, DAT_a00b4d14, 8);
    port = param_1;
    ffe = 0;
    if (ARR_a807db6c[port] != ARR_a807873c[port]) {
        FUN_a0073044(DAT_a006bb98, port);
        ARR_a807873c[port] = ARR_a807db6c[port];
    }
    n = 3 + (ARR_a80791fc[port] >= 3);
    st = ARR_a80791e8[port];
    ARR_a80791e8[port] = st + 1;
    if (st > 200 && ARR_a80791a8[port] == 0 && ARR_a8078728[port] == 1) {
        FUN_a0073044(DAT_a006bbe0, port);
        ARR_a807db6c[port] = 6;
        ARR_a80791e8[port] = 0;
    }
    if ((unsigned char)FUN_a0091bac(port) == 0) {
        FUN_a0073044(DAT_a006bc38, port);
        return 0;
    }
    st = FUN_a0091d64(port, 0x10);
    if (st & 8) {
        r = FUN_a0091d64(port, 0x35);
        FUN_a0073044(DAT_a006bc80, 0x35, r, r & 0x80, r & 0x20);
        if (r & 2)
            DAT_a80791e2 = 1;
        else if (r & 4)
            DAT_a80791e2 = 2;
        else if (r & 8)
            DAT_a80791e2 = 3;
        else
            DAT_a80791e2 = 0;
        FUN_a00a3578(port, DAT_a80791e2);
        if (r & 0x20)
            ARR_a80791a8[port] = 1;
        else
            ARR_a80791a8[port] = 0;
        FUN_a0091cf4(port, 0x10, 8);
    }
    if (!(st & 0x20))
        return 0;

    port = param_1;
    if (ARR_a8078720[port] != 0)
        FUN_a00a80cc(port, 1, 0x39, 0x10, 1);
    else
        FUN_a00a80cc(port, 1, 0x39, 0x10, 0);
    b[0] = FUN_a0091d64(port, 0x41);
    b[1] = FUN_a0091d64(port, 0x42);
    v = (b[1] << 8) | b[0];
    for (i = 0; i < n; i++)
        vals[i] = (int)(v & (0xf << (i * 4))) >> (i * 4);

    if (v == 0 || (n == 3 && (v & 0xfff) == 0)) {
        FUN_a00a8054(port, 4, 0xd, 0x20);
        FUN_a0094ac4(port, 1);
        ARR_a807db6c[port] = 5;
        ARR_a80791e8[port] = 0;
    } else if (v == 0xffff || (n == 3 && (v & 0xfff) == 0xfff)) {
        ARR_a807db6c[port] = 4;
        ARR_a80791e8[port] = 0;
    } else {
        if (port == 0)
            FUN_a0061534(REG_340C, FUN_a0061528(REG_340C) & 0xffff80ff);
        else
            FUN_a0061534(REG_370C, FUN_a0061528(REG_370C) & 0xffff80ff);
        if (ARR_a8078718[port] != 0)
            FUN_a00a80cc(port, 1, 0x39, 2, 1);
        else
            FUN_a00a80cc(port, 1, 0x39, 2, 0);
        if (ARR_a8078710[port] != 0)
            FUN_a00a80cc(port, 1, 0x3c, 0xc, 0);
        else
            FUN_a00a80cc(port, 1, 0x3c, 0xc, 1);
        once = 0;
        for (i = 0; i < n; i++) {
            if (vals[i] == 0xe) {
                ffe = 1;
                if (!once) {
                    once = 1;
                    port = param_1;
                    idx = ARR_a80791f0[port] + 1;
                    if (idx <= ARR_a80791f4[port]) {
                        ARR_a80791f0[port] = idx % (ARR_a80791f4[port] + 1);
                        FUN_a0073044(DAT_a006bce8, i);
                        FUN_a00a3578(port, DAT_a80791e2);
                    } else {
                        FUN_a0073044(DAT_a006bd88, i);
                    }
                }
                FUN_a0073044(DAT_a006bd38, (unsigned char)param_1, i);
            } else if (vals[i] - 1 < 8u) {
                if (vals[i] - 5 < 4u) {
                    FUN_a00a80cc(param_1, 1, 0x3b, 0x20, 1);
                    ffe = 1;
                    FUN_a00a80cc(param_1, 1, 0x3b, 0x10, 0);
                }
                if (vals[i] == 3 && ARR_a80791a8[(unsigned char)param_1] == 0) {
                    FUN_a0073044(DAT_a006bdc8, i);
                } else if (i == 0) {
                    FUN_a00a8184(param_1, 4, 0xe0, 0xf, (unsigned char)vals[0]);
                    FUN_a00a80cc(param_1, 1, 0x50, 1, 0);
                } else if (i == 1) {
                    FUN_a00a8184(param_1, 4, 0xe0, 0xf0, (vals[1] << 4) & 0xf0);
                    FUN_a00a80cc(param_1, 1, 0x50, 2, 0);
                } else if (i == 2) {
                    FUN_a00a8184(param_1, 4, 0xe1, 0xf, (unsigned char)vals[2]);
                    FUN_a00a80cc(param_1, 1, 0x50, 4, 0);
                } else if (i == 3) {
                    FUN_a00a8184(param_1, 4, 0xe1, 0xf0, (vals[3] << 4) & 0xf0);
                    FUN_a00a80cc(param_1, 1, 0x50, 8, 0);
                }
            } else {
                FUN_a0073044(DAT_a006be10, (unsigned char)param_1, i, vals[i] & 0xff);
            }
        }
        FUN_a00a338c(param_1, ffe);
    }
    FUN_a0091cf4((unsigned char)param_1, 0x10, 0x20);
    return 0;
}
