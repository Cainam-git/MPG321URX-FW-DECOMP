/* hdmi_rx21_write_lane_setting  (FUN_a007aac4)
 *
 * Write a byte setting to one lane, or to all four lanes.
 *   port: PHY
 *   lane: lane, >3 = all
 *   value0: lane 0
 *   value1: lane 1
 *   value2: lane 2
 *   value3: lane 3
 * Name basis: descriptive - byte 1 of 0x2064/0x2464/0x2864/0x3064; callers DRV_HDMI21_IQ_Scan_byCED and the
 *   default reset
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007aac4 @ 0xa007aac4-0xa007ab94, flags -mcpu=v8 -Os -g.
 * Source form: the idx > 3 arm is written first.
 */
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern const unsigned short hdmi_rx21_lane_regs_0x064[];

/*
 * Write byte 1 of PHY register 0x064 of one lane, or of all four lanes.
 *   port: PHY index.
 *   lane: 0..3 = that lane, above 3 = all four lanes.
 *   value0..value3: the byte for lane 0..3. With a single lane only that lane's byte is used.
 * Called by hdmi_rx21_reset_lane_setting and DRV_HDMI21_IQ_Scan_byCED.
 */
void hdmi_rx21_write_lane_setting(unsigned char port, unsigned char lane, unsigned char value0, unsigned char value1, unsigned char value2,
                  unsigned char value3)
{
    unsigned char values[4];

    values[0] = value0;
    values[1] = value1;
    values[2] = value2;
    values[3] = value3;
    if (lane > 3) {
        hdmi_phy_update_reg(port, 0x2064, 0xffff00ff, value0 << 8);
        hdmi_phy_update_reg(port, 0x2464, 0xffff00ff, value1 << 8);
        hdmi_phy_update_reg(port, 0x2864, 0xffff00ff, value2 << 8);
        hdmi_phy_update_reg(port, 0x3064, 0xffff00ff, value3 << 8);
    } else {
        hdmi_phy_update_reg(port, hdmi_rx21_lane_regs_0x064[lane], 0xffff00ff, values[lane] << 8);
    }
}
