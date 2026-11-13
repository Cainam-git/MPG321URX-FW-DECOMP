/* osd_enter_pbp_settings  (FUN_a00979ec)
 *
 * Switch to PBP and open its settings list on the current PBP mode.
 * Note: Settings states 0x7F..0x85 (Mode 1, Mode 2, Customize, Source 1, Source 2, ...); PBP mode = settings
 *   byte +0x2F.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x25 = 'PBP'; texts 0x18E89C / 0x182534
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00979ec @ 0xa00979ec-0xa0097ad0 (57 words), flags -mcpu=v8 -O3 -g.
 * Source form: same sequence as osd_enter_pip_settings, except that the menu state comes from the PBP layout
 * and the local is assigned from the menu state difference before osd_highlight_choice_row. The settings record
 * is a plain byte array. The routine has no parameters.
 */
extern unsigned char osd_saved_choice_value;
extern unsigned char osd_edit_value;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char osd_list_id;
extern unsigned char user_settings[];
extern void osd_apply_pip_pbp_mode(void);
extern void osd_commit_pip_pbp_layout(void);
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_item_highlight(unsigned char);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(int, int);
extern void osd_draw_adaptive_sync_status(void);
extern void sys_user_save_mode_slot(void);

#define USER_SETTINGS_PIP_PBP_MODE   0x1f       /* offset of the PIP/PBP mode byte (0 off, 1 PIP, 2 PBP) */
#define USER_SETTINGS_PBP_LAYOUT     0x2f       /* offset of the PBP layout byte */
#define USER_SETTINGS_SCREEN_SIZE    0x1a4      /* offset of the Screen Size byte */
#define PAGE_PIP_PBP_ITEMS           0x23       /* first item state of the PIP/PBP page; item row = state - 0x23 */
#define MENU_STATE_PBP_LIST          0x7f       /* + row: the PBP settings list (layouts 0..2, then Source 1, Source 2, ...) */
#define LIST_ID_PBP_ITEMS            0x10       /* osd_list_id value set before the PBP items are drawn */
#define CHOICE_MARK_ITEMS            0          /* list kind of osd_draw_choice_mark: an item list */
#define CHOICE_MARK_LIST             1          /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_OFF              0
#define HIGHLIGHT_ITEM_LIST_OPEN     2          /* item row highlight while its choice list is open */
#define CHOICE_ROW_EDGED             1          /* highlight style of a choice row in the open list */

/*
 * OK or right on the PBP item of the PIP/PBP page (menu state 0x25): switch to PBP and open its settings list on
 * the stored PBP layout.
 *
 * The first steps are those of osd_enter_pip_settings: the highlight and mark of the item that was active when
 * the PIP/PBP list opened (osd_choice_row) are removed, the mark of the stored layout is cleared, the present
 * item row is highlighted in the "list open" style, osd_apply_pip_pbp_mode stores the PBP layout and
 * osd_commit_pip_pbp_layout applies it when it changed. The menu state then becomes 0x7F plus the stored PBP
 * layout and that layout's row is highlighted.
 *
 * When the stored PIP/PBP mode differs from osd_choice_row, the Adaptive-Sync status line is redrawn. The mode is
 * then saved in osd_choice_row, the Screen Size in osd_edit_value and the PBP layout in osd_saved_choice_value,
 * osd_list_id becomes 0x10, and the mode slot is saved.
 */
void osd_enter_pbp_settings(void)
{
    unsigned char saved_mode;

    osd_clear_item_highlight(osd_choice_row);
    osd_draw_choice_mark(CHOICE_MARK_ITEMS, osd_choice_row, CHOICE_MARK_OFF);
    osd_draw_choice_mark(CHOICE_MARK_ITEMS, user_settings[USER_SETTINGS_PIP_PBP_MODE], CHOICE_MARK_OFF);
    osd_highlight_item_row(osd_menu_state - PAGE_PIP_PBP_ITEMS, HIGHLIGHT_ITEM_LIST_OPEN);
    osd_apply_pip_pbp_mode();
    osd_commit_pip_pbp_layout();
    osd_menu_state = user_settings[USER_SETTINGS_PBP_LAYOUT] + MENU_STATE_PBP_LIST;
    osd_draw_choice_mark(CHOICE_MARK_LIST, user_settings[USER_SETTINGS_PBP_LAYOUT], CHOICE_MARK_OFF);
    saved_mode = osd_menu_state - MENU_STATE_PBP_LIST;
    osd_highlight_choice_row(saved_mode, CHOICE_ROW_EDGED);
    saved_mode = user_settings[USER_SETTINGS_PIP_PBP_MODE];
    if (saved_mode != osd_choice_row) {
        osd_draw_adaptive_sync_status();
        saved_mode = user_settings[USER_SETTINGS_PIP_PBP_MODE];
    }
    osd_choice_row = saved_mode;
    osd_edit_value = user_settings[USER_SETTINGS_SCREEN_SIZE];
    osd_saved_choice_value = user_settings[USER_SETTINGS_PBP_LAYOUT];
    osd_list_id = LIST_ID_PBP_ITEMS;
    sys_user_save_mode_slot();
}
