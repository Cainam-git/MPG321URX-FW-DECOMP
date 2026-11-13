/* osd_enter_gaming_items  (FUN_a00918f4)
 *
 * Enter the Gaming tab's list (Game Mode .. DSC) at its first enabled item.
 * Note: Item states 0x0E..0x14.
 * Name basis: proven - sets state 0x0E, skips items osd_is_item_enabled rejects; leaving returns to state 3
 *   (osd_leave_gaming_items); key role from the menu state handler table 0xA802422C, tab texts 0x196DC0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00918f4, flags -mcpu=v8 -O3 -g.
 * Source form: 'for (;;) { if (call == 1) break; ... }' gives the firmware's rotated loop ('while (call != 1)' gives other
 * code).
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
extern void osd_highlight_item_row(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_tab(unsigned char, int);
extern void osd_draw_item_choices(int, unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char user_settings_game_mode;

/*
 * Open the item list of the Gaming tab from the tab row: the tab gets the "parent" highlight, the menu state
 * becomes the first item that osd_is_item_enabled accepts (stepping forward, wrapping after the last), and that
 * item's row, its choice column and the row of the Game Mode setting in it are highlighted.
 */
void osd_enter_gaming_items(void)
{
  int next_item;

  osd_highlight_tab(osd_menu_state - MENU_STATE_TAB_BASE, TAB_STYLE_PARENT);
  osd_menu_state = PAGE_GAMING_ITEMS;
  for (;;) {
    if (osd_is_item_enabled(osd_menu_state - PAGE_GAMING_ITEMS) == 1)
      break;
    next_item = (unsigned short)osd_menu_state - (PAGE_GAMING_ITEMS - 1);
    next_item = next_item % GAMING_ITEM_COUNT;
    osd_menu_state = next_item + PAGE_GAMING_ITEMS;
  }
  osd_highlight_item_row(osd_menu_state - PAGE_GAMING_ITEMS, 1);
  osd_draw_item_choices(PAGE_GAMING_ITEMS, osd_menu_state - PAGE_GAMING_ITEMS);
  osd_highlight_choice_row(user_settings_game_mode, 0);
}
