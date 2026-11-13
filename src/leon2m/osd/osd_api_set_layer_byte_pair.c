/* osd_api_set_layer_byte_pair  (FUN_a0146354)
 *
 * Store two bytes for a menu layer.
 * Name basis: descriptive - forwards to osd_set_layer_byte_pair
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146354, flags -mcpu=v8 -O2 -g (section default).
 * The callee is declared without a prototype.
 */
extern int osd_set_layer_byte_pair();

/* Store the horizontal and the vertical scale of a menu layer (osd_set_layer_byte_pair).
 *   x_scale, y_scale: the two scales
 *   layer:            menu layer number
 * Called by osd_setup_window_full.
 */
void osd_api_set_layer_byte_pair(unsigned char x_scale, unsigned char y_scale, unsigned char layer)
{
  osd_set_layer_byte_pair(x_scale, y_scale, layer);
  return;
}
