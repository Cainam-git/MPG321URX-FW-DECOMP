/* hdmi_rx21_set_audio_enable  (FUN_a00a1bb0)
 *
 * Enable or disable the audio output path of an HDMI 2.1 receiver.
 *   port: receiver
 *   enable: 1 = enable
 * Note: Enable sets bit 0x1C (+0x24) and bits 8..10 (+0x28) of register block 1 and clears bit 0x19 (+0x34);
 *   disable does the reverse.
 * Name basis: derived - bits 0x1C / 8 / 9 / 10 set and bit 0x19 cleared on enable, the reverse on disable;
 *   caller audio_set_source_enable
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1bb0, flags -mcpu=v8 -Os -g (section default). The base is 0xa807db00 (sethi 0xa807d800 | 0x300)
 * with the word at +4 re-read before every call; the two branches have their own `blocks` pointer.
 */
extern void reg_set_bit(unsigned int, int);
extern void reg_clear_bit(unsigned int, int);
extern unsigned char hdmi_rx21_reg_blocks[];

/*
 * Enable or disable the audio path of HDMI 2.1 receiver `port`. The bits are set or cleared in word arrays at
 * byte offsets of register block 1 (the word at +4 of the receiver's row of hdmi_rx21_reg_blocks):
 *   enable:  set bit 0x1C at +0x24, set bits 8, 9 and 10 at +0x28, clear bit 0x19 at +0x34;
 *   disable: clear bit 0x1C at +0x24, clear bits 8, 9 and 10 at +0x28, set bit 0x19 at +0x34.
 * Called by audio_set_source_enable.
 *   port    HDMI 2.1 receiver 0/1
 *   enable  non-zero = enable
 */
void hdmi_rx21_set_audio_enable(unsigned int port, unsigned char enable)
{
  if (enable != 0)
  {
    unsigned int *blocks = (unsigned int *)(hdmi_rx21_reg_blocks + ((port & 0xff) * 0x34));
    reg_set_bit(0x1c, blocks[1] + 0x24);
    reg_set_bit(8, blocks[1] + 0x28);
    reg_set_bit(9, blocks[1] + 0x28);
    reg_set_bit(10, blocks[1] + 0x28);
    reg_clear_bit(0x19, blocks[1] + 0x34);
  }
  else
  {
    unsigned int *blocks = (unsigned int *)(hdmi_rx21_reg_blocks + ((port & 0xff) * 0x34));
    reg_clear_bit(0x1c, blocks[1] + 0x24);
    reg_clear_bit(8, blocks[1] + 0x28);
    reg_clear_bit(9, blocks[1] + 0x28);
    reg_clear_bit(10, blocks[1] + 0x28);
    reg_set_bit(0x19, blocks[1] + 0x34);
  }
}
