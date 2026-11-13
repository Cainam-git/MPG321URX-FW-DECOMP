/* osd_clear_item_highlight  (FUN_a00a8ee8)
 *
 * Draw an item row back in normal colours.
 *   item: item row
 * Name basis: derived - called by the leave/select item handlers; menu columns: tabs 1..0x12, items 0x14..,
 *   choices 0x27.., key guide 0x37..
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a8ee8 @ 0xa00a8ee8, flags -mcpu=v8 -O3 -g.
 * Source form: the row is built in two steps (item * 2, then +/- a constant) through unsigned short casts, and
 * kept as a byte (first_row); rows first_row + 1 and + 2 are computed as unsigned short.
 */
extern void panel_wait_sync_pulse(void);                          // 0x4008e2a4
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value, unsigned char layer); // 0xa0146a80
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer); // 0xa0146b20
extern void osd_set_highlight_window(unsigned char on, unsigned char column, unsigned int row, unsigned int width); // 0xa00b3ed0
extern void osd_draw_cell_run(unsigned char across, unsigned char rising, unsigned short attribute, unsigned char column, unsigned char row, unsigned char count, unsigned int first_glyph); // 0xa00b32e4

#define MENU_LAYER_MAIN 0
#define PLANE_0         0
#define CELL_BLANK      0x792
#define ITEM_COLUMN     0x14
#define ITEM_WIDTH      0x11

/* Draw an item back in its normal colours. The item occupies three rows
 * starting at first_row = 2 * item + 5 (items 0..6) or 2 * item - 9 (item 7
 * and above, the next page). In the item column (ITEM_COLUMN, ITEM_WIDTH
 * cells) the top and bottom rows get CELL_BLANK and glyph byte 0, the middle
 * row gets CELL_BLANK; the highlight window is switched off, and the two side
 * cells at columns 0x13 and 0x25 are cleared over the three rows. The routine
 * waits for panel_wait_sync_pulse before the first writes and again after the
 * window is off. Called by the leave and select item handlers. */
void osd_clear_item_highlight(unsigned char item) {
    unsigned char row_byte;
    unsigned char first_row;
    unsigned short bottom_row;
    
    if (item > 6) {
        row_byte = (unsigned short)(item * 2);
        row_byte = (unsigned short)(row_byte - 9);
    } else {
        row_byte = (unsigned short)(item * 2);
        row_byte = (unsigned short)(row_byte + 5);
    }
    first_row = row_byte & 0xff;
    
    panel_wait_sync_pulse();
    osd_api_fill_cells(ITEM_COLUMN, first_row, ITEM_WIDTH, CELL_BLANK, MENU_LAYER_MAIN);
    
    bottom_row = (unsigned short)(first_row + 2);
    osd_api_fill_cells(ITEM_COLUMN, bottom_row, ITEM_WIDTH, CELL_BLANK, MENU_LAYER_MAIN);
    
    osd_api_fill_cell_bytes(PLANE_0, ITEM_COLUMN, first_row, ITEM_WIDTH, 0, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, ITEM_COLUMN, bottom_row, ITEM_WIDTH, 0, MENU_LAYER_MAIN);
    
    osd_set_highlight_window(0, 0, 0, 0);
    
    panel_wait_sync_pulse();
    
    osd_api_fill_cells(ITEM_COLUMN, (unsigned short)(first_row + 1), ITEM_WIDTH, CELL_BLANK, MENU_LAYER_MAIN);
    
    osd_draw_cell_run(0, 0, CELL_BLANK, 0x13, first_row, 3, 0);
    osd_draw_cell_run(0, 0, CELL_BLANK, 0x25, first_row, 3, 0);
}
