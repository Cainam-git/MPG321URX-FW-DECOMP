/* osd_enter_pip_settings  (FUN_a00978c8)
 *
 * Switch to PIP and open its settings list (Source, Size, Location, ...)
 * Note: Settings states 0x7A..0x7E.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x24 = 'PIP'; texts 0x1828C0: Source, PIP
 *   Size, Location, Display Switch, Audio Switch
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00978c8 @ 0xa00978c8-0xa0097988 (48 words), flags -mcpu=v8 -O3 -g.
 * Source form: one local (saved_layout) is assigned twice, once before the test and once after
 * osd_draw_adaptive_sync_status: the second assignment is why the firmware keeps an 'and 0xff' after the byte
 * load. The settings record is a plain (non-volatile) byte array. The routine has no parameters.
 */
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
#define USER_SETTINGS_SCREEN_SIZE    0x1a4      /* offset of the Screen Size byte */
#define PAGE_PIP_PBP_ITEMS           0x23       /* first item state of the PIP/PBP page; item row = state - 0x23 */
#define MENU_STATE_PIP_LIST          0x7a       /* + row: the PIP settings list (Source, PIP Size, Location, ...) */
#define LIST_ID_PIP_ITEMS            0x0f       /* osd_list_id value set before the PIP items are drawn */
#define CHOICE_MARK_ITEMS            0          /* list kind of osd_draw_choice_mark: an item list */
#define CHOICE_MARK_OFF              0
#define HIGHLIGHT_ITEM_LIST_OPEN     2          /* item row highlight while its choice list is open */
#define CHOICE_ROW_EDGED_NO_GUIDE    3          /* as the edged style, key guide left as it is */

/*
 * OK or right on the PIP item of the PIP/PBP page (menu state 0x24): switch to PIP and open its settings list.
 *
 * The highlight and mark of the item that was active when the PIP/PBP list opened (osd_choice_row) are removed,
 * the mark of the stored layout is cleared, and the present item row is highlighted in the "list open" style.
 * osd_apply_pip_pbp_mode stores the PIP layout and osd_commit_pip_pbp_layout applies it when it changed. The menu
 * state becomes 0x7A (first row of the PIP list) with choice row 0 highlighted.
 *
 * When the stored layout differs from osd_choice_row, the Adaptive-Sync status line is redrawn. The stored layout
 * is then saved in osd_choice_row and the Screen Size in osd_edit_value (osd_apply_pip_pbp_mode puts it back when
 * PIP/PBP is switched off), osd_list_id becomes 0xF, and the mode slot is saved.
 */
void osd_enter_pip_settings(void)
{
    unsigned char saved_layout;

    osd_clear_item_highlight(osd_choice_row);
    osd_draw_choice_mark(CHOICE_MARK_ITEMS, osd_choice_row, CHOICE_MARK_OFF);
    osd_draw_choice_mark(CHOICE_MARK_ITEMS, user_settings[USER_SETTINGS_PIP_PBP_MODE], CHOICE_MARK_OFF);
    osd_highlight_item_row(osd_menu_state - PAGE_PIP_PBP_ITEMS, HIGHLIGHT_ITEM_LIST_OPEN);
    osd_apply_pip_pbp_mode();
    osd_commit_pip_pbp_layout();
    osd_menu_state = MENU_STATE_PIP_LIST;
    osd_highlight_choice_row(0, CHOICE_ROW_EDGED_NO_GUIDE);
    saved_layout = user_settings[USER_SETTINGS_PIP_PBP_MODE];
    if (saved_layout != osd_choice_row) {
        osd_draw_adaptive_sync_status();
        saved_layout = user_settings[USER_SETTINGS_PIP_PBP_MODE];
    }
    osd_choice_row = saved_layout;
    osd_edit_value = user_settings[USER_SETTINGS_SCREEN_SIZE];
    osd_list_id = LIST_ID_PIP_ITEMS;
    sys_user_save_mode_slot();
}
