/* osd_accept_color_temp  (FUN_a00964fc)
 *
 * Keep the highlighted colour temperature (Cool, Normal, Warm) and go back (OK)
 * Note: Returns to state 0x1B.
 * Name basis: derived - handler table 0xA802422C: OK on states 0x6C..0x6E; texts 0x18DB28: Cool, Normal, Warm,
 *   Customization
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00964fc @ 0xa00964fc (-mcpu=v8 -O3 -g)
 * Source form: the decompiler's two-parameter prototype is kept (the return value is the first parameter
 * unchanged). The result of osd_highlight_choice_row is passed to pq_user_apply_color_settings as its argument,
 * and the callees are declared without parameter lists.
 */
extern unsigned char osd_choice_row;
extern unsigned char osd_request_bits;
extern unsigned char osd_list_id;
extern unsigned char user_settings_color_temperature;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark();
extern int osd_highlight_item_row();
extern int osd_clear_choice_highlight();
extern int osd_highlight_choice_row();
extern int pq_user_apply_color_settings();

#define MENU_STATE_COLOR_TEMP_ITEM   0x1b       /* Image page, item Color Temperature (item row 3) */
#define MENU_STATE_COLOR_TEMP_LIST   0x6c       /* + choice: the Color Temperature list (states 0x6C..0x6F) */
#define COLOR_TEMP_ITEM_ROW          3          /* item row of the Color Temperature item */
#define LIST_ID_IMAGE_ITEMS          3          /* value of osd_list_id after leaving the list */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits: event 0x80 */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_MARK_OFF              0
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */

/*
 * OK in the Color Temperature list (menu states 0x6C..0x6F): store the highlighted choice and return to the item.
 *
 * The highlight and mark of the row saved on entry (osd_choice_row) are removed and the row of the present state
 * (state minus 0x6C) is highlighted. That choice is written to the Color Temperature setting and the colour
 * settings are applied. The new choice is marked, the menu state returns to the Color Temperature item with its
 * row highlighted, osd_list_id becomes 3 and the settings-changed request bit is set.
 *
 * param_2 is not used. The routine returns param_1 unchanged.
 */
unsigned int osd_accept_color_temp(unsigned int param_1,unsigned int param_2)
{
  osd_clear_choice_highlight(osd_choice_row);
  osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_OFF);
  unsigned int highlight_result = osd_highlight_choice_row((osd_menu_state - MENU_STATE_COLOR_TEMP_LIST) & 0xff, CHOICE_ROW_PLAIN);
  user_settings_color_temperature = (unsigned char)(osd_menu_state - MENU_STATE_COLOR_TEMP_LIST);
  pq_user_apply_color_settings(highlight_result);
  osd_draw_choice_mark(CHOICE_MARK_LIST, (osd_menu_state - MENU_STATE_COLOR_TEMP_LIST) & 0xff, CHOICE_MARK_ON);
  osd_menu_state = MENU_STATE_COLOR_TEMP_ITEM;
  osd_highlight_item_row(COLOR_TEMP_ITEM_ROW, HIGHLIGHT_ITEM_ACTIVE);
  osd_list_id = LIST_ID_IMAGE_ITEMS;
  osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
  return param_1;
}
