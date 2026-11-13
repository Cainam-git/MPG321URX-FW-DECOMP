/* osd_accept_pip_source  (FUN_a00950a8)
 *
 * Keep the highlighted PIP source and go back to the PIP settings (OK)
 * Note: States 0xD0..0xD3; returns to 'Source' (0x7A) and re-applies the sub-window inputs.
 * Name basis: derived - handler table 0xA802422C: OK on states 0xD0..0xD3; PIP item texts 0x1828C0 (Source,
 *   PIP Size, Location, ...)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00950a8, flags -mcpu=v8 -O3 -g.
 * Source form: the old source is read into a local before the new one is stored; the settings record is a
 * struct with the two bytes used here.
 */
#define LIST_ID_PIP_ITEMS             0x0f      /* osd_list_id value set before the PIP items are drawn */
#define MENU_STATE_PIP_SOURCE_ITEM    0x7a      /* PIP items, Source row (item row 0) */
#define OSD_REQUEST_SETTINGS_CHANGED  0x02      /* bit of osd_request_bits */

/* The fields of the user settings record used here. */
struct user_settings_record {
  unsigned char pad[0x20];
  unsigned char second_source;                  /* +0x20: source of the second picture (menu index) */
  unsigned char pad2[0x1a4 - 0x21];
  unsigned char screen_size;                    /* +0x1A4: Screen Size */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_edit_value;
extern unsigned char osd_request_bits;
extern unsigned char osd_list_id;
extern unsigned int osd_menu_state;
extern void osd_draw_pip_items(void);
extern void osd_clear_choice_column(void);
extern void osd_highlight_choice_row(unsigned char, int);
extern void sys_user_apply_pip_sources(int);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);

/*
 * OK key in the PIP Source choices: the source of the second picture becomes
 * input_api_menu_index_to_source_id((menu state + 0x30) & 0xff). When it differs from the old one the sources
 * are applied again (sys_user_apply_pip_sources). Then back to the PIP items: the choice column is cleared,
 * the items are drawn, the menu state becomes the Source item with its row highlighted, osd_edit_value is
 * loaded with the Screen Size setting and the settings-changed request is made.
 */
void osd_accept_pip_source(void)
{
  struct user_settings_record *settings = &user_settings;
  unsigned char old_source = settings->second_source;

  settings->second_source = input_api_menu_index_to_source_id(osd_menu_state + 0x30);
  if (settings->second_source != old_source)
    sys_user_apply_pip_sources(1);
  osd_list_id = LIST_ID_PIP_ITEMS;
  osd_clear_choice_column();
  osd_draw_pip_items();
  osd_menu_state = MENU_STATE_PIP_SOURCE_ITEM;
  osd_highlight_choice_row(0, 1);
  osd_edit_value = settings->screen_size;
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
