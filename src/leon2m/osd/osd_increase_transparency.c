/* osd_increase_transparency  (FUN_a00a4448)
 *
 * Raise menu Transparency by 1 on its slider (right key) and apply it.
 * Note: Settings byte +0xF, range 0..5; redraws the slider.
 * Name basis: derived - handler table 0xA802422C: right on state 0xAF (menu Transparency slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a4448, flags -mcpu=v8 -O3 -g.
 * Source form: the new value is an unsigned byte local; the routine returns its first argument unchanged and the
 * call results are not used.
 */
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern int osd_draw_transparency_slider(int);
extern int osd_user_apply_transparency(void);

#define transparency user_settings[0xf]    /* menu Transparency, settings byte +0xf */
#define TRANSPARENCY_MAX 5
#define SLIDER_BEING_EDITED          1          /* argument of osd_draw_transparency_slider */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

/*
 * Right key on the menu Transparency slider (menu state 0xAF): raise menu Transparency by 1, redraw the slider and
 * apply the value (osd_user_apply_transparency). At the top of the range (5) the value stays there and nothing is
 * redrawn or applied.
 * The settings-changed request bit is set in every case.
 *
 * The first argument is returned unchanged; the second is not used.
 */
int osd_increase_transparency(int first_arg, int unused)
{
    unsigned char new_value = transparency + 1;
    
    if (new_value <= TRANSPARENCY_MAX) {
        transparency = new_value;
        osd_draw_transparency_slider(SLIDER_BEING_EDITED);
        osd_user_apply_transparency();
    } else {
        transparency = TRANSPARENCY_MAX;
    }
    
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    return first_arg;
}
