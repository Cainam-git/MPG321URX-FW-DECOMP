/* osd_api_set_size_in_cells  (FUN_a014613c)
 *
 * Store the number of columns and rows of a menu layer.
 * Name basis: derived - forwards to osd_set_columns and osd_set_rows
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014613c, flags -mcpu=v8 -O2 -g (section default).
 */
extern void osd_set_columns(unsigned short columns, unsigned int layer);
extern void osd_set_rows(unsigned char rows, unsigned int layer);

/* Store the number of columns and rows, in cells, of a menu layer.
 *   columns, rows: the size
 *   layer:         menu layer number (low byte)
 * Called by ShowLogo (ShowLogo).
 */
void osd_api_set_size_in_cells(unsigned short columns, unsigned char rows, unsigned int layer)

{
  osd_set_columns(columns, layer & 0xff);
  osd_set_rows(rows, layer & 0xff);
  return;
}
