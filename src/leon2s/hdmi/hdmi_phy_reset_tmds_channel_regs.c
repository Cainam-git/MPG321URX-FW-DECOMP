/* hdmi_phy_reset_tmds_channel_regs  (FUN_a007a708)
 *
 * Reset the control registers of the three TMDS channels.
 * Name basis: descriptive - bit 7 cleared and field set on 0x1178/0x1578/0x1978
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007a708 @ 0xa007a708, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes, as the decompiler wrote them.
 */
extern void hdmi_phy_write_bit();
extern void hdmi_phy_update_reg();

/*
 * For each of the three channels of a PHY (register pages 0x11xx, 0x15xx, 0x19xx): clear bit 7 of register 0x178
 * (the register that holds RCT and CFT) and set byte 3 of register 0x17C to 0x18.
 * port: PHY index. Called by hdmi_phy_reset_all_lane_regs and hdmi_rx21_reload_lane_regs.
 */
void hdmi_phy_reset_tmds_channel_regs(unsigned char port)
{
  hdmi_phy_write_bit(0, 7, port, 0x1178);
  hdmi_phy_write_bit(0, 7, port, 0x1578);
  hdmi_phy_write_bit(0, 7, port, 0x1978);
  hdmi_phy_update_reg(port, 0x117c, 0xffffff, 0x18000000);
  hdmi_phy_update_reg(port, 0x157c, 0xffffff, 0x18000000);
  hdmi_phy_update_reg(port, 0x197c, 0xffffff, 0x18000000);
}
