/* hdmi_tx_set_regs_7c_9a  (FUN_a008e3c0)
 *
 * Set the fields of HDMI TX registers 0x7C and 0x9A from one value.
 *   port: HDMI TX port
 *   v: value
 * Name basis: descriptive - 0 at power-down; 0 or 0x30 in the TMDS set-up
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e3c0 @ 0xa008e3c0, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes; the unused parameters are the decompiler's pass-through
 * of the argument registers (the last write forwards the last two).
 */
extern int hdmi_tx_reg_read8();
extern void hdmi_tx_reg_write8();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Read-modify-write HDMI TX registers 0x7C and 0x9A from one value:
 *   - register 0x7C: clear bits 4..5, OR in the low byte of value << 4;
 *   - register 0x9A: clear bits 0..1, OR in the whole value; then clear bit 3, OR in the low byte of value << 2;
 *     then clear bits 4..5, OR in the low byte of value << 4.
 *   port: HDMI TX port.  value: the setting.  unused_3 to unused_6: not used here; unused_5 and unused_6 are
 *   passed on in the last write.
 * Called by hdmi_tx_phy_setup_frl, hdmi_tx_phy_power_down, hdmi_tx_phy_tune_for_tmds_clock and hdmi_tx_set_txffe_mode.
 */
void hdmi_tx_set_regs_7c_9a(unsigned char port, unsigned int value, unsigned int unused_3, unsigned int unused_4, unsigned int unused_5
                 , unsigned int unused_6)

{
  unsigned int reg;
  unsigned int value_high;
  
  port = port & 0xff;
  reg = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x7c);
  value_high = (value & 0xff) << 4;
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x7c, (reg & 0xffffffcf | value_high) & 0xff);
  reg = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x9a);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x9a, (value | reg & 0xfffffffc) & 0xff);
  reg = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x9a);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x9a, (reg & 0xfffffff7 | (value & 0xff) << 2) & 0xff);
  reg = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, 0x9a);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x9a, (reg & 0xffffffcf | value_high) & 0xff, unused_5, unused_6);
}
