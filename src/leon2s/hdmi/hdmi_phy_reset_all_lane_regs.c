/* hdmi_phy_reset_all_lane_regs  (FUN_a007ac7c)
 *
 * Reset the TMDS channel, HDMI 2.1 lane and lane EQ registers of a port.
 * Name basis: descriptive - hdmi_phy_reset_tmds_channel_regs, hdmi_rx21_reset_lane_ctrl_regs,
 *   hdmi_rx21_reset_lane_eq_regs
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007ac7c @ 0xa007ac7c-0xa007aca0, flags -mcpu=v8 -Os -g.
 * The port byte is masked once at entry ('and %i0,0xff,%i0') and passed unchanged to all three routines.
 * All three callees take an unsigned char port, as in their own definitions. The last call is a tail call.
 */
extern void hdmi_phy_reset_tmds_channel_regs(unsigned char);
extern void hdmi_rx21_reset_lane_ctrl_regs(unsigned char);
extern void hdmi_rx21_reset_lane_eq_regs(unsigned char);

/*
 * Reset the channel registers, the lane registers and the lane EQ registers of a PHY, in that order.
 * port: PHY index. Called by DRV_HDMI21_Set_PHY.
 */
void hdmi_phy_reset_all_lane_regs(unsigned char port)
{
    hdmi_phy_reset_tmds_channel_regs(port);
    hdmi_rx21_reset_lane_ctrl_regs(port);
    hdmi_rx21_reset_lane_eq_regs(port);
}
