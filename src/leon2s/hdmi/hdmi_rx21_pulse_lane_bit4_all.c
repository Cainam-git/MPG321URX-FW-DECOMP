/* hdmi_rx21_pulse_lane_bit4_all  (FUN_a007f9d0)
 *
 * Pulse bit 4 of PHY register 0x060 of all four lanes.
 * Name basis: descriptive - hdmi_rx21_pulse_lane_bit4_masked(port, 0xF)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007f9d0 @ 0xa007f9d0, flags -mcpu=v8 -Os -g.
 */
extern int hdmi_rx21_pulse_lane_bit4_masked();

#define ALL_LANES_MASK 0xf              /* lane bits 0..3 */

/* hdmi_rx21_pulse_lane_bit4_masked for all four lanes of a PHY (port = PHY index). */
void hdmi_rx21_pulse_lane_bit4_all(unsigned char port)
{
  hdmi_rx21_pulse_lane_bit4_masked(port, ALL_LANES_MASK);
}
