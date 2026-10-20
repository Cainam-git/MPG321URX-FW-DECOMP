/* leon2s FUN_a00d3670 @ 0xa00d3670-0xa00d36a4 (13 words), flags -mcpu=v8 -Os -g.
 * Its only caller is FUN_a00d3c40 (the c24 != 1 arm). t0 = _DAT_a8078c20 (stored by FUN_a00d3c40 with
 * func_0xa0fc2064() when FUN_a00d2e00() == 1), now = func_0xa0fc2064() (ROM call outside the image);
 * d = now - t0, minus 1 more when now < t0 (wrap); returns 1 when d >= 0xc9 (d > 200), else 0 (cmp 0xc9;
 * subx). Same shape as FUN_a008f990 (limit 0x33). The value compared is func_0xa0fc2064()'s return.
 * Source form: the FUN_a008f990 form (t0 read before the call, u32 limit local).
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
