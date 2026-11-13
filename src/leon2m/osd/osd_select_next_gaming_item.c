/* osd_select_next_gaming_item  (FUN_a0091b94)
 *
 * Move the highlight to the next enabled Gaming item (down key)
 * Note: Wraps inside the states 0x0E..0x14 (Game Mode .. DSC).
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x188DA0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091b94, flags -mcpu=v8 -O3 -g.
 * The halfword read is '(unsigned short)osd_menu_state'.
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_GAMING            1
#define PAGE_GAMING_ITEMS          0x0e       /* menu state of the first item of the Gaming tab */
#define GAMING_ITEM_COUNT          7

extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_item_choices(int, unsigned char);
extern void osd_draw_gaming_items(unsigned char, int);
extern void osd_draw_gaming_item_state(unsigned char, int);

/*
 * Move the highlight of the Gaming tab to the next item that osd_is_item_enabled accepts (wrapping after the last).
 * The items are drawn in pages of GAMING_ITEM_COUNT; when the page changes it is drawn again. The new item's
 * switch state and choice column are drawn.
 */
void osd_select_next_gaming_item(void)
{
    int item;
    unsigned char page;

    osd_clear_item_highlight(osd_menu_state - PAGE_GAMING_ITEMS);
    osd_draw_gaming_item_state(osd_menu_state - PAGE_GAMING_ITEMS, 0);
    page = (osd_menu_state - PAGE_GAMING_ITEMS) / GAMING_ITEM_COUNT;
    do {
        item = ((unsigned short)osd_menu_state - (PAGE_GAMING_ITEMS - 1)) % GAMING_ITEM_COUNT;
        osd_menu_state = item + PAGE_GAMING_ITEMS;
    } while (osd_is_item_enabled(item) != 1);
    if (page != (osd_menu_state - PAGE_GAMING_ITEMS) / GAMING_ITEM_COUNT)
        osd_draw_gaming_items((osd_menu_state - PAGE_GAMING_ITEMS) / GAMING_ITEM_COUNT, 1);
    osd_highlight_item_row(osd_menu_state - PAGE_GAMING_ITEMS, 1);
    osd_draw_gaming_item_state(osd_menu_state - PAGE_GAMING_ITEMS, 1);
    osd_draw_item_choices(PAGE_GAMING_ITEMS, osd_menu_state - PAGE_GAMING_ITEMS);
}
