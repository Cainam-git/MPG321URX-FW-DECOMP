/* osd_select_next_color_temp  (FUN_a009c8ec)
 *
 * Move to the next allowed colour temperature (down key) and preview it.
 * Note: Wraps inside the states 0x6C..0x6F; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: down on states 0x6C..0x6F; writes settings byte +0x11,
 *   applies with pq_user_apply_color_settings; texts 0x18DB28
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009c8ec @ 0xa009c8ec, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - (BASE - 1), taken modulo the count in a second statement;
 *  - the settings record is a byte array (Color Temperature at +0x11); osd_choice_row is copied into a block-scope
 *    local for the compare and the mark row.
 */

#define MENU_STATE_COLOR_TEMP_LIST  0x6c        /* + row: the four Color Temperature choices */
#define COLOR_TEMP_COUNT            4
#define USER_SETTINGS_COLOR_TEMPERATURE 0x11    /* user_settings_color_temperature */
#define CHOICE_MARK_LIST            1           /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON              1
#define CHOICE_MARK_OFF             0
#define CHOICE_ROW_EDGED            1           /* highlight style of a choice row */

extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void pq_user_apply_color_settings(void);

/*
 * Down key in the Color Temperature list: move the highlight to the next row, wrapping from the last row to the first.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The row number is stored as the Color Temperature (+0x11) at once and pq_user_apply_color_settings applies it.
 * The mark is drawn at the row of the value saved on entry (osd_choice_row); it is switched off while the
 * highlight is on that row and on otherwise.
 */
void osd_select_next_color_temp(void)
{
  int row;

  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_COLOR_TEMP_LIST);
  do {
    row = (unsigned short)osd_menu_state - (MENU_STATE_COLOR_TEMP_LIST - 1);
    row = row % COLOR_TEMP_COUNT;
    osd_menu_state = row + MENU_STATE_COLOR_TEMP_LIST;
  } while (osd_is_choice_enabled(row) != 1);
  user_settings[USER_SETTINGS_COLOR_TEMPERATURE] = osd_menu_state - MENU_STATE_COLOR_TEMP_LIST;
  pq_user_apply_color_settings();
  osd_highlight_choice_row(osd_menu_state - MENU_STATE_COLOR_TEMP_LIST, CHOICE_ROW_EDGED);
  {
    unsigned char saved = osd_choice_row;
    if (osd_menu_state - MENU_STATE_COLOR_TEMP_LIST == saved)
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
    else
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
  }
}
