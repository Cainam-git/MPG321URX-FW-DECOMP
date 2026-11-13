/* osd_leave_pbp_settings  (FUN_a0097ad0)
 *
 * Restore the PBP mode saved on entry if changed and return to the PIP/PBP list.
 * Note: Re-applies with UserSetPIPMode when settings byte +0x2F changed; returns to state 0x25.
 * Name basis: derived - handler table 0xA802422C: left on states 0x7F..0x85
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097ad0 @ 0xa0097ad0-0xa0097b7c (43 words), flags -mcpu=v8 -O3 -g.
 * Source form: the PBP layout byte is reached through a struct pointer and is written with the byte of
 * osd_saved_choice_value; all types are bytes. The routine has no parameters.
 */

/* The field of the user settings record used here. */
struct user_settings_record {
  unsigned char pad0[0x2f];
  unsigned char pbp_layout;                     /* +0x2F: the PBP layout */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_saved_choice_value;
extern unsigned char osd_list_id;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void UserSetPIPMode(void);

#define MENU_STATE_PBP_LIST          0x7f       /* + row: the PBP settings list (layouts 0..2, then Source 1, Source 2, ...) */
#define MENU_STATE_PBP_ITEM          0x25       /* PIP/PBP page, item PBP (item row 2) */
#define PBP_ITEM_ROW                 2          /* item row of the PBP item */
#define LIST_ID_PIP_PBP_ITEMS        5          /* value of osd_list_id set when the PIP/PBP item list is shown again */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */

/*
 * Left key in the PBP settings list: go back to the PBP item of the PIP/PBP list.
 *
 * When the PBP layout differs from the one saved when the list opened (osd_saved_choice_value), the saved layout
 * is written back and UserSetPIPMode applies it. The highlight of the list row of the present state (state minus
 * 0x7F) is cleared, the layout's row is marked and highlighted, the menu state returns to 0x25 with its item row
 * highlighted, the key guide is redrawn and osd_list_id becomes 5.
 */
void osd_leave_pbp_settings(void)
{
  struct user_settings_record *settings = &user_settings;

  if (settings->pbp_layout != osd_saved_choice_value) {
    settings->pbp_layout = osd_saved_choice_value;
    UserSetPIPMode();
  }
  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_PBP_LIST);
  osd_draw_choice_mark(CHOICE_MARK_LIST, settings->pbp_layout, CHOICE_MARK_ON);
  osd_highlight_choice_row(settings->pbp_layout, CHOICE_ROW_PLAIN);
  osd_draw_key_guide(1, 2);
  osd_menu_state = MENU_STATE_PBP_ITEM;
  osd_highlight_item_row(PBP_ITEM_ROW, HIGHLIGHT_ITEM_ACTIVE);
  osd_draw_key_guide(1, 2);
  osd_update_key_guide(0, 1);
  osd_list_id = LIST_ID_PIP_PBP_ITEMS;
}
