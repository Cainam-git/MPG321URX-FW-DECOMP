/* osd_set_rows  (FUN_a0119658)
 *
 * Store the number of character rows of a menu layer.
 * Name basis: derived - byte per layer at 0xA802C9C8, written with the columns to the size registers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0119658 @ 0xa0119658 (-mcpu=v8 -O2 -g)
 * Source form: the layer parameter is an unsigned int masked with 0xff at the index.
 */
extern unsigned char osd_layer_rows[];            /* rows of each menu layer */

/* Store the number of character rows of a menu layer (byte table indexed by layer). */
void osd_set_rows(unsigned char rows,unsigned int layer)

{
  osd_layer_rows[(layer & 0xff)] = rows;
  return;
}
