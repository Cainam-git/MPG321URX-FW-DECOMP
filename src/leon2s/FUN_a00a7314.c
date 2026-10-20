/* FUN_a00a7314 (leon2s, 0xa00a7314-0xa00a7368, 84 bytes, 21 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: port = (u8)param_1; page register R = 0xcf000000 | ((port + 0xf401) << 2); saves R,
 * writes the high byte of param_2 (u16) to R, reads the word at 0xce008100 + (port << 8) +
 * (param_2 & 0xff), writes the saved low byte back to R, returns the word read.
 * Fixes vs draft: returns the full word (unsigned int; the draft's u8 return added an 'and 0xff'),
 * the low byte of param_2 is its own variable 'lo' (fw computes it before 'port << 8'), and the
 * hardware accesses are volatile (0xcf000000 / 0xce000000 register space). Aids: none.
 */
unsigned int FUN_a00a7314(unsigned int param_1, unsigned short param_2)
{
    unsigned int idx = (param_1 & 0xff) + 0xf401;
    volatile unsigned int *reg = (volatile unsigned int *)((idx << 2) | 0xcf000000);
    unsigned int old = *reg;
    unsigned int lo = param_2 & 0xff;
    unsigned int table_addr = 0xce008100 + ((param_1 & 0xff) << 8) + lo;
    unsigned int result;

    *reg = (param_2 >> 8) & 0xff;
    result = *(volatile unsigned int *)table_addr;
    *reg = old & 0xff;
    return result;
}
