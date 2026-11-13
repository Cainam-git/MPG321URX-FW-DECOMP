/* osd_select_next_input_source_item  (FUN_a0092444)
 *
 * Move the highlight to the next selectable input (down key)
 * Note: Marks the entry that is the current input.
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x196DC0 (tab 'Input Source')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092444, flags -mcpu=v8 -O3 -g.
 * Twin of osd_select_prev_input_source_item (only the loop constant differs).
 * Source form: an if/else of two tail calls (a '!=' argument gives one call); an 'unsigned int' local for the
 * current item gives the firmware's 'cmp' operand order. The halfword read is '(unsigned short)osd_menu_state'.
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

extern unsigned char user_settings_input_source;
extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_input_item_state(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void osd_api_set_window_enable(int, int, int);

/*
 * Move the highlight of the Input Source tab to the next item that osd_is_item_enabled accepts (wrapping
 * after the last). Window 6 of the menu layer is set with 0 when that item is the one of the current input source
 * (input_api_source_id_to_menu_index of the setting), else with 1.
 */
void osd_select_next_input_source_item(void)
{
  int next_item;

  osd_clear_item_highlight(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS);
  osd_draw_input_item_state(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS, 0);
  do {
    next_item = (unsigned short)osd_menu_state - (PAGE_INPUT_SOURCE_ITEMS - 1);
    next_item = next_item % INPUT_SOURCE_ITEM_COUNT;
    osd_menu_state = next_item + PAGE_INPUT_SOURCE_ITEMS;
  } while (osd_is_item_enabled(next_item) != 1);
  osd_highlight_item_row(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS, 1);
  osd_draw_input_item_state(osd_menu_state - PAGE_INPUT_SOURCE_ITEMS, 1);
  {
    unsigned int item = osd_menu_state - PAGE_INPUT_SOURCE_ITEMS;
    unsigned int current_item = input_api_source_id_to_menu_index(user_settings_input_source);
    if (item == current_item)
      osd_api_set_window_enable(6, 0, 0);
    else
      osd_api_set_window_enable(6, 1, 0);
  }
}
