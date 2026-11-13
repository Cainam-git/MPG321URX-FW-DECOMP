/* font_get_glyph_width_code_f9  (FUN_a00a28a4)
 *
 * Return a glyph width from the table of menu font 0xF9.
 *   glyph_index
 * Returns: table entry
 * Note: ROM table 0x115588; font codes 0xF0..0xFE in menu texts select the table.
 * Name basis: derived - font_get_glyph_width (widths) case 0xF9; text drawer osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: one indexed read of an extern table; the index
 * is an unsigned short.
 */
/* Width table of font 0xF9: one byte entry per index (at address 0x115588). osd_draw_text adds the widths of a text to place its characters. */
extern const unsigned char font_glyph_widths_f9[];

/* Return entry glyph_index of the width table of font 0xF9. Called by font_get_glyph_width. */
unsigned char font_get_glyph_width_code_f9(unsigned short glyph_index)
{
    return font_glyph_widths_f9[glyph_index];
}
