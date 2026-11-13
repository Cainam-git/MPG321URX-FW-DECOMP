/* osd_select_next_pip_pbp_item  (FUN_a00927e8)
 *
 * Move the highlight to the next enabled PIP/PBP layout (down key)
 * Note: Wraps inside the states 0x23..0x25.
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x196DC0 (tab 'PIP/PBP')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00927e8, flags -mcpu=v8 -O3 -g.
 * Source form: do/while loop with the new item in a local int (the firmware computes it from the low halfword of
 * the state word); the two conditions on the highlighted item are tested separately, as in the firmware.
 */
#define MENU_STATE_TAB_BASE    2        /* menu state of a tab row = 2 + tab number */
#define PAGE_PIP_PBP_ITEMS     0x23     /* menu state of the first item of the PIP/PBP tab */
#define PIP_PBP_ITEM_COUNT     3
#define KEY_TEXT_MOVE          0        /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER         1
#define KEY_TEXT_SELECT        4

extern unsigned int osd_menu_state;
extern unsigned char osd_choice_row;
extern void osd_clear_item_highlight(unsigned char);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_item_choices(int, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void osd_draw_choice_mark(int, unsigned char, int);

/*
 * Down key in the PIP/PBP item list: move the highlight to the next item that osd_is_item_enabled accepts,
 * stepping forward through the three items and wrapping after the last. The menu state is the item's state
 * (PAGE_PIP_PBP_ITEMS + item). Then redraw the item's choices, the key guide, window 6 and the choice mark; the
 * item that is stored in osd_choice_row gets different window 6 and mark arguments from the others.
 */
void osd_select_next_pip_pbp_item(void)
{
    int item;

    osd_clear_item_highlight(osd_menu_state - PAGE_PIP_PBP_ITEMS);
    do {
        item = ((unsigned short)osd_menu_state - (PAGE_PIP_PBP_ITEMS - 1)) % PIP_PBP_ITEM_COUNT;
        osd_menu_state = item + PAGE_PIP_PBP_ITEMS;
    } while (osd_is_item_enabled(item) != 1);
    osd_highlight_item_row(osd_menu_state - PAGE_PIP_PBP_ITEMS, 1);
    if (osd_menu_state - PAGE_PIP_PBP_ITEMS == osd_choice_row)
        osd_api_set_window_enable(6, 0, 0);
    else
        osd_api_set_window_enable(6, 1, 0);
    osd_draw_item_choices(PAGE_PIP_PBP_ITEMS, osd_menu_state - PAGE_PIP_PBP_ITEMS);
    /* The first item shows the key texts Move/Select, the others Move/Enter. */
    if (osd_menu_state == PAGE_PIP_PBP_ITEMS) {
        osd_draw_key_guide(1, 3);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SELECT);
    } else {
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    }
    if (osd_menu_state - PAGE_PIP_PBP_ITEMS == osd_choice_row)
        osd_draw_choice_mark(0, osd_choice_row, 0);
    else
        osd_draw_choice_mark(0, osd_choice_row, 1);
}
