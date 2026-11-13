/* osd_draw_cell_run  (FUN_a00b32e4)
 *
 * Write a run of n glyph cells across or down, with the same or rising glyphs.
 *   across: 1 across, else down
 *   rising: 1 next glyph per cell, 0 same glyph
 *   attribute
 *   column
 *   row
 *   count
 *   first_glyph: glyph
 * Note: Sets the attribute once, then one glyph per cell.
 * Name basis: derived - osd_api_write_reg_cc then osd_api_fill_cell_bytes n times; used by all frame drawers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b32e4 @ 0xa00b32e4, flags -mcpu=v8 -O3 -g.
 * Parameters (u8, u8, u16, u16, u8, u8, u8); the seventh is passed on the stack.
 * Source form: the 'rising' test sits inside each loop; the compiler unswitches it into four loops.
 */
extern void osd_api_write_reg_cc(unsigned short value, unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count, unsigned char value, unsigned char layer);

#define PLANE_1 1

/* Write a run of glyph cells, in a row or in a column, into the menu layer.
 *   across:      1 = the run goes along a row (column, column + 1, ...); any other value = down a column.
 *   rising:      non-zero = the glyph rises by one for every cell (first_glyph, first_glyph + 1, ...);
 *                zero = every cell gets first_glyph.
 *   attribute:   value written once to registers 0xCC/0xCD (osd_api_write_reg_cc) before the cells.
 *   column, row: first cell.
 *   count:       number of cells.
 * The glyph bytes go into plane 1 of the layer. Used by the frame and highlight drawers. */
void osd_draw_cell_run(unsigned char across, unsigned char rising, unsigned short attribute, unsigned short column, unsigned char row,
                  unsigned char count, unsigned char first_glyph)
{
    unsigned char k;

    osd_api_write_reg_cc(attribute, 0);
    if (across == 1) {
        for (k = 0; k < count; k++) {
            if (rising)
                osd_api_fill_cell_bytes(PLANE_1, column + k, row, 1, first_glyph + k, 0);
            else
                osd_api_fill_cell_bytes(PLANE_1, column + k, row, 1, first_glyph, 0);
        }
    } else {
        for (k = 0; k < count; k++) {
            if (rising)
                osd_api_fill_cell_bytes(PLANE_1, column, row + k, 1, first_glyph + k, 0);
            else
                osd_api_fill_cell_bytes(PLANE_1, column, row + k, 1, first_glyph, 0);
        }
    }
}
