/* dp_tx_phy_power_down_edp_unit  (FUN_a00a9e74)
 *
 * Write the fixed power-down register list of the eDP transmitter PHY unit.
 * Name basis: derived - 25 dp_tx_phy_reg_write8(1, ..) writes; callers input_power_off_receivers_mode0/1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a9e74 @ 0xa00a9e74 (-mcpu=v8 -Os -g)
 * Source form: the register numbers and values are plain constants in the call order of the firmware.
 */
#define PHY_UNIT_EDP 1 /* PHY unit used by eDP outputs 1..4 */

extern void dp_tx_phy_reg_write8(unsigned int unit, unsigned short reg, unsigned int value);

/*
 * Write the fixed power-down register list of the eDP transmitter PHY unit (unit 1): 25 register writes, no
 * waits. It starts with register 0xE7 = 0x70, then writes the registers that dp_tx_phy_init_edp_unit set up
 * at start-up with the opposite values: 0x44, 0x67, 0x8A and 0xAD to 0 and the lane groups 0x46.., 0x3E.. to
 * 0, while 0x4A, 0x6D, 0x90 and 0xB3 get 0xFF (they get 0 at start-up). It ends with registers 0xE5, 0x1B,
 * 0x1C, 0xE9, 0xC6, 0x1A and 0 set to 0x82, 0x22, 0x22, 4, 4, 0x23 and 0.
 * Called by input_power_off_receivers_mode0 and input_power_off_receivers_mode1, just before
 * dp_tx_phy_power_down_dptx_unit.
 */
void dp_tx_phy_power_down_edp_unit(void)

{
  
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe7, 0x70);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x44, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x67, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x8a, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xad, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x46, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x69, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x8c, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xaf, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x3e, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x61, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x84, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xa7, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x3b, 0);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x4a, 0xff);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x6d, 0xff);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x90, 0xff);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xb3, 0xff);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe5, 0x82);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x1b, 0x22);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x1c, 0x22);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xe9, 4);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0xc6, 4);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0x1a, 0x23);
  dp_tx_phy_reg_write8(PHY_UNIT_EDP, 0, 0);
  return;
}
