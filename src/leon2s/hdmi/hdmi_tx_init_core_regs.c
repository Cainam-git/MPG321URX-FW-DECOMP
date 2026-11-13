/* hdmi_tx_init_core_regs  (FUN_a00944e0)
 *
 * Load the fixed start values of the HDMI TX core registers.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - regs 0x86, 0x88, 0x56, 8, 0x12F, page 3 0xBE/0xBF, 0x49
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00944e0 @ 0xa00944e0 (-mcpu=v8 -Os -g)
 */
extern void hdmi_tx_reg_write8();
extern void hdmi_tx_reg_update_bits();

/*
 * Write fixed start values into HDMI TX 'port': bank 0 register 0x86 bit 7 set, 0x88 = 0xD6, 0x56 = 0x2E,
 * 8 = 0x30, 0x12F bit 7 set, 0x49 bit 5 set; bank 3 registers 0xBE and 0xBF = 0xFF.
 */
void hdmi_tx_init_core_regs(unsigned char port)

{
  
  hdmi_tx_reg_update_bits(port,0,0x86,0x80,1);
  hdmi_tx_reg_write8(port,0,0x88,0xd6);
  hdmi_tx_reg_write8(port,0,0x56,0x2e);
  hdmi_tx_reg_write8(port,0,8,0x30);
  hdmi_tx_reg_update_bits(port,0,0x12f,0x80,1);
  hdmi_tx_reg_write8(port,3,0xbe,0xff);
  hdmi_tx_reg_write8(port,3,0xbf,0xff);
  hdmi_tx_reg_update_bits(port,0,0x49,0x20,1);
  return;
}
