/* osd_switch_reset_confirm_choice  (FUN_a009dd34)
 *
 * Move the highlight between Yes and No in the Reset question.
 * Note: The byte-identical copy osd_switch_reset_confirm_choice_copy serves the down key.
 * Name basis: derived - handler table 0xA802422C: up on states 0xB6 (Yes) / 0xB7 (No)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009dd34 @ 0xa009dd34, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - (BASE - 1), taken modulo 2 in a second statement (both directions are the same step);
 *  - the row passed to the clear and highlight calls is written state + (256 - BASE) (the argument is one byte).
 */

#define MENU_STATE_RESET_CONFIRM_LIST   0xb6    /* + row: 0 Yes, 1 No */
#define RESET_CONFIRM_COUNT             2
#define CHOICE_ROW_EDGED                1       /* highlight style of a choice row */

extern unsigned int osd_menu_state;
extern void osd_clear_choice_highlight(unsigned char);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);

/*
 * Up or down key on the Yes / No choices of the Reset question: move the highlight to the other row (with two
 * rows both keys do the same). Serves the up key; osd_switch_reset_confirm_choice_copy is a byte-identical copy for the down key.
 * Rows that osd_is_choice_enabled rejects are skipped. Nothing is stored and no mark is drawn.
 */
void osd_switch_reset_confirm_choice(void)
{
  int row;

  osd_clear_choice_highlight(osd_menu_state + (256 - MENU_STATE_RESET_CONFIRM_LIST));
  do {
    row = (unsigned short)osd_menu_state - (MENU_STATE_RESET_CONFIRM_LIST - 1);
    row = row % RESET_CONFIRM_COUNT;
    osd_menu_state = row + MENU_STATE_RESET_CONFIRM_LIST;
  } while (osd_is_choice_enabled(row) != 1);
  osd_highlight_choice_row(osd_menu_state + (256 - MENU_STATE_RESET_CONFIRM_LIST), CHOICE_ROW_EDGED);
}
