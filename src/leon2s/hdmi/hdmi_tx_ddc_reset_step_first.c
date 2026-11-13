/* hdmi_tx_ddc_reset_step_first  (FUN_a00c7b60)
 *
 * Set the low four bits of the DDC control register 0xF3.
 * Name basis: descriptive - read, OR 0x0F, write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c7b60, flags -mcpu=v8 -Os -g.
 * Source form: the register value is an unsigned char, widened again for the OR.
 */
extern int hdmi_tx_reg_read8();
extern int hdmi_tx_reg_write8();

#define HDMI_TX_BANK_CORE 0             /* bank 0 of an HDMI transmitter's registers */
#define DDC_CONTROL_REG 0xf3            /* control register of the DDC master */

/*
 * First step of the DDC master reset: set the low four bits of DDC control register 0xF3 (value | 0x0F).
 * hdmi_tx_ddc_reset calls it first, then the second and third step.
 *   port: HDMI TX port
 */
void hdmi_tx_ddc_reset_step_first(unsigned int port)

{
  unsigned char value;
  
  port = port & 0xff;
  value = hdmi_tx_reg_read8(port,HDMI_TX_BANK_CORE,DDC_CONTROL_REG);
  hdmi_tx_reg_write8(port,HDMI_TX_BANK_CORE,DDC_CONTROL_REG,value & 0xff | 0xf);
  return;
}
