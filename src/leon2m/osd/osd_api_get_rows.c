/* osd_api_get_rows  (FUN_a014617c)
 *
 * Return the number of rows of a menu layer.
 * Returns: rows
 * Name basis: derived - forwards to osd_get_rows; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014617c, flags -mcpu=v8 -O2 -g (section default).
 * The callee is declared without a prototype; the second parameter is the decompiler's.
 */
extern int osd_get_rows();

/* Return the number of rows of a menu layer (osd_get_rows of the layer).
 *   layer:   menu layer number (low byte)
 *   ignored: second parameter, not used
 * Nothing in the image calls it.
 */
unsigned char osd_api_get_rows(unsigned int layer, unsigned int ignored)
{
  layer = layer & 0xff;
  return osd_get_rows(layer);
}
