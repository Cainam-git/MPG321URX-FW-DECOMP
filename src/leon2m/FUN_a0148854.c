/* leon2m FUN_a0148854 @ 0xa0148854-0xa0148868 (5 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/5 mismatches.
 * Code facts: leaf; reads byte +7 of the record DAT_a802e1a0 (0xa802e1a7, ldub) and returns 1 when it
 * is >= 5 (cmp 5; subx %g0,-1 = 1 - carry), else 0.
 * Fixes vs the autoc draft (37.50): real base DAT_a802e1a0 (the draft used the mid-record name
 * DAT_a802e1a7) and two early returns 'if (b > 4) return 1; return 0;': ifcvt then emits the fw
 * cmp 5 / subx scc; the expression, ternary and flag-variable forms all keep a branch (cmp 4; bgu).
 * Aids: none.
 */
extern unsigned char DAT_a802e1a0[];

unsigned char FUN_a0148854(void)
{
    if (DAT_a802e1a0[7] > 4)
        return 1;
    return 0;
}
