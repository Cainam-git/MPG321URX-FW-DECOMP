/* hdcp_tx_hdmi_set_enable  (FUN_a00c89b8)
 *
 * Switch the protection of an HDMI output on or off.
 * Name basis: derived - bit 0 of register 0x0F
 *
 * Matching notes
 * --------------
 * FUN_a00c89b8 (leon2s 0xa00c89b8-0xa00c8a1c, 25 words), flags -mcpu=v8 -Os -g.
 */
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, int);
extern void hdmi_tx_reg_write8(unsigned char, int, int, unsigned char);

/*
 * Set (on == 1) or clear (any other value) bit 0 of register 0x0F of HDMI output `port`.
 *
 * Called from hdcp_tx_hdmi_state_check_link and hdcp_tx_hdmi_disable.
 */
void hdcp_tx_hdmi_set_enable(unsigned char port, unsigned char on)
{
    if (on == 1)
        hdmi_tx_reg_write8(port, 0, 0xf, hdmi_tx_reg_read8(port, 0, 0xf) | 1);
    else
        hdmi_tx_reg_write8(port, 0, 0xf, hdmi_tx_reg_read8(port, 0, 0xf) & 0xfe);
}
