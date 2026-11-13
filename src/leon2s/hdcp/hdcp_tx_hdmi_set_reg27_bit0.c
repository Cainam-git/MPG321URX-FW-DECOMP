/* hdcp_tx_hdmi_set_reg27_bit0  (FUN_a00c8a1c)
 *
 * Set or clear bit 0 of register 0x27 of an HDMI output.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * FUN_a00c8a1c (leon2s 0xa00c8a1c-0xa00c8a80, 25 words), flags -mcpu=v8 -Os -g.
 */
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, int);
extern void hdmi_tx_reg_write8(unsigned char, int, int, unsigned char);

/*
 * Set (on == 1) or clear (any other value) bit 0 of register 0x27 of HDMI output `port`. What the bit
 * controls is not shown in the code.
 *
 * Called from hdcp_tx_hdmi_state_check_link, hdcp_tx_hdmi_disable, hdcp_tx_hdmi_state_probe and from the picture code
 * (hdmi_tx_scdc_write, hdmi_tx_check_hotplug).
 */
void hdcp_tx_hdmi_set_reg27_bit0(unsigned char port, unsigned char on)
{
    if (on == 1)
        hdmi_tx_reg_write8(port, 0, 0x27, hdmi_tx_reg_read8(port, 0, 0x27) | 1);
    else
        hdmi_tx_reg_write8(port, 0, 0x27, hdmi_tx_reg_read8(port, 0, 0x27) & 0xfe);
}
