/* oled_user_apply_pixel_shift_speed  (FUN_a00dab08)
 *
 * Apply the pixel shift speed setting.
 * Name basis: proven - oled_set_pixel_shift_speed with the settings byte
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dab08 @ 0xa00dab08, flags -mcpu=v8 -O2 -g (section default; -O3 -g and -Os -g give the same
 * bytes).
 */
extern unsigned char user_settings_pixel_shift;        /* settings byte +0x1DD: the Pixel Shift speed */
extern int oled_set_pixel_shift_speed();

/* Send the Pixel Shift speed setting to the OLED panel controller (written and read back there). */
void oled_user_apply_pixel_shift_speed(void)
{
  oled_set_pixel_shift_speed(user_settings_pixel_shift);
  return;
}
