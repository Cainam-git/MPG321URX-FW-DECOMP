/* osd_select_prev_quick_night_vision  (FUN_a00ae020)
 *
 * Move to the previous row of the night vision quick menu (up key) and apply it.
 * Note: Row = settings byte +0x15B, 5 rows, wraps.
 * Name basis: derived - handler table 0xA802422C: up on state 0x102 (Navi Key quick menu)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ae020 @ 0xa00ae020, flags -mcpu=v8 -O3 -g. Reached through the key handler table only (no direct call).
 */
struct user_settings_record {
    unsigned char pad[0x15b];
    unsigned char night_vision;
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_highlight_quick_menu_row(unsigned char item, unsigned char cursor);
extern void osd_draw_night_vision_quick_menu(unsigned char page);
extern void osd_draw_cell_run(unsigned int dir, unsigned int inc, unsigned int attribute, unsigned int column, unsigned int row, unsigned int count, unsigned int glyph);
extern void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width);
extern void sys_user_apply_dimming_mode(void);
extern void sys_user_save_mode_slot(void);

#define CELL_BLANK                   0x792
#define QUICK_MENU_FIRST_ROW         4       /* row of the first entry; entries are two rows apart */
#define QUICK_MENU_LAST_ROW          10      /* row of the fourth entry on a page */
#define QUICK_MENU_LEFT_EDGE         3       /* columns of the frame edges of an entry */
#define QUICK_MENU_RIGHT_EDGE        0x12
#define QUICK_MENU_EDGE_ROWS         3       /* rows high */
#define CELL_LOWER_LEFT              0x3092  /* cell value and glyph of the cell below the left edge of the last row */
#define LOWER_LEFT_GLYPH             0x11
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit of osd_request_bits */

/* Up key in the Night Vision quick menu (key table state 0x102): move to the previous entry, five entries (0..4),
 * wrapping around. The entry is user_settings byte +0x15B (Night Vision).
 * Its low two bits give the row on a page of four entries.
 * The old entry is taken back first: the highlight window is switched off and the cells of its frame edges
 * (columns 3 and 0x12, three rows) are blanked; on the last row of a page the left edge is two cells and the
 * cell below it gets its lower-left glyph back.
 * When the new entry is 3 or 4, the list page entry / 4 is redrawn first (page 0 holds entries 0..3).
 * Then the new entry is highlighted, the dimming mode is sent (sys_user_apply_dimming_mode)
 * and the picture settings are copied into the slot of the picture mode (sys_user_save_mode_slot).
 * The settings-changed request bit is set at the end. */
void osd_select_prev_quick_night_vision(void)
{
    unsigned char entry_row;

    entry_row = ((user_settings.night_vision & 3) * 2 + QUICK_MENU_FIRST_ROW) & 0xff;
    osd_set_highlight_window(0, 0, 0, 0);

    if (entry_row == QUICK_MENU_LAST_ROW) {
        osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_LEFT_EDGE, QUICK_MENU_LAST_ROW, QUICK_MENU_EDGE_ROWS - 1, 0);
        osd_draw_cell_run(1, 0, CELL_LOWER_LEFT, QUICK_MENU_LEFT_EDGE, QUICK_MENU_LAST_ROW + 2, 1, LOWER_LEFT_GLYPH);
    } else {
        osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_LEFT_EDGE, entry_row, QUICK_MENU_EDGE_ROWS, 0);
    }

    osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_RIGHT_EDGE, entry_row, QUICK_MENU_EDGE_ROWS, 0);

    user_settings.night_vision = (user_settings.night_vision + 4) % 5;
    if (user_settings.night_vision == 3 || user_settings.night_vision == 4)
        osd_draw_night_vision_quick_menu(user_settings.night_vision / 4);
    osd_highlight_quick_menu_row(user_settings.night_vision & 3, 1);
    sys_user_apply_dimming_mode();
    sys_user_save_mode_slot();
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
