/* osd_draw_value_number  (FUN_a00b3708)
 *
 * Draw a value as up to three digits at a cell position.
 *   column
 *   row
 *   value
 * Name basis: derived - format at 0x1981D0; called by the Brightness quick menu handlers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b3708 @ 0xa00b3708, flags -mcpu=v8 -O3 -g.
 * Source form: the prototypes take unsigned char/unsigned int arguments as the firmware passes them; the
 * format "n%3d" is passed to sprintf as an unsigned int argument.
 */
extern void osd_api_set_glyph_write_address(unsigned int address, unsigned char layer);
extern void osd_api_set_text_mode(unsigned int mode, unsigned int layer);
extern void sprintf(unsigned char *buffer, unsigned int format, unsigned char value);
extern void osd_draw_text(unsigned int plane, unsigned int column, unsigned int row, unsigned int width, unsigned char *text, unsigned int layer);

#define PLANE_0                  0
#define MENU_LAYER_MAIN          0
#define TEXT_ALIGN_CENTRE        2
#define VALUE_GLYPH_ADDRESS      0x6f    /* glyph memory address given before the number is drawn */
#define VALUE_WIDTH              3       /* cells of the number */

/* Draw a value 0..255 as a three-character number at a cell position, centred in a field of three cells.
 *   column, row: cell position.
 *   value:       the number.
 * The text is built with sprintf "n%3d"; the leading 'n' is a placeholder that is overwritten with the
 * length byte (index of the first 0 byte among the first four bytes, or 4, minus 1) that the text drawing
 * routine expects. Called by the Brightness quick menu handlers. */
void osd_draw_value_number(unsigned int column, unsigned int row, unsigned char value)
{
    unsigned char text[8];
    unsigned char i;

    osd_api_set_glyph_write_address(VALUE_GLYPH_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, 0);
    sprintf(text, "n%3d", value);
    for (i = 0; i <= 3; i++)
        if (text[i] == 0)
            break;
    text[0] = i - 1;
    osd_draw_text(PLANE_0, column & 0xff, row & 0xff, VALUE_WIDTH, text, MENU_LAYER_MAIN);
}
