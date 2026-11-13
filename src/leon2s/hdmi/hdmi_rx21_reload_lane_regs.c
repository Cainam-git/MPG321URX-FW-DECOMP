/* hdmi_rx21_reload_lane_regs  (FUN_a007a79c)
 *
 * Reset the TMDS channel registers of a PHY and write fixed values to the lane registers in the mask.
 *   phy: PHY (2 or 3)
 *   mask: bit n set = lane n
 * Note: Writes no RCT / CFT values: it clears bit 7 of each lane's EQ register (0x178) and writes fixed bytes
 *   to 0x17C and 0x308..0x334.
 * Name basis: descriptive - hdmi_phy_reset_tmds_channel_regs, then per-lane writes of constants through the
 *   lane register tables; callers DRV_HDMI21_Set_PHY and hdmi_rx21_apply_lane_eq
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007a79c @ 0xa007a79c, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - every table write has its own 'lane < 4' bound check (macro WRITE_LANE_BYTE, as in
 *    hdmi_rx21_reset_lane_eq_regs and hdmi_rx21_setup_lanes_masked), and so has the hdmi_phy_write_bit call
 *    of the second loop;
 *  - the counter of the first loop is set before the hdmi_phy_reset_tmds_channel_regs call (0xa007a7a4), and
 *    that loop is a while loop.
 */

extern void hdmi_phy_reset_tmds_channel_regs(unsigned char port);
extern void hdmi_phy_write_bit(unsigned int set, unsigned int bit, unsigned int port, unsigned short reg);
extern void hdmi_phy_update_reg(unsigned int port, unsigned short reg, unsigned int keep, unsigned int value);
/* Each table holds one register for each of the four lanes (lane register pages 0x2000, 0x2400, 0x2800,
   0x3000 + the register in its name; the EQ register is 0x178). */
extern unsigned short hdmi_rx21_lane_regs_0x17c[4];
extern unsigned short hdmi_rx21_lane_eq_regs[4];
extern const unsigned short hdmi_rx21_lane_regs_0x328[4];
extern const unsigned short hdmi_rx21_lane_regs_0x308[4];
extern const unsigned short hdmi_rx21_lane_regs_0x330[4];
extern const unsigned short hdmi_rx21_lane_regs_0x310[4];
extern const unsigned short hdmi_rx21_lane_regs_0x334[4];
extern const unsigned short hdmi_rx21_lane_regs_0x314[4];

#define BIT_CLEAR    0              /* first argument of hdmi_phy_write_bit */
#define EQ_REG_BIT_7 7              /* bit cleared in the lane EQ register (RCT bits 0..3, CFT bits 8..23) */

/* Keep masks of hdmi_phy_update_reg: the byte named is replaced by the value, the rest is kept. */
#define SET_BYTE0    0xffffff00
#define SET_BYTE1    0xffff00ff
#define SET_BYTE2    0xff00ffff
#define SET_BYTE3    0xffffff

#define WRITE_LANE_BYTE(tab, keep, value) if (lane < 4) hdmi_phy_update_reg(port, tab[lane], keep, value)

/*
 * Reset the TMDS channel registers of an HDMI 2.1 receiver PHY and rewrite fixed values into lane registers.
 *
 *   phy   the PHY (2 or 3; only the low byte is used)
 *   mask  bit n set = lane n (bits 0..3)
 *
 * Called by DRV_HDMI21_Set_PHY for all four lanes before each search row, and by hdmi_rx21_apply_lane_eq for
 * the lanes it has just given new RCT / CFT values, right before hdmi_rx21_setup_lanes_masked.
 *
 * First the three TMDS channels are reset (hdmi_phy_reset_tmds_channel_regs) and every lane, in the mask or
 * not, gets bit 7 of its EQ register cleared and byte 3 of register 0x17C = 0x18. Then each lane in the
 * mask gets these two writes again, followed by: byte 3 of 0x310 / 0x330 and byte 0 of 0x314 / 0x334 = 0x88,
 * bytes 1 and 2 of 0x308 / 0x328 = 0, and finally byte 3 of 0x310 / 0x330 and byte 0 of 0x314 / 0x334 = 0x08.
 */
void hdmi_rx21_reload_lane_regs(unsigned int phy, int mask)
{
  unsigned char port = phy;
  int lane;

  lane = 0;
  hdmi_phy_reset_tmds_channel_regs(port);
  while (lane < 4) {
    hdmi_phy_write_bit(BIT_CLEAR, EQ_REG_BIT_7, port, hdmi_rx21_lane_eq_regs[lane]);
    WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x17c, SET_BYTE3, 0x18000000);
    lane++;
  }
  for (lane = 0; lane < 4; lane++) {
    if (((mask & 0xff) >> lane) & 1) {
      if (lane < 4)
        hdmi_phy_write_bit(BIT_CLEAR, EQ_REG_BIT_7, port, hdmi_rx21_lane_eq_regs[lane]);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x17c, SET_BYTE3, 0x18000000);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x310, SET_BYTE3, 0x88000000);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x314, SET_BYTE0, 0x88);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x330, SET_BYTE3, 0x88000000);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x334, SET_BYTE0, 0x88);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x308, SET_BYTE1, 0);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x328, SET_BYTE1, 0);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x308, SET_BYTE2, 0);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x328, SET_BYTE2, 0);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x310, SET_BYTE3, 0x8000000);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x314, SET_BYTE0, 8);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x330, SET_BYTE3, 0x8000000);
      WRITE_LANE_BYTE(hdmi_rx21_lane_regs_0x334, SET_BYTE0, 8);
    }
  }
}
