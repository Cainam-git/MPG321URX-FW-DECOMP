/* osd_select_next_professional_item  (FUN_a0091ea0)
 *
 * Move the highlight to the next enabled Professional item (down key)
 * Note: Wraps inside the states 0x15..0x17.
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x188634
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091ea0, flags -mcpu=v8 -O3 -g.
 * Twin of osd_select_prev_professional_item (only the loop constant differs). The halfword read is
 * '(unsigned short)osd_menu_state'.
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
extern void osd_clear_item_highlight(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_professional_item_state(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_draw_item_choices(unsigned char, unsigned char);

/*
 * Move the highlight of the Professional tab to the next item that osd_is_item_enabled accepts (wrapping
 * after the last). The old and new item's switch states and the new item's choice column are drawn.
 */
void osd_select_next_professional_item(void)
{
  int item;

  osd_clear_item_highlight(osd_menu_state - PAGE_PROFESSIONAL_ITEMS);
  osd_draw_professional_item_state(osd_menu_state - PAGE_PROFESSIONAL_ITEMS, 0);
  do {
    item = (unsigned short)osd_menu_state - (PAGE_PROFESSIONAL_ITEMS - 1);
    item = item % PRO_ITEM_COUNT;
    osd_menu_state = item + PAGE_PROFESSIONAL_ITEMS;
  } while (osd_is_item_enabled(item) != 1);
  osd_highlight_item_row(osd_menu_state - PAGE_PROFESSIONAL_ITEMS, 1);
  osd_draw_professional_item_state(osd_menu_state - PAGE_PROFESSIONAL_ITEMS, 1);
  osd_draw_item_choices(PAGE_PROFESSIONAL_ITEMS, osd_menu_state - PAGE_PROFESSIONAL_ITEMS);
}
