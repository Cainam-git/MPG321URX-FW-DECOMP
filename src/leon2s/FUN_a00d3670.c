/* leon2s FUN_a00d3670 @ 0xa00d3670-0xa00d36a4 (13 words), flags -mcpu=v8 -Os -g.
 * Code facts: timeout test of the 0xcf03c80c == 0x99 state machine FUN_a00d3c40 (its only caller, the c24 != 1 arm):
 * t0 = _DAT_a8078c20 (stamped by FUN_a00d3c40 with func_0xa0fc2064() when FUN_a00d2e00() == 1), now =
 * func_0xa0fc2064() (ROM tick counter outside the image); d = now - t0, minus 1 more when now < t0 (wrap);
 * returns 1 when d >= 0xc9 (more than 200 ticks), else 0 (cmp 0xc9; subx). Same shape as FUN_a008f990 (limit 0x33).
 * This machine reports to 0xd0013ffc, not to mailbox portal 1; the Big chip's keep-going bit comes from
 * FUN_a00908d0 rec+0xa6. Fix vs the autoc draft: BEHAVIOUR: the draft used a
 * parameter instead of func_0xa0fc2064()'s return. Matching form: the FUN_a008f990 form (t0 read before the call,
 * u32 limit local). Aids: none.
 */
extern unsigned int _DAT_a8078c20;
extern unsigned int func_0xa0fc2064(void);

int FUN_a00d3670(void)
{
    unsigned int t0 = _DAT_a8078c20;
    unsigned int now = func_0xa0fc2064();
    unsigned int d;
    unsigned int lim = 0xc9;

    if (now >= t0)
        d = now - t0;
    else
        d = now - t0 - 1;
    return d >= lim;
}
