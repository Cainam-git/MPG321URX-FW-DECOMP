/* sys_is_logo_hold  (FUN_a0082c4c)
 *
 * Return bit 0 of 0xA802AF41 (logo shown, events held)
 * Returns: 0 or 1
 * Name basis: derived - bit set by osd_show_logo_on_power_on (show logo), cleared by sys_release_logo_hold,
 *   blocks sys_app_generate_events
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0082c4c @ 0xa0082c4c, flags -mcpu=v8 -O2 -g (section default).
 * Returns app_flags & 1 as an unsigned char.
 */
extern unsigned char app_flags;

#define APP_FLAG_LOGO_HOLD 0x01         /* app_flags bit 0 */

/*
 * Return bit 0 of app_flags (1 or 0): the logo is shown and events are held.
 * osd_show_logo_on_power_on sets the bit; sys_release_logo_hold clears it; sys_app_generate_events skips its work
 * while it is set.
 */
unsigned char sys_is_logo_hold(void)
{
  return app_flags & APP_FLAG_LOGO_HOLD;
}
