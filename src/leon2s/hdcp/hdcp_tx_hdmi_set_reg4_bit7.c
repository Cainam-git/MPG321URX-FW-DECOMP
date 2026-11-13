/* hdcp_tx_hdmi_set_reg4_bit7  (FUN_a00c9968)
 *
 * Set or clear bit 7 of register 4 of an HDMI output's protection block.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * FUN_a00c9968 (leon2s 0xa00c9968-0xa00c9998), flags -mcpu=v8 -Os -g.
 * Source form: both arms call hdcp_tx_reg_update_bits (declared without a prototype); the test of the unsigned
 * char (btst 0xff) branches to the clearing call and the fall-through sets the flag; 'mov 4, %o1' sits in the
 * branch delay slot.
 */
extern int hdcp_tx_reg_update_bits();

/*
 * Set (set != 0) or clear (set == 0) bit 7 of register 4 of the protection block of output `output`.
 *
 * Called from hdcp_tx_hdmi_state_refresh_status (set) and hdcp_tx_hdmi_disable (clear).
 */
void hdcp_tx_hdmi_set_reg4_bit7(unsigned char output, unsigned char set)
{
    if (set != 0)
        hdcp_tx_reg_update_bits(output, 4, 0x80, 1);
    else
        hdcp_tx_reg_update_bits(output, 4, 0x80, 0);
    return;
}
