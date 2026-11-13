/* oled_user_apply_pixel_shift  (FUN_a00daae8)
 *
 * Apply the pixel shift on/off setting.
 * Name basis: proven - oled_set_pixel_shift_on_off with settings bit 29 of the word at +0x1DC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00daae8 @ 0xa00daae8, flags -mcpu=v8 -O2 -g (section default; -O3 -g and -Os -g give the same
 * bytes).
 */
extern unsigned int user_settings_oled_care_flags;     /* settings word +0x1DC: switches of the OLED Care menu */
extern int oled_set_pixel_shift_on_off();

#define OLED_CARE_PIXEL_SHIFT_BIT 29                    /* the Pixel Shift on/off switch */

/* Send the Pixel Shift on/off setting of the OLED Care menu to the OLED panel controller. */
void oled_user_apply_pixel_shift(void)
{
  oled_set_pixel_shift_on_off(user_settings_oled_care_flags >> OLED_CARE_PIXEL_SHIFT_BIT & 1);
  return;
}
