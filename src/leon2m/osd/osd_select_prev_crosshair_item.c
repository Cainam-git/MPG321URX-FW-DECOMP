/* osd_select_prev_crosshair_item  (FUN_a009bedc)
 *
 * Move to the previous allowed Smart Crosshair item (up key)
 * Note: Wraps inside the states 0x3F..0x42; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: up on states 0x3F..0x42; texts 0x18F984 Icon, Color,
 *   Position, Reset
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009bedc @ 0xa009bedc, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - (BASE - (COUNT - 1)), taken modulo the count in a second statement.
 */

#define MENU_STATE_CROSSHAIR_ITEMS  0x3f        /* + item row: Icon, Color, Position, Reset */
#define CROSSHAIR_ITEM_COUNT        4
#define CHOICE_ROW_EDGED            1           /* highlight style of a choice row */

extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * Up key on the Smart Crosshair items (Icon, Color, Position, Reset): move the highlight to the previous item, wrapping from the first item to the last.
 * Items that osd_is_choice_enabled rejects are skipped.
 */
void osd_select_prev_crosshair_item(void)
{
    int item;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_CROSSHAIR_ITEMS);
    do {
        item = (unsigned short)osd_menu_state - (MENU_STATE_CROSSHAIR_ITEMS - (CROSSHAIR_ITEM_COUNT - 1));
        item = item % CROSSHAIR_ITEM_COUNT;
        osd_menu_state = item + MENU_STATE_CROSSHAIR_ITEMS;
    } while (osd_is_choice_enabled(item) != 1);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_CROSSHAIR_ITEMS, CHOICE_ROW_EDGED);
}
