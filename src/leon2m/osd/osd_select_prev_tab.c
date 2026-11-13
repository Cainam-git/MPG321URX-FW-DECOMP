/* osd_select_prev_tab  (FUN_a00912ac)
 *
 * Move the main menu highlight to the previous enabled tab (up key)
 * Note: Tabs G.I. .. MSI OLED Care are states 2..10; state 1 is an extra top entry when settings bit 14 is
 *   set.
 * Name basis: proven - steps the menu state down with wrap, skipping tabs osd_is_tab_enabled rejects; redraws
 *   the tab column; key role from the menu state handler table 0xA802422C, tab texts 0x196DC0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00912ac @ 0xa00912ac-0xa009145c (108 words), flags -mcpu=v8 -O3 -g.
 * Same form as osd_select_next_tab. Source form the exact build depends on: the new tab index k is computed as
 * ((unsigned short)state + 6) % 9 in an int, stored as k + 2, and the enabled test uses k.
 */

/* The main menu's tab column. While a tab is highlighted the menu state is 2..10 and the tab index is
   state - 2. The column shows tabs 0..6 on its first page and tabs 7..8 on its second page. State 1 is one more
   entry above the first tab, reachable only while the factory mode flag is set. */
#define MENU_STATE_TOP_ENTRY        1
#define MENU_STATE_FIRST_TAB        2
#define MENU_STATE_LAST_TAB_PAGE_0  8       /* tab 6, the last tab of the first page */
#define MENU_STATE_FIRST_TAB_PAGE_1 9       /* tab 7, the first tab of the second page */
#define MENU_STATE_LAST_TAB         10
#define TAB_STATE_OFFSET            2       /* tab index = menu state - 2 */
#define TAB_COUNT                   9
#define TAB_PAGE_0                  0
#define TAB_PAGE_1                  1

#define SETTINGS_WORD0_FACTORY_MODE 0x4000  /* user settings word +0, bit 14: the factory mode flag */

/* Fill values written to cell column 1 of the top entry by osd_api_fill_cells. */
#define TOP_ENTRY_FILL_REACHED      0x592   /* written when the top entry is reached */
#define TOP_ENTRY_FILL_LEFT         0x792   /* written when the top entry is left */

extern unsigned int osd_menu_state;
extern unsigned int user_settings;
extern void osd_clear_tab_highlight(unsigned char);
extern unsigned char osd_is_tab_enabled(unsigned char);
extern void osd_clear_tab_column(void);
extern void osd_draw_tab_icons(unsigned char);
extern void osd_draw_tab_names(unsigned char);
extern void osd_highlight_tab(unsigned char, int);
extern void osd_draw_tab_page(unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

/* Up key in the main menu: move the highlight to the previous enabled tab, wrapping round. Reads and writes
 * osd_menu_state; no parameters, no result.
 *  - From the first tab, with the factory mode flag set, the highlight goes to the top entry (state 1): the
 *    tab highlight is cleared and cell (1, 5) gets TOP_ENTRY_FILL_REACHED.
 *  - From the top entry the highlight wraps to the last tab (state 10): the tab column is redrawn with its
 *    second page, cell (1, 5) gets TOP_ENTRY_FILL_LEFT, the tab is highlighted and its page drawn.
 *  - Otherwise the highlight of the current tab is cleared and the state steps down by one tab, wrapping from
 *    the first tab to the last, until osd_is_tab_enabled accepts the tab (disabled tabs are skipped). When
 *    the new state is 8 or 10 the tab column is cleared and redrawn with the icons and names of page 0 or
 *    page 1. Then the new tab is highlighted and its page drawn.
 */
void osd_select_prev_tab(void)
{
    int k;

    if (osd_menu_state == MENU_STATE_FIRST_TAB && (user_settings & SETTINGS_WORD0_FACTORY_MODE)) {
        osd_clear_tab_highlight(0);
        osd_api_fill_cells(1, 5, 1, TOP_ENTRY_FILL_REACHED, 0);
        osd_menu_state = MENU_STATE_TOP_ENTRY;
        return;
    }
    if (osd_menu_state == MENU_STATE_TOP_ENTRY && (user_settings & SETTINGS_WORD0_FACTORY_MODE)) {
        osd_clear_tab_column();
        osd_draw_tab_icons(TAB_PAGE_1);
        osd_draw_tab_names(TAB_PAGE_1);
        osd_menu_state = MENU_STATE_LAST_TAB;
        osd_api_fill_cells(1, 5, 1, TOP_ENTRY_FILL_LEFT, 0);
        osd_highlight_tab(osd_menu_state - TAB_STATE_OFFSET, 1);
        osd_draw_tab_page(osd_menu_state - TAB_STATE_OFFSET);
        return;
    }
    osd_clear_tab_highlight(osd_menu_state - TAB_STATE_OFFSET);
    do {
        /* tab index one lower, wrapping: (state - 2 + 8) % 9 */
        k = ((unsigned short)osd_menu_state + 6) % TAB_COUNT;
        osd_menu_state = k + TAB_STATE_OFFSET;
    } while (osd_is_tab_enabled(k) != 1);
    if (osd_menu_state == MENU_STATE_LAST_TAB_PAGE_0) {
        osd_clear_tab_column();
        osd_draw_tab_icons(TAB_PAGE_0);
        osd_draw_tab_names(TAB_PAGE_0);
    } else if (osd_menu_state == MENU_STATE_LAST_TAB) {
        osd_clear_tab_column();
        osd_draw_tab_icons(TAB_PAGE_1);
        osd_draw_tab_names(TAB_PAGE_1);
    }
    osd_highlight_tab(osd_menu_state - TAB_STATE_OFFSET, 1);
    osd_draw_tab_page(osd_menu_state - TAB_STATE_OFFSET);
}
