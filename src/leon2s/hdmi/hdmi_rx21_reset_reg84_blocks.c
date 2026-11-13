/* hdmi_rx21_reset_reg84_blocks  (FUN_a009fe98)
 *
 * Set bits 0x71 of register 0x84 and pulse its reset bits 0xEA8A.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: descriptive - caller hdmi_rx21_modedet_check_pll (PLL check restart)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009fe98, flags -mcpu=v8 -Os -g (section default). The first read-modify-write recomputes the
 * record address twice, as the firmware does.
 */
extern unsigned char hdmi_rx21_reg_blocks;
extern int hdmi_rx21_pulse_reg84_bits();

/*
 * Set bits 0x71 in the word at byte offset 0x84 of register block 0 of receiver `port`, then pulse the bits
 * 0xEA8A of the same word with hdmi_rx21_pulse_reg84_bits. Called by hdmi_rx21_modedet_check_pll.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_reset_reg84_blocks(unsigned int port)
{
  *(unsigned int *)(*(int *)(&hdmi_rx21_reg_blocks + (port & 0xff) * 0x34) + 0x84) =
       *(unsigned int *)(*(int *)(&hdmi_rx21_reg_blocks + (port & 0xff) * 0x34) + 0x84) | 0x71;
  hdmi_rx21_pulse_reg84_bits(port & 0xff, 0xea8a);
}
