/* font_get_glyph_column_code_fa  (FUN_a00a285c)
 *
 * Return a glyph bitmap column from the table of menu font 0xFA.
 *   glyph_index
 * Returns: table entry
 * Note: ROM table 0x1081F0; font codes 0xF0..0xFE in menu texts select the table.
 * Name basis: derived - font_get_glyph_column (columns) case 0xFA; text drawer osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: one indexed read of an extern table; the index
 * is an unsigned short.
 */
/* Glyph table of font 0xFA: one 32-bit entry per index (at address 0x1081F0). osd_draw_text ORs these entries into its cell buffer. */
extern const unsigned int font_glyph_columns_fa[];

/* Return entry glyph_index of the glyph table of font 0xFA. Called by font_get_glyph_column. */
unsigned int font_get_glyph_column_code_fa(unsigned short glyph_index)
{
    return font_glyph_columns_fa[glyph_index];
}
