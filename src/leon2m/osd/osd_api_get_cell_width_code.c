/* osd_api_get_cell_width_code  (FUN_a0146324)
 *
 * Return the stored cell code of a menu layer (second table).
 * Returns: code
 * Name basis: descriptive - forwards to osd_get_cell_height
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146324, flags -mcpu=v8 -O2 -g (section default).
 * The callee is declared without a prototype; the second parameter is the decompiler's.
 */
extern int osd_get_cell_height();

/* Return the cell width code stored for a menu layer (osd_get_cell_height).
 *   layer:   menu layer number (low byte)
 *   ignored: second parameter, not used
 */
unsigned char osd_api_get_cell_width_code(unsigned int layer, unsigned int ignored)
{
  layer = layer & 0xff;
  return osd_get_cell_height(layer);
}
