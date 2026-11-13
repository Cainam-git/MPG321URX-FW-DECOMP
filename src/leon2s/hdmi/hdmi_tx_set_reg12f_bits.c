/* hdmi_tx_set_reg12f_bits  (FUN_a009434c)
 *
 * Set or clear bits 0 and 7 of HDMI TX register 0x12F.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: descriptive - caller the TX set-up steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009434c @ 0xa009434c (-mcpu=v8 -Os -g)
 */
extern int hdmi_tx_reg_update_bits();

/* Set (on = 1) or clear (on = 0) bits 7 and 0 of register 0x12F, bank 0, of HDMI TX 'port'. */
void hdmi_tx_set_reg12f_bits(unsigned char port, unsigned char on)

{
  hdmi_tx_reg_update_bits(port,0,0x12f,0x81,on);
  return;
}
