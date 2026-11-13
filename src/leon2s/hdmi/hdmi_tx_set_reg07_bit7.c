/* hdmi_tx_set_reg07_bit7  (FUN_a008e054)
 *
 * Set or clear bit 7 of HDMI TX register 7.
 *   port: HDMI TX port
 *   on: 1 = set
 * Name basis: descriptive - single bit
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e054 @ 0xa008e054, flags -mcpu=v8 -Os -g.
 * Source form: the extern is declared without a prototype; the call is written in both arms of the if / else
 * (the firmware loads 'mov 1, %o1' on both paths).
 */
extern int hdmi_tx_reg_update_bits();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Set (on != 0) or clear (on == 0) bit 7 of HDMI TX register 7.
 *   port: HDMI TX port.  Called by hdmi_tx_phy_enable_outputs.
 */
void hdmi_tx_set_reg07_bit7(unsigned char port, unsigned char on)
{
    if (on != 0)
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 7, 0x80, 1);
    else
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 7, 0x80, 0);
    return;
}
