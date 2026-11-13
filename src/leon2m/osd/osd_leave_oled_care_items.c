/* osd_leave_oled_care_items  (FUN_a0092f2c)
 *
 * Leave the MSI OLED Care item list and return the highlight to its tab (left key)
 * Name basis: proven - key role from the menu state handler table 0xA802422C; labels from ROM text table
 *   0x185E78
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0092f2c, flags -mcpu=v8 -O3 -g.
 * Source form: an if/else-if chain with the shared calls written in both arms (the compiler merges the tails);
 * osd_highlight_tab is a tail call.
 */
#define TAB_STYLE_CURSOR       1        /* osd_highlight_tab: the cursor is on the tabs */
#define TAB_OLED_CARE          8
#define MENU_STATE_TAB_BASE    2        /* menu state of a tab row = 2 + tab number */
#define PAGE_OLED_CARE_ITEMS   0x34     /* menu state of the first item of the MSI OLED Care tab */
#define MENU_STATE_PANEL_PROTECT_ITEM 0x35      /* OLED Care item 1 */
#define MENU_STATE_PANEL_INFO_ITEM    0x3b      /* OLED Care item 7: OLED Panel Info. */
#define KEY_TEXT_MOVE          0        /* key guide texts: Move, Enter */
#define KEY_TEXT_ENTER         1

extern unsigned int osd_menu_state;
extern unsigned char user_settings_key_guide_shown;
extern void osd_clear_item_highlight(unsigned char);
extern void osd_draw_tab_page(unsigned char id);
extern void osd_draw_adjust_key_guide(void);
extern void osd_draw_key_guide(unsigned char sel, unsigned char mode);
extern void osd_update_key_guide(unsigned char hi, unsigned char lo);
extern void osd_highlight_tab(unsigned char, int);

/*
 * Left key in the MSI OLED Care item list: take the highlight off the item, redraw the tab's page, set the key
 * guide for the tab row (Move, Enter) and put the menu state and the highlight back on the OLED Care tab row.
 *
 * The key guide is redrawn only when the list is left from item 1 or from OLED Panel Info.; leaving from the
 * latter also draws the adjust key guide. Settings byte +0x189 holds the key guide texts shown last and
 * osd_update_key_guide redraws only a text that differs from the stored one, so 0xFF makes it redraw both.
 */
void osd_leave_oled_care_items(void)
{
    osd_clear_item_highlight(osd_menu_state - PAGE_OLED_CARE_ITEMS);
    osd_draw_tab_page(TAB_OLED_CARE);
    if (osd_menu_state == MENU_STATE_PANEL_INFO_ITEM) {
        user_settings_key_guide_shown = 0xff;
        osd_draw_adjust_key_guide();
        osd_draw_key_guide(2, 5);
        osd_draw_key_guide(0, 0);
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    } else if (osd_menu_state == MENU_STATE_PANEL_PROTECT_ITEM) {
        osd_draw_key_guide(1, 2);
        osd_update_key_guide(KEY_TEXT_MOVE, KEY_TEXT_ENTER);
    }
    osd_menu_state = MENU_STATE_TAB_BASE + TAB_OLED_CARE;
    osd_highlight_tab(TAB_OLED_CARE, TAB_STYLE_CURSOR);
}
