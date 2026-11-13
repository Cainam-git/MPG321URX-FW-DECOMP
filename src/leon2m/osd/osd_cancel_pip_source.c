/* osd_cancel_pip_source  (FUN_a0095134)
 *
 * Restore the PIP source saved on entry, re-apply it if changed, and go back (left)
 * Note: Source = settings byte +0x20.
 * Name basis: derived - handler table 0xA802422C: left on states 0xD0..0xD3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095134, flags -mcpu=v8 -O3 -g.
 * Source form: the old source and the saved one are unsigned int locals and the comparison is its own
 * statement before the stores (unsigned char locals would extend the saved value again); the settings record
 * is a plain byte array; there is no volatile. The copy of the Screen Size byte runs after the last call.
 */
#define LIST_ID_PIP_ITEMS             0x0f      /* osd_list_id value set before the PIP items are drawn */
#define MENU_STATE_PIP_SOURCE_ITEM    0x7a      /* PIP items, Source row (item row 0) */
#define SETTINGS_SECOND_SOURCE        0x20      /* settings offset: source of the second picture */
#define SETTINGS_SCREEN_SIZE          0x1a4     /* settings offset: Screen Size */

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char osd_list_id;
extern unsigned char user_settings[];
extern void sys_user_apply_pip_sources(int);
extern void osd_clear_choice_column(void);
extern void osd_draw_pip_items(void);
extern void osd_highlight_choice_row(int, int);

/*
 * Left key in the PIP Source choices: put back the source of the second picture that was saved in
 * osd_edit_value when the list was opened; when it differs from the present one the sources are applied again
 * (sys_user_apply_pip_sources). Then back to the PIP items: the choice column is cleared, the items are drawn,
 * the menu state becomes the Source item with its row highlighted, and osd_edit_value is loaded with the
 * Screen Size setting.
 */
void osd_cancel_pip_source(void)
{
  unsigned char *settings = user_settings;
  unsigned int old_source = settings[SETTINGS_SECOND_SOURCE];
  unsigned int saved_source = osd_edit_value;
  int changed;

  changed = old_source != saved_source;
  osd_list_id = LIST_ID_PIP_ITEMS;
  settings[SETTINGS_SECOND_SOURCE] = saved_source;
  if (changed)
    sys_user_apply_pip_sources(1);
  osd_clear_choice_column();
  osd_draw_pip_items();
  osd_menu_state = MENU_STATE_PIP_SOURCE_ITEM;
  osd_highlight_choice_row(0, 1);
  osd_edit_value = settings[SETTINGS_SCREEN_SIZE];
}
