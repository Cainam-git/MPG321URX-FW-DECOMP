/* osd_draw_static_screen_level_slider  (FUN_a00b7d14)
 *
 * Draw the Static Screen Detection reduce-level slider.
 *   editing: 1 = being edited
 * Note: Value = settings byte +0x1DF x 17 (100 above 5).
 * Name basis: proven - callers osd_open_static_screen_reduce_level, osd_increase_static_screen_reduce_level
 *   ...
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b7d14 @ 0xa00b7d14-0xa00b7e68 (85 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the setting is read from the byte array itself (not through a local
 * base pointer); the cell value is assigned in BOTH arms with the non-zero arm first (a default before the if
 * moves the first value into the branch delay slot); the parameter is tested as (p & 0xff); the bar value is a
 * 32-bit variable passed on as a byte.
 */
#define SETTING_STATIC_SCREEN_LEVEL 0x1df       /* user_settings byte: Static Screen Detection reduce level */
#define STATIC_SCREEN_LEVEL_SCALE   17          /* bar value per level step */
#define STATIC_SCREEN_LEVEL_FULL    5           /* levels above this fill the bar (100) */
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

extern unsigned char user_settings[];
extern void osd_api_set_glyph_write_address(unsigned int, unsigned char);
extern void osd_draw_value_slider(unsigned int, unsigned int, unsigned char, unsigned int, unsigned int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_api_fill_cells(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern void sprintf(unsigned char *, unsigned int, unsigned char);
extern void osd_api_set_text_mode(unsigned int, unsigned int);
extern void osd_draw_text(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);

/*
 * Draw the slider of the Static Screen Detection reduce level: the bar, the number at column 0x28 and the key
 * guide.
 *
 *   editing  non-zero while the slider is being adjusted (cells take the active value, key guide shows its
 *            adjusting mode)
 *
 * The setting is user_settings byte +0x1DF. The bar is given the setting times 17, or 100 when the setting is
 * above 5; the number shown is the setting plus 1.
 */
void osd_draw_static_screen_level_slider(unsigned int editing)
{
    unsigned short cell_value;
    unsigned int bar_value;
    unsigned char text[8];

    bar_value = user_settings[SETTING_STATIC_SCREEN_LEVEL] * STATIC_SCREEN_LEVEL_SCALE;
    if (user_settings[SETTING_STATIC_SCREEN_LEVEL] > STATIC_SCREEN_LEVEL_FULL)
        bar_value = 100;
    osd_draw_value_slider(SLIDER_COLUMN, SLIDER_ROW, bar_value, SLIDER_KIND_WITH_GUIDE, editing & 0xff);
    if ((editing & 0xff) != 0) {
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
    sprintf(text, "n%3d", user_settings[SETTING_STATIC_SCREEN_LEVEL] + 1);
    text[0] = 3;
    osd_api_set_text_mode(TEXT_MODE_NUMBER, 0);
    osd_draw_text(0, 0x28, SLIDER_ROW, 2, text, 0);
}
