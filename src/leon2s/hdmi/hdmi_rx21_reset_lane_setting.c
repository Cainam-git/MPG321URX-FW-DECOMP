/* hdmi_rx21_reset_lane_setting  (FUN_a007ab94)
 *
 * Set the byte setting of all four lanes to its default 0x1F.
 * Name basis: descriptive - hdmi_rx21_write_lane_setting(port, all, 0x1F x4)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007ab94 @ 0xa007ab94, flags -mcpu=v8 -Os -g.
 */
extern int hdmi_rx21_write_lane_setting();

#define LANE_SETTING_DEFAULT 0x1f
#define ALL_LANES 0xff                  /* lane number above 3: all four lanes */

/* Write the value 0x1F to the byte setting (PHY register 0x064, byte 1) of all four lanes of a PHY. */
void hdmi_rx21_reset_lane_setting(unsigned char port)
{
  hdmi_rx21_write_lane_setting(port, ALL_LANES, LANE_SETTING_DEFAULT, LANE_SETTING_DEFAULT, LANE_SETTING_DEFAULT, LANE_SETTING_DEFAULT);
}
