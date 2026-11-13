/* osd_select_prev_pip_item  (FUN_a009cb0c)
 *
 * Move to the previous allowed PIP settings item (up key)
 * Note: Wraps inside the states 0x7A..0x7E; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: up on states 0x7A..0x7E; texts 0x1828C0 Source .. Audio
 *   Switch
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009cb0c @ 0xa009cb0c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is one expression, ((u16)state - (BASE - (COUNT - 1))) % COUNT, in an int.
 */

#define MENU_STATE_PIP_LIST    122             /* + item row: the five PIP items (Source .. Audio Switch) */
#define PIP_ITEM_COUNT          5
#define CHOICE_ROW_EDGED        1               /* highlight style of a choice row */

extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * Up key on the PIP items: move the highlight to the previous item, wrapping from the first item to the last.
 * Items that osd_is_choice_enabled rejects are skipped.
 */
void osd_select_prev_pip_item(void)
{
    int item;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_PIP_LIST);
    do {
        item = ((unsigned short)osd_menu_state - (MENU_STATE_PIP_LIST - (PIP_ITEM_COUNT - 1))) % PIP_ITEM_COUNT;
        osd_menu_state = item + MENU_STATE_PIP_LIST;
    } while (osd_is_choice_enabled(item) != 1);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_PIP_LIST, CHOICE_ROW_EDGED);
}
