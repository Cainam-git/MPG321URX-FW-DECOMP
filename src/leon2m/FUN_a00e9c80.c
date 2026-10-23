/* leon2m FUN_a00e9c80 @ 0xa00e9c80-0xa00ea1f0 (348 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a00e0e44, FUN_a00ea1f0.
 * FUN_a00e9c80(unit, p2, p3, b, pct, p6): FUN_a00dffb4(9, unit, b), FUN_a00dfc50(unit, p2, p3). pct outside 20..80:
 * FUN_a00df80c(), FUN_a00e0bc0(), "Error: UI_percentage = %d < 20 or > 80.\n" with pct to FUN_a00df170, returns -1.
 * Register fields are read with FUN_a00e0754 and written with FUN_a00e0774, with (reg, mask, shift) taken from entry
 * b of three word tables (b == -1 passes the table addresses themselves): field A = tables 0xa8026368/0xa8026358/
 * 0xa802b668, field B = 0xa8026838/0xa8026828/0xa802b708, field C = 0xa8026348/0xa8026328/0xa802b658, field D =
 * 0xa8026338/0xa8026318/0xa802b648. lim = A * pct * 2 / 100 (unsigned), r1 = B, hi = lo = C.
 * res = FUN_a00e9b34(unit, p2, p3, hi, b, r1, p6) returns a two-word structure {a, b}; both words -1: FUN_a00df80c(),
 * FUN_a00e0bc0(), "Error: Bist fail or timeout.\n" to FUN_a00df170, returns -1. The upper pair (ua, ub) and the lower
 * pair (la, lb) start as (res.a, res.b). Two passes with step 4, then step 1, each repeating until both directions
 * stop: upwards hi += step and res = FUN_a00e9b34(.., hi, ..): both words -1, or MIN(la, res.a) - MAX(lb, res.b)
 * (unsigned) below lim, undoes the step and stops; otherwise (ua, ub) = res and it stops when hi > 0x4b. Downwards
 * the same with lo -= step, the pair (ua, ub), storing (la, lb), stopping when lo <= 4. Finally C and D are written
 * with (lo + hi) >> 1 and B with (MIN(la, ua) + MAX(lb, ub)) / 2; returns 0.
 * Source form: each read and write is its own if (b == -1)/else statement; the two -1 tests combine with '&'; the
 * failing upwards step and the hi > 0x4b stop end with continue; the result words are copied into ra/rb (operand
 * order of the MIN/MAX selections); lo = hi is assigned before the -1 test.
 */
struct win { int a; int b; };
extern void FUN_a00dffb4(unsigned int, unsigned int, unsigned int);
extern int FUN_a00dfc50(unsigned int, unsigned int, unsigned int);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern struct win FUN_a00e9b34(unsigned int, unsigned int, unsigned int, int, int, int, unsigned int);
extern unsigned int DAT_a8026368[], DAT_a8026358[], DAT_a802b668[];
extern unsigned int DAT_a8026838[], DAT_a8026828[], DAT_a802b708[];
extern unsigned int DAT_a8026348[], DAT_a8026328[], DAT_a802b658[];
extern unsigned int DAT_a8026338[], DAT_a8026318[], DAT_a802b648[];

#define MIN(x, y) ((x) <= (y) ? (x) : (y))
#define MAX(x, y) ((x) >= (y) ? (x) : (y))

int FUN_a00e9c80(unsigned int unit, unsigned int p2, unsigned int p3, int b, int pct, unsigned int p6)
{
    unsigned int v, lim;
    int r1, hi, lo, step, pass, up, dn;
    int la, lb, ua, ub;
    struct win res;
    int ra, rb;

    FUN_a00dffb4(9, unit, b);
    FUN_a00dfc50(unit, p2, p3);
    if (pct < 20 || pct > 80) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: UI_percentage = %d < 20 or > 80.\n", pct);
        return -1;
    }
    if (b == -1)
        v = FUN_a00e0754(unit, (unsigned int)DAT_a8026368, (unsigned int)DAT_a8026358, (unsigned int)DAT_a802b668);
    else
        v = FUN_a00e0754(unit, DAT_a8026368[b], DAT_a8026358[b], DAT_a802b668[b]);
    lim = v * pct * 2 / 100;
    if (b == -1)
        r1 = FUN_a00e0754(unit, (unsigned int)DAT_a8026838, (unsigned int)DAT_a8026828, (unsigned int)DAT_a802b708);
    else
        r1 = FUN_a00e0754(unit, DAT_a8026838[b], DAT_a8026828[b], DAT_a802b708[b]);
    if (b == -1)
        hi = FUN_a00e0754(unit, (unsigned int)DAT_a8026348, (unsigned int)DAT_a8026328, (unsigned int)DAT_a802b658);
    else
        hi = FUN_a00e0754(unit, DAT_a8026348[b], DAT_a8026328[b], DAT_a802b658[b]);
    step = 4;
    res = FUN_a00e9b34(unit, p2, p3, hi, b, r1, p6);
    ra = res.a;
    rb = res.b;
    lo = hi;
    if ((rb == -1) & (ra == -1)) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: Bist fail or timeout.\n");
        return -1;
    }
    ub = rb;
    ua = ra;
    lb = rb;
    la = ra;
    for (pass = 0; pass <= 1; pass++) {
        if (pass > 0)
            step = 1;
        dn = 0;
        up = 0;
        while (!up || !dn) {
            if (!up) {
                hi += step;
                res = FUN_a00e9b34(unit, p2, p3, hi, b, r1, p6);
                ra = res.a;
                rb = res.b;
                if ((rb == -1) & (ra == -1)) {
                    hi -= step;
                    up = 1;
                    continue;
                }
                if ((unsigned int)(MIN(la, ra) - MAX(lb, rb)) >= lim) {
                    ub = rb;
                    ua = ra;
                    if (hi > 0x4b) {
                        up = 1;
                        continue;
                    }
                } else {
                    hi -= step;
                    up = 1;
                }
            }
            if (!dn) {
                lo -= step;
                res = FUN_a00e9b34(unit, p2, p3, lo, b, r1, p6);
                ra = res.a;
                rb = res.b;
                if ((rb == -1) & (ra == -1)) {
                    lo += step;
                    dn = 1;
                    continue;
                }
                if ((unsigned int)(MIN(ra, ua) - MAX(rb, ub)) >= lim) {
                    lb = rb;
                    la = ra;
                    if (lo <= 4)
                        dn = 1;
                } else {
                    lo += step;
                    dn = 1;
                }
            }
        }
    }
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026348, (unsigned int)DAT_a8026328, (unsigned int)DAT_a802b658, (lo + hi) >> 1);
    else
        FUN_a00e0774(unit, DAT_a8026348[b], DAT_a8026328[b], DAT_a802b658[b], (lo + hi) >> 1);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026338, (unsigned int)DAT_a8026318, (unsigned int)DAT_a802b648, (lo + hi) >> 1);
    else
        FUN_a00e0774(unit, DAT_a8026338[b], DAT_a8026318[b], DAT_a802b648[b], (lo + hi) >> 1);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026838, (unsigned int)DAT_a8026828, (unsigned int)DAT_a802b708,
                     (MIN(la, ua) + MAX(lb, ub)) / 2);
    else
        FUN_a00e0774(unit, DAT_a8026838[b], DAT_a8026828[b], DAT_a802b708[b], (MIN(la, ua) + MAX(lb, ub)) / 2);
    return 0;
}
