/* leon2m FUN_a00fe820 @ 0xa00fe820-0xa00fe880 (24 words incl. the unreachable ret/restore pair
 * FUN_a00fe878), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/24 mismatches.
 * Code facts: only for p == 6 or 7 ((u8)(p - 6) <= 1): r = FUN_a00f1a90(p, 5) (register read);
 * v = on ? (r & ~1) | 8 : (r & ~8) | 1; tail call FUN_a00f1ad4(p, 5, (u8)v) (register write).
 * void. FUN_a00f1a90 takes 2 args (the draft passed a 3rd) and its value is used unmasked
 * (int-style return); FUN_a00f1ad4 = src/leon2m/FUN_a00f1ad4.c (u8, u8, u8).
 * Fix vs the autoc draft (80.00): the arm test is '!on' with the (r & ~8) | 1 arm FIRST
 * (if/else; the 'default then override' form and the 'if (on)' order give other block layouts:
 * 83.33 / 79.17); void, 2 params. Aids: none.
 */
extern unsigned int FUN_a00f1a90(unsigned char, unsigned char);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);

void FUN_a00fe820(unsigned char p, unsigned char on)
{
    unsigned int r;
    unsigned int v;

    if ((unsigned char)(p - 6) > 1)
        return;
    r = FUN_a00f1a90(p, 5);
    if (!on)
        v = (r & ~8) | 1;
    else
        v = (r & ~1) | 8;
    FUN_a00f1ad4(p, 5, v);
}
