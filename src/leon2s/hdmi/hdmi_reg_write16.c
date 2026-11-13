/* hdmi_reg_write16  (FUN_a00a66dc)
 *
 * Write a 16-bit value to two byte registers of one or both HDMI 2.0 receivers.
 *   receiver: receiver, 2 = both
 *   reg: first register
 *   value
 * Name basis: proven - registers reg, reg+1, low byte first; port 2 = both
 *
 * Matching notes
 * --------------
 * FUN_a00a66dc (leon2s 0xa00a66dc), flags -mcpu=v8 -Os -g.
 * Source forms: the inlined helper reg_addr() keeps (base + reg + 1) * 4 as add + shift; the bytes are
 * (unsigned char) casts of the unsigned short value.
 */
extern unsigned short hdmi_reg_bases[];

static __inline__ volatile unsigned int *reg_addr(unsigned int index)
{
    return (volatile unsigned int *)((index * 4) | 0xcf000000);
}

/* Write a 16-bit value to registers reg (low byte) and reg + 1 (high byte) of HDMI 2.0 receiver 0 or 1;
   receiver 2 writes both receivers, receiver 0 first. Larger numbers write nothing. */
void hdmi_reg_write16(unsigned int receiver, unsigned short reg, unsigned short value)
{
    unsigned char i;

    receiver &= 0xff;
    if (receiver > 2)
        return;
    if (receiver == 2) {
        i = 0;
        do {
            *reg_addr(hdmi_reg_bases[i] + reg) = (unsigned char)value;
            *reg_addr(hdmi_reg_bases[i] + reg + 1) = (unsigned char)(value >> 8);
            i++;
        } while (i <= 1);
    } else if (receiver <= 1) {
        *reg_addr(hdmi_reg_bases[receiver] + reg) = (unsigned char)value;
        *reg_addr(hdmi_reg_bases[receiver] + reg + 1) = (unsigned char)(value >> 8);
    }
}
