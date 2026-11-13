/* osd_select_prev_scope_ratio  (FUN_a009bb0c)
 *
 * Move to the previous allowed Optix Scope ratio (up key) and apply it.
 * Note: Wraps inside the states 0xEA..0xEC; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: up on states 0xEA..0xEC; writes settings byte +0x4C, re-
 *   applies with sys_user_apply_second_picture_enable
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009bb0c @ 0xa009bb0c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - BASE + (COUNT - 1), taken modulo the count in a second statement;
 *  - the settings record is a byte array (ratio at +0x4C); osd_edit_value is read again for the compare and the
 *    mark row.
 */

#define MENU_STATE_SCOPE_RATIO_LIST 0xea        /* + row: the three Optix Scope ratios */
#define SCOPE_RATIO_COUNT           3
#define USER_SETTINGS_SCOPE_RATIO   0x4c        /* the Optix Scope ratio (user_settings_scope_ratio) */
#define CHOICE_MARK_LIST            1           /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON              1
#define CHOICE_MARK_OFF             0
#define CHOICE_ROW_EDGED            1           /* highlight style of a choice row */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit 1 of osd_request_bits */

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern unsigned char osd_request_bits;
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void sys_user_apply_second_picture_enable(int);
extern void sys_api_set_channel_timeout(int, int, int);

/*
 * Up key in the Optix Scope ratio list: move the highlight to the previous row, wrapping from the first row to the last.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The row number is stored as the Optix Scope ratio (+0x4C) at once, sys_user_apply_second_picture_enable(1) is
 * called, the settings-changed request bit is set in osd_request_bits and sys_api_set_channel_timeout(1, 0, 0)
 * is called. The mark is drawn at the row of the ratio saved on entry (osd_edit_value); it is switched off while
 * the highlight is on that row and on otherwise.
 */
void osd_select_prev_scope_ratio(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_SCOPE_RATIO_LIST);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_SCOPE_RATIO_LIST + (SCOPE_RATIO_COUNT - 1);
        row = row % SCOPE_RATIO_COUNT;
        osd_menu_state = row + MENU_STATE_SCOPE_RATIO_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    user_settings[USER_SETTINGS_SCOPE_RATIO] = osd_menu_state - MENU_STATE_SCOPE_RATIO_LIST;
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_SCOPE_RATIO_LIST, CHOICE_ROW_EDGED);
    sys_user_apply_second_picture_enable(1);
    if (osd_menu_state - MENU_STATE_SCOPE_RATIO_LIST == osd_edit_value)
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_edit_value, CHOICE_MARK_OFF);
    else
        osd_draw_choice_mark(CHOICE_MARK_LIST, osd_edit_value, CHOICE_MARK_ON);
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    sys_api_set_channel_timeout(1, 0, 0);
}
