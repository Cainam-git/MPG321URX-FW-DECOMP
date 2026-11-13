/* osd_draw_input_quick_menu  (FUN_a00b5d10)
 *
 * Draw the input quick menu with the input names and the current one.
 * Name basis: derived - input names 0x196B24; called by osd_open_input_quick_menu and osd_dispatch_key_event
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b5d10 @ 0xa00b5d10-0xa00b60cc (956 bytes), flags -mcpu=v8 -O3 -g. Called by osd_open_input_quick_menu
 * and osd_dispatch_key_event (osd_open_input_quick_menu, osd_dispatch_key_event).
 * Source form: the two loops over the cell columns i + 10 compare with a limit variable row_limit = 2 (cmp 2; bcs),
 * the others with constants; prototypes and record layout as in osd_draw_navi_quick_menu (osd_draw_navi_quick_menu).
 */
/* Fields of the application state record used here. */
struct app_state_record_fields {
    unsigned char p00[0x3e];
    struct { unsigned short flag_15 : 1, rest : 15; } flags_0x3e;  /* +0x3E: flag_15 = bit 15 */
};
/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char p000[8];
    unsigned char language;                     /* +0x08: menu language (1 = English) */
    unsigned char p009[0x0d - 0x09];
    unsigned char menu_position_a, menu_position_b; /* +0x0D, +0x0E: the two position percentages of the menu */
    unsigned char p00f[0x1e - 0x0f];
    unsigned char input_source;                 /* +0x1E: Input Source */
    unsigned char p01f[0x1a3 - 0x1f];
    unsigned char byte_0x1a3;                   /* +0x1A3: row of the input quick menu */
};
extern struct app_state_record_fields app_state_record;
extern struct user_settings_record user_settings;
extern unsigned char osd_list_id;
extern unsigned int osd_navi_function_texts[], osd_input_name_texts[], osd_key_guide_texts[];

extern void osd_api_enable(int, int);
extern void osd_api_set_window_enable(int, int, int);
extern void panel_wait_sync_pulse(void);
extern void osd_set_layout(unsigned int);
extern void osd_api_set_reg_c8_ranges(int, int, int, int, int);
extern void osd_api_set_size_in_cells(int, int, int);
extern void osd_api_set_position(unsigned short, unsigned short, unsigned char);
extern void osd_api_write_reg_cc(int, int);
extern void osd_api_reset_layer(int);
extern int osd_get_cell_width(int);
extern void osd_api_set_origin_and_size(int, int, int);
extern void osd_draw_info_box(int, int, int);
extern void osd_draw_quick_menu_frame(unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void osd_highlight_quick_menu_row(unsigned char, unsigned char);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

#define MENU_LAYER_MAIN       0
#define CROSSHAIR_LAYER       1
#define ALL_WINDOWS           8
#define OSD_LIST_QUICK_MENU   0x24    /* osd_list_id; osd_draw_navi_quick_menu sets the same value */
#define LAYOUT_QUICK_MENU     2       /* osd_set_layout 2: 22 x 17 cells */
#define QUICK_MENU_COLUMNS    0x16
#define QUICK_MENU_ROWS       0x11
#define CELL_BLANK            0x792   /* cell value of an empty menu cell (the layer background) */
#define KEY_GUIDE_CELL        0x592   /* cell value written under the title and the key guide texts */
#define TEXTS_PER_ITEM        29      /* a text table holds one text per menu language for every item */
#define NAVI_FUNCTION_INPUT_SOURCE 5  /* the title is item 5 of osd_navi_function_texts */
#define TEXT_ALIGN_LEFT       0       /* osd_api_set_text_mode */
#define TEXT_ALIGN_CENTRE     2
#define PLANE_0               0
#define INPUT_NAME_COUNT      4       /* input names listed on the menu: rows 5, 7, 9 and 11 */

#define T user_settings

/* Draw the input quick menu (the Navi Key function Input Source) from scratch on the main menu layer.
 * Order: switch the layers and all windows off, set osd_list_id to 0x24, clear flag 15 of
 * app_state_record +0x3E, wait two sync pulses, select layout 2 and size, position and background of the layer
 * (position from settings bytes +0x0D / +0x0E, origin x = 0x780 - 11 * cell height code, y = 0x57c). Then the
 * title (item 5 of osd_navi_function_texts in the menu language), the four input names from
 * osd_input_name_texts at column 6, rows 5, 7, 9 and 11, the highlight of the row of the current input
 * (settings byte +0x1E through the menu-index-to-source table; input numbers above 3 are drawn on row
 * number - 4), two marker cells next to that row, and the key guide texts at row 0xf. Settings byte
 * +0x1A3 is set to a copy of byte +0x1E.
 * The set-up sequence up to the layer background is the same as in osd_draw_navi_quick_menu. */
void osd_draw_input_quick_menu(void)
{
    unsigned char i, input_row, row_limit;
    unsigned char cell_height_code;

    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, MENU_LAYER_MAIN);
    osd_list_id = OSD_LIST_QUICK_MENU;
    osd_api_enable(0, CROSSHAIR_LAYER);
    app_state_record.flags_0x3e.flag_15 = 0;
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_set_layout(LAYOUT_QUICK_MENU);
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, MENU_LAYER_MAIN);
    osd_api_set_reg_c8_ranges(0, 0, 0, 0, 0);
    osd_api_set_size_in_cells(QUICK_MENU_COLUMNS, QUICK_MENU_ROWS, MENU_LAYER_MAIN);
    osd_api_set_position(T.menu_position_a, T.menu_position_b, MENU_LAYER_MAIN);
    osd_api_write_reg_cc(CELL_BLANK, MENU_LAYER_MAIN);
    osd_api_reset_layer(MENU_LAYER_MAIN);
    cell_height_code = osd_get_cell_width(0);
    osd_api_set_origin_and_size((unsigned short)(0x780 - cell_height_code * 11), 0x57c, MENU_LAYER_MAIN);
    osd_draw_info_box(0, 0, 2);
    osd_draw_quick_menu_frame(5);
    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(0x60, MENU_LAYER_MAIN);
    osd_api_fill_cells(3, 1, 0x10, KEY_GUIDE_CELL, 0);
    osd_draw_text(PLANE_0, 3, 1, 0x10, osd_get_text(osd_navi_function_texts, T.language + NAVI_FUNCTION_INPUT_SOURCE * TEXTS_PER_ITEM), 0);
    osd_api_write_reg_cc(CELL_BLANK, MENU_LAYER_MAIN);
    row_limit = 2;
    for (i = 0; i < row_limit; i++)
        osd_api_fill_cell_bytes(1, i + 10, 3, 1, i + 0x16, 0);
    osd_api_write_reg_cc(CELL_BLANK, MENU_LAYER_MAIN);
    for (i = 0; i < row_limit; i++)
        osd_api_fill_cell_bytes(1, i + 10, 0xd, 1, i + 0x18, 0);
    for (i = 0; i <= 3; i++)
        osd_draw_text(PLANE_0, 6, i * 2 + 5, 0xa, osd_get_text(osd_input_name_texts, i), 0);
    osd_highlight_quick_menu_row(input_api_source_id_to_menu_index(T.input_source), 1);
    osd_highlight_quick_menu_row(input_api_source_id_to_menu_index(T.input_source), 0);
    input_row = input_api_source_id_to_menu_index(T.input_source);
    if (input_row > 3)
        input_row -= 4;
    for (i = 0; i <= 1; i++)
        osd_api_fill_cell_bytes(0, i + 4, input_row * 2 + 5, 1, i + 0x1c, 0);
    T.byte_0x1a3 = T.input_source;
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, 0);
    osd_api_fill_cells(6, 0xf, 6, KEY_GUIDE_CELL, 0);
    osd_api_fill_cells(0xf, 0xf, 6, KEY_GUIDE_CELL, 0);
    osd_draw_text(PLANE_0, 6, 0xf, 1, osd_get_text(osd_key_guide_texts, T.language), 0);
    osd_draw_text(PLANE_0, 0xf, 0xf, 1, osd_get_text(osd_key_guide_texts, T.language + 4 * TEXTS_PER_ITEM), 0);
}
