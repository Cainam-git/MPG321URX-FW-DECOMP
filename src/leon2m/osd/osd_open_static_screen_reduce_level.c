/* osd_open_static_screen_reduce_level  (FUN_a009a3cc)
 *
 * Open the Static Screen Detection 'Reducing Level' choice with its notice.
 * Note: State 0xF5; level = settings byte +0x1DF; also draws the notice that the effect depends on
 *   Brightness/HDR.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0xBF = 'Reducing Level' (Static Screen
 *   Detection rows via osd_get_oled_care_text: texts 0x18B94C); notice texts 0x183CB4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a3cc @ 0xa009a3cc-0xa009a424 (22 words), flags -mcpu=v8 -O3 -g.
 * osd_clear_choice_column is called with no argument set; osd_draw_static_screen_level_slider takes ONE argument
 * (only the first argument register is set before the call). The last call is a tail call.
 */
extern unsigned char osd_edit_value;
extern unsigned char user_settings_static_screen_level;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_column(void);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(int, int);
extern void osd_draw_choice_notes(unsigned char, unsigned char);
extern void osd_draw_static_screen_level_slider(unsigned char);

#define MENU_STATE_STATIC_REDUCE_LEVEL 0xbf /* the Reducing Level row of the Static Screen Detection choices */
#define MENU_STATE_STATIC_REDUCE_LEVEL_SLIDER 0xf5 /* the Reducing Level slider is open */
#define SLIDER_BEING_EDITED      1      /* argument of the slider draw routine: highlight as being edited */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on Reducing Level (state 0xBF) in the Static Screen Detection choices: open the Reducing Level
 * slider on the level now stored (settings byte +0x1DF).
 *
 * The level is saved in osd_edit_value for the left key. The highlight of the cursor row (state - 0xBB, written
 * as state + 0x45 in the byte argument) is removed, the choice column is cleared and the slider is drawn as being
 * edited. The menu state becomes 0xF5, row 0 is highlighted with edge glyphs and the notes of state 0xBF are
 * drawn (osd_draw_choice_notes).
 */
void osd_open_static_screen_reduce_level(void)
{
  osd_edit_value = user_settings_static_screen_level;
  osd_clear_choice_highlight(osd_menu_state + 0x45);
  osd_clear_choice_column();
  osd_draw_static_screen_level_slider(SLIDER_BEING_EDITED);
  osd_menu_state = MENU_STATE_STATIC_REDUCE_LEVEL_SLIDER;
  osd_highlight_choice_row(0, CHOICE_ROW_EDGED);
  osd_draw_choice_notes(MENU_STATE_STATIC_REDUCE_LEVEL, 0);
}
