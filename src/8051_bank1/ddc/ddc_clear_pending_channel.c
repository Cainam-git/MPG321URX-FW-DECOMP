/* ddc_clear_pending_channel  (FUN_CODE_dbc8)
 *
 * Clear the message-waiting flag of DDC/CI channel n.
 *   channel
 * Name basis: derived - bit n of 0xA0F3, cleared by the report builder after sending type 4
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dbc8 @ 0xdbc8 (23 B)
 * Options: OPTIMIZE(7,SPEED) (also level 8).
 * Source form: the old byte is read into a local first.
 */
extern unsigned char xdata ddc_pending_channel_flags;

/* Clear bit channel of ddc_pending_channel_flags (one bit per DDC/CI slave
 * port with a finished request waiting to be reported).
 *   channel: bit number */
void ddc_clear_pending_channel(unsigned char channel)
{
    unsigned char old_flags;

    old_flags = ddc_pending_channel_flags;
    ddc_pending_channel_flags = old_flags & ~(1 << channel);
}
