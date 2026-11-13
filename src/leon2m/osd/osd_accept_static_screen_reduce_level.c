/* osd_accept_static_screen_reduce_level  (FUN_a009a424)
 *
 * Keep the chosen 'Reducing Level', apply it and go back (OK)
 * Note: Applies with oled_user_apply_screen_saver_range; returns to state 0xBF.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xF5
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a424 @ 0xa009a424, flags -mcpu=v8 -O3 -g.
 * Source form: the routine has two parameters and returns the first one as an int (the other half of the 64-bit
 * value built from the two parameters is dropped by the conversion); the callees are declared without parameter
 * lists.
 */
extern unsigned char osd_edit_value;
extern unsigned char osd_request_bits;
extern unsigned int osd_menu_state;
extern int osd_clear_choice_highlight();
extern void osd_highlight_choice_row();
extern void osd_draw_item_choices();
extern int osd_draw_static_screen_level_slider();
extern void oled_user_apply_screen_saver_range();

#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page */
#define OLED_CARE_ITEM_STATIC_SCREEN 3  /* item index of Static Screen Detection in that page */
#define MENU_STATE_STATIC_REDUCE_LEVEL 0xbf /* the Reducing Level row of the Static Screen Detection choices */
#define SLIDER_NOT_EDITED        0      /* argument of the slider draw routine: not being edited */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK on the Reducing Level slider (menu state 0xF5): keep the level in settings byte +0x1DF and go back to the
 * Static Screen Detection choices.
 *
 * The highlight of row 0 is removed, the slider is redrawn as not being edited and the choice column of Static
 * Screen Detection is drawn again (osd_draw_item_choices). The menu state returns to 0xBF and its row (row 4) is
 * highlighted with edge glyphs. osd_edit_value is cleared, the level is applied
 * (oled_user_apply_screen_saver_range) and a settings change is reported. The first parameter is returned.
 */
int osd_accept_static_screen_reduce_level(unsigned int first_arg, unsigned int second_arg)

{
  osd_clear_choice_highlight(0);
  osd_draw_static_screen_level_slider(SLIDER_NOT_EDITED);
  osd_draw_item_choices(PAGE_OLED_CARE_ITEMS, OLED_CARE_ITEM_STATIC_SCREEN);
  osd_menu_state = MENU_STATE_STATIC_REDUCE_LEVEL;
  osd_highlight_choice_row(4, CHOICE_ROW_EDGED);
  osd_edit_value = 0;
  oled_user_apply_screen_saver_range();
  osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
  return first_arg;
}
