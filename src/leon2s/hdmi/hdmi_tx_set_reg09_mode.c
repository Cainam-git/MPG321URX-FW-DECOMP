/* hdmi_tx_set_reg09_mode  (FUN_a008df40)
 *
 * Write 0x43 or 0x42 to HDMI TX register 9.
 *   port: HDMI TX port
 *   on: 1 = 0x43
 * Name basis: descriptive - bank 1 reg 9; called with 0 at PHY power-down
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008df40 @ 0xa008df40, flags -mcpu=v8 -Os -g.
 * Source form: the extern is declared without a prototype; the call is written in both arms of an if / else
 * (the 'btst 0xff' of the target tests the whole byte).
 */
extern int hdmi_tx_reg_write8();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Write 0x43 (on != 0) or 0x42 (on == 0) to HDMI TX register 9, the whole register.
 *   port: HDMI TX port.  Called by hdmi_tx_phy_enable_outputs and hdmi_tx_phy_power_down.
 */
void hdmi_tx_set_reg09_mode(unsigned char port, unsigned char on)
{
    if (on != 0)
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 9, 0x43);
    else
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 9, 0x42);
    return;
}
