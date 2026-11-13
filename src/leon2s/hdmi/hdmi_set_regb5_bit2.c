/* hdmi_set_regb5_bit2  (FUN_a008fe6c)
 *
 * Set or clear bit 2 of HDMI receiver register 0xB5.
 *   port: HDMI 2.0 receiver
 *   on: 1 = set
 * Name basis: descriptive - single bit; caller hdmi_tmds_run_link_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008fe6c @ 0xa008fe6c (-mcpu=v8 -Os -g)
 * Source form: "on" is tested for non-zero ('btst 0xff'); the update call is in both arms.
 */

#define RX_REG_B5   0xb5

extern int hdmi_reg_update_bits();

/* Bit 2 of register 0xB5 is set when "on" is not 0 and cleared when it is 0. The link state machine sets it
   when a port goes to STANDBY and clears it again on the way from STABLE to READY. */
void hdmi_set_regb5_bit2(unsigned char port, unsigned char on)
{
    if (on != 0)
        hdmi_reg_update_bits(port, RX_REG_B5, 4, 1);
    else
        hdmi_reg_update_bits(port, RX_REG_B5, 4, 0);
}
