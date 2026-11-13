/* sys_poll_events_stub_copy5  (FUN_a0107ba4)
 *
 * Do nothing (empty routine).
 * Note: Identical copy of sys_poll_events_stub; the event pump does not call this copy.
 * Name basis: descriptive - empty function; called by sys_service_ports_by_mask and
 *   input_power_on_ports_by_mask
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0107ba4 @ 0xa0107ba4, flags -mcpu=v8 -O2 -g (the section default).
 * Empty function: returns at once.
 */
/*
 * Empty. Its callers, sys_service_ports_by_mask (sys_service_ports_by_mask) and input_power_on_ports_by_mask (input_power_on_ports_by_mask),
 * call it with two arguments, a 0 or 1 and a 0 or 1; the routine takes no parameters and does nothing.
 */
void sys_poll_events_stub_copy5(void)
{
}
