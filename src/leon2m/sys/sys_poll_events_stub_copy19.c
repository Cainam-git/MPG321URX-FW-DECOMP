/* sys_poll_events_stub_copy19  (FUN_a01437fc)
 *
 * Do nothing (empty application event source)
 * Note: Called by the event pump with the other event sources. Identical copy of sys_poll_events_stub.
 * Name basis: descriptive - empty function called by sys_pump_app_events
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01437fc @ 0xa01437fc (-mcpu=v8 -O2 -g)
 * Source form: an explicit return in the body.
 */

/* Empty: returns at once. */
void sys_poll_events_stub_copy19(void)

{
  return;
}
