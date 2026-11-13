/* hdmi_rx21_restart_lanes  (FUN_a007f9e8)
 *
 * Pulse the lane reset bits and the PHY control bit, then wait.
 * Name basis: descriptive - hdmi_rx21_pulse_lane_bit4_all, hdmi_rx21_pulse_ctrl_bit, delay; caller
 *   DRV_HDMI21_IQ_Scan_byCED
 *
 * Matching notes
 * --------------
 * leon2s FUN_a007f9e8 @ 0xa007f9e8, flags -mcpu=v8 -Os -g.
 * Source form: the five extra words are the decompiler's pass-through of the unused argument registers; the
 * last call is a tail call.
 */
extern int hdmi_rx21_pulse_ctrl_bit();
extern int hdmi_rx21_pulse_lane_bit4_all();
extern int timer_delay_long_units();

/*
 * Pulse bit 4 of lane register 0x060 on all lanes, pulse the control bit of the PHY (hdmi_rx21_pulse_ctrl_bit),
 * then wait one long delay unit. The extra parameters are only passed on to the wait routine.
 *   port: PHY index. Called by DRV_HDMI21_IQ_Scan_byCED.
 */
void hdmi_rx21_restart_lanes(unsigned char port, unsigned int unused_2, unsigned int unused_3, unsigned int unused_4,
                 unsigned int unused_5, unsigned int unused_6)

{
  hdmi_rx21_pulse_lane_bit4_all(port);
  hdmi_rx21_pulse_ctrl_bit(port);
  timer_delay_long_units(1, unused_2, unused_3, unused_4, unused_5, unused_6);
}
