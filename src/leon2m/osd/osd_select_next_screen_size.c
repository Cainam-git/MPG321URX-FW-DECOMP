/* osd_select_next_screen_size  (FUN_a009ca54)
 *
 * Move to the next allowed screen size (down key)
 * Note: Wraps inside the states 0x70..0x76; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: down on states 0x70..0x76; texts 0x1910B0 Auto .. 27"
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009ca54 @ 0xa009ca54, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - BASE + 1, taken modulo the count in a second statement;
 *  - osd_choice_row is copied into a block-scope local for the compare and the mark row;
 *  - the two input_api_* routines and user_settings are declared but not used here.
 */

#define MENU_STATE_SCREEN_SIZE_LIST 0x70        /* + row: Auto, 4:3, 16:9, 16:10, 1:1, 24.5", 27" */
#define SCREEN_SIZE_COUNT           7
#define CHOICE_MARK_LIST            1           /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON              1
#define CHOICE_MARK_OFF             0
#define CHOICE_ROW_EDGED            1           /* highlight style of a choice row */

extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void osd_draw_adaptive_sync_status(void);

/*
 * Down key in the Screen Size list: move the highlight to the next row, wrapping from the last row to the first.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The Screen Size itself is not written here. After the highlight moves, osd_draw_adaptive_sync_status is
 * called. The mark is drawn at the row of the size saved on entry (osd_choice_row); it is switched off while
 * the highlight is on that row and on otherwise.
 */
void osd_select_next_screen_size(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_SCREEN_SIZE_LIST);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_SCREEN_SIZE_LIST + 1;
        row = row % SCREEN_SIZE_COUNT;
        osd_menu_state = row + MENU_STATE_SCREEN_SIZE_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_SCREEN_SIZE_LIST, CHOICE_ROW_EDGED);
    osd_draw_adaptive_sync_status();
    {
        unsigned char saved = osd_choice_row;
        if (osd_menu_state - MENU_STATE_SCREEN_SIZE_LIST == saved)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
    }
}
