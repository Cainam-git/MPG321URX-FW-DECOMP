/* audio_set_hdmi_rx_level  (FUN_a008aab0)
 *
 * Write a 16-bit audio level to an HDMI 2.0 receiver.
 *   port: HDMI 2.0 port
 *   level: 16-bit level
 * Name basis: descriptive - receiver registers 0x2A0 and 0x2A2
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008aab0 @ 0xa008aab0 (-mcpu=v8 -Os -g).
 * Source form: hdmi_reg_write16 is declared without a prototype; the port is masked with 0xff at each call.
 */
extern int hdmi_reg_write16();

#define HDMI_AUDIO_LEVEL_REG_A 0x2a0    /* the level is written to both of these registers */
#define HDMI_AUDIO_LEVEL_REG_B 0x2a2

/*
 * Write a 16-bit audio level to an HDMI 2.0 receiver, into two of its registers.
 *   port:  receiver 0 or 1 (hdmi_reg_write16 also takes 2 for both)
 *   level: 16-bit level
 * Called by audio_set_input_levels.
 */
void audio_set_hdmi_rx_level(unsigned int port, unsigned short level)

{
  hdmi_reg_write16(port & 0xff,HDMI_AUDIO_LEVEL_REG_A,level & 0xffff);
  hdmi_reg_write16(port & 0xff,HDMI_AUDIO_LEVEL_REG_B,level & 0xffff);
  return;
}
