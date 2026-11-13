/* osd_api_set_glyph_write_address  (FUN_a0146b50)
 *
 * Store the memory address at which the next glyph data of a menu layer is written.
 * Name basis: derived - forwards to osd_set_glyph_write_address
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146b50 @ 0xa0146b50, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and returns int; the address is a halfword, the layer a
 * byte.
 */
extern int osd_set_glyph_write_address();

/* Pass the address in the layer's memory and the menu layer (0 or 1) on to osd_set_glyph_write_address. */
void osd_api_set_glyph_write_address(unsigned short address,unsigned char layer)

{
  osd_set_glyph_write_address(address,layer);
  return;
}
