/* osd_enter_settings_items  (FUN_a0092b18)
 *
 * Enter the Settings tab's list at its first enabled item (OK or right key)
 * Note: Item states 0x2A..0x33 (Language .. Reset).
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x1874F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092b18, flags -mcpu=v8 -O3 -g.
 * Source form: 'for (;;) { if (call == 1) break; ... }' gives the firmware's rotated loop; the new item is
 * computed in two statements (the remainder is a signed % 10).
 */
#define MENU_STATE_TAB_BASE    2        /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_PARENT       2        /* osd_highlight_tab: the tab whose item list is open */
#define PAGE_SETTINGS_ITEMS    0x2a     /* menu state of the first item of the Settings tab */
#define SETTINGS_ITEM_COUNT    10       /* Language .. Reset */

extern unsigned int osd_menu_state;
extern void osd_highlight_item_row(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_tab(unsigned char, int);

/*
 * Open the item list of the Settings tab from the tab row: the tab gets the "parent" highlight, the menu state
 * becomes the first item that osd_is_item_enabled accepts (stepping forward, wrapping after the last) and that
 * item's row is highlighted.
 */
void osd_enter_settings_items(void)
{
  int next_item;

  osd_highlight_tab(osd_menu_state - MENU_STATE_TAB_BASE, TAB_STYLE_PARENT);
  osd_menu_state = PAGE_SETTINGS_ITEMS;
  for (;;) {
    if (osd_is_item_enabled(osd_menu_state - PAGE_SETTINGS_ITEMS) == 1)
      break;
    next_item = (unsigned short)osd_menu_state - (PAGE_SETTINGS_ITEMS - 1);
    next_item = next_item % SETTINGS_ITEM_COUNT;
    osd_menu_state = next_item + PAGE_SETTINGS_ITEMS;
  }
  osd_highlight_item_row(osd_menu_state - PAGE_SETTINGS_ITEMS, 1);
}
