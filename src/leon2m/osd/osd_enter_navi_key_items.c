/* osd_enter_navi_key_items  (FUN_a0092908)
 *
 * Enter the Navi Key tab's list at its first enabled item (OK or right key)
 * Note: Item states 0x26..0x29 (Up, Down, Left, Right).
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x19158C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092908, flags -mcpu=v8 -O3 -g.
 * Source form: 'for (;;) { if (call == 1) break; ... }' gives the firmware's rotated loop ('while (call != 1)'
 * gives other code); the new item is computed in two statements, as in the firmware.
 */
#define MENU_STATE_TAB_BASE    2        /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_PARENT       2        /* osd_highlight_tab: the tab whose item list is open */
#define PAGE_NAVI_KEY_ITEMS    0x26     /* menu state of the first item of the Navi Key tab */
#define NAVI_KEY_ITEM_COUNT    4        /* Up, Down, Left, Right */

extern unsigned int osd_menu_state;
extern void osd_highlight_item_row(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_tab(unsigned char, int);
extern unsigned char user_settings_byte_0x1a3;

/*
 * Open the item list of the Navi Key tab from the tab row: the tab gets the "parent" highlight, the menu state
 * becomes the first item that osd_is_item_enabled accepts (stepping forward, wrapping after the last) and that
 * item's row is highlighted. Settings byte +0x1A3, which the Navi Key list steps along with the item, is cleared.
 */
void osd_enter_navi_key_items(void)
{
  int next_item;

  osd_highlight_tab(osd_menu_state - MENU_STATE_TAB_BASE, TAB_STYLE_PARENT);
  osd_menu_state = PAGE_NAVI_KEY_ITEMS;
  for (;;) {
    if (osd_is_item_enabled(osd_menu_state - PAGE_NAVI_KEY_ITEMS) == 1)
      break;
    next_item = (unsigned short)osd_menu_state - (PAGE_NAVI_KEY_ITEMS - 1);
    next_item = next_item % NAVI_KEY_ITEM_COUNT;
    osd_menu_state = next_item + PAGE_NAVI_KEY_ITEMS;
  }
  osd_highlight_item_row(osd_menu_state - PAGE_NAVI_KEY_ITEMS, 1);
  user_settings_byte_0x1a3 = 0;
}
