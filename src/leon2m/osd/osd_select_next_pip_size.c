/* osd_select_next_pip_size  (FUN_a009b070)
 *
 * Move to the next allowed PIP size (down key) and apply it.
 * Note: Wraps inside the states 0xCD..0xCF; skips entries osd_is_choice_enabled rejects.
 * Name basis: derived - handler table 0xA802422C: down on states 0xCD..0xCF; writes settings byte +0x31, re-
 *   applies with sys_user_rebuild_window_channel1; texts 0x18F550
 *
 * Matching notes
 * --------------
 * leon2m FUN_a009b070 @ 0xa009b070, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the walk is (u16)state - BASE + 1, taken modulo the count in a second statement;
 *  - the stored size is written as 2 - row in the settings record, a byte array (+0x31); the same expression is
 *    repeated in the compare and in the mark row.
 */

#define CHOICE_MARK_LIST        1       /* list kind of osd_draw_choice_mark: a choice list */
#define CHOICE_MARK_ON          1
#define CHOICE_MARK_OFF         0
#define CHOICE_ROW_EDGED        1       /* highlight style of a choice row */

#define MENU_STATE_PIP_SIZE_LIST    0xcd        /* + row: the three PIP sizes of the list */
#define PIP_SIZE_COUNT              3
#define USER_SETTINGS_PIP_SIZE      0x31        /* the PIP size (0..2); the list rows run the other way: row = 2 - size */
#define PIP_SIZE_LAST               2

extern unsigned char osd_edit_value;
extern unsigned int osd_menu_state;
extern unsigned char user_settings[];
extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_clear_choice_highlight(unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern unsigned char osd_is_choice_enabled(unsigned char);
extern void sys_user_rebuild_window_channel1(void);

/*
 * Down key in the PIP size list: move the highlight to the next row, wrapping from the last row to the first.
 * Rows that osd_is_choice_enabled rejects are skipped.
 *
 * The size stored in the settings record (+0x31) is 2 minus the highlighted row; the window of channel 1 is
 * rebuilt at once. The mark is drawn at the row of the size saved on entry (osd_edit_value); it is switched off
 * while the highlight is on that row and on otherwise.
 */
void osd_select_next_pip_size(void)
{
    int row;

    osd_clear_choice_highlight(osd_menu_state - MENU_STATE_PIP_SIZE_LIST);
    do {
        row = (unsigned short)osd_menu_state - MENU_STATE_PIP_SIZE_LIST + 1;
        row = row % PIP_SIZE_COUNT;
        osd_menu_state = row + MENU_STATE_PIP_SIZE_LIST;
    } while (osd_is_choice_enabled(row) != 1);
    user_settings[USER_SETTINGS_PIP_SIZE] = PIP_SIZE_LAST - (osd_menu_state - MENU_STATE_PIP_SIZE_LIST);
    osd_highlight_choice_row(osd_menu_state - MENU_STATE_PIP_SIZE_LIST, CHOICE_ROW_EDGED);
    sys_user_rebuild_window_channel1();
    if (PIP_SIZE_LAST - (osd_menu_state - MENU_STATE_PIP_SIZE_LIST) == osd_edit_value)
        osd_draw_choice_mark(CHOICE_MARK_LIST, PIP_SIZE_LAST - osd_edit_value, CHOICE_MARK_OFF);
    else
        osd_draw_choice_mark(CHOICE_MARK_LIST, PIP_SIZE_LAST - osd_edit_value, CHOICE_MARK_ON);
}
