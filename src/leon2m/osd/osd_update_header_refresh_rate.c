/* osd_update_header_refresh_rate  (FUN_a00b37a4)
 *
 * Redraw the 'n Hz' refresh rate field in the menu header.
 * Name basis: derived - formats input_user_get_rounded_refresh_rate() with '%d HZ' at row 2; called every 100
 *   ms by osd_run_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b37a4 @ 0xa00b37a4, flags -mcpu=v8 -O3 -g.
 * Source form: the length scan keeps its counter in an unsigned char and the loop test reads the incremented
 * value; the length byte is the index of the terminating 0 minus 1 (the leading 'n' placeholder is
 * overwritten with it).
 */
extern int input_user_get_rounded_refresh_rate(void); /* 0xa00d8b38 */
extern void sprintf(unsigned char *buffer, unsigned int format, unsigned short value); /* 0xa01577f4 */
extern void osd_api_set_text_mode(int mode, int layer); /* 0xa0146b6c */
extern void osd_api_set_glyph_write_address(int address, int layer); /* 0xa0146b50 */
extern void osd_api_fill_cells(int column, int row, int count, int value, int layer); /* 0xa0146a80 */
extern void osd_draw_text(int plane, int column, int row, int width, unsigned char *text, int layer); /* 0xa00a31a4 */

#define PLANE_0                  0
#define MENU_LAYER_MAIN          0
#define TEXT_ALIGN_CENTRE        2
#define HEADER_RATE_COLUMN       0xe
#define HEADER_RATE_ROW          2
#define HEADER_RATE_WIDTH        8       /* cells of the field */
#define HEADER_GLYPH_ADDRESS     0x1b5   /* glyph memory address given before the text is drawn */
#define CELL_TEXT_FIELD          0x596   /* value the text field is cleared with */
#define TEXT_BUFFER_SIZE         16

/* Redraw the refresh rate in the header of the menu as 'n HZ' (the rounded incoming refresh rate from
 * input_user_get_rounded_refresh_rate, for example '60 HZ'). The field at column 0xE, row 2 (8 cells) is
 * cleared first. Called every 100 ms by osd_run_periodic_task while the menu state is one of the header
 * states. */
void osd_update_header_refresh_rate(void)
{
    unsigned char text[TEXT_BUFFER_SIZE];
    unsigned int refresh_rate;
    unsigned char length;
    unsigned char next_length;

    refresh_rate = input_user_get_rounded_refresh_rate();
    sprintf(text, "n%d HZ", (unsigned short)refresh_rate);

    length = 0;
    do {
        if (text[length & 0xff] == 0)
            break;
        length++;
        next_length = (unsigned char)length;
    } while (next_length <= TEXT_BUFFER_SIZE - 1);

    text[0] = length - 1;
    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(HEADER_GLYPH_ADDRESS, 0);
    osd_api_fill_cells(HEADER_RATE_COLUMN, HEADER_RATE_ROW, HEADER_RATE_WIDTH, CELL_TEXT_FIELD, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, HEADER_RATE_COLUMN, HEADER_RATE_ROW, HEADER_RATE_WIDTH, text, MENU_LAYER_MAIN);
}
