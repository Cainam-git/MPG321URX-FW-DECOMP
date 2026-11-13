/* osd_select_pip_pbp_off  (FUN_a0097814)
 *
 * Switch PIP/PBP off and return to the PIP/PBP tab (OK on OFF)
 * Note: Redraws the tab list when the layout changed.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x23; texts 0x196678 OFF, PIP, PBP
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097814 @ 0xa0097814-0xa00978c8 (45 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through the handler table).
 * Source form: the settings record is a byte array; the callees are declared with byte or unsigned parameters
 * as below.
 */
extern unsigned char user_settings[];
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern void osd_clear_item_highlight(unsigned char);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_apply_pip_pbp_mode(void);
extern void osd_commit_pip_pbp_layout(void);
extern void osd_highlight_tab(unsigned char, int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void osd_draw_adaptive_sync_status(void);

#define USER_SETTINGS_PIP_PBP_MODE   0x1f       /* offset of the PIP/PBP mode byte (0 off, 1 PIP, 2 PBP) */
#define PAGE_PIP_PBP_ITEMS           0x23       /* first item state of the PIP/PBP page; item row = state - 0x23 */
#define MENU_STATE_TAB_PIP_PBP       7          /* menu state of the PIP/PBP tab (tab 5, state = 2 + tab) */
#define TAB_PIP_PBP                  5
#define TAB_STYLE_CURSOR             1          /* osd_highlight_tab: the cursor is on the tabs */
#define CHOICE_MARK_ITEMS            0          /* list kind of osd_draw_choice_mark: an item list */
#define CHOICE_MARK_ON               1
#define CHOICE_MARK_OFF              0
#define HIGHLIGHT_ITEM_MODE_0        0          /* mode 0 of osd_highlight_item_row */

/*
 * OK on the OFF item of the PIP/PBP page (menu state 0x23): switch PIP/PBP off and return to the PIP/PBP tab.
 *
 * The highlight and mark of the item that was active when the list opened (osd_choice_row) are removed, the
 * present item row is highlighted in mode 0, then osd_apply_pip_pbp_mode stores the layout of the present menu
 * state and osd_commit_pip_pbp_layout applies it when it changed. The mark of the stored layout is drawn, the
 * menu state returns to the PIP/PBP tab (state 7) with the tab highlighted and the key guide redrawn.
 * The Adaptive-Sync status line is redrawn when the stored layout differs from osd_choice_row.
 */
void osd_select_pip_pbp_off(void)
{
    osd_clear_item_highlight(osd_choice_row);
    osd_draw_choice_mark(CHOICE_MARK_ITEMS, osd_choice_row, CHOICE_MARK_OFF);
    osd_highlight_item_row(osd_menu_state - PAGE_PIP_PBP_ITEMS, HIGHLIGHT_ITEM_MODE_0);
    osd_apply_pip_pbp_mode();
    osd_commit_pip_pbp_layout();
    osd_draw_choice_mark(CHOICE_MARK_ITEMS, user_settings[USER_SETTINGS_PIP_PBP_MODE], CHOICE_MARK_ON);
    osd_menu_state = MENU_STATE_TAB_PIP_PBP;
    osd_highlight_tab(TAB_PIP_PBP, TAB_STYLE_CURSOR);
    osd_draw_key_guide(1, 2);
    osd_update_key_guide(0, 1);
    if (user_settings[USER_SETTINGS_PIP_PBP_MODE] != osd_choice_row)
        osd_draw_adaptive_sync_status();
}
