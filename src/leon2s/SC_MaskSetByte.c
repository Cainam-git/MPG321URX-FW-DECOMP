/* leon2s SC_MaskSetByte @ 0xa00a6440-0xa00a6544 (-mcpu=v8 -Os -g)
 * Register read-modify-write over the u16 offset list DAT_a00b4da0[id] (DAT_a00b4dc0[id] entries).
 * Register address = ((list[k] + off) * 4) | 0xcf000000; each write stores the low byte of
 * (old & ~mask) | val. n equal to the entry count: writes entries 0..n-1; n below the count: writes
 * entry n only; n above the count: prints s_a006c158 ("SC_MaskSetByte wrong access %d!!!") with 99
 * through FUN_a0073044.
 * Source form: mask and val are unsigned char parameters (callers pass them zero-extended) and both
 * stores are written as (unsigned char) conversions of the whole expression, so GCC narrows the
 * operations and keeps no extension of mask or val.
 */
extern unsigned short *DAT_a00b4da0[];
extern unsigned char DAT_a00b4dc0[];
extern char s_a006c158[];
extern int FUN_a0073044(const char *, ...);

#define REG(a) (*(volatile unsigned int *)((a) * 4 | 0xcf000000))

void SC_MaskSetByte(unsigned char id, unsigned char n, unsigned short off, unsigned char mask, unsigned char val)
{
    unsigned char i;
    volatile unsigned int *r;

    if (n == DAT_a00b4dc0[id]) {
        for (i = 0; i < n; i++)
            REG(DAT_a00b4da0[id][i] + off) = (unsigned char)(REG(DAT_a00b4da0[id][i] + off) & ~mask | val);
    } else if (n < DAT_a00b4dc0[id]) {
        r = &REG(DAT_a00b4da0[id][n] + off);
        *r = (unsigned char)(val | (*r & ~mask));
    } else {
        FUN_a0073044(s_a006c158, 99);
    }
}
