/* osd_cancel_static_screen_start_time  (FUN_a009a37c)
 *
 * Restore the 'Starting in' time saved on entry and go back (left)
 * Note: Writes 0xA8025C55 back into settings byte +0x1E0.
 * Name basis: derived - handler table 0xA802422C: left on state 0xF4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009a37c @ 0xa009a37c, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is addressed through a local base pointer (the firmware loads the record base
 * into one register and uses [base + 0x1e0]).
 */
extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_item_choices(unsigned int, unsigned int);
extern void osd_highlight_choice_row(unsigned int, unsigned int);

#define USER_SETTINGS_BASE       0xa802d290 /* the user settings record */
#define USER_SETTINGS_STATIC_SCREEN_START_TIME 0x1e0 /* the Static Screen Detection start time */
#define PAGE_OLED_CARE_ITEMS     0x34   /* first item state of the MSI OLED Care page */
#define OLED_CARE_ITEM_STATIC_SCREEN 3  /* item index of Static Screen Detection in that page */
#define MENU_STATE_STATIC_START_TIME 0xbd /* the Starting in row of the Static Screen Detection choices */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * Left key in the Starting in list (menu state 0xF4): put back the value saved on entry and go back to the
 * Static Screen Detection choices.
 *
 * The highlight of the row of the value now stored is removed, settings byte +0x1E0 gets the value saved in
 * osd_edit_value, the choice column of Static Screen Detection is drawn again (osd_draw_item_choices), the menu
 * state returns to 0xBD and its row (row 2) is highlighted. osd_edit_value is cleared.
 */
void osd_cancel_static_screen_start_time(void)
{
    unsigned char *base = (unsigned char *)USER_SETTINGS_BASE;
    osd_clear_choice_highlight(base[USER_SETTINGS_STATIC_SCREEN_START_TIME]);
    base[USER_SETTINGS_STATIC_SCREEN_START_TIME] = osd_edit_value;
    osd_draw_item_choices(PAGE_OLED_CARE_ITEMS, OLED_CARE_ITEM_STATIC_SCREEN);
    osd_menu_state = MENU_STATE_STATIC_START_TIME;
    osd_highlight_choice_row(2, CHOICE_ROW_EDGED);
    osd_edit_value = 0;
}
