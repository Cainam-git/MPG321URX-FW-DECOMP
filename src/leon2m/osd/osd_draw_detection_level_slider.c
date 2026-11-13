/* osd_draw_detection_level_slider  (FUN_a00b7e68)
 *
 * Draw a logo/taskbar/boundary detection level slider with its number.
 *   editing: 1 = being edited
 *   bar_value
 *   number: number shown
 * Name basis: proven - callers osd_show_detection_level_slider, osd_increase_detection_level,
 *   osd_decrease_detection_level
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7e68 @ 0xa00b7e68-0xa00b7f9c (77 words), flags -mcpu=v8 -O3 -g.
 * Source form: the cell value is assigned in both arms (the non-zero arm first) instead of a default before the
 * if (a default changes where the first value is scheduled); the first parameter is an unsigned char.
 */
#define GLYPH_WRITE_ADDRESS     0x111
#define SLIDER_COLUMN           0x2c
#define SLIDER_ROW              6
#define SLIDER_KIND_WITH_GUIDE  6               /* kind argument of osd_draw_value_slider */
#define NUMBER_GLYPH_ADDRESS    0xe6            /* glyph memory address given before the number is drawn */
#define CELL_SLIDER_ACTIVE      0x742           /* cell value of the row while its slider is being adjusted */
#define CELL_BLANK              0x792           /* cell value of the row when it is not adjusted */
#define KEY_GUIDE_GROUP         1
#define KEY_GUIDE_ADJUSTING     3
#define KEY_GUIDE_IDLE          2
#define TEXT_MODE_NUMBER        2

extern void osd_api_set_glyph_write_address(unsigned int, unsigned char);
extern void osd_draw_value_slider(unsigned int, unsigned int, unsigned char, unsigned int, unsigned int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_api_fill_cells(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern void sprintf(unsigned char *, unsigned int, unsigned char);
extern void osd_api_set_text_mode(unsigned int, unsigned int);
extern void osd_draw_text(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);

/*
 * Draw the level slider of an OLED Care detection (Multi Logo, Taskbar or Boundary): the bar, the number at
 * column 0x28 and the key guide.
 *
 *   editing    non-zero while the slider is being adjusted (cells take the active value, key guide shows its
 *              adjusting mode)
 *   bar_value  what the slider bar shows (the callers pass 1..100)
 *   number     the level printed as three digits
 */
void osd_draw_detection_level_slider(unsigned char editing, unsigned char bar_value, unsigned char number)
{
    unsigned short cell_value;
    unsigned char text[8];

    osd_api_set_glyph_write_address(GLYPH_WRITE_ADDRESS, 0);
    osd_draw_value_slider(SLIDER_COLUMN, SLIDER_ROW, bar_value, SLIDER_KIND_WITH_GUIDE, editing);

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

    /* The number as a length-prefixed text of three characters. */
    sprintf(text, "n%3d", number);
    text[0] = 3;
    osd_api_set_text_mode(TEXT_MODE_NUMBER, 0);
    osd_draw_text(0, 0x28, SLIDER_ROW, 2, text, 0);
}
