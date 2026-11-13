/* font_get_glyph_column_code_f0  (FUN_a00a2c04)
 *
 * Return a glyph bitmap column from the table of menu font 0xF0.
 *   glyph_index
 * Returns: table entry
 * Note: ROM table 0x125928 (also the default for unknown codes).
 * Name basis: derived - font_get_glyph_column (columns) case 0xF0; text drawer osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: one indexed read of an extern table; the index
 * is an unsigned short.
 */
/* Glyph table of font 0xF0: one 32-bit entry per index (at address 0x125928). osd_draw_text ORs these entries into its cell buffer. Any font code outside 0xF0..0xFE also uses this table. */
extern unsigned int font_glyph_columns_f0[];

/* Return entry glyph_index of the glyph table of font 0xF0. Called by font_get_glyph_column. */
unsigned int font_get_glyph_column_code_f0(unsigned short glyph_index)
{
    return font_glyph_columns_f0[glyph_index];
}
