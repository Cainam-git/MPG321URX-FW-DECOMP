/* hdmi_rx21_clear_lane_ctrl_all  (FUN_a00799b8)
 *
 * Clear bit 7 of the four HDMI 2.1 lane control registers.
 * Name basis: descriptive - bit 7 of 0x2178/0x2578/0x2978/0x3178
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00799b8 @ 0xa00799b8, flags -mcpu=v8 -Os -g.
 * Source form: hdmi_phy_write_bit is declared without a parameter list.
 */
extern void hdmi_phy_write_bit();

/* Clears bit 7 of registers 0x2178, 0x2578, 0x2978 and 0x3178 (the four HDMI 2.1 lanes).
 *   port: PHY page */
void hdmi_rx21_clear_lane_ctrl_all(unsigned char port)

{
  
  hdmi_phy_write_bit(0,7,port,0x2178);
  hdmi_phy_write_bit(0,7,port,0x2578);
  hdmi_phy_write_bit(0,7,port,0x2978);
  hdmi_phy_write_bit(0,7,port,0x3178);
  return;
}