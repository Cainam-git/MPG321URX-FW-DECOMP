/* FUN_a00a6da8 (leon2s, 0xa00a6da8-0xa00a6e10, 104 bytes, 26 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * block = (u8)param_1; returns 0 when block > 1. Otherwise val = DAT_a00b4d94[block] (u16 table of block
 * bases) + param_2; reads the registers 0xcf000000 | (val << 2) and 0xcf000000 | ((val + 1) << 2) and
 * returns (u16)((hi << 8) | (lo & 0xff)). Same register space as FUN_a00f1690 (leon2m).
 * Source form: the high register value is not masked to a byte (same value after the u16 truncation;
 * firmware: sll 8 of the full word, then the u16 return truncation); the reads go through a static inline
 * register-read helper rd(idx) (the firmware keeps 'add 1' then 'sll 2' for the second address; an
 * open-coded (val + 1) * 4 folds to val*4 + 4).
 */
extern unsigned short DAT_a00b4d94[];

static inline unsigned int rd(unsigned int idx)
{
    return *(volatile unsigned int *)((idx << 2) | 0xcf000000);
}

unsigned short FUN_a00a6da8(unsigned int param_1, unsigned short param_2)
{
    unsigned int idx, val, lo, hi;

    idx = param_1 & 0xff;
    if (idx > 1)
        return 0;
    val = DAT_a00b4d94[idx] + param_2;
    lo = rd(val);
    hi = rd(val + 1);
    return (unsigned short)((hi << 8) | (lo & 0xff));
}
