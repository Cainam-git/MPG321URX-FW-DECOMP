/* osd_select_prev_image_item  (FUN_a00920f4)
 *
 * Move the highlight to the previous enabled Image item (up key)
 * Note: Wraps inside the states 0x18..0x1D (Brightness .. DisplayHDR).
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x18CA88
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00920f4, flags -mcpu=v8 -O3 -g.
 * Source form: the firmware reads the halfword with 'lduh [%i1 + 0x3ee]' on the same sethi as the word load
 * 'ld [%i1 + 0x3ec]'; that is '(unsigned short)osd_menu_state' (combine narrows the word load to a halfword load
 * at +2 and keeps the lo_sum on the word's HIGH). A separate extern for the halfword gets its own sethi; a union
 * or struct member or a pointer cast gives 'or %lo' + [reg+2].
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_IMAGE             3
#define PAGE_IMAGE_ITEMS           0x18       /* menu state of the first item of the Image tab */
#define IMAGE_ITEM_COUNT           6

extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_item_choices(int, unsigned char);

/*
 * Move the highlight of the Image tab to the previous item that osd_is_item_enabled accepts (wrapping before
 * the first) and draw its choice column.
 */
void osd_select_prev_image_item(void)
{
    int item;

    osd_clear_item_highlight(osd_menu_state - PAGE_IMAGE_ITEMS);
    do {
        item = ((unsigned short)osd_menu_state - (PAGE_IMAGE_ITEMS + 1 - IMAGE_ITEM_COUNT)) % IMAGE_ITEM_COUNT;
        osd_menu_state = item + PAGE_IMAGE_ITEMS;
    } while (osd_is_item_enabled(item) != 1);
    osd_highlight_item_row(osd_menu_state - PAGE_IMAGE_ITEMS, 1);
    osd_draw_item_choices(PAGE_IMAGE_ITEMS, osd_menu_state - PAGE_IMAGE_ITEMS);
}
