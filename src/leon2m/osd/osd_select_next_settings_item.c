/* osd_select_next_settings_item  (FUN_a0092d80)
 *
 * Move the highlight to the next enabled Settings item (down key)
 * Note: The list scrolls in pages of 7 items.
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x1874F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092d80, flags -mcpu=v8 -O3 -g.
 * Source form: do/while loop; the page is kept in an unsigned char, as in the firmware.
 */
#define PAGE_SETTINGS_ITEMS    0x2a     /* menu state of the first item of the Settings tab */
#define SETTINGS_ITEM_COUNT    10       /* Language .. Reset */
#define SETTINGS_ITEMS_PER_PAGE 7       /* items shown at once; the later ones are on a second page */

extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_item_choices(int, unsigned char);
extern void osd_draw_settings_items(unsigned char);
extern void osd_draw_settings_item_state(unsigned char, int);

/*
 * Down key in the Settings item list: move the highlight to the next item that osd_is_item_enabled accepts
 * (wrapping after the last). The items are drawn in pages of seven; when the new item lies on another page than
 * the old one, that page is drawn. The switch state drawing moves with the highlight.
 */
void osd_select_next_settings_item(void)
{
    int item;
    unsigned char page;

    osd_clear_item_highlight(osd_menu_state - PAGE_SETTINGS_ITEMS);
    osd_draw_settings_item_state(osd_menu_state - PAGE_SETTINGS_ITEMS, 0);
    page = (osd_menu_state - PAGE_SETTINGS_ITEMS) / SETTINGS_ITEMS_PER_PAGE;
    do {
        item = ((unsigned short)osd_menu_state - (PAGE_SETTINGS_ITEMS - 1)) % SETTINGS_ITEM_COUNT;
        osd_menu_state = item + PAGE_SETTINGS_ITEMS;
    } while (osd_is_item_enabled(item) != 1);
    if ((osd_menu_state - PAGE_SETTINGS_ITEMS) / SETTINGS_ITEMS_PER_PAGE != page)
        osd_draw_settings_items((osd_menu_state - PAGE_SETTINGS_ITEMS) / SETTINGS_ITEMS_PER_PAGE);
    osd_highlight_item_row(osd_menu_state - PAGE_SETTINGS_ITEMS, 1);
    osd_draw_settings_item_state(osd_menu_state - PAGE_SETTINGS_ITEMS, 1);
    osd_draw_item_choices(PAGE_SETTINGS_ITEMS, osd_menu_state - PAGE_SETTINGS_ITEMS);
}
