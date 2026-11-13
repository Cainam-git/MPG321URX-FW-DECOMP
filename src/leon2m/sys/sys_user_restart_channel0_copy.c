/* sys_user_restart_channel0_copy  (FUN_a00d5d8c)
 *
 * Restart channel 0 at level 1.
 * Note: Identical copy of sys_user_restart_channel0.
 * Name basis: descriptive - sys_api_restart_channel_at_level(0, 1); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5d8c @ 0xa00d5d8c-0xa00d5da4 (6 words), flags -mcpu=v8 -O2 -g.
 * Source form: a tail call. The caller's return address is handed on, so the callee returns straight to this
 * routine's caller; the last word is the nop the compiler places behind such a call sequence.
 */
extern void sys_api_restart_channel_at_level(unsigned char channel, unsigned char level);

/* Restart channel 0 with level argument 1. Nothing calls it. */
void sys_user_restart_channel0_copy(void)
{
    sys_api_restart_channel_at_level(0, 1);
}
