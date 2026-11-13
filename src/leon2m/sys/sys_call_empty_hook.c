/* sys_call_empty_hook  (FUN_a0132a14)
 *
 * Call a routine that is empty in this firmware.
 * Name basis: descriptive - forwards to the empty routine at 0xA013855C; called by
 *   sys_channel_apply_output_timing
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0132a14 @ 0xa0132a14 (-mcpu=v8 -O2 -g)
 * The extern is declared without a parameter list, as in the decompiler output.
 */
extern int sys_poll_events_stub_copy17();

/* Call sys_poll_events_stub_copy17, an empty routine, with the argument. Called by sys_channel_apply_output_timing. */
void sys_call_empty_hook(unsigned char arg)
{
  sys_poll_events_stub_copy17(arg);
}
