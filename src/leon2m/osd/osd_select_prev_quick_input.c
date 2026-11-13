/* osd_select_prev_quick_input  (FUN_a00aea3c)
 *
 * Move to the previous row of the input quick menu (up key)
 * Note: Row = settings byte +0x1A3, 4 rows, wraps.
 * Name basis: derived - handler table 0xA802422C: up on state 0xFE (Navi Key quick menu)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00aea3c @ 0xa00aea3c, flags -mcpu=v8 -O3 -g. Reached through the key handler table only.
 * Source form: word +0 and byte +0x1a3 of user_settings are members of one record, so both addresses share one
 * high-address register. The row is held in a local and masked with 0xff.
 */
struct user_settings_record {
    unsigned int word_0x0;                  /* +0 */
    unsigned char pad4[0x1a3 - 4];
    unsigned char quick_menu_input;         /* +0x1A3 */
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width);
extern void osd_draw_cell_run(unsigned int dir, unsigned int inc, unsigned int attribute, unsigned int column, unsigned int row, unsigned int count, unsigned int glyph);
extern void osd_highlight_quick_menu_row(unsigned char item, unsigned char cursor);
extern unsigned char sys_api_get_channel_state_code(unsigned char channel);
extern void sys_app_timer_start(int id, int ms);
extern void osd_set_seconds_countdown(unsigned short seconds);

#define CELL_BLANK                   0x792
#define QUICK_MENU_FIRST_ROW         4       /* row of the first entry; entries are two rows apart */
#define QUICK_MENU_LAST_ROW          10      /* row of the fourth entry */
#define QUICK_MENU_LEFT_EDGE         3       /* columns of the frame edges of an entry */
#define QUICK_MENU_RIGHT_EDGE        0x12
#define QUICK_MENU_EDGE_ROWS         3       /* rows high */
#define CELL_LOWER_LEFT              0x3092  /* cell value and glyph of the cell below the left edge of the last row */
#define LOWER_LEFT_GLYPH             0x11
#define QUICK_MENU_ENTRIES_MASK      3       /* four entries */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit of osd_request_bits */
#define CHANNEL_CODE_LAST            10      /* state code of channel 0 that skips the timer start */
#define SETTINGS_WORD0_BIT9          0x200
#define APP_TIMER_INPUT_QUICK_MENU   0xb     /* application timer restarted for 10000 ms */
#define INPUT_QUICK_MENU_TIMEOUT_MS  10000
#define INPUT_QUICK_MENU_COUNTDOWN   10      /* seconds given to osd_set_seconds_countdown */

/* Up key in the Input quick menu (key table state 0xFE): move to the previous of the four entries, wrapping
 * around. The entry is user_settings byte +0x1A3; its position in the list is
 * input_api_source_id_to_menu_index(byte) and the previous value is stored back through
 * input_api_menu_index_to_source_id.
 * The old entry is taken back first: the highlight window is switched off and the cells of its frame edges
 * (columns 3 and 0x12, three rows) are blanked; on the last row the left edge is two cells and the cell below
 * it gets its lower-left glyph back. Then the new entry is highlighted.
 * Unless channel 0 reports state code 10 or bit 9 of user_settings word 0 is set, application timer 0xB is
 * restarted for 10000 ms. The settings-changed request bit is set and the menu's one-second countdown is set to 10. */
void osd_select_prev_quick_input(void)
{
    unsigned char entry_row;

    entry_row = (input_api_source_id_to_menu_index(user_settings.quick_menu_input) * 2 + QUICK_MENU_FIRST_ROW) & 0xff;
    osd_set_highlight_window(0, 0, 0, 0);

    if (entry_row == QUICK_MENU_LAST_ROW) {
        osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_LEFT_EDGE, QUICK_MENU_LAST_ROW, QUICK_MENU_EDGE_ROWS - 1, 0);
        osd_draw_cell_run(1, 0, CELL_LOWER_LEFT, QUICK_MENU_LEFT_EDGE, QUICK_MENU_LAST_ROW + 2, 1, LOWER_LEFT_GLYPH);
    } else {
        osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_LEFT_EDGE, entry_row, QUICK_MENU_EDGE_ROWS, 0);
    }

    osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_RIGHT_EDGE, entry_row, QUICK_MENU_EDGE_ROWS, 0);

    user_settings.quick_menu_input = input_api_menu_index_to_source_id((input_api_source_id_to_menu_index(user_settings.quick_menu_input) + 3) & QUICK_MENU_ENTRIES_MASK);
    osd_highlight_quick_menu_row(input_api_source_id_to_menu_index(user_settings.quick_menu_input), 1);
    if (sys_api_get_channel_state_code(0) != CHANNEL_CODE_LAST && !(user_settings.word_0x0 & SETTINGS_WORD0_BIT9))
        sys_app_timer_start(APP_TIMER_INPUT_QUICK_MENU, INPUT_QUICK_MENU_TIMEOUT_MS);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
    osd_set_seconds_countdown(INPUT_QUICK_MENU_COUNTDOWN);
}
