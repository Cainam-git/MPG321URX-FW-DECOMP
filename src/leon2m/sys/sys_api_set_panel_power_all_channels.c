/* sys_api_set_panel_power_all_channels  (FUN_a0145348)
 *
 * Store whether every channel (1) or only channel 0 (0) drives the panel power.
 * Name basis: derived - stores stSysConfig byte +0x2E, which GlobalModeHandler tests before its panel power
 *   phase; called from UserSetPIPMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145348 @ 0xa0145348 (-mcpu=v8 -O2 -g)
 * Source form: explicit return at the end of the body.
 */
extern unsigned char sys_config_panel_power_all_channels;

/* Store value in the configuration byte at 0xA802E3fe (+0x2E of the configuration). */
void sys_api_set_panel_power_all_channels(unsigned char value)

{
  sys_config_panel_power_all_channels = value;
  return;
}
