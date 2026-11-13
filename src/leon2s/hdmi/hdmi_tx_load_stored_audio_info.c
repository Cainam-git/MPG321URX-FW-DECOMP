/* hdmi_tx_load_stored_audio_info  (FUN_a0093164)
 *
 * Load the stored audio settings and audio InfoFrame into an HDMI TX port.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - 5 bytes 0xA8078600 to regs 0x11E..0x122, 9 bytes 0xA80785F0 to 0x180..0x188
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0093164 @ 0xa0093164-0xa00931fc (152 bytes), flags -mcpu=v8 -Os -g.
 * The raw parameter is passed to the unsigned char port parameter on every call.
 */
extern unsigned char hdmi_tx_stored_audio_infoframe[];
extern unsigned char hdmi_tx_stored_audio_settings[];
extern void hdmi_tx_reg_write8(unsigned char, unsigned int, unsigned short, unsigned char);

/*
 * Copy two stored byte tables into bank 0 of HDMI TX 'port': the 5 bytes of hdmi_tx_stored_audio_infoframe
 * to registers 0x11E..0x122 and the 9 bytes of hdmi_tx_stored_audio_settings to registers 0x180..0x188.
 */
void hdmi_tx_load_stored_audio_info(unsigned int port)
{
    unsigned char i;

    for (i = 0; i < 5; i++)
        hdmi_tx_reg_write8(port, 0, i + 0x11e, hdmi_tx_stored_audio_infoframe[i]);
    for (i = 0; i < 9; i++)
        hdmi_tx_reg_write8(port, 0, i + 0x180, hdmi_tx_stored_audio_settings[i]);
}
