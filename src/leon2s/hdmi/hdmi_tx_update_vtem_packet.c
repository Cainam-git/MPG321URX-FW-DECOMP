/* hdmi_tx_update_vtem_packet  (FUN_a0093034)
 *
 * Replace the VTEM packet of an HDMI TX port safely.
 *   port: HDMI TX port
 *   p: packet
 * Name basis: derived - disable, write, enable; caller CONV2HDMITX_UpdatePacket for DP inputs
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0093034 @ 0xa0093034 (-mcpu=v8 -Os -g)
 * The last call passes four more values (unused_arg3..6) that the callee does not take; they must stay for the
 * exact build.
 */
extern void hdmi_tx_enable_vtem_packet();
extern int hdmi_tx_write_vtem_payload();

/* Replace the VTEM packet of HDMI TX 'port': switch it off, write 'packet', switch it on. */
void hdmi_tx_update_vtem_packet(unsigned int port,int packet,unsigned int unused_arg3,unsigned int unused_arg4,unsigned int unused_arg5,
                 unsigned int unused_arg6)

{
  port = port & 0xff;
  hdmi_tx_enable_vtem_packet(port,0);
  hdmi_tx_write_vtem_payload(port,packet);
  hdmi_tx_enable_vtem_packet(port,1,unused_arg3,unused_arg4,unused_arg5,unused_arg6);
  return;
}
