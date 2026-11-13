/* hdmi_tx_set_deep_color_bit  (FUN_a0091ef0)
 *
 * Set or clear the deep colour bit (reg 0x12F bit 6) of an HDMI TX port.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: derived - 1 for 10 and 12 bits, 0 for 8 bits in hdmi_tx_set_color_depth
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091ef0 @ 0xa0091ef0 (-mcpu=v8 -Os -g)
 */
extern int hdmi_tx_reg_update_bits();

/* Set (on = 1) or clear (on = 0) bit 6 of register 0x12F, bank 0, of HDMI TX 'port'. */
void hdmi_tx_set_deep_color_bit(unsigned char port, unsigned char on)

{
  hdmi_tx_reg_update_bits(port,0,0x12f,0x40,on);
  return;
}
