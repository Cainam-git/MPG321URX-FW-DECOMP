/* osd_select_prev_optix_scope_item  (FUN_a009dbd4)
 *
 * Move to the previous allowed Optix Scope row (Scope Size, Scope Ratio, OFF, ON) (up key)
 * Name basis: derived - handler table 0xA802422C: up on states 0x44..0x47; texts 0x18D578
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009dbd4 @ 0xa009dbd4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - (BASE - (COUNT - 1)), taken modulo the count in a second statement;
 *  - osd_choice_row is copied into a block-scope local; the compare uses state - 0x46 and the mark row is the local
 *    plus 2.
 */

#define MENU_STATE_OPTIX_SCOPE_ITEMS    0x44    /* + row: Scope Size, Scope Ratio, OFF, ON */
#define OPTIX_SCOPE_ROW_COUNT           4
#define MENU_STATE_OPTIX_SCOPE_OFF      0x46    /* row 2: the OFF choice; ON is 0x47 */
#define OPTIX_SCOPE_FIRST_SWITCH_ROW    2       /* the switch choices OFF / ON start at row 2 */
#define CHOICE_MARK_LIST                1       /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON                  1
#define CHOICE_MARK_OFF                 0
#define CHOICE_ROW_EDGED                1       /* highlight style of a choice row */

extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);

/*
 * Up key on the Optix Scope rows (Scope Size, Scope Ratio, OFF, ON): move the highlight to the previous row, wrapping from the first row to the last.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * Only the switch choices OFF (state 0x46) and ON (0x47) carry a mark: osd_choice_row holds the saved switch value
 * (0 or 1) and the mark is drawn at row osd_choice_row + 2. The mark is switched off while the highlight is on
 * that choice and on otherwise.
 */
void osd_select_prev_optix_scope_item(void)
{
  int row;

  osd_clear_choice_highlight(osd_menu_state - MENU_STATE_OPTIX_SCOPE_ITEMS);
  do {
    row = (unsigned short)osd_menu_state - (MENU_STATE_OPTIX_SCOPE_ITEMS - (OPTIX_SCOPE_ROW_COUNT - 1));
    row = row % OPTIX_SCOPE_ROW_COUNT;
    osd_menu_state = row + MENU_STATE_OPTIX_SCOPE_ITEMS;
  } while (osd_is_choice_enabled(row) != 1);
  osd_highlight_choice_row(osd_menu_state - MENU_STATE_OPTIX_SCOPE_ITEMS, CHOICE_ROW_EDGED);
  {
    unsigned char saved = osd_choice_row;
    if (osd_menu_state - MENU_STATE_OPTIX_SCOPE_OFF == saved)
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved + OPTIX_SCOPE_FIRST_SWITCH_ROW, CHOICE_MARK_OFF);
    else
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved + OPTIX_SCOPE_FIRST_SWITCH_ROW, CHOICE_MARK_ON);
  }
}
