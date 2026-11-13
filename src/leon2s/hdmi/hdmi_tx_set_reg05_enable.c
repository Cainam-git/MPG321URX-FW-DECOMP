/* hdmi_tx_set_reg05_enable  (FUN_a008df7c)
 *
 * Set HDMI TX register 5 bit 0, or 0x0D for the special port mode.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: descriptive - bit 4 of the TX record word 0 selects 0x0D
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008df7c @ 0xa008df7c-0xa008dfe4, flags -mcpu=v8 -Os -g.
 * Source form: three separate calls in nested if/else arms, the clear-bit test first (one shared call with a flag
 * variable gives a frameless function). The calls are tail calls.
 */
extern unsigned int hdmi_tx_output_records[];
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */
#define CHANNEL_FRL_MODE 0x10           /* word 0 of an HDMI TX channel record: frl_mode */

/*
 * on == 0: clear bit 0 of HDMI TX register 5.
 * on != 0: when frl_mode is set in word 0 of the port's 7-word channel record (hdmi_tx_output_records), write 0x0D to
 * register 5 (the whole register); otherwise set bit 0 of register 5.
 *   port: HDMI TX port.  Called by hdmi_tx_phy_enable_outputs and hdmi_tx_phy_power_down.
 */
void hdmi_tx_set_reg05_enable(unsigned char port, unsigned char on)
{
    if (on != 0) {
        if (!(hdmi_tx_output_records[port * 7] & CHANNEL_FRL_MODE))
            hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 5, 1, 1);
        else
            hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, 5, 0xd);
    } else {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, 5, 1, 0);
    }
}
