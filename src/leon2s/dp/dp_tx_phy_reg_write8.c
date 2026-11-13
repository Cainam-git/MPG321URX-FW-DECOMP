/* dp_tx_phy_reg_write8  (FUN_a00a7cc0)
 *
 * Write a byte register of a DP transmitter PHY unit.
 *   unit
 *   reg: register
 *   value
 * Name basis: derived - block table 0xA00B4D6C (unit 0 = 0x7500 DPTX, unit 1 = 0x7300 shared by eDP 1..4);
 *   long fixed write lists with delays
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the base table is declared as an unsigned char and the entry is read through a cast to
 * unsigned short at byte offset unit * 2; the store is through a non-volatile pointer.
 */
extern unsigned char dp_tx_phy_reg_bases;

/*
 * Write a byte register of a DP transmitter PHY unit (unit 0 = DPTX, unit 1 = the one used for the eDP
 * outputs). Units above 1 write nothing.
 *
 *   unit:  0 or 1
 *   reg:   register number
 *   value: only the low byte is written
 *
 * The register is the word at 0xCF000000 | ((base[unit] + reg) * 4), with the table dp_tx_phy_reg_bases
 * (0xA00B4D6C).
 */
void dp_tx_phy_reg_write8(unsigned int unit, unsigned short reg, unsigned int value)

{
  if ((unit & 0xff) < 2) {
    *(unsigned int *)(((unsigned int)*(unsigned short *)(&dp_tx_phy_reg_bases + (unit & 0xff) * 2) + (reg & 0xffff)) * 4 |
             0xcf000000) = value & 0xff;
  }
}
