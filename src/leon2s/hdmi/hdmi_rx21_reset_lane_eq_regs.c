/* hdmi_rx21_reset_lane_eq_regs  (FUN_a0079e00)
 *
 * Write the default EQ register values of all four HDMI 2.1 lanes.
 *   port: PHY
 * Name basis: descriptive - twelve fixed writes per lane from the lane register tables; callers
 *   DRV_HDMI21_LMS_To_EQ, lane reset
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0079e00 @ 0xa0079e00-0xa0079f80, flags -mcpu=v8 -Os -g.
 * Source form: every write has its own 'i < 4' bound check (macro WR); GCC keeps the first test of each
 * iteration and removes the others, but the separate blocks keep the port conversion ('and %i0,0xff') at each
 * call. The tables are const (read-only data), so each entry is loaded once and reused after the calls.
 */
extern const unsigned short hdmi_rx21_lane_regs_0x328[4];
extern const unsigned short hdmi_rx21_lane_regs_0x308[4];
extern const unsigned short hdmi_rx21_lane_regs_0x330[4];
extern const unsigned short hdmi_rx21_lane_regs_0x310[4];
extern const unsigned short hdmi_rx21_lane_regs_0x334[4];
extern const unsigned short hdmi_rx21_lane_regs_0x314[4];
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);

/* Same bound check before every write, see the matching notes. */
#define WR(tab, mask, val) if (i < 4) hdmi_phy_update_reg(port, tab[i], mask, val)

/*
 * Put the lane registers of the four HDMI 2.1 lanes of a PHY to their default values.
 * For each lane, in this order (hdmi_phy_update_reg keeps the bits in the mask and ORs in the value):
 *   - registers 0x310 and 0x330: byte 3 = 0x88; registers 0x314 and 0x334: byte 0 = 0x88;
 *   - registers 0x308 and 0x328: byte 1 = 0, then byte 2 = 0xF0;
 *   - registers 0x310 and 0x330: byte 3 = 0x08; registers 0x314 and 0x334: byte 0 = 0x08.
 * The register number of each lane comes from a four-entry table per register.
 * port: PHY index. Called by DRV_HDMI21_LMS_To_EQ and hdmi_phy_reset_all_lane_regs.
 */
void hdmi_rx21_reset_lane_eq_regs(unsigned char port)
{
    unsigned short i;

    for (i = 0; i < 4; i++) {
        WR(hdmi_rx21_lane_regs_0x310, 0xffffff, 0x88000000);
        WR(hdmi_rx21_lane_regs_0x314, 0xffffff00, 0x88);
        WR(hdmi_rx21_lane_regs_0x330, 0xffffff, 0x88000000);
        WR(hdmi_rx21_lane_regs_0x334, 0xffffff00, 0x88);
        WR(hdmi_rx21_lane_regs_0x308, 0xffff00ff, 0);
        WR(hdmi_rx21_lane_regs_0x328, 0xffff00ff, 0);
        WR(hdmi_rx21_lane_regs_0x308, 0xff00ffff, 0xf00000);
        WR(hdmi_rx21_lane_regs_0x328, 0xff00ffff, 0xf00000);
        WR(hdmi_rx21_lane_regs_0x310, 0xffffff, 0x8000000);
        WR(hdmi_rx21_lane_regs_0x314, 0xffffff00, 8);
        WR(hdmi_rx21_lane_regs_0x330, 0xffffff, 0x8000000);
        WR(hdmi_rx21_lane_regs_0x334, 0xffffff00, 8);
    }
}
