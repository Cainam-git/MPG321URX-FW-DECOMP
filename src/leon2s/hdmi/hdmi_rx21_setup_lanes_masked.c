/* hdmi_rx21_setup_lanes_masked  (FUN_a007a0a0)
 *
 * Write the per-lane set-up register tables for the lanes in the mask.
 *   port: PHY
 *   mask: lanes
 * Name basis: descriptive - per lane four table writes, fourteen table byte writes, four more table byte
 *   writes and two bit writes at the lane page, plus bit 18 of lane 0 register 0x034
 *
 * Matching notes
 * --------------
 * FUN_a007a0a0 (leon2s 0xa007a0a0-0xa007a630, 1424 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - every table write has its own 'lane < 4' bound check (macro WRITE_LANE_BYTE, as in hdmi_rx21_reset_lane_eq_regs and
 *    hdmi_rx21_reload_lane_regs), also where the index cannot be 4 or more;
 *  - the lane list, its count and the loop counters are unsigned short;
 *  - each lane arm of the last loop writes its two hdmi_phy_write_bit calls with the register address as one
 *    constant (PHY_LANEn + LANE_REG_310 / _330), as DRV_HDMI21_PHY_INV_PICDR_Reset writes its per-lane
 *    registers.
 */
extern void hdmi_phy_write_bit(int set, unsigned int bit, unsigned char port, unsigned short reg);
extern void hdmi_phy_update_reg(unsigned int port, unsigned short reg, unsigned int keep, unsigned int value);
/* Each table holds one register for each of the four lanes: PHY_LANEn + the register in its name. */
extern const unsigned short hdmi_rx21_lane_regs_0x328[4];
extern const unsigned short hdmi_rx21_lane_regs_0x308[4];
extern const unsigned short hdmi_rx21_lane_regs_0x330[4];
extern const unsigned short hdmi_rx21_lane_regs_0x310[4];
extern const unsigned short hdmi_rx21_lane_regs_0x334[4];
extern const unsigned short hdmi_rx21_lane_regs_0x314[4];
extern const unsigned short hdmi_rx21_lane_regs_0x034[4];
extern const unsigned short hdmi_rx21_lane_regs_0x014[4];

#define BIT_CLEAR    0              /* first argument of hdmi_phy_write_bit */
#define BIT_SET      1

/* Register pages of the four lanes of an HDMI 2.1 receiver PHY. */
#define PHY_LANE0    0x2000
#define PHY_LANE1    0x2400
#define PHY_LANE2    0x2800
#define PHY_LANE3    0x3000
#define LANE_REG_034 0x034
#define LANE_REG_310 0x310
#define LANE_REG_330 0x330

#define LANE_BIT_18  0x12           /* bit written in lane registers 0x014 and 0x034 */
#define LANE_BIT_12  0xc            /* bit written in lane registers 0x310 and 0x330 */

/* Keep masks of hdmi_phy_update_reg: the byte named is replaced by the value, the rest is kept. */
#define SET_BYTE0    0xffffff00
#define SET_BYTE1    0xffff00ff
#define SET_BYTE2    0xff00ffff
#define SET_BYTE3    0xffffff

#define ALL_LANES_MASK 0xf

#define WRITE_LANE_BYTE(tab, keep, value) if (lane[j] < 4) hdmi_phy_update_reg(port, tab[lane[j]], keep, value)

/*
 * Write the fixed set-up values into the lane registers of an HDMI 2.1 receiver PHY, for the lanes in a mask.
 *
 *   port  the PHY (2 or 3)
 *   mask  bit n set = lane n (bits 0..3; the callers pass 0..ALL_LANES_MASK)
 *
 * Called by hdmi_rx21_setup_lanes_all (all four lanes) and by hdmi_rx21_apply_lane_eq (the lanes whose RCT /
 * CFT it has just written).
 *
 * Steps, each applied to the lanes in the mask, in lane order:
 *  1. Set bit 18 of lane 0's register 0x034 (whatever the mask), then per lane set bit 18 of registers 0x014
 *     and 0x034 and write 0xC8 into byte 1 of registers 0x314 and 0x334.
 *  2. Per lane: byte 3 of 0x310 / 0x330 = 0x88, byte 0 of 0x314 / 0x334 = 0x88, bytes 0..2 of 0x308 and 0x328
 *     = 3, 0, 0, byte 3 of 0x308 = 0xB8 and of 0x328 = 0xF8, byte 1 of 0x314 / 0x334 = 0x88.
 *  3. Per lane: byte 3 of 0x310 / 0x330 = 0x08, byte 0 of 0x314 / 0x334 = 0x08, then set bit 12 of 0x310 and
 *     clear bit 12 of 0x330.
 * The registers at 0x308..0x334 are the ones hdmi_rx21_reload_lane_regs also writes; it writes the same 0x88
 * and 0x08 values there, and clears bytes 1..2 of 0x308 / 0x328.
 */
void hdmi_rx21_setup_lanes_masked(unsigned char port, int mask)
{
    unsigned short lane[4] = {0, 0, 0, 0};     /* the lanes of the mask, in order */
    unsigned short lane_count, i, j;

    hdmi_phy_write_bit(BIT_SET, LANE_BIT_18, port, PHY_LANE0 + LANE_REG_034);
    lane_count = 0;
    for (i = 0; i < 4; i++) {
        if (((mask & 0xff) >> i) & 1) {
            lane[lane_count++] = i;
            if (i < 4)
                hdmi_phy_write_bit(BIT_SET, LANE_BIT_18, port, hdmi_rx21_lane_regs_0x014[i]);
            if (i < 4)
                hdmi_phy_write_bit(BIT_SET, LANE_BIT_18, port, hdmi_rx21_lane_regs_0x034[i]);
            if (i < 4)
                hdmi_phy_update_reg(port, hdmi_rx21_lane_regs_0x314[i], SET_BYTE1, 0xc800);
            if (i < 4)
                hdmi_phy_update_reg(port, hdmi_rx21_lane_regs_0x334[i], SET_BYTE1, 0xc800);
        }
    }
    for (j = 0; j < lane_count; j++) {
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x310, SET_BYTE3, 0x88000000);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x314, SET_BYTE0, 0x88);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x330, SET_BYTE3, 0x88000000);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x334, SET_BYTE0, 0x88);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x308, SET_BYTE0, 3);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x328, SET_BYTE0, 3);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x308, SET_BYTE1, 0);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x328, SET_BYTE1, 0);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x308, SET_BYTE2, 0);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x328, SET_BYTE2, 0);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x308, SET_BYTE3, 0xb8000000);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x328, SET_BYTE3, 0xf8000000);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x314, SET_BYTE1, 0x8800);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x334, SET_BYTE1, 0x8800);
    }
    for (j = 0; j < lane_count; j++) {
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x310, SET_BYTE3, 0x8000000);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x314, SET_BYTE0, 8);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x330, SET_BYTE3, 0x8000000);
        WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x334, SET_BYTE0, 8);
        if (lane[j] == 0) {
            hdmi_phy_write_bit(BIT_SET, LANE_BIT_12, port, PHY_LANE0 + LANE_REG_310);
            hdmi_phy_write_bit(BIT_CLEAR, LANE_BIT_12, port, PHY_LANE0 + LANE_REG_330);
        } else if (lane[j] == 1) {
            hdmi_phy_write_bit(BIT_SET, LANE_BIT_12, port, PHY_LANE1 + LANE_REG_310);
            hdmi_phy_write_bit(BIT_CLEAR, LANE_BIT_12, port, PHY_LANE1 + LANE_REG_330);
        } else if (lane[j] == 2) {
            hdmi_phy_write_bit(BIT_SET, LANE_BIT_12, port, PHY_LANE2 + LANE_REG_310);
            hdmi_phy_write_bit(BIT_CLEAR, LANE_BIT_12, port, PHY_LANE2 + LANE_REG_330);
        } else {
            hdmi_phy_write_bit(BIT_SET, LANE_BIT_12, port, PHY_LANE3 + LANE_REG_310);
            hdmi_phy_write_bit(BIT_CLEAR, LANE_BIT_12, port, PHY_LANE3 + LANE_REG_330);
        }
    }
}
