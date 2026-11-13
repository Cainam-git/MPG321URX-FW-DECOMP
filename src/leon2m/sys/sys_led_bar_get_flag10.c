/* sys_led_bar_get_flag10  (FUN_a00daad4)
 *
 * Return flag bit 10 of the LED light bar state.
 * Returns: 0 or 1
 * Name basis: descriptive - halfword at 0xA802D00C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00daad4 @ 0xa00daad4, flags -mcpu=v8 -O2 -g.
 */
extern unsigned short _DAT_a802d00c;

/* Return bit 10 of the halfword at 0xA802D00C (a halfword whose low byte sys_led_bar_get_status_code writes). Called from osd_check_panel_protect_prompt. */
unsigned short sys_led_bar_get_flag10(void)
{
  return _DAT_a802d00c >> 10 & 1;
}
