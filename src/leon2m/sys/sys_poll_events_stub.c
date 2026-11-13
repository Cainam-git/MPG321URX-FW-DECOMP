/* sys_poll_events_stub  (FUN_a008e7a8)
 *
 * Do nothing (empty application event source)
 * Note: Called by the event pump with the other event sources.
 * Name basis: descriptive - empty function called by sys_pump_app_events
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008e7a8 @ 0xa008e7a8, flags -mcpu=v8 -O2 -g (section default).
 * Empty function: returns at once.
 */
/* Does nothing. sys_pump_app_events calls it with every event, as one of its four consumers. */
void sys_poll_events_stub(void)
{
}
