/* sys_api_set_all_channels_flag25  (FUN_a0143d98)
 *
 * Set flag bit 25 in all four channel records.
 * Name basis: descriptive - channel record word +0x70
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143d98 @ 0xa0143d98 (-mcpu=v8 -O2 -g)
 * Source form: the callee is declared int-returning with no parameters; explicit return at the end.
 */
extern int sys_set_all_channels_flag25();

/* Application-interface entry for sys_set_all_channels_flag25. */
void sys_api_set_all_channels_flag25(void)

{
  sys_set_all_channels_flag25();
  return;
}
