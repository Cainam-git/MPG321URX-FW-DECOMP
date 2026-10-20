/* leon2m FUN_a00e2690 @ 0xa00e2690-0xa00e2714 (33 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/33 mismatches.
 * Code facts: params unit, a, b. If a > 9: FUN_a00df80c(); FUN_a00e0bc0(); tail log
 * FUN_a00df170(string 0x199788, a). Else if b > 9: same two calls, tail log (string 0x199768, b).
 * Else FUN_a00e0774(unit, 0x215, 0xf0, 4, a) and tail FUN_a00e0774(unit, 0x1ef, 0xf, 0, b)
 * (e0774 is a 5-arg wrapper: FUN_a00e05d8(r0, r1, r2, r4 << r3)). void.
 * Fixes vs the autoc draft (82.35): BEHAVIOUR: both e0774 calls take a 5th arg (a, then b); in the
 * b arm df80c runs BEFORE e0bc0 (draft swapped); FUN_a00df80c takes no args (it overwrites %o0).
 * Aids: none.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00df80c(void);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0bc0(void);
extern const char s_00199788[];
extern const char s_00199768[];

void FUN_a00e2690(unsigned int unit, unsigned int a, unsigned int b)
{
    if (a > 9) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_00199788, a);
        return;
    }
    if (b > 9) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_00199768, b);
        return;
    }
    FUN_a00e0774(unit, 0x215, 0xf0, 4, a);
    FUN_a00e0774(unit, 0x1ef, 0xf, 0, b);
}
