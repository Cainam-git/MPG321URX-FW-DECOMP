/* hdmi_tx_set_reg3b_mode  (FUN_a008e73c)
 *
 * Set or clear bit 6 of HDMI TX register 0x3B and its low mode bits.
 *   port: HDMI TX port
 *   on: 1 = set
 * Name basis: descriptive - bank 1 reg 0x3B; caller hdmi_tx_phy_setup_frl
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e73c @ 0xa008e73c, flags -mcpu=v8 -Os -g.
 * Source form: the externs are declared without prototypes; the OR with 1 in the else arm goes through a
 * small inline function, and the unused words param_3..param_6 are the decompiler's pass-through (the last
 * write forwards param_5 and param_6).
 */
extern int hdmi_tx_reg_read8();
extern int hdmi_tx_reg_write8();
extern int hdmi_tx_reg_update_bits();
inline int inline_fn(unsigned char arg0)
{
  return arg0 | 1;
}

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Set (on == 1) or clear (otherwise) bit 6 of HDMI TX register 0x3B, then rewrite the register's low nibble:
 *   on == 1: low nibble = 0 (the upper nibble is kept, bit 6 included);
 *   otherwise: bits 1..3 cleared and bit 0 set, upper nibble kept.
 *   port: HDMI TX port.  param_3 to param_6: not used here; param_5 and param_6 are passed on to the write.
 * Called by hdmi_tx_phy_setup_frl (with on = 1).
 */
void hdmi_tx_set_reg3b_mode(unsigned char port, unsigned char on, int param_3, int param_4, int param_5, int param_6)
{
  unsigned char value;
  unsigned char port_byte;
  unsigned int port_word;
  port_byte = port & 0xff;
  port_word = port_byte;
  if (on == 1)
  {
    hdmi_tx_reg_update_bits(port_word, HDMI_TX_BANK_PHY, 0x3b, 0x40, 1);
    value = hdmi_tx_reg_read8(port_word, HDMI_TX_BANK_PHY, 0x3b) & 0xf0;
    hdmi_tx_reg_write8(port_word, HDMI_TX_BANK_PHY, 0x3b, value, param_5, param_6);
  }
  else
  {
    hdmi_tx_reg_update_bits(port_word, HDMI_TX_BANK_PHY, 0x3b, 0x40, 0);
    value = hdmi_tx_reg_read8(port_word, HDMI_TX_BANK_PHY, 0x3b) & 0xf1;
    value = inline_fn(value);
    hdmi_tx_reg_write8(port_word, HDMI_TX_BANK_PHY, 0x3b, value, param_5, param_6);
  }
}
