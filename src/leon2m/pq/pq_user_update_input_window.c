/* pq_user_update_input_window  (FUN_a00d4928)
 *
 * Update the input window of channel 0.
 * Name basis: descriptive - pq_update_input_window(0); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4928 @ 0xa00d4928-0xa00d493c (5 words), flags -mcpu=v8 -O2 -g.
 * Source form: calls pq_update_input_window(0) as a tail call; the caller's return address is handed on, so
 * the callee returns straight to this routine's caller. The last word is the nop the compiler places behind
 * such a call sequence.
 */
#define CHANNEL_0 0                          /* channel 0 */

extern void pq_update_input_window(unsigned char channel);

/*
 * Update the input window of channel 0.
 * Calls pq_update_input_window, which recomputes and stores a port's input crop window
 * (video wall, margins, rate scaling), for channel 0.
 * The call is a tail call: the callee returns directly to this routine's caller.
 */
void pq_user_update_input_window(void)
{
    pq_update_input_window(CHANNEL_0);
}
