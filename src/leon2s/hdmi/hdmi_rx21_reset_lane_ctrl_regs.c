/* hdmi_rx21_reset_lane_ctrl_regs  (FUN_a007abbc)
 *
 * Reset the control registers of the four HDMI 2.1 lanes.
 * Name basis: descriptive - bit 7 cleared and field set on 0x2178..0x317C
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007abbc @ 0xa007abbc, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes, as the decompiler wrote them.
 */
extern void hdmi_phy_write_bit();
extern void hdmi_phy_update_reg();

/*
 * For each of the four HDMI 2.1 lanes of a PHY (register pages 0x21xx, 0x25xx, 0x29xx, 0x31xx): clear bit 7 of
 * register 0x178 (the register that holds RCT and CFT) and set byte 3 of register 0x17C to 0x18.
 * Same writes as hdmi_phy_reset_tmds_channel_regs, which does them for the three TMDS channel pages.
 * port: PHY index. Called by hdmi_phy_reset_all_lane_regs.
 */
void hdmi_rx21_reset_lane_ctrl_regs(unsigned char port)
{
  hdmi_phy_write_bit(0, 7, port, 0x2178);
  hdmi_phy_write_bit(0, 7, port, 0x2578);
  hdmi_phy_write_bit(0, 7, port, 0x2978);
  hdmi_phy_write_bit(0, 7, port, 0x3178);
  hdmi_phy_update_reg(port, 0x217c, 0xffffff, 0x18000000);
  hdmi_phy_update_reg(port, 0x257c, 0xffffff, 0x18000000);
  hdmi_phy_update_reg(port, 0x297c, 0xffffff, 0x18000000);
  hdmi_phy_update_reg(port, 0x317c, 0xffffff, 0x18000000);
}
