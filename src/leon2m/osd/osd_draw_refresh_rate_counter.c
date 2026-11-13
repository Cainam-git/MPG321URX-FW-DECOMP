/* osd_draw_refresh_rate_counter  (FUN_a00b88e0)
 *
 * Draw the current refresh rate as 'nnn HZ' in the overlay box.
 *   column
 *   row
 * Name basis: proven - format 'n%d HZ' with input_user_get_rounded_refresh_rate; caller
 *   osd_show_screen_overlays
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b88e0 @ 0xa00b88e0-0xa00b89c4 (57 words), flags -mcpu=v8 -O3 -g.
 * Source form: the length byte is computed with a loop that searches for the first zero byte of the 16-byte
 * buffer (index i, limit 16), then stored as i - 1.
 */
#define GLYPH_WRITE_ADDRESS   200
#define TEXT_MODE_NUMBER      2
#define COUNTER_BOX_COLUMNS   0x10              /* cells cleared for the counter */
#define COUNTER_CELL_COLUMN   3                 /* the cleared cells start at x + 3 */
#define COUNTER_TEXT_COLUMN   8                 /* the text starts at x + 8 */
#define COUNTER_ROW           11                /* the cleared cells and the text are at y + 11 */
#define CELL_BLANK            0x792
#define TEXT_BUFFER_SIZE      16

extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned short input_user_get_rounded_refresh_rate(void);
extern void sprintf(unsigned char *, unsigned int, unsigned short);
extern void osd_draw_text(int, unsigned short, unsigned short, int, unsigned char *, int);

/*
 * Draw the refresh rate counter 'nnn HZ' of the screen overlays at the box position (column, row).
 *
 *   column, row  top left of the overlay box; the cells are cleared from (column + 3, row + 11) and the text is
 *                drawn from (column + 8, row + 11)
 *
 * The number is the rounded incoming refresh rate (input_user_get_rounded_refresh_rate). The text is built as
 * "n%d HZ"; its first byte is then replaced by the length of the text, found as the index of the first zero
 * byte minus 1. Called by osd_show_screen_overlays.
 */
void osd_draw_refresh_rate_counter(unsigned short column, unsigned short row)
{
    unsigned char text[TEXT_BUFFER_SIZE];
    unsigned char i;

    osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_MODE_NUMBER, 0);
    osd_api_fill_cells(column + COUNTER_CELL_COLUMN, row + COUNTER_ROW, COUNTER_BOX_COLUMNS, CELL_BLANK, 0);
    sprintf(text, "n%d HZ", input_user_get_rounded_refresh_rate());
    for (i = 0; i < TEXT_BUFFER_SIZE; i++)
        if (text[i] == 0)
            break;
    text[0] = i - 1;
    osd_draw_text(0, column + COUNTER_TEXT_COLUMN, row + COUNTER_ROW, 6, text, 0);
}
