/* osd_api_reset_layer  (FUN_a0146108)
 *
 * Reset a menu layer.
 * Name basis: descriptive - forwards to osd_reset_layer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146108, flags -mcpu=v8 -O2 -g (section default).
 * The callee is declared without a prototype.
 */
extern int osd_reset_layer();

/* Reset a menu layer: calls osd_reset_layer.
 *   layer: menu layer number
 * Called by ShowLogo (ShowLogo).
 */
void osd_api_reset_layer(unsigned char layer)

{
  osd_reset_layer(layer);
  return;
}
