/* leon2m FUN_a00e285c @ 0xa00e285c-0xa00e29a4 (82 words).
 * Parameters unit, a, b, x, y, z. If a > 9: FUN_a00df80c(), FUN_a00e0bc0() and the log call FUN_a00df170(string
 * 0x199788 "error: N_adj=%d, should be 0~9.", a). Else if b > 9: the same two calls and FUN_a00df170(string 0x199768,
 * b). Otherwise three FUN_a00e0774(unit, reg, mask, shift, value) calls whose register, mask and shift come from
 * entry a of 10-word tables: (0xa80260b0, 0xa8026088, 0xa8026060) with value z, (0xa8026038, 0xa8026010, 0xa8025fe8)
 * with x, and (0xa8025fc0, 0xa8025f98, 0xa802b5a8) with y. b is only range-checked. The code also has a branch for a
 * == 0xffffffff that passes the table addresses themselves instead of entries; after the range check it is never
 * taken. Same code as FUN_a00e2714 with other tables; same checks as FUN_a00e2690. Compiler aid: 'x++; x--;' after
 * the first check emits no instructions; it changes the order in which GCC assigns the registers that hold the table
 * addresses, which then match the firmware.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00df80c(void);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0bc0(void);
extern const char s_00199788[];
extern const char s_00199768[];
extern unsigned int DAT_a80260b0[10], DAT_a8026088[10], DAT_a8026060[10];
extern unsigned int DAT_a8026038[10], DAT_a8026010[10], DAT_a8025fe8[10];
extern unsigned int DAT_a8025fc0[10], DAT_a8025f98[10], DAT_a802b5a8[10];

void FUN_a00e285c(unsigned int unit, unsigned int a, unsigned int b, unsigned int x, unsigned int y, unsigned int z)
{
    if (a > 9) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_00199788, a);
        return;
    }
    x++;
    x--;
    if (b > 9) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_00199768, b);
        return;
    }
    if (a == 0xffffffff) {
        FUN_a00e0774(unit, (unsigned int)DAT_a80260b0, (unsigned int)DAT_a8026088, (unsigned int)DAT_a8026060, z);
        FUN_a00e0774(unit, (unsigned int)DAT_a8026038, (unsigned int)DAT_a8026010, (unsigned int)DAT_a8025fe8, x);
        FUN_a00e0774(unit, (unsigned int)DAT_a8025fc0, (unsigned int)DAT_a8025f98, (unsigned int)DAT_a802b5a8, y);
        return;
    }
    FUN_a00e0774(unit, DAT_a80260b0[a], DAT_a8026088[a], DAT_a8026060[a], z);
    FUN_a00e0774(unit, DAT_a8026038[a], DAT_a8026010[a], DAT_a8025fe8[a], x);
    FUN_a00e0774(unit, DAT_a8025fc0[a], DAT_a8025f98[a], DAT_a802b5a8[a], y);
}
