/* leon2m FUN_a00ee1e8 @ 0xa00ee1e8-0xa00ee964 (1916 bytes), flags -mcpu=v8 -O3. Callers: FUN_a00e0e44, FUN_a00eec44.
 * FUN_a00ee1e8(unit, p1, p2, b, p4, p5, speed, pct): FUN_a00dffb4(12, unit, b), FUN_a00dfc50(unit, p1, p2).
 * Register fields are read with FUN_a00e0754 and written with FUN_a00e0774, with (reg, mask, shift) from entry b of
 * three word tables (b == -1 passes the table addresses themselves), as in FUN_a00e9c80.
 * v = field 0xa8026308/0xa80262f8/0xa802b638, lim = v * pct * 8 / 100. speed selects mode 0 (<= 0x535), 1 (<= 0x74a),
 * 2 (<= 0x960) or 3 (<= 0xa6b), as FUN_a00ee188 does; larger speed calls FUN_a00df80c(), FUN_a00e0bc0(), prints
 * "Error: Undefined MR6 tCCD_L for DDR speed = %d.\n" with speed and returns -1. k = the same field read again.
 * idx = index of the first of the 0x4a three-byte entries of DAT_a8026998 whose byte 0 equals the low byte of
 * FUN_a00e02ec(unit, 0x28e); no entry: FUN_a00df80c(), FUN_a00e0bc0(), "vref2index: can not valid index of vref:
 * 0x%02x\n" with that byte, returns -1.
 * res = FUN_a00edc70(unit, p1, p2, mode, idx, b, k, p4, p5) returns a two-word structure {a, b}; both words -1:
 * FUN_a00df80c(), FUN_a00e0bc0(), "Error: Bist fail or timeout.\n", returns -1. hi = lo = idx; the pairs (la, lb)
 * and (ua, ub) start as (res.a, res.b). Two passes with step 4, then step 1, each repeating until both directions
 * stop: upwards hi += step and res = FUN_a00edc70(.., hi, ..): res.b == -1, or MIN(lb, res.b) - MAX(la, res.a) below
 * lim, undoes the step and stops; otherwise (ua, ub) = res and it stops when hi > 0x49. Downwards the same with
 * lo -= step and the pair (ua, ub), storing (la, lb), stopping when lo <= 0.
 * Word unit of DAT_a802698c is lowered to hi and word unit of DAT_a802b730 raised to lo (unsigned compares).
 * mid = (MAX(la, ua) + MIN(lb, ub)) >> 1, pos = mid / k (unsigned); field 0xa80268e8/0xa80268d8/0xa80268c8 =
 * field 0xa8026918/0xa8026908/0xa80268f8 + pos, field 0xa80268b8/0xa80268a8/0xa8026898 = that field + pos - 4;
 * with m = mid % k (unsigned): fields 0xa8026798/88/78 and 0xa8026748/38/28 = m >> 3, fields 0xa8026768/58 +
 * 0xa802b6e8 and 0xa8026718/08 + 0xa802b6d8 = m & 7. Returns 0.
 * Source form: each read and write is its own if (b == -1)/else statement and the final writes nest their read
 * ('FUN_a00e0774(.., FUN_a00e0754(..) + ..)'); the mode chain is written in place with k as the temporary
 * ('mode = k;', k is then set by the second read), which keeps the copy into mode; the second final write adds
 * '(pos -= 4)' so the subtraction stays a separate step before the addition; 'step = 4;' precedes the both-words
 * test; the table at 0xa802b638 is declared as u_a802b638 and the one at 0xa8026718 as ARR_a8026718 (the symbol
 * names set the order of the address pseudos and so the register choices).
 */
struct win { int a; int b; };
extern void FUN_a00dffb4(unsigned int, unsigned int, unsigned int);
extern int FUN_a00dfc50(unsigned int, unsigned int, unsigned int);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e02ec(unsigned int, unsigned int);
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern struct win FUN_a00edc70(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, int,
                               int, unsigned int, unsigned int);
extern unsigned char DAT_a8026998[][3];
extern unsigned int DAT_a802698c[], DAT_a802b730[];
extern unsigned int DAT_a8026308[], DAT_a80262f8[], u_a802b638[];
extern unsigned int DAT_a8026918[], DAT_a8026908[], DAT_a80268f8[];
extern unsigned int DAT_a80268e8[], DAT_a80268d8[], DAT_a80268c8[];
extern unsigned int DAT_a80268b8[], DAT_a80268a8[], DAT_a8026898[];
extern unsigned int DAT_a8026798[], DAT_a8026788[], DAT_a8026778[];
extern unsigned int DAT_a8026768[], DAT_a8026758[], DAT_a802b6e8[];
extern unsigned int DAT_a8026748[], DAT_a8026738[], DAT_a8026728[];
extern unsigned int ARR_a8026718[], DAT_a8026708[], DAT_a802b6d8[];

#define MIN(x, y) ((x) <= (y) ? (x) : (y))
#define MAX(x, y) ((x) >= (y) ? (x) : (y))

static int vref2index(unsigned char vref)
{
    int i;

    for (i = 0; i < 0x4a; i++)
        if (DAT_a8026998[i][0] == vref)
            return i;
    FUN_a00df80c();
    FUN_a00e0bc0();
    FUN_a00df170("vref2index: can not valid index of vref: 0x%02x\n", vref);
    return -1;
}

int FUN_a00ee1e8(unsigned int unit, unsigned int p1, unsigned int p2, int b, unsigned int p4, unsigned int p5,
                 int speed, int pct)
{
    int idx, v, lim, mode, k, hi, lo, step, pass, up, dn, mid;
    int la, lb, ua, ub, ra, rb;
    unsigned int pos;
    struct win res;

    FUN_a00dffb4(12, unit, b);
    FUN_a00dfc50(unit, p1, p2);
    if (b == -1)
        v = FUN_a00e0754(unit, (unsigned int)DAT_a8026308, (unsigned int)DAT_a80262f8, (unsigned int)u_a802b638);
    else
        v = FUN_a00e0754(unit, DAT_a8026308[b], DAT_a80262f8[b], u_a802b638[b]);
    lim = v * pct * 8 / 100;
    if (speed <= 0x535)
        k = 0;
    else if (speed <= 0x74a)
        k = 1;
    else if (speed <= 0x960)
        k = 2;
    else if (speed <= 0xa6b)
        k = 3;
    else {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: Undefined MR6 tCCD_L for DDR speed = %d.\n", speed);
        return -1;
    }
    mode = k;
    if (b == -1)
        k = FUN_a00e0754(unit, (unsigned int)DAT_a8026308, (unsigned int)DAT_a80262f8, (unsigned int)u_a802b638);
    else
        k = FUN_a00e0754(unit, DAT_a8026308[b], DAT_a80262f8[b], u_a802b638[b]);
    idx = vref2index(FUN_a00e02ec(unit, 0x28e));
    if (idx < 0)
        return -1;
    lo = idx;
    res = FUN_a00edc70(unit, p1, p2, mode, idx, b, k, p4, p5);
    ra = res.a;
    rb = res.b;
    hi = lo;
    step = 4;
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
                res = FUN_a00edc70(unit, p1, p2, mode, hi, b, k, p4, p5);
                ra = res.a;
                rb = res.b;
                if (rb == -1) {
                    hi -= step;
                    up = 1;
                } else if (MIN(lb, rb) - MAX(la, ra) >= lim) {
                    ub = rb;
                    ua = ra;
                    if (hi > 0x49)
                        up = 1;
                } else {
                    hi -= step;
                    up = 1;
                }
            }
            if (!dn) {
                lo -= step;
                res = FUN_a00edc70(unit, p1, p2, mode, lo, b, k, p4, p5);
                ra = res.a;
                rb = res.b;
                if (rb == -1) {
                    lo += step;
                    dn = 1;
                } else if (MIN(rb, ub) - MAX(ra, ua) >= lim) {
                    lb = rb;
                    la = ra;
                    if (lo <= 0)
                        dn = 1;
                } else {
                    lo += step;
                    dn = 1;
                }
            }
        }
    }
    if (DAT_a802698c[unit] > (unsigned int)hi)
        DAT_a802698c[unit] = hi;
    if (DAT_a802b730[unit] < (unsigned int)lo)
        DAT_a802b730[unit] = lo;
    mid = (MAX(la, ua) + MIN(lb, ub)) >> 1;
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8,
                     FUN_a00e0754(unit, (unsigned int)DAT_a8026918, (unsigned int)DAT_a8026908, (unsigned int)DAT_a80268f8) + (pos = (unsigned int)mid / k));
    else
        FUN_a00e0774(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b],
                     FUN_a00e0754(unit, DAT_a8026918[b], DAT_a8026908[b], DAT_a80268f8[b]) + (pos = (unsigned int)mid / k));
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268b8, (unsigned int)DAT_a80268a8, (unsigned int)DAT_a8026898,
                     FUN_a00e0754(unit, (unsigned int)DAT_a8026918, (unsigned int)DAT_a8026908, (unsigned int)DAT_a80268f8) + (pos -= 4));
    else
        FUN_a00e0774(unit, DAT_a80268b8[b], DAT_a80268a8[b], DAT_a8026898[b],
                     FUN_a00e0754(unit, DAT_a8026918[b], DAT_a8026908[b], DAT_a80268f8[b]) + (pos -= 4));
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)DAT_a8026778, (unsigned int)mid % k >> 3);
    else
        FUN_a00e0774(unit, DAT_a8026798[b], DAT_a8026788[b], DAT_a8026778[b], (unsigned int)mid % k >> 3);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026768, (unsigned int)DAT_a8026758, (unsigned int)DAT_a802b6e8, (unsigned int)mid % k & 7);
    else
        FUN_a00e0774(unit, DAT_a8026768[b], DAT_a8026758[b], DAT_a802b6e8[b], (unsigned int)mid % k & 7);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728, (unsigned int)mid % k >> 3);
    else
        FUN_a00e0774(unit, DAT_a8026748[b], DAT_a8026738[b], DAT_a8026728[b], (unsigned int)mid % k >> 3);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)ARR_a8026718, (unsigned int)DAT_a8026708, (unsigned int)DAT_a802b6d8, (unsigned int)mid % k & 7);
    else
        FUN_a00e0774(unit, ARR_a8026718[b], DAT_a8026708[b], DAT_a802b6d8[b], (unsigned int)mid % k & 7);
    return 0;
}
