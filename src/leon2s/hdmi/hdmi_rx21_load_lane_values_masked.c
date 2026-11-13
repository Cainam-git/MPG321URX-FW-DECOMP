/* hdmi_rx21_load_lane_values_masked  (FUN_a00802cc)
 *
 * Write the lane start values and pulse the lane reset for the lanes in the mask.
 *   p1: PHY
 *   mask: lanes
 * Name basis: descriptive - per-lane register tables and hdmi_rx21_pulse_lane_bit4_masked; caller
 *   DRV_HDMI21_Set_PHY
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00802cc @ 0xa00802cc-0xa0080494, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - phy is an unsigned int parameter; the PHY test and the calls of one pass take its low byte in different
 *    spellings (phy & 0xff, (char)phy & 0xff, (unsigned short)phy & 0xff, (unsigned char)phy, (phy << 24) >> 24,
 *    phy - phy / 256 * 256): equal spellings are merged into one register by GCC, the firmware masks %i0 again
 *    for every use;
 *  - the mask test and the 'lane <= 3' test are two nested ifs without braces;
 *  - the lane count is read from the link training record as a byte array (hdmi_rx21_lts_records[record][0]).
 */
extern unsigned char hdmi_rx21_lts_records[][0xb0];         /* link training record of HDMI 2.1 receiver 0 / 1 */
/* Each table holds one register for each of the four lanes (the EQ register is 0x178). */
extern unsigned short hdmi_rx21_lane_regs_0x17c[4];
extern unsigned short hdmi_rx21_lane_eq_regs[4];
extern unsigned short hdmi_rx21_lane_regs_0x170[4];
extern void hdmi_phy_write_bit(int set, unsigned int bit, unsigned int port, unsigned short reg);
extern void hdmi_phy_update_reg(unsigned int port, unsigned short reg, unsigned int keep, unsigned int value);
extern void hdmi_rx21_pulse_lane_bit4_masked(unsigned char, unsigned char);

#define PHY_RX21_0      2           /* PHYs of HDMI 2.1 receivers 0 and 1 */
#define PHY_RX21_1      3
#define LTS_LANE_COUNT  0           /* byte of the link training record: lanes in use (0, 3 or 4) */

#define BIT_CLEAR       0           /* first argument of hdmi_phy_write_bit */
#define BIT_SET         1
#define REG_170_BIT_0   0           /* bits written in lane register 0x170 */
#define REG_170_BIT_16  0x10
#define REG_170_BIT_17  0x11
#define REG_17C_BIT_4   4           /* bit written in lane register 0x17C */

#define EQ_REG_KEEP     0xff0000f0  /* keep mask of the RCT / CFT write: RCT bits 0..3, CFT bits 8..23 */

/*
 * Write RCT / CFT values into the EQ registers of the lanes in a mask of an HDMI 2.1 receiver PHY.
 *
 *   phy   the PHY: PHY_RX21_0 or PHY_RX21_1 (any other value returns at once)
 *   mask  bit n set = lane n; 0 returns at once
 *   rct   RCT value per lane (4 bytes; bits 0..3 are written)
 *   cft   CFT value per lane (4 halfwords)
 *
 * Called by DRV_HDMI21_Set_PHY for every search row, right after hdmi_rx21_reload_lane_regs.
 *
 * Only lanes below the receiver's lane_count are handled. First pass, per lane: clear bit 16 of lane
 * register 0x170, set bit 4 of 0x17C, clear bit 0 and set bit 17 of 0x170, and write the lane's RCT and CFT.
 * Then bit 4 of lane register 0x060 is pulsed on the lanes of the mask (hdmi_rx21_pulse_lane_bit4_masked).
 * Second pass, per lane: set bit 0 of 0x170 and clear bit 4 of 0x17C again.
 */
void hdmi_rx21_load_lane_values_masked(unsigned int phy, unsigned char mask, unsigned char *rct, unsigned short *cft)
{
    unsigned char record;
    unsigned char lane;
    unsigned short reg_170;

    if ((phy & 0xff) == PHY_RX21_0)
        record = 0;
    else if ((phy & 0xff) == PHY_RX21_1)
        record = 1;
    else
        return;
    if (mask == 0)
        return;
    for (lane = 0; lane < hdmi_rx21_lts_records[record][LTS_LANE_COUNT]; lane++) {
        if ((mask >> lane) & 1)
        if (lane <= 3) {
            reg_170 = hdmi_rx21_lane_regs_0x170[lane];
            hdmi_phy_write_bit(BIT_CLEAR, REG_170_BIT_16, (char)phy & 0xff, reg_170);
            hdmi_phy_write_bit(BIT_SET, REG_17C_BIT_4, (unsigned short)phy & 0xff, hdmi_rx21_lane_regs_0x17c[lane]);
            hdmi_phy_write_bit(BIT_CLEAR, REG_170_BIT_0, (unsigned char)phy, reg_170);
            hdmi_phy_write_bit(BIT_SET, REG_170_BIT_17, (phy << 24) >> 24, reg_170);
            hdmi_phy_update_reg(phy - phy / 256 * 256, hdmi_rx21_lane_eq_regs[lane], EQ_REG_KEEP, (rct[lane] & 0xf) | (cft[lane] << 8));
        }
    }
    hdmi_rx21_pulse_lane_bit4_masked((char)phy & 0xff, mask);
    for (lane = 0; lane < hdmi_rx21_lts_records[record][LTS_LANE_COUNT]; lane++) {
        if ((mask >> lane) & 1)
        if (lane <= 3) {
            hdmi_phy_write_bit(BIT_SET, REG_170_BIT_0, (char)phy & 0xff, hdmi_rx21_lane_regs_0x170[lane]);
            hdmi_phy_write_bit(BIT_CLEAR, REG_17C_BIT_4, (unsigned short)phy & 0xff, hdmi_rx21_lane_regs_0x17c[lane]);
        }
    }
}
