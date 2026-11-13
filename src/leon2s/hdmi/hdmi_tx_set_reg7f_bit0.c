/* hdmi_tx_set_reg7f_bit0  (FUN_a008db90)
 *
 * Set or clear bit 0 of HDMI TX register 0x7F.
 *   port: HDMI TX port
 *   on: 1 = set
 * Name basis: descriptive - single bit; callers hdmi_tx_phy_switch_power and hdmi_tx_phy_power_down
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008db90 @ 0xa008db90, flags -mcpu=v8 -Os -g.
 * Source form: the extern is declared without a prototype; the call is written in both arms of an if / else.
 */
extern int hdmi_tx_reg_update_bits();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Set (on != 0) or clear (on == 0) bit 0 of HDMI TX register 0x7F.
 *   port: HDMI TX port.  Called by hdmi_tx_phy_switch_power and hdmi_tx_phy_power_down.
 */
void hdmi_tx_set_reg7f_bit0(unsigned char port, unsigned char on)
{
    if (on != 0)
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x7f, 1, 1);
    else
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x7f, 1, 0);
    return;
}
