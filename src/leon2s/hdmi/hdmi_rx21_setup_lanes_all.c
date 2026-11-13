/* hdmi_rx21_setup_lanes_all  (FUN_a007a630)
 *
 * Write the per-lane set-up register tables for all four lanes.
 * Name basis: descriptive - hdmi_rx21_setup_lanes_masked(port, 0xF)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007a630 @ 0xa007a630, flags -mcpu=v8 -Os -g.
 */
extern int hdmi_rx21_setup_lanes_masked();

#define ALL_LANES_MASK 0xf              /* lane bits 0..3 */

/* Write the lane set-up registers of all four lanes of a PHY (port = PHY index). */
void hdmi_rx21_setup_lanes_all(unsigned char port)
{
  hdmi_rx21_setup_lanes_masked(port, ALL_LANES_MASK);
}
