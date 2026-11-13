/* hdmi_pulse_reg133_bit7  (FUN_a008fa00)
 *
 * Pulse bit 7 of HDMI receiver register 0x133.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - set then clear; caller hdmi_tmds_run_link_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008fa00 @ 0xa008fa00 (-mcpu=v8 -Os -g)
 */

#define RX_REG_133  0x133

extern int hdmi_reg_update_bits();

/* Called by the link state machine on the way from STABLE to READY, just before the latched status registers
   are cleared. Bit 7 of register 0x133 is set and cleared again at once. */
void hdmi_pulse_reg133_bit7(unsigned char port)
{
    hdmi_reg_update_bits(port, RX_REG_133, 0x80, 1);
    hdmi_reg_update_bits(port, RX_REG_133, 0x80, 0);
}
