/* osd_draw_menu_header  (FUN_a00a550c)
 *
 * Draw the fixed frame cells of the main menu's top rows.
 * Name basis: descriptive - fixed cell writes on rows 0/1; called by osd_draw_main_menu_frame (main menu page)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a550c @ 0xa00a550c, flags -mcpu=v8 -O3 -g.
 * Source form: each loop is a do-while with the increment after the call; the counters are unsigned char; the
 * column argument of osd_api_fill_cell_bytes is "(unsigned short)(i + offset)". Three separate counters i, j, k
 * are kept. The cell fill at column 0x35 appears twice, as in the firmware.
 */
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define MENU_LAYER_MAIN 0
#define PLANE_0         0

/* Draw the fixed cells of the main menu's top rows 0..2.
 *   row 1:  cells 3..8 get cell value 0xF9A and glyph bytes 0x15..0x1A
 *   row 0:  single or double cells at columns 0x14, 0x1D, 0x25, 0x32 and 0x35
 *           get cell value 0x12AA and glyph bytes 0x1B, 0x1C | 0x1D, 0x1E |
 *           0x1F | 0x20 | 0x21
 *   row 2:  column 0xD gets cell value 0x12AA and glyph byte 0x22
 * Called by the main menu page drawer. */
void osd_draw_menu_header(void)
{
    unsigned char i;
    unsigned char j;
    unsigned char k;
    osd_api_fill_cells(3, 1, 6, 0xf9a, MENU_LAYER_MAIN);
    i = 0;
    do {
        osd_api_fill_cell_bytes(PLANE_0, (unsigned short)(i + 3), 1, 1, i + 0x15, MENU_LAYER_MAIN);
        i++;
    } while (i <= 5);
    osd_api_fill_cells(0x14, 0, 2, 0x12aa, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x1d, 0, 2, 0x12aa, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x25, 0, 1, 0x12aa, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x32, 0, 1, 0x12aa, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x35, 0, 1, 0x12aa, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x35, 0, 1, 0x12aa, MENU_LAYER_MAIN);
    osd_api_fill_cells(0xd, 2, 1, 0x12aa, MENU_LAYER_MAIN);
    j = 0;
    do {
        osd_api_fill_cell_bytes(PLANE_0, (unsigned short)(j + 0x14), 0, 1, j + 0x1b, MENU_LAYER_MAIN);
        j++;
    } while (j <= 1);
    k = 0;
    do {
        osd_api_fill_cell_bytes(PLANE_0, (unsigned short)(k + 0x1d), 0, 1, k + 0x1d, MENU_LAYER_MAIN);
        k++;
    } while (k <= 1);
    osd_api_fill_cell_bytes(PLANE_0, 0x25, 0, 1, 0x1f, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, 0x32, 0, 1, 0x20, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, 0x35, 0, 1, 0x21, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, 0xd, 2, 1, 0x22, MENU_LAYER_MAIN);
}
