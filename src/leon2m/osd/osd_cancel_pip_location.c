/* osd_cancel_pip_location  (FUN_a0095020)
 *
 * Restore the PIP window location saved on entry and go back (left)
 * Note: Location = bits 4..7 of the settings word +0x30.
 * Name basis: derived - handler table 0xA802422C: left on states 0xD8..0xDC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0095020, flags -mcpu=v8 -O3 -g.
 * Source form: the location is a 4-bit bit-field (bits 4..7) of the word at +0x30 of the real settings record
 * (not a symbol in the middle of the record); the record base stays in a register. osd_draw_pip_items takes
 * no argument.
 */
#define LIST_ID_PIP_ITEMS             0x0f      /* osd_list_id value set before the PIP items are drawn */
#define MENU_STATE_PIP_LOCATION_ITEM  0x7c      /* PIP items, Location row (item row 2) */

/* The fields of the user settings record used here. */
struct user_settings_record {
  unsigned char pad[0x30];
  unsigned int pip_word_high : 24;              /* +0x30: PIP word, bits 8..31 */
  unsigned int pip_location : 4;                /* bits 4..7: the PIP window location */
  unsigned int pip_second_location : 4;         /* bits 0..3 */
  unsigned char pad2[0x1a4 - 0x34];
  unsigned char screen_size;                    /* +0x1A4: Screen Size */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned char osd_list_id;
extern unsigned int osd_menu_state;
extern void osd_draw_pip_items(void);
extern void osd_clear_choice_column(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void sys_user_resize_window_channel1(int);

/*
 * Left key in the PIP Location choices: put back the PIP location that was saved in osd_edit_value when the
 * list was opened. When it differs from the present one, the location is stored and the window of channel 1 is
 * computed again (sys_user_resize_window_channel1). Then back to the PIP items: the choice column is cleared,
 * the items are drawn, the menu state becomes the Location item with its row highlighted, and osd_edit_value
 * is loaded with the Screen Size setting.
 */
void osd_cancel_pip_location(void)
{
  struct user_settings_record *settings = &user_settings;

  osd_list_id = LIST_ID_PIP_ITEMS;
  if (osd_edit_value != settings->pip_location) {
    settings->pip_location = osd_edit_value;
    sys_user_resize_window_channel1(1);
  }
  osd_clear_choice_column();
  osd_draw_pip_items();
  osd_menu_state = MENU_STATE_PIP_LOCATION_ITEM;
  osd_highlight_choice_row(2, 1);
  osd_edit_value = settings->screen_size;
}
