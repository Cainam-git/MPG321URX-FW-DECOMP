/* osd_leave_pip_pbp_items  (FUN_a0092648)
 *
 * Leave the PIP/PBP list and return the highlight to its tab (left key)
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x196DC0 (tab 'PIP/PBP')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092648, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record pointer is taken after the first call (the firmware's sethi of the record
 * address comes after it).
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

/* The one field of the user settings record used here. */
struct user_settings_record { unsigned char pad[0x1f]; unsigned char pip_pbp_mode; };  /* +0x1F */
extern struct user_settings_record user_settings;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_item_highlight(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_draw_adaptive_sync_status(void);
extern void osd_draw_item_choices(unsigned char, unsigned char);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void osd_highlight_tab(int, int);

/*
 * Leave the item list of the PIP/PBP tab: the highlighted item is drawn back in normal colours, the choice mark
 * of the current PIP/PBP mode is drawn and osd_highlight_item_row is called for that item with 0. The menu state becomes the PIP/PBP
 * tab row, the cursor goes back to the tab, the Adaptive-Sync status line and the key guide are drawn, and the
 * choice column of the mode's item is drawn.
 */
void osd_leave_pip_pbp_items(void)
{
  struct user_settings_record *settings;

  osd_clear_item_highlight(osd_menu_state - PAGE_PIP_PBP_ITEMS);
  settings = &user_settings;
  osd_draw_choice_mark(0, settings->pip_pbp_mode, 1);
  osd_highlight_item_row(settings->pip_pbp_mode, 0);
  osd_menu_state = MENU_STATE_TAB_BASE + TAB_PIP_PBP;
  osd_highlight_tab(TAB_PIP_PBP, TAB_STYLE_CURSOR);
  osd_draw_adaptive_sync_status();
  osd_draw_key_guide(1, 2);
  osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
  osd_draw_item_choices(PAGE_PIP_PBP_ITEMS, settings->pip_pbp_mode);
}
