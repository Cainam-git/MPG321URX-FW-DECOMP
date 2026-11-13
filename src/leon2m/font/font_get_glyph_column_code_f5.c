/* font_get_glyph_column_code_f5  (FUN_a00a2e14)
 *
 * Return a glyph bitmap column from the table of menu font 0xF5.
 *   glyph_index
 * Returns: table entry
 * Note: ROM table 0x160068.
 * Name basis: derived - font_get_glyph_column (columns) case 0xF5; text drawer osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: one indexed read of an extern table; the index
 * is an unsigned short.
 */
/* Glyph table of font 0xF5: one 32-bit entry per index (at address 0x160068). osd_draw_text ORs these entries into its cell buffer. */
extern const unsigned int font_glyph_columns_f5[];

/* Return entry glyph_index of the glyph table of font 0xF5. Called by font_get_glyph_column. */
unsigned int font_get_glyph_column_code_f5(unsigned short glyph_index)
{
    return font_glyph_columns_f5[glyph_index];
}
