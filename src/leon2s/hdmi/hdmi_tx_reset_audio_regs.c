/* hdmi_tx_reset_audio_regs  (FUN_a0091e70)
 *
 * Reset the audio input registers of an HDMI TX port.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - reg 0x11D bits cleared, reg 0x114 = 9
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091e70 @ 0xa0091e70 (-mcpu=v8 -Os -g)
 */
extern int hdmi_tx_reg_write8();
extern int hdmi_tx_reg_update_bits();

/*
 * For HDMI TX ports 0 and 1: clear bits 0 and 2 of register 0x11D (mask 5, mode 0) and write 9 to register
 * 0x114, both in bank 0. For any other value the port number is returned and nothing is written.
 */
int hdmi_tx_reset_audio_regs(unsigned int port)

{
  unsigned int unused_result;
  
  port = port & 0xff;
  if (port < 2) {
    hdmi_tx_reg_update_bits(port,0,0x11d,5,0);
    unused_result = 0;
    return hdmi_tx_reg_write8(port,0,0x114,9);
  }
  return (unsigned long long)port;
}
