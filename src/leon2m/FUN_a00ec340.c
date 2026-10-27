/* leon2m FUN_a00ec340 @ 0xa00ec340-0xa00ec6b8 (888 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a00ec6b8.
 * FUN_a00ec340(unit, b, p3, p4, n): v = (p3 + p4 - 1) >> 1, q = v / n, r = v % n (as v - q * n), hi = bits 3..7
 * of r, lo = bits 0..2 of r. Register fields are read with FUN_a00e0754 and written with FUN_a00e0774, with (reg,
 * mask, shift) from entry b of three word tables (b == -1 passes the table addresses themselves, as in
 * FUN_a00e9c80): base = field(0xa8026918/908/8f8) + q; field(0xa80268e8/8d8/8c8) = base; field(0xa80268b8/8a8/898)
 * = base - 4; field(0xa8026948/938/928) = 3 when q > 8, else 0; field(0xa8026798/788/778) = hi;
 * field(0xa8026748/738/728) = hi; field(0xa8026768/758, 0xa802b6e8) = lo; field(0xa8026718/708, 0xa802b6d8) = lo.
 * Source form: each read and write is its own if (b == -1)/else statement (GCC threads the repeated tests); the
 * '+ q' is part of the read statement; q is an int; the q > 8 arm first.
 */
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int DAT_a8026918[], DAT_a8026908[], DAT_a80268f8[], DAT_a80268e8[], DAT_a80268d8[], DAT_a80268c8[], DAT_a80268b8[], DAT_a80268a8[], DAT_a8026898[], DAT_a8026948[], DAT_a8026938[], DAT_a8026928[], DAT_a8026798[], DAT_a8026788[], DAT_a8026778[], DAT_a8026748[], DAT_a8026738[], DAT_a8026728[], DAT_a8026768[], DAT_a8026758[], DAT_a802b6e8[], DAT_a8026718[], DAT_a8026708[], DAT_a802b6d8[];

void FUN_a00ec340(unsigned int unit, int b, int p3, int p4, unsigned int n)
{
    unsigned int v, r, hi, lo;
    int q, base;

    v = (p3 + p4 - 1U) >> 1;
    q = v / n;
    r = v - q * n;
    hi = (r >> 3) & 0x1f;
    lo = r & 7;
    if (b == -1)
        base = FUN_a00e0754(unit, (unsigned int)DAT_a8026918, (unsigned int)DAT_a8026908, (unsigned int)DAT_a80268f8) + q;
    else
        base = FUN_a00e0754(unit, DAT_a8026918[b], DAT_a8026908[b], DAT_a80268f8[b]) + q;
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8, base);
    else
        FUN_a00e0774(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b], base);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268b8, (unsigned int)DAT_a80268a8, (unsigned int)DAT_a8026898, base - 4);
    else
        FUN_a00e0774(unit, DAT_a80268b8[b], DAT_a80268a8[b], DAT_a8026898[b], base - 4);
    if (q > 8) {
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a8026948, (unsigned int)DAT_a8026938, (unsigned int)DAT_a8026928, 3);
        else
            FUN_a00e0774(unit, DAT_a8026948[b], DAT_a8026938[b], DAT_a8026928[b], 3);
    } else {
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a8026948, (unsigned int)DAT_a8026938, (unsigned int)DAT_a8026928, 0);
        else
            FUN_a00e0774(unit, DAT_a8026948[b], DAT_a8026938[b], DAT_a8026928[b], 0);
    }
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)DAT_a8026778, hi);
    else
        FUN_a00e0774(unit, DAT_a8026798[b], DAT_a8026788[b], DAT_a8026778[b], hi);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728, hi);
    else
        FUN_a00e0774(unit, DAT_a8026748[b], DAT_a8026738[b], DAT_a8026728[b], hi);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026768, (unsigned int)DAT_a8026758, (unsigned int)DAT_a802b6e8, lo);
    else
        FUN_a00e0774(unit, DAT_a8026768[b], DAT_a8026758[b], DAT_a802b6e8[b], lo);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026718, (unsigned int)DAT_a8026708, (unsigned int)DAT_a802b6d8, lo);
    else
        FUN_a00e0774(unit, DAT_a8026718[b], DAT_a8026708[b], DAT_a802b6d8[b], lo);
}
