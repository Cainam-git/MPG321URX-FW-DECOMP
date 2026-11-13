/* sys_poll_events_stub_copy22  (FUN_a0151494)
 *
 * Do nothing (empty routine).
 * Note: Identical copy of sys_poll_events_stub; the event pump does not call this copy.
 * Name basis: descriptive - empty function; called by GlobalModeHandler when a channel goes from state 5 to
 *   state 6
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0151494 @ 0xa0151494 (-mcpu=v8 -O2 -g, the section default).
 * Source form: the decompiler's void signature is kept.
 */


/* Does nothing. The channel state handler GlobalModeHandler calls it, with the channel number, when a channel leaves
 * state 5 for state 6; the routine ignores the argument. */
void sys_poll_events_stub_copy22(void)

{
  return;
}
