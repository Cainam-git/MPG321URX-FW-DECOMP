/* osd_set_glyph_write_count  (FUN_a011b3b8)
 *
 * Store the count of glyph entries written to a menu layer so far.
 * Name basis: derived - byte per layer at 0xA802C9A0; advanced together with the write address
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b3b8, flags -mcpu=v8 -O2 -g (section default).
 * The global is declared as an array and indexed with a plain subscript, which makes the global address the base
 * register and the index the offset (stb %o0, [%g1 + %o1]); the pointer form (&DAT)[idx] swaps the two registers.
 */
extern unsigned char osd_glyph_write_count[256]; /* 0xa802c9a0 */

/* Store the glyph write count of a menu layer (the count for the next glyph data written to its memory).
 *   count: the new count
 *   layer: menu layer number (low byte)
 */
void osd_set_glyph_write_count(unsigned char count, unsigned int layer)
{
    osd_glyph_write_count[layer & 0xff] = count;
}
