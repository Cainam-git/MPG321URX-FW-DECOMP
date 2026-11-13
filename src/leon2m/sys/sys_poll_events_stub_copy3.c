/* sys_poll_events_stub_copy3  (FUN_a0101858)
 *
 * Do nothing (empty routine).
 * Note: Identical copy of sys_poll_events_stub; the event pump does not call this copy.
 * Name basis: descriptive - empty function; called by panel_level_gen_set_target
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101858 @ 0xa0101858, flags -mcpu=v8 -O2 -g (the section default).
 * Empty function: returns at once. Callers pass it arguments, which it ignores.
 */
/*
 * Empty. Its one caller, panel_level_gen_set_target (panel_level_gen_set_target), calls it with the arguments (7, 0xd); the
 * routine takes no parameters and does nothing.
 */
void sys_poll_events_stub_copy3(void)
{
}
