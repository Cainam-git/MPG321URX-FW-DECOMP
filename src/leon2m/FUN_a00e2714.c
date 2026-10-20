/* leon2m FUN_a00e2714 @ 0xa00e2714-0xa00e285c (82 words).
 * Parameters unit, a, b, x, y, z. If a > 9: FUN_a00df80c(), FUN_a00e0bc0() and the log call FUN_a00df170(string
 * 0x199788 "error: N_adj=%d, should be 0~9.", a). Else if b > 9: the same two calls and FUN_a00df170(string 0x199768,
 * b). Otherwise three FUN_a00e0774(unit, reg, mask, shift, value) calls whose register, mask and shift come from
 * entry a of 10-word tables: (0xa80261f0, 0xa80261c8, 0xa80261a0) with value z, (0xa8026178, 0xa8026150, 0xa8026128)
 * with x, and (0xa8026100, 0xa80260d8, 0xa802b5d0) with y. b is only range-checked. The code also has a branch for a
 * == 0xffffffff that passes the table addresses themselves instead of entries; after the range check it is never
 * taken. Same checks as FUN_a00e2690. Compiler aid: 'x++; x--;' after the first check emits no instructions; it
 * changes the order in which GCC assigns the registers that hold the table addresses, which then match the firmware.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00df80c(void);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0bc0(void);
extern const char s_00199788[];
extern const char s_00199768[];
extern unsigned int DAT_a80261f0[10], DAT_a80261c8[10], DAT_a80261a0[10];
extern unsigned int DAT_a8026178[10], DAT_a8026150[10], DAT_a8026128[10];
extern unsigned int DAT_a8026100[10], DAT_a80260d8[10], DAT_a802b5d0[10];

void FUN_a00e2714(unsigned int unit, unsigned int a, unsigned int b, unsigned int x, unsigned int y, unsigned int z)
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
        FUN_a00e0774(unit, (unsigned int)DAT_a80261f0, (unsigned int)DAT_a80261c8, (unsigned int)DAT_a80261a0, z);
        FUN_a00e0774(unit, (unsigned int)DAT_a8026178, (unsigned int)DAT_a8026150, (unsigned int)DAT_a8026128, x);
        FUN_a00e0774(unit, (unsigned int)DAT_a8026100, (unsigned int)DAT_a80260d8, (unsigned int)DAT_a802b5d0, y);
        return;
    }
    FUN_a00e0774(unit, DAT_a80261f0[a], DAT_a80261c8[a], DAT_a80261a0[a], z);
    FUN_a00e0774(unit, DAT_a8026178[a], DAT_a8026150[a], DAT_a8026128[a], x);
    FUN_a00e0774(unit, DAT_a8026100[a], DAT_a80260d8[a], DAT_a802b5d0[a], y);
}
