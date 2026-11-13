/* font_get_glyph_column_code_f7  (FUN_a00a2e44)
 *
 * Return a glyph bitmap column from the table of menu font 0xF7.
 *   glyph_index
 * Returns: table entry
 * Note: ROM table 0x167000.
 * Name basis: derived - font_get_glyph_column (columns) case 0xF7; text drawer osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: one indexed read of an extern table; the index
 * is an unsigned short.
 */
/* Glyph table of font 0xF7: one 32-bit entry per index (at address 0x167000). osd_draw_text ORs these entries into its cell buffer. */
extern const unsigned int font_glyph_columns_f7[];

/* Return entry glyph_index of the glyph table of font 0xF7. Called by font_get_glyph_column. */
unsigned int font_get_glyph_column_code_f7(unsigned short glyph_index)
{
    return font_glyph_columns_f7[glyph_index];
}
