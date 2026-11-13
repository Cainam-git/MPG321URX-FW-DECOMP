/* sys_poll_events_stub_copy  (FUN_a00d8b30)
 *
 * Do nothing (empty application event source)
 * Note: Called by the event pump with the other event sources. Identical copy of sys_poll_events_stub.
 * Name basis: descriptive - empty function called by sys_pump_app_events
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d8b30 @ 0xa00d8b30, flags -mcpu=v8 -O2 -g.
 * Empty function: returns at once.
 */
/* Empty event source; it is called by the event pump together with the other event sources. */
void sys_poll_events_stub_copy(void)
{
  return;
}
