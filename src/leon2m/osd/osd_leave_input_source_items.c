/* osd_leave_input_source_items  (FUN_a00922f0)
 *
 * Leave the Input Source list and return the highlight to its tab (left key)
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x196DC0 (tab 'Input Source')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00922f0, flags -mcpu=v8 -O3 -g.
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

extern unsigned char user_settings_input_source;      /* 0xa802d2ae */
extern unsigned int osd_menu_state;      /* 0xa802afec */
extern int osd_clear_item_highlight(int);           /* 0xa00a8ee8 */
extern void osd_highlight_item_row(int, int);     /* 0xa00a900c */
extern int osd_draw_key_guide(int, int);      /* 0xa00a9468 */
extern void osd_draw_input_item_state(int, int);     /* 0xa00aa01c */
extern int osd_update_key_guide(int, int);      /* 0xa00b34d4 */
extern void osd_highlight_tab(int, int);     /* 0xa00b4144 */
extern int input_api_source_id_to_menu_index(unsigned char); /* 0xa01445fc */

/*
 * Leave the item list of the Input Source tab: the highlighted item is drawn back in normal colours, osd_highlight_item_row is called with 0 for the
 * item of the current input source, the menu state becomes the Input Source tab row and
 * the cursor goes back to the tab. Returns the result of osd_update_key_guide.
 */
int osd_leave_input_source_items(void)
{
  osd_clear_item_highlight((osd_menu_state - PAGE_INPUT_SOURCE_ITEMS) & 0xff);
  osd_draw_input_item_state((osd_menu_state - PAGE_INPUT_SOURCE_ITEMS) & 0xff, 0);
  osd_highlight_item_row(input_api_source_id_to_menu_index(user_settings_input_source) & 0xff, 0);
  osd_menu_state = MENU_STATE_TAB_BASE + TAB_INPUT_SOURCE;
  osd_highlight_tab(TAB_INPUT_SOURCE, TAB_STYLE_CURSOR);
  osd_draw_key_guide(1, 2);
  return osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
}
