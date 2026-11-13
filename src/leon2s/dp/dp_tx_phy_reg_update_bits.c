/* dp_tx_phy_reg_update_bits  (FUN_a00a7d04)
 *
 * Set or clear masked bits of a byte register of a DP transmitter PHY unit.
 *   unit: unit 0/1
 *   reg: register
 *   mask: bits
 *   mode: 1 = set
 * Name basis: derived - block table 0xA00B4D6C, units 0/1
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the store address uses (unsigned short)reg (firmware srl 16), like the load; the table entry is
 * read again for the store.
 */

extern unsigned char dp_tx_phy_reg_bases;

/*
 * Set or clear the bits of mask in a byte register of a DP transmitter PHY unit. Units above 1 are ignored.
 * Read-modify-write on the register of dp_tx_phy_reg_write8.
 *
 *   unit: 0 or 1
 *   reg:  register number
 *   mask: bits to change
 *   mode: 1 = set the bits, any other value = clear them
 */
void dp_tx_phy_reg_update_bits(unsigned int unit, short reg, unsigned int mask, unsigned int mode)
{
  unsigned int addr;
  unsigned char value;
  if ((unit & 0xff) < 2)
  {
    addr = reg;
    addr = (((*((unsigned short *) ((&dp_tx_phy_reg_bases) + ((unit & 0xff) * 2)))) + ((addr << 16) >> 16)) * 4) | 0xcf000000;
    value = *((unsigned int *) addr);
    if ((mode & 0xff) == 1)
    {
      value |= mask;
    }
    else
    {
      value &= ~mask;
    }
    *((unsigned int *) ((((*((unsigned short *) ((&dp_tx_phy_reg_bases) + ((unit & 0xff) * 2)))) + (unsigned short)reg) * 4) | 0xcf000000)) = value & 0xff;
  }
}
