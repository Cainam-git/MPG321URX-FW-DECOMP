/* osd_draw_red_gain  (FUN_a00abe94)
 *
 * Draw the red gain slider of the custom colour page.
 *   active
 * Note: Settings byte +0x12, row 6.
 * Name basis: derived - called by osd_move_cursor_red_to_green / osd_move_cursor_green_to_red
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00abe94 @ 0xa00abe94, flags -mcpu=v8 -O3 -g.
 * Source form: osd_draw_value_slider is declared without a prototype and called with five arguments; the
 * settings base is written as the address constant (a local pointer), the cell value as the expression
 * ((active != 0) - 1 & 0x50) + 0x742, and the result of the last call is returned (a tail call).
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();

extern void osd_draw_value_slider();
extern void osd_api_fill_cells(undefined2 column, undefined2 row, undefined1 count, undefined2 value, undefined1 layer);
extern void osd_api_set_glyph_write_address(undefined2 address, undefined1 layer);
extern int osd_draw_three_digit_number(uint column, uint row, undefined1 value);

#define SETTINGS_BASE         0xa802d290    /* address of user_settings */
#define SETTING_RED_GAIN      0x12          /* user_settings byte: custom red gain */
#define RED_GAIN_ROW          6             /* menu row of the red gain slider (green 8, blue 0xA) */
#define GAIN_SLIDER_KIND      7
#define GAIN_NUMBER_COLUMN    0x29
#define RED_GAIN_GLYPH_ADDRESS 0xe6         /* glyph memory address given before the number is drawn */
#define CELL_SLIDER_ACTIVE    0x742         /* cell value of the row while its slider is being adjusted */
#define CELL_BLANK            0x792         /* cell value of the row when it is not adjusted */
#define MENU_LAYER_MAIN       0

/* Draw the Red Gain row of the custom colour page: slider bar and number, with the three label cell groups
 * in the active colours (CELL_SLIDER_ACTIVE) when 'active' is non-zero and blank (CELL_BLANK) when it is zero.
 * The value is user_settings byte +0x12. Returns the result of osd_draw_three_digit_number. */
int osd_draw_red_gain(int active)
{
    unsigned char flag;
    unsigned short cell_value;
    unsigned char *settings;

    flag = (unsigned char)active;
    cell_value = ((flag != '\0') - 1 & (CELL_BLANK - CELL_SLIDER_ACTIVE)) + CELL_SLIDER_ACTIVE;
    settings = (unsigned char *)SETTINGS_BASE;
    osd_draw_value_slider(0x2c, RED_GAIN_ROW, settings[SETTING_RED_GAIN], GAIN_SLIDER_KIND, flag);
    osd_api_fill_cells(0x28, RED_GAIN_ROW, 3, cell_value, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x2b, RED_GAIN_ROW, 1, cell_value, MENU_LAYER_MAIN);
    osd_api_fill_cells(0x32, RED_GAIN_ROW, 1, cell_value, MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(RED_GAIN_GLYPH_ADDRESS, 0);
    return osd_draw_three_digit_number(GAIN_NUMBER_COLUMN, RED_GAIN_ROW, settings[SETTING_RED_GAIN]);
}
