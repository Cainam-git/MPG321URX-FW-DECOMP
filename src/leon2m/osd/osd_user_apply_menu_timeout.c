/* osd_user_apply_menu_timeout  (FUN_a00d47b0)
 *
 * Apply the menu time-out setting.
 * Name basis: derived - settings byte +0x0C passed to osd_set_seconds_countdown
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d47b0 @ 0xa00d47b0 (-mcpu=v8 -O2 -g)
 */
extern unsigned char user_settings_osd_timeout;         /* settings byte +0xC: OSD Time out */
extern int osd_set_seconds_countdown();

/* Start the menu's one-second countdown from the OSD Time out setting. */
void osd_user_apply_menu_timeout(void)

{
  osd_set_seconds_countdown(user_settings_osd_timeout);
  return;
}
