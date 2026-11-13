/* osd_cancel_color_temp  (FUN_a0096598)
 *
 * Restore the colour temperature saved on entry, re-apply it and go back (left)
 * Note: Copies 0xA8025C56 back into settings byte +0x11 and re-applies the colour gains
 *   (pq_user_apply_color_settings).
 * Name basis: derived - handler table 0xA802422C: left on states 0x6C..0x6F
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096598 @ 0xa0096598-0xa0096610 (30 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is reached through a struct pointer and the Color Temperature byte is read
 * again for every use. The callees are declared with byte parameters.
 */

/* The field of the user settings record used here. */
struct user_settings_record {
  unsigned char pad0[0x11];
  unsigned char color_temperature;              /* +0x11: Color Temperature */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned char osd_list_id;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void pq_user_apply_color_settings(void);

#define MENU_STATE_COLOR_TEMP_ITEM   0x1b       /* Image page, item Color Temperature (item row 3) */
#define MENU_STATE_COLOR_TEMP_LIST   0x6c       /* + choice: the Color Temperature list (states 0x6C..0x6F) */
#define COLOR_TEMP_ITEM_ROW          3          /* item row of the Color Temperature item */
#define LIST_ID_IMAGE_ITEMS          3          /* value of osd_list_id after leaving the list */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */

/*
 * Left key in the Color Temperature list: put back the choice that was saved when the list was opened
 * (osd_choice_row) and apply the colour settings. The highlight leaves the list row of the present state, the
 * restored choice is highlighted and marked, the menu state returns to the Color Temperature item with its row
 * highlighted, and osd_list_id becomes 3.
 */
void osd_cancel_color_temp(void)
{
  struct user_settings_record *settings = &user_settings;

  settings->color_temperature = osd_choice_row;
  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_COLOR_TEMP_LIST);
  osd_highlight_choice_row(settings->color_temperature, CHOICE_ROW_PLAIN);
  osd_draw_choice_mark(CHOICE_MARK_LIST, settings->color_temperature, CHOICE_MARK_ON);
  pq_user_apply_color_settings();
  osd_menu_state = MENU_STATE_COLOR_TEMP_ITEM;
  osd_highlight_item_row(COLOR_TEMP_ITEM_ROW, HIGHLIGHT_ITEM_ACTIVE);
  osd_list_id = LIST_ID_IMAGE_ITEMS;
}
