/* osd_increase_brightness  (FUN_a00a4244)
 *
 * Raise Brightness by 1 on its slider (right key) and apply it.
 * Note: Settings byte +9, range 0..100; redraws the slider.
 * Name basis: derived - handler table 0xA802422C: right on state 0x69 (Brightness slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a4244, flags -mcpu=v8 -O3 -g.
 * Source form: declared void but ends in 'return 0;' (the firmware sets %o0 to 0); the call results are not used.
 */
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern int osd_draw_brightness_slider(int);
extern int sys_user_apply_brightness(void);

#define brightness      user_settings[9]        /* the Brightness setting, settings byte +9 */
#define BRIGHTNESS_MAX  100
#define SLIDER_BEING_EDITED          1          /* argument of osd_draw_brightness_slider */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

/*
 * Right key on the Brightness slider (menu state 0x69): raise Brightness by 1, redraw the slider and apply the
 * value (sys_user_apply_brightness). At 100 the value stays 100 and nothing is redrawn or applied.
 * The settings-changed request bit is set in every case.
 */
void osd_increase_brightness(void)
{
    unsigned char new_value = brightness + 1;

    if (new_value <= BRIGHTNESS_MAX) {
        brightness = new_value;
        osd_draw_brightness_slider(SLIDER_BEING_EDITED);
        sys_user_apply_brightness();
    } else {
        brightness = BRIGHTNESS_MAX;
    }

    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    return 0;
}
