/* hdmi_reg_read24  (FUN_a00a6668)
 *
 * Read a 24-bit value from three byte registers of an HDMI 2.0 receiver.
 *   receiver
 *   reg: first register
 * Returns: 24-bit value
 * Name basis: proven - registers reg..reg+2, low byte first; block table 0xA00B4D9C
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a6668 @ 0xa00a6668 flags -mcpu=v8 -Os -g.
 * Source form: the receiver test is written as a mask ((receiver & 0xff) >= 2 gives mask 0, else all ones), so
 * receivers 2 and above read the registers of block 0.
 */
extern unsigned short hdmi_reg_bases[];

/* Read three byte registers of an HDMI 2.0 receiver as one 24-bit value: reg is the low byte, reg + 1 the
   middle byte, reg + 2 the high byte. Register address = 0xCF000000 | ((base + n) * 4). A receiver number
   of 2 or more reads receiver 0's registers. */
unsigned int hdmi_reg_read24(unsigned int receiver, unsigned int reg)
{
    unsigned int low = receiver & 0xff;
    unsigned int mask = (low >= 2) - 1;
    unsigned int index = (receiver & mask) & 0xff;
    unsigned int first = hdmi_reg_bases[index] + (unsigned short)reg;
    return (*(volatile unsigned int *)(0xcf000000 | ((first + 2) << 2)) << 8 |
            *(volatile unsigned int *)(0xcf000000 | ((first + 1) << 2))) << 8 |
           *(volatile unsigned int *)(0xcf000000 | (first << 2));
}
