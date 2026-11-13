/* osd_open_rgb_brightness_slider  (FUN_a0099b18)
 *
 * Open the RGB Brightness slider of the light bar.
 * Note: Menu state 0xF0; value = settings byte +0xAC, saved in 0xA8025C55.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0xB3 = 'RGB Brightness'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099b18 @ 0xa0099b18, flags -mcpu=v8 -O3 -g.
 * Source form: the callee declarations have no parameter list, so the six incoming argument registers are
 * passed on to osd_highlight_choice_row (it is called last, in the tail position). The RGB Brightness level is
 * the byte at 0xA802D33C, declared as a byte of its own.
 */
extern unsigned char osd_edit_value;
extern unsigned char user_settings_settings_page_flags;
extern unsigned int osd_menu_state;
extern int osd_clear_choice_highlight();
extern int osd_highlight_choice_row();
extern int osd_draw_rgb_brightness_levels();

#define MENU_STATE_RGB_BRIGHTNESS_SLIDER 0xf0 /* the RGB Brightness level is being edited */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on RGB Brightness in the RGB LED list (state 0xB3): open the RGB Brightness levels.
 *
 * The highlight of the cursor row (state - 0xB1, written as state + 0x4F in the byte argument) is removed and the
 * five level texts are drawn. The level now stored (the byte at 0xA802D33C, the first byte of settings word
 * +0xAC) is saved in osd_edit_value for the left key, the menu state becomes 0xF0 and the level's row is
 * highlighted with edge glyphs.
 *
 * The six argument registers of the caller are handed on unchanged to osd_highlight_choice_row.
 */
void osd_open_rgb_brightness_slider(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_clear_choice_highlight(osd_menu_state + 0x4fU & 0xff);
  osd_draw_rgb_brightness_levels();
  osd_edit_value = user_settings_settings_page_flags;
  osd_menu_state = MENU_STATE_RGB_BRIGHTNESS_SLIDER;
  osd_highlight_choice_row(user_settings_settings_page_flags, CHOICE_ROW_EDGED, arg3, arg4, arg5, arg6);
  return;
}
