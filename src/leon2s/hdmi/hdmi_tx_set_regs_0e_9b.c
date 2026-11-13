/* hdmi_tx_set_regs_0e_9b  (FUN_a008e200)
 *
 * Set the 3-bit fields of HDMI TX registers 0x0E and 0x9B.
 *   port: HDMI TX port
 *   v: value
 * Name basis: descriptive - low and upper 3-bit fields of both registers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e200 @ 0xa008e200, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes; the unused parameters are the decompiler's pass-through
 * of the argument registers (the last write forwards the last two).
 */
extern int hdmi_tx_reg_read8();
extern void hdmi_tx_reg_write8();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * For each of HDMI TX registers 0x0E and 0x9B, in two read-modify-write steps:
 *   - clear bits 0..2, then OR in the value (the whole value, not only its low three bits);
 *   - clear bits 4..6, then OR in the low byte of value << 4.
 *   port: HDMI TX port.  value: the setting.  unused_3 to unused_6: not used here; unused_5 and unused_6 are
 *   passed on in the last write.
 * Called by hdmi_tx_phy_setup_frl, hdmi_tx_phy_power_down, hdmi_tx_phy_tune_for_tmds_clock and hdmi_tx_set_txffe_mode.
 */
void hdmi_tx_set_regs_0e_9b(unsigned int port, int value, unsigned int unused_3, unsigned int unused_4, unsigned int unused_5
                 , unsigned int unused_6)

{
  unsigned int reg;
  unsigned int value_high;
  
  port = port & 0xff;
  reg = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0xe);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0xe, (value | reg & 0xfffffff8) & 0xff);
  reg = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0xe);
  value_high = (value & 0xff) << 4;
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0xe, (reg & 0xffffff8f | value_high) & 0xff);
  reg = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x9b);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x9b, (value | reg & 0xfffffff8) & 0xff);
  reg = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x9b);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x9b, (reg & 0xffffff8f | value_high) & 0xff, unused_5, unused_6);
}
