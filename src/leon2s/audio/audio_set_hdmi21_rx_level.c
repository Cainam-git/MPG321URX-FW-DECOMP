/* audio_set_hdmi21_rx_level  (FUN_a008aadc)
 *
 * Write a 16-bit audio level to an HDMI 2.1 receiver.
 *   port: HDMI 2.1 port
 *   level: 16-bit level
 * Name basis: descriptive - forwards to the HDMI 2.1 record register write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008aadc @ 0xa008aadc (-mcpu=v8 -Os -g).
 * Source form: hdmi_rx21_write_audio_level is declared without a prototype.
 */
extern int hdmi_rx21_write_audio_level();

/*
 * Write a 16-bit audio level to an HDMI 2.1 receiver; the work is done by hdmi_rx21_write_audio_level.
 *   port:  receiver 0 or 1
 *   level: 16-bit level
 * Called by audio_set_input_levels.
 */
void audio_set_hdmi21_rx_level(unsigned char port, unsigned short level)

{
  hdmi_rx21_write_audio_level(port,level);
  return;
}
