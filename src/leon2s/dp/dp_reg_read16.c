/* dp_reg_read16  (FUN_a00a6da8)
 *
 * Read a 16-bit value from two byte registers of a DP receiver.
 *   receiver
 *   reg: first register
 * Returns: 16-bit value
 * Name basis: proven - registers reg, reg+1; used for the timing registers 0x94..0x9A
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the high register value is not masked to a byte (same value after the unsigned short return;
 * the firmware shifts the full word); the reads go through a static inline helper (the firmware keeps 'add 1'
 * then 'sll 2' for the second address; an open-coded (index + 1) * 4 folds to index * 4 + 4).
 */
extern unsigned short dp_reg_bases[];

static inline unsigned int rd(unsigned int idx)
{
    return *(volatile unsigned int *)((idx << 2) | 0xcf000000);
}

/*
 * Read a 16-bit value from two byte registers of a DP receiver: register reg is the low byte, register
 * reg + 1 the high byte. Returns 0 for a receiver above 1.
 *
 *   receiver: 0 or 1
 *   reg:      first (low) register
 */
unsigned short dp_reg_read16(unsigned int receiver, unsigned short reg)
{
    unsigned int idx, first_index, low, high;

    idx = receiver & 0xff;
    if (idx > 1)
        return 0;
    first_index = dp_reg_bases[idx] + reg;
    low = rd(first_index);
    high = rd(first_index + 1);
    return (unsigned short)((high << 8) | (low & 0xff));
}
