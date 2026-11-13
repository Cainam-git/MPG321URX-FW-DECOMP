/* hdmi_tx_ddc_reset_step_second  (FUN_a00c7b90)
 *
 * Set the low nibble of the DDC control register 0xF3 to 9.
 * Name basis: descriptive - read, merge, write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c7b90, flags -mcpu=v8 -Os -g.
 * Source form: the nibble is replaced in the unsigned char and then masked with 0xF9 as a second step;
 * ((v & 0xF0) | 9) & 0xF9 equals (v & 0xF0) | 9.
 */
extern int hdmi_tx_reg_read8();
extern int hdmi_tx_reg_write8();

#define HDMI_TX_BANK_CORE 0             /* bank 0 of an HDMI transmitter's registers */
#define DDC_CONTROL_REG 0xf3            /* control register of the DDC master */

/*
 * Second step of the DDC master reset: set the low four bits of DDC control register 0xF3 to 9 and leave the
 * upper four bits as they are. Called by hdmi_tx_ddc_reset after the first step.
 *   port: HDMI TX port
 */
void hdmi_tx_ddc_reset_step_second(unsigned int port)

{
  unsigned char value;
  
  port = port & 0xff;
  value = hdmi_tx_reg_read8(port,HDMI_TX_BANK_CORE,DDC_CONTROL_REG);
  value = (value & 0xfffffff0) | 9;
  hdmi_tx_reg_write8(port,HDMI_TX_BANK_CORE,DDC_CONTROL_REG,value & 0xf9);
  return;
}
