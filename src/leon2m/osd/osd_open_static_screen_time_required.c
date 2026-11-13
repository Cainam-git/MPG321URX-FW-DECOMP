/* osd_open_static_screen_time_required  (FUN_a009a500)
 *
 * Open the Static Screen Detection 'Time required' choice.
 * Note: State 0xF6; value = settings byte +0x1E1, saved in 0xA8025C55.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0xBE = 'Time required' (Static Screen
 *   Detection rows via osd_get_oled_care_text: texts 0x18B94C); choices 0x18A7EC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a500 @ 0xa009a500, flags -mcpu=v8 -O3 -g.
 * Source form: the callee declarations have no parameter list, so the six incoming argument registers are
 * passed on to the second osd_highlight_choice_row call (the last call, in the tail position).
 */
extern unsigned char osd_edit_value;
extern unsigned char user_settings_static_screen_time_required;
extern unsigned int osd_menu_state;
extern int osd_clear_choice_highlight();
extern int osd_highlight_choice_row();
extern int osd_draw_oled_care_choices();

#define MENU_STATE_STATIC_TIME_REQUIRED 0xbe /* the Time required row of the Static Screen Detection choices */
#define MENU_STATE_STATIC_TIME_REQUIRED_LIST 0xf6 /* the Time required list is open */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on Time required (state 0xBE) in the Static Screen Detection choices: open the Time required
 * choices on the value now stored (settings byte +0x1E1).
 *
 * The value is saved in osd_edit_value for the left key. The highlight of the cursor row (state - 0xBB, written
 * as state + 0x45 in the byte argument) is removed and the choices of state 0xBE are drawn
 * (osd_draw_oled_care_choices). The menu state becomes 0xF6 and the value's row is highlighted, first plain and
 * then with edge glyphs.
 *
 * The six argument registers of the caller are handed on unchanged to the second osd_highlight_choice_row call.
 */
void osd_open_static_screen_time_required(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_edit_value = user_settings_static_screen_time_required;
  osd_clear_choice_highlight(osd_menu_state + 0x45U & 0xff);
  osd_draw_oled_care_choices(MENU_STATE_STATIC_TIME_REQUIRED);
  osd_menu_state = MENU_STATE_STATIC_TIME_REQUIRED_LIST;
  osd_highlight_choice_row(osd_edit_value, CHOICE_ROW_PLAIN);
  osd_highlight_choice_row(osd_edit_value, CHOICE_ROW_EDGED, arg3, arg4, arg5, arg6);
  return;
}
