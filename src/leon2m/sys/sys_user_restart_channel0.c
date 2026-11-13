/* sys_user_restart_channel0  (FUN_a00d4910)
 *
 * Restart channel 0 at level 1.
 * Name basis: descriptive - sys_api_restart_channel_at_level(0, 1); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4910 @ 0xa00d4910-0xa00d4928 (6 words), flags -mcpu=v8 -O2 -g.
 * Calls sys_api_restart_channel_at_level(0, 1) as a tail call. The caller's return address is handed on, so the callee returns
 * straight to this routine's caller. The last word is the nop the compiler places behind such a call sequence.
 * Nothing in the firmware calls it and no stored address points at it (unused code).
 */
extern void sys_api_restart_channel_at_level(unsigned char, unsigned char);

#define MAIN_CHANNEL 0                  /* channel 0: the main picture */

/* Restart channel 0 at level 1: sys_api_restart_channel_at_level(0, 1). Nothing calls it. */
void sys_user_restart_channel0(void)
{
    sys_api_restart_channel_at_level(MAIN_CHANNEL, 1);
}
