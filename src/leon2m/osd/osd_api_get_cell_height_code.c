/* osd_api_get_cell_height_code  (FUN_a014633c)
 *
 * Return the stored cell code of a menu layer (first table).
 * Returns: code
 * Name basis: descriptive - forwards to osd_get_cell_width; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014633c, flags -mcpu=v8 -O2 -g (section default).
 * The callee is declared without a prototype; the second parameter is the decompiler's.
 */
extern int osd_get_cell_width();

/* Return the cell height code stored for a menu layer (osd_get_cell_width).
 *   layer:   menu layer number (low byte)
 *   ignored: second parameter, not used
 * Nothing in the image calls it.
 */
unsigned char osd_api_get_cell_height_code(unsigned int layer, unsigned int ignored)
{
  layer = layer & 0xff;
  return osd_get_cell_width(layer);
}
