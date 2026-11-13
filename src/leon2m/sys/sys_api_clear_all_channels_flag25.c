/* sys_api_clear_all_channels_flag25  (FUN_a0143da8)
 *
 * Clear flag bit 25 in all four channel records.
 * Name basis: descriptive - channel record word +0x70
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143da8 @ 0xa0143da8 (-mcpu=v8 -O2 -g)
 * Source form: the callee is declared int-returning with no parameters; explicit return at the end.
 */
extern int sys_clear_all_channels_flag25();

/* Application-interface entry for sys_clear_all_channels_flag25. */
void sys_api_clear_all_channels_flag25(void)

{
  sys_clear_all_channels_flag25();
  return;
}
