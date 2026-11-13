/* osd_draw_text  (FUN_a00a31a4)
 *
 * Draw a menu text (length byte, characters, font codes) at a cell position.
 *   plane
 *   x: column
 *   y: row
 *   cells: field width in cells
 *   text: length byte then characters
 *   layer: menu layer
 * Note: Aligns left, right or centred by the layer's mode word; stores the pixel width in 0xA802B088. The
 *   first parameter only picks the cell write command (0x90 for 1, else 0x40).
 * Name basis: proven - called by most menu draw routines with texts from the language tables; uses
 *   font_get_glyph_column/width
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a31a4 @ 0xa00a31a4-0xa00a3838 (421 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - layer_arg is a copy of the parameter layer used for every call but the last; layer itself is used only in the
 *    final osd_api_write_index_run call (the firmware stores the parameter to its stack slot at 0xa00a31d4 and
 *    reloads it for that call at 0xa00a33f4 and 0xa00a3534);
 *  - code_offset is unsigned short (it is only used as entry + code_offset, the 16-bit index of
 *    font_get_glyph_column);
 *  - in the centred case the remainder, the odd-quotient addition and the halving are all done in pixel_pos itself
 *    (no separate local);
 *  - glyph_width is unsigned char (the return type of font_get_glyph_width);
 *  - the OR loop is written twice, for pixel_pos below 0x10 and above (two copies in the firmware:
 *    0xa00a3778-0xa00a37cc and 0xa00a37e0-0xa00a3834);
 *  - the second scan tests font codes 0xFA..0xFE on a copy of the character (ch), the first scan on text[i].
 */
extern unsigned char osd_text_field_width;
extern unsigned short osd_last_text_width;
extern unsigned int osd_text_column_buffer[];
extern unsigned char font_get_glyph_width(unsigned char font, unsigned short ch);
extern unsigned int font_get_glyph_column(unsigned char font, unsigned short index);
extern unsigned char osd_api_get_text_mode(unsigned char layer);
extern unsigned char osd_api_get_const_0x18(void);
extern unsigned char osd_api_get_cell_width_code(unsigned char layer);
extern void osd_api_clear_glyph_write_count(unsigned char layer);
extern void osd_api_write_words24(unsigned int *entries, unsigned char layer);
extern void osd_api_write_index_run(unsigned char plane, unsigned short x, unsigned short y, unsigned char cells,
                                    unsigned char layer);

/* A text starts in font 0xF0. The bytes 0xF0..0xFE inside a text are not characters: each one switches the font
   for the characters that follow (font_get_glyph_width / font_get_glyph_column pick the table of that font). */
#define FONT_DEFAULT 0xf0

/* Text modes of a menu layer (osd_api_get_text_mode). osd_ram_write_index_run puts no empty cells in front of the
   text in mode 0, all unused cells of the field in mode 1 and half of them in mode 2. */
enum {
    TEXT_ALIGN_LEFT   = 0,
    TEXT_ALIGN_RIGHT  = 1,
    TEXT_ALIGN_CENTRE = 2
};

/*
 * Draw one menu text into a field of character cells of a menu layer.
 *
 *   plane   passed on to osd_api_write_index_run, which starts the cell write with command 0x90 when it is 1
 *           and with command 0x40 otherwise (PLANE_0 / PLANE_1 in the menu code)
 *   x, y    first cell of the field: column and row in the layer
 *   cells   width of the field in cells
 *   text    length byte, then the characters and font switch bytes (a text from the language tables,
 *           osd_get_text)
 *   layer   the menu layer drawn on
 *
 * The characters have different widths (font_get_glyph_width); a cell is 24 (osd_api_get_const_0x18) of those
 * width units wide. The routine therefore builds new cell pictures for this text, packed without gaps, rather
 * than using one cell per character:
 *
 *   1. Sum the widths of all characters. The total goes to osd_last_text_width.
 *   2. From the layer's text mode, work out where the text starts inside its first cell: at 0 for left
 *      alignment; at the remainder of (field width - text width) / 24 for right alignment; for centring the
 *      same remainder, plus 24 when the number of unused whole cells is odd, halved.
 *   3. Clear the cell buffer (osd_text_column_buffer) and start a new glyph run on the layer.
 *   4. For each character, OR its glyph entries, shifted by the position reached, into the buffer. Each time a
 *      cell is full, send it to the layer's memory (osd_api_write_words24); the part of the character that did
 *      not fit starts the next cell.
 *   5. Send the last, partly filled cell, then write the run of cell numbers into the field at (x, y)
 *      (osd_api_write_index_run), with the empty cells in front that the text mode asks for.
 *
 * Called by almost every menu drawing routine.
 */
void osd_draw_text(unsigned char plane, unsigned short x, unsigned short y, unsigned char cells, unsigned char *text,
                  unsigned char layer)
{
    unsigned char text_end, i, entry, entries_per_cell, pixel_pos;
    unsigned char glyph_width;
    char font;
    unsigned short text_width;
    unsigned short unused_width;
    unsigned short code_offset;
    unsigned char ch;
    unsigned char layer_arg;

    layer_arg = layer;
    osd_text_field_width = cells;
    text_end = text[0] + 1;

    /* 1. Width of the whole text, in the units of the font width tables. */
    font = FONT_DEFAULT;
    text_width = 0;
    for (i = 1; i < text_end; i++) {
        if (text[i] == 0xf0)
            font = 0xf0;
        else if (text[i] == 0xf2)
            font = 0xf2;
        else if (text[i] == 0xf1)
            font = 0xf1;
        else if (text[i] == 0xf4)
            font = 0xf4;
        else if (text[i] == 0xf3)
            font = 0xf3;
        else if (text[i] == 0xf5)
            font = 0xf5;
        else if (text[i] == 0xf6)
            font = 0xf6;
        else if (text[i] == 0xf7)
            font = 0xf7;
        else if (text[i] == 0xf8)
            font = 0xf8;
        else if (text[i] == 0xf9)
            font = 0xf9;
        else if (text[i] == 0xfa)
            font = 0xfa;
        else if (text[i] == 0xfb)
            font = 0xfb;
        else if (text[i] == 0xfc)
            font = 0xfc;
        else if (text[i] == 0xfd)
            font = 0xfd;
        else if (text[i] == 0xfe)
            font = 0xfe;
        else
            text_width += font_get_glyph_width(font, text[i]);
    }
    osd_last_text_width = text_width;

    /* 2. Where the text starts inside its first cell. The whole empty cells in front of it are added later by
          osd_api_write_index_run. */
    if (osd_api_get_text_mode(layer_arg) == TEXT_ALIGN_LEFT)
        pixel_pos = 0;
    else if (osd_api_get_text_mode(layer_arg) == TEXT_ALIGN_RIGHT) {
        unused_width = osd_text_field_width * osd_api_get_const_0x18() - text_width;
        pixel_pos = (int)unused_width % osd_api_get_const_0x18();
    } else if (osd_api_get_text_mode(layer_arg) == TEXT_ALIGN_CENTRE) {
        unused_width = osd_text_field_width * osd_api_get_const_0x18() - text_width;
        entry = (int)unused_width / osd_api_get_const_0x18();
        pixel_pos = (int)unused_width % osd_api_get_const_0x18();
        /* An odd number of unused cells cannot be split in half: half a cell more goes in front. */
        if (entry & 1)
            pixel_pos += osd_api_get_const_0x18();
        pixel_pos = pixel_pos >> 1;
    }

    /* 3. Empty cell buffer; the layer's glyph write count starts again from 0. One cell picture is
          entries_per_cell entries (osd_ram_write_words24 sends that many per cell). */
    entries_per_cell = osd_api_get_cell_width_code(layer_arg);
    for (entry = 0; entry < entries_per_cell; entry++)
        osd_text_column_buffer[entry] = 0;
    osd_api_clear_glyph_write_count(layer_arg);

    /* 4. Pack the characters into cells. */
    font = FONT_DEFAULT;
    for (i = 1; i < text_end; i++) {
        if (text[i] == 0xf0)
            font = 0xf0;
        else if (text[i] == 0xf2)
            font = 0xf2;
        else if (text[i] == 0xf1)
            font = 0xf1;
        else if (text[i] == 0xf4)
            font = 0xf4;
        else if (text[i] == 0xf3)
            font = 0xf3;
        else if (text[i] == 0xf5)
            font = 0xf5;
        else if (text[i] == 0xf6)
            font = 0xf6;
        else if (text[i] == 0xf7)
            font = 0xf7;
        else if (text[i] == 0xf8)
            font = 0xf8;
        else if (text[i] == 0xf9)
            font = 0xf9;
        else {
            ch = text[i];
            if (ch == 0xfa)
                font = 0xfa;
            else if (ch == 0xfb)
                font = 0xfb;
            else if (ch == 0xfc)
                font = 0xfc;
            else if (ch == 0xfd)
                font = 0xfd;
            else if (ch == 0xfe)
                font = 0xfe;
            else {
            glyph_width = font_get_glyph_width(font, ch);
            /* The glyph of a character is entries_per_cell entries long in the font's table. */
            code_offset = ch * entries_per_cell;
            if (pixel_pos == 0) {
                /* At the start of a cell the glyph replaces what the buffer held. */
                for (entry = 0; entry < entries_per_cell; entry++)
                    osd_text_column_buffer[entry] = font_get_glyph_column(font, entry + code_offset);
            } else if (pixel_pos < 0x10) {
                for (entry = 0; entry < entries_per_cell; entry++)
                    osd_text_column_buffer[entry] |= font_get_glyph_column(font, entry + code_offset) >> pixel_pos;
            } else {
                for (entry = 0; entry < entries_per_cell; entry++)
                    osd_text_column_buffer[entry] |= font_get_glyph_column(font, entry + code_offset) >> pixel_pos;
            }
            pixel_pos += glyph_width;
            /* Send every cell that is now full. */
            do {
                if (osd_api_get_const_0x18() == pixel_pos) {
                    osd_api_write_words24(osd_text_column_buffer, layer_arg);
                    pixel_pos = 0;
                } else if (osd_api_get_const_0x18() < pixel_pos) {
                    osd_api_write_words24(osd_text_column_buffer, layer_arg);
                    pixel_pos -= osd_api_get_const_0x18();
                    /* The rest of the glyph, shifted to the start of the next cell. */
                    for (entry = 0; entry < entries_per_cell; entry++)
                        osd_text_column_buffer[entry] =
                            font_get_glyph_column(font, entry + code_offset) << (glyph_width - pixel_pos);
                }
            } while (pixel_pos > osd_api_get_const_0x18() - 1);
            }
        }
    }

    /* 5. The last cell, then the cell numbers into the field. */
    if (pixel_pos != 0)
        osd_api_write_words24(osd_text_column_buffer, layer_arg);
    osd_api_write_index_run(plane, x, y, cells, layer);
}
