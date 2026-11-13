/* osd_accept_static_screen_start_time  (FUN_a009a324)
 *
 * Keep the chosen 'Starting in' time, apply it and go back (OK)
 * Note: Value = settings byte +0x1E0; applies with oled_user_apply_screen_saver_range; returns to state 0xBD.
 * Name basis: derived - handler table 0xA802422C: OK on state 0xF4 (Static Screen Detection rows via
 *   osd_get_oled_care_text: texts 0x18B94C)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a324 @ 0xa009a324, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char osd_edit_value;
extern unsigned char osd_request_bits;
extern unsigned char user_settings_static_screen_start_time;
extern unsigned int osd_menu_state;

extern int osd_clear_choice_highlight(unsigned char);
extern void osd_draw_item_choices(int, int);
extern void osd_highlight_choice_row(int, int);
extern void oled_user_apply_screen_saver_range(void);

#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page */
#define OLED_CARE_ITEM_STATIC_SCREEN 3  /* item index of Static Screen Detection in that page */
#define MENU_STATE_STATIC_START_TIME 0xbd /* the Starting in row of the Static Screen Detection choices */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK in the Starting in list (menu state 0xF4): keep the value in settings byte +0x1E0 and go back to the
 * Static Screen Detection choices.
 *
 * The highlight of the value's row is removed, the choice column of Static Screen Detection is drawn again
 * (osd_draw_item_choices), the menu state returns to 0xBD and its row (row 2) is highlighted. osd_edit_value is
 * cleared, the value is applied (oled_user_apply_screen_saver_range) and a settings change is reported.
 */
void osd_accept_static_screen_start_time(void)
{
    osd_clear_choice_highlight(user_settings_static_screen_start_time);
    osd_draw_item_choices(PAGE_OLED_CARE_ITEMS, OLED_CARE_ITEM_STATIC_SCREEN);
    osd_menu_state = MENU_STATE_STATIC_START_TIME;
    osd_highlight_choice_row(2, CHOICE_ROW_EDGED);
    osd_edit_value = 0;
    oled_user_apply_screen_saver_range();
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
