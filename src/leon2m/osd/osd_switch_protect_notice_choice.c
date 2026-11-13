/* osd_switch_protect_notice_choice  (FUN_a009e0bc)
 *
 * Move the highlight between the two Protect Notice choices.
 * Note: Choices Auto / Usage 24 hrs; the byte-identical copy osd_switch_protect_notice_choice_copy serves the
 *   down key.
 * Name basis: derived - handler table 0xA802422C: up on states 0xC3/0xC4; texts 0x18B29C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009e0bc @ 0xa009e0bc, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - one expression for the step, ((u16)state - (BASE - 1)) % 2 in an int (both directions are the same step);
 *  - the row passed to the clear and highlight calls is written state + (256 - BASE) (the argument is one byte);
 *    the compare and the mark use osd_choice_row directly, without a local copy.
 */

#define MENU_STATE_PROTECT_NOTICE_LIST  0xc3    /* + row: the two Protect Notice choices (Auto, Usage 24 hrs) */
#define PROTECT_NOTICE_COUNT            2
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
 * Up or down key on the two Protect Notice choices: move the highlight to the other row (with two rows both
 * keys do the same). Serves the up key; osd_switch_protect_notice_choice_copy is a byte-identical copy for the down key.
 * Rows that osd_is_choice_enabled rejects are skipped. Nothing is stored here.
 *
 * The mark is drawn at the row of osd_choice_row (the value saved on entry); it is switched off while the
 * highlight is on that row and on otherwise.
 */
void osd_switch_protect_notice_choice(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state + (256 - MENU_STATE_PROTECT_NOTICE_LIST));
    do {
        row = ((unsigned short)osd_menu_state - (MENU_STATE_PROTECT_NOTICE_LIST - 1)) % PROTECT_NOTICE_COUNT;
        osd_menu_state = row + MENU_STATE_PROTECT_NOTICE_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    osd_highlight_choice_row(osd_menu_state + (256 - MENU_STATE_PROTECT_NOTICE_LIST), CHOICE_ROW_EDGED);
    if (osd_menu_state - MENU_STATE_PROTECT_NOTICE_LIST == osd_choice_row)
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_OFF);
    else
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, CHOICE_MARK_ON);
}
