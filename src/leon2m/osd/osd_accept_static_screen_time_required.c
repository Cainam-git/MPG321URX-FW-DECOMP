/* osd_accept_static_screen_time_required  (FUN_a009a554)
 *
 * Keep the chosen 'Time required', apply it and go back (OK)
 * Note: Applies with oled_user_apply_screen_saver_range; returns to state 0xBE.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xF6
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a554 @ 0xa009a554, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char osd_edit_value;
extern unsigned char osd_request_bits;
extern unsigned char user_settings_static_screen_time_required;
extern unsigned int osd_menu_state;
extern int osd_clear_choice_highlight();
extern void osd_highlight_choice_row();
extern void osd_draw_item_choices();
extern void oled_user_apply_screen_saver_range(void);

#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page */
#define OLED_CARE_ITEM_STATIC_SCREEN 3  /* item index of Static Screen Detection in that page */
#define MENU_STATE_STATIC_TIME_REQUIRED 0xbe /* the Time required row of the Static Screen Detection choices */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK in the Time required list (menu state 0xF6): keep the value in settings byte +0x1E1 and go back to the
 * Static Screen Detection choices.
 *
 * The highlight of the value's row is removed, the choice column of Static Screen Detection is drawn again
 * (osd_draw_item_choices), the menu state returns to 0xBE and its row (row 3) is highlighted with edge glyphs.
 * osd_edit_value is cleared, the value is applied (oled_user_apply_screen_saver_range) and a settings change is
 * reported.
 */
void osd_accept_static_screen_time_required(void)
{
    osd_clear_choice_highlight(user_settings_static_screen_time_required);
    osd_draw_item_choices(PAGE_OLED_CARE_ITEMS, OLED_CARE_ITEM_STATIC_SCREEN);
    osd_menu_state = MENU_STATE_STATIC_TIME_REQUIRED;
    osd_highlight_choice_row(3, CHOICE_ROW_EDGED);
    osd_edit_value = 0;
    oled_user_apply_screen_saver_range();
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
