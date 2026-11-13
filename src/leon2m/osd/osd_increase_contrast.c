/* osd_increase_contrast  (FUN_a00a42f0)
 *
 * Raise Contrast by 1 on its slider (right key) and apply it.
 * Note: Settings byte +0xA, range 0..100; redraws the slider.
 * Name basis: derived - handler table 0xA802422C: right on state 0x6A (Contrast slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a42f0, flags -mcpu=v8 -O3 -g.
 * Source form: declared void but ends in 'return 1;' (the firmware sets %o0 to 1 before the branch, so it is
 * returned in both cases); the call results are not used.
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
 * Right key on the Contrast slider (menu state 0x6A): raise Contrast by 1, redraw the slider and apply the
 * value (pq_user_apply_color_gain). At 100 the value stays 100 and nothing is redrawn or applied.
 * The settings-changed request bit is set in every case.
 */
void osd_increase_contrast(void)
{
    unsigned char new_value = contrast + 1;
    
    if (new_value <= CONTRAST_MAX) {
        contrast = new_value;
        osd_draw_contrast_slider(SLIDER_BEING_EDITED);
        pq_user_apply_color_gain();
    } else {
        contrast = CONTRAST_MAX;
    }
    
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    return 1;
}
