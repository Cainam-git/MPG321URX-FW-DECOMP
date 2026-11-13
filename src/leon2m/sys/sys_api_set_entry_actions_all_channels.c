/* sys_api_set_entry_actions_all_channels  (FUN_a0145354)
 *
 * Store whether the state entry actions run for every channel (1) or only channel 0 (0).
 * Name basis: derived - stores stSysConfig byte +0x2F, which GlobalModeHandler tests before the state entry
 *   actions; called from UserSetPIPMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145354 @ 0xa0145354 (-mcpu=v8 -O2 -g)
 * Source form: explicit return at the end of the body.
 */
extern unsigned char sys_config_entry_actions_all_channels;

/* Store value in the configuration byte at 0xA802E3ff (+0x2F of the configuration). */
void sys_api_set_entry_actions_all_channels(unsigned char value)

{
  sys_config_entry_actions_all_channels = value;
  return;
}
