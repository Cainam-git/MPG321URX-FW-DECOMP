/* font_get_glyph_width_code_fa  (FUN_a00a2874)
 *
 * Return a glyph width from the table of menu font 0xFA.
 *   glyph_index
 * Returns: table entry
 * Note: ROM table 0x10DFE0; font codes 0xF0..0xFE in menu texts select the table.
 * Name basis: derived - font_get_glyph_width (widths) case 0xFA; text drawer osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: one indexed read of an extern table; the index
 * is an unsigned short.
 */
/* Width table of font 0xFA: one byte entry per index (at address 0x10DFE0). osd_draw_text adds the widths of a text to place its characters. */
extern const unsigned char font_glyph_widths_fa[];

/* Return entry glyph_index of the width table of font 0xFA. Called by font_get_glyph_width. */
unsigned char font_get_glyph_width_code_fa(unsigned short glyph_index)
{
    return font_glyph_widths_fa[glyph_index];
}
