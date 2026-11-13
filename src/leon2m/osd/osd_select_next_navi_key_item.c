/* osd_select_next_navi_key_item  (FUN_a0092a80)
 *
 * Move the highlight to the next enabled Navi Key item (down key)
 * Note: Steps the row byte 0xA802D433 along with the state.
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x19158C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092a80, flags -mcpu=v8 -O3 -g.
 * Source form: do/while loop; the settings record is a plain byte array (user_settings[0x1a3]) and the byte is
 * stepped after the loop, as in the firmware.
 */
#define PAGE_NAVI_KEY_ITEMS    0x26     /* menu state of the first item of the Navi Key tab */
#define NAVI_KEY_ITEM_COUNT    4        /* Up, Down, Left, Right */

extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_clear_item_highlight(unsigned char);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_item_choices(int, unsigned char);

/*
 * Down key in the Navi Key item list: move the highlight to the next item that osd_is_item_enabled accepts
 * (wrapping after the last), step settings byte +0x1A3 forward by one in the same way (modulo 4), and redraw
 * the row highlight and the item's choices.
 */
void osd_select_next_navi_key_item(void)
{
    int item;

    osd_clear_item_highlight(osd_menu_state - PAGE_NAVI_KEY_ITEMS);
    do {
        item = ((unsigned short)osd_menu_state - (PAGE_NAVI_KEY_ITEMS - 1)) % NAVI_KEY_ITEM_COUNT;
        osd_menu_state = item + PAGE_NAVI_KEY_ITEMS;
    } while (osd_is_item_enabled(item) != 1);
    user_settings[0x1a3] = (user_settings[0x1a3] + 1) & (NAVI_KEY_ITEM_COUNT - 1);
    osd_highlight_item_row(osd_menu_state - PAGE_NAVI_KEY_ITEMS, 1);
    osd_draw_item_choices(PAGE_NAVI_KEY_ITEMS, osd_menu_state - PAGE_NAVI_KEY_ITEMS);
}
