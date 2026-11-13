/* font_get_glyph_width_code_f0  (FUN_a00a2c1c)
 *
 * Return a glyph width from the table of menu font 0xF0.
 *   glyph_index
 * Returns: table entry
 * Note: ROM table 0x12E2F8 (also the default for unknown codes).
 * Name basis: derived - font_get_glyph_width (widths) case 0xF0; text drawer osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: one indexed read of an extern table; the index
 * is an unsigned short.
 */
/* Width table of font 0xF0: one byte entry per index (at address 0x12E2F8). osd_draw_text adds the widths of a text to place its characters. Any font code outside 0xF0..0xFE also uses this table. */
extern unsigned char font_glyph_widths_f0[];

/* Return entry glyph_index of the width table of font 0xF0. Called by font_get_glyph_width. */
unsigned char font_get_glyph_width_code_f0(unsigned short glyph_index)
{
    return font_glyph_widths_f0[glyph_index];
}
