/* leon2s FUN_a00a68d0 @ 0xa00a68d0 (-mcpu=v8 -Os -g)
 * k = p1 & 0xff. For k <= 1: v = halfword k of the table at 0xA00B4D9C + p2; with R(x) = register 0xCF000000 | (x
 * << 2) returns ((R(v + 1) << 8) | (R(v) & 0xff)) as 16 bits. Other k return 0. Same code as FUN_a00a6da8 with
 * other constants.
 * See FUN_a00a6da8 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned short DAT_a00b4d9c[];

static inline unsigned int rd(unsigned int idx)
{
    return *(volatile unsigned int *)((idx << 2) | 0xcf000000);
}

unsigned short FUN_a00a68d0(unsigned int param_1, unsigned short param_2)
{
    unsigned int idx, val, lo, hi;

    idx = param_1 & 0xff;
    if (idx > 1)
        return 0;
    val = DAT_a00b4d9c[idx] + param_2;
    lo = rd(val);
    hi = rd(val + 1);
    return (unsigned short)((hi << 8) | (lo & 0xff));
}
