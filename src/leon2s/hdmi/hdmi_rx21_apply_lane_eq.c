/* hdmi_rx21_apply_lane_eq  (FUN_a007a9c0)
 *
 * Write the chosen RCT/CFT values to the selected lanes and restart them.
 *   port: PHY
 *   mask: lanes
 *   rct: RCT values
 *   cft: CFT values
 * Name basis: derived - (rct & 0xF) | cft << 8 per lane, then the lane set-up and restart helpers; caller
 *   DRV_HDMI21_Set_PHY
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007a9c0 @ 0xa007a9c0-0xa007aac4, flags -mcpu=v8 -Os -g.
 * Source form: unsigned int parameter p; the two loop calls mask the port in different spellings (p & 0xff,
 *   (unsigned short)p & 0xff); equal spellings are merged into one register by GCC. The final calls use a
 *   block-local unsigned char copy q = p.
 */
extern unsigned char hdmi_rx21_lts_records[][0xb0];
extern unsigned short hdmi_rx21_lane_regs_0x170[4];
extern unsigned short hdmi_rx21_lane_eq_regs[4];
extern void hdmi_phy_write_bit(int mode, unsigned int bit, unsigned int reg, unsigned short val);
extern void hdmi_phy_update_reg(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4);
extern void hdmi_rx21_pulse_ctrl_bit(unsigned char);
extern void hdmi_rx21_reload_lane_regs(unsigned int, int);
extern void hdmi_rx21_setup_lanes_masked(unsigned char, unsigned char);
extern void hdmi_rx21_set_lane_bit7_masked(unsigned char, unsigned char);
extern void timer_delay_long_units(unsigned int);
extern void hdmi_rx21_clear_lane_bit7_masked(unsigned int port, unsigned char mask);

/*
 * Write the chosen RCT and CFT values to the selected lanes of a PHY and restart them.
 * For each lane in mask (and below the count in byte 0 of the PHY's 0xB0-byte link training record
 * hdmi_rx21_lts_records[port != 2]): bit 16 of lane register 0x170 is set, and the RCT/CFT register 0x178 gets
 * rct[lane] & 0xf in bits 0..3 and cft[lane] in bits 8..23.
 * Then: pulse the control bit (hdmi_rx21_pulse_ctrl_bit), reload the lane registers, run the lane set-up, set
 * bit 7 of the lanes (hdmi_rx21_set_lane_bit7_masked), wait one long delay unit and clear bit 7 again.
 *   port: PHY index.  mask: lanes, bit 0..3 = lane 0..3.
 *   rct: RCT value per lane (4 bytes).  cft: CFT value per lane (4 halfwords).
 * Called by DRV_HDMI21_Set_PHY.
 */
void hdmi_rx21_apply_lane_eq(unsigned int port, unsigned char mask, unsigned char *rct, unsigned short *cft)
{
    unsigned char record = (unsigned char)port != 2;
    unsigned char i;

    for (i = 0; i < hdmi_rx21_lts_records[record][0]; i++) {
        if ((mask >> i) & 1)
        if (i <= 3) {
            hdmi_phy_write_bit(1, 0x10, port & 0xff, hdmi_rx21_lane_regs_0x170[i]);
            hdmi_phy_update_reg((unsigned short)port & 0xff, hdmi_rx21_lane_eq_regs[i], 0xff0000f0, (rct[i] & 0xf) | (cft[i] << 8));
        }
    }
    {
        unsigned char phy = port;

        hdmi_rx21_pulse_ctrl_bit(phy);
        hdmi_rx21_reload_lane_regs(phy, mask & 0xf);
        hdmi_rx21_setup_lanes_masked(phy, mask & 0xf);
        hdmi_rx21_set_lane_bit7_masked(phy, mask & 0xf);
        timer_delay_long_units(1);
        hdmi_rx21_clear_lane_bit7_masked(phy, mask & 0xf);
    }
}
