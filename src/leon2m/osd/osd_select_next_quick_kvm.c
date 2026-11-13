/* osd_select_next_quick_kvm  (FUN_a00adc98)
 *
 * Move to the next row of the KVM quick menu (down key)
 * Note: Row = settings byte +0x17C, 3 rows, wraps.
 * Name basis: derived - handler table 0xA802422C: down on state 0x104 (Navi Key quick menu)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00adc98 @ 0xa00adc98, flags -mcpu=v8 -O3 -g. Reached through the key handler table only (no direct call).
 */
struct user_settings_record {
    unsigned char pad[0x17c];
    unsigned char kvm;
};
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_highlight_quick_menu_row(unsigned char item, unsigned char cursor);
extern void osd_draw_cell_run(unsigned int dir, unsigned int inc, unsigned int attribute, unsigned int column, unsigned int row, unsigned int count, unsigned int glyph);
extern void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width);

#define CELL_BLANK                   0x792
#define QUICK_MENU_FIRST_ROW         4       /* row of the first entry; entries are two rows apart */
#define QUICK_MENU_LAST_ROW          10      /* row of the fourth entry on a page */
#define QUICK_MENU_LEFT_EDGE         3       /* columns of the frame edges of an entry */
#define QUICK_MENU_RIGHT_EDGE        0x12
#define QUICK_MENU_EDGE_ROWS         3       /* rows high */
#define CELL_LOWER_LEFT              0x3092  /* cell value and glyph of the cell below the left edge of the last row */
#define LOWER_LEFT_GLYPH             0x11
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit of osd_request_bits */

/* Down key in the KVM quick menu (key table state 0x104): move to the next entry, three entries (0..2),
 * wrapping around. The entry is user_settings byte +0x17C (KVM).
 * The old entry is taken back first: the highlight window is switched off and the cells of its frame edges
 * (columns 3 and 0x12, three rows) are blanked; on the last row of a page the left edge is two cells and the
 * cell below it gets its lower-left glyph back.
 * Then the new entry is highlighted.
 * The settings-changed request bit is set at the end. */
void osd_select_next_quick_kvm(void)
{
    unsigned char entry_row;

    entry_row = (user_settings.kvm * 2 + QUICK_MENU_FIRST_ROW) & 0xff;
    osd_set_highlight_window(0, 0, 0, 0);

    if (entry_row == QUICK_MENU_LAST_ROW) {
        osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_LEFT_EDGE, QUICK_MENU_LAST_ROW, QUICK_MENU_EDGE_ROWS - 1, 0);
        osd_draw_cell_run(1, 0, CELL_LOWER_LEFT, QUICK_MENU_LEFT_EDGE, QUICK_MENU_LAST_ROW + 2, 1, LOWER_LEFT_GLYPH);
    } else {
        osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_LEFT_EDGE, entry_row, QUICK_MENU_EDGE_ROWS, 0);
    }

    osd_draw_cell_run(0, 0, CELL_BLANK, QUICK_MENU_RIGHT_EDGE, entry_row, QUICK_MENU_EDGE_ROWS, 0);

    user_settings.kvm = (user_settings.kvm + 1) % 3;
    osd_highlight_quick_menu_row(user_settings.kvm, 1);
    osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
