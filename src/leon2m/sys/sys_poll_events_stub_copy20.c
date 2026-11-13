/* sys_poll_events_stub_copy20  (FUN_a014771c)
 *
 * Do nothing (empty application event source)
 * Note: Called by the event pump with the other event sources. Identical copy of sys_poll_events_stub.
 * Name basis: descriptive - empty function called by sys_pump_app_events
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014771c @ 0xa014771c (-mcpu=v8 -O2 -g)
 * Source form: an explicit return in the body.
 */

/* Empty: returns at once. */
void sys_poll_events_stub_copy20(void)

{
  return;
}
