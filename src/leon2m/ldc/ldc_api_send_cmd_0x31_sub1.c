/* ldc_api_send_cmd_0x31_sub1  (FUN_a0143848)
 *
 * Send dimming command 0x31, variant 1, with a 16-bit value.
 * Name basis: descriptive - tail call to the mailbox portal 2 sender
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143848 @ 0xa0143848, flags -mcpu=v8 -O2 -g.
 * Source form: a one-line forward; the firmware makes it a tail call (the caller's return address is handed on),
 * followed by the nop that belongs to such a call sequence.
 */
extern void ldc_send_user_adim_sub1(unsigned short);

/* Forward value to ldc_send_user_adim_sub1 (command 0x31, set usUserADIM). Called by pq_fga_handle_command. */
void ldc_api_send_cmd_0x31_sub1(unsigned short value)
{
    ldc_send_user_adim_sub1(value);
}
