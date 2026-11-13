/* oled_user_apply_screen_saver_range  (FUN_a00dab20)
 *
 * Apply the screen saver range setting.
 * Name basis: proven - oled_set_screen_saver_range
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dab20 @ 0xa00dab20, flags -mcpu=v8 -O2 -g (section default; -O3 -g and -Os -g give the same
 * bytes).
 */
extern int oled_set_screen_saver_range();

/*
 * Send the screen saver range setting to the OLED panel controller. The routine takes no value: the callee
 * writes the setting and reads it back itself.
 */
void oled_user_apply_screen_saver_range(void)
{
  oled_set_screen_saver_range();
  return;
}
