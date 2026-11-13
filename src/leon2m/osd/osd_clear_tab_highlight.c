/* osd_clear_tab_highlight  (FUN_a00a7e00)
 *
 * Draw a tab row of the left column back in normal colours.
 *   tab: tab index
 * Note: Switches the highlight windows 1 and 2 off first; osd_highlight_tab draws the new one.
 * Name basis: derived - called by osd_select_prev_tab / osd_select_next_tab; menu columns: tabs 1..0x12, items
 *   0x14.., choices 0x27.., key guide 0x37..
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a7e00 @ 0xa00a7e00, flags -mcpu=v8 -O3 -g.
 * Source form: icon_attr is assigned after the row selection; the test for tabs 1 and 8 is written
 * 'tab != 1 && tab != 8' with that arm second; in the arm for the other tabs row + 2 goes through the unsigned
 * char local lower_row, elsewhere it is passed as row + 2 (converted to each parameter type at the call).
 */
extern void osd_api_set_window_enable(unsigned char, unsigned char, unsigned char);
extern void panel_wait_sync_pulse(void);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);

#define TAB_BLANK_ATTR       0x792      /* attribute of a blank cell in the tab column */
#define TAB_ICON_ATTR_TALL   0x629a     /* icon attribute of tabs 0, 6, 7 */
#define TAB_ICON_ATTR_SHORT  0x659a     /* icon attribute of the other tabs */
#define TAB_ICON_COLUMN      2
#define TAB_ICON_WIDTH       3
#define TAB_TEXT_COLUMN      5          /* the tab name starts here; the cells up to column 17 hold it */
#define TAB_NAME_WIDTH       0xd
#define TAB_LAST_COLUMN_CELL 0x11       /* columns 1..17 are the tab column */
#define TAB_ICON_GLYPH_TAB_0_BOTTOM 0x4f  /* bottom icon row of tab 0 (0x49 + 6), shared with the row of tab 1 */
#define TAB_ICON_GLYPH_TAB_7_BOTTOM 0x76  /* bottom icon row of tab 7 (0x70 + 6), shared with the row of tab 8 */
#define TAB_ICON_GLYPH_TAB_6_TOP    100   /* top icon row of tab 6 (0x64), shared with the row of tab 5 */

/*
 * Redraw one tab of the left column of the main menu in its normal (not highlighted) look.
 *
 *   tab  tab index 0..8
 *
 * The two highlight windows 1 and 2 are switched off first; osd_highlight_tab then draws the new highlight.
 * A tab owns the three cell rows row..row+2 with row = 2 * tab + 5 (tabs 0..6) or 2 * tab - 9 (tabs 7, 8, on
 * the second page), so two tabs next to each other share a cell row. The tall icons of tabs 0, 6 and 7
 * (see osd_draw_tab_icons) reach into the neighbours' rows, so for the neighbours the routine draws the icon
 * row they share back in (tab 1: glyph 0x4f, tab 8: glyph 0x76, tab 5: glyph 100).
 *
 * Order: windows off, cell (1, row) blanked; then by tab:
 *   tabs 0, 6, 7   the icon cells (columns 2..4) of rows row and row + 2 are filled with attribute 0x629a and
 *                  the name cells and column 1 blanked
 *   tabs 1, 8      the shared icon row, then row blanked except the icon, then row + 2 blanked across
 *   other tabs     rows row and row + 2 blanked across (tab 5 then redraws the shared icon row on row + 2)
 * Finally the middle row row + 1: column 1 blank, icon cells with the icon attribute of the tab (0x629a for
 * tabs 0, 6, 7, else 0x659a), name cells blank, glyph plane 0 cleared at column 0x11.
 *
 * Called by the Up and Down key handlers of the tab column, before they move the highlight.
 */
void osd_clear_tab_highlight(unsigned char tab)
{
    unsigned char row;
    unsigned short icon_attr;
    unsigned char lower_row;

    if (tab > 6)
        row = tab * 2 - 9;
    else
        row = tab * 2 + 5;
    icon_attr = TAB_ICON_ATTR_TALL;
    osd_api_set_window_enable(1, 0, 0);
    osd_api_set_window_enable(2, 0, 0);
    panel_wait_sync_pulse();
    osd_api_fill_cells(1, row, 1, TAB_BLANK_ATTR, 0);
    if ((unsigned char)(tab - 6) < 2 || tab == 0) {
        osd_api_fill_cells(TAB_ICON_COLUMN, row, TAB_ICON_WIDTH, TAB_ICON_ATTR_TALL, 0);
        osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, 1, row, 1, 0);
        osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, TAB_TEXT_COLUMN, row, TAB_NAME_WIDTH, 0);
        osd_api_fill_cells(TAB_ICON_COLUMN, row + 2, TAB_ICON_WIDTH, TAB_ICON_ATTR_TALL, 0);
        osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, 1, row + 2, 1, 0);
        osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, TAB_TEXT_COLUMN, row + 2, TAB_NAME_WIDTH, 0);
    } else {
        if (tab != 1 && tab != 8) {
            osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, 1, row, TAB_LAST_COLUMN_CELL, 0);
            lower_row = row + 2;
            osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, 1, lower_row, TAB_LAST_COLUMN_CELL, 0);
        } else {
            if (tab == 8)
                osd_draw_cell_run(1, 1, TAB_ICON_ATTR_TALL, TAB_ICON_COLUMN, row, TAB_ICON_WIDTH, TAB_ICON_GLYPH_TAB_7_BOTTOM);
            else if (tab == 1)
                osd_draw_cell_run(1, 1, TAB_ICON_ATTR_TALL, TAB_ICON_COLUMN, row, TAB_ICON_WIDTH, TAB_ICON_GLYPH_TAB_0_BOTTOM);
            osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, 1, row, 1, 0);
            osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, TAB_TEXT_COLUMN, row, TAB_NAME_WIDTH, 0);
            lower_row = row + 2;
            osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, 1, lower_row, TAB_LAST_COLUMN_CELL, 0);
        }
        if (tab == 5)
            osd_draw_cell_run(1, 1, TAB_ICON_ATTR_TALL, TAB_ICON_COLUMN, lower_row, TAB_ICON_WIDTH, TAB_ICON_GLYPH_TAB_6_TOP);
        icon_attr = TAB_ICON_ATTR_SHORT;
    }
    osd_draw_cell_run(1, 0, TAB_BLANK_ATTR, 1, row + 1, 1, 0);
    osd_api_fill_cells(TAB_ICON_COLUMN, row + 1, TAB_ICON_WIDTH, icon_attr, 0);
    osd_api_fill_cells(TAB_TEXT_COLUMN, row + 1, TAB_NAME_WIDTH, TAB_BLANK_ATTR, 0);
    osd_api_fill_cell_bytes(0, TAB_LAST_COLUMN_CELL, row + 1, 1, 0, 0);
}
