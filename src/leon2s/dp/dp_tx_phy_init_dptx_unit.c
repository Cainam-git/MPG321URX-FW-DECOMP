/* dp_tx_phy_init_dptx_unit  (FUN_a00aa00c)
 *
 * Write the fixed start-up register list of the DPTX transmitter PHY unit.
 * Name basis: derived - 25 writes to PHY unit 0 and control bank 0 with two delays; tail of
 *   dp_tx_phy_set_link_rate for output 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aa00c @ 0xa00aa00c (-mcpu=v8 -Os -g)
 * Source form: the register numbers and values are plain constants in the call order of the firmware; the
 * helpers keep their unprototyped declarations; the delays are calls of timer_delay_units(500).
 */
#define PHY_UNIT_DPTX 0 /* PHY unit and control bank of output 0 */
#define CTL_BANK_DPTX 0
#define PHY_SETTLE_DELAY 500 /* argument of timer_delay_units between the steps */

extern void dp_tx_ctl_reg_write8();
extern void dp_tx_ctl_reg_update_bits();
extern void dp_tx_phy_reg_write8(unsigned int unit, unsigned short reg, unsigned int value);
extern void dp_tx_phy_reg_update_bits();
extern int timer_delay_units();

/*
 * Write the fixed start-up register list of the DPTX transmitter PHY unit (unit 0) and its control bank 0:
 * 25 calls in three steps, with a wait (timer_delay_units(500)) after the 14th and after the 16th.
 * The update calls are (unit, register, mask, mode) with mode 1 = set the mask bits, 0 = clear them.
 *  1. PHY register 2 bit 3 cleared; 0xC = 0x10; 0xD bits 0x0A set; control register 8 bit 2 set; 0x3C bit 6
 *     cleared; control register 0x3F = 0x22; then PHY 0x3E bit 0 cleared, 0x30 bit 0 set, 0x34 bits 0x44 set,
 *     0x33 bits 0x30 and then 0x40 set, 0x3E bit 0 set and bit 3 cleared, 0x3C bits 0xC2 set. Wait.
 *  2. PHY 0x3C bit 7 cleared; control register 0x3F = 2. Wait.
 *  3. PHY 0x35 bit 0 set; 0x4A bits 0xF0 cleared; 0x44 = 0xFF; control register 0x11 = 0x80 and 0x12 = 0; then
 *     PHY 0x15 bit 4 cleared, 0xD bit 1 cleared and set again, 0x15 bit 4 set.
 * Called at the end of dp_tx_phy_set_link_rate for output 0 when its last argument (go) is set.
 */
void dp_tx_phy_init_dptx_unit(void)

{
  
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 2, 8, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_DPTX, 0xc, 0x10);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0xd, 10, 1);
  dp_tx_ctl_reg_update_bits(CTL_BANK_DPTX, 8, 4, 1);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x3c, 0x40, 0);
  dp_tx_ctl_reg_write8(CTL_BANK_DPTX, 0x3f, 0x22);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x3e, 1, 0);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x30, 1, 1);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x34, 0x44, 1);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x33, 0x30, 1);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x33, 0x40, 1);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x3e, 1, 1);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x3e, 8, 0);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x3c, 0xc2, 1);
  timer_delay_units(PHY_SETTLE_DELAY);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x3c, 0x80, 0);
  dp_tx_ctl_reg_write8(CTL_BANK_DPTX, 0x3f, 2);
  timer_delay_units(PHY_SETTLE_DELAY);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x35, 1, 1);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x4a, 0xf0, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_DPTX, 0x44, 0xff);
  dp_tx_ctl_reg_write8(CTL_BANK_DPTX, 0x11, 0x80);
  dp_tx_ctl_reg_write8(CTL_BANK_DPTX, 0x12, 0);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x15, 0x10, 0);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0xd, 2, 0);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0xd, 2, 1);
  dp_tx_phy_reg_update_bits(PHY_UNIT_DPTX, 0x15, 0x10, 1);
  return;
}
