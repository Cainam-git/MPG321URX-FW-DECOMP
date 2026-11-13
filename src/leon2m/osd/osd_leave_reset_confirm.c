/* osd_leave_reset_confirm  (FUN_a0099ad0)
 *
 * Leave the Reset question without resetting and return to the item.
 * Note: Returns to state 0x33.
 * Name basis: proven - handler table 0xA802422C: left on 0xB6/0xB7 and OK on 0xB7 = 'No'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099ad0 @ 0xa0099ad0, flags -mcpu=v8 -O2 -g (the default of the section; the earlier note said -Os).
 * Source form: the callee declarations have no parameter list, so the six incoming argument registers are
 * passed on to osd_update_key_guide (it is called last, in the tail position).
 */
extern unsigned int osd_menu_state;
extern void osd_highlight_item_row();
extern int osd_clear_choice_highlight();
extern int osd_draw_key_guide();
extern int osd_update_key_guide();

#define MENU_STATE_RESET_ITEM    0x33   /* Reset item of the Settings page (item row 9) */
#define ITEM_ROW_ACTIVE          1      /* osd_highlight_item_row mode: cursor is in the item list */

/*
 * Left key in the Reset question (states 0xB6, 0xB7), or OK on No: leave without resetting and go back to the
 * Reset item.
 *
 * The highlights of choice rows 0 and 1 are removed, the menu state returns to the Reset item, the item row is
 * highlighted as active and the key guide is redrawn (osd_draw_key_guide, osd_update_key_guide).
 *
 * The six argument registers of the caller are handed on unchanged to osd_update_key_guide.
 */
void osd_leave_reset_confirm(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_clear_choice_highlight(0);
  osd_clear_choice_highlight(1);
  osd_menu_state = MENU_STATE_RESET_ITEM;
  osd_highlight_item_row(9, ITEM_ROW_ACTIVE);
  osd_draw_key_guide(1,2);
  osd_update_key_guide(0,1,arg3,arg4,arg5,arg6);
  return;
}
