/* dp_reg_read24  (FUN_a00a6e10)
 *
 * Read a 24-bit value from three byte registers of a DP receiver.
 *   receiver
 *   reg: first register
 * Returns: 24-bit value
 * Name basis: proven - registers reg..reg+2, low byte first; block table 0xA00B4D94
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the reads go through a static inline helper as in dp_reg_read16; the top byte is not masked.
 */
extern unsigned short dp_reg_bases[];

static inline unsigned int rd(unsigned int idx)
{
    return *(volatile unsigned int *)((idx << 2) | 0xcf000000);
}

/*
 * Read a 24-bit value from three byte registers of a DP receiver: register reg is the low byte, reg + 1 the
 * middle byte and reg + 2 the high byte. Returns 0 for a receiver above 1.
 *
 *   receiver: 0 or 1
 *   reg:      first (low) register
 */
unsigned int dp_reg_read24(unsigned int receiver, unsigned short reg)
{
    unsigned int idx, first_index, low, mid, high;

    idx = receiver & 0xff;
    if (idx > 1)
        return 0;
    first_index = dp_reg_bases[idx] + reg;
    low = rd(first_index);
    mid = rd(first_index + 1);
    high = rd(first_index + 2);
    return (((high << 8) | (mid & 0xff)) << 8) | (low & 0xff);
}
