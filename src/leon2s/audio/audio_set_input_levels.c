/* audio_set_input_levels  (FUN_a008aaf8)
 *
 * Apply a 16-bit audio level to all HDMI and DP receivers.
 *   level: 16-bit level
 * Name basis: descriptive - mailbox command 0x94 sub 1; calls the HDMI, HDMI 2.1 and DP level writers for
 *   ports 0 and 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008aaf8 @ 0xa008aaf8-0xa008ab5c (100 bytes), flags -mcpu=v8 -Os -g.
 * The last call is a tail call.
 */
extern void audio_set_hdmi_rx_level(unsigned char, unsigned short);
extern void audio_set_hdmi21_rx_level(unsigned char, unsigned short);
extern void audio_set_dp_rx_level(unsigned char, unsigned short);
extern void audio_write_level_high_byte(unsigned char);

/*
 * Set the audio level of all receivers (mailbox command 0x94, sub 1; 0x8000 is the neutral level).
 *   level: 16-bit level
 *
 * The level goes to HDMI 2.0, HDMI 2.1 and DP receivers 0 and 1 in turn. The high byte of the level also goes
 * to audio_write_level_high_byte.
 */
void audio_set_input_levels(unsigned short level)
{
    audio_set_hdmi_rx_level(0, level);
    audio_set_hdmi_rx_level(1, level);
    audio_set_hdmi21_rx_level(0, level);
    audio_set_hdmi21_rx_level(1, level);
    audio_set_dp_rx_level(0, level);
    audio_set_dp_rx_level(1, level);
    audio_write_level_high_byte(level >> 8);
}
