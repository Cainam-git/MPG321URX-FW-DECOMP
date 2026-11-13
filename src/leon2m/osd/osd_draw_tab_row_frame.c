/* osd_draw_tab_row_frame  (FUN_a00a8bc0)
 *
 * Draw the frame cells around a tab row.
 *   tab: tab index
 * Note: Row 10 gets a special shape.
 * Name basis: descriptive - cell writes in the tab column at row 2p + 4; no table reference
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a8bc0 @ 0xa00a8bc0, flags -mcpu=v8 -O3 -g.
 * Source form: the row is computed in a word (tab * 2 + 4) and masked to a byte after the call to
 * osd_set_highlight_window.
 */
extern void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width);
extern void osd_draw_cell_run(unsigned int across, unsigned int rising, unsigned int attribute, unsigned int column, unsigned int row, unsigned int count, unsigned int first_glyph);

#define CELL_BLANK 0x792

/* Redraw the frame cells at the two sides of a tab's row, after switching the
 * highlight window off. The tab starts at row 2 * tab + 4. Column 3 and
 * column 0x12 each get three cells down from that row set to CELL_BLANK with
 * glyph 0. For the tab at row 10 column 3 gets only two such cells, and a
 * single cell at row 12 with attribute 0x3092 and glyph 0x11. */
void osd_draw_tab_row_frame(unsigned int tab)
{
    unsigned int row;
    
    row = (tab & 0xff) * 2 + 4;
    osd_set_highlight_window(0, 0, 0, 0);
    row = row & 0xff;
    
    if (row == 10) {
        osd_draw_cell_run(0, 0, CELL_BLANK, 3, 10, 2, 0);
        osd_draw_cell_run(1, 0, 0x3092, 3, 0xc, 1, 0x11);
    } else {
        osd_draw_cell_run(0, 0, CELL_BLANK, 3, row, 3, 0);
    }
    
    osd_draw_cell_run(0, 0, CELL_BLANK, 0x12, row, 3, 0);
}
