/* hdmi_tx_set_reg8_bits45  (FUN_a0094f64)
 *
 * Set HDMI TX register 8 bits 4..5 and write 10 to register 0x130.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - only caller hdmi_tx_run_step, in its TMDS link step
 *
 * Matching notes
 * --------------
 * FUN_a0094f64 (leon2s 0xa0094f64-0xa0094fb0, 76 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the register write is a tail call.
 */
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);

/*
 * Set bits 4 and 5 of register 8 of bank 0 and write 10 to register 0x130 of bank 0.
 *   port: HDMI TX port 0/1
 * Called by hdmi_tx_run_step in TX_STEP_LINK_TMDS, before the PHY is tuned for the TMDS clock.
 */
void hdmi_tx_set_reg8_bits45(unsigned char port)
{
    hdmi_tx_reg_update_bits(port, 0, 8, 0x10, 1);
    hdmi_tx_reg_update_bits(port, 0, 8, 0x20, 1);
    hdmi_tx_reg_write8(port, 0, 0x130, 10);
}
