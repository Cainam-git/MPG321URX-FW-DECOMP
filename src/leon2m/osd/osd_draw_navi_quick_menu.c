/* osd_draw_navi_quick_menu  (FUN_a00b8e7c)
 *
 * Draw the quick menu of the function assigned to a Navi key.
 *   direction: Navi key direction: 0 up, 1 down, 2 left, 3 right
 * Note: The parameter is the Navi key direction 0 up / 1 down / 2 left / 3 right; the function is settings
 *   byte +0x18A + direction (1..11).
 * Name basis: derived - callers osd_run_navi_key_up/down/left/right; texts of the KVM, PIP/PBP, input and key
 *   guide lists
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b8e7c @ 0xa00b8e7c-0xa00b9750 (2260 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - every test of the function reads user_settings.navi_key_function[direction] again (the compiler reuses
 *    the load for ten tests and reloads it for the eleventh, as in the firmware);
 *  - bit 11 of gaming_flags is read and cleared as the bit-field pro_selected; the copy in osd_edit_value is
 *    tested as '== 1';
 *  - the Brightness value is read into len for sprintf before the osd_api_set_glyph_write_address /
 *    osd_api_set_text_mode calls; len then counts the characters.
 */

/* The fields of the application state record used here. */
struct app_state_record {
    unsigned char p00[0x3e];
    struct { unsigned short flag_15 : 1, rest : 15; } flags_0x3e;  /* +0x3E: flag_15 = bit 15 */
};

/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char p000[8];
    unsigned char language;                     /* +0x08: menu language (1 = English) */
    unsigned char brightness;                   /* +0x09: Brightness */
    unsigned char p00a[0x0d - 0x0a];
    unsigned char menu_position_a, menu_position_b; /* +0x0D, +0x0E: the two position percentages of the menu */
    unsigned char p00f[0x1e - 0x0f];
    unsigned char input_source;                 /* +0x1E: Input Source */
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP/PBP mode (0 off, 1 PIP, 2 PBP) */
    unsigned char p020[0x4a - 0x20];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char p04b[0xa8 - 0x4b];
    union {
        unsigned int word;
        struct { unsigned int high : 20, pro_selected : 1, low : 11; } bits;   /* bit 11: Pro (1) / Game (0) mode */
    } gaming_flags;                             /* +0xA8 */
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned char p0b0[0x15b - 0xb0];
    unsigned char night_vision;                 /* +0x15B: Night Vision */
    unsigned char p15c[0x17c - 0x15c];
    unsigned char kvm;                          /* +0x17C: KVM (Auto, Upstream, Type C) */
    unsigned char p17d[0x182 - 0x17d];
    unsigned char game_mode;                    /* +0x182: Game Mode */
    unsigned char p183[0x18a - 0x183];
    unsigned char navi_key_function[0x18f - 0x18a]; /* +0x18A..+0x18D: Navi Key up, down, left, right */
    unsigned char byte_0x18f;                   /* +0x18F: set to crosshair_icon here */
    unsigned char crosshair_icon;               /* +0x190: Smart Crosshair icon */
    unsigned char p191[0x1a0 - 0x191];
    unsigned char alarm_clock;                  /* +0x1A0: Alarm Clock timer choice */
    unsigned char p1a1[0x1a3 - 0x1a1];
    unsigned char byte_0x1a3;                   /* +0x1A3: row of the input quick menu (osd_select_next/prev_quick_input) */
};
extern struct app_state_record app_state_record;
extern struct user_settings_record user_settings;
extern unsigned char osd_list_id, osd_edit_value, osd_choice_row;
extern unsigned int osd_navi_function_texts[], osd_off_on_texts[], osd_input_name_texts[], osd_pip_pbp_texts[], osd_kvm_texts[], osd_key_guide_texts[];

extern void osd_api_enable(int on, int layer);
extern void osd_api_set_window_enable(int window, int on, int layer);
extern void panel_wait_sync_pulse(void);
extern void osd_set_layout(unsigned int);
extern void osd_api_set_reg_c8_ranges(int, int, int, int, int);
extern void osd_api_set_size_in_cells(int columns, int rows, int layer);
extern void osd_api_set_position(unsigned short, unsigned short, unsigned char layer);
extern void osd_api_write_reg_cc(int, int layer);
extern void osd_api_reset_layer(int layer);
extern void osd_api_set_origin_and_size(int, int, int layer);
extern void osd_draw_info_box(int column, int row, int mode);
extern void osd_draw_quick_menu_frame(unsigned char function);
extern void osd_api_set_text_mode(int mode, int layer);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char layer);
extern unsigned int osd_get_text(unsigned int *, unsigned short);
extern void osd_draw_text(unsigned char plane, unsigned short column, unsigned short row, unsigned char width,
                          unsigned int text, unsigned char layer);
extern void osd_draw_quick_switch(unsigned char on);
extern void osd_draw_slider_bar(unsigned char column, unsigned char row, unsigned char value, unsigned int length);
extern void sprintf(unsigned char *, const char *, ...);
extern void UserSetGameMode(void);
extern void osd_draw_game_mode_quick_menu(unsigned char page);
extern void osd_highlight_quick_menu_row(unsigned char row, unsigned char cursor);
extern void osd_draw_alarm_clock_quick_menu(unsigned char page);
extern void osd_set_menu_state(int);
extern void osd_draw_crosshair_quick_menu(void);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void osd_api_fill_cell_bytes(unsigned char plane, unsigned short column, unsigned short row, unsigned char count,
                                    unsigned char value, unsigned char layer);
extern void osd_draw_night_vision_quick_menu(unsigned char page);
extern void osd_api_fill_cells(unsigned short column, unsigned short row, unsigned char count, unsigned short value,
                               unsigned char layer);

/* Navi Key functions (the menu's Navi Key choices, texts of osd_navi_function_texts). Function +
 * MENU_STATE_NAVI_BASE is the menu state of its quick menu. */
enum {
    NAVI_FUNCTION_BRIGHTNESS     = 1,
    NAVI_FUNCTION_GAME_MODE      = 2,
    NAVI_FUNCTION_CROSSHAIR      = 3,           /* Smart Crosshair */
    NAVI_FUNCTION_ALARM_CLOCK    = 4,
    NAVI_FUNCTION_INPUT_SOURCE   = 5,
    NAVI_FUNCTION_PIP_PBP        = 6,
    NAVI_FUNCTION_REFRESH_RATE   = 7,
    NAVI_FUNCTION_INFO_ON_SCREEN = 8,           /* Info. On Screen */
    NAVI_FUNCTION_NIGHT_VISION   = 9,
    NAVI_FUNCTION_OPTIX_SCOPE    = 10,
    NAVI_FUNCTION_KVM            = 11
};
#define MENU_STATE_NAVI_CROSSHAIR   0xfc        /* MENU_STATE_NAVI_BASE 0xF9 + NAVI_FUNCTION_CROSSHAIR */

#define MENU_LAYER_MAIN         0
#define CROSSHAIR_LAYER         1
#define ALL_WINDOWS             8               /* osd_api_set_window_enable: all eight windows */
#define OSD_LIST_QUICK_MENU     0x24            /* osd_list_id; osd_draw_input_quick_menu sets the same value */
#define LAYOUT_QUICK_MENU       2               /* osd_set_layout 2; osd_draw_input_quick_menu uses it too */
#define QUICK_MENU_COLUMNS      0x16            /* 22 x 17 cells */
#define QUICK_MENU_ROWS         0x11
#define CELL_BLANK              0x792           /* cell value of an empty menu cell (the layer background) */
#define KEY_GUIDE_CELL          0x592           /* cell value written under the key guide texts */
#define TEXT_ALIGN_LEFT         0               /* osd_api_set_text_mode */
#define TEXT_ALIGN_CENTRE       2
#define PLANE_0                 0
#define TEXTS_PER_ITEM          29              /* a text table holds one text per menu language for every item */
#define ENGLISH                 1               /* language 1 */

/* Cell positions. */
#define TITLE_COLUMN            3               /* the function name: row 1, 16 cells wide */
#define TITLE_ROW               1
#define TITLE_WIDTH             0x10
#define SWITCH_ROW              8               /* OFF / ON switch and the Brightness bar */
#define OFF_TEXT_COLUMN         3
#define ON_TEXT_COLUMN          0x10
#define BAR_COLUMN              5
#define BAR_LENGTH              0xc             /* cells */
#define VALUE_COLUMN            0xa             /* the Brightness number: row 6, 3 cells */
#define VALUE_ROW               6
#define LIST_TEXT_COLUMN        6               /* list rows: 5, 7, 9, 11; 10 cells wide */
#define LIST_FIRST_ROW          5
#define LIST_TEXT_WIDTH         0xa
#define ROWS_PER_PAGE           4               /* a list value v is on page v >> 2, row v & 3 */
#define MARK_COLUMN             4               /* mark of the stored choice: columns 4, 5 */
#define MARK_GLYPH              0x1c            /* glyphs 0x1C, 0x1D in those two cells */
#define KEY_GUIDE_ROW           0xf
#define KEY_GUIDE_LEFT_COLUMN   6               /* two key guide fields of 6 cells */
#define KEY_GUIDE_RIGHT_COLUMN  0xf
#define KEY_GUIDE_WIDTH         6

/* osd_highlight_quick_menu_row: 1 = the cursor row (window 3; the up / down handlers move it), 0 = the row of the
 * value the quick menu opened with (window 4). */
#define ROW_STORED              0
#define ROW_CURSOR              1

/* Key guide texts (osd_key_guide_texts: Move, Enter, Switch, Adjust, Select, Save); Move is text 0. */
#define KEY_TEXT_SWITCH         (2 * TEXTS_PER_ITEM)
#define KEY_TEXT_ADJUST         (3 * TEXTS_PER_ITEM)
#define KEY_TEXT_SELECT         (4 * TEXTS_PER_ITEM)
#define KEY_TEXT_SAVE           (5 * TEXTS_PER_ITEM)

#define REFRESH_RATE_SHIFT      12              /* gaming_flags bit 12: the Refresh Rate overlay is on */
#define INFO_ON_SCREEN_SHIFT    22              /* settings_page_flags bit 22: Info. On Screen */

/*
 * Draw the quick menu that a Navi key opens: the function set for that key direction in the Navi Key menu
 * (user_settings.navi_key_function, functions 1..11).
 *
 *   direction: 0 up, 1 down, 2 left, 3 right (index of navi_key_function)
 *
 * Callers: osd_run_navi_key_up / _down / _left / _right with the menu closed, and osd_close_change_notice for
 * the direction whose function is Game Mode. The callers set the menu state (function + MENU_STATE_NAVI_BASE)
 * and show the menu layer after this routine returns.
 *
 * Phases:
 *   1. Switch the menu layer, all its windows and the crosshair layer off; mark the open list as a quick menu
 *      (osd_list_id, the value osd_draw_input_quick_menu also sets) and clear flag_15 of app_state_record
 *      +0x3E; wait for two sync pulses of the panel.
 *   2. Set up the menu layer: layout 2, 22 x 17 cells, placed at the menu position of the settings.
 *   3. Draw the info box, the frame of this function's kind (osd_draw_quick_menu_frame) and the function name as
 *      title.
 *   4. The body, by function:
 *      - Refresh Rate, Info. On Screen, Optix Scope: an OFF / ON switch at the stored value, with the OFF and ON
 *        texts beside it;
 *      - Brightness: a bar of the value and the value as a number;
 *      - Game Mode: when the Pro mode was selected (gaming_flags bit 11) it is cleared and the picture mode of
 *        the Gaming menu applied (UserSetGameMode); then as the next group;
 *      - Game Mode, Alarm Clock, Smart Crosshair, Night Vision: their list routine draws the page that holds the
 *        stored value (value >> 2) and the cursor goes to its row (value & 3);
 *      - Input Source, PIP/PBP, KVM: the list texts, the cursor and the window-4 highlight on the stored value,
 *        and the mark glyphs in front of that row. For Input Source the row is
 *        input_api_source_id_to_menu_index(input_source); Input Source and PIP/PBP also copy their value to
 *        byte_0x1a3.
 *      osd_choice_row receives that value in every case.
 *   5. The key guide row: Switch / Save for the switches, Adjust / Save for Brightness, Move / Select for the
 *      lists.
 *
 * The OFF / ON texts are taken in the menu language for languages 0, 6, 7 and 10, otherwise in English.
 */
void osd_draw_navi_quick_menu(unsigned char direction)
{
    unsigned char off_on_language, i, mark_row, len;
    unsigned char text[8];                      /* length byte, then the characters */

    /* 1. Everything off while the layer is rebuilt. */
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, MENU_LAYER_MAIN);
    osd_list_id = OSD_LIST_QUICK_MENU;
    osd_api_enable(0, CROSSHAIR_LAYER);
    /* While flag_15 is set, osd_dispatch_key_event does not apply the menu time-out after a key. */
    app_state_record.flags_0x3e.flag_15 = 0;
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();

    /* 2. Layer set-up. */
    osd_set_layout(LAYOUT_QUICK_MENU);
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, MENU_LAYER_MAIN);
    osd_api_set_reg_c8_ranges(0, 0, 0, 0, 0);
    osd_api_set_size_in_cells(QUICK_MENU_COLUMNS, QUICK_MENU_ROWS, MENU_LAYER_MAIN);
    osd_api_set_position(user_settings.menu_position_a, user_settings.menu_position_b, MENU_LAYER_MAIN);
    osd_api_write_reg_cc(CELL_BLANK, MENU_LAYER_MAIN);
    osd_api_reset_layer(MENU_LAYER_MAIN);
    osd_api_set_origin_and_size(0x678, 0x57c, MENU_LAYER_MAIN);

    /* 3. Box, frame and title. */
    osd_draw_info_box(0, 0, 2);
    osd_draw_quick_menu_frame(user_settings.navi_key_function[direction]);
    osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(0x60, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, TITLE_COLUMN, TITLE_ROW, TITLE_WIDTH,
                  osd_get_text(osd_navi_function_texts,
                               user_settings.navi_key_function[direction] * TEXTS_PER_ITEM + user_settings.language),
                  MENU_LAYER_MAIN);

    /* 4. The body. */
    if (user_settings.language == 0 || user_settings.language == 6 || user_settings.language == 7 ||
        user_settings.language == 10)
        off_on_language = user_settings.language;
    else
        off_on_language = ENGLISH;
    if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_REFRESH_RATE)
        osd_draw_quick_switch((user_settings.gaming_flags.word >> REFRESH_RATE_SHIFT) & 1);
    else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_INFO_ON_SCREEN)
        osd_draw_quick_switch((user_settings.settings_page_flags >> INFO_ON_SCREEN_SHIFT) & 1);
    else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_OPTIX_SCOPE)
        osd_draw_quick_switch(user_settings.optix_scope);
    if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_BRIGHTNESS) {
        osd_choice_row = user_settings.brightness;
        osd_draw_slider_bar(BAR_COLUMN, SWITCH_ROW, user_settings.brightness, BAR_LENGTH);
        len = user_settings.brightness;
        osd_api_set_glyph_write_address(0x6f, MENU_LAYER_MAIN);
        osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
        /* 'n' holds the place of the length byte. */
        sprintf(text, "n%3d", len);
        for (len = 0; len < 4; len++)
            if (text[len] == 0)
                break;
        text[0] = len - 1;                      /* the number of characters after the length byte */
        osd_draw_text(PLANE_0, VALUE_COLUMN, VALUE_ROW, 3, (unsigned int)text, MENU_LAYER_MAIN);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_GAME_MODE) {
        osd_choice_row = user_settings.game_mode;
        /* Opening the Game Mode quick menu leaves the Pro mode. */
        osd_edit_value = user_settings.gaming_flags.bits.pro_selected;
        user_settings.gaming_flags.bits.pro_selected = 0;
        if (osd_edit_value == 1)
            UserSetGameMode();
        osd_draw_game_mode_quick_menu(user_settings.game_mode >> 2);
        osd_highlight_quick_menu_row(user_settings.game_mode & 3, ROW_CURSOR);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_REFRESH_RATE) {
        osd_choice_row = (user_settings.gaming_flags.word >> REFRESH_RATE_SHIFT) & 1;
        osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, OFF_TEXT_COLUMN, SWITCH_ROW, 3, osd_get_text(osd_off_on_texts, off_on_language),
                      MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, ON_TEXT_COLUMN, SWITCH_ROW, 3,
                      osd_get_text(osd_off_on_texts, off_on_language + TEXTS_PER_ITEM), MENU_LAYER_MAIN);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_INFO_ON_SCREEN) {
        osd_choice_row = (user_settings.settings_page_flags >> INFO_ON_SCREEN_SHIFT) & 1;
        osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, OFF_TEXT_COLUMN, SWITCH_ROW, 3, osd_get_text(osd_off_on_texts, off_on_language),
                      MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, ON_TEXT_COLUMN, SWITCH_ROW, 3,
                      osd_get_text(osd_off_on_texts, off_on_language + TEXTS_PER_ITEM), MENU_LAYER_MAIN);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_OPTIX_SCOPE) {
        osd_choice_row = user_settings.optix_scope;
        osd_api_set_text_mode(TEXT_ALIGN_CENTRE, MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, OFF_TEXT_COLUMN, SWITCH_ROW, 3, osd_get_text(osd_off_on_texts, off_on_language),
                      MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, ON_TEXT_COLUMN, SWITCH_ROW, 3,
                      osd_get_text(osd_off_on_texts, off_on_language + TEXTS_PER_ITEM), MENU_LAYER_MAIN);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_ALARM_CLOCK) {
        osd_choice_row = user_settings.alarm_clock;
        osd_draw_alarm_clock_quick_menu(user_settings.alarm_clock >> 2);
        osd_highlight_quick_menu_row(user_settings.alarm_clock & 3, ROW_CURSOR);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_CROSSHAIR) {
        /* The callers set this state again after the return. */
        osd_set_menu_state(MENU_STATE_NAVI_CROSSHAIR);
        osd_choice_row = user_settings.crosshair_icon;
        user_settings.byte_0x18f = user_settings.crosshair_icon;
        osd_draw_crosshair_quick_menu();
        osd_highlight_quick_menu_row(user_settings.byte_0x18f & 3, ROW_CURSOR);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_INPUT_SOURCE) {
        for (i = 0; i <= 3; i++)                /* HDMI 1, HDMI 2, DP, Type C: one text for all languages */
            osd_draw_text(PLANE_0, LIST_TEXT_COLUMN, i * 2 + LIST_FIRST_ROW, LIST_TEXT_WIDTH,
                          osd_get_text(osd_input_name_texts, i), MENU_LAYER_MAIN);
        osd_choice_row = input_api_source_id_to_menu_index(user_settings.input_source);
        osd_highlight_quick_menu_row(osd_choice_row, ROW_CURSOR);
        osd_highlight_quick_menu_row(osd_choice_row, ROW_STORED);
        mark_row = osd_choice_row;
        if (mark_row > 3)
            mark_row -= ROWS_PER_PAGE;
        for (i = 0; i <= 1; i++)
            osd_api_fill_cell_bytes(PLANE_0, i + MARK_COLUMN, mark_row * 2 + LIST_FIRST_ROW, 1, i + MARK_GLYPH,
                                    MENU_LAYER_MAIN);
        user_settings.byte_0x1a3 = user_settings.input_source;
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_PIP_PBP) {
        osd_choice_row = user_settings.pip_pbp_mode;
        user_settings.byte_0x1a3 = user_settings.pip_pbp_mode;
        for (i = 0; i <= 2; i++)                /* OFF, PIP, PBP */
            osd_draw_text(PLANE_0, LIST_TEXT_COLUMN, i * 2 + LIST_FIRST_ROW, LIST_TEXT_WIDTH,
                          osd_get_text(osd_pip_pbp_texts, i * TEXTS_PER_ITEM + user_settings.language),
                          MENU_LAYER_MAIN);
        osd_highlight_quick_menu_row(user_settings.pip_pbp_mode, ROW_CURSOR);
        osd_highlight_quick_menu_row(user_settings.pip_pbp_mode, ROW_STORED);
        mark_row = user_settings.pip_pbp_mode;
        if (mark_row > 3)
            mark_row -= ROWS_PER_PAGE;
        for (i = 0; i <= 1; i++)
            osd_api_fill_cell_bytes(PLANE_0, i + MARK_COLUMN, mark_row * 2 + LIST_FIRST_ROW, 1, i + MARK_GLYPH,
                                    MENU_LAYER_MAIN);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_NIGHT_VISION) {
        osd_choice_row = user_settings.night_vision;
        osd_draw_night_vision_quick_menu(user_settings.night_vision >> 2);
        osd_highlight_quick_menu_row(user_settings.night_vision & 3, ROW_CURSOR);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_KVM) {
        osd_choice_row = user_settings.kvm;
        for (i = 0; i <= 2; i++)                /* Auto, Upstream, Type C */
            osd_draw_text(PLANE_0, LIST_TEXT_COLUMN, i * 2 + LIST_FIRST_ROW, LIST_TEXT_WIDTH,
                          osd_get_text(osd_kvm_texts, i * TEXTS_PER_ITEM + user_settings.language), MENU_LAYER_MAIN);
        osd_highlight_quick_menu_row(user_settings.kvm, ROW_CURSOR);
        osd_highlight_quick_menu_row(user_settings.kvm, ROW_STORED);
        mark_row = user_settings.kvm;
        if (mark_row > 3)
            mark_row -= ROWS_PER_PAGE;
        for (i = 0; i <= 1; i++)
            osd_api_fill_cell_bytes(PLANE_0, i + MARK_COLUMN, mark_row * 2 + LIST_FIRST_ROW, 1, i + MARK_GLYPH,
                                    MENU_LAYER_MAIN);
    }

    /* 5. The key guide row. */
    osd_api_set_glyph_write_address(0x92, MENU_LAYER_MAIN);
    osd_api_set_text_mode(TEXT_ALIGN_LEFT, MENU_LAYER_MAIN);
    osd_api_fill_cells(KEY_GUIDE_LEFT_COLUMN, KEY_GUIDE_ROW, KEY_GUIDE_WIDTH, KEY_GUIDE_CELL, MENU_LAYER_MAIN);
    osd_api_fill_cells(KEY_GUIDE_RIGHT_COLUMN, KEY_GUIDE_ROW, KEY_GUIDE_WIDTH, KEY_GUIDE_CELL, MENU_LAYER_MAIN);
    if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_REFRESH_RATE ||
        user_settings.navi_key_function[direction] == NAVI_FUNCTION_INFO_ON_SCREEN ||
        user_settings.navi_key_function[direction] == NAVI_FUNCTION_OPTIX_SCOPE) {
        osd_draw_text(PLANE_0, KEY_GUIDE_LEFT_COLUMN, KEY_GUIDE_ROW, 1,
                      osd_get_text(osd_key_guide_texts, user_settings.language + KEY_TEXT_SWITCH), MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, KEY_GUIDE_RIGHT_COLUMN, KEY_GUIDE_ROW, 1,
                      osd_get_text(osd_key_guide_texts, user_settings.language + KEY_TEXT_SAVE), MENU_LAYER_MAIN);
    } else if (user_settings.navi_key_function[direction] == NAVI_FUNCTION_BRIGHTNESS) {
        osd_draw_text(PLANE_0, KEY_GUIDE_LEFT_COLUMN, KEY_GUIDE_ROW, 1,
                      osd_get_text(osd_key_guide_texts, user_settings.language + KEY_TEXT_ADJUST), MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, KEY_GUIDE_RIGHT_COLUMN, KEY_GUIDE_ROW, 1,
                      osd_get_text(osd_key_guide_texts, user_settings.language + KEY_TEXT_SAVE), MENU_LAYER_MAIN);
    } else {
        osd_draw_text(PLANE_0, KEY_GUIDE_LEFT_COLUMN, KEY_GUIDE_ROW, 1,
                      osd_get_text(osd_key_guide_texts, user_settings.language), MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, KEY_GUIDE_RIGHT_COLUMN, KEY_GUIDE_ROW, 1,
                      osd_get_text(osd_key_guide_texts, user_settings.language + KEY_TEXT_SELECT), MENU_LAYER_MAIN);
    }
}
