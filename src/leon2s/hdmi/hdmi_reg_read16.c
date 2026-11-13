/* hdmi_reg_read16  (FUN_a00a68d0)
 *
 * Read a 16-bit value from two byte registers of an HDMI 2.0 receiver.
 *   receiver
 *   reg: first register
 * Returns: 16-bit value
 * Name basis: proven - registers reg, reg+1, low byte first; block table 0xA00B4D9C
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a68d0 @ 0xa00a68d0, flags -mcpu=v8 -Os -g.
 * Source form: the register read is an inline helper taking the register index.
 */
extern unsigned short hdmi_reg_bases[];

static inline unsigned int read_reg(unsigned int index)
{
    return *(volatile unsigned int *)((index << 2) | 0xcf000000);
}

/* Read registers reg (low byte) and reg + 1 (high byte) of HDMI 2.0 receiver 0 or 1 as one 16-bit value.
   Any other receiver returns 0. */
unsigned short hdmi_reg_read16(unsigned int receiver, unsigned short reg)
{
    unsigned int index, first, low, high;

    index = receiver & 0xff;
    if (index > 1)
        return 0;
    first = hdmi_reg_bases[index] + reg;
    low = read_reg(first);
    high = read_reg(first + 1);
    return (unsigned short)((high << 8) | (low & 0xff));
}
