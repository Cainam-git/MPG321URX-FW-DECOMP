/* osd_enter_gi_items  (FUN_a0091668)
 *
 * Enter the G.I. tab's list (KVM, Smart Crosshair, Optix Scope) at its first enabled item.
 * Note: Item states 0x0B..0x0D.
 * Name basis: proven - sets state 0x0B, skips items osd_is_item_enabled rejects; osd_leave_gi_items returns to
 *   state 2; labels from ROM table 0x18A360; key role from the menu state handler table 0xA802422C, tab texts
 *   0x196DC0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091668, flags -mcpu=v8 -O3 -g.
 * Source form: 'for (;;) { if (call == 1) break; ... }' gives the firmware's rotated loop ('while (call != 1)' gives other
 * code).
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_GI                0
#define PAGE_GI_ITEMS              0x0b       /* menu state of the first item of the G.I. tab */
#define GI_ITEM_COUNT              3

extern unsigned int osd_menu_state;
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_default_key_guide(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_tab(unsigned char, int);

/*
 * Open the item list of the G.I. tab from the tab row: the tab gets the "parent" highlight, the menu state
 * becomes the first item that osd_is_item_enabled accepts (stepping forward, wrapping after the last), and that
 * item's row is highlighted with the default key guide.
 */
void osd_enter_gi_items(void)
{
  int next_item;

  osd_highlight_tab(osd_menu_state - MENU_STATE_TAB_BASE, TAB_STYLE_PARENT);
  osd_menu_state = PAGE_GI_ITEMS;
  for (;;) {
    if (osd_is_item_enabled(osd_menu_state - PAGE_GI_ITEMS) == 1)
      break;
    next_item = (unsigned short)osd_menu_state - (PAGE_GI_ITEMS - 1);
    next_item = next_item % GI_ITEM_COUNT;
    osd_menu_state = next_item + PAGE_GI_ITEMS;
  }
  osd_highlight_item_row(osd_menu_state - PAGE_GI_ITEMS, 1);
  osd_draw_default_key_guide(osd_menu_state - PAGE_GI_ITEMS, 1);
}
