/* hdmi_set_reg2fd_bit3  (FUN_a0091520)
 *
 * Set bit 3 of HDMI receiver register 0x2FD.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - cleared again by hdmi_clear_scdc_config
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091520 @ 0xa0091520 (-mcpu=v8 -Os -g)
 */
extern int hdmi_reg_update_bits();

/* Set bit 3 of receiver register 0x2FD of HDMI receiver 'port' (mask 8, mode 1: set). */
void hdmi_set_reg2fd_bit3(unsigned char port)
{
  hdmi_reg_update_bits(port,0x2fd,8,1);
  return;
}
