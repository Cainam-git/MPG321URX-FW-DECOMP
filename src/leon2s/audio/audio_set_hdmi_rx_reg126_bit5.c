/* audio_set_hdmi_rx_reg126_bit5  (FUN_a0090e4c)
 *
 * Set or clear bit 5 of HDMI receiver audio register 0x126.
 *   port: HDMI 2.0 receiver, 2 = both
 *   on: 1 = set
 * Name basis: descriptive - audio_configure byte 1 bits 6..7, same option as the DP and HDMI 2.1 receivers get
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090e4c @ 0xa0090e4c (-mcpu=v8 -Os -g).
 * Source form: hdmi_reg_update_bits is declared without a prototype.
 */
extern int hdmi_reg_update_bits();

#define HDMI_AUDIO_OPTION_REG 0x126
#define HDMI_AUDIO_OPTION_BIT5 0x20

/*
 * Set (on = 1) or clear (any other value) bit 5 of register 0x126 of an HDMI 2.0 receiver.
 *   port: receiver 0 or 1, or 2 for both
 *   on:   1 = set
 * Called by audio_configure.
 */
void audio_set_hdmi_rx_reg126_bit5(unsigned char port, unsigned char on)

{
  hdmi_reg_update_bits(port,HDMI_AUDIO_OPTION_REG,HDMI_AUDIO_OPTION_BIT5,on);
  return;
}
