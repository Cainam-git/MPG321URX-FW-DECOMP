/* osd_leave_professional_items  (FUN_a0091d74)
 *
 * Leave the Professional item list and return the highlight to its tab (left key)
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x188634
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091d74, flags -mcpu=v8 -O3 -g.
 * Source form: the decompiler's six-argument form is kept; the callees are declared without parameter lists and
 * arguments 3 to 6 are handed on to osd_update_key_guide.
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_PROFESSIONAL      2
#define PAGE_PROFESSIONAL_ITEMS    0x15       /* menu state of the first item of the Professional tab */
#define PRO_ITEM_COUNT             3

extern unsigned int osd_menu_state;
extern int osd_clear_item_highlight();
extern void osd_highlight_item_row();
extern int osd_draw_key_guide();
extern void osd_draw_professional_item_state();
extern void osd_draw_item_choices();
extern int osd_update_key_guide();
extern void osd_highlight_tab();

/*
 * Leave the item list of the Professional tab: the highlighted item is drawn back in normal colours, the choice
 * column is redrawn for item 0, the menu state becomes the Professional tab row and the cursor goes back to
 * the tab. arg1 and arg2 are not used; arg3 to arg6 are handed on to osd_update_key_guide.
 */
void osd_leave_professional_items(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                 unsigned int arg5, unsigned int arg6)

{
  osd_clear_item_highlight((osd_menu_state - PAGE_PROFESSIONAL_ITEMS) & 0xff);
  osd_draw_professional_item_state((osd_menu_state - PAGE_PROFESSIONAL_ITEMS) & 0xff, 0);
  osd_draw_item_choices(PAGE_PROFESSIONAL_ITEMS, 0);
  osd_highlight_item_row(0, 0);
  osd_menu_state = MENU_STATE_TAB_BASE + TAB_PROFESSIONAL;
  osd_highlight_tab(TAB_PROFESSIONAL, TAB_STYLE_CURSOR);
  osd_draw_key_guide(1, 2);
  osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER, arg3, arg4, arg5, arg6);
  return;
}
