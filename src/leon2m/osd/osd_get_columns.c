/* osd_get_columns  (FUN_a011966c)
 *
 * Return the number of character columns of a menu layer.
 * Returns: columns
 * Name basis: derived - halfword per layer at 0xA802C9CA
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011966c @ 0xa011966c (-mcpu=v8 -O2 -g)
 * Source form: the layer parameter is an unsigned int masked with 0xff at the index.
 */
extern unsigned short osd_layer_columns[];           /* columns of each menu layer */

/* Return the number of character columns of a menu layer (halfword table indexed by layer). */
unsigned short osd_get_columns(unsigned int layer)

{
  return osd_layer_columns[(layer & 0xff)];
}
