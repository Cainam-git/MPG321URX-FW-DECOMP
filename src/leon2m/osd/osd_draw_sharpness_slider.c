/* osd_draw_sharpness_slider  (FUN_a00b7188)
 *
 * Draw the Sharpness slider with its value and key guide.
 *   editing: 1 = slider is being edited (highlighted)
 * Note: Value = settings byte +0x49 x 20; drawn highlighted while being edited.
 * Name basis: proven - callers osd_open_sharpness_slider, osd_increase_sharpness ...
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7188 @ 0xa00b7188-0xa00b72cc (81 words), flags -mcpu=v8 -O3 -g.
 * Source form: the cell value and the key guide call are set in both arms of the if; there is no mask on the
 * cell value (the 16-bit variable is only zero-extended); the record is a struct with the Sharpness byte as
 * its field. Unlike the Contrast and Brightness twins the slider is given the setting times 20.
 */
#define SLIDER_COLUMN           0x2c
#define SLIDER_ROW              6
#define SLIDER_KIND_WITH_GUIDE  6               /* kind argument of osd_draw_value_slider */
#define SHARPNESS_SLIDER_SCALE  20              /* the slider is given the setting times 20 */
#define NUMBER_GLYPH_ADDRESS    0xe6            /* glyph memory address given before the number is drawn */
#define CELL_SLIDER_ACTIVE      0x742           /* cell value of the row while its slider is being adjusted */
#define CELL_BLANK              0x792           /* cell value of the row when it is not adjusted */
#define KEY_GUIDE_GROUP         1
#define KEY_GUIDE_ADJUSTING     3
#define KEY_GUIDE_IDLE          2
#define TEXT_MODE_NUMBER        2

struct user_settings_record {
    unsigned char pad[0x49];
    unsigned char sharpness;                    /* +0x49: the Sharpness setting */
};
extern struct user_settings_record user_settings;
extern void osd_api_set_glyph_write_address(unsigned int, unsigned char);
extern void osd_draw_value_slider(unsigned int, unsigned int, unsigned char, unsigned int, unsigned int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_api_fill_cells(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern void sprintf(unsigned char *, unsigned int, unsigned char);
extern void osd_api_set_text_mode(unsigned int, unsigned int);
extern void osd_draw_text(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);

/*
 * Draw the Sharpness row: the slider bar, the value as three digits at column 0x28, and the
 * key guide.
 *
 *   editing  non-zero while the slider is being adjusted: the cells take the active value and the key guide
 *            shows its adjusting mode
 *
 * The number shown is the Sharpness setting (user_settings byte +0x49); the slider bar is given the setting
 * times 20.
 */
void osd_draw_sharpness_slider(unsigned char editing)
{
    unsigned short cell_value;
    unsigned char text[8];

    osd_draw_value_slider(SLIDER_COLUMN, SLIDER_ROW, user_settings.sharpness * SHARPNESS_SLIDER_SCALE, SLIDER_KIND_WITH_GUIDE, editing);

    if (editing != 0) {
        cell_value = CELL_SLIDER_ACTIVE;
        osd_draw_key_guide(KEY_GUIDE_GROUP, KEY_GUIDE_ADJUSTING);
    } else {
        cell_value = CELL_BLANK;
        osd_draw_key_guide(KEY_GUIDE_GROUP, KEY_GUIDE_IDLE);
    }

    osd_api_fill_cells(0x28, SLIDER_ROW, 3, cell_value, 0);
    osd_api_fill_cells(0x2b, SLIDER_ROW, 1, cell_value, 0);
    osd_api_fill_cell_bytes(0, 0x2b, SLIDER_ROW, 1, 0x3f, 0);
    osd_api_fill_cells(0x32, SLIDER_ROW, 1, cell_value, 0);
    osd_api_fill_cell_bytes(0, 0x32, SLIDER_ROW, 1, 0x40, 0);
    osd_api_set_glyph_write_address(NUMBER_GLYPH_ADDRESS, 0);

    /* The value as a length-prefixed text of three characters. */
    sprintf(text, "n%3d", user_settings.sharpness);
    text[0] = 3;
    osd_api_set_text_mode(TEXT_MODE_NUMBER, 0);
    osd_draw_text(0, 0x28, SLIDER_ROW, 2, text, 0);
}
