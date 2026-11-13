/* osd_set_layer_byte_pair  (FUN_a011a554)
 *
 * Store two bytes for a menu layer.
 * Name basis: descriptive - byte tables at 0xA802C9D0 and 0xA802C9D8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011a554, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char osd_layer_x_scales[];
extern unsigned char osd_layer_y_scales[];

/* Store the horizontal and the vertical scale of a menu layer (used when a window rectangle is set up).
 *   x_scale, y_scale: the two scales
 *   layer:            menu layer number (low byte)
 */
void osd_set_layer_byte_pair(unsigned char x_scale, unsigned char y_scale, unsigned int layer)

{
  osd_layer_x_scales[(layer & 0xff)] = x_scale;
  osd_layer_y_scales[(layer & 0xff)] = y_scale;
  return;
}
