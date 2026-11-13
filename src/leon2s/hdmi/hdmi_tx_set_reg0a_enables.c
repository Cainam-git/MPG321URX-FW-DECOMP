/* hdmi_tx_set_reg0a_enables  (FUN_a008da88)
 *
 * Set or clear the four enable bits of HDMI TX register 0x0A.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: descriptive - bits 2..5 of bank 1 reg 0x0A
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008da88 @ 0xa008da88-0xa008db4c, flags -mcpu=v8 -Os -g.
 * Source form: both arms are written out in full (four calls each); the last call is a tail call.
 */
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */

/*
 * Set (on != 0) or clear (on == 0) bits 2, 3, 4 and 5 of HDMI TX register 0x0A, one bit at a time.
 *   port: HDMI TX port.  Called by hdmi_tx_phy_enable_outputs.
 */
void hdmi_tx_set_reg0a_enables(unsigned char port, unsigned char on)
{
    if (on != 0) {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 10, 4, 1);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 10, 8, 1);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 10, 0x10, 1);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 10, 0x20, 1);
    } else {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 10, 4, 0);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 10, 8, 0);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 10, 0x10, 0);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 10, 0x20, 0);
    }
}
