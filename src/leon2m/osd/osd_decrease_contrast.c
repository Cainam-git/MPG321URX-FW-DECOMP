/* osd_decrease_contrast  (FUN_a00a4348)
 *
 * Lower Contrast by 1 on its slider (left key) and apply it.
 * Note: Settings byte +0xA, range 0..100; redraws the slider.
 * Name basis: derived - handler table 0xA802422C: left on state 0x6A (Contrast slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a4348, flags -mcpu=v8 -O3 -g.
 * Source form: the new value is computed first and tested as an unsigned byte, so a value of 0 (which wraps to
 * 255) takes the else arm; the routine returns its first argument unchanged and the call results are not used.
 */
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern int osd_draw_contrast_slider(int);
extern int pq_user_apply_color_gain(void);

#define contrast        user_settings[0xa]      /* the Contrast setting, settings byte +0xA */
#define CONTRAST_MAX    100
#define SLIDER_BEING_EDITED          1          /* argument of osd_draw_contrast_slider */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

/*
 * Left key on the Contrast slider (menu state 0x6A): lower Contrast by 1, redraw the slider and apply the
 * value (pq_user_apply_color_gain). A value of 0 (or one above 101) is set to 0 without a redraw.
 * The settings-changed request bit is set in every case.
 *
 * The first argument is returned unchanged; the second is not used.
 */
int osd_decrease_contrast(int first_arg, int unused)
{
    unsigned char new_value = contrast - 1;
    
    if (new_value <= CONTRAST_MAX) {
        contrast = new_value;
        osd_draw_contrast_slider(SLIDER_BEING_EDITED);
        pq_user_apply_color_gain();
    } else {
        contrast = 0;
    }
    
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    return first_arg;
}
