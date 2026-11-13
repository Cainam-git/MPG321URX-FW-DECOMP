/* osd_api_fill_cells  (FUN_a0146a80)
 *
 * Fill a number of cells from a cell position with one 16-bit value.
 * Name basis: derived - forwards to osd_ram_fill_cells
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146a80 @ 0xa0146a80, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and returns int; the parameters keep the decompiler's
 * widths (halfwords for column, row and value, bytes for count and side).
 */
extern int osd_ram_fill_cells();

/* Pass the cell position (column, row), the number of cells, the 16-bit cell value and the menu layer (0 or 1)
 * on to osd_ram_fill_cells. */
void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value,
                 unsigned char layer)

{
  osd_ram_fill_cells(column,row,count,value,layer);
  return;
}
