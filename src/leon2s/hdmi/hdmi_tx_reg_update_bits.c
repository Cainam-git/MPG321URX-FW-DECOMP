/* hdmi_tx_reg_update_bits  (FUN_a00a80cc)
 *
 * Set or clear masked bits of a byte register of an HDMI transmitter bank.
 *   port: HDMI TX port
 *   bank
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: proven - block table 0xA00B4D44; mode 1 sets, else clears
 *
 * Matching notes
 * --------------
 * FUN_a00a80cc (leon2s 0xa00a80cc), flags -mcpu=v8 -Os -g.
 * Source forms: the range test uses two flag variables, as in hdmi_tx_reg_write8; the load address uses a copy
 * of reg truncated as ((addr << 16) >> 16) and the store uses (unsigned short)reg, and both addresses repeat the
 * full table index expression; this gives the firmware's register copies.
 */
/* Base of the registers of each bank of each HDMI transmitter port: 16-bit entries, six banks per port
   (index port * 6 + bank). Bank 1 is the PHY, bank 2 the HDR dynamic metadata packet, bank 3 the VTEM packet. */
extern unsigned char hdmi_tx_reg_bases;

/* Set (mode 1) or clear (any other mode) the bits of mask in the low byte of register reg of a bank (0..5)
   of HDMI transmitter port 0 or 1. Any other port or bank changes nothing. The register is read, changed
   and written back. */
void hdmi_tx_reg_update_bits(unsigned int port, unsigned int bank, short reg, unsigned int mask, unsigned int mode)
{
    unsigned int bad_port;
    unsigned int bad_bank;
    unsigned int addr;
    unsigned char value;

    bad_port = (port & 0xff) > 1;
    bad_bank = (bank & 0xff) > 5;
    if (bad_port || bad_bank)
        return;
    addr = reg;
    addr = ((*(unsigned short *)(&hdmi_tx_reg_bases + ((port & 0xff) * 6 + (bank & 0xff)) * 2) + ((addr << 16) >> 16))
            * 4) | 0xcf000000;
    value = *(volatile unsigned int *)addr;
    if ((mode & 0xff) == 1)
        value |= mask;
    else
        value &= ~mask;
    *(volatile unsigned int *)(((*(unsigned short *)(&hdmi_tx_reg_bases + ((port & 0xff) * 6 + (bank & 0xff)) * 2)
                                 + (unsigned short)reg) * 4) | 0xcf000000) = value & 0xff;
}
