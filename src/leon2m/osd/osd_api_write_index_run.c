/* osd_api_write_index_run  (FUN_a0146c14)
 *
 * Write a run of rising byte values into a menu layer's memory.
 * Name basis: descriptive - forwards to osd_ram_write_index_run
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146c14 @ 0xa0146c14, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and returns int; the parameters keep the decompiler's
 * widths (byte plane, halfwords for column and row, bytes for width and layer).
 */
extern int osd_ram_write_index_run();

/* Pass the plane, the cell position (column, row), the field width in cells and the menu layer (0 or 1) on to
 * osd_ram_write_index_run. Called by osd_draw_text. */
void osd_api_write_index_run(unsigned char plane,unsigned short column,unsigned short row,unsigned char width,
                 unsigned char layer)

{
  osd_ram_write_index_run(plane,column,row,width,layer);
  return;
}
