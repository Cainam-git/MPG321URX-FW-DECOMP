/* osd_leave_gaming_items  (FUN_a00919b4)
 *
 * Leave the Gaming item list and return the highlight to its tab (left key)
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x188DA0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00919b4, flags -mcpu=v8 -O3 -g.
 * The common tail is duplicated per arm by jump threading. Source form: the '> last item' arm comes first.
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_GAMING            1
#define PAGE_GAMING_ITEMS          0x0e       /* menu state of the first item of the Gaming tab */
#define GAMING_ITEM_COUNT          7
#define MENU_STATE_GAMING_ITEM_LAST 0x14
extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_key_guide(int, int);
extern void osd_draw_gaming_item_state(unsigned char, int);
extern void osd_draw_item_choices(unsigned char, unsigned char);
extern void osd_draw_tab_page(int);
extern void osd_update_key_guide(int, int);
extern void osd_highlight_tab(int, int);

/*
 * Leave the item list of the Gaming tab: the highlighted item is drawn back in normal colours. When the menu
 * state is above the last Gaming item (0x14) the page of tab 1 is drawn; otherwise the choice column is
 * redrawn for item 0. The menu state becomes the Gaming tab row and the cursor goes back to the tab.
 */
void osd_leave_gaming_items(void)
{
  osd_clear_item_highlight(osd_menu_state - PAGE_GAMING_ITEMS);
  osd_draw_gaming_item_state(osd_menu_state - PAGE_GAMING_ITEMS, 0);
  if (osd_menu_state > MENU_STATE_GAMING_ITEM_LAST)
    osd_draw_tab_page(TAB_GAMING);
  else {
    osd_draw_item_choices(PAGE_GAMING_ITEMS, 0);
    osd_highlight_item_row(0, 0);
  }
  osd_menu_state = MENU_STATE_TAB_BASE + TAB_GAMING;
  osd_highlight_tab(TAB_GAMING, TAB_STYLE_CURSOR);
  osd_draw_key_guide(1, 2);
  osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
}
