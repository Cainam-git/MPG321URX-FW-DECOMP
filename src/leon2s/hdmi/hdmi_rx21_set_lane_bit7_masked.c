/* hdmi_rx21_set_lane_bit7_masked  (FUN_a007a648)
 *
 * Set bit 7 and the control fields of the lanes selected in the mask.
 *   port: PHY
 *   mask: lanes
 * Name basis: descriptive - per-lane register tables; pair of hdmi_rx21_clear_lane_bit7_masked
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007a648 @ 0xa007a648-0xa007a6f0, flags -mcpu=v8 -Os -g.
 * Source form: each call has its own 'if (i < 4)' guard (the firmware keeps one 'cmp 3; bgu' for all three;
 * the separate guards stop CSE from sharing one masked port between the calls). The firmware masks the port
 * separately for each call.
 */
extern unsigned short hdmi_rx21_lane_regs_0x17c[];
extern unsigned short hdmi_rx21_lane_eq_regs[];
extern unsigned short hdmi_rx21_lane_regs_0x050[];
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);

/*
 * For each lane whose bit is set in the mask, write three PHY registers of that lane:
 *   - register 0x17C: byte 3 = 0x38;
 *   - register 0x050: byte 0 = 0x16;
 *   - register 0x178 (the register that holds RCT and CFT): bit 7 set.
 * port: PHY index. mask: lanes, bit 0..3 = lane 0..3.
 * Called by hdmi_rx21_set_lane_bit7_all and hdmi_rx21_apply_lane_eq. Its pair is hdmi_rx21_clear_lane_bit7_masked.
 */
void hdmi_rx21_set_lane_bit7_masked(unsigned int port, unsigned char mask)
{
    unsigned short i;

    for (i = 0; i < 4; i++) {
        if ((mask >> i) & 1) {
            if (i < 4)
                hdmi_phy_update_reg(port & 0xff, hdmi_rx21_lane_regs_0x17c[i], 0xffffff, 0x38000000);
            if (i < 4)
                hdmi_phy_update_reg(port & 0xff, hdmi_rx21_lane_regs_0x050[i], 0xffffff00, 0x16);
            if (i < 4)
                hdmi_phy_write_bit(1, 7, port, hdmi_rx21_lane_eq_regs[i]);
        }
    }
}
