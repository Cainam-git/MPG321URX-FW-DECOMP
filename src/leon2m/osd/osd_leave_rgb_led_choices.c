/* osd_leave_rgb_led_choices  (FUN_a009901c)
 *
 * Leave the RGB LED list and return to the item (left)
 * Note: Returns to state 0x2D.
 * Name basis: derived - handler table 0xA802422C: left on states 0xB1..0xB3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009901c @ 0xa009901c, flags -mcpu=v8 -O3 -g.
 * Source form: the callee declarations have no parameter list, so the six incoming argument registers are
 * passed on to osd_highlight_item_row (it is called last, in the tail position); the unnamed prototypes of
 * osd_draw_choice_mark / osd_highlight_item_row / osd_clear_choice_highlight are kept.
 */
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern int osd_draw_choice_mark();
extern int osd_highlight_item_row();
extern int osd_clear_choice_highlight();
extern void osd_highlight_choice_row();

#define MENU_STATE_RGB_LED_ITEM  0x2d   /* RGB LED item of the Settings page (item row 3) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_DRAW                1
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */
#define CHOICE_ROW_PLAIN         0      /* osd_highlight_choice_row style: plain */

/*
 * Left key in the RGB LED list (states 0xB1..0xB3): leave without changing the setting and go back to the
 * RGB LED item.
 *
 * The cursor row (state - 0xB1, written as state + 0x4F in the byte argument) loses its highlight. The row saved
 * on entry (osd_choice_row) gets the plain highlight and the mark. The menu state returns to the RGB LED item
 * and the item row is highlighted as active.
 *
 * The six argument registers of the caller are handed on unchanged to osd_highlight_item_row.
 */
void osd_leave_rgb_led_choices(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_clear_choice_highlight(osd_menu_state + 0x4fU & 0xff);
  osd_highlight_choice_row(osd_choice_row, CHOICE_ROW_PLAIN);
  osd_draw_choice_mark(CHOICE_MARK_LIST, osd_choice_row, MARK_DRAW);
  osd_menu_state = MENU_STATE_RGB_LED_ITEM;
  osd_highlight_item_row(3, ITEM_ROW_ACTIVE, arg3, arg4, arg5, arg6);
  return;
}
