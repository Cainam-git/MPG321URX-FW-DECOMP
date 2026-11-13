/* osd_get_rows  (FUN_a0119684)
 *
 * Return the number of character rows of a menu layer.
 * Returns: rows
 * Name basis: derived - byte per layer at 0xA802C9C8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0119684 @ 0xa0119684 (-mcpu=v8 -O2 -g)
 * Source form: the layer parameter is an unsigned int masked with 0xff at the index.
 */
extern unsigned char osd_layer_rows[];            /* rows of each menu layer */

/* Return the number of character rows of a menu layer (byte table indexed by layer). */
unsigned char osd_get_rows(unsigned int layer)

{
  return osd_layer_rows[(layer & 0xff)];
}
