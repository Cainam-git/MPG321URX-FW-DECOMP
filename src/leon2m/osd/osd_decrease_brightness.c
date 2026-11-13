/* osd_decrease_brightness  (FUN_a00a429c)
 *
 * Lower Brightness by 1 on its slider (left key) and apply it.
 * Note: Settings byte +9, range 0..100; redraws the slider.
 * Name basis: derived - handler table 0xA802422C: left on state 0x69 (Brightness slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a429c, flags -mcpu=v8 -O3 -g.
 * Source form: the test is on (unsigned char)(value - 1), so a value of 0 (which wraps to 255) takes the else
 * arm; the routine returns its first argument unchanged and the call results are not used.
 */
extern unsigned char osd_request_bits;
extern unsigned char user_settings[];
extern int osd_draw_brightness_slider(int);
extern int sys_user_apply_brightness(void);

#define brightness      user_settings[9]        /* the Brightness setting, settings byte +9 */
#define BRIGHTNESS_MAX  100
#define SLIDER_BEING_EDITED          1          /* argument of osd_draw_brightness_slider */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

/*
 * Left key on the Brightness slider (menu state 0x69): lower Brightness by 1, redraw the slider and apply the
 * value (sys_user_apply_brightness). A value of 0 (or one above 101) is set to 0 without a redraw.
 * The settings-changed request bit is set in every case.
 *
 * The first argument is returned unchanged; the second is not used.
 */
int osd_decrease_brightness(int first_arg, int unused)
{
    unsigned char value = brightness;
    
    if ((unsigned char)(value - 1) <= BRIGHTNESS_MAX) {
        value--;
        brightness = value;
        osd_draw_brightness_slider(SLIDER_BEING_EDITED);
        sys_user_apply_brightness();
    } else {
        brightness = 0;
    }
    
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    return first_arg;
}
