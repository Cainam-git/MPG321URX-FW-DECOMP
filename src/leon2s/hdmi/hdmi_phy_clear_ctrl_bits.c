/* hdmi_phy_clear_ctrl_bits  (FUN_a0073704)
 *
 * Clear bits 0 and 1 of the PHY control register 0x3600.
 * Name basis: descriptive - callers hdmi_phy_set_power off, DRV_HDMI21_Set_PHY,
 *   DRV_HDMI21_LTS_STS_InitialSettings
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073704 @ 0xa0073704, flags -mcpu=v8 -Os -g.
 * Source form: hdmi_phy_write_bit is declared without a parameter list.
 */
extern int hdmi_phy_write_bit();

/* Clears bits 0 and 1 of PHY register 0x3600.
 *   phy: PHY page */
void hdmi_phy_clear_ctrl_bits(unsigned char phy)

{
  
  hdmi_phy_write_bit(0,0,phy,0x3600);
  hdmi_phy_write_bit(0,1,phy,0x3600);
  return;
}