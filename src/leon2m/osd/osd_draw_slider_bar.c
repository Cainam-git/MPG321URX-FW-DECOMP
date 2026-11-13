/* osd_draw_slider_bar  (FUN_a00a45c0)
 *
 * Draw a value bar of cells: full cells, one partial cell, then empty cells.
 * Name basis: derived - called by the brightness quick menu handlers and the quick menu page drawer
 *   osd_draw_navi_quick_menu
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a45c0 @ 0xa00a45c0, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: old-style (K&R) byte parameters; the two cell values are signed short
 * locals (sethi of the shifted constant + srl 16 at each use), except the literal 0x839a in the value 0 arm.
 */
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

/*
 * Draw a horizontal value bar in one row of the menu cells: `length` cells starting at `column`, filled up to
 * `value` (0..100).
 *
 * Every cell is written twice: osd_api_fill_cells sets its 16-bit cell value (0x869a for the filled part, 0x839a
 * for the empty part) and osd_api_fill_cell_bytes sets its byte-plane code (0x7b is a plain cell).
 * One cell stands for 9 steps of the value: full = value / 9 cells are drawn plain (when the remainder is 0 one
 * less, unless there are none). After them comes the end piece, which is two cells wide:
 *   value 0:   code 0x7c in a filled cell, then an empty cell with 0x7b;
 *   value 99:  codes 0x8d and 0x8e in two filled cells;
 *   value 100: code 0x7c in one filled cell;
 *   otherwise: codes 0x7b + 2 * remainder and 0x7c + 2 * remainder (the second only while full <= 11).
 * The cells that are left up to `length` are empty cells (0x839a, code 0x7b).
 *
 * Callers: the Brightness quick menu (osd_increase_quick_brightness, osd_decrease_quick_brightness) and the
 * quick menu page drawer osd_draw_navi_quick_menu, which pass column 5, row 8 and length 12.
 */
void osd_draw_slider_bar(column, row, value, length)
unsigned char column, row, value, length;
{
    unsigned char full, remainder, empty_cells, i;
    short filled = (short)0x869a, empty = (short)0x839a;

    full = value / 9;
    remainder = value % 9;
    empty_cells = 0;
    if (remainder == 0 && full != 0)
        full--;
    if (full < length - 2)
        empty_cells = length - full - 2;
    /* The plain cells at the start of the bar. */
    if (full != 0)
        for (i = 0; i < full; i++) {
            osd_api_fill_cells(column + i, row, 1, filled, 0);
            osd_api_fill_cell_bytes(0, column + i, row, 1, 0x7b, 0);
        }
    /* The end piece. */
    if (value == 0) {
        osd_api_fill_cells(column + full, row, 1, filled, 0);
        osd_api_fill_cell_bytes(0, column + full, row, 1, 0x7c, 0);
        osd_api_fill_cells(column + full + 1, row, 1, 0x839a, 0);
        osd_api_fill_cell_bytes(0, column + full + 1, row, 1, 0x7b, 0);
    } else if (value == 99) {
        osd_api_fill_cells(column + full, row, 1, filled, 0);
        osd_api_fill_cell_bytes(0, column + full, row, 1, 0x8d, 0);
        osd_api_fill_cells(column + full + 1, row, 1, filled, 0);
        osd_api_fill_cell_bytes(0, column + full + 1, row, 1, 0x8e, 0);
    } else if (value == 100) {
        osd_api_fill_cells(column + full, row, 1, filled, 0);
        osd_api_fill_cell_bytes(0, column + full, row, 1, 0x7c, 0);
    } else {
        osd_api_fill_cells(column + full, row, 1, filled, 0);
        osd_api_fill_cell_bytes(0, column + full, row, 1, remainder * 2 + 0x7b, 0);
        if (full <= 11) {
            osd_api_fill_cells(column + full + 1, row, 1, filled, 0);
            osd_api_fill_cell_bytes(0, column + full + 1, row, 1, remainder * 2 + 0x7c, 0);
        }
    }
    /* The empty rest of the bar. */
    for (i = 0; i < empty_cells; i++) {
        osd_api_fill_cells(column + full + i + 2, row, 1, empty, 0);
        osd_api_fill_cell_bytes(0, column + full + i + 2, row, 1, 0x7b, 0);
    }
}
