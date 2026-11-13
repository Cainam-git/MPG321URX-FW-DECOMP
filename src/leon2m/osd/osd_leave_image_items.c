/* osd_leave_image_items  (FUN_a0092044)
 *
 * Leave the Image item list and return the highlight to its tab (left key)
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x18CA88
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092044, flags -mcpu=v8 -O3 -g.
 * The whole tail is duplicated per path by jump threading. Source form: the ternary '== 1 ? 1 : 2' keeps the
 * firmware's addx + add 1 ('(x != 1) + 1' folds to mov 2 / addx -1).
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define TAB_IMAGE             3
#define PAGE_IMAGE_ITEMS           0x18       /* menu state of the first item of the Image tab */
#define IMAGE_ITEM_COUNT           6

extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_draw_item_choices(unsigned char, unsigned char);
extern void osd_highlight_tab(int, int);

/*
 * Leave the item list of the Image tab: the highlighted item is drawn back in normal colours. The item shown
 * afterwards is item 0 if osd_is_item_enabled accepts it, else item 1 if that is accepted, else item 2; its
 * choice column is drawn and osd_highlight_item_row is called for it with 0. The menu state becomes the Image tab row and the
 * cursor goes back to the tab.
 */
void osd_leave_image_items(void)
{
  unsigned char item;

  osd_clear_item_highlight(osd_menu_state - PAGE_IMAGE_ITEMS);
  if (osd_is_item_enabled(0) != 0)
    item = 0;
  else
    item = osd_is_item_enabled(1) == 1 ? 1 : 2;
  osd_draw_item_choices(PAGE_IMAGE_ITEMS, item);
  osd_highlight_item_row(item, 0);
  osd_menu_state = MENU_STATE_TAB_BASE + TAB_IMAGE;
  osd_highlight_tab(TAB_IMAGE, TAB_STYLE_CURSOR);
}
