/* osd_draw_color_gain_labels  (FUN_a00b72cc)
 *
 * Draw the R, G and B labels of the custom colour gains.
 * Name basis: proven - texts 0x197d08 'R|G|B'; called by osd_draw_custom_color_page
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b72cc @ 0xa00b72cc-0xa00b7474 (106 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two wrapped cases (language 0x13, and language 0xd with label 0 or 2) are separate if arms
 * with identical bodies (merged by the compiler); one '||' over both tests gives a different block layout.
 */
#define GLYPH_WRITE_ADDRESS   0xd7
#define TEXT_MODE_NORMAL      0
#define TEXT_MODE_NUMBER      2                 /* the mode the labels are drawn in unless the language below is set */
#define LABEL_COLUMN          0x28
#define LANGUAGE_COUNT        29                /* text index = entry * 29 + language byte of the settings */
#define LABEL_COUNT           3                 /* R, G, B */
#define LANGUAGE_19           0x13              /* languages whose labels are drawn in text mode 0 ... */
#define LANGUAGE_13           0xd               /* ... (this one only for labels 0 and 2) */
#define CELL_BLANK            0x792

struct user_settings_record {
    unsigned char pad[8];
    unsigned char language;                     /* +8: selects the text of the menu language */
};
extern struct user_settings_record user_settings;
extern unsigned int osd_color_gain_label_texts[];
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(int, int, unsigned int, int, unsigned int, int);

/*
 * Draw the three labels R, G and B of the custom colour gains at column 0x28, rows 6, 8 and 10, and blank the
 * cells at columns 0x2b and 0x32 of each of those rows (setting their byte-plane values to 0x3f and 0x40).
 * Called by osd_draw_custom_color_page.
 */
void osd_draw_color_gain_labels(void)
{
    unsigned char i;
    unsigned int row;

    osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
    osd_api_set_text_mode(TEXT_MODE_NUMBER, 0);
    for (i = 0; i <= LABEL_COUNT - 1; i++) {
        /* For these two languages the label is drawn in text mode 0. */
        if (user_settings.language == LANGUAGE_19) {
            osd_api_set_text_mode(TEXT_MODE_NORMAL, 0);
            osd_draw_text(0, LABEL_COLUMN, i * 2 + 6, 1, osd_get_text(osd_color_gain_label_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
            osd_api_set_text_mode(TEXT_MODE_NUMBER, 0);
        } else if ((i == 0 || i == 2) && user_settings.language == LANGUAGE_13) {
            osd_api_set_text_mode(TEXT_MODE_NORMAL, 0);
            osd_draw_text(0, LABEL_COLUMN, i * 2 + 6, 1, osd_get_text(osd_color_gain_label_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
            osd_api_set_text_mode(TEXT_MODE_NUMBER, 0);
        } else
            osd_draw_text(0, LABEL_COLUMN, i * 2 + 6, 1, osd_get_text(osd_color_gain_label_texts, i * LANGUAGE_COUNT + user_settings.language), 0);
        row = i * 2 + 6;
        osd_api_fill_cells(0x2b, row, 1, CELL_BLANK, 0);
        osd_api_fill_cell_bytes(0, 0x2b, row, 1, 0x3f, 0);
        osd_api_fill_cells(0x32, row, 1, CELL_BLANK, 0);
        osd_api_fill_cell_bytes(0, 0x32, row, 1, 0x40, 0);
    }
    osd_api_set_text_mode(TEXT_MODE_NORMAL, 0);
}
