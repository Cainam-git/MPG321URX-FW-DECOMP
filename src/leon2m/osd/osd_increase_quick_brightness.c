/* osd_increase_quick_brightness  (FUN_a00a493c)
 *
 * Raise Brightness by 1 in the Brightness quick menu (right key)
 * Note: Settings byte +9, max 100; redraws the bar and the number.
 * Name basis: derived - handler table 0xA802422C: right on state 0xFA (Navi Key quick menu 'Brightness')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a493c @ 0xa00a493c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the clamp arm comes first in the source (with the increment arm first the compiler swaps two registers, as in
 *    osd_increase_red_gain);
 *  - the new value is computed once in a byte (new_value) and the settings byte is incremented again in the other
 *    arm; the stored byte is re-read for the number.
 */
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern void osd_draw_slider_bar(int, int, unsigned char, int);
extern void osd_draw_value_number(int, int, unsigned char);
extern void sys_user_save_mode_slot(void);
extern void sys_user_apply_brightness(void);

#define SETTING_BRIGHTNESS      9     /* byte offset in user_settings */
#define BRIGHTNESS_MAX          100
#define BRIGHTNESS_SLIDER_COLUMN 5
#define BRIGHTNESS_SLIDER_ROW    8
#define BRIGHTNESS_SLIDER_LENGTH 12   /* cells */
#define BRIGHTNESS_NUMBER_COLUMN 10
#define BRIGHTNESS_NUMBER_ROW    6
#define OSD_REQUEST_SETTINGS_CHANGED 0x02

/* Right key in the Brightness quick menu: raise Brightness by one, up to 100.
 * Below the limit the new value is applied to the panel and the slider and the
 * number are redrawn; at the limit nothing is redrawn. The mode slot is saved
 * and the settings-changed request is raised in both cases. */
void osd_increase_quick_brightness(void)
{
  unsigned char new_value = user_settings[SETTING_BRIGHTNESS] + 1;

  if (new_value > BRIGHTNESS_MAX)
    user_settings[SETTING_BRIGHTNESS] = BRIGHTNESS_MAX;
  else {
    user_settings[SETTING_BRIGHTNESS] = user_settings[SETTING_BRIGHTNESS] + 1;
    osd_draw_slider_bar(BRIGHTNESS_SLIDER_COLUMN, BRIGHTNESS_SLIDER_ROW, new_value, BRIGHTNESS_SLIDER_LENGTH);
    osd_draw_value_number(BRIGHTNESS_NUMBER_COLUMN, BRIGHTNESS_NUMBER_ROW, user_settings[SETTING_BRIGHTNESS]);
    sys_user_apply_brightness();
  }
  sys_user_save_mode_slot();
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
