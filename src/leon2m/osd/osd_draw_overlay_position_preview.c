/* osd_draw_overlay_position_preview  (FUN_a00a6b98)
 *
 * Draw the overlay being positioned (crosshair, refresh rate or alarm timer)
 *   overlay: overlay 0..2
 *   set_up: draw mode
 *   erase: flag
 * Note: Called when a position editor opens, by the periodic menu task, and around each move of the Refresh
 *   Rate and Alarm Clock boxes; the crosshair is moved without it.
 * Name basis: derived - callers osd_open_crosshair_position / _refresh_rate_position / _alarm_clock_position,
 *   osd_move_overlay_*, osd_run_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a6b98 @ 0xa00a6b98-0xa00a788c (3316 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the Refresh Rate location choice is a flat if-chain; the Alarm Clock one sets the row before its inner tests
 *    and the column to 2 inside the LEFT_TOP and LEFT_BOTTOM arms;
 *  - the 'set_up == 0' call is a separate if after the 'set_up == 1' block;
 *  - the two boxes are static helpers (draw_alarm_clock_box / draw_refresh_rate_box) with the row and the erase
 *    flag as unsigned char parameters; draw_alarm_clock_box uses one byte counter for all its row loops;
 *  - the crosshair colour rows and the 3 x 4 crosshair cells go through static helpers with unsigned short
 *    parameters (as in osd_show_screen_overlays);
 *  - the icon selection is an if-chain with a final else;
 *  - osd_setup_layer_window is declared void (its result is not used).
 */
/* The fields of the user settings record used here (same layout as in osd_show_screen_overlays). */
struct user_settings_record {
    unsigned char pad000[0xd];
    unsigned char menu_position_a, menu_position_b; /* +0x0D, +0x0E: the two position percentages of the menu
                                                       layer (osd_user_apply_menu_position) */
    unsigned char pad00f[0xa8 - 0xf];
    unsigned int gaming_flags;                  /* +0xA8: not read here */
    unsigned int settings_page_flags;           /* +0xAC: not read here */
    unsigned char pad0b0[0x13e - 0xb0];
    unsigned char refresh_rate_location;        /* +0x13E: location of the Refresh Rate overlay (OVERLAY_LOCATION_*) */
    unsigned char alarm_clock_location;         /* +0x13F: location of the Alarm Clock overlay (OVERLAY_LOCATION_*) */
    unsigned char pad140[0x17b - 0x140];
    unsigned char crosshair_color;              /* +0x17B: Smart Crosshair colour (CROSSHAIR_COLOR_AUTO = automatic) */
    unsigned char pad17c[0x190 - 0x17c];
    unsigned char crosshair_icon;               /* +0x190: Smart Crosshair icon 1..6 (0 = off) */
    unsigned char pad191[0x1a0 - 0x191];
    union { unsigned int word; unsigned char bytes[4]; } alarm;   /* +0x1A0: bytes ALARM_* */
    unsigned char pad1a4;
    unsigned char refresh_rate_custom_x;        /* +0x1A5: Customize position of the Refresh Rate overlay, in */
    unsigned char refresh_rate_custom_y;        /* +0x1A6:   steps of 3 columns / 2 rows */
    unsigned char alarm_clock_custom_x;         /* +0x1A7: the same for the Alarm Clock overlay */
    unsigned char alarm_clock_custom_y;         /* +0x1A8 */
    unsigned char pad1a9[3];
    unsigned short crosshair_x, crosshair_y;    /* +0x1AC, +0x1AE: origin of the crosshair layer */
};

/* The bytes of user_settings.alarm read here. */
#define ALARM_MINUTES           1       /* +0x1A1: minutes left */
#define ALARM_SECONDS           2       /* +0x1A2: seconds left */

#define CROSSHAIR_COLOR_AUTO    2

/* The overlay being positioned (also the value of settings byte +0x1A3 in the position editor). */
#define OVERLAY_REFRESH_RATE    0
#define OVERLAY_ALARM_CLOCK     1
#define OVERLAY_CROSSHAIR       2

/* Overlay locations, in the order of the location list of the menu. */
enum {
    OVERLAY_LOCATION_LEFT_TOP     = 0,
    OVERLAY_LOCATION_RIGHT_TOP    = 1,
    OVERLAY_LOCATION_LEFT_BOTTOM  = 2,
    OVERLAY_LOCATION_RIGHT_BOTTOM = 3,
    OVERLAY_LOCATION_CUSTOMIZE    = 4       /* and every value above 3: the *_custom_x / _y bytes */
};

#define MENU_LAYER_MAIN       0         /* layer 0: the menu layer, here holding the boxes */
#define CROSSHAIR_LAYER       1         /* layer 1: the crosshair */
#define PLANE_0               0         /* byte plane 0 (first argument of osd_api_fill_cell_bytes) */
#define ALL_WINDOWS           8         /* osd_api_set_window_enable: all eight windows */
#define LAYOUT_OVERLAYS       3         /* osd_set_layout 3: full width x 61 rows */
#define OVERLAY_ROWS          0x3d      /* rows of the menu layer in this layout */
#define CELL_WIDTH            24        /* panel width units per cell */
#define PANEL_WIDTH           0         /* panel_api_get_active_size(0): width of the active panel row */

/* Box positions in cells. The right-side columns are counted back from the panel width. */
#define LEFT_COLUMN           2
#define RATE_TOP_ROW          2         /* Refresh Rate box: 8 columns x 3 rows */
#define RATE_BOTTOM_ROW       0x35
#define RATE_RIGHT_OFFSET     0xf0      /* 10 cells */
#define ALARM_TOP_ROW         6         /* Alarm Clock box: 12 columns x 3 rows */
#define ALARM_BOTTOM_ROW      0x31
#define ALARM_RIGHT_OFFSET    0x150     /* 14 cells */
#define INFO_RIGHT_OFFSET     0x238     /* the Info. On Screen box */
#define INFO_ROW              0x13
#define CUSTOM_COLUMN_STEP    3
#define CUSTOM_ROW_STEP       2

/* Big digits: digit d is a block of 2 columns x 3 rows of glyphs, glyph (d * 3 + row) * 2 + col + DIGIT_GLYPH_BASE.
   Block 10 (glyphs 0x6C..0x71) is drawn between the minutes and the seconds of the Alarm Clock. */
#define DIGIT_GLYPH_BASE      0x30
#define SEPARATOR_GLYPH_BASE  0x6c

extern struct user_settings_record user_settings;
extern unsigned short panel_api_get_active_size(unsigned char field);
extern void osd_hide_menu(void);
extern void osd_set_layout(unsigned char layout);
extern void osd_setup_layer_window(int columns, int rows, int);
extern void osd_api_set_origin_and_size(unsigned short, unsigned short, unsigned char layer);
extern void osd_draw_info_box(unsigned short x, unsigned short y, unsigned char mode);
extern void osd_api_enable(unsigned char on, unsigned char layer);
extern void osd_api_set_cell_size_mode(unsigned char mode, unsigned char layer);
extern void osd_api_set_layer_byte_pair(unsigned char, unsigned char, unsigned char layer);
extern void osd_api_set_window_enable(unsigned char window, unsigned char on, unsigned char layer);
extern void osd_api_set_reg_c8_ranges(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char layer);
extern void osd_api_set_size_in_cells(unsigned short columns, unsigned char rows, unsigned int layer);
extern void osd_api_set_position(unsigned short a, unsigned short b, unsigned char layer);
extern void osd_api_write_reg_cc(unsigned short, unsigned char layer);
extern void osd_api_reset_layer(unsigned char layer);
extern void font_load_crosshair_icon1(void);
extern void font_load_crosshair_icon2(void);
extern void font_load_crosshair_icon3(void);
extern void font_load_crosshair_icon4(void);
extern void font_load_crosshair_icon5(void);
extern void font_load_crosshair_icon6(void);
extern void osd_api_fill_cells(unsigned short x, unsigned short y, unsigned char count, unsigned short value,
                               unsigned char layer);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short x, unsigned short y, unsigned char count,
                                    unsigned char value, unsigned char layer);
extern void osd_update_crosshair_color(int force);
extern void osd_draw_cell_run(unsigned char across, unsigned char rising, unsigned short attr, unsigned short x,
                              unsigned char y, unsigned char count, unsigned char glyph);
extern unsigned short input_user_get_rounded_refresh_rate(void);

/* One row of the 4 x 3 crosshair cells, for crosshair colour 1. */
static void fill_crosshair_row_colour1(unsigned short row)
{
    osd_api_fill_cells(0, row, 4, 0x1702, CROSSHAIR_LAYER);
}

/* The same for crosshair colour 0. */
static void fill_crosshair_row_colour0(unsigned short row)
{
    osd_api_fill_cells(0, row, 4, 0x1802, CROSSHAIR_LAYER);
}

/* Crosshair cell (col, row) shows glyph row * 4 + col of the loaded icon. */
static void put_crosshair_glyph(unsigned short col, unsigned short row, unsigned char glyph_row, unsigned char glyph_col)
{
    osd_api_fill_cell_bytes(PLANE_0, col, row, 1, glyph_row * 4 + glyph_col, CROSSHAIR_LAYER);
}

/*
 * The Alarm Clock box (12 columns x 3 rows) at (x, y).
 * erase = 1: all 36 cells get cell value 0x802 and glyph 0. Otherwise: the side columns (glyphs 7 / 9 left,
 * 8 / 10 right on rows 0 and 2; 7 / 8 with attribute 0x8A2 on row 1), then the countdown mm:ss in columns 1..10:
 * minutes in 1..4, the separator in 5..6, seconds in 7..10.
 */
static void draw_alarm_clock_box(unsigned short x, unsigned char y, unsigned char erase)
{
    unsigned char row, col;

    if (erase == 1) {
        for (row = 0; row < 3; row++) {
            osd_api_fill_cells(x, y + row, 0xc, 0x802, MENU_LAYER_MAIN);
            osd_api_fill_cell_bytes(PLANE_0, x, y + row, 0xc, 0, MENU_LAYER_MAIN);
        }
    } else {
        for (row = 0; row < 2; row++) {
            osd_draw_cell_run(0, 0, 0xb80a, x, y + row * 2, 1, row * 2 + 7);
            osd_draw_cell_run(0, 0, 0xb80a, x + 0xb, y + row * 2, 1, row * 2 + 8);
        }
        osd_draw_cell_run(0, 0, 0x8a2, x, y + 1, 1, 7);
        osd_draw_cell_run(0, 0, 0x8a2, x + 0xb, y + 1, 1, 8);
        for (row = 0; row < 3; row++) {
            osd_api_fill_cells(x + 1, y + row, 10, 0xb80a, MENU_LAYER_MAIN);
            for (col = 0; col < 2; col++) {
                osd_api_fill_cell_bytes(PLANE_0, x + col + 1, y + row, 1, ((user_settings.alarm.bytes[ALARM_MINUTES] / 10) * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
                osd_api_fill_cell_bytes(PLANE_0, x + col + 3, y + row, 1, ((user_settings.alarm.bytes[ALARM_MINUTES] % 10) * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
                osd_api_fill_cell_bytes(PLANE_0, x + col + 5, y + row, 1, row * 2 + col + SEPARATOR_GLYPH_BASE, MENU_LAYER_MAIN);
                osd_api_fill_cell_bytes(PLANE_0, x + col + 7, y + row, 1, ((user_settings.alarm.bytes[ALARM_SECONDS] / 10) * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
                osd_api_fill_cell_bytes(PLANE_0, x + col + 9, y + row, 1, ((user_settings.alarm.bytes[ALARM_SECONDS] % 10) * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
            }
        }
    }
}

/*
 * The Refresh Rate box (8 columns x 3 rows) at (x, y).
 * erase = 1: all 24 cells get cell value 0x802 and glyph 0. Otherwise: the side columns as in the Alarm Clock box,
 * then the hundreds, tens and ones of input_user_get_rounded_refresh_rate in columns 1..2, 3..4 and 5..6.
 */
static void draw_refresh_rate_box(unsigned short x, unsigned char y, unsigned char erase)
{
    unsigned short refresh_rate;
    unsigned char row, col, k;

    if (erase == 1) {
        for (k = 0; k < 3; k++) {
            osd_api_fill_cells(x, y + k, 8, 0x802, MENU_LAYER_MAIN);
            osd_api_fill_cell_bytes(PLANE_0, x, y + k, 8, 0, MENU_LAYER_MAIN);
        }
    } else {
        unsigned char hundreds, tens, ones;

        refresh_rate = input_user_get_rounded_refresh_rate();
        hundreds = refresh_rate / 100;
        tens = (refresh_rate % 100) / 10;
        ones = refresh_rate % 10;
        for (k = 0; k < 2; k++) {
            osd_draw_cell_run(0, 0, 0xb80a, x, y + k * 2, 1, k * 2 + 7);
            osd_draw_cell_run(0, 0, 0xb80a, x + 7, y + k * 2, 1, k * 2 + 8);
        }
        osd_draw_cell_run(0, 0, 0x8a2, x, y + 1, 1, 7);
        osd_draw_cell_run(0, 0, 0x8a2, x + 7, y + 1, 1, 8);
        if (refresh_rate >= 100) {
            for (row = 0; row < 3; row++) {
                osd_api_fill_cells(x + 1, y + row, 2, 0xb80a, MENU_LAYER_MAIN);
                for (col = 0; col < 2; col++)
                    osd_api_fill_cell_bytes(PLANE_0, x + col + 1, y + row, 1, (hundreds * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
            }
        } else {
            /* Below 100 the hundreds place gets the glyphs of digit 0 with cell value 0xBB0A (here over 3 cells;
               the third is set again by the tens). */
            for (row = 0; row < 3; row++) {
                osd_api_fill_cells(x + 1, y + row, 3, 0xbb0a, MENU_LAYER_MAIN);
                for (col = 0; col < 2; col++)
                    osd_api_fill_cell_bytes(PLANE_0, x + col + 1, y + row, 1, row * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
            }
        }
        for (row = 0; row < 3; row++) {
            osd_api_fill_cells(x + 3, y + row, 4, 0xb80a, MENU_LAYER_MAIN);
            for (col = 0; col < 2; col++) {
                osd_api_fill_cell_bytes(PLANE_0, x + col + 3, y + row, 1, (tens * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
                osd_api_fill_cell_bytes(PLANE_0, x + col + 5, y + row, 1, (ones * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
            }
        }
    }
}

/*
 * Draw the overlay that the position editor (menu state 0x108) moves.
 *
 *   overlay  OVERLAY_REFRESH_RATE, OVERLAY_ALARM_CLOCK or OVERLAY_CROSSHAIR
 *   set_up   1: set the menu layer up first (as osd_show_screen_overlays does); 0: switch it off first
 *   erase    1: blank the box instead of drawing it (refresh rate and alarm clock only)
 *
 * Callers: osd_open_refresh_rate_position / _alarm_clock_position / _crosshair_position and osd_run_periodic_task
 * open the editor with (overlay, 1, 0). osd_move_overlay_left / _up / _down / _right move a Refresh Rate or Alarm
 * Clock box with (overlay, 0, 1) at the old place and (overlay, 0, 0) at the new one; they move the crosshair by
 * its layer origin without calling this routine.
 *
 * Phases:
 *   1. Positions in cells of the Refresh Rate box, the Alarm Clock box and the Info. On Screen box, as in
 *      osd_show_screen_overlays.
 *   2. Menu layer: set up in layout 3 (set_up = 1; for the crosshair also the Info. On Screen box), or switched
 *      off (set_up = 0).
 *   3. Crosshair only: the crosshair layer as in osd_show_screen_overlays. With the icon set to off, icon 1 is
 *      shown; the setting itself is left unchanged.
 *   4. The Alarm Clock box: for the crosshair, or for the alarm clock when its location is 4 (Customize).
 *   5. The Refresh Rate box: for the crosshair, or for the refresh rate when its location is 4 (Customize).
 *   6. The menu layer is switched on.
 * For the crosshair both boxes are drawn whatever their own switches are.
 */
void osd_draw_overlay_position_preview(unsigned char overlay, unsigned char set_up, unsigned char erase)
{
    unsigned short overlay_columns, alarm_x, info_x;
    unsigned short rate_x;
    unsigned char rate_y, alarm_y, row, col, saved_icon;
    int value;

    /* 1. Positions. */
    overlay_columns = panel_api_get_active_size(PANEL_WIDTH) / CELL_WIDTH + 1;
    if (user_settings.refresh_rate_location == OVERLAY_LOCATION_LEFT_TOP) {
        rate_x = LEFT_COLUMN;
        rate_y = RATE_TOP_ROW;
    } else if (user_settings.refresh_rate_location == OVERLAY_LOCATION_RIGHT_TOP) {
        value = panel_api_get_active_size(PANEL_WIDTH) - RATE_RIGHT_OFFSET;
        rate_x = value / CELL_WIDTH;
        rate_y = RATE_TOP_ROW;
    } else if (user_settings.refresh_rate_location == OVERLAY_LOCATION_LEFT_BOTTOM) {
        rate_x = LEFT_COLUMN;
        rate_y = RATE_BOTTOM_ROW;
    } else if (user_settings.refresh_rate_location == OVERLAY_LOCATION_RIGHT_BOTTOM) {
        value = panel_api_get_active_size(PANEL_WIDTH) - RATE_RIGHT_OFFSET;
        rate_x = value / CELL_WIDTH;
        rate_y = RATE_BOTTOM_ROW;
    } else {
        rate_x = user_settings.refresh_rate_custom_x * CUSTOM_COLUMN_STEP;
        rate_y = user_settings.refresh_rate_custom_y * CUSTOM_ROW_STEP;
    }
    if (user_settings.alarm_clock_location == OVERLAY_LOCATION_LEFT_TOP) {
        alarm_x = LEFT_COLUMN;
        alarm_y = ALARM_TOP_ROW;
    } else {
        alarm_y = ALARM_TOP_ROW;
        if (user_settings.alarm_clock_location == OVERLAY_LOCATION_RIGHT_TOP) {
            value = panel_api_get_active_size(PANEL_WIDTH) - ALARM_RIGHT_OFFSET;
            alarm_x = value / CELL_WIDTH;
        } else if (user_settings.alarm_clock_location == OVERLAY_LOCATION_LEFT_BOTTOM) {
            alarm_x = LEFT_COLUMN;
            alarm_y = ALARM_BOTTOM_ROW;
        } else {
            alarm_y = ALARM_BOTTOM_ROW;
            if (user_settings.alarm_clock_location == OVERLAY_LOCATION_RIGHT_BOTTOM) {
                value = panel_api_get_active_size(PANEL_WIDTH) - ALARM_RIGHT_OFFSET;
                alarm_x = value / CELL_WIDTH;
            } else {
                alarm_x = user_settings.alarm_clock_custom_x * CUSTOM_COLUMN_STEP;
                alarm_y = user_settings.alarm_clock_custom_y * CUSTOM_ROW_STEP;
            }
        }
    }
    value = panel_api_get_active_size(PANEL_WIDTH) - INFO_RIGHT_OFFSET;
    info_x = value / CELL_WIDTH;

    /* 2. Menu layer. */
    if (set_up == 1) {
        osd_hide_menu();
        osd_set_layout(LAYOUT_OVERLAYS);
        osd_setup_layer_window(overlay_columns, OVERLAY_ROWS, 0x802);
        osd_api_set_origin_and_size(0, 0, MENU_LAYER_MAIN);
        if (overlay == OVERLAY_CROSSHAIR)
            osd_draw_info_box(info_x, INFO_ROW, 1);
    }
    if (set_up == 0)
        osd_api_enable(0, MENU_LAYER_MAIN);

    /* 3. Crosshair layer. */
    if (overlay == OVERLAY_CROSSHAIR) {
        osd_api_enable(0, CROSSHAIR_LAYER);
        osd_api_set_cell_size_mode(4, CROSSHAIR_LAYER);
        osd_api_set_layer_byte_pair(0x18, 0x24, CROSSHAIR_LAYER);
        osd_api_set_window_enable(ALL_WINDOWS, 0, CROSSHAIR_LAYER);
        osd_api_set_reg_c8_ranges(0, 0, 0, 0, CROSSHAIR_LAYER);
        osd_api_set_size_in_cells(4, 3, CROSSHAIR_LAYER);
        osd_api_set_position(user_settings.menu_position_a, user_settings.menu_position_b, CROSSHAIR_LAYER);
        osd_api_write_reg_cc(0x792, CROSSHAIR_LAYER);
        osd_api_reset_layer(CROSSHAIR_LAYER);
        osd_api_set_origin_and_size(user_settings.crosshair_x, user_settings.crosshair_y, CROSSHAIR_LAYER);
        /* With the crosshair off, icon 1 stands in while the position is edited. */
        saved_icon = user_settings.crosshair_icon;
        col = saved_icon;
        if (col == 0) {
            col = 1;
            user_settings.crosshair_icon = 1;
        }
        value = (col - 1) % 6;
        if (value == 0)
            font_load_crosshair_icon1();
        else if (value == 1)
            font_load_crosshair_icon2();
        else if (value == 2)
            font_load_crosshair_icon3();
        else if (value == 3)
            font_load_crosshair_icon4();
        else if (value == 4)
            font_load_crosshair_icon5();
        else if (value == 5)
            font_load_crosshair_icon6();
        else
            font_load_crosshair_icon1();
        /* Colour: fixed cell values for colours 1 and 0; for the automatic colour the colour 1 values first,
           then osd_update_crosshair_color. */
        if (user_settings.crosshair_color == 1) {
            for (row = 0; row < 3; row++)
                fill_crosshair_row_colour1(row);
        } else if (user_settings.crosshair_color == 0) {
            for (row = 0; row < 3; row++)
                fill_crosshair_row_colour0(row);
        } else {
            for (row = 0; row < 3; row++)
                fill_crosshair_row_colour1(row);
            osd_update_crosshair_color(1);
        }
        for (row = 0; row < 3; row++)
            for (col = 0; col < 4; col++)
                put_crosshair_glyph(col, row, row, col);
        user_settings.crosshair_icon = saved_icon;
        osd_api_enable(1, CROSSHAIR_LAYER);
    }

    /* 4., 5. The boxes. When the refresh rate or the alarm clock is positioned, only its own box is drawn, and
              only when its location is exactly 4 (Customize). */
    if (overlay == OVERLAY_CROSSHAIR || (overlay == OVERLAY_ALARM_CLOCK && user_settings.alarm_clock_location == OVERLAY_LOCATION_CUSTOMIZE))
        draw_alarm_clock_box(alarm_x, alarm_y, erase);
    if (overlay == OVERLAY_CROSSHAIR || (overlay == OVERLAY_REFRESH_RATE && user_settings.refresh_rate_location == OVERLAY_LOCATION_CUSTOMIZE))
        draw_refresh_rate_box(rate_x, rate_y, erase);

    /* 6. Show the menu layer. */
    osd_api_enable(1, MENU_LAYER_MAIN);
}
