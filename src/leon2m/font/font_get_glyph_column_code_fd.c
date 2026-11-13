/* font_get_glyph_column_code_fd  (FUN_a00a2c94)
 *
 * Return a glyph bitmap column from the table of menu font 0xFD.
 *   glyph_index
 * Returns: table entry
 * Note: ROM table 0x12FBC0.
 * Name basis: derived - font_get_glyph_column (columns) case 0xFD; text drawer osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: one indexed read of an extern table; the index
 * is an unsigned short.
 */
/* Glyph table of font 0xFD: one 32-bit entry per index (at address 0x12FBC0). osd_draw_text ORs these entries into its cell buffer. */
extern const unsigned int font_glyph_columns_fd[];

/* Return entry glyph_index of the glyph table of font 0xFD. Called by font_get_glyph_column. */
unsigned int font_get_glyph_column_code_fd(unsigned short glyph_index)
{
    return font_glyph_columns_fd[glyph_index];
}
