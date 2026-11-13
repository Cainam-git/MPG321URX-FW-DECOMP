/* sys_api_latch_status_state  (FUN_a0147c80)
 *
 * Derive a 0..2 state from the status bits and latch it.
 * Name basis: descriptive - forwards to the routine that writes it one-hot to 0xCF01345C; unused
 *
 * Matching notes
 * --------------
 * FUN_a0147c80 (leon2m 0xa0147c80-0xa0147c94, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * The call is a tail call; the nop after it is the -g line nop. Nothing in the image refers to this
 * routine. Source form: an unsigned char parameter passed on (and 0xff before the call).
 */
extern void sys_latch_status_state(unsigned char);

/* Pass the argument on to sys_latch_status_state. Nothing calls this routine. */
void sys_api_latch_status_state(unsigned char value)
{
    sys_latch_status_state(value);
}
