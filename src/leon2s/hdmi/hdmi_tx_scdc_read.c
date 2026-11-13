/* hdmi_tx_scdc_read  (FUN_a0091d64)
 *
 * Read one SCDC register of the display connected to an HDMI TX port.
 *   port: HDMI TX port
 *   scdc_offset: SCDC register
 * Returns: byte
 * Name basis: proven - DDC read from I2C address 0xA8 (SCDC), data from reg 0xF4; callers the FRL training
 *   steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091d64 @ 0xa0091d64 (-mcpu=v8 -Os -g)
 * The data register is read twice and the second result is returned.
 */
extern int hdmi_tx_reg_read8();
extern int timer_delay_long_units();
extern int hdmi_tx_ddc_start();

#define SCDC_I2C_ADDRESS 0xa8           /* I2C address of the sink's SCDC registers */
#define DDC_DATA_REG 0xf4               /* DDC master data register */

/*
 * Read the SCDC register 'scdc_offset' of the sink on HDMI TX 'port'.
 *
 * Programs the DDC master for device 0xA8, offset 'scdc_offset' and a count of 1 (hdmi_tx_ddc_start), waits timer_delay_long_units(2), then reads TX register 0xF4 (bank 0) twice
 * and returns the second value.
 */
unsigned char hdmi_tx_scdc_read(unsigned int port, unsigned int scdc_offset)

{
  port = port & 0xff;
  hdmi_tx_ddc_start(port,SCDC_I2C_ADDRESS,scdc_offset & 0xff,1);
  timer_delay_long_units(2);
  hdmi_tx_reg_read8(port,0,DDC_DATA_REG);
  return hdmi_tx_reg_read8(port,0,DDC_DATA_REG);
}
