/* hdmi_rx21_clear_lane_bit7_all  (FUN_a0079aac)
 *
 * Clear bit 7 and set the control field on all four lanes.
 * Name basis: descriptive - hdmi_rx21_clear_lane_bit7_masked(port, 0xF)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0079aac @ 0xa0079aac, flags -mcpu=v8 -Os -g.
 * Source form: the callee is declared without a parameter list.
 */
extern int hdmi_rx21_clear_lane_bit7_masked();

/* Calls hdmi_rx21_clear_lane_bit7_masked for all four lanes (mask 0xf).
 *   port: PHY page */
void hdmi_rx21_clear_lane_bit7_all(unsigned char port)

{
  hdmi_rx21_clear_lane_bit7_masked(port,0xf);
  return;
}