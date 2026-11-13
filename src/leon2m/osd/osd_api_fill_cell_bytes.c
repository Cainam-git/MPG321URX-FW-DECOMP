/* osd_api_fill_cell_bytes  (FUN_a0146b20)
 *
 * Fill a number of cells in one of the two byte planes with one value.
 * Name basis: derived - forwards to osd_ram_fill_cell_bytes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146b20 @ 0xa0146b20, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and returns int; the parameters keep the decompiler's
 * widths (byte plane_select, halfwords for column and row, bytes for the rest).
 */
extern int osd_ram_fill_cell_bytes();

/* Pass the plane choice, the cell position (column, row), the number of cells, the byte value and the menu layer
 * (0 or 1) on to osd_ram_fill_cell_bytes. plane_select 1 picks byte plane 1, any other value plane 0. */
void osd_api_fill_cell_bytes(unsigned char plane_select,unsigned short column,unsigned short row,unsigned char count,
                 unsigned char value,unsigned char layer)

{
  osd_ram_fill_cell_bytes(plane_select,column,row,count,value,layer);
  return;
}
