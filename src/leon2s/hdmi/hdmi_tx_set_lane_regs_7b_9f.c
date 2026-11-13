/* hdmi_tx_set_lane_regs_7b_9f  (FUN_a008e098)
 *
 * Write one value to HDMI TX registers 0x7B and 0x9D..0x9F.
 *   port: HDMI TX port
 *   v: value
 * Name basis: descriptive - 0 at power-down, 0x1B in the TMDS set-up
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e098 @ 0xa008e098, flags -mcpu=v8 -Os -g.
 * Source form: the extern is declared without a prototype. The four unused parameters are the decompiler's
 * pass-through of the argument registers; the last call is a tail call that forwards the last two.
 */
extern void hdmi_tx_reg_write8();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Write one value to HDMI TX registers 0x7B, 0x9D, 0x9E and 0x9F.
 *   port: HDMI TX port.  value: the byte.  unused_3 to unused_6: not used here; unused_5 and unused_6 are
 *   passed on in the last call.
 * Called by hdmi_tx_phy_setup_frl, hdmi_tx_phy_power_down and hdmi_tx_phy_tune_for_tmds_clock.
 */
void hdmi_tx_set_lane_regs_7b_9f(unsigned char port, unsigned char value, unsigned int unused_3, unsigned int unused_4,
                 unsigned int unused_5, unsigned int unused_6)

{
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x7b, value);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x9d, value);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x9e, value);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x9f, value, unused_5, unused_6);
}
