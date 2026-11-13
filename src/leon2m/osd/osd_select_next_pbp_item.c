/* osd_select_next_pbp_item  (FUN_a009ccc0)
 *
 * Move to the next allowed PBP settings item (down key)
 * Name basis: derived - handler table 0xA802422C: down on states 0x7F..0x85
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009ccc0 @ 0xa009ccc0, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - BASE + 1, taken modulo the count in a second statement;
 *  - osd_saved_choice_value is copied into a block-scope local for the compare and the mark row;
 *  - user_settings and the two input_api_* routines are declared but not used here.
 */

#define MENU_STATE_PBP_LIST    0x7f            /* + item row: the seven PBP items */
#define PBP_ITEM_COUNT          7
#define CHOICE_MARK_LIST        1               /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON          1
#define CHOICE_MARK_OFF         0
#define CHOICE_ROW_EDGED        1               /* highlight style of a choice row */

extern unsigned char osd_saved_choice_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);

/*
 * Down key on the PBP items: move the highlight to the next item, wrapping from the last item to the first.
 * Items that osd_is_choice_enabled rejects are skipped.
 *
 * The mark is drawn at the row of osd_saved_choice_value (the value saved when the list was entered); it is
 * switched off while the highlight is on that row and on otherwise.
 */
void osd_select_next_pbp_item(void)
{
    int item;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_PBP_LIST);
    do {
        item = (unsigned short)osd_menu_state - MENU_STATE_PBP_LIST + 1;
        item = item % PBP_ITEM_COUNT;
        osd_menu_state = item + MENU_STATE_PBP_LIST;
    } while (osd_is_choice_enabled(item) != 1);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_PBP_LIST, CHOICE_ROW_EDGED);
    {
        unsigned char saved = osd_saved_choice_value;
        if (osd_menu_state - MENU_STATE_PBP_LIST == saved)
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
        else
            osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
    }
}
