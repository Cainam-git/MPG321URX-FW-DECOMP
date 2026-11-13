/* hdmi_rx21_write_audio_level  (FUN_a00a1b80)
 *
 * Write the audio level of an HDMI 2.1 receiver to both channel fields.
 *   port: receiver
 *   level
 * Name basis: derived - (v << 16) | v into word 12 of the audio block; caller audio_set_hdmi21_rx_level
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1b80, flags -mcpu=v8 -Os -g (section default). Leaf. Block 12 is accessed as volatile (hardware
 * registers); the store stays out of the retl delay slot.
 */
extern unsigned char hdmi_rx21_reg_blocks[];

/*
 * Write `level` into both halves of word 12 of register block 12 of receiver `port`: (level << 16) | level.
 * Called by audio_set_hdmi21_rx_level.
 *   port   HDMI 2.1 receiver 0/1
 *   level  audio level
 */
void hdmi_rx21_write_audio_level(unsigned char port, unsigned short level)
{
    unsigned int *blocks = (unsigned int *)(hdmi_rx21_reg_blocks + port * 0x34);

    ((volatile unsigned int *)blocks[12])[12] = (level << 16) | level;
}
