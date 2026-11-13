/* hdmi_tx_scdc_write  (FUN_a0091cf4)
 *
 * Write one SCDC register of the display connected to an HDMI TX port.
 *   port: HDMI TX port
 *   scdc_offset: SCDC register
 *   value: byte
 * Name basis: proven - DDC write to I2C address 0xA8 (SCDC) through the TX DDC master; callers the FRL
 *   training steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091cf4 @ 0xa0091cf4 (-mcpu=v8 -Os -g)
 * The saved bit goes through a char local masked with 1 again before the last call (keeps the 'and 1' of the
 * firmware).
 */
extern int hdmi_tx_reg_read8();
extern int hdmi_tx_ddc_reset();
extern unsigned char hdmi_tx_ddc_write();
extern void hdcp_tx_hdmi_set_reg27_bit0();

#define SCDC_I2C_ADDRESS 0xa8           /* I2C address of the sink's SCDC registers */

/*
 * Write the SCDC register 'scdc_offset' of the sink on HDMI TX 'port' with 'value'.
 *
 * Does nothing when hdmi_tx_ddc_reset reports a non-zero result. Otherwise it clears bit 0 of TX register 0x27
 * for the duration of the write (hdcp_tx_hdmi_set_reg27_bit0) and then restores the value it had.
 */
void hdmi_tx_scdc_write(unsigned char port, char scdc_offset, unsigned char value)

{
    char saved_reg27_bit0;
  unsigned short status;
  unsigned int port32;
  unsigned char data[1];
  
  port32 = port & 0xff;
  status = hdmi_tx_ddc_reset(port);
  if ((status & 0xff) == 0) {
    status = hdmi_tx_reg_read8(port32,0,0x27) & 1;
    hdcp_tx_hdmi_set_reg27_bit0(port32,0);
    data[0] = value;
    hdmi_tx_ddc_write(port32,data,SCDC_I2C_ADDRESS,scdc_offset & 0xff,1);
    saved_reg27_bit0 = status;
    saved_reg27_bit0 = saved_reg27_bit0 & 1;
    hdcp_tx_hdmi_set_reg27_bit0(port32, saved_reg27_bit0);
  }
}
