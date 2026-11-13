/* osd_select_prev_alarm_clock_location  (FUN_a009b2c4)
 *
 * Move to the previous allowed alarm clock location (up key) and store it.
 * Note: Wraps inside the states 0xE2..0xE6; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: up on states 0xE2..0xE6; writes settings byte +0x13F; texts
 *   0x18E9F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009b2c4 @ 0xa009b2c4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - BASE + (COUNT - 1), taken modulo the count in a second statement;
 *  - the settings record is a byte array; osd_edit_value is copied into a block-scope local that is used for the
 *    compare and the mark row.
 */

#define CHOICE_MARK_LIST        1       /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON          1
#define CHOICE_MARK_OFF         0
#define CHOICE_ROW_EDGED        1       /* highlight style of a choice row */

#define MENU_STATE_ALARM_LOCATION_LIST    0xe2        /* + row: the 5 rows of the Alarm Clock location list */
#define ALARM_LOCATION_COUNT    5
#define USER_SETTINGS_ALARM_CLOCK_LOCATION    0x13f        /* the location of the Alarm Clock overlay (user_settings_alarm_clock_location) */

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);

/*
 * Up key in the Alarm Clock location list: move the highlight to the previous row, wrapping from the first row to the last.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The row number is stored in the settings byte at +0x13f. The mark is drawn at the row of the value saved on
 * entry (osd_edit_value); it is switched off while the highlight is on that row and on otherwise.
 */
void osd_select_prev_alarm_clock_location(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_ALARM_LOCATION_LIST);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_ALARM_LOCATION_LIST + (ALARM_LOCATION_COUNT - 1);
        row = row % ALARM_LOCATION_COUNT;
        osd_menu_state = row + MENU_STATE_ALARM_LOCATION_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    user_settings[USER_SETTINGS_ALARM_CLOCK_LOCATION] = osd_menu_state - MENU_STATE_ALARM_LOCATION_LIST;
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_ALARM_LOCATION_LIST, CHOICE_ROW_EDGED);
    {
        unsigned char saved = osd_edit_value;
        if (osd_menu_state - MENU_STATE_ALARM_LOCATION_LIST == saved)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
    }
}
