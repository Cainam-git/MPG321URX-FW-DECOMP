/* hdmi_tx_set_reg0d_bit2  (FUN_a0094308)
 *
 * Set or clear bit 2 of HDMI TX register 0x0D.
 *   port: HDMI TX port
 *   on: 1 = on
 * Name basis: descriptive - mailbox command 0x47
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0094308 @ 0xa0094308 (-mcpu=v8 -Os -g)
 * The call is written in both arms of the if/else.
 */
extern int hdmi_tx_reg_update_bits();

/* Set (on != 0) or clear (on = 0) bit 2 of register 0x0D, bank 0, of HDMI TX 'port'. */
void hdmi_tx_set_reg0d_bit2(unsigned char port, unsigned char on)
{
    if (on != 0)
        hdmi_tx_reg_update_bits(port, 0, 0xd, 4, 1);
    else
        hdmi_tx_reg_update_bits(port, 0, 0xd, 4, 0);
    return;
}
