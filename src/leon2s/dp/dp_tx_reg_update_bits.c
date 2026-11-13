/* dp_tx_reg_update_bits  (FUN_a00a7940)
 *
 * Set or clear masked bits of a byte register of a DP / eDP transmitter.
 *   port: unit
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: proven - block table 0xA00B4D7A, outputs 0..4
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Same code shape as dp_tx_phy_reg_update_bits (table dp_tx_phy_reg_bases, 2 outputs). Source forms: the load address uses
 * ((unsigned)reg << 16) >> 16 and the store address (unsigned short)reg, which keeps two separate truncations;
 * the table entry is read again for the store; the value is held in an unsigned char.
 */
extern unsigned char dp_tx_reg_bases;

/*
 * Set or clear the bits of mask in a byte register of a DP transmitter output (0 = DPTX, 1..4 = eDP).
 * Outputs above 4 are ignored. Read-modify-write on the register of dp_tx_reg_read8.
 *
 *   port: 0..4
 *   reg:  register number
 *   mask: bits to change
 *   mode: 1 = set the bits, any other value = clear them
 *
 * The parameters are unsigned int: the routine extends them itself.
 */
void dp_tx_reg_update_bits(unsigned int port, short reg, unsigned int mask, unsigned int mode)
{
    unsigned int addr;
    unsigned char value;

    if ((port & 0xff) < 5) {
        addr = reg;
        addr = ((*(unsigned short *)(&dp_tx_reg_bases + (port & 0xff) * 2) + ((addr << 16) >> 16)) * 4) | 0xcf000000;
        value = *(unsigned int *)addr;
        if ((mode & 0xff) == 1)
            value |= mask;
        else
            value &= ~mask;
        *(unsigned int *)(((*(unsigned short *)(&dp_tx_reg_bases + (port & 0xff) * 2) + (unsigned short)reg) * 4)
                          | 0xcf000000) = value & 0xff;
    }
}
