/* osd_cancel_static_screen_reduce_level  (FUN_a009a480)
 *
 * Restore the 'Reducing Level' saved on entry and go back.
 * Note: Nothing refers to it (the left key of state 0xF5 uses another routine).
 * Name basis: descriptive - writes 0xA8025C55 back into settings byte +0x1DF, returns to state 0xBF
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a480 @ 0xa009a480-0xa009a500 (32 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 */
extern unsigned char user_settings[];
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_item_choices(int, unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);

#define USER_SETTINGS_STATIC_SCREEN_LEVEL 0x1df /* the Static Screen Detection reduce level */
#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page */
#define OLED_CARE_ITEM_STATIC_SCREEN 3  /* item index of Static Screen Detection in that page */
#define MENU_STATE_STATIC_REDUCE_LEVEL 0xbf /* the Reducing Level row of the Static Screen Detection choices */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * Put back the Reducing Level saved on entry and go back to the Static Screen Detection choices. No routine
 * calls this one directly (it is reached through a table).
 *
 * The highlight of row (level modulo 7) is removed, settings byte +0x1DF gets the level saved in osd_edit_value,
 * the choice column of Static Screen Detection is drawn again (osd_draw_item_choices), the menu state returns
 * to 0xBF and its row (row 4) is highlighted with edge glyphs. osd_edit_value is cleared.
 */
void osd_cancel_static_screen_reduce_level(void)
{
    osd_clear_choice_highlight(user_settings[USER_SETTINGS_STATIC_SCREEN_LEVEL] % 7);
    user_settings[USER_SETTINGS_STATIC_SCREEN_LEVEL] = osd_edit_value;
    osd_draw_item_choices(PAGE_OLED_CARE_ITEMS, OLED_CARE_ITEM_STATIC_SCREEN);
    osd_menu_state = MENU_STATE_STATIC_REDUCE_LEVEL;
    osd_highlight_choice_row(4, CHOICE_ROW_EDGED);
    osd_edit_value = 0;
}
