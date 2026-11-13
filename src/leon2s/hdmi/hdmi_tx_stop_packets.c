/* hdmi_tx_stop_packets  (FUN_a0094370)
 *
 * Stop all InfoFrame packets and the deep colour bit of an HDMI TX port.
 *   port: HDMI TX port 0/1
 * Name basis: derived - clears regs 0x13E/0x13F enables, 0x12F bit 6 and reg 8 bit 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094370 @ 0xa0094370 (-mcpu=v8 -Os -g)
 */
extern void hdmi_tx_reg_write8();
extern void hdmi_tx_reg_update_bits();

/*
 * Clear bit 6 of register 0x12F, write 0 to registers 0x13E and 0x13F, and clear bit 0 of register 8 (all in
 * bank 0) of HDMI TX 'port'.
 */
void hdmi_tx_stop_packets(unsigned char port)

{
  
  hdmi_tx_reg_update_bits(port,0,0x12f,0x40,0);
  hdmi_tx_reg_write8(port,0,0x13e,0);
  hdmi_tx_reg_write8(port,0,0x13f,0);
  hdmi_tx_reg_update_bits(port,0,8,1,0);
  return;
}
