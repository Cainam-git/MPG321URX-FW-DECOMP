/* font_get_glyph_width  (FUN_a00a3024)
 *
 * Return the width of a character in the given menu font.
 *   font: font code 0xF0..0xFE
 *   glyph_index: character
 * Returns: width in pixels
 * Note: Codes 0xF0..0xFE; any other code uses font 0xF0.
 * Name basis: derived - switch 0xF0..0xFE over the font_get_glyph_width_code_* getters; called by
 *   osd_draw_text
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source form: a switch with a jump table (15 entries) of returns; the case order below
 * is the firmware's, not ascending. The order decides the registers chosen in each case block, the code layout is
 * the same for this order and for ascending order.
 */
extern unsigned char font_get_glyph_width_code_f0(unsigned short n);
extern unsigned char font_get_glyph_width_code_f1(unsigned short n);
extern unsigned char font_get_glyph_width_code_f2(unsigned short n);
extern unsigned char font_get_glyph_width_code_f3(unsigned short n);
extern unsigned char font_get_glyph_width_code_f4(unsigned short n);
extern unsigned char font_get_glyph_width_code_f5(unsigned short n);
extern unsigned char font_get_glyph_width_code_f6(unsigned short n);
extern unsigned char font_get_glyph_width_code_f7(unsigned short n);
extern unsigned char font_get_glyph_width_code_f8(unsigned short n);
extern unsigned char font_get_glyph_width_code_f9(unsigned short n);
extern unsigned char font_get_glyph_width_code_fa(unsigned short n);
extern unsigned char font_get_glyph_width_code_fb(unsigned short n);
extern unsigned char font_get_glyph_width_code_fc(unsigned short n);
extern unsigned char font_get_glyph_width_code_fd(unsigned short n);
extern unsigned char font_get_glyph_width_code_fe(unsigned short n);

/* Return the width of one character in a font.
 *   font:  font code 0xF0..0xFE; any other code uses font 0xF0 like the code 0xF0
 *   glyph_index: index into the width table of that font
 * The width table of each font has its own getter (font_get_glyph_width_code_f0 .. _fe). Called by
 * osd_draw_text, which adds the widths of a text to place its characters. */
unsigned char font_get_glyph_width(unsigned char font, unsigned short glyph_index)
{
    switch (font) {
    case 0xf0: return font_get_glyph_width_code_f0(glyph_index);
    case 0xf1: return font_get_glyph_width_code_f1(glyph_index);
    case 0xf4: return font_get_glyph_width_code_f4(glyph_index);
    case 0xf3: return font_get_glyph_width_code_f3(glyph_index);
    case 0xf5: return font_get_glyph_width_code_f5(glyph_index);
    case 0xf6: return font_get_glyph_width_code_f6(glyph_index);
    case 0xf7: return font_get_glyph_width_code_f7(glyph_index);
    case 0xf8: return font_get_glyph_width_code_f8(glyph_index);
    case 0xf9: return font_get_glyph_width_code_f9(glyph_index);
    case 0xfa: return font_get_glyph_width_code_fa(glyph_index);
    case 0xf2: return font_get_glyph_width_code_f2(glyph_index);
    case 0xfb: return font_get_glyph_width_code_fb(glyph_index);
    case 0xfc: return font_get_glyph_width_code_fc(glyph_index);
    case 0xfd: return font_get_glyph_width_code_fd(glyph_index);
    case 0xfe: return font_get_glyph_width_code_fe(glyph_index);
    default:   return font_get_glyph_width_code_f0(glyph_index);
    }
}
