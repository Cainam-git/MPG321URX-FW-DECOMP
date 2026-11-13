/* osd_cancel_static_screen_time_required  (FUN_a009a5ac)
 *
 * Restore the 'Time required' value saved on entry and go back (left)
 * Note: Writes 0xA8025C55 back into settings byte +0x1E1.
 * Name basis: derived - handler table 0xA802422C: left on state 0xF6
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a5ac @ 0xa009a5ac, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is declared as a byte array so that the compiler computes the base once and
 * uses [base + 0x1e1] for both the load and the store.
 */
extern unsigned char osd_edit_value;
extern unsigned char user_settings[];
extern unsigned int osd_menu_state;
extern int osd_clear_choice_highlight();
extern int osd_highlight_choice_row();
extern void osd_draw_item_choices();

#define USER_SETTINGS_STATIC_SCREEN_TIME_REQUIRED 0x1e1 /* the Static Screen Detection time required */
#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page */
#define OLED_CARE_ITEM_STATIC_SCREEN 3  /* item index of Static Screen Detection in that page */
#define MENU_STATE_STATIC_TIME_REQUIRED 0xbe /* the Time required row of the Static Screen Detection choices */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * Left key in the Time required list (menu state 0xF6): put back the value saved on entry and go back to the
 * Static Screen Detection choices.
 *
 * The highlight of the row of the value now stored is removed, settings byte +0x1E1 gets the value saved in
 * osd_edit_value, the choice column of Static Screen Detection is drawn again (osd_draw_item_choices), the menu
 * state returns to 0xBE and its row (row 3) is highlighted with edge glyphs. osd_edit_value is cleared.
 */
void osd_cancel_static_screen_time_required(void)
{
    osd_clear_choice_highlight(user_settings[USER_SETTINGS_STATIC_SCREEN_TIME_REQUIRED]);
    user_settings[USER_SETTINGS_STATIC_SCREEN_TIME_REQUIRED] = osd_edit_value;
    osd_draw_item_choices(PAGE_OLED_CARE_ITEMS, OLED_CARE_ITEM_STATIC_SCREEN);
    osd_menu_state = MENU_STATE_STATIC_TIME_REQUIRED;
    osd_highlight_choice_row(3, CHOICE_ROW_EDGED);
    osd_edit_value = 0;
}
