/* osd_show_screen_overlays  (FUN_a00a5e68)
 *
 * Draw or refresh the overlays: crosshair, alarm timer, refresh rate counter.
 *   redraw: 1 redraw all, 0 update
 * Note: Uses menu layout 3; positions from settings +0x13E / +0x13F; on = 0 only updates the numbers.
 * Name basis: derived - crosshair icon +0x190 (font_load_crosshair_icon*), timer +0x1A0..0x1A2, refresh rate
 *   bit 12 of +0xA8; called by osd_run_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a5e68 @ 0xa00a5e68-0xa00a6b98 (3376 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - each location choice sets the row before its inner tests, and the column to 2 inside the LEFT_TOP and
 *    LEFT_BOTTOM arms (if-conversion moves those arms above their branches);
 *  - the overlap test of phase 5 is the static helper rate_box_covers_counter, returning 1 / 0, with '&' between
 *    the two compares of its second term and the row 0x1e in an unsigned short local; the counter is drawn when it
 *    returns 0;
 *  - the crosshair colour rows and the 3 x 4 crosshair cells go through static helpers with unsigned short
 *    parameters (fill_crosshair_row_colour1 / _colour0, put_crosshair_glyph(col, row, row, col) with the
 *    row * 4 + col sum formed from two byte parameters);
 *  - the hundreds arm 'refresh_rate >= 100' is written first.
 */
/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad000[0xd];
    unsigned char menu_position_a, menu_position_b; /* +0x0D, +0x0E: the two position percentages of the menu
                                                       layer (osd_user_apply_menu_position) */
    unsigned char pad00f[0xa8 - 0xf];
    unsigned int gaming_flags;                  /* +0xA8: GAMING_FLAG_* */
    unsigned int settings_page_flags;           /* +0xAC: SETTINGS_INFO_ON_SCREEN */
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
#define ALARM_CLOCK             0       /* +0x1A0 alarm_clock: the Alarm Clock choice (0 = off) */
#define ALARM_MINUTES           1       /* +0x1A1: minutes left */
#define ALARM_SECONDS           2       /* +0x1A2: seconds left */

#define GAMING_FLAG_ADAPTIVE_SYNC   0x80        /* gaming_flags bit 7: Adaptive-Sync */
#define GAMING_FLAG_REFRESH_RATE    0x1000      /* gaming_flags bit 12: the Refresh Rate overlay is on */
#define SETTINGS_INFO_ON_SCREEN     0x400000    /* settings_page_flags bit 22: Info. On Screen */
#define CROSSHAIR_COLOR_AUTO        2
#define APP_STATE_FLAG0_BIT10       0x400       /* app_state_record halfword +0, bit 10: no overlays drawn */

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
extern unsigned short app_state_record;
extern unsigned char osd_shown_refresh_rate;
extern unsigned short panel_api_get_active_size(unsigned char field);
extern void osd_hide_menu(void);
extern void osd_set_layout(unsigned char layout);
extern int osd_setup_layer_window(int columns, int rows, int);
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
extern void osd_draw_refresh_rate_counter(unsigned short x, unsigned short y);

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

/* 1 when the Refresh Rate box at (rate_x, rate_y) meets the field of the info box's refresh rate counter
   (osd_draw_refresh_rate_counter draws a 6-cell text at x + 8, y + 11, here counter_x on row 0x1e): counter_x <=
   rate_x < counter_x + 6 or rate_x < counter_x <= rate_x + 8, with row 0x1e within rate_y .. rate_y + 3. */
static int rate_box_covers_counter(unsigned short rate_x, unsigned char rate_y, unsigned short counter_x)
{
    unsigned short counter_row = 0x1e;

    if (((rate_x >= counter_x && rate_x < counter_x + 6) || ((rate_x + 8 >= counter_x) & (rate_x < counter_x)))
        && rate_y <= counter_row && counter_row <= rate_y + 3)
        return 1;
    return 0;
}

/*
 * Draw the screen overlays that are switched on while the menu is closed: the Smart Crosshair, the Alarm Clock
 * countdown, the Refresh Rate display and the Info. On Screen box.
 *
 *   redraw  1: set the layers up and draw everything; 0: only update the numbers
 *
 * Called with redraw = 1 by osd_open_menu_state_0x106, osd_open_pbp_custom_split and osd_run_periodic_task (when
 * it enters menu state 0x106), and with redraw = 0 by osd_run_periodic_task on every later pass in that state.
 *
 * Phases:
 *   0. Nothing is drawn while bit 10 of the application state halfword is set.
 *   1. Positions in cells: the Refresh Rate box (rate_x, rate_y), the Alarm Clock box (alarm_x, alarm_y) from
 *      their location settings, and the Info. On Screen box (info_x, row 0x13).
 *   2. redraw only: the menu layer is set up in layout 3 (the whole panel width); the Info. On Screen box
 *      (osd_draw_info_box mode 1); the crosshair on layer 1 (its icon glyphs loaded, then 4 x 3 cells with glyphs
 *      0..11); the side columns of the Alarm Clock box and of the Refresh Rate box.
 *   3. Alarm Clock digits mm:ss, unless the Alarm Clock box overlaps the Refresh Rate box while that is on.
 *   4. Refresh Rate digits: hundreds, tens, ones of input_user_get_rounded_refresh_rate.
 *   5. With Info. On Screen and Adaptive-Sync on, the refresh rate counter of the info box is drawn again when the
 *      value has changed, unless the Refresh Rate box lies over it.
 *   6. redraw only: the menu layer is switched on.
 */
void osd_show_screen_overlays(unsigned char redraw)
{
    unsigned short overlay_columns, rate_x, alarm_x, info_x, refresh_rate;
    unsigned char rate_y, alarm_y, row, col, k;
    int value;

    /* 0. Gate. */
    overlay_columns = panel_api_get_active_size(PANEL_WIDTH) / CELL_WIDTH + 1;
    if (app_state_record & APP_STATE_FLAG0_BIT10)
        return;

    /* 1. Positions. */
    if (user_settings.refresh_rate_location == OVERLAY_LOCATION_LEFT_TOP) {
        rate_x = LEFT_COLUMN;
        rate_y = RATE_TOP_ROW;
    } else {
        rate_y = RATE_TOP_ROW;
        if (user_settings.refresh_rate_location == OVERLAY_LOCATION_RIGHT_TOP) {
            value = panel_api_get_active_size(PANEL_WIDTH) - RATE_RIGHT_OFFSET;
            rate_x = value / CELL_WIDTH;
        } else if (user_settings.refresh_rate_location == OVERLAY_LOCATION_LEFT_BOTTOM) {
            rate_x = LEFT_COLUMN;
            rate_y = RATE_BOTTOM_ROW;
        } else {
            rate_y = RATE_BOTTOM_ROW;
            if (user_settings.refresh_rate_location == OVERLAY_LOCATION_RIGHT_BOTTOM) {
                value = panel_api_get_active_size(PANEL_WIDTH) - RATE_RIGHT_OFFSET;
                rate_x = value / CELL_WIDTH;
            } else {
                rate_x = user_settings.refresh_rate_custom_x * CUSTOM_COLUMN_STEP;
                rate_y = user_settings.refresh_rate_custom_y * CUSTOM_ROW_STEP;
            }
        }
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

    /* 2. Full redraw: layer set-up and the fixed parts. */
    if (redraw) {
        osd_hide_menu();
        osd_set_layout(LAYOUT_OVERLAYS);
        osd_setup_layer_window(overlay_columns, OVERLAY_ROWS, 0x802);
        osd_api_set_origin_and_size(0, 0, MENU_LAYER_MAIN);
        if (user_settings.settings_page_flags & SETTINGS_INFO_ON_SCREEN)
            osd_draw_info_box(info_x, INFO_ROW, 1);

        /* The crosshair: layer 1, off while it is set up, 4 x 3 cells at the stored origin. */
        if (user_settings.crosshair_icon != 0) {
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
            /* Icons 1..6 have one glyph loader each. */
            value = (user_settings.crosshair_icon - 1) % 6;
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
            /* Colour: fixed cell values for colours 1 and 0; the automatic colour is picked by
               osd_update_crosshair_color. */
            if (user_settings.crosshair_color == 1) {
                for (row = 0; row < 3; row++)
                    fill_crosshair_row_colour1(row);
            } else if (user_settings.crosshair_color == 0) {
                for (row = 0; row < 3; row++)
                    fill_crosshair_row_colour0(row);
            } else
                osd_update_crosshair_color(1);
            for (row = 0; row < 3; row++)
                for (col = 0; col < 4; col++)
                    put_crosshair_glyph(col, row, row, col);
            osd_api_enable(1, CROSSHAIR_LAYER);
        }

        /* Alarm Clock box, 12 columns x 3 rows: all cells glyph 0 with attribute 0x792; then on rows 0 and 2
           glyph 7 / 9 in the left column, 8 / 10 in the right column and 0xB / 0xC in the ten columns between;
           on row 1 glyphs 7 and 8 with attribute 0x8A2 in the two side columns. */
        if (user_settings.alarm.bytes[ALARM_CLOCK] != 0) {
            for (k = 0; k < 3; k++)
                osd_draw_cell_run(1, 0, 0x792, alarm_x, alarm_y + k, 0xc, 0);
            for (k = 0; k < 2; k++) {
                osd_draw_cell_run(0, 0, 0xb80a, alarm_x, alarm_y + k * 2, 1, k * 2 + 7);
                osd_draw_cell_run(1, 0, 0xb80a, alarm_x + 1, alarm_y + k * 2, 10, k + 0xb);
                osd_draw_cell_run(0, 0, 0xb80a, alarm_x + 0xb, alarm_y + k * 2, 1, k * 2 + 8);
            }
            osd_draw_cell_run(0, 0, 0x8a2, alarm_x, alarm_y + 1, 1, 7);
            osd_draw_cell_run(0, 0, 0x8a2, alarm_x + 0xb, alarm_y + 1, 1, 8);
        }

        /* Refresh Rate box, 8 columns: the same glyphs in its two side columns only. */
        if (user_settings.gaming_flags & GAMING_FLAG_REFRESH_RATE) {
            for (k = 0; k < 2; k++) {
                osd_draw_cell_run(0, 0, 0xb80a, rate_x, rate_y + k * 2, 1, k * 2 + 7);
                osd_draw_cell_run(0, 0, 0xb80a, rate_x + 7, rate_y + k * 2, 1, k * 2 + 8);
            }
            osd_draw_cell_run(0, 0, 0x8a2, rate_x, rate_y + 1, 1, 7);
            osd_draw_cell_run(0, 0, 0x8a2, rate_x + 7, rate_y + 1, 1, 8);
        }
    }

    /* 3. Alarm Clock digits: minutes in columns 1..4, the separator in 5..6, seconds in 7..10. Skipped while the
          box overlaps the Refresh Rate box and that box is on. */
    if (user_settings.alarm.bytes[ALARM_CLOCK] != 0) {
        if (!(alarm_x + 0xb > rate_x && rate_x + 8 > alarm_x && alarm_y + 3 > rate_y && rate_y + 3 > alarm_y
              && (user_settings.gaming_flags & GAMING_FLAG_REFRESH_RATE))) {
            for (row = 0; row < 3; row++) {
                osd_api_fill_cells(alarm_x + 1, alarm_y + row, 10, 0xb80a, MENU_LAYER_MAIN);
                for (col = 0; col < 2; col++) {
                    osd_api_fill_cell_bytes(PLANE_0, alarm_x + col + 1, alarm_y + row, 1, ((user_settings.alarm.bytes[ALARM_MINUTES] / 10) * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
                    osd_api_fill_cell_bytes(PLANE_0, alarm_x + col + 3, alarm_y + row, 1, ((user_settings.alarm.bytes[ALARM_MINUTES] % 10) * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
                    osd_api_fill_cell_bytes(PLANE_0, alarm_x + col + 5, alarm_y + row, 1, row * 2 + col + SEPARATOR_GLYPH_BASE, MENU_LAYER_MAIN);
                    osd_api_fill_cell_bytes(PLANE_0, alarm_x + col + 7, alarm_y + row, 1, ((user_settings.alarm.bytes[ALARM_SECONDS] / 10) * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
                    osd_api_fill_cell_bytes(PLANE_0, alarm_x + col + 9, alarm_y + row, 1, ((user_settings.alarm.bytes[ALARM_SECONDS] % 10) * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
                }
            }
        }
    }

    /* 4. Refresh Rate digits in columns 1..6 of its box. */
    if (user_settings.gaming_flags & GAMING_FLAG_REFRESH_RATE) {
        unsigned char hundreds, tens, ones;

        refresh_rate = input_user_get_rounded_refresh_rate();
        hundreds = refresh_rate / 100;
        tens = (refresh_rate % 100) / 10;
        ones = refresh_rate % 10;
        if (refresh_rate >= 100) {
            for (row = 0; row < 3; row++) {
                osd_api_fill_cells(rate_x + 1, rate_y + row, 2, 0xb80a, MENU_LAYER_MAIN);
                for (col = 0; col < 2; col++)
                    osd_api_fill_cell_bytes(PLANE_0, rate_x + col + 1, rate_y + row, 1, (hundreds * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
            }
        } else {
            /* Below 100 the hundreds place gets the glyphs of digit 0 with cell value 0xBB0A instead of 0xB80A. */
            for (row = 0; row < 3; row++) {
                osd_api_fill_cells(rate_x + 1, rate_y + row, 2, 0xbb0a, MENU_LAYER_MAIN);
                for (col = 0; col < 2; col++)
                    osd_api_fill_cell_bytes(PLANE_0, rate_x + col + 1, rate_y + row, 1, row * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
            }
        }
        for (row = 0; row < 3; row++) {
            osd_api_fill_cells(rate_x + 3, rate_y + row, 4, 0xb80a, MENU_LAYER_MAIN);
            for (col = 0; col < 2; col++) {
                osd_api_fill_cell_bytes(PLANE_0, rate_x + col + 3, rate_y + row, 1, (tens * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
                osd_api_fill_cell_bytes(PLANE_0, rate_x + col + 5, rate_y + row, 1, (ones * 3 + row) * 2 + col + DIGIT_GLYPH_BASE, MENU_LAYER_MAIN);
            }
        }
    }

    /* 5. The refresh rate counter of the Info. On Screen box, only when the value has changed. */
    if ((user_settings.settings_page_flags & SETTINGS_INFO_ON_SCREEN) && (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC) && input_user_get_rounded_refresh_rate() != osd_shown_refresh_rate) {
        unsigned short counter_x = info_x + 8;

        if (!rate_box_covers_counter(rate_x, rate_y, counter_x))
            osd_draw_refresh_rate_counter(info_x, INFO_ROW);
        osd_shown_refresh_rate = input_user_get_rounded_refresh_rate();
    }

    /* 6. Show the menu layer. */
    if (redraw)
        osd_api_enable(1, MENU_LAYER_MAIN);
}
