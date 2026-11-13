/* osd_api_set_origin_and_size  (FUN_a014654c)
 *
 * Write the origin and the size in cells of a menu layer.
 * Name basis: derived - forwards to osd_set_origin_and_size
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014654c, flags -mcpu=v8 -O2 -g (section default).
 * The callee is declared without a prototype.
 */
extern int osd_set_origin_and_size();

/* Put a menu layer at (x, y) with the size stored for it: calls osd_set_origin_and_size.
 *   x, y:  origin of the layer
 *   layer: menu layer number
 * Called by ShowLogo (ShowLogo) and by routines that place layer 1 at user_settings.crosshair_x / _y.
 */
void osd_api_set_origin_and_size(unsigned short x, unsigned short y, unsigned char layer)
{
  osd_set_origin_and_size(x, y, layer);
  return;
}
