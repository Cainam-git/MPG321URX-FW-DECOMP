/* hdmi_tx_update_avi_payload  (FUN_a00925b8)
 *
 * Replace the AVI InfoFrame payload of an HDMI TX port safely.
 *   port: HDMI TX port
 *   packet
 * Name basis: derived - disable, write, enable; caller CONV2HDMITX_UpdateInterface
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00925b8 @ 0xa00925b8 (-mcpu=v8 -Os -g)
 */
extern void hdmi_tx_enable_avi_packet(unsigned char port, unsigned char on);
extern int hdmi_tx_write_avi_payload();

/* Replace the AVI InfoFrame of HDMI TX 'port': switch it off, write 'packet' (see hdmi_tx_write_avi_payload), switch it on. */
void hdmi_tx_update_avi_payload(unsigned char port, unsigned int packet)

{
  hdmi_tx_enable_avi_packet(port,0);
  hdmi_tx_write_avi_payload(port,packet);
  hdmi_tx_enable_avi_packet(port,1);
  return;
}
