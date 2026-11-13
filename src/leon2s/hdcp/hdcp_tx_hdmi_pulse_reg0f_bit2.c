/* hdcp_tx_hdmi_pulse_reg0f_bit2  (FUN_a00c7ccc)
 *
 * Clear bit 2 of register 0x0F of an HDMI output, optionally setting it again after a wait.
 * Name basis: descriptive - pulse form for argument 1
 *
 * Matching notes
 * --------------
 * FUN_a00c7ccc (leon2s 0xa00c7ccc-0xa00c7d5c, 144 bytes), flags -mcpu=v8 -Os -g.
 * Source form: both arms end in their own tail call of hdmi_tx_reg_write8 (cross-jumped into one call plus a
 * restore); with one call at the join the firmware's early argument set-up of the mode-1 arm does not appear.
 */
extern unsigned int hdmi_tx_reg_read8(unsigned int, unsigned int, unsigned int);
extern void hdmi_tx_reg_write8(unsigned int, unsigned int, unsigned int, unsigned int);
extern void timer_delay_long_units(unsigned int);

#define HDMI_TX_CONTROL_REG 0x0f                /* register 0x0F of an HDMI output */
#define CONTROL_BIT2        0x04                /* bit 2 of that register */

/*
 * Clear bit 2 of register 0x0F of HDMI output `port`. With mode 1 the bit is set again after a wait of
 * timer_delay_long_units(1); with any other mode it stays cleared.
 *
 * Called with mode 1 by hdcp_tx_hdmi_state_run_checks and hdcp_tx_hdmi_state_start.
 */
void hdcp_tx_hdmi_pulse_reg0f_bit2(unsigned char port, unsigned char mode)
{
    unsigned int value;

    if (mode == 1) {
        value = hdmi_tx_reg_read8(port, 0, HDMI_TX_CONTROL_REG);
        hdmi_tx_reg_write8(port, 0, HDMI_TX_CONTROL_REG, value & 0xfb);
        timer_delay_long_units(1);
        value = hdmi_tx_reg_read8(port, 0, HDMI_TX_CONTROL_REG);
        hdmi_tx_reg_write8(port, 0, HDMI_TX_CONTROL_REG, (unsigned char)(value | CONTROL_BIT2));
    } else {
        value = hdmi_tx_reg_read8(port, 0, HDMI_TX_CONTROL_REG);
        hdmi_tx_reg_write8(port, 0, HDMI_TX_CONTROL_REG, value & 0xfb);
    }
}
