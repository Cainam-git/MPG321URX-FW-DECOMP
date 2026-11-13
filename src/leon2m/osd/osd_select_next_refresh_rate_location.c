/* osd_select_next_refresh_rate_location  (FUN_a009b20c)
 *
 * Move to the next allowed refresh rate display location (down key) and store it.
 * Note: Wraps inside the states 0xDD..0xE1; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: down on states 0xDD..0xE1; writes settings byte +0x13E;
 *   texts 0x18E9F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009b20c @ 0xa009b20c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - BASE + 1, taken modulo the count in a second statement;
 *  - the settings record is a byte array; osd_edit_value is copied into a block-scope local that is used for the
 *    compare and the mark row.
 */

#define CHOICE_MARK_LIST        1       /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON          1
#define CHOICE_MARK_OFF         0
#define CHOICE_ROW_EDGED        1       /* highlight style of a choice row */

#define MENU_STATE_REFRESH_RATE_LOCATION_LIST    0xdd        /* + row: the 5 rows of the Refresh Rate location list */
#define REFRESH_RATE_LOCATION_COUNT    5
#define USER_SETTINGS_REFRESH_RATE_LOCATION    0x13e        /* the location of the Refresh Rate overlay (user_settings_refresh_rate_location) */

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);

/*
 * Down key in the Refresh Rate location list: move the highlight to the next row, wrapping from the last row to the first.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The row number is stored in the settings byte at +0x13e. The mark is drawn at the row of the value saved on
 * entry (osd_edit_value); it is switched off while the highlight is on that row and on otherwise.
 */
void osd_select_next_refresh_rate_location(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_REFRESH_RATE_LOCATION_LIST);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_REFRESH_RATE_LOCATION_LIST + 1;
        row = row % REFRESH_RATE_LOCATION_COUNT;
        osd_menu_state = row + MENU_STATE_REFRESH_RATE_LOCATION_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    user_settings[USER_SETTINGS_REFRESH_RATE_LOCATION] = osd_menu_state - MENU_STATE_REFRESH_RATE_LOCATION_LIST;
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_REFRESH_RATE_LOCATION_LIST, CHOICE_ROW_EDGED);
    {
        unsigned char saved = osd_edit_value;
        if (osd_menu_state - MENU_STATE_REFRESH_RATE_LOCATION_LIST == saved)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
    }
}
