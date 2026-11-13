/* hdmi_rx21_pick_eq_step  (FUN_a0079ac4)
 *
 * Choose an EQ step (8/4/2/0) from two lane status fields and the link mode.
 *   port: PHY
 *   idx: lane
 *   mode: link mode
 * Returns: step 0..8
 * Name basis: descriptive - bits 8..12 of two per-lane status registers; caller DRV_HDMI21_Set_PHY
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0079ac4 @ 0xa0079ac4, flags -mcpu=v8 -Os -g.
 * Source form: the mode 6 value is written `m >= 0x17 ? 4 : 8` (gives the subx/and/add sequence).
 */
extern unsigned int hdmi_phy_read_reg(unsigned int param_1, unsigned short param_2);
extern const unsigned short hdmi_rx21_lane_regs_0x33c[];
extern const unsigned short hdmi_rx21_lane_regs_0x31c[];

/* Reads two registers of lane idx (tables hdmi_rx21_lane_regs_0x31c and _0x33c) and keeps bits 8..12 of
 * each (both 0 when idx is above 3). Bit 4 of each value is flipped and m is the smaller of the two.
 * Result: for mode 6, 4 when m >= 0x17, otherwise 8; for mode 5, 2; for any other mode, 0.
 *   port: PHY page
 *   idx:  lane 0..3
 *   mode: link mode
 * Returns the step (0, 2, 4 or 8), masked with 0xe. Called by DRV_HDMI21_Set_PHY. */
unsigned char hdmi_rx21_pick_eq_step(unsigned char port, unsigned char idx, unsigned char mode)
{
    unsigned char a = 0;
    unsigned char b = 0;
    unsigned char m;
    unsigned char r = 0;

    if (idx <= 3) {
        a = (hdmi_phy_read_reg(port, hdmi_rx21_lane_regs_0x31c[idx]) & 0x1f00) >> 8;
        b = (hdmi_phy_read_reg(port, hdmi_rx21_lane_regs_0x33c[idx]) & 0x1f00) >> 8;
    }
    a ^= 0x10;
    b ^= 0x10;
    m = a > b ? b : a;
    if (mode == 6)
        r = m >= 0x17 ? 4 : 8;
    else if (mode == 5)
        r = 2;
    return r & 0xe;
}
