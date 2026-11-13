/* sys_poll_events_stub_copy4  (FUN_a0101e68)
 *
 * Do nothing (empty routine).
 * Note: Identical copy of sys_poll_events_stub; the event pump does not call this copy.
 * Name basis: descriptive - empty function; called by sys_shut_down_blocks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101e68 @ 0xa0101e68, flags -mcpu=v8 -O2 -g (the section default).
 * Empty function: returns at once.
 */
/*
 * Empty. Its one caller, sys_shut_down_blocks (sys_shut_down_blocks), calls it without arguments.
 */
void sys_poll_events_stub_copy4(void)
{
}
