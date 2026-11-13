/* sys_poll_events_stub_copy21  (FUN_a014b968)
 *
 * Do nothing (empty routine).
 * Note: Identical copy of sys_poll_events_stub; the event pump does not call this copy.
 * Name basis: descriptive - empty function; called by sys_user_apply_table_record_slot5 and
 *   sys_user_apply_table_record_slot6
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014b968 @ 0xa014b968 (-mcpu=v8 -O2 -g, the section default).
 * Source form: the decompiler's void signature is kept.
 */

/* Does nothing. sys_user_apply_table_record_slot5 and sys_user_apply_table_record_slot6 call it, with 5 or 6 and the address of a local record; it ignores both. */
void sys_poll_events_stub_copy21(void)

{
  return;
}
