/* hdmi_tx_set_reg08_bit3  (FUN_a008db4c)
 *
 * Set or clear bit 3 of HDMI TX register 8.
 *   port: HDMI TX port
 *   on: 1 = set
 * Name basis: descriptive - single bit; callers hdmi_tx_phy_switch_power and hdmi_tx_phy_power_down
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008db4c @ 0xa008db4c, flags -mcpu=v8 -Os -g.
 * Source form: the extern is declared without a prototype; both parameters are bytes (btst 0xff, %o1 and
 * and %o0, 0xff, %g1 in the target); each arm is a tail call.
 */
extern int hdmi_tx_reg_update_bits();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Set (on != 0) or clear (on == 0) bit 3 of HDMI TX register 8.
 *   port: HDMI TX port.  Called by hdmi_tx_phy_switch_power and hdmi_tx_phy_power_down.
 */
void hdmi_tx_set_reg08_bit3(unsigned char port, unsigned char on)
{
    if (on != 0)
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 8, 8, 1);
    else
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 8, 8, 0);
    return;
}
