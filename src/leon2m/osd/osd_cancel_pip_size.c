/* osd_cancel_pip_size  (FUN_a0095430)
 *
 * Restore the PIP size saved on entry, re-apply it if changed, and go back (left)
 * Note: Size = settings byte +0x31.
 * Name basis: derived - handler table 0xA802422C: left on states 0xCD..0xCF
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095430, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a plain byte array; the saved size is read into an unsigned char local
 * first; the callees return nothing.
 */
#define LIST_ID_PIP_ITEMS             0x0f      /* osd_list_id value set before the PIP items are drawn */
#define MENU_STATE_PIP_SIZE_ITEM      0x7b      /* PIP items, PIP Size row (item row 1) */
#define SETTINGS_PIP_SIZE             0x31      /* settings offset: PIP window size */
#define SETTINGS_SCREEN_SIZE          0x1a4     /* settings offset: Screen Size */

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char osd_list_id;
extern unsigned char user_settings[];
extern void sys_user_rebuild_window_channel1(void);
extern void osd_clear_choice_column(void);
extern void osd_draw_pip_items(void);
extern void osd_highlight_choice_row(int, int);

/*
 * Left key in the PIP Size choices: put back the PIP size that was saved in osd_edit_value when the list was
 * opened. When it differs from the present one, it is stored and the window of channel 1 is computed again
 * (sys_user_rebuild_window_channel1). Then back to the PIP items: the choice column is cleared, the items are
 * drawn, the menu state becomes the PIP Size item with its row highlighted, and osd_edit_value is loaded with
 * the Screen Size setting.
 */
void osd_cancel_pip_size(void)
{
  unsigned char saved_size;

  osd_list_id = LIST_ID_PIP_ITEMS;
  saved_size = osd_edit_value;
  if (user_settings[SETTINGS_PIP_SIZE] != saved_size) {
    user_settings[SETTINGS_PIP_SIZE] = saved_size;
    sys_user_rebuild_window_channel1();
  }
  osd_clear_choice_column();
  osd_draw_pip_items();
  osd_menu_state = MENU_STATE_PIP_SIZE_ITEM;
  osd_highlight_choice_row(1, 1);
  osd_edit_value = user_settings[SETTINGS_SCREEN_SIZE];
}
