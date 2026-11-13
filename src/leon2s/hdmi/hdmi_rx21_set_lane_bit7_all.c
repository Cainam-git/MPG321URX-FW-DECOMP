/* hdmi_rx21_set_lane_bit7_all  (FUN_a007a6f0)
 *
 * Set bit 7 and the control fields on all four lanes.
 * Name basis: descriptive - hdmi_rx21_set_lane_bit7_masked(port, 0xF)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007a6f0 @ 0xa007a6f0, flags -mcpu=v8 -Os -g.
 */
extern int hdmi_rx21_set_lane_bit7_masked();

#define ALL_LANES_MASK 0xf              /* lane bits 0..3 */

/* hdmi_rx21_set_lane_bit7_masked for all four lanes of a PHY (port = PHY index). */
void hdmi_rx21_set_lane_bit7_all(unsigned char port)
{
  hdmi_rx21_set_lane_bit7_masked(port, ALL_LANES_MASK);
}
