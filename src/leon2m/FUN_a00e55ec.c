/* leon2m FUN_a00e55ec @ 0xa00e55ec-0xa00e57b4 (456 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a00e57b4,
 * FUN_a00e5fc8, FUN_a00e7254 and itself.
 * FUN_a00e55ec(unit, b, d): a step d above 8 or below -8 is applied as recursive calls with 8 / -8 (a non-zero
 * result is returned) until |d| <= 8; d == 0 returns 0. The register field (reg, mask, shift) is taken from entry b
 * of the word tables 0xa8026698 / 0xa8026688 / 0xa8026678 (b == -1 passes the table addresses themselves),
 * read with FUN_a00e0754 into v. For v in 5..12: d > 0 with 12 - v < d calls FUN_a00e5428(unit, b, 1), d < 0
 * with v - 5 < -d calls FUN_a00e5428(unit, b, -1); otherwise the same with 7 - ((v + 3) & 0xf) < d and
 * ((v + 3) & 0xf) < -d. A non-zero FUN_a00e5428 result is returned. Then v + d is written back with
 * FUN_a00e0774 and the function returns 0.
 * Source form: the three tables are named ARR_A8026678 / ARR_A8026688 / ARR_a8026698; the symbol names set the
 * order of GCSE's registers for their high parts, which decides %l1 / %l2 / %l3.
 */
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00e5428(unsigned int unit, int b, int d);
extern unsigned int ARR_A8026678[];
extern unsigned int ARR_A8026688[];
extern unsigned int ARR_a8026698[];

int FUN_a00e55ec(unsigned int unit, int b, int d)
{
    unsigned int v;
    int r;

    if (d > 8) {
        while (d > 8) {
            r = FUN_a00e55ec(unit, b, 8);
            d -= 8;
            if (r != 0)
                return r;
        }
    } else {
        while (d < -8) {
            r = FUN_a00e55ec(unit, b, -8);
            d += 8;
            if (r != 0)
                return r;
        }
    }
    if (d == 0)
        return 0;
    if (b == -1)
        v = FUN_a00e0754(unit, (unsigned int)ARR_a8026698, (unsigned int)ARR_A8026688, (unsigned int)ARR_A8026678);
    else
        v = FUN_a00e0754(unit, ARR_a8026698[b], ARR_A8026688[b], ARR_A8026678[b]);
    if (v >= 5 && v <= 12) {
        if (d > 0) {
            if (12 - v < d) {
                r = FUN_a00e5428(unit, b, 1);
                if (r != 0)
                    return r;
            }
        } else if (d < 0) {
            if (v - 5 < -d) {
                r = FUN_a00e5428(unit, b, -1);
                if (r != 0)
                    return r;
            }
        }
    } else {
        if (d > 0) {
            if (7 - ((v + 3) & 0xf) < d) {
                r = FUN_a00e5428(unit, b, 1);
                if (r != 0)
                    return r;
            }
        } else if (d < 0) {
            if (((v + 3) & 0xf) < -d) {
                r = FUN_a00e5428(unit, b, -1);
                if (r != 0)
                    return r;
            }
        }
    }
    v += d;
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)ARR_a8026698, (unsigned int)ARR_A8026688, (unsigned int)ARR_A8026678, v);
    else
        FUN_a00e0774(unit, ARR_a8026698[b], ARR_A8026688[b], ARR_A8026678[b], v);
    return 0;
}
