/* osd_enter_input_source_items  (FUN_a009221c)
 *
 * Enter the Input Source list with the current input highlighted (OK or right key)
 * Note: Item states 0x1E..0x22; the current input is settings byte +0x1E (0xA802D2AE).
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x196DC0 (tab 'Input Source')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009221c, flags -mcpu=v8 -O3 -g.
 * Same loop as osd_enter_pip_pbp_items.
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_INPUT_SOURCE      4
#define PAGE_INPUT_SOURCE_ITEMS    0x1e       /* menu state of the first item of the Input Source tab */
#define INPUT_SOURCE_ITEM_COUNT    5

extern unsigned int osd_menu_state;
extern unsigned char user_settings_input_source;
extern void osd_highlight_item_row(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_highlight_tab(unsigned char, int);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);

/*
 * Open the item list of the Input Source tab from the tab row: the tab gets the "parent" highlight. The menu
 * state starts at the item that input_api_source_id_to_menu_index gives for the current input source, then
 * becomes the first item from there that osd_is_item_enabled accepts (stepping forward, wrapping after the
 * last). That item's row is highlighted, window 6 of the menu layer is set with 0, and the key guide is drawn
 * (Move, Select).
 */
void osd_enter_input_source_items(void)
{
  int next_item;

  osd_highlight_tab(osd_menu_state - MENU_STATE_TAB_BASE, TAB_STYLE_PARENT);
  osd_menu_state = input_api_source_id_to_menu_index(user_settings_input_source) + PAGE_INPUT_SOURCE_ITEMS;
  for (;;) {
    if (osd_is_item_enabled(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS) == 1)
      break;
    next_item = (unsigned short)osd_menu_state - (PAGE_INPUT_SOURCE_ITEMS - 1);
    next_item = next_item % INPUT_SOURCE_ITEM_COUNT;
    osd_menu_state = next_item + PAGE_INPUT_SOURCE_ITEMS;
  }
  osd_highlight_item_row(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS, 1);
  osd_api_set_window_enable(6, 0, 0);
  osd_draw_key_guide(1, 3);
  osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SELECT);
}
