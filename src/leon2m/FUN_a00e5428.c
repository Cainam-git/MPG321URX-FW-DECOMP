/* leon2m FUN_a00e5428 @ 0xa00e5428-0xa00e55ec (452 bytes), flags -mcpu=v8 -O3 -g. Callers: FUN_a00e55ec.
 * Parameters unit, b, d. A step d outside -1..1 calls FUN_a00df80c and FUN_a00e0bc0, passes "TODO:
 * add_qs_gate_sel(phy_id, ) not implement more than 1 or -1 steps.\n" to FUN_a00df170 and returns -1; d == 0
 * returns 0. Reads v = FUN_a00e0754(unit, reg, mask, shift) with reg, mask, shift taken from entry b of the word
 * tables DAT_a80266c8, DAT_a80266b8, DAT_a80266a8 (b == -1 passes the three table addresses themselves). v == 1:
 * for d != 1 first FUN_a00e52e8(unit, b, -1) (a non-zero result is returned), then FUN_a00e0774(.., 3). v == 3:
 * for d == 1 first FUN_a00e52e8(unit, b, 1), then FUN_a00e0774(.., 1). Any other v calls FUN_a00df80c,
 * FUN_a00e0bc0, passes "Error: add_qs_gate_sel(phy_id, ) impossible val_qs_gate_sel = %d\n" with v to
 * FUN_a00df170 and returns -1. Otherwise returns 0.
 * Source form: both arms test d == 1 first and write the field in each branch ('if (d == 1) { write 3 } else {
 * FUN_a00e52e8(-1); write 3 }', 'if (d == 1) { FUN_a00e52e8(1); write 1 } else { write 1 }'); cross-jumping
 * merges the writes and keeps the v == 1 arm's FUN_a00e52e8(-1) block out of line (0xa00e554c, entered by the
 * bne,a at 0xa00e5500). Each table access is its own if (b == -1)/else statement, as in src/leon2m/FUN_a00e52e8.c.
 */
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int FUN_a00e52e8(unsigned int unit, int b, int d);
extern unsigned int DAT_a80266a8[];
extern unsigned int DAT_a80266b8[];
extern unsigned int DAT_a80266c8[];


int FUN_a00e5428(unsigned int unit, int b, int d)
{
    int v, r;

    if (d < -1 || d > 1) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("TODO: add_qs_gate_sel(phy_id, ) not implement more than 1 or -1 steps.\n");
        return -1;
    }
    if (d == 0)
        return 0;
    if (b == -1)
        v = FUN_a00e0754(unit, (unsigned int)DAT_a80266c8, (unsigned int)DAT_a80266b8, (unsigned int)DAT_a80266a8);
    else
        v = FUN_a00e0754(unit, DAT_a80266c8[b], DAT_a80266b8[b], DAT_a80266a8[b]);
    if (v == 1) {
        if (d == 1) {
            if (b == -1)
                FUN_a00e0774(unit, (unsigned int)DAT_a80266c8, (unsigned int)DAT_a80266b8, (unsigned int)DAT_a80266a8, 3);
            else
                FUN_a00e0774(unit, DAT_a80266c8[b], DAT_a80266b8[b], DAT_a80266a8[b], 3);
        } else {
            r = FUN_a00e52e8(unit, b, -1);
            if (r != 0)
                return r;
            if (b == -1)
                FUN_a00e0774(unit, (unsigned int)DAT_a80266c8, (unsigned int)DAT_a80266b8, (unsigned int)DAT_a80266a8, 3);
            else
                FUN_a00e0774(unit, DAT_a80266c8[b], DAT_a80266b8[b], DAT_a80266a8[b], 3);
        }
    } else if (v == 3) {
        if (d == 1) {
            r = FUN_a00e52e8(unit, b, 1);
            if (r != 0)
                return r;
            if (b == -1)
                FUN_a00e0774(unit, (unsigned int)DAT_a80266c8, (unsigned int)DAT_a80266b8, (unsigned int)DAT_a80266a8, 1);
            else
                FUN_a00e0774(unit, DAT_a80266c8[b], DAT_a80266b8[b], DAT_a80266a8[b], 1);
        } else {
            if (b == -1)
                FUN_a00e0774(unit, (unsigned int)DAT_a80266c8, (unsigned int)DAT_a80266b8, (unsigned int)DAT_a80266a8, 1);
            else
                FUN_a00e0774(unit, DAT_a80266c8[b], DAT_a80266b8[b], DAT_a80266a8[b], 1);
        }
    } else {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: add_qs_gate_sel(phy_id, ) impossible val_qs_gate_sel = %d\n", v);
        return -1;
    }
    return 0;
}
