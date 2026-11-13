/* dp_tx_phy_reg_read8  (FUN_a00a7d88)
 *
 * Read a byte register of a DP transmitter PHY unit.
 *   unit
 *   reg: register
 * Returns: byte, 0 for an invalid unit
 * Name basis: derived - block table 0xA00B4D6C, units 0/1
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the base table is declared as an unsigned char and the entry is read through a cast to
 * unsigned short at byte offset unit * 2.
 */
extern unsigned char dp_tx_phy_reg_bases;

/*
 * Read a byte register of a DP transmitter PHY unit (unit 0 = DPTX, unit 1 = the one used for the eDP
 * outputs). Returns 0 for a unit above 1. Same address scheme as dp_tx_phy_reg_write8.
 *
 *   unit: 0 or 1
 *   reg:  register number
 */
unsigned int dp_tx_phy_reg_read8(unsigned int unit, unsigned short reg)

{
  unsigned int value;
  
  value = 0;
  if ((unit & 0xff) < 2) {
    value = *(volatile unsigned int *)((*(unsigned short *)(&dp_tx_phy_reg_bases + (unit & 0xff) * 2) + (reg & 0xffff))
                      * 4 | 0xcf000000) & 0xff;
  }
  return value;
}
