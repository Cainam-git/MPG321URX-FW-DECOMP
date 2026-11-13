/* osd_enter_professional_items  (FUN_a0091cc0)
 *
 * Enter the Professional tab's list at its first enabled item (OK or right key)
 * Note: Item states 0x15..0x17 (Pro Mode, Low Blue Light, Image Enhancement).
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x188634
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091cc0, flags -mcpu=v8 -O3 -g.
 * Source form: 'for (;;) { if (call == 1) break; ... }' gives the firmware's rotated loop ('while (call != 1)' gives other
 * code).
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_PROFESSIONAL      2
#define PAGE_PROFESSIONAL_ITEMS    0x15       /* menu state of the first item of the Professional tab */
#define PRO_ITEM_COUNT             3
#define PRO_ITEM_LOW_BLUE_LIGHT 1       /* the item with a switch */
extern unsigned int osd_menu_state;
extern void osd_highlight_item_row(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_tab(unsigned char, int);
extern void osd_draw_professional_item_state(int, int);

/*
 * Open the item list of the Professional tab from the tab row: the tab gets the "parent" highlight, the menu
 * state becomes the first item that osd_is_item_enabled accepts (stepping forward, wrapping after the last),
 * and that item's row is highlighted. For the Low Blue Light item (item 1) the switch state is drawn too.
 */
void osd_enter_professional_items(void)
{
  int next_item;

  osd_highlight_tab(osd_menu_state - MENU_STATE_TAB_BASE, TAB_STYLE_PARENT);
  osd_menu_state = PAGE_PROFESSIONAL_ITEMS;
  for (;;) {
    if (osd_is_item_enabled(osd_menu_state - PAGE_PROFESSIONAL_ITEMS) == 1)
      break;
    next_item = (unsigned short)osd_menu_state - (PAGE_PROFESSIONAL_ITEMS - 1);
    next_item = next_item % PRO_ITEM_COUNT;
    osd_menu_state = next_item + PAGE_PROFESSIONAL_ITEMS;
  }
  osd_highlight_item_row(osd_menu_state - PAGE_PROFESSIONAL_ITEMS, 1);
  if (osd_menu_state == PAGE_PROFESSIONAL_ITEMS + PRO_ITEM_LOW_BLUE_LIGHT)
    osd_draw_professional_item_state(1, 0);
}
