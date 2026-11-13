/* osd_draw_factory_menu  (FUN_a008d2f8)
 *
 * Draw the whole factory service menu with all item labels and values.
 * Note: Highlights item 0x1A on entry.
 * Name basis: proven - ROM texts 'Burn In', 'Reset', 'SSC', 'PHY CTS AUTO', 'Panel ERR Count', ... and the
 *   item layout table
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008d2f8 @ 0xa008d2f8-0xa008e270 (990 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the number fields are static helpers that GCC inlines (draw_on_time_hours / draw_on_time_minutes read
 *    device_settings.on_time like osd_draw_on_time_hours / osd_draw_on_time_minutes);
 *  - draw_hex_value reads its value argument before its clearing loop;
 *  - the format strings and the texts at 0x1002b0..0x100410 are separate ROM symbols (one sethi per symbol,
 *    shared between uses of the same symbol);
 *  - the highlight of item 26 reads osd_factory_menu_layout[osd_factory_item] after the store to osd_factory_item;
 *  - the OFF-RS choice is written 'if (!nvram_get_device_setting(0x11))' with the YES arm first;
 *  - bit 6 of app_state_record halfword +4 is cleared through a bit-field (the mask form schedules the halfword
 *    store after the next one);
 *  - the serial number goes through a variable-length array of serial_length + 1 bytes.
 */

/* The items of the factory menu, by their position in osd_factory_menu_layout; the names are the labels drawn
   below. Same list as in osd_factory_decrease_value / osd_factory_increase_value. */
enum factory_item {
    FACTORY_ITEM_WARM50_RED = 1, FACTORY_ITEM_WARM50_GREEN = 2, FACTORY_ITEM_WARM50_BLUE = 3,
    FACTORY_ITEM_COOL93_RED = 4, FACTORY_ITEM_COOL93_GREEN = 5, FACTORY_ITEM_COOL93_BLUE = 6,
    FACTORY_ITEM_USER_RED = 7, FACTORY_ITEM_USER_GREEN = 8, FACTORY_ITEM_USER_BLUE = 9,
    FACTORY_ITEM_NORMAL65_RED = 10, FACTORY_ITEM_NORMAL65_GREEN = 11, FACTORY_ITEM_NORMAL65_BLUE = 12,
    FACTORY_ITEM_BRIGHTNESS = 13, FACTORY_ITEM_CONTRAST = 14,
    FACTORY_ITEM_SSC_FREQ = 15, FACTORY_ITEM_SSC_RATIO = 16,
    FACTORY_ITEM_PRODUCT = 17, FACTORY_ITEM_RESET = 18, FACTORY_ITEM_BURN_IN = 19,
    FACTORY_ITEM_CEC_PWM_ADJUST = 20, FACTORY_ITEM_PANEL_NPC = 21, FACTORY_ITEM_DUMMY = 22,
    FACTORY_ITEM_SENSING_TEST = 23, FACTORY_ITEM_PHY_CTS_AUTO = 24, FACTORY_ITEM_HDMI_CTS = 25,
    FACTORY_ITEM_CRC_AUTO = 26
};

/* Fields of the device settings record (nvram_get_device_setting). */
#define DEVICE_SETTING_PHY_CTS_AUTO  2
#define DEVICE_SETTING_SENSING_TEST  0x10
#define DEVICE_SETTING_USAGE_RECORD  0x11   /* shown as OFF-RS: YES when it is 0 */

#define FACTORY_MODE_MARKER          0x55aa /* settings +0x1F6 while the factory mode is on ("PRODUCT" ON) */

#define MENU_LAYER_MAIN   0                 /* the layer osd_show_menu_layer switches on */
#define PLANE_0           0                 /* byte planes (first argument of osd_draw_text / osd_api_write_cell_bytes) */
#define PLANE_1           1
#define ALL_WINDOWS       8                 /* osd_api_set_window_enable: all eight windows */
#define TEXT_ATTR_NORMAL  0x790             /* not highlighted */
#define TEXT_ATTR_HIGHLIGHT 0x90            /* the highlighted item */

/* Number fields are drawn as cell codes: a space becomes code 0, a digit becomes its character minus 47
   ('0' -> 1 ... '9' -> 10). */
#define DIGIT_CODE_OFFSET 47

/* Application state halfword +4 (app_state_record_sleep_word); only bit 6 is changed here. */
struct app_state_record_layout {        /* app_state_record, 0xA802CFF4 */
    unsigned short halfword_0x0, halfword_0x2;
    struct { unsigned short bits_15_7 : 9, bit_6 : 1, bits_5_0 : 6; } sleep_word;     /* +0x04 */
};
/* The fields of the user settings record shown in the factory menu. */
struct user_settings_record {           /* user_settings, 0xA802D290 */
    unsigned char pad000[9];
    unsigned char brightness, contrast;                 /* +0x09, +0x0A */
    unsigned char pad00b[7];
    unsigned char red_gain, green_gain, blue_gain;      /* +0x12..+0x14: the custom gains, 0..100 */
    unsigned char pad015[0x1bf];
    union {                                             /* +0x1D4 */
        unsigned int word;                              /* bit 7: "HDMI CTS"; bits 8-15 = byte +0x1D6 */
        unsigned char bytes[4];                         /* bytes[1] = +0x1D5 burn_in_flag */
    } word_0x1d4;
    unsigned short halfword_0x1d8;                      /* +0x1D8 */
    unsigned short brightness_knee;                     /* +0x1DA: shown as "CEC PWM Adjust" */
    unsigned char pad1dc[0x1a];
    unsigned short factory_marker;                 /* +0x1F6 */
};
#define BURN_IN_FLAG 1                  /* index of the burn_in_flag byte in word_0x1d4.bytes */
#define HDMI_CTS_BIT 0x80               /* bit 7 of word_0x1d4 */

/* The colour values of the part record shown in the rows Warm50, Normal65 and Cool93. */
struct part_record_colours {            /* part_record, 0xA802E1F0 */
    unsigned char pad0[6];
    unsigned char warm50_red, warm50_green, warm50_blue;            /* +0x06 */
    unsigned char normal65_red, normal65_green, normal65_blue;      /* +0x09 */
    unsigned char pad0c[6];
    unsigned char cool93_red, cool93_green, cool93_blue;            /* +0x12 */
};
/* The factory record as far as the menu shows it. */
struct factory_record_layout {          /* factory_record, 0xA802D274 */
    unsigned char byte_0x0, byte_0x1;
    unsigned char serial_length;        /* +0x02 */
    unsigned char serial[0x12];         /* +0x03: shown after "SN:"; 0 ends the text, 0xFF is shown as a space */
    unsigned char byte_0x15;            /* +0x15: shown after "Panel ERR Count" */
    unsigned short halfword_0x16;       /* +0x16: shown in hex after "Status" */
    unsigned short halfword_0x18;       /* +0x18: bit 15 shown after "Check" */
};
/* The first three words of the device settings record. */
struct device_settings_head {           /* device_settings, 0xA802E1A0 */
    unsigned int word_0x0, word_0x4;
    unsigned int on_time;               /* +0x08: bits 8-23 hours, top byte minutes (docs/RECORDS.md) */
};
/* One record of osd_factory_menu_layout: where an item sits, in menu cells. */
struct factory_item_position { unsigned char col, row, len; };

extern struct app_state_record_layout app_state_record;
extern unsigned char osd_factory_drawn_flag, osd_factory_item, osd_factory_dummy_value, osd_factory_ssc_ratio, osd_factory_crc_auto_value;
extern struct user_settings_record user_settings;
extern struct part_record_colours part_record;
extern struct factory_record_layout factory_record;
extern struct device_settings_head device_settings;
extern const struct factory_item_position osd_factory_menu_layout[];
/* Menu texts in ROM (length byte, then the characters). */
extern const char s_001002b0[];         /* "Monitor On Time" */
extern const char s_001002e8[];         /* "FW.021 20260112" */
extern const char s_00100340[];         /* "fastUPH" */
extern const char s_00100360[];         /* "Panel ERR Count" */
extern const char s_00100380[];         /* "NT68550" */
extern const char s_00100400[];         /* "Burn In" */
extern const char s_00100410[];         /* "PRODUCT" */

extern void osd_api_enable(int, int);
extern void panel_wait_sync_pulse(void);
extern void osd_api_set_cell_size_mode(int, int);
extern void osd_api_set_layer_byte_pair(int, int, int);
extern unsigned short osd_api_cell_count_plus_one(int, int);
extern void osd_api_write_reg24_group(unsigned char, unsigned int, unsigned char);
extern void font_load_layout0_glyphs(void);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_size_in_cells(int, int, int);
extern void osd_api_set_position(unsigned short, unsigned short, unsigned char);
extern void osd_api_write_reg_cc(int, int);
extern void osd_api_reset_layer(int);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);
extern void osd_api_fill_cells(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void osd_draw_factory_number(unsigned char, unsigned short);
extern unsigned short nvram_get_device_setting(unsigned int id);
extern unsigned short oled_get_lum_mode(void);
extern void osd_draw_factory_ssc_freq(void);
extern void osd_draw_factory_ssc_ratio(void);
extern void sprintf(unsigned char *, const char *, unsigned short);
extern void osd_api_write_cell_bytes(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern unsigned short oled_user_get_temperature(void);
extern void osd_show_menu_layer(void);

/* The on-time word shifted right by 8, in five cells from (col, row). */
static void draw_on_time_hours(unsigned char col, unsigned char row)
{
    unsigned char buf[8];
    unsigned char i;

    sprintf(buf, "%5ld", device_settings.on_time >> 8);
    for (i = 0; i < 5; i++) {
        if (buf[i] == ' ')
            buf[i] = 0;
        else
            buf[i] -= DIGIT_CODE_OFFSET;
    }
    osd_api_write_cell_bytes(PLANE_0, col, row, 5, buf, MENU_LAYER_MAIN);
}

/* The top byte of the on-time word, in two cells from (col, row). */
static void draw_on_time_minutes(unsigned char col, unsigned char row)
{
    unsigned char buf[8];
    unsigned char i;

    sprintf(buf, "%2ld", device_settings.on_time >> 24);
    for (i = 0; i < 2; i++) {
        if (buf[i] == ' ')
            buf[i] = 0;
        else
            buf[i] -= DIGIT_CODE_OFFSET;
    }
    osd_api_write_cell_bytes(PLANE_0, col, row, 2, buf, MENU_LAYER_MAIN);
}

/* value as the menu text "0x" + four hex digits at (col, row). The 'n' of the format only reserves byte 0,
   which then becomes the length byte (characters before the end, minus that byte). */
static void draw_hex_value(unsigned char col, unsigned char row, unsigned short value)
{
    unsigned char buf[8];
    unsigned char i;

    for (i = 0; i < 7; i++)
        buf[i] = 0;
    sprintf(buf, "n0x%4x", value);
    for (i = 0; i < 7; i++)
        if (buf[i] == 0)
            break;
    buf[0] = i - 1;
    osd_draw_text(PLANE_0, col, row, buf[0], (const char *)buf, MENU_LAYER_MAIN);
}

/* value in three cells from (col, row). */
static void draw_number3(unsigned char col, unsigned char row, unsigned short value)
{
    unsigned char buf[8];
    unsigned char i;

    sprintf(buf, "%3d", value);
    for (i = 0; i < 3; i++) {
        if (buf[i] == ' ')
            buf[i] = 0;
        else
            buf[i] -= DIGIT_CODE_OFFSET;
    }
    osd_api_write_cell_bytes(PLANE_0, col, row, 3, buf, MENU_LAYER_MAIN);
}

/*
 * Draw the factory service menu on menu layer 0 and switch the layer on.
 *
 * Called by osd_factory_open_menu (menu state 0x111), by osd_factory_activate_item after Reset, and by
 * osd_dispatch_key_event. Phases:
 *
 *  1. Clear bit 6 of the application state halfword +4, mark the factory page as drawn, and set the layer up:
 *     24 x 37 cells, layout-0 glyphs, layer and windows off, three panel sync pulses before and after.
 *  2. Item labels on plane 0, one line per item; the four colour rows Warm50, Cool93, User and Normal65 get
 *     R, G and B columns. Line positions are fixed or come from osd_factory_menu_layout.
 *  3. The value of every item (the same fields the '+' and '-' keys change, osd_factory_increase_value).
 *  4. Highlight item 26 (CRC AUTO) and make it the selected item.
 *  5. The information block on plane 1: firmware version, panel, model and controller texts, then the lines
 *     Monitor On Time, SN:, OFF-RS, Panel ERR Count, Status / Check, Temp and fastUPH with their values.
 *  6. Switch the layer on.
 */
void osd_draw_factory_menu(void)
{
    unsigned char i;
    unsigned char col, row;

    /* 1. State and layer set-up. */
    app_state_record.sleep_word.bit_6 = 0;
    osd_factory_drawn_flag = 1;
    osd_api_enable(0, MENU_LAYER_MAIN);
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_cell_size_mode(4, MENU_LAYER_MAIN);
    osd_api_set_layer_byte_pair(0x18, 0x24, MENU_LAYER_MAIN);
    osd_api_write_reg24_group(0, osd_api_cell_count_plus_one(0x18, 0x25), MENU_LAYER_MAIN);
    font_load_layout0_glyphs();
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, MENU_LAYER_MAIN);
    osd_api_set_size_in_cells(0x18, 0x25, MENU_LAYER_MAIN);
    osd_api_set_position(1, 0x62, MENU_LAYER_MAIN);
    osd_api_write_reg_cc(TEXT_ATTR_NORMAL, MENU_LAYER_MAIN);
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_api_reset_layer(MENU_LAYER_MAIN);

    /* 2. Item labels (column, row, field width). */
    osd_api_set_glyph_write_address(0xb, MENU_LAYER_MAIN);
    osd_api_set_text_mode(0, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 5, 6, "\006" "Warm50", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 6, 6, "\006" "Cool93", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 7, 4, "\004" "User", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 8, 8, "\010" "Normal65", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 6, 9, 3, "\003" "BRI", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 0xe, 9, 3, "\003" "CON", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 0xb, 3, "\003" "SSC", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_SSC_RATIO].col, osd_factory_menu_layout[FACTORY_ITEM_SSC_RATIO].row, 5, "\005" "Ratio", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_SSC_FREQ].col, osd_factory_menu_layout[FACTORY_ITEM_SSC_FREQ].row, 4, "\004" "Freq", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 0xd, 7, s_00100410, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 0xe, 5, "\005" "Reset", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 0xf, 1, s_00100400, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_CEC_PWM_ADJUST].col, osd_factory_menu_layout[FACTORY_ITEM_CEC_PWM_ADJUST].row, 0xe, "\016" "CEC PWM Adjust", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_SENSING_TEST].col, osd_factory_menu_layout[FACTORY_ITEM_SENSING_TEST].row, 0xc, "\014Sensing Test", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 0x11, 9, "\tPanel NPC", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 0x12, 5, "\005" "Dummy", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 0x14, 0xc, "\014PHY CTS AUTO", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].col, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].row, 8, "\010" "CRC AUTO", MENU_LAYER_MAIN);
    /* The colour rows (lines 5..8): 22 cells filled with 0x290, then the column letters. */
    for (i = 5; i < 9; i++) {
        osd_api_fill_cells(1, i, 0x16, 0x290, MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, 8, i, 1, "\001" "R", MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, 0xc, i, 1, "\001" "G", MENU_LAYER_MAIN);
        osd_draw_text(PLANE_0, 0x10, i, 1, "\001" "B", MENU_LAYER_MAIN);
    }

    /* 3. Item values. The custom gains are kept as 0..100 and shown as 0..255, rounded. */
    osd_draw_factory_number(FACTORY_ITEM_WARM50_RED, part_record.warm50_red);
    osd_draw_factory_number(FACTORY_ITEM_WARM50_GREEN, part_record.warm50_green);
    osd_draw_factory_number(FACTORY_ITEM_WARM50_BLUE, part_record.warm50_blue);
    osd_draw_factory_number(FACTORY_ITEM_COOL93_RED, part_record.cool93_red);
    osd_draw_factory_number(FACTORY_ITEM_COOL93_GREEN, part_record.cool93_green);
    osd_draw_factory_number(FACTORY_ITEM_COOL93_BLUE, part_record.cool93_blue);
    osd_draw_factory_number(FACTORY_ITEM_USER_RED, (user_settings.red_gain * 255u + 50) / 100);
    osd_draw_factory_number(FACTORY_ITEM_USER_GREEN, (user_settings.green_gain * 255u + 50) / 100);
    osd_draw_factory_number(FACTORY_ITEM_USER_BLUE, (user_settings.blue_gain * 255u + 50) / 100);
    osd_draw_factory_number(FACTORY_ITEM_NORMAL65_RED, part_record.normal65_red);
    osd_draw_factory_number(FACTORY_ITEM_NORMAL65_GREEN, part_record.normal65_green);
    osd_draw_factory_number(FACTORY_ITEM_NORMAL65_BLUE, part_record.normal65_blue);
    osd_draw_factory_number(FACTORY_ITEM_BRIGHTNESS, user_settings.brightness);
    osd_draw_factory_number(FACTORY_ITEM_CONTRAST, user_settings.contrast);
    osd_api_set_glyph_write_address(0xca, MENU_LAYER_MAIN);
    osd_api_set_text_mode(0, MENU_LAYER_MAIN);
    if (user_settings.word_0x1d4.bytes[BURN_IN_FLAG] == 1)
        osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_BURN_IN].col + 8, 0xf, 3, "\003" "ON ", MENU_LAYER_MAIN);
    else
        osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_BURN_IN].col + 8, 0xf, 3, "\003" "OFF", MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(0xd6, MENU_LAYER_MAIN);
    if (user_settings.factory_marker == FACTORY_MODE_MARKER)          /* PRODUCT */
        osd_draw_text(PLANE_0, 9, 0xd, 3, "\003" "ON ", MENU_LAYER_MAIN);
    else
        osd_draw_text(PLANE_0, 9, 0xd, 3, "\003" "OFF", MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(0xd3, MENU_LAYER_MAIN);
    if (nvram_get_device_setting(DEVICE_SETTING_PHY_CTS_AUTO))
        osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_PHY_CTS_AUTO].col + 0xb, 0x14, 3, "\003" "ON ", MENU_LAYER_MAIN);
    else
        osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_PHY_CTS_AUTO].col + 0xb, 0x14, 3, "\003" "OFF", MENU_LAYER_MAIN);
    osd_draw_factory_number(FACTORY_ITEM_PANEL_NPC, oled_get_lum_mode());
    osd_draw_factory_number(FACTORY_ITEM_DUMMY, osd_factory_dummy_value);
    osd_api_set_glyph_write_address(0xf7, MENU_LAYER_MAIN);
    if (nvram_get_device_setting(DEVICE_SETTING_SENSING_TEST))
        osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_SENSING_TEST].col + 0xb, 0x13, 3, "\003" "ON ", MENU_LAYER_MAIN);
    else
        osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_SENSING_TEST].col + 0xb, 0x13, 3, "\003" "OFF", MENU_LAYER_MAIN);
    osd_draw_factory_ssc_freq();
    osd_draw_factory_ssc_ratio();
    osd_draw_factory_number(FACTORY_ITEM_SSC_RATIO, osd_factory_ssc_ratio);
    osd_draw_factory_ssc_ratio();
    osd_api_set_glyph_write_address(0xea, MENU_LAYER_MAIN);
    osd_api_set_text_mode(0, MENU_LAYER_MAIN);
    col = osd_factory_menu_layout[FACTORY_ITEM_HDMI_CTS].col;
    row = osd_factory_menu_layout[FACTORY_ITEM_HDMI_CTS].row;
    osd_draw_text(PLANE_0, col, row, 8, "\010" "HDMI CTS", MENU_LAYER_MAIN);
    if (user_settings.word_0x1d4.word & HDMI_CTS_BIT)
        osd_draw_text(PLANE_0, col + 0xc, row, 3, "\003" "ON ", MENU_LAYER_MAIN);
    else
        osd_draw_text(PLANE_0, col + 0xc, row, 3, "\003" "OFF", MENU_LAYER_MAIN);
    osd_draw_factory_number(FACTORY_ITEM_CEC_PWM_ADJUST, user_settings.brightness_knee);
    osd_api_set_glyph_write_address(0xf4, MENU_LAYER_MAIN);
    osd_api_set_text_mode(0, MENU_LAYER_MAIN);
    if (osd_factory_crc_auto_value == 1)
        osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].col + 8, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].row, 3, "\003" "ON ", MENU_LAYER_MAIN);
    else
        osd_draw_text(PLANE_0, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].col + 8, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].row, 3, "\003" "OFF", MENU_LAYER_MAIN);

    /* 4. The menu opens with CRC AUTO selected. */
    osd_factory_item = FACTORY_ITEM_CRC_AUTO;
    osd_api_fill_cells(osd_factory_menu_layout[osd_factory_item].col, osd_factory_menu_layout[osd_factory_item].row, osd_factory_menu_layout[osd_factory_item].len,
                 TEXT_ATTR_HIGHLIGHT, MENU_LAYER_MAIN);

    /* 5. Information block: labels on plane 1, values on plane 0. */
    osd_api_write_reg_cc(0x794, MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(0x100, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 4, 3, "\003" "   ", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 1, 0xf, s_001002e8, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 2, 0x12, "\022" "SDC QMC315AA01_D01", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 3, 0xe, "\016" "MSI MPG 321URX", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 0xf, 3, 7, s_00100380, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 0x18, 0xf, s_001002b0, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 0x19, 3, "\003" "SN:", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 0x1a, 6, "\006" "OFF-RS", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 0x1b, 0xf, s_00100360, MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 0x1c, 6, "\006" "Status", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 0xd, 0x1c, 5, "\005" "Check", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 0x1d, 4, "\004" "Temp", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_1, 1, 0x1e, 7, s_00100340, MENU_LAYER_MAIN);
    /* The serial number, turned into a menu text: a length byte (the characters before the first 0), then the
       characters with 0xFF shown as a space. */
    {
        unsigned char text[factory_record.serial_length + 1];

        text[0] = factory_record.serial_length;
        osd_api_set_glyph_write_address(0xbb, MENU_LAYER_MAIN);
        osd_api_set_text_mode(0, MENU_LAYER_MAIN);
        for (i = 0; i < factory_record.serial_length; i++)
            text[i + 1] = factory_record.serial[i];
        for (i = 0; i < factory_record.serial_length; i++)
            if (text[i + 1] == 0)
                break;
        text[0] = i;
        for (i = 0; i < factory_record.serial_length; i++)
            if (text[i + 1] == 0xff)
                text[i + 1] = ' ';
        osd_draw_text(PLANE_0, 6, 0x19, factory_record.serial_length + 1, (const char *)text, MENU_LAYER_MAIN);
    }
    draw_on_time_hours(0xe, 0x18);
    draw_on_time_minutes(0x14, 0x18);
    draw_number3(0x10, 0x1b, factory_record.byte_0x15);                 /* Panel ERR Count */
    draw_hex_value(7, 0x1c, factory_record.halfword_0x16);              /* Status */
    draw_number3(0x12, 0x1c, factory_record.halfword_0x18 >> 15);       /* Check */
    draw_number3(5, 0x1d, oled_user_get_temperature());                 /* Temp */
    osd_api_set_glyph_write_address(0xfa, MENU_LAYER_MAIN);
    osd_api_set_text_mode(0, MENU_LAYER_MAIN);
    if (!nvram_get_device_setting(DEVICE_SETTING_USAGE_RECORD))         /* OFF-RS */
        osd_draw_text(PLANE_0, 9, 0x1a, 3, "\003" "YES", MENU_LAYER_MAIN);
    else
        osd_draw_text(PLANE_0, 9, 0x1a, 3, "\002" "NO", MENU_LAYER_MAIN);
    draw_hex_value(9, 0x1e, (user_settings.word_0x1d4.word >> 8) & 0xff);   /* fastUPH: settings byte +0x1D6 */

    /* 6. */
    osd_show_menu_layer();
}
