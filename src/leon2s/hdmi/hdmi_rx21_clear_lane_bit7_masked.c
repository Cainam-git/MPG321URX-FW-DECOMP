/* hdmi_rx21_clear_lane_bit7_masked  (FUN_a0079a20)
 *
 * Clear bit 7 and set the control field of the lanes selected in the mask.
 *   port: PHY
 *   mask: lanes
 * Name basis: descriptive - per-lane register tables; pair of hdmi_rx21_set_lane_bit7_masked
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0079a20 @ 0xa0079a20, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: a 32-bit port parameter (an 8-bit one gives one shared 'and');
 * the two tests as separate ifs (a '&&' gives a branch-free addx form); the i < 4 test is redundant but
 * the firmware keeps it. The port is masked separately for each call (the parameter conversion and the
 * explicit '& 0xff' are different RTL, so they are not merged).
 */
extern unsigned short hdmi_rx21_lane_regs_0x17c[];
extern unsigned short hdmi_rx21_lane_eq_regs[];
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);

/* For each lane whose bit is set in the mask: clears bit 7 of the lane's register in the table
 * hdmi_rx21_lane_eq_regs and sets the top byte of its register in hdmi_rx21_lane_regs_0x17c to 0x38.
 *   port: PHY page
 *   mask: lanes, bit 0..3 */
void hdmi_rx21_clear_lane_bit7_masked(unsigned int port, unsigned char mask)
{
    unsigned short i;

    for (i = 0; i < 4; i++) {
        if ((mask >> i) & 1) {
            if (i < 4) {
                hdmi_phy_write_bit(0, 7, port, hdmi_rx21_lane_eq_regs[i]);
                hdmi_phy_update_reg(port & 0xff, hdmi_rx21_lane_regs_0x17c[i], 0xffffff, 0x38000000);
            }
        }
    }
}
