/* hdmi_tx_set_reg7c_low_nibble  (FUN_a008d8e0)
 *
 * Write 0x0F (on = 1) or 0 to register 0x7C of the PHY bank of an HDMI output.
 *   port: HDMI TX port
 *   on: 1 = set
 * Note: Writes the whole register; it is not read first.
 * Name basis: descriptive - bank 1 reg 0x7C = 0x0F or 0; callers PHY power-down
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008d8e0 @ 0xa008d8e0, flags -mcpu=v8 -Os -g.
 * Source form: the extern is declared without a prototype, as the decompiler wrote it.
 */
extern int hdmi_tx_reg_write8();

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Write 0x0F (on == 1) or 0 (any other value) to HDMI TX register 0x7C, the whole register.
 *   port: HDMI TX port.  Called by hdmi_tx_phy_power_down and hdmi_tx_run_step.
 */
void hdmi_tx_set_reg7c_low_nibble(unsigned char port, unsigned char on)
{
    if (on == 1) {
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x7c, 0xf);
    } else {
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 0x7c, 0);
    }
}
