/* osd_decrease_quick_brightness  (FUN_a00a49b8)
 *
 * Lower Brightness by 1 in the Brightness quick menu (left key)
 * Note: Settings byte +9, min 0; redraws the bar and the number.
 * Name basis: derived - handler table 0xA802422C: left on state 0xFA (Navi Key quick menu 'Brightness')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a49b8 @ 0xa00a49b8, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the reset arm comes first ("if (new_value > 100)", the exact negation of the calls arm); with the calls arm
 *    first the compiler swaps two registers, as in osd_increase_red_gain;
 *  - the prototypes of osd_draw_slider_bar and osd_draw_value_number take unsigned char arguments (the callee
 *    re-masks them).
 */
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern void osd_draw_slider_bar(unsigned char, unsigned char, unsigned char, unsigned int);
extern void osd_draw_value_number(unsigned char, unsigned char, unsigned int);
extern void sys_user_apply_brightness(void);
extern void sys_user_save_mode_slot(void);

#define SETTING_BRIGHTNESS      9     /* byte offset in user_settings */
#define BRIGHTNESS_SLIDER_COLUMN 5
#define BRIGHTNESS_SLIDER_ROW    8
#define BRIGHTNESS_SLIDER_LENGTH 12   /* cells */
#define BRIGHTNESS_NUMBER_COLUMN 10
#define BRIGHTNESS_NUMBER_ROW    6
#define OSD_REQUEST_SETTINGS_CHANGED 0x02

/* Left key in the Brightness quick menu: lower Brightness by one, down to 0.
 * The byte is decremented first; a result above 100 means it wrapped from 0,
 * so the setting stays 0 and nothing is redrawn. Otherwise the new value is
 * stored, the slider and the number are redrawn and it is applied to the
 * panel. The mode slot is saved and the settings-changed request is raised in
 * both cases. */
void osd_decrease_quick_brightness(void)
{
    unsigned char new_value = user_settings[SETTING_BRIGHTNESS] - 1;
    if (new_value > 100) {
        user_settings[SETTING_BRIGHTNESS] = 0;
    } else {
        user_settings[SETTING_BRIGHTNESS] = new_value;
        osd_draw_slider_bar(BRIGHTNESS_SLIDER_COLUMN, BRIGHTNESS_SLIDER_ROW, new_value, BRIGHTNESS_SLIDER_LENGTH);
        osd_draw_value_number(BRIGHTNESS_NUMBER_COLUMN, BRIGHTNESS_NUMBER_ROW, user_settings[SETTING_BRIGHTNESS]);
        sys_user_apply_brightness();
    }
    sys_user_save_mode_slot();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
