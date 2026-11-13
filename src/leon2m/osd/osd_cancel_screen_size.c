/* osd_cancel_screen_size  (FUN_a0096bd8)
 *
 * Restore the screen size saved on entry, re-apply it if changed, and go back.
 * Note: Returns to state 0x1C.
 * Name basis: derived - handler table 0xA802422C: left on states 0x70..0x76
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0096bd8 @ 0xa0096bd8-0xa0096c80 (42 words), flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is reached through a struct pointer (RAM, no volatile). The Screen Size byte
 * is written again after the conditional block. The 0x1C store comes before the osd_highlight_item_row call and
 * osd_draw_adaptive_sync_status after it.
 */

/* The field of the user settings record used here. */
struct user_settings_record {
  unsigned char pad0[0x1a4];
  unsigned char screen_size;                    /* +0x1A4: Screen Size */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned char osd_list_id;
extern unsigned int osd_menu_state;
extern void pq_update_input_window(int);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_draw_adaptive_sync_status(void);
extern void panel_user_set_output_on(int);

#define MENU_STATE_SCREEN_SIZE_ITEM  0x1c       /* Image page, item Screen Size (item row 4) */
#define MENU_STATE_SCREEN_SIZE_LIST  0x70       /* + choice: the Screen Size list */
#define SCREEN_SIZE_ITEM_ROW         4          /* item row of the Screen Size item */
#define LIST_ID_IMAGE_ITEMS          3          /* value of osd_list_id after leaving the list */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON               1
#define CHOICE_ROW_PLAIN             0          /* highlight style of a choice row while the list is left */
#define HIGHLIGHT_ITEM_ACTIVE        1          /* highlight style of an item row with the cursor in the item list */

/*
 * Left key in the Screen Size list: put back the Screen Size that was saved when the list was opened
 * (osd_choice_row).
 *
 * When the stored Screen Size differs from the saved one, the picture output is switched off first
 * (panel_user_set_output_on(0)), the saved value is written back and the input window is recomputed
 * (pq_update_input_window(0)). Then the highlight leaves the list row of the present state, the restored choice is
 * highlighted and marked, the menu state returns to the Screen Size item with its row highlighted, the
 * Adaptive-Sync status line is redrawn and osd_list_id becomes 3.
 */
void osd_cancel_screen_size(void)
{
  struct user_settings_record *settings = &user_settings;

  if (settings->screen_size != osd_choice_row) {
    panel_user_set_output_on(0);
    settings->screen_size = osd_choice_row;
    pq_update_input_window(0);
  }
  settings->screen_size = osd_choice_row;
  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_SCREEN_SIZE_LIST);
  osd_highlight_choice_row(settings->screen_size, CHOICE_ROW_PLAIN);
  osd_draw_choice_mark(CHOICE_MARK_LIST, settings->screen_size, CHOICE_MARK_ON);
  osd_menu_state = MENU_STATE_SCREEN_SIZE_ITEM;
  osd_highlight_item_row(SCREEN_SIZE_ITEM_ROW, HIGHLIGHT_ITEM_ACTIVE);
  osd_draw_adaptive_sync_status();
  osd_list_id = LIST_ID_IMAGE_ITEMS;
}
