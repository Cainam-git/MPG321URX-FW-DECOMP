/* osd_clear_menu_rows  (FUN_a00a7ce8)
 *
 * Clear the menu rows 5..20 and hide their highlight windows.
 * Name basis: descriptive - called by osd_close_position_editor
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a7ce8 @ 0xa00a7ce8, flags -mcpu=v8 -O2 -g.
 * Source form: the helper parameters are int (not Ghidra's undefined1 / undefined2) so that the default promotions
 * give the matching code. The row is kept twice, as the byte counter i and the widened copy j used by the loop test.
 */
extern int panel_wait_sync_pulse(void); /* 0x4008e2a4 */
extern void osd_api_fill_cell_bytes(int plane, int column, int row, int count, int value, int layer); /* 0xa0146b20 */
extern void osd_api_fill_cells(int column, int row, int count, int value, int layer); /* 0xa0146a80 */
extern void osd_api_set_window_enable(int window, int on, int layer); /* 0xa0146c40 */

#define MENU_LAYER_MAIN 0
#define PLANE_0         0
#define CELL_BLANK      0x792

/* Clear the menu rows 5..20: after a call to panel_wait_sync_pulse, each row
 * gets 19 cells from column 0x13 set to CELL_BLANK with glyph byte 0. Then two
 * glyph bytes at column 0x1c of row 0x15 are cleared and window 5 of the menu
 * layer is switched off. Called by osd_close_position_editor. */
void osd_clear_menu_rows(void)
{
    unsigned char i;
    unsigned int j;
    panel_wait_sync_pulse();
    i = 5;
    j = 5;
    do {
        osd_api_fill_cell_bytes(PLANE_0, 0x13, j, 0x13, 0, MENU_LAYER_MAIN);
        osd_api_fill_cells(0x13, j, 0x13, CELL_BLANK, MENU_LAYER_MAIN);
        i++;
        j = i & 0xff;
    } while (j <= 0x14);
    osd_api_fill_cell_bytes(PLANE_0, 0x1c, 0x15, 2, 0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(5, 0, MENU_LAYER_MAIN);
}
