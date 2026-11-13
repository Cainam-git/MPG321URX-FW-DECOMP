/* osd_select_prev_static_screen_item  (FUN_a009df5c)
 *
 * Move to the previous allowed Static Screen Detection row (up key)
 * Note: Rows OFF, ON, Starting in, Time required, Reducing Level.
 * Name basis: derived - handler table 0xA802422C: up on states 0xBB..0xBF
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009df5c @ 0xa009df5c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - BASE + (COUNT - 1), taken modulo the count in a second statement;
 *  - osd_choice_row is copied into a block-scope local for the compare and the mark row;
 *  - user_settings and the two input_api_* routines are declared but not used here.
 */

#define MENU_STATE_STATIC_SCREEN_LIST   0xbb    /* + row: OFF, ON, Starting in, Time required, Reducing Level */
#define STATIC_SCREEN_COUNT             5
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

/*
 * Up key on the Static Screen Detection rows (OFF, ON, Starting in, Time required, Reducing Level): move the
 * highlight to the previous row, wrapping from the first row to the last. Rows that osd_is_choice_enabled rejects are skipped. Nothing is stored here.
 *
 * The mark is drawn at the row of osd_choice_row (the value saved on entry); it is switched off while the
 * highlight is on that row and on otherwise.
 */
void osd_select_prev_static_screen_item(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_STATIC_SCREEN_LIST);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_STATIC_SCREEN_LIST + (STATIC_SCREEN_COUNT - 1);
        row = row % STATIC_SCREEN_COUNT;
        osd_menu_state = row + MENU_STATE_STATIC_SCREEN_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_STATIC_SCREEN_LIST, CHOICE_ROW_EDGED);
    {
        unsigned char saved = osd_choice_row;
        if (osd_menu_state - MENU_STATE_STATIC_SCREEN_LIST == saved)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
    }
}
