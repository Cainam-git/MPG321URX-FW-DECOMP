/* FUN_a00a6e10 (leon2s 0xa00a6e10-0xa00a6e8c, 124 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Three-register read of FUN_a00a6da8's register space: returns 0 when block > 1. Otherwise val =
 * DAT_a00b4d94[block] + reg; reads the registers at val, val + 1 and val + 2 (address 0xcf000000 | (idx << 2))
 * and returns (((r2 << 8) | (r1 & 0xff)) << 8) | (r0 & 0xff), with r2 unmasked.
 * The reads go through the static inline helper rd(idx) as in FUN_a00a6da8.
 */
extern unsigned short DAT_a00b4d94[];

static inline unsigned int rd(unsigned int idx)
{
    return *(volatile unsigned int *)((idx << 2) | 0xcf000000);
}

unsigned int FUN_a00a6e10(unsigned int param_1, unsigned short param_2)
{
    unsigned int idx, val, b0, b1, b2;

    idx = param_1 & 0xff;
    if (idx > 1)
        return 0;
    val = DAT_a00b4d94[idx] + param_2;
    b0 = rd(val);
    b1 = rd(val + 1);
    b2 = rd(val + 2);
    return (((b2 << 8) | (b1 & 0xff)) << 8) | (b0 & 0xff);
}
