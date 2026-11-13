/* hdmi_rx21_pulse_reg84_bits  (FUN_a009fe2c)
 *
 * Set and then clear the given bits of control register 0x84 of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 *   mask: bit mask
 * Name basis: descriptive - only caller hdmi_rx21_reset_reg84_blocks
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009fe2c, flags -mcpu=v8 -Os -g (section default). The register is read and written twice (set,
 * then clear), both as volatile accesses.
 */
extern unsigned char hdmi_rx21_reg_blocks;

/*
 * Set the bits of `mask` in the word at byte offset 0x84 of register block 0 of receiver `port`, then clear them
 * again. The only caller is hdmi_rx21_reset_reg84_blocks.
 *   port  HDMI 2.1 receiver 0/1
 *   mask  bits to pulse
 */
void hdmi_rx21_pulse_reg84_bits(unsigned int port, unsigned int mask)
{
  int block0;

  block0 = *(volatile int *)(&hdmi_rx21_reg_blocks + (port & 0xff) * 0x34);
  *(volatile unsigned int *)(block0 + 0x84) = *(volatile unsigned int *)(block0 + 0x84) | mask;
  *(volatile unsigned int *)(block0 + 0x84) = *(volatile unsigned int *)(block0 + 0x84) & ~mask;
}
