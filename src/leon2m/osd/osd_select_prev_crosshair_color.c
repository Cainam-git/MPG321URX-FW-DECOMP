/* osd_select_prev_crosshair_color  (FUN_a009b434)
 *
 * Move to the previous allowed crosshair colour (up key)
 * Note: Wraps inside the states 0xED..0xEF; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: up on states 0xED..0xEF; texts 0x18E54C White, Red, Auto
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009b434 @ 0xa009b434, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - BASE + (COUNT - 1), taken modulo the count in a second statement;
 *  - the settings record is a byte array; osd_edit_value is copied into a block-scope local that is used for the
 *    compare and the mark row.
 */

#define CHOICE_MARK_LIST        1       /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON          1
#define CHOICE_MARK_OFF         0
#define CHOICE_ROW_EDGED        1       /* highlight style of a choice row */

#define MENU_STATE_CROSSHAIR_COLOR_LIST    0xed        /* + row: the 3 rows of the Smart Crosshair colour list */
#define CROSSHAIR_COLOR_COUNT    3
#define USER_SETTINGS_CROSSHAIR_COLOR    0x17b        /* the Smart Crosshair colour (user_settings_crosshair_color, 2 = automatic) */

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);

/*
 * Up key in the Smart Crosshair colour list: move the highlight to the previous row, wrapping from the first row to the last.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The row number is stored in the settings byte at +0x17b. The mark is drawn at the row of the value saved on
 * entry (osd_edit_value); it is switched off while the highlight is on that row and on otherwise.
 */
void osd_select_prev_crosshair_color(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_CROSSHAIR_COLOR_LIST);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_CROSSHAIR_COLOR_LIST + (CROSSHAIR_COLOR_COUNT - 1);
        row = row % CROSSHAIR_COLOR_COUNT;
        osd_menu_state = row + MENU_STATE_CROSSHAIR_COLOR_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    user_settings[USER_SETTINGS_CROSSHAIR_COLOR] = osd_menu_state - MENU_STATE_CROSSHAIR_COLOR_LIST;
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_CROSSHAIR_COLOR_LIST, CHOICE_ROW_EDGED);
    {
        unsigned char saved = osd_edit_value;
        if (osd_menu_state - MENU_STATE_CROSSHAIR_COLOR_LIST == saved)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
    }
}
