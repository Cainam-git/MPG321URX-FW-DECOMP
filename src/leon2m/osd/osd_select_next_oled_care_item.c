/* osd_select_next_oled_care_item  (FUN_a0093144)
 *
 * Move the highlight to the next enabled MSI OLED Care item (down key)
 * Note: The list scrolls in pages of 7 items.
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x185E78
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0093144, flags -mcpu=v8 -O3 -g.
 * Source form: do/while loop; the page is kept in an unsigned char, as in the firmware.
 */
#define PAGE_OLED_CARE_ITEMS   0x34     /* menu state of the first item of the MSI OLED Care tab */
#define OLED_CARE_ITEM_COUNT   8        /* Pixel Shift .. OLED Panel Info. */
#define OLED_CARE_ITEMS_PER_PAGE 7      /* items shown at once; the later ones are on a second page */
#define MENU_STATE_PANEL_PROTECT_ITEM 0x35      /* OLED Care item 1 */
#define MENU_STATE_PANEL_INFO_ITEM    0x3b      /* OLED Care item 7: OLED Panel Info. */
#define KEY_TEXT_MOVE          0        /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER         1
#define KEY_TEXT_SELECT        4

extern unsigned int osd_menu_state;
extern unsigned char user_settings_key_guide_shown;
extern void osd_clear_item_highlight(unsigned char);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_item_choices(int, unsigned char);
extern void osd_draw_oled_care_items(unsigned char);
extern void osd_draw_adjust_key_guide(void);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);

/*
 * Down key in the MSI OLED Care item list: move the highlight to the next item that osd_is_item_enabled accepts
 * (wrapping after the last). The items are drawn in pages of seven; when the new item lies on another page,
 * osd_draw_oled_care_items is called with 1 - old page. Then the choices of the item and the key guide are
 * drawn: item 1 and OLED Panel Info. each get their own guide, every other item gets the adjust key guide
 * (settings byte +0x189 set to 0xFF so that osd_update_key_guide redraws both texts).
 */
void osd_select_next_oled_care_item(void)
{
    int item;
    unsigned char page;

    osd_clear_item_highlight(osd_menu_state - PAGE_OLED_CARE_ITEMS);
    page = (osd_menu_state - PAGE_OLED_CARE_ITEMS) / OLED_CARE_ITEMS_PER_PAGE;
    do {
        item = ((unsigned short)osd_menu_state - (PAGE_OLED_CARE_ITEMS - 1)) % OLED_CARE_ITEM_COUNT;
        osd_menu_state = item + PAGE_OLED_CARE_ITEMS;
    } while (osd_is_item_enabled(item) != 1);
    if (page != (osd_menu_state - PAGE_OLED_CARE_ITEMS) / OLED_CARE_ITEMS_PER_PAGE)
        osd_draw_oled_care_items(1 - page);
    osd_highlight_item_row(osd_menu_state - PAGE_OLED_CARE_ITEMS, 1);
    osd_draw_item_choices(PAGE_OLED_CARE_ITEMS, osd_menu_state - PAGE_OLED_CARE_ITEMS);
    if (osd_menu_state == MENU_STATE_PANEL_PROTECT_ITEM) {
        osd_draw_key_guide(1, 3);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SELECT);
    } else if (osd_menu_state == MENU_STATE_PANEL_INFO_ITEM) {
        osd_draw_key_guide(1, 6);
    } else {
        user_settings_key_guide_shown = 0xff;
        osd_draw_adjust_key_guide();
        osd_draw_key_guide(1, 2);
        osd_draw_key_guide(2, 5);
        osd_draw_key_guide(0, 0);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    }
}
