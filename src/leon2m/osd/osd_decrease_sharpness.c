/* osd_decrease_sharpness  (FUN_a00a43f4)
 *
 * Lower Sharpness by 1 on its slider (left key) and apply it.
 * Note: Settings byte +0x49, range 0..5; redraws the slider.
 * Name basis: derived - handler table 0xA802422C: left on state 0x6B (Sharpness slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a43f4, flags -mcpu=v8 -O3 -g.
 * Source form: the new value is an unsigned byte local; the routine returns its first argument unchanged and the
 * call results are not used.
 */
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern int osd_draw_sharpness_slider(int);
extern int pq_user_apply_sharpness(void);

#define sharpness user_settings[0x49]    /* Sharpness, settings byte +0x49 */
#define SHARPNESS_MAX 5
#define SLIDER_BEING_EDITED          1          /* argument of osd_draw_sharpness_slider */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

/*
 * Left key on the Sharpness slider (menu state 0x6B): lower Sharpness by 1, redraw the slider and apply the value
 * (pq_user_apply_sharpness). At 0 (the byte wraps to 255 and fails the range test) the value is set to 0 without a
 * redraw.
 * The settings-changed request bit is set in every case.
 *
 * The first argument is returned unchanged; the second is not used.
 */
int osd_decrease_sharpness(int first_arg, int unused)
{
    unsigned char new_value = sharpness - 1;
    
    if (new_value <= SHARPNESS_MAX) {
        sharpness = new_value;
        osd_draw_sharpness_slider(SLIDER_BEING_EDITED);
        pq_user_apply_sharpness();
    } else {
        sharpness = 0;
    }
    
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    return first_arg;
}
