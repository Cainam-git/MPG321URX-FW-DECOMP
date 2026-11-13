/* hdmi_tx_set_phy_reg3b_bits  (FUN_a00a338c)
 *
 * Set or clear bits 4 and 5 of PHY register 0x3B of an HDMI TX port.
 *   port: HDMI TX port
 *   on: 1 = set
 * Name basis: descriptive - bank 1 register 0x3B; caller DRV_HDMI21_TXDetect_FSM_LTS_3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a338c @ 0xa00a338c, flags -mcpu=v8 -Os -g.
 * Source form: both arms are written out in full; the last call of each arm is a tail call.
 */
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);

#define HDMI_TX_BANK_PHY 1          /* bank 1 of the HDMI transmitter registers */

/* Set (on = 1) or clear (any other value) bits 5 and 4 of register 0x3B in the PHY bank of the HDMI
   transmitter port, bit 5 first. Called by DRV_HDMI21_TXDetect_FSM_LTS_3. */
void hdmi_tx_set_phy_reg3b_bits(unsigned char port, unsigned char on)
{
    if (on == 1) {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x3b, 0x20, 1);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x3b, 0x10, 1);
    } else {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x3b, 0x20, 0);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 0x3b, 0x10, 0);
    }
}
