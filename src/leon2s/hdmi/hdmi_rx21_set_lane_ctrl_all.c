/* hdmi_rx21_set_lane_ctrl_all  (FUN_a00798fc)
 *
 * Set the control field and bit 7 of the four HDMI 2.1 lane registers.
 * Name basis: descriptive - field 0x38000000 of 0x217C.. and bit 7 of 0x2178..; pair of
 *   hdmi_rx21_clear_lane_ctrl_all
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00798fc @ 0xa00798fc, flags -mcpu=v8 -Os -g.
 * Source form: the callees are declared without parameter lists.
 */
extern void hdmi_phy_write_bit();
extern void hdmi_phy_update_reg();

/* For the four HDMI 2.1 lanes: sets the top byte of registers 0x217c, 0x257c, 0x297c and 0x317c to
 * 0x38, then sets bit 7 of registers 0x2178, 0x2578, 0x2978 and 0x3178.
 *   port: PHY page */
void hdmi_rx21_set_lane_ctrl_all(unsigned char port)

{
  
  hdmi_phy_update_reg(port,0x217c,0xffffff,0x38000000);
  hdmi_phy_update_reg(port,0x257c,0xffffff,0x38000000);
  hdmi_phy_update_reg(port,0x297c,0xffffff,0x38000000);
  hdmi_phy_update_reg(port,0x317c,0xffffff,0x38000000);
  hdmi_phy_write_bit(1,7,port,0x2178);
  hdmi_phy_write_bit(1,7,port,0x2578);
  hdmi_phy_write_bit(1,7,port,0x2978);
  hdmi_phy_write_bit(1,7,port,0x3178);
  return;
}