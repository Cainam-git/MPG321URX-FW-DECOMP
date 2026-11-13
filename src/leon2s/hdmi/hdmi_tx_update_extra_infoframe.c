/* hdmi_tx_update_extra_infoframe  (FUN_a00926e0)
 *
 * Replace the packet in the 0x160 InfoFrame slot of an HDMI TX port safely.
 *   port: HDMI TX port
 *   buf: packet
 * Name basis: descriptive - disable, write, enable; caller CONV2HDMITX_UpdatePacket
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00926e0 @ 0xa00926e0 (-mcpu=v8 -Os -g)
 * The last call passes four more values (unused_arg3..6) that the callee does not take; they must stay for the
 * exact build.
 */
extern void hdmi_tx_enable_extra_infoframe();
extern int hdmi_tx_write_extra_infoframe();

/* Replace the packet in the 0x160 slot of HDMI TX 'port': switch it off, write 'packet', switch it on. */
void hdmi_tx_update_extra_infoframe(unsigned char port,unsigned int packet,unsigned int unused_arg3,unsigned int unused_arg4,
                 unsigned int unused_arg5,unsigned int unused_arg6)

{
  hdmi_tx_enable_extra_infoframe(port,0);
  hdmi_tx_write_extra_infoframe(port,packet);
  hdmi_tx_enable_extra_infoframe(port,1,unused_arg3,unused_arg4,unused_arg5,unused_arg6);
  return;
}
