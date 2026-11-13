/* osd_leave_navi_key_items  (FUN_a0092998)
 *
 * Leave the Navi Key item list and return the highlight to its tab (left key)
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x19158C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092998 @ 0xa0092998 (-mcpu=v8 -O3 -g).
 * Source forms the exact build depends on: the routine is declared void and takes six words it does not use
 * itself; its last four are handed on unchanged to osd_highlight_tab, which is declared without a parameter
 * list and is the last call (a tail call). osd_draw_item_choices is declared void, the others int.
 */

#define MENU_STATE_NAVI_KEY_ITEMS_FIRST  0x26   /* the Navi Key item list: state 0x26 + item */
#define MENU_STATE_TAB_6                 8      /* tab index 6 (state = tab + 2) of the main menu */
#define TAB_6                            6

extern unsigned char user_settings_byte_0x1a3;
extern unsigned int osd_menu_state;
extern int osd_clear_item_highlight();
extern int osd_highlight_item_row();
extern void osd_draw_item_choices();
extern int osd_highlight_tab();

/* Left key in the Navi Key item list: leave the list and put the highlight back on its tab (tab index 6 of the
 * main menu, menu state 8). No result.
 * In order: clear settings byte +0x1A3, clear the highlight of the current item row (state - 0x26), draw the
 * choice column for 0x26, highlight item row 0 with the second argument 0, set the menu state to 8 and
 * highlight tab 6.
 *   arg1, arg2    not used
 *   arg3 .. arg6  passed on unchanged as the remaining arguments of osd_highlight_tab
 */
void osd_leave_navi_key_items(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  user_settings_byte_0x1a3 = 0;
  osd_clear_item_highlight(osd_menu_state - MENU_STATE_NAVI_KEY_ITEMS_FIRST & 0xff);
  osd_draw_item_choices(MENU_STATE_NAVI_KEY_ITEMS_FIRST, 0);
  osd_highlight_item_row(0, 0);
  osd_menu_state = MENU_STATE_TAB_6;
  osd_highlight_tab(TAB_6, 1, arg3, arg4, arg5, arg6);
}
