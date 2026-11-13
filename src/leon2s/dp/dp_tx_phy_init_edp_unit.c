/* dp_tx_phy_init_edp_unit  (FUN_a00a9c4c)
 *
 * Write the fixed start-up register list of the eDP transmitter PHY unit.
 * Name basis: derived - 33 dp_tx_phy_reg_write8(1, ..) writes with two 500-step delays; tail of
 *   dp_tx_phy_set_link_rate for eDP
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a9c4c @ 0xa00a9c4c (-mcpu=v8 -Os -g)
 * Source form: the register numbers and values are plain constants in the call order of the firmware, the
 * delays are calls of timer_delay_units(500).
 */
#define PHY_UNIT_EDP 1 /* PHY unit used by eDP outputs 1..4 */
#define PHY_SETTLE_DELAY 500 /* argument of timer_delay_units between the steps */

extern void dp_tx_phy_reg_write8(unsigned int unit, unsigned short reg, unsigned int value);
extern int timer_delay_units();

/*
 * Write the fixed start-up register list of the eDP transmitter PHY unit (unit 1). 33 register writes in
 * three steps:
 *  1. 13 writes that end with register 0xE5 = 0xC2, then a wait (timer_delay_units(500));
 *  2. register 0xE5 = 0x42 and 0xE8 = 2, then a second wait;
 *  3. 18 writes: registers 0x3B, 0x5E, 0x81 and 0xA4 (0x23 apart) get 0x81; each of the groups 0x46.., 0x4A..
 *     and 0x3E.. (four registers, 0x23 apart) gets 0 or 0xFF (0x46 group: 0, FF, FF, 0; 0x4A group: all 0;
 *     0x3E group: 0, FF, FF, 0); registers 0x44 and 0xAD get 0.
 * dp_tx_phy_power_down_edp_unit writes to the same registers again at power-off.
 * Called at the end of dp_tx_phy_set_link_rate for an output other than 0 when its last argument (go) is set.
 */
void dp_tx_phy_init_edp_unit(void)

{
  
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe5, 0x82);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe8, 0x22);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe7, 0x70);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xea, 3);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x16, 1);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x1b, 0x60);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x1c, 6);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe9, 5);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xc6, 5);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x1a, 0x27);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe7, 0x71);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 5, 1);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe5, 0xc2);
  timer_delay_units(PHY_SETTLE_DELAY);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe5, 0x42);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe8, 2);
  timer_delay_units(PHY_SETTLE_DELAY);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x3b, 0x81);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x5e, 0x81);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x81, 0x81);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xa4, 0x81);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x46, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x69, 0xff);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x8c, 0xff);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xaf, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x4a, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x6d, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x90, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xb3, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x3e, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x61, 0xff);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x84, 0xff);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xa7, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x44, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xad, 0);
  return;
}
