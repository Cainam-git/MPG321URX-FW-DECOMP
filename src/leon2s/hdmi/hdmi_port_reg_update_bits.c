/* hdmi_port_reg_update_bits  (FUN_a00a7e14)
 *
 * Set or clear masked bits of a byte register of any HDMI receiver (ports 0..3).
 *   port: unit
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: proven - block table 0xA00B4D64, ports 0..3
 *
 * Matching notes
 * --------------
 * FUN_a00a7e14 (leon2s 0xa00a7e14), flags -mcpu=v8 -Os -g.
 * Source forms: the load address uses ((u32)reg << 16) >> 16 and the store address (unsigned short)reg, which
 * keeps two separate truncations; the store looks up the table entry again; the value is an unsigned char.
 */
extern unsigned char hdmi_port_reg_bases;      /* 16-bit register bases of HDMI ports 0..3 */

/* Set (mode 1) or clear (any other mode) the bits of mask in the low byte of register reg of HDMI port 0..3.
   Larger port numbers change nothing. The register is read, changed and written back. */
void hdmi_port_reg_update_bits(unsigned int port, short reg, unsigned int mask, unsigned int mode)
{
    unsigned int addr;
    unsigned char value;

    if ((port & 0xff) < 4) {
        addr = reg;
        addr = ((*(unsigned short *)(&hdmi_port_reg_bases + (port & 0xff) * 2) + ((addr << 16) >> 16)) * 4) | 0xcf000000;
        value = *(unsigned int *)addr;
        if ((mode & 0xff) == 1)
            value |= mask;
        else
            value &= ~mask;
        *(unsigned int *)(((*(unsigned short *)(&hdmi_port_reg_bases + (port & 0xff) * 2) + (unsigned short)reg) * 4)
                          | 0xcf000000) = value & 0xff;
    }
}
