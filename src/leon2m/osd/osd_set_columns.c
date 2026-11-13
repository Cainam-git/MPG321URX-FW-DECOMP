/* osd_set_columns  (FUN_a0119640)
 *
 * Store the number of character columns of a menu layer.
 * Name basis: derived - halfword per layer at 0xA802C9CA; the memory writes compute cell addresses as x + y *
 *   columns
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0119640 @ 0xa0119640 (-mcpu=v8 -O2 -g)
 * Source form: the layer parameter is an unsigned int masked with 0xff at the index.
 */
extern unsigned short osd_layer_columns[];           /* columns of each menu layer */

/* Store the number of character columns of a menu layer (halfword table indexed by layer). */
void osd_set_columns(unsigned short columns,unsigned int layer)

{
  osd_layer_columns[(layer & 0xff)] = columns;
  return;
}
