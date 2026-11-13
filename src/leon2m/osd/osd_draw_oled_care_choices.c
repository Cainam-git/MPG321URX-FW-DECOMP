/* osd_draw_oled_care_choices  (FUN_a00ac718)
 *
 * Draw the choice list of an OLED Care setting and highlight the current one.
 *   menu_state: OLED Care item state
 * Name basis: derived - texts through osd_get_oled_care_text; called by osd_open_pixel_shift_speed,
 *   osd_open_static_screen_*, the detection sliders
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ac718 @ 0xa00ac718-0xa00acc40 (330 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the case blocks of the switch on menu_state in the order written (it sets the register choices);
 *    0xBD and 0xBE are separate cases with their own 'row_count = 2', and 'case 0x35: row_count = 0;' (a body equal
 *    to the default, dropped later) gives the compare tree its root 0x39;
 *  - el_text is declared before offs_text;
 *  - the format string is the symbol s_001981c0.
 */
/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad000[8];
    unsigned char language;                     /* +0x08: menu language, the column of the text tables */
    unsigned char pad009[0x1dc - 9];
    union { unsigned int flags; unsigned char bytes[4]; } oled_care;    /* +0x1DC: oled_care_flags word; bytes
                                                                           OLED_CARE_* */
    unsigned char pad1e0[0x1e8 - 0x1e0];
    unsigned char multi_logo_detection;         /* +0x1E8: Multi Logo Detection off / on */
    unsigned char pad1e9;
    unsigned char taskbar_detection;            /* +0x1EA: Taskbar Detection off / on */
    unsigned char pad1eb;
    unsigned char boundary_detection;           /* +0x1EC: Boundary Detection off / on */
    unsigned char pad1ed;
    unsigned char protect_notice;               /* +0x1EE: Protect Notice */
};

/* Bytes of user_settings.oled_care read here, and the Static Screen Detection bit of its word. */
#define OLED_CARE_PIXEL_SHIFT          1        /* +0x1DD pixel_shift: the Pixel Shift speed */
#define OLED_CARE_STATIC_SCREEN_LEVEL  3        /* +0x1DF static_screen_level */
#define OLED_CARE_STATIC_SCREEN_SHIFT  15       /* bit 15 of the word: Static Screen Detection on */

/* Menu states (osd_menu_state) whose choice lists are drawn here. 0x34..0x3B are the items of the MSI OLED
   Care page (PAGE_OLED_CARE_ITEMS + item). */
enum {
    MENU_STATE_PIXEL_SHIFT_ITEM     = 0x34,
    MENU_STATE_PANEL_PROTECT_ITEM   = 0x35,     /* no choice list */
    MENU_STATE_PROTECT_NOTICE_ITEM  = 0x36,
    MENU_STATE_STATIC_SCREEN_ITEM   = 0x37,
    MENU_STATE_MULTI_LOGO_ITEM      = 0x38,
    MENU_STATE_TASKBAR_ITEM         = 0x39,
    MENU_STATE_BOUNDARY_ITEM        = 0x3a,
    MENU_STATE_PANEL_INFO_ITEM      = 0x3b,     /* OLED Panel Info. */
    MENU_STATE_PIXEL_SHIFT_SPEED    = 0xba,     /* osd_open_pixel_shift_speed */
    MENU_STATE_STATIC_START_TIME    = 0xbd,     /* osd_open_static_screen_start_time */
    MENU_STATE_STATIC_TIME_REQUIRED = 0xbe,     /* osd_open_static_screen_time_required */
    MENU_STATE_BF                   = 0xbf
};

/* Usage counters of the panel in the device settings (nvram_get_device_setting). */
#define DEVICE_SETTING_EL_COUNT     0xa
#define DEVICE_SETTING_OFFS_COUNT   0xb
#define DEVICE_SETTING_EL_HOURS     0xc
#define DEVICE_SETTING_OFFS_HOURS   0xd
#define DEVICE_SETTING_EL_RUNS      0xe
#define DEVICE_SETTING_OFFS_RUNS    0xf

#define NO_CHOICE             7         /* nothing to mark */
#define TEXTS_PER_ENTRY       29        /* text tables hold one text per language for each entry */
#define TEXT_ALIGN_LEFT       0         /* osd_api_set_text_mode */
#define TEXT_ALIGN_RIGHT      1
#define MENU_LAYER_MAIN       0
#define PLANE_0               0
#define LABEL_COLUMN          0x2a      /* row texts of the choice lists */
#define INFO_LABEL_COLUMN     0x29      /* row labels of the OLED Panel Info. page */
#define INFO_VALUE_COLUMN     0x27      /* its values: right-aligned in 14 cells, one cell row lower */
#define INFO_VALUE_WIDTH      0xe
#define FIRST_ROW             6         /* row i is drawn on cell row i * 2 + 6 */
#define VALUE_FIRST_ROW       7         /* OLED Panel Info.: the value of row i on cell row i * 2 + 7 */
#define CHOICE_MARK_GLYPH     0xf       /* glyphs 0x0F, 0x10 in columns 0x28, 0x29 (as osd_draw_choice_mark) */

extern struct user_settings_record user_settings;
extern unsigned int osd_off_on_texts[], osd_oled_care_speed_texts[];
extern void osd_api_set_glyph_write_address(int address, int layer);
extern void osd_api_set_text_mode(int mode, int layer);
extern void osd_clear_choice_column(void);
extern unsigned short nvram_get_device_setting(unsigned int);
extern void sprintf(unsigned char *, const char *, ...);
extern unsigned int osd_get_oled_care_text(unsigned short, unsigned char);
extern void osd_draw_text(int, unsigned short, unsigned short, int, unsigned int, int);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_highlight_choice_row(unsigned char, int);
extern void osd_api_fill_cell_bytes(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

/*
 * Draw the right-hand column of the MSI OLED Care page for one of its items or sub-lists, and mark the current
 * choice.
 *
 *   menu_state  the item or list (MENU_STATE_*); the row texts come from osd_get_oled_care_text(menu_state, row)
 *
 * Called by osd_draw_item_choices (PAGE_OLED_CARE_ITEMS + item), osd_redraw_page_after_notice (0x35),
 * osd_open_pixel_shift_speed (0xBA), osd_open_static_screen_start_time (0xBD), osd_open_static_screen_time_required
 * (0xBE) and osd_close_<multi_logo|taskbar|boundary>_level_slider (0x38..0x3A).
 *
 * Phases:
 *   1. Glyph write address 0x111 and left-aligned text on the menu layer; the choice column is cleared.
 *   2. From the menu state: the number of rows and the setting that gives the current choice. Pixel Shift (from
 *      +0x1DD), Multi Logo / Taskbar / Boundary Detection (on / off) and the 0xBA list have 3 rows; Protect Notice
 *      and the 0xBD / 0xBE lists 2; Static Screen Detection 5 (current = on / off); OLED Panel Info. 6; state 0xBF
 *      7, or 1 when the Static Screen level is above 6. Any other state (Panel Protect among them) draws nothing
 *      more. A current choice is marked only for Pixel Shift, Protect Notice, Static Screen Detection and the three
 *      detection items.
 *   3. Two texts '<runs>, <hours>h  <count>m' from the device settings: the OFFS counters and the EL counters.
 *      Only the OFFS text is drawn (row 0 of OLED Panel Info.).
 *   4. The rows. For OLED Panel Info. each row has a label (column 0x29; with language 0xD rows 2 and 4 start at
 *      column 0x28 and row 3 at column 0x26) and a value right-aligned below it: the OFFS text, the Pixel Shift
 *      speed, then OFF / ON of Static Screen, Multi Logo, Taskbar and Boundary Detection. Every other list draws
 *      its row texts at column 0x2A.
 *   5. The current choice: osd_highlight_choice_row in mode 0 and the choice mark in front of it.
 */
void osd_draw_oled_care_choices(unsigned short menu_state)
{
    unsigned char el_text[15] = {0};
    unsigned char offs_text[15] = {0};
    unsigned char row_count, current, i, len, mark_row;
    unsigned int label;

    /* 1. Text set-up and an empty choice column. */
    osd_api_set_glyph_write_address(0x111, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    osd_clear_choice_column();

    /* 2. Rows and current choice. */
    current = NO_CHOICE;
    row_count = 0;
    switch (menu_state) {
    case MENU_STATE_PIXEL_SHIFT_ITEM:
        current = user_settings.oled_care.bytes[OLED_CARE_PIXEL_SHIFT];
        row_count = 3;
        break;
    case MENU_STATE_PANEL_PROTECT_ITEM:
        row_count = 0;
        break;
    case MENU_STATE_PIXEL_SHIFT_SPEED:
        row_count = 3;
        break;
    case MENU_STATE_STATIC_SCREEN_ITEM:
        current = (user_settings.oled_care.flags >> OLED_CARE_STATIC_SCREEN_SHIFT) & 1;
        row_count = 5;
        break;
    case MENU_STATE_STATIC_TIME_REQUIRED:
        row_count = 2;
        break;
    case MENU_STATE_PANEL_INFO_ITEM:
        row_count = 6;
        break;
    case MENU_STATE_PROTECT_NOTICE_ITEM:
        current = user_settings.protect_notice;
        row_count = 2;
        break;
    case MENU_STATE_BF:
        if (user_settings.oled_care.bytes[OLED_CARE_STATIC_SCREEN_LEVEL] <= 6)
            row_count = 7;
        else
            row_count = 1;
        break;
    case MENU_STATE_STATIC_START_TIME:
        row_count = 2;
        break;
    case MENU_STATE_MULTI_LOGO_ITEM:
        current = user_settings.multi_logo_detection;
        row_count = 3;
        break;
    case MENU_STATE_TASKBAR_ITEM:
        current = user_settings.taskbar_detection;
        row_count = 3;
        break;
    case MENU_STATE_BOUNDARY_ITEM:
        current = user_settings.boundary_detection;
        row_count = 3;
        break;
    }
    if (row_count == 0)
        return;

    /* 3. The usage counter texts. The first byte ('n') is replaced by the text length, so the buffers are
          texts in the form osd_draw_text takes. */
    sprintf(offs_text, "n %d, %dh  %dm", nvram_get_device_setting(DEVICE_SETTING_OFFS_RUNS), nvram_get_device_setting(DEVICE_SETTING_OFFS_HOURS), nvram_get_device_setting(DEVICE_SETTING_OFFS_COUNT));
    for (len = 0; len < 15; len++)
        if (offs_text[len] == 0)
            break;
    offs_text[0] = len - 1;
    sprintf(el_text, "n %d, %dh  %dm", nvram_get_device_setting(DEVICE_SETTING_EL_RUNS), nvram_get_device_setting(DEVICE_SETTING_EL_HOURS), nvram_get_device_setting(DEVICE_SETTING_EL_COUNT));
    for (len = 0; len < 15; len++)
        if (el_text[len] == 0)
            break;
    el_text[0] = len - 1;

    /* 4. The rows. */
    for (i = 0; i < row_count; i++) {
        label = osd_get_oled_care_text(menu_state, i);
        if (menu_state == MENU_STATE_PANEL_INFO_ITEM) {
            osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
            /* Labels of rows 2..4 sit further left in language 0xD. */
            if ((unsigned char)(i - 2) <= 2 && user_settings.language == 0xd) {
                if (i == 2 || i == 4) {
                    osd_draw_text(0, 0x28, i * 2 + FIRST_ROW, 1, label, MENU_LAYER_MAIN);
                } else {
                    osd_api_fill_cells(0x26, i * 2 + FIRST_ROW, 1, 0x796, MENU_LAYER_MAIN);
                    osd_draw_text(0, 0x26, i * 2 + FIRST_ROW, 1, label, MENU_LAYER_MAIN);
                }
            } else {
                osd_draw_text(0, INFO_LABEL_COLUMN, i * 2 + FIRST_ROW, 1, label, MENU_LAYER_MAIN);
            }
            osd_api_set_text_mode(TEXT_ALIGN_RIGHT, MENU_LAYER_MAIN);
            switch (i) {
            case 0:
                osd_draw_text(0, INFO_VALUE_COLUMN, i * 2 + VALUE_FIRST_ROW, INFO_VALUE_WIDTH, (unsigned int)offs_text, MENU_LAYER_MAIN);
                break;
            case 1:
                osd_draw_text(0, INFO_VALUE_COLUMN, i * 2 + VALUE_FIRST_ROW, INFO_VALUE_WIDTH,
                             osd_get_text(osd_oled_care_speed_texts, user_settings.oled_care.bytes[OLED_CARE_PIXEL_SHIFT] * TEXTS_PER_ENTRY + user_settings.language), MENU_LAYER_MAIN);
                break;
            case 2:
                osd_draw_text(0, INFO_VALUE_COLUMN, i * 2 + VALUE_FIRST_ROW, INFO_VALUE_WIDTH,
                             osd_get_text(osd_off_on_texts, ((user_settings.oled_care.flags >> OLED_CARE_STATIC_SCREEN_SHIFT) & 1) * TEXTS_PER_ENTRY + user_settings.language), MENU_LAYER_MAIN);
                break;
            case 3:
                osd_draw_text(0, INFO_VALUE_COLUMN, i * 2 + VALUE_FIRST_ROW, INFO_VALUE_WIDTH,
                             osd_get_text(osd_off_on_texts, user_settings.multi_logo_detection * TEXTS_PER_ENTRY + user_settings.language), MENU_LAYER_MAIN);
                break;
            case 4:
                osd_draw_text(0, INFO_VALUE_COLUMN, i * 2 + VALUE_FIRST_ROW, INFO_VALUE_WIDTH,
                             osd_get_text(osd_off_on_texts, user_settings.taskbar_detection * TEXTS_PER_ENTRY + user_settings.language), MENU_LAYER_MAIN);
                break;
            case 5:
                osd_draw_text(0, INFO_VALUE_COLUMN, i * 2 + VALUE_FIRST_ROW, INFO_VALUE_WIDTH,
                             osd_get_text(osd_off_on_texts, user_settings.boundary_detection * TEXTS_PER_ENTRY + user_settings.language), MENU_LAYER_MAIN);
                break;
            }
        } else {
            osd_draw_text(0, LABEL_COLUMN, i * 2 + FIRST_ROW, 1, label, MENU_LAYER_MAIN);
        }
    }

    /* 5. The current choice. */
    if (current == NO_CHOICE)
        return;
    osd_highlight_choice_row(current, 0);
    if (current <= 6)
        mark_row = current * 2 + FIRST_ROW;
    else
        mark_row = current * 2 - 8;
    osd_api_fill_cell_bytes(PLANE_0, 0x28, mark_row, 1, CHOICE_MARK_GLYPH, MENU_LAYER_MAIN);
    osd_api_fill_cell_bytes(PLANE_0, 0x29, mark_row, 1, CHOICE_MARK_GLYPH + 1, MENU_LAYER_MAIN);
}
