/* hdmi_phy_power_off_first_step  (FUN_a0073680)
 *
 * Switch the six PHY control bits used at the start of power-off.
 * Name basis: descriptive - PHY registers 0x3004..0x3034; first step of hdmi_phy_set_power off
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073680 @ 0xa0073680, flags -mcpu=v8 -Os -g.
 * Source form: hdmi_phy_write_bit is declared without a parameter list.
 */
extern void hdmi_phy_write_bit();

/* Six single-bit writes to PHY registers: sets bit 16 of 0x3024, clears bit 16 of 0x3004, sets bit 8 of
 * 0x3034, clears bit 8 of 0x3014, sets bit 30 of 0x3018, clears bit 29 of 0x3018. Called at the start
 * of the power-off sequence in hdmi_phy_set_power.
 *   phy: PHY page */
void hdmi_phy_power_off_first_step(unsigned char phy)

{
  
  hdmi_phy_write_bit(1,0x10,phy,0x3024);
  hdmi_phy_write_bit(0,0x10,phy,0x3004);
  hdmi_phy_write_bit(1,8,phy,0x3034);
  hdmi_phy_write_bit(0,8,phy,0x3014);
  hdmi_phy_write_bit(1,0x1e,phy,0x3018);
  hdmi_phy_write_bit(0,0x1d,phy,0x3018);
  return;
}