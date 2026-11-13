/* osd_increase_static_screen_reduce_level  (FUN_a009e624)
 *
 * Raise the Static Screen 'Reducing Level' one step (max 6) and redraw.
 * Note: Settings byte +0x1DF; osd_draw_static_screen_level_slider redraws the slider.
 * Name basis: derived - handler table 0xA802422C: right on state 0xF5 (Reducing Level)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e624, flags -mcpu=v8 -O2 -g.
 * Source form: the level is reached as a byte of the settings array (reducing_level is a macro); the slider
 * redraw is the last call.
 */
extern unsigned char user_settings[];
extern void osd_draw_static_screen_level_slider(int);

#define reducing_level             user_settings[0x1df]     /* the Reducing Level of Static Screen Detection */
#define STATIC_SCREEN_LEVEL_MAX    6
#define SLIDER_BEING_EDITED        1                        /* argument of osd_draw_static_screen_level_slider */

/*
 * Right key on the Static Screen Detection Reducing Level slider (menu state 0xF5): raise the level by one (levels 0
 * to 6, no wrap) and redraw the slider. At the end of its range nothing happens.
 */
void osd_increase_static_screen_reduce_level(void)
{
    if (reducing_level < STATIC_SCREEN_LEVEL_MAX) {
        reducing_level++;
        osd_draw_static_screen_level_slider(SLIDER_BEING_EDITED);
    }
}
