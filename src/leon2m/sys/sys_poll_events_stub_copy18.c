/* sys_poll_events_stub_copy18  (FUN_a01437f4)
 *
 * Do nothing (empty application event source)
 * Note: Called by the event pump with the other event sources. Identical copy of sys_poll_events_stub.
 * Name basis: descriptive - empty function called by sys_pump_app_events
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01437f4 @ 0xa01437f4 (-mcpu=v8 -O2 -g)
 * Source form: an explicit return in the body.
 */

/* Empty: returns at once. */
void sys_poll_events_stub_copy18(void)

{
  return;
}
