/* hdmi_tx_write_reg0c  (FUN_a008dfe4)
 *
 * Write a value to HDMI TX register 0x0C.
 *   port: HDMI TX port
 *   value
 * Name basis: descriptive - single write; caller hdmi_tx_load_reg0c_trim
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008dfe4 @ 0xa008dfe4, flags -mcpu=v8 -Os -g.
 * Source form: the extern is declared without a prototype, as the decompiler wrote it.
 */
extern int hdmi_tx_reg_write8();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/* Write a value to HDMI TX register 0x0C. Called by hdmi_tx_load_reg0c_trim. */
void hdmi_tx_write_reg0c(unsigned char port, unsigned char value)

{
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0xc, value);
}
