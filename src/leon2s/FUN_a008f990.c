/* leon2s FUN_a008f990 @ 0xa008f990-0xa008f9c0 (12 words), flags -mcpu=v8 -Os -g.
 * Code facts: now = FUN_a00b2064(); d = now - t0, minus 1 more when now < t0 (unsigned wrap); returns
 * d >= 0x33 (unsigned; fw 'cmp d, 0x33; subx %g0, -1' = 1 - carry).
 * Fix vs the autoc draft (78.57): BEHAVIOUR - the result is d >= 0x33 on the full word (the draft returned
 * (u8)d == 0x33); one parameter. Source forms: d set in both arms of an if/else on now >= t0; the limit 0x33 is a
 * local (a literal is canonicalised to 'd > 0x32' = branch; with the constant known only after cse the
 * comparison stays GEU and gives the fw 'cmp; subx %g0, -1'; same lever as 'n = 4' in FUN_a00a8230). Aids: none.
 */
extern unsigned int FUN_a00b2064(void);

int FUN_a008f990(unsigned int t0)
{
    unsigned int now = FUN_a00b2064();
    unsigned int d;
    unsigned int lim = 0x33;

    if (now >= t0)
        d = now - t0;
    else
        d = now - t0 - 1;
    return d >= lim;
}
