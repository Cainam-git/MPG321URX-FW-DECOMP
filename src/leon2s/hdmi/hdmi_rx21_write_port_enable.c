/* hdmi_rx21_write_port_enable  (FUN_a00a2c94)
 *
 * Set or clear the port enable bit of an HDMI 2.1 receiver.
 *   receiver
 *   enable: 1 = enable
 * Returns: 0
 * Name basis: derived - bit 0 of control register 8; caller DRV_HDMI_IF_Enable_RxPort
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2c94 @ 0xa00a2c94, flags -mcpu=v8 -Os -g.
 * Source form: the row array is the byte symbol hdmi_rx21_reg_blocks indexed by hand; the return value is the unused
 * high part of the 64-bit expression (enable << 32), which gives the firmware's return of 0.
 */
extern unsigned char hdmi_rx21_reg_blocks;     /* rows of 0x34 bytes, word 0 = block 0 of the receiver */
extern int reg_set_bit();
extern int reg_clear_bit();

/* Set (enable = 1) or clear (enable = 0) bit 0 of the word at offset 8 of register block 0 of the HDMI 2.1
   receiver (0 or 1); any other value changes nothing. Called by DRV_HDMI_IF_Enable_RxPort. Returns 0. */
unsigned int hdmi_rx21_write_port_enable(unsigned int receiver, unsigned char enable)
{
  if (enable == 1) {
    reg_set_bit(0, *(int *)(&hdmi_rx21_reg_blocks + (receiver & 0xff) * 0x34) + 8);
  }
  else if (enable == 0) {
    reg_clear_bit(0, *(int *)(&hdmi_rx21_reg_blocks + (receiver & 0xff) * 0x34) + 8);
  }
  return (unsigned long long)enable << 0x20;
}
