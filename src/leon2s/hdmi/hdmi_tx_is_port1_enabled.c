/* hdmi_tx_is_port1_enabled  (FUN_a0070414)
 *
 * Return bit 1 of the command flag byte: the enable of HDMI TX port 1.
 * Returns: 0 or 2
 * Name basis: derived - hdmi_tx_service_port and hdmi_tx_stop_unless_enabled shut HDMI TX port 1 down while it
 *   is 0; dp_tx_update_hpd_status reads that port's hot-plug bit only while it is 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0070414 @ 0xa0070414, flags -mcpu=v8 -Os -g.
 */

extern unsigned char input_command_flags;

/* Return bit 1 of the port action flag byte (the value 2, not 1): the enable of HDMI TX port 1 (read by dp_tx_update_hpd_status and hdmi_tx_service_port). */
unsigned char hdmi_tx_is_port1_enabled(void)
{
  return input_command_flags & 2;
}
