/* osd_enter_pip_pbp_items  (FUN_a0092524)
 *
 * Enter the PIP/PBP list with the current layout highlighted (OK or right key)
 * Note: Item states 0x23..0x25; the current layout is settings byte +0x1F (0xA802D2AF), saved in 0xA8025C56.
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x196DC0 (tab 'PIP/PBP')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092524, flags -mcpu=v8 -O3 -g.
 * Source form: test-first loop. All settings bytes are read through the array base user_settings.
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_PIP_PBP           5
#define PAGE_PIP_PBP_ITEMS         0x23       /* menu state of the first item of the PIP/PBP tab */
#define PIP_PBP_ITEM_COUNT         3

/* Offsets of the user settings bytes used here. */
#define SETTINGS_RESPONSE_TIME  0x19
#define SETTINGS_PIP_PBP_MODE   0x1f
#define SETTINGS_BYTE_0X8F      0x8f
#define SETTINGS_SCREEN_SIZE    0x1a4

extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern unsigned char osd_edit_value;
extern unsigned char osd_choice_row;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void osd_highlight_tab(unsigned char, int);
extern void osd_api_set_window_enable(int, int, int);

/*
 * Open the item list of the PIP/PBP tab from the tab row. osd_edit_value gets the screen size setting and
 * osd_choice_row the PIP/PBP mode; when the mode is 0, settings byte +0x8F is set from the response time byte
 * (+0x19). The tab gets the "parent" highlight. The menu state starts at the item of the current mode, then
 * becomes the first item from there that osd_is_item_enabled accepts (stepping forward, wrapping after the
 * last). The mode's choice mark is drawn, the item's row is highlighted and window 6 is set with 0. The key
 * guide is Move, Select for item 0 and Move, Enter for the others.
 */
void osd_enter_pip_pbp_items(void)
{
  int next_item;

  osd_edit_value = user_settings[SETTINGS_SCREEN_SIZE];
  osd_choice_row = user_settings[SETTINGS_PIP_PBP_MODE];
  if (user_settings[SETTINGS_PIP_PBP_MODE] == 0)
    user_settings[SETTINGS_BYTE_0X8F] = user_settings[SETTINGS_RESPONSE_TIME];
  osd_highlight_tab(osd_menu_state - MENU_STATE_TAB_BASE, TAB_STYLE_PARENT);
  osd_menu_state = user_settings[SETTINGS_PIP_PBP_MODE] + PAGE_PIP_PBP_ITEMS;
  for (;;) {
    if (osd_is_item_enabled(osd_menu_state - PAGE_PIP_PBP_ITEMS) == 1)
      break;
    next_item = (unsigned short)osd_menu_state - (PAGE_PIP_PBP_ITEMS - 1);
    next_item = next_item % PIP_PBP_ITEM_COUNT;
    osd_menu_state = next_item + PAGE_PIP_PBP_ITEMS;
  }
  osd_draw_choice_mark(0, user_settings[SETTINGS_PIP_PBP_MODE], 0);
  osd_highlight_item_row(osd_menu_state - PAGE_PIP_PBP_ITEMS, 1);
  osd_api_set_window_enable(6, 0, 0);
  if (osd_menu_state == PAGE_PIP_PBP_ITEMS) {
    osd_draw_key_guide(1, 3);
    osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_SELECT);
  } else {
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
  }
}
