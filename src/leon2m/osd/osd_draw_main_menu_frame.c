/* osd_draw_main_menu_frame  (FUN_a00b5378)
 *
 * Set up the main menu layer and draw its frame, tabs and header.
 * Name basis: derived - called by osd_open_main_menu, osd_close_position_editor, osd_redraw_page_after_notice
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b5378 @ 0xa00b5378, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - hide_menu and setup_layer_window are static copies of osd_hide_menu and osd_setup_layer_window (the
 *    routines just before this one), inlined here;
 *  - the bytes of user_settings are indexed from one array symbol (one base register).
 */
/* Application state halfword +0x3E: bit 15 is cleared when the menu is hidden. */
struct app_state_record { unsigned char pad[0x3e]; unsigned short bit15_0x3e : 1, rest : 15; };
extern struct app_state_record app_state_record;
extern unsigned char osd_list_id;
extern unsigned char user_settings[];
extern unsigned int osd_key_guide_texts[];
extern void osd_api_enable(int, int);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_reg_c8_ranges(int, int, int, int, int);
extern void osd_api_set_size_in_cells(int, int, int);
extern void osd_api_set_position(int, int, int);
extern void osd_api_write_reg_cc(int, int);
extern int osd_api_reset_layer(int);
extern void panel_wait_sync_pulse(void);
extern void osd_set_layout(unsigned int);
extern unsigned short panel_api_get_active_size(int);
extern void osd_api_set_origin_and_size(unsigned short, unsigned short, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void osd_draw_menu_header(void);
extern void osd_draw_cell_run(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);
extern void osd_draw_tab_icons(unsigned char);
extern void osd_draw_tab_names(unsigned char);
extern void osd_draw_adjust_key_guide(void);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void osd_update_key_guide(unsigned int, unsigned int);
extern void osd_draw_key_guide(unsigned int, unsigned int);
extern void osd_draw_signal_info_header(void);

/* Byte offsets in the user settings record. */
#define SETTINGS_LANGUAGE       0x08    /* menu language */
#define SETTINGS_BYTE_0x0D      0x0d    /* first argument of osd_api_set_position */
#define SETTINGS_BYTE_0x0E      0x0e    /* second argument of osd_api_set_position */
#define SETTINGS_BYTE_0x189     0x189
#define SETTINGS_BYTE_0x1A3     0x1a3

#define TEXTS_PER_ITEM          29      /* a text table holds one text per menu language for every item */
#define KEY_GUIDE_EXIT          (6 * TEXTS_PER_ITEM)    /* text 6 of the key guide table: 'Exit' */
#define KEY_GUIDE_COLUMN        0x37
#define KEY_GUIDE_ROW           9

#define MENU_LAYER_MAIN         0       /* the layer osd_show_menu_layer switches on */
#define ALL_WINDOWS             8       /* window number that means all eight windows */
#define PANEL_SIZE_WIDTH        0       /* panel_api_get_active_size(0): the active width */

/* The main menu layer in character cells. */
#define MENU_COLUMNS            0x3c
#define MENU_ROWS               0x17
#define LEFT_EDGE_COLUMN        0
#define RIGHT_EDGE_COLUMN       0x3b
#define BOTTOM_ROW              0x16
#define CELL_BLANK              0x792   /* cell value of an empty menu cell (the layer background) */
#define CELL_FRAME              0x8a2   /* cell value of the outer frame */

/* Copy of osd_hide_menu: switch layer 0 and its windows off, set osd_list_id to 0x24, switch layer 1 off and
   clear bit 15 of application state halfword +0x3E. */
static void hide_menu(void)
{
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, 0);
    osd_list_id = 0x24;
    osd_api_enable(0, 1);
    app_state_record.bit15_0x3e = 0;
}

/* Copy of osd_setup_layer_window: reset layer 0 with `columns` x `rows` cells and the background cell value,
   at the position from settings bytes +0x0D / +0x0E. */
static int setup_layer_window(int columns, int rows, int background)
{
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, 0);
    osd_api_set_reg_c8_ranges(0, 0, 0, 0, 0);
    osd_api_set_size_in_cells((unsigned short)columns, rows & 0xff, 0);
    osd_api_set_position(user_settings[SETTINGS_BYTE_0x0D], user_settings[SETTINGS_BYTE_0x0E], 0);
    osd_api_write_reg_cc((unsigned short)background, 0);
    return osd_api_reset_layer(0);
}

/*
 * Set up menu layer 0 for the main menu and draw everything that does not depend on the open tab: the outer
 * frame, the top rows, the line under them, fixed glyph runs, the first page of the tab column (icons and
 * names), the key guide column and the header line with the signal information. This routine does not switch
 * the layer on.
 *
 * Callers: osd_open_main_menu, osd_close_position_editor and osd_redraw_page_after_notice.
 *
 * Phases:
 *   1. Hide the menu, wait two sync pulses, load layout 0 and reset the layer to 0x3C x 0x17 cells; the layer
 *      origin is (active panel width - 1440) / 2, 0x4A4.
 *   2. Outer frame: top row, both edge columns, bottom row.
 *   3. The top rows and the line of row 3.
 *   4. Fixed glyph runs.
 *   5. Tab icons and names of the first page, the key guide ('Exit' and the key icons) and the header line.
 *      Settings byte +0x189 is set to 0xFF and +0x1A3 to 0.
 */
void osd_draw_main_menu_frame(void)
{
    unsigned char i;
    unsigned short row;

    /* Phase 1: hide the menu and set up layer 0 for the main menu. */
    hide_menu();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_set_layout(0);
    setup_layer_window(MENU_COLUMNS, MENU_ROWS, CELL_BLANK);
    osd_api_set_origin_and_size((panel_api_get_active_size(PANEL_SIZE_WIDTH) - 1440) / 2, 0x4a4, 0);
    /* Phase 2: outer frame. Top row: corner glyph 0x0B, 0x3A cells of glyph 0x0C, corner 0x0D. */
    osd_api_fill_cells(0, 0, MENU_COLUMNS, CELL_FRAME, 0);
    osd_api_fill_cell_bytes(0, 0, 0, 1, 0xb, 0);
    osd_api_fill_cell_bytes(0, 1, 0, 0x3a, 0xc, 0);
    osd_api_fill_cell_bytes(0, RIGHT_EDGE_COLUMN, 0, 1, 0xd, 0);
    /* Rows 1..0x15: glyph 0x0E in the left edge column, 0x0F in the right one. */
    for (i = 0; i <= 0x14; i++) {
        row = i + 1;
        osd_api_fill_cells(LEFT_EDGE_COLUMN, row, 1, CELL_FRAME, 0);
        osd_api_fill_cells(RIGHT_EDGE_COLUMN, row, 1, CELL_FRAME, 0);
        osd_api_fill_cell_bytes(0, LEFT_EDGE_COLUMN, row, 1, 0xe, 0);
        osd_api_fill_cell_bytes(0, RIGHT_EDGE_COLUMN, row, 1, 0xf, 0);
    }
    /* Bottom row: glyphs 0x10, 0x11 (0x3A cells), 0x12. */
    osd_api_fill_cells(0, BOTTOM_ROW, MENU_COLUMNS, CELL_FRAME, 0);
    osd_api_fill_cell_bytes(0, 0, BOTTOM_ROW, 1, 0x10, 0);
    osd_api_fill_cell_bytes(0, 1, BOTTOM_ROW, 0x3a, 0x11, 0);
    osd_api_fill_cell_bytes(0, RIGHT_EDGE_COLUMN, BOTTOM_ROW, 1, 0x12, 0);
    /* Phase 3: the top rows (osd_draw_menu_header), then the line of row 3 across the whole layer: cell value
       0x14AA on columns 0..0x10, 0x179E from column 0x11 on. */
    osd_draw_menu_header();
    osd_api_fill_cells(0, 3, 0x11, 0x14aa, 0);
    osd_api_fill_cell_bytes(0, 0, 3, 1, 0x23, 0);
    osd_api_fill_cell_bytes(0, 1, 3, 1, 0x24, 0);
    osd_api_fill_cell_bytes(0, 2, 3, 9, 0x25, 0);
    osd_api_fill_cell_bytes(0, 0xb, 3, 1, 0x26, 0);
    osd_api_fill_cell_bytes(0, 0xc, 3, 1, 0x27, 0);
    osd_api_fill_cell_bytes(0, 0xd, 3, 1, 0x28, 0);
    osd_api_fill_cell_bytes(0, 0xe, 3, 3, 0x29, 0);
    osd_api_fill_cells(0x11, 3, 0x2b, 0x179e, 0);
    osd_draw_cell_run(1, 1, 0x179e, 0x11, 3, 4, 1);
    osd_api_fill_cell_bytes(0, 0x15, 3, 2, 5, 0);
    osd_api_fill_cell_bytes(0, 0x17, 3, 1, 6, 0);
    osd_api_fill_cell_bytes(0, 0x18, 3, 10, 7, 0);
    osd_api_fill_cell_bytes(0, 0x22, 3, 1, 8, 0);
    osd_api_fill_cell_bytes(0, 0x23, 3, 1, 9, 0);
    osd_api_fill_cell_bytes(0, 0x24, 3, 10, 10, 0);
    osd_api_fill_cell_bytes(0, 0x2e, 3, 1, 0xb, 0);
    osd_api_fill_cell_bytes(0, 0x2f, 3, 3, 0xc, 0);
    osd_draw_cell_run(1, 1, 0x179e, 0x32, 3, 10, 0xd);
    /* Phase 4: fixed glyph runs: down runs in columns 0x16, 0x21, 0x28 and 0x35 (rows 1..2, and column 0x35 down to
       row 0x16), runs in rows 0..5 at the top and right, runs in rows 0x14..0x16 at the bottom right. */
    osd_draw_cell_run(0, 1, 0x992, 0x16, 1, 2, 0x24);
    osd_draw_cell_run(0, 1, 0x992, 0x21, 1, 2, 0x24);
    osd_draw_cell_run(0, 1, 0x992, 0x28, 1, 2, 0x24);
    osd_draw_cell_run(0, 1, 0x992, 0x35, 1, 2, 0x24);
    osd_draw_cell_run(0, 0, 0x992, 0x35, 4, 0x12, 0x26);
    osd_draw_cell_run(0, 0, 0x992, 0x35, 0x16, 1, 0x27);
    osd_draw_cell_run(1, 1, 0x21aa, 10, 0, 5, 0x2a);
    osd_draw_cell_run(1, 1, 0x3092, 9, 1, 2, 0x13);
    osd_draw_cell_run(1, 0, 0x21aa, 0xb, 1, 1, 0x2f);
    osd_draw_cell_run(1, 1, 0x3392, 0xc, 1, 2, 0x15);
    osd_draw_cell_run(1, 0, 0x3092, 0x3a, 2, 1, 0x17);
    osd_draw_cell_run(0, 1, 0x21aa, 0x3b, 1, 2, 0x30);
    osd_draw_cell_run(1, 1, 0x3292, 0x38, 4, 2, 0x18);
    osd_draw_cell_run(1, 1, 0x3292, 0x38, 5, 1, 0x1a);
    osd_draw_cell_run(1, 1, 0x249a, 0x3a, 4, 2, 0x32);
    osd_draw_cell_run(1, 1, 0x249a, 0x39, 5, 3, 0x34);
    osd_draw_cell_run(1, 0, 0x3092, 0x24, 0x15, 1, 0x1b);
    osd_draw_cell_run(1, 1, 0x3392, 0x26, 0x15, 2, 0x1c);
    osd_draw_cell_run(1, 1, 0x279a, 0x25, 0x15, 1, 0x37);
    osd_draw_cell_run(1, 1, 0x279a, 0x23, 0x16, 3, 0x38);
    osd_draw_cell_run(1, 1, 0x2aaa, 0x26, 0x16, 1, 0x3b);
    osd_draw_cell_run(1, 1, 0x2d9a, 0x28, 0x15, 2, 0x3c);
    osd_draw_cell_run(1, 1, 0x2d9a, 0x27, 0x16, 3, 0x3e);
    osd_draw_cell_run(1, 1, 0x3292, 0x33, 0x14, 2, 0x1e);
    osd_draw_cell_run(1, 1, 0x3392, 0x30, 0x15, 2, 0x20);
    osd_draw_cell_run(1, 1, 0x3292, 0x33, 0x15, 2, 0x22);
    osd_draw_cell_run(1, 1, 0x249a, 0x35, 0x14, 1, 0x41);
    osd_draw_cell_run(1, 1, 0x249a, 0x32, 0x15, 1, 0x42);
    osd_draw_cell_run(1, 1, 0x249a, 0x35, 0x15, 1, 0x43);
    osd_draw_cell_run(1, 1, 0x249a, 0x2f, 0x16, 5, 0x44);
    /* Phase 5: first page of the tab column, then the key guide column and the header line. */
    osd_draw_tab_icons(0);
    osd_draw_tab_names(0);
    /* Settings byte +0x189 is set to 0xFF here, as when the OLED Care list is left. */
    user_settings[SETTINGS_BYTE_0x189] = 0xff;
    osd_draw_adjust_key_guide();
    /* 'Exit' in the key guide column, as osd_highlight_tab draws it for style 1. */
    osd_api_set_glyph_write_address(0x1e5, 0);
    osd_api_set_text_mode(2, 0);
    osd_api_fill_cells(KEY_GUIDE_COLUMN, KEY_GUIDE_ROW, 4, 0x596, 0);
    osd_draw_text(0, KEY_GUIDE_COLUMN, KEY_GUIDE_ROW, 4, osd_get_text(osd_key_guide_texts, user_settings[SETTINGS_LANGUAGE] + KEY_GUIDE_EXIT), 0);
    osd_update_key_guide(0, 1);
    osd_draw_key_guide(2, 5);
    osd_draw_key_guide(0, 0);
    osd_draw_key_guide(1, 2);
    osd_draw_signal_info_header();
    /* Settings byte +0x1A3 starts at 0 each time the main menu is drawn. */
    user_settings[SETTINGS_BYTE_0x1A3] = 0;
}
