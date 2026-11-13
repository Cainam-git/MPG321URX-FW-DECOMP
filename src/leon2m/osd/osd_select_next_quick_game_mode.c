/* osd_select_next_quick_game_mode  (FUN_a00ae638)
 *
 * Move to the next row of the game mode quick menu (down key) and apply it.
 * Note: Row = settings byte +0x182, 6 rows, wraps.
 * Name basis: derived - handler table 0xA802422C: down on state 0xFB (Navi Key quick menu)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ae638 @ 0xa00ae638, flags -mcpu=v8 -O3 -g. Reached through the key handler table only.
 * Source form: the divisor 6 is held in a local (the firmware divides by the immediate 6 with a signed divide
 * instruction; a literal divisor would be expanded into a multiplication).
 */
struct user_settings_record {
    unsigned char pad[0x182];
    unsigned char game_mode;
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_highlight_quick_menu_row(unsigned char item, unsigned char cursor);
extern void osd_draw_game_mode_quick_menu(unsigned char page);
extern void osd_draw_cell_run(unsigned int dir, unsigned int inc, unsigned int attribute, unsigned int column, unsigned int row, unsigned int count, unsigned int glyph);
extern void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width);
extern void UserSetGameMode(void);

#define CELL_BLANK                   0x792
#define QUICK_MENU_FIRST_ROW         4       /* row of the first entry; entries are two rows apart */
#define QUICK_MENU_LAST_ROW          10      /* row of the fourth entry on a page */
#define QUICK_MENU_LEFT_EDGE         3       /* columns of the frame edges of an entry */
#define QUICK_MENU_RIGHT_EDGE        0x12
#define QUICK_MENU_EDGE_ROWS         3       /* rows high */
#define CELL_LOWER_LEFT              0x3092  /* cell value and glyph of the cell below the left edge of the last row */
#define LOWER_LEFT_GLYPH             0x11
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit of osd_request_bits */
#define QUICK_MENU_ENTRIES           6       /* Premium Color, User, FPS, Racing, RTS, RPG */

/* Down key in the Game Mode quick menu (key table state 0xFB): move to the next entry, six entries (0..5),
 * wrapping around. The entry is user_settings byte +0x182 (Game Mode); its low two bits give the row on a page
 * of four entries.
 * The old entry is taken back first: the highlight window is switched off and the cells of its frame edges
 * (columns 3 and 0x12, three rows) are blanked; on the last row of a page the left edge is two cells and the
 * cell below it gets its lower-left glyph back.
 * When the new entry is 4 or 0, the list page entry / 4 is redrawn first (page 0 holds entries 0..3).
 * Then the new entry is highlighted and the game mode is applied (UserSetGameMode).
 * The settings-changed request bit is set at the end. */
void osd_select_next_quick_game_mode(void)
{
    unsigned char entry_row;
    unsigned char entries = QUICK_MENU_ENTRIES;

    entry_row = ((user_settings.game_mode & 3) * 2 + QUICK_MENU_FIRST_ROW) & 0xff;
    osd_set_highlight_window(0, 0, 0, 0);

    if (entry_row == QUICK_MENU_LAST_ROW) {
        osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_LEFT_EDGE, QUICK_MENU_LAST_ROW, QUICK_MENU_EDGE_ROWS - 1, 0);
        osd_draw_cell_run(1, 0, CELL_LOWER_LEFT, QUICK_MENU_LEFT_EDGE, QUICK_MENU_LAST_ROW + 2, 1, LOWER_LEFT_GLYPH);
    } else {
        osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_LEFT_EDGE, entry_row, QUICK_MENU_EDGE_ROWS, 0);
    }

    osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_RIGHT_EDGE, entry_row, QUICK_MENU_EDGE_ROWS, 0);

    user_settings.game_mode = (user_settings.game_mode + 1) % entries;
    if (user_settings.game_mode == 4 || user_settings.game_mode == 0)
        osd_draw_game_mode_quick_menu(user_settings.game_mode / 4);
    osd_highlight_quick_menu_row(user_settings.game_mode & 3, 1);
    UserSetGameMode();
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
