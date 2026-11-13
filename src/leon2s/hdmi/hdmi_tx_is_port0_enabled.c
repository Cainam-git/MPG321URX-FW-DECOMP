/* hdmi_tx_is_port0_enabled  (FUN_a0070404)
 *
 * Return bit 0 of the command flag byte: the enable of HDMI TX port 0.
 * Returns: 0 or 1
 * Name basis: derived - hdmi_tx_service_port and hdmi_tx_stop_unless_enabled shut HDMI TX port 0 down while it
 *   is 0; dp_tx_update_hpd_status reads that port's hot-plug bit only while it is 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0070404 @ 0xa0070404, flags -mcpu=v8 -Os -g.
 */

extern unsigned char input_command_flags;

/* Return bit 0 of the port action flag byte: the enable of HDMI TX port 0 (read by dp_tx_update_hpd_status and hdmi_tx_service_port). */
unsigned char hdmi_tx_is_port0_enabled(void)
{
  return input_command_flags & 1;
}
