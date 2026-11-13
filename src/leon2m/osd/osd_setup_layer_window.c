/* osd_setup_layer_window  (FUN_a00b52f8)
 *
 * Reset the menu layer and set its size in cells, position and background.
 *   columns
 *   rows
 *   attribute: background attribute
 * Returns: osd_api_reset_layer result
 * Note: Position from settings bytes +0xD / +0xE.
 * Name basis: derived - osd_api_set_size_in_cells, osd_api_set_position, osd_api_write_reg_cc,
 *   osd_api_reset_layer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b52f8 @ 0xa00b52f8, flags -mcpu=v8 -O3 -g.
 * Source form: the settings base is the address constant 0xa802d290 held in a local pointer inside a braced
 * block; the last call is a tail call and its result is returned.
 */
extern void osd_api_enable(int on, int layer);
extern void osd_api_set_window_enable(int window, int on, int unused);
extern void osd_api_set_reg_c8_ranges(int, int, int, int, int);
extern void osd_api_set_size_in_cells(int columns, int rows, int layer);
extern void osd_api_set_position(int x, int y, int layer);
extern void osd_api_write_reg_cc(int value, int layer);
extern int osd_api_reset_layer(int layer);

#define SETTINGS_BASE           0xa802d290   /* address of user_settings */
#define SETTING_MENU_POSITION_A 0xd          /* user_settings bytes: the menu position (percentages) */
#define SETTING_MENU_POSITION_B 0xe
#define MENU_LAYER_MAIN         0
#define ALL_WINDOWS             8

/* Reset the menu layer for a new page layout: the layer and all its windows are switched off, the layer
 * is given the size columns x rows (in cells), is placed at the menu position of the user settings (bytes +0xD and
 * +0xE), gets the background attribute and is reset. Returns the result of osd_api_reset_layer.
 *   columns:   width in cells.
 *   rows:      height in cells.
 *   attribute: background value written to registers 0xCC/0xCD. */
int osd_setup_layer_window(int columns, int rows, int attribute) {
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, 0);
    osd_api_set_reg_c8_ranges(0, 0, 0, 0, 0);
    osd_api_set_size_in_cells((unsigned short)columns, rows & 0xff, 0);
    {
        unsigned char *settings = (unsigned char *)SETTINGS_BASE;
        osd_api_set_position(settings[SETTING_MENU_POSITION_A], settings[SETTING_MENU_POSITION_B], 0);
    }
    osd_api_write_reg_cc((unsigned short)attribute, 0);
    return osd_api_reset_layer(MENU_LAYER_MAIN);
}
