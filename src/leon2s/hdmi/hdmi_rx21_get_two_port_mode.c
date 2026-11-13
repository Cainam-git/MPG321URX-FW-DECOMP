/* hdmi_rx21_get_two_port_mode  (FUN_a00a29d8)
 *
 * Return the two-port mode byte of an HDMI 2.1 receiver (0 or 1).
 *   receiver
 * Returns: 0 or 1; also used as a left shift of the horizontal timing values
 * Name basis: proven - returns the byte FRL_PLL sets and prints as '2PortMode=%d';
 *   hdmi_rx21_detect_timing_change shifts the horizontal total and active width left by it; caller
 *   dp_tx_set_lane_routing compares it with 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a29d8 @ 0xa00a29d8, flags -mcpu=v8 -Os -g.
 */
extern unsigned char hdmi_rx21_two_port_mode_flags[];

/* Byte entry of the receiver (0 or 1) in hdmi_rx21_two_port_mode_flags. hdmi_rx21_detect_timing_change shifts the receiver's horizontal
   total and active width left by this value; dp_tx_set_lane_routing tests it for 1. */
unsigned char hdmi_rx21_get_two_port_mode(unsigned int receiver)
{
    return hdmi_rx21_two_port_mode_flags[receiver & 0xff];
}
