/* hdmi_tx_update_audio_infoframe  (FUN_a0093138)
 *
 * Replace the audio InfoFrame of an HDMI TX port safely.
 *   port: HDMI TX port
 *   buf: packet
 * Name basis: derived - disable, write, enable; caller CONV2HDMITX_UpdatePacket
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0093138 @ 0xa0093138 (-mcpu=v8 -Os -g)
 * The last call passes four more values (unused_arg3..6) that the callee does not take; they must stay for the
 * exact build.
 */
extern void hdmi_tx_enable_audio_infoframe();
extern int hdmi_tx_write_audio_infoframe();

/* Replace the audio InfoFrame of HDMI TX 'port': switch it off, write 'packet', switch it on. */
void hdmi_tx_update_audio_infoframe(unsigned char port,unsigned int packet,unsigned int unused_arg3,unsigned int unused_arg4,
                 unsigned int unused_arg5,unsigned int unused_arg6)

{
  hdmi_tx_enable_audio_infoframe(port,0);
  hdmi_tx_write_audio_infoframe(port,packet);
  hdmi_tx_enable_audio_infoframe(port,1,unused_arg3,unused_arg4,unused_arg5,unused_arg6);
  return;
}
