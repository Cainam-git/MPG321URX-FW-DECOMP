/* hdcp_tx_hdmi_get_status_bit6  (FUN_a00c9370)
 *
 * Return status bit 6 of an HDMI output's protection block.
 * Returns: 0 or 1
 * Name basis: descriptive - register read masked with 0x40
 *
 * Matching notes
 * --------------
 * FUN_a00c9370 (leon2s 0xa00c9370-0xa00c9398, 10 words), flags -mcpu=v8 -Os -g.
 * Source form: the masked result is stored in a local before the comparison (as in hdmi_status134_bit1), which gives
 * the firmware's 'cmp %g0, %o0; addx %g0, 0, %i0'.
 */
extern unsigned int hdmi_tx_reg_read8(unsigned int param_1, unsigned int param_2, unsigned int param_3);

/*
 * Return bit 6 of register 0x0F of HDMI output `output` (0 or 1). The register is read with the HDMI output
 * register read (hdmi_tx_reg_read8).
 *
 * Called by hdcp_tx_get_output_status.
 */
unsigned int hdcp_tx_hdmi_get_status_bit6(unsigned int output)
{
    unsigned int bit6 = hdmi_tx_reg_read8(output & 0xff, 0, 0xf) & 0x40;
    return bit6 != 0;
}
