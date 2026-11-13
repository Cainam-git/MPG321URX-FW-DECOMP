/* hdmi_phy_power_on_final_step  (FUN_a0073638)
 *
 * Clear the three control bits that finish the PHY power-on sequence.
 * Name basis: descriptive - bits 0x10, 8, 0x1E of PHY registers 0x3024 / 0x3034 / 0x3018; last step of
 *   hdmi_phy_set_power on
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0073638 @ 0xa0073638, flags -mcpu=v8 -Os -g.
 * Source form: hdmi_phy_write_bit is declared without a parameter list.
 */
extern void hdmi_phy_write_bit();

/* Clears bit 16 of PHY register 0x3024, bit 8 of 0x3034 and bit 30 of 0x3018. Last step of the
 * power-on sequence in hdmi_phy_set_power.
 *   phy: PHY page */
void hdmi_phy_power_on_final_step(unsigned char phy)

{
  
  hdmi_phy_write_bit(0,0x10,phy,0x3024);
  hdmi_phy_write_bit(0,8,phy,0x3034);
  hdmi_phy_write_bit(0,0x1e,phy,0x3018);
  return;
}