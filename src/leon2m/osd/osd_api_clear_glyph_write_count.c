/* osd_api_clear_glyph_write_count  (FUN_a0146be8)
 *
 * Set the glyph write count of the given menu layer back to 0.
 *   layer: menu layer number
 * Name basis: derived - calls osd_set_glyph_write_count with the fixed count 0 and its own parameter as the
 *   layer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146be8 @ 0xa0146be8, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and returns int; the layer is a byte.
 */
extern int osd_set_glyph_write_count();

/* Set the glyph write count of the menu layer (0 or 1) back to 0. The count is fixed in this routine; the
 * parameter is the layer. Called by osd_draw_text before it packs the characters of a text. */
void osd_api_clear_glyph_write_count(unsigned char layer)

{
  osd_set_glyph_write_count(0,layer);
  return;
}
