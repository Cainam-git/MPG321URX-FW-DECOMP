/* osd_clear_tab_column  (FUN_a00ab080)
 *
 * Clear the tab column rows 5..0x15.
 * Name basis: derived - called by osd_select_prev_tab / osd_select_next_tab
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ab080 @ 0xa00ab080, flags -mcpu=v8 -O2 -g.
 * Source form: Ghidra's type and symbol names are kept. The row is kept twice, as the byte counter and the
 * widened copy the loop test uses; the callee parameters are int.
 */
extern void panel_wait_sync_pulse(void); /* 0x4008e2a4 */
extern void osd_api_fill_cells(int column, int row, int count, int value, int layer); /* 0xa0146a80 */
extern void osd_api_fill_cell_bytes(int plane, int column, int row, int count, int value, int layer); /* 0xa0146b20 */

#define MENU_LAYER_MAIN 0
#define PLANE_0         0
#define CELL_BLANK      0x792

/* Clear the tab column: after panel_wait_sync_pulse, rows 5..0x15 each get 17
 * cells from column 1 set to CELL_BLANK with glyph byte 0. Called by
 * osd_select_prev_tab and osd_select_next_tab. */
void osd_clear_tab_column(void)
{
    unsigned char row_byte;
    unsigned int row;
    panel_wait_sync_pulse();
    row_byte = 5;
    row = 5;
    do {
        osd_api_fill_cells(1, row, 0x11, CELL_BLANK, MENU_LAYER_MAIN);
        osd_api_fill_cell_bytes(PLANE_0, 1, row, 0x11, 0, MENU_LAYER_MAIN);
        row_byte++;
        row = row_byte & 0xff;
    } while (row <= 0x15);
}
