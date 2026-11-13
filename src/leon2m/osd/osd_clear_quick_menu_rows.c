/* osd_clear_quick_menu_rows  (FUN_a00a7c88)
 *
 * Clear the text rows 4..11 of a quick menu.
 * Name basis: descriptive - called by osd_draw_alarm_clock_quick_menu / osd_draw_game_mode_quick_menu (alarm
 *   clock and game mode quick menus)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a7c88 @ 0xa00a7c88, flags -mcpu=v8 -O2 -g.
 * Source form: Ghidra's type and symbol names are kept. The row is kept twice, as the byte counter i and the
 * widened copy j that the loop test uses.
 */
extern int panel_wait_sync_pulse(void); /* 0x4008e2a4 */
extern void osd_api_fill_cell_bytes(int plane, int column, int row, int count, int value, int layer); /* 0xa0146b20 */
extern void osd_api_fill_cells(int column, int row, int count, int value, int layer); /* 0xa0146a80 */

#define MENU_LAYER_MAIN 0
#define PLANE_0         0
#define CELL_BLANK      0x792

/* Clear rows 4..11 of a quick menu: after a call to panel_wait_sync_pulse,
 * each row gets 16 cells from column 3 set to CELL_BLANK with glyph byte 0.
 * Called by the Alarm Clock and Game Mode quick menu drawers. */
void osd_clear_quick_menu_rows(void)
{
    unsigned char i;
    unsigned int j;
    panel_wait_sync_pulse();
    i = 4;
    j = 4;
    do {
        osd_api_fill_cell_bytes(PLANE_0, 3, j, 0x10, 0, MENU_LAYER_MAIN);
        osd_api_fill_cells(3, j, 0x10, CELL_BLANK, MENU_LAYER_MAIN);
        i++;
        j = i & 0xff;
    } while (j <= 0xb);
}
