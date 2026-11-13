/* osd_get_text_mode  (FUN_a011b384)
 *
 * Return the text drawing mode of a menu layer.
 * Returns: byte
 * Name basis: descriptive - word per layer at 0xA802C9A8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b384, flags -mcpu=v8 -O2 -g (section default).
 */
extern unsigned int osd_layer_text_modes[];             /* text mode of each menu layer (low byte used) */

/* Return the text mode of a menu layer (low byte of its word): TEXT_ALIGN_LEFT 0, RIGHT 1 or CENTRE 2.
 *   layer: menu layer number (low byte)
 * Called by osd_api_get_text_mode.
 */
unsigned int osd_get_text_mode(unsigned int layer)

{
  return osd_layer_text_modes[(layer & 0xff)] & 0xff;
}
