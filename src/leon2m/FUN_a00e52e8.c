/* leon2m FUN_a00e52e8 @ 0xa00e52e8-0xa00e5428, flags -mcpu=v8 -O3 -g. Callers: FUN_a00e5428, FUN_a00e5fc8.
 * Parameters unit, b, d. Reads v = FUN_a00e0754(unit, reg, mask, shift) with reg, mask, shift taken from entry b
 * of the word tables DAT_a80266f8, DAT_a80266e8, DAT_a80266d8 (b == -1 passes the three table addresses
 * themselves). d == 0 returns 0. For d > 0 with 15 - v < d, and for d < 0 with v + d < 0, it calls FUN_a00df80c and
 * FUN_a00e0bc0, passes "Error: qsen_wrap_dly_reg_b%d = %d, add %d will be overflow.\n" (or "... underflow.\n")
 * with b, v, d to FUN_a00df170 and returns -1. Otherwise it calls FUN_a00e0774(unit, reg, mask, shift, v + d) with
 * the same table selection and returns 0. Source form: each call written twice (b == -1 / table entry arm), as in
 * src/leon2m/FUN_a00e2714.c; the d tests nested (d > 0 / else d < 0, each with its own range test).
 */
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int DAT_a80266d8[];
extern unsigned int DAT_a80266e8[];
extern unsigned int DAT_a80266f8[];

int FUN_a00e52e8(unsigned int unit, int b, int d)
{
    int v;

    if (b == -1)
        v = FUN_a00e0754(unit, (unsigned int)DAT_a80266f8, (unsigned int)DAT_a80266e8, (unsigned int)DAT_a80266d8);
    else
        v = FUN_a00e0754(unit, DAT_a80266f8[b], DAT_a80266e8[b], DAT_a80266d8[b]);
    if (d == 0)
        return 0;
    if (d > 0) {
        if (15 - v < d) {
            FUN_a00df80c();
            FUN_a00e0bc0();
            FUN_a00df170("Error: qsen_wrap_dly_reg_b%d = %d, add %d will be overflow.\n", b, v, d);
            return -1;
        }
    } else if (d < 0) {
        if (v + d < 0) {
            FUN_a00df80c();
            FUN_a00e0bc0();
            FUN_a00df170("Error: qsen_wrap_dly_reg_b%d = %d, add %d will be underflow.\n", b, v, d);
            return -1;
        }
    }
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80266f8, (unsigned int)DAT_a80266e8, (unsigned int)DAT_a80266d8, v + d);
    else
        FUN_a00e0774(unit, DAT_a80266f8[b], DAT_a80266e8[b], DAT_a80266d8[b], v + d);
    return 0;
}
