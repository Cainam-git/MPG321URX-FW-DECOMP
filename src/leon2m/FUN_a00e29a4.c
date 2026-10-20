/* leon2m FUN_a00e29a4 @ 0xa00e29a4-0xa00e2aec (82 words).
 * Parameters unit, a, b, x, y, z. If a > 9: FUN_a00df80c(), FUN_a00e0bc0() and the log call FUN_a00df170(string
 * 0x199788 "error: N_adj=%d, should be 0~9.", a). Else if b > 9: the same two calls and FUN_a00df170(string 0x199768,
 * b). Otherwise three FUN_a00e0774(unit, reg, mask, shift, value) calls whose register, mask and shift come from
 * entry a of 10-word tables: (0xa8025f70, 0xa8025f48, 0xa8025f20) with value z, (0xa8025ef8, 0xa8025ed0, 0xa8025ea8)
 * with x, and (0xa8025e80, 0xa8025e58, 0xa802b580) with y. b is only range-checked. The code also has a branch for a
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
extern unsigned int DAT_a8025f70[10], DAT_a8025f48[10], DAT_a8025f20[10];
extern unsigned int DAT_a8025ef8[10], DAT_a8025ed0[10], DAT_a8025ea8[10];
extern unsigned int DAT_a8025e80[10], DAT_a8025e58[10], DAT_a802b580[10];

void FUN_a00e29a4(unsigned int unit, unsigned int a, unsigned int b, unsigned int x, unsigned int y, unsigned int z)
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
        FUN_a00e0774(unit, (unsigned int)DAT_a8025f70, (unsigned int)DAT_a8025f48, (unsigned int)DAT_a8025f20, z);
        FUN_a00e0774(unit, (unsigned int)DAT_a8025ef8, (unsigned int)DAT_a8025ed0, (unsigned int)DAT_a8025ea8, x);
        FUN_a00e0774(unit, (unsigned int)DAT_a8025e80, (unsigned int)DAT_a8025e58, (unsigned int)DAT_a802b580, y);
        return;
    }
    FUN_a00e0774(unit, DAT_a8025f70[a], DAT_a8025f48[a], DAT_a8025f20[a], z);
    FUN_a00e0774(unit, DAT_a8025ef8[a], DAT_a8025ed0[a], DAT_a8025ea8[a], x);
    FUN_a00e0774(unit, DAT_a8025e80[a], DAT_a8025e58[a], DAT_a802b580[a], y);
}
