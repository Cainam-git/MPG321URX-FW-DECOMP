/* osd_select_prev_gi_item  (FUN_a0091784)
 *
 * Move the highlight to the previous enabled item of the G.I. tab.
 * Note: Wraps inside the states 0x0B..0x0D.
 * Name basis: proven - steps the menu state by -1 mod 3 until osd_is_item_enabled accepts it; key role from
 *   the menu state handler table 0xA802422C, tab texts 0x196DC0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0091784, flags -mcpu=v8 -O3 -g.
 * Same code as osd_select_prev_professional_item with other constants. The halfword read is
 * '(unsigned short)osd_menu_state'.
 */

#define MENU_STATE_TAB_BASE   2         /* menu state of a tab row = 2 + tab number */
#define TAB_STYLE_CURSOR      1         /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_STYLE_PARENT      2         /* osd_highlight_tab: the tab whose item list is open */
#define KEY_TEXT_MOVE         0         /* key guide texts: Move, Enter, Select */
#define KEY_TEXT_ENTER        1
#define KEY_TEXT_SELECT       4
#define PAGE_GI_ITEMS              0x0b       /* menu state of the first item of the G.I. tab */
#define GI_ITEM_COUNT              3

extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_draw_default_key_guide(unsigned char, int);
extern unsigned char osd_is_item_enabled(unsigned char);
extern void osd_draw_item_choices(unsigned char, unsigned char);

/*
 * Move the highlight of the G.I. tab to the previous item that osd_is_item_enabled accepts (wrapping before the
 * first), with its default key guide and choice column.
 */
void osd_select_prev_gi_item(void)
{
  int item;

  osd_clear_item_highlight(osd_menu_state - PAGE_GI_ITEMS);
  osd_draw_default_key_guide(osd_menu_state - PAGE_GI_ITEMS, 0);
  do {
    item = (unsigned short)osd_menu_state - (PAGE_GI_ITEMS + 1 - GI_ITEM_COUNT);
    item = item % GI_ITEM_COUNT;
    osd_menu_state = item + PAGE_GI_ITEMS;
  } while (osd_is_item_enabled(item) != 1);
  osd_highlight_item_row(osd_menu_state - PAGE_GI_ITEMS, 1);
  osd_draw_default_key_guide(osd_menu_state - PAGE_GI_ITEMS, 1);
  osd_draw_item_choices(PAGE_GI_ITEMS, osd_menu_state - PAGE_GI_ITEMS);
}
