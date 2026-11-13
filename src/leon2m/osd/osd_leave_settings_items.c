/* osd_leave_settings_items  (FUN_a0092bb4)
 *
 * Leave the Settings item list and return the highlight to its tab (left key)
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x1874F8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092bb4, flags -mcpu=v8 -O3 -g.
 * Source form: the common tail after the if is duplicated by the compiler into both paths; osd_highlight_tab is
 * a tail call.
 */
#define TAB_STYLE_CURSOR       1        /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_SETTINGS           7
#define MENU_STATE_TAB_BASE    2        /* menu state of a tab row = 2 + tab number */
#define PAGE_SETTINGS_ITEMS    0x2a     /* menu state of the first item of the Settings tab */
#define SETTINGS_ITEMS_PER_PAGE 7       /* items shown at once; the later ones are on a second page */

extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern void osd_draw_settings_item_state(unsigned char, int);
extern void osd_draw_item_choices(unsigned short page, unsigned char sel);
extern void osd_draw_tab_page(unsigned char id);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_tab(unsigned char, int);

/*
 * Left key in the Settings item list: take the highlight and the switch state drawing off the current item,
 * redraw the tab's page when the item was beyond the first seven, draw the choices of item 0 and call
 * osd_highlight_item_row(0, 0), then put the menu state and the highlight back on the Settings tab row.
 */
void osd_leave_settings_items(void)
{
    osd_clear_item_highlight(osd_menu_state - PAGE_SETTINGS_ITEMS);
    osd_draw_settings_item_state(osd_menu_state - PAGE_SETTINGS_ITEMS, 0);
    if (osd_menu_state - PAGE_SETTINGS_ITEMS > SETTINGS_ITEMS_PER_PAGE - 1)
        osd_draw_tab_page(TAB_SETTINGS);
    osd_draw_item_choices(PAGE_SETTINGS_ITEMS, 0);
    osd_highlight_item_row(0, 0);
    osd_menu_state = MENU_STATE_TAB_BASE + TAB_SETTINGS;
    osd_highlight_tab(TAB_SETTINGS, TAB_STYLE_CURSOR);
}
