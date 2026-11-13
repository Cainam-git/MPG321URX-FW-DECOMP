/* osd_select_prev_pbp_source  (FUN_a009ae04)
 *
 * Move to the previous allowed PBP source input (up key)
 * Note: Wraps inside the states 0xD4..0xD7; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: up on states 0xD4..0xD7; same code as
 *   osd_select_next_pip_source with base 0xD4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009ae04 @ 0xa009ae04, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk back is (u16)state - BASE + (COUNT - 1) taken modulo the count in a second statement;
 *  - the translation routines are declared unsigned-char-returning here, and the translated row is compared inside
 *    the if.
 */

#define CHOICE_MARK_LIST        1       /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON          1
#define CHOICE_MARK_OFF         0
#define CHOICE_ROW_EDGED        1       /* highlight style of a choice row */

#define MENU_STATE_PBP_SOURCE_LIST  0xd4        /* + row: the four inputs of the PBP source list */
#define PBP_SOURCE_COUNT            4

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);

/*
 * Up key in the PBP source list: move the highlight to the previous row, wrapping from the first row to the
 * last. Rows that osd_is_choice_enabled rejects are skipped. Same as osd_select_prev_pip_source with the list
 * at 0xD4.
 *
 * The highlighted row is translated with input_api_menu_index_to_source_id and compared with the input saved on
 * entry (osd_edit_value). The mark is drawn at the row of that saved input (input_api_source_id_to_menu_index); it
 * is switched off while the highlight is on the saved input and on otherwise.
 */
void osd_select_prev_pbp_source(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_PBP_SOURCE_LIST);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_PBP_SOURCE_LIST + (PBP_SOURCE_COUNT - 1);
        row = row % PBP_SOURCE_COUNT;
        osd_menu_state = row + MENU_STATE_PBP_SOURCE_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_PBP_SOURCE_LIST, CHOICE_ROW_EDGED);
    if (input_api_menu_index_to_source_id(osd_menu_state - MENU_STATE_PBP_SOURCE_LIST) == osd_edit_value)
        osd_draw_choice_mark(CHOICE_MARK_LIST, input_api_source_id_to_menu_index(osd_edit_value), CHOICE_MARK_OFF);
    else
        osd_draw_choice_mark(CHOICE_MARK_LIST, input_api_source_id_to_menu_index(osd_edit_value), CHOICE_MARK_ON);
}
