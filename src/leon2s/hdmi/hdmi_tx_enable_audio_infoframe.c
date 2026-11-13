/* hdmi_tx_enable_audio_infoframe  (FUN_a0093060)
 *
 * Switch sending of the audio InfoFrame of an HDMI TX port.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: derived - reg 0x13E bits 4..5 guard the 0x180 slot that gets header 0x84 1 0x0A
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0093060 @ 0xa0093060 (-mcpu=v8 -Os -g)
 */
extern int hdmi_tx_reg_update_bits();

#define PACKET_ENABLE_REG 0x13e         /* packet enable bits, bank 0 */
#define AUDIO_INFOFRAME_ENABLE_MASK 0x30 /* bits 5..4: the packet in the 0x180 slot */

/* Set (on = 1) or clear (on = 0) bits 5..4 of register 0x13E of HDMI TX 'port'. */
void hdmi_tx_enable_audio_infoframe(unsigned char port, unsigned char on)

{
  hdmi_tx_reg_update_bits(port,0,PACKET_ENABLE_REG,AUDIO_INFOFRAME_ENABLE_MASK,on);
  return;
}
