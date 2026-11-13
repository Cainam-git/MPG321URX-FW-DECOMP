/* hdmi_tx_ddc_reset_step_third  (FUN_a00c7bc4)
 *
 * Write a derived value to a DDC control register.
 * Name basis: descriptive - read, mask, OR, write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c7bc4, flags -mcpu=v8 -Os -g.
 * Source form: the three operations (AND 0xFFFFFFF0, OR 0xA, AND 0xFA) are separate statements on an unsigned
 * char, which forces the firmware's exact sequence; the result is (v & 0xF0) | 0xA.
 */
extern int hdmi_tx_reg_read8();
extern int hdmi_tx_reg_write8();

#define HDMI_TX_BANK_CORE 0             /* bank 0 of an HDMI transmitter's registers */
#define DDC_CONTROL_REG 0xf3            /* control register of the DDC master */

/*
 * Third step of the DDC master reset: set the low four bits of DDC control register 0xF3 to 0xA and leave the
 * upper four bits as they are. Called by hdmi_tx_ddc_reset after the second step.
 *   port: HDMI TX port
 */
void hdmi_tx_ddc_reset_step_third(unsigned int port)

{
  unsigned int read_value;
  unsigned char new_value;
  
  port = port & 0xff;
  read_value = hdmi_tx_reg_read8(port,HDMI_TX_BANK_CORE,DDC_CONTROL_REG);
  new_value = read_value & 0xfffffff0;
  new_value = new_value | 0xa;
  new_value = new_value & 0xfa;
  hdmi_tx_reg_write8(port,HDMI_TX_BANK_CORE,DDC_CONTROL_REG,new_value);
  return;
}
