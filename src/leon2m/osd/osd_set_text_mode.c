/* osd_set_text_mode  (FUN_a011b36c)
 *
 * Store the text drawing mode of a menu layer.
 * Name basis: descriptive - word per layer at 0xA802C9A8; read back by osd_get_text_mode and
 *   osd_ram_write_index_run
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b36c, flags -mcpu=v8 -O2 -g (section default).
 */
extern unsigned int osd_layer_text_modes[];             /* text mode of each menu layer (low byte used) */

/* Store the text mode of a menu layer: TEXT_ALIGN_LEFT 0, TEXT_ALIGN_RIGHT 1 or TEXT_ALIGN_CENTRE 2, the values
 * osd_ram_write_index_run tests.
 *   mode:  the new text mode
 *   layer: menu layer number (low byte)
 */
void osd_set_text_mode(unsigned int mode, unsigned int layer)

{
  osd_layer_text_modes[(layer & 0xff)] = mode;
  return;
}
