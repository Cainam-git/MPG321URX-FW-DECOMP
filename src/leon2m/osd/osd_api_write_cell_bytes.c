/* osd_api_write_cell_bytes  (FUN_a0146af4)
 *
 * Write a run of bytes to one of the two byte planes at a cell position.
 * Name basis: derived - forwards to osd_ram_write_cell_bytes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146af4 @ 0xa0146af4, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and returns int; the parameters keep the decompiler's
 * widths (byte plane_select, halfwords for column and row, byte count, word data pointer, byte layer).
 */
extern int osd_ram_write_cell_bytes();

/* Pass the plane choice, the cell position (column, row), the number of bytes, the address of the bytes and the
 * menu layer (0 or 1) on to osd_ram_write_cell_bytes. plane_select 1 picks byte plane 1, any other value plane 0. */
void osd_api_write_cell_bytes(unsigned char plane_select,unsigned short column,unsigned short row,unsigned char count,
                 unsigned int data,unsigned char layer)

{
  osd_ram_write_cell_bytes(plane_select,column,row,count,data,layer);
  return;
}
