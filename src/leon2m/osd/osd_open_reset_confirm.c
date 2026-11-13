/* osd_open_reset_confirm  (FUN_a0099a7c)
 *
 * Ask for confirmation of the settings Reset with 'No' highlighted.
 * Note: States 0xB6 = Yes, 0xB7 = No.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x33 = 'Reset' (Settings texts 0x1874F8);
 *   texts 0x190748 Yes, No
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0099a7c @ 0xa0099a7c, flags -mcpu=v8 -O3 -g (the default of the section).
 * Source form: the callee declarations have no parameter list, so the six incoming argument registers are
 * passed on to osd_highlight_choice_row (it is called last, in the tail position).
 */
extern unsigned int osd_menu_state;
extern void osd_draw_choice_mark();
extern int osd_highlight_item_row();
extern int osd_highlight_choice_row();

#define PAGE_SETTINGS_ITEMS      0x2a   /* first item state of the Settings page; item row = state - 0x2a */
#define MENU_STATE_RESET_NO      0xb7   /* the No row of the Reset question (Yes is 0xB6) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define ITEM_ROW_LIST_OPEN       2      /* osd_highlight_item_row mode: parent of an open choice list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */

/*
 * OK or right on the Reset item of the Settings page: show the Yes / No question with No (row 1) highlighted.
 * The mark of row 1 is cleared, the item row is highlighted in the "list open" style and the menu state becomes
 * 0xB7.
 *
 * The six argument registers of the caller are handed on unchanged to osd_highlight_choice_row.
 */
void osd_open_reset_confirm(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_draw_choice_mark(CHOICE_MARK_LIST, 1, MARK_CLEAR);
  osd_highlight_item_row(osd_menu_state - PAGE_SETTINGS_ITEMS & 0xff, ITEM_ROW_LIST_OPEN);
  osd_menu_state = MENU_STATE_RESET_NO;
  osd_highlight_choice_row(1, CHOICE_ROW_EDGED, arg3, arg4, arg5, arg6);
  return;
}
