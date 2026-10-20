/* leon2s FUN_a008f990 @ 0xa008f990-0xa008f9c0 (12 words), flags -mcpu=v8 -Os -g.
 * One parameter t0. now = FUN_a00b2064(); d = now - t0, minus 1 more when now < t0 (unsigned wrap);
 * returns d >= 0x33 on the full word (unsigned; firmware 'cmp d, 0x33; subx %g0, -1' = 1 - carry).
 * Source form: d set in both arms of an if/else on now >= t0; the limit 0x33 is a local (a literal is
 * canonicalised to 'd > 0x32' = branch; with the constant known only after cse the comparison stays GEU and
 * gives the firmware 'cmp; subx %g0, -1'; same lever as 'n = 4' in FUN_a00a8230).
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
