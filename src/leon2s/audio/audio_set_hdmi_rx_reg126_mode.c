/* audio_set_hdmi_rx_reg126_mode  (FUN_a0090e6c)
 *
 * Set the mode bits 0 and 2 of HDMI receiver audio register 0x126.
 *   port: HDMI 2.0 receiver, 2 = both
 *   mode: 0..2
 * Name basis: descriptive - audio_configure byte 1 bits 4..5: 0 -> (0,0), 2 -> (1,0), 1 -> (1,1)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090e6c @ 0xa0090e6c (-mcpu=v8 -Os -g).
 * Source form: one case per mode value with its two calls written out.
 */
extern void hdmi_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);

#define HDMI_AUDIO_OPTION_REG 0x126
#define HDMI_AUDIO_MODE_BIT0  0x1
#define HDMI_AUDIO_MODE_BIT2  0x4

/*
 * Set bits 0 and 2 of register 0x126 of an HDMI 2.0 receiver from a mode:
 *   mode 0: bit 0 = 0, bit 2 = 0
 *   mode 2: bit 0 = 1, bit 2 = 0
 *   mode 1: bit 0 = 1, bit 2 = 1
 * Any other mode changes nothing.
 *   port: receiver 0 or 1, or 2 for both
 *   mode: 0..2
 * Called by audio_configure.
 */
void audio_set_hdmi_rx_reg126_mode(unsigned char port, unsigned char mode)
{
    switch (mode) {
    case 0:
        hdmi_reg_update_bits(port, HDMI_AUDIO_OPTION_REG, HDMI_AUDIO_MODE_BIT0, 0);
        hdmi_reg_update_bits(port, HDMI_AUDIO_OPTION_REG, HDMI_AUDIO_MODE_BIT2, 0);
        break;
    case 2:
        hdmi_reg_update_bits(port, HDMI_AUDIO_OPTION_REG, HDMI_AUDIO_MODE_BIT0, 1);
        hdmi_reg_update_bits(port, HDMI_AUDIO_OPTION_REG, HDMI_AUDIO_MODE_BIT2, 0);
        break;
    case 1:
        hdmi_reg_update_bits(port, HDMI_AUDIO_OPTION_REG, HDMI_AUDIO_MODE_BIT0, 1);
        hdmi_reg_update_bits(port, HDMI_AUDIO_OPTION_REG, HDMI_AUDIO_MODE_BIT2, 1);
        break;
    }
}
