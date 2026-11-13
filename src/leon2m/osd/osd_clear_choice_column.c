/* osd_clear_choice_column  (FUN_a00a8c88)
 *
 * Clear the choice column (rows 5..0x14) and its highlight windows.
 * Name basis: derived - called by many accept/cancel handlers; menu columns: tabs 1..0x12, items 0x14..,
 *   choices 0x27.., key guide 0x37..
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a8c88 @ 0xa00a8c88, flags -mcpu=v8 -O3 -g.
 * Source form: the set of menu states is a static helper with one 'return 1' per range and a final 'return 0'
 * (inlined); a set of two disjoint parts is one || test, so GCC evaluates both parts as flag values. The test on
 * the menu state inside the loop is two separate calls of osd_get_menu_state joined by ||.
 */
struct user_settings_head { unsigned char pad_0x0[8]; unsigned char language; };
extern struct user_settings_head user_settings;
extern void panel_wait_sync_pulse(void);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_api_set_window_enable(int, int, int);
extern unsigned short osd_get_menu_state(void);
extern void osd_set_highlight_window(unsigned char, unsigned char, unsigned int, unsigned int);

#define CHOICE_COLUMN        0x27       /* first column of the choice column */
#define CHOICE_FIRST_ROW     5          /* first cell row cleared */
#define CHOICE_LAST_ROW      0x14       /* last cell row cleared; this row is only 12 cells wide */
#define CHOICE_WIDTH         0xe        /* cells cleared per row */
#define CHOICE_BLANK_ATTR    0x796      /* attribute of a cleared cell */
#define LANGUAGE_13          0xd        /* language setting (byte +8) that also clears column 0x26 of row 12 */
#define WINDOW_CHOICE_PLAIN  4          /* the two choice highlight windows (see osd_highlight_choice_row) */
#define WINDOW_5             5

/*
 * True for the menu states in which clearing the choice column also switches the highlight window off:
 * 63..64, 67, 68..69, 111, 122..124, 130..131, 204..220 and 231..239.
 */
static unsigned char state_has_highlight_window(unsigned int state)
{
    if (state >= 63 && state <= 64)
        return 1;
    if (state == 67 || (state >= 237 && state <= 239))
        return 1;
    if (state >= 68 && state <= 69)
        return 1;
    if (state >= 231 && state <= 236)
        return 1;
    if (state == 111 || state == 204)
        return 1;
    if (state >= 122 && state <= 124)
        return 1;
    if (state >= 205 && state <= 207)
        return 1;
    if (state >= 208 && state <= 211)
        return 1;
    if (state >= 216 && state <= 220)
        return 1;
    if (state >= 130 && state <= 131)
        return 1;
    if (state >= 212 && state <= 215)
        return 1;
    return 0;
}

/*
 * Empty the choice column of the main menu (columns 0x27..0x34, cell rows 5..0x14) and switch its two
 * highlight windows off. Takes and returns nothing.
 *
 * Order: wait (panel_wait_sync_pulse); for each of the rows 5..0x14 clear the glyph plane 0 and set the
 * blank attribute 0x796 over 14 cells (12 cells in the last row); in row 12 one more cell at column 0x26 is
 * cleared when the language setting is 13 (the menu-state test beside it, "above 0x33 or at most 0x3b", is true
 * for every state). Then two cells at column 0x2d, row 0x15 of plane 0 are cleared, the windows 5 and 4 are
 * switched off and, for the menu states listed in state_has_highlight_window, the highlight window over the
 * column is switched off too.
 *
 * Called by many handlers that accept or cancel a choice list.
 */
void osd_clear_choice_column(void)
{
    unsigned char row, width, in_set;
    unsigned int state;

    panel_wait_sync_pulse();
    for (row = CHOICE_FIRST_ROW; row <= CHOICE_LAST_ROW; row++) {
        width = row == CHOICE_LAST_ROW ? 0xc : CHOICE_WIDTH;
        osd_api_fill_cell_bytes(0, CHOICE_COLUMN, row, width, 0, 0);
        osd_api_fill_cells(CHOICE_COLUMN, row, width, CHOICE_BLANK_ATTR, 0);
        if ((osd_get_menu_state() > 0x33 || osd_get_menu_state() <= 0x3b) && row == 0xc && user_settings.language == LANGUAGE_13) {
            osd_api_fill_cell_bytes(0, 0x26, 0xc, 1, 0, 0);
            osd_api_fill_cells(0x26, 0xc, 1, CHOICE_BLANK_ATTR, 0);
        }
    }
    osd_api_fill_cell_bytes(0, 0x2d, 0x15, 2, 0, 0);
    osd_api_set_window_enable(WINDOW_5, 0, 0);
    osd_api_set_window_enable(WINDOW_CHOICE_PLAIN, 0, 0);
    state = osd_get_menu_state();
    in_set = state_has_highlight_window(state);
    if (in_set)
        osd_set_highlight_window(0, CHOICE_COLUMN, 1, CHOICE_WIDTH);
}
