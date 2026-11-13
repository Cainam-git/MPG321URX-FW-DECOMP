/* font_get_glyph_column  (FUN_a00a2eec)
 *
 * Return a glyph bitmap column from the table of the given menu font code.
 *   font: font code 0xF0..0xFE
 *   glyph_index: glyph column index
 * Returns: column bits
 * Note: Codes 0xF0..0xFE; any other code uses font 0xF0.
 * Name basis: derived - switch 0xF0..0xFE over the font_get_glyph_column_code_* getters; called by
 *   osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source form: a switch with a jump table (15 entries); the case order below is the
 * firmware's, not ascending. The order decides the registers of the inlined argument truncations, the block
 * layout is the same for every order. The result goes through a local before the single return.
 */
extern unsigned int font_get_glyph_column_code_f0(unsigned short n);
extern unsigned int font_get_glyph_column_code_fe(unsigned short n);
extern unsigned int font_get_glyph_column_code_fd(unsigned short n);
extern unsigned int font_get_glyph_column_code_fc(unsigned short n);
extern unsigned int font_get_glyph_column_code_fb(unsigned short n);
extern unsigned int font_get_glyph_column_code_fa(unsigned short n);
extern unsigned int font_get_glyph_column_code_f9(unsigned short n);
extern unsigned int font_get_glyph_column_code_f8(unsigned short n);
extern unsigned int font_get_glyph_column_code_f7(unsigned short n);
extern unsigned int font_get_glyph_column_code_f6(unsigned short n);
extern unsigned int font_get_glyph_column_code_f5(unsigned short n);
extern unsigned int font_get_glyph_column_code_f4(unsigned short n);
extern unsigned int font_get_glyph_column_code_f3(unsigned short n);
extern unsigned int font_get_glyph_column_code_f2(unsigned short n);
extern unsigned int font_get_glyph_column_code_f1(unsigned short n);

/* Return one entry of the glyph table of a font (osd_draw_text ORs these entries into its cell buffer).
 *   font:         font code 0xF0..0xFE; any other code uses font 0xF0 like the code 0xF0
 *   glyph_index:  index into the table of that font
 * The table of each font has its own getter (font_get_glyph_column_code_f0 .. _fe). */
unsigned int font_get_glyph_column(unsigned char font, unsigned short glyph_index)
{
    unsigned int column;

    switch (font) {
    case 0xf0: column = font_get_glyph_column_code_f0(glyph_index); break;
    case 0xf1: column = font_get_glyph_column_code_f1(glyph_index); break;
    case 0xf4: column = font_get_glyph_column_code_f4(glyph_index); break;
    case 0xf3: column = font_get_glyph_column_code_f3(glyph_index); break;
    case 0xf5: column = font_get_glyph_column_code_f5(glyph_index); break;
    case 0xf6: column = font_get_glyph_column_code_f6(glyph_index); break;
    case 0xf7: column = font_get_glyph_column_code_f7(glyph_index); break;
    case 0xf8: column = font_get_glyph_column_code_f8(glyph_index); break;
    case 0xf9: column = font_get_glyph_column_code_f9(glyph_index); break;
    case 0xfa: column = font_get_glyph_column_code_fa(glyph_index); break;
    case 0xf2: column = font_get_glyph_column_code_f2(glyph_index); break;
    case 0xfb: column = font_get_glyph_column_code_fb(glyph_index); break;
    case 0xfc: column = font_get_glyph_column_code_fc(glyph_index); break;
    case 0xfd: column = font_get_glyph_column_code_fd(glyph_index); break;
    case 0xfe: column = font_get_glyph_column_code_fe(glyph_index); break;
    default: column = font_get_glyph_column_code_f0(glyph_index); break;
    }
    return column;
}
