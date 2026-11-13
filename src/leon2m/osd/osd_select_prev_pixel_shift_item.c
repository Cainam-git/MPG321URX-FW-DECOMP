/* osd_select_prev_pixel_shift_item  (FUN_a009de04)
 *
 * Move to the previous allowed Pixel Shift row (OFF, ON, speed) (up key)
 * Name basis: derived - handler table 0xA802422C: up on states 0xB8..0xBA
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009de04 @ 0xa009de04, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - (BASE - (COUNT - 1)), taken modulo the count in a second statement;
 *  - the row passed to the clear and highlight calls is written state + (256 - BASE) (the argument is one byte);
 *    osd_choice_row is copied into a block-scope local for the compare and the mark row.
 */

#define MENU_STATE_PIXEL_SHIFT_LIST 0xb8        /* + row: OFF, ON, speed */
#define PIXEL_SHIFT_COUNT           3
#define CHOICE_MARK_LIST            1           /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON              1
#define CHOICE_MARK_OFF             0
#define CHOICE_ROW_EDGED            1           /* highlight style of a choice row */

extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);

/*
 * Up key on the Pixel Shift rows (OFF, ON, speed): move the highlight to the previous row, wrapping from the first row to the last.
 * Rows that osd_is_choice_enabled rejects are skipped. Nothing is stored here.
 *
 * The mark is drawn at the row of osd_choice_row (the value saved on entry); it is switched off while the
 * highlight is on that row and on otherwise.
 */
void osd_select_prev_pixel_shift_item(void)
{
  int row;

  osd_clear_choice_highlight(osd_menu_state + (256 - MENU_STATE_PIXEL_SHIFT_LIST));
  do {
    row = (unsigned short)osd_menu_state - (MENU_STATE_PIXEL_SHIFT_LIST - (PIXEL_SHIFT_COUNT - 1));
    row = row % PIXEL_SHIFT_COUNT;
    osd_menu_state = row + MENU_STATE_PIXEL_SHIFT_LIST;
  } while (osd_is_choice_enabled(row) != 1);
  osd_highlight_choice_row(osd_menu_state + (256 - MENU_STATE_PIXEL_SHIFT_LIST), CHOICE_ROW_EDGED);
  {
    unsigned char saved = osd_choice_row;
    if (osd_menu_state - MENU_STATE_PIXEL_SHIFT_LIST == saved)
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_OFF);
    else
      osd_draw_choice_mark(CHOICE_MARK_LIST, saved, CHOICE_MARK_ON);
  }
}
