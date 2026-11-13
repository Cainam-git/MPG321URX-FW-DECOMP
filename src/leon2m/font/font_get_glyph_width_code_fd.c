/* font_get_glyph_width_code_fd  (FUN_a00a2cac)
 *
 * Return a glyph width from the table of menu font 0xFD.
 *   glyph_index
 * Returns: table entry
 * Note: ROM table 0x130DC0.
 * Name basis: derived - font_get_glyph_width (widths) case 0xFD; text drawer osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O2 -g (the section default). Source form: one indexed read of an extern table; the index
 * is an unsigned short.
 */
/* Width table of font 0xFD: one byte entry per index (at address 0x130DC0). osd_draw_text adds the widths of a text to place its characters. */
extern const unsigned char font_glyph_widths_fd[];

/* Return entry glyph_index of the width table of font 0xFD. Called by font_get_glyph_width. */
unsigned char font_get_glyph_width_code_fd(unsigned short glyph_index)
{
    return font_glyph_widths_fd[glyph_index];
}
