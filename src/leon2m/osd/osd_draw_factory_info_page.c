/* osd_draw_factory_info_page  (FUN_a008ce90)
 *
 * Draw the factory information page: model, firmware version, serial, panel, on-time.
 * Name basis: proven - ROM texts 'MSI MPG 321URX', 'FW VER:', 'FW.021 20260112', 'SN:', 'Panel:', 'Monitor On
 *   Time'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ce90 @ 0xa008ce90-0xa008d2e0 (276 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the two on-time fields are the same-file routines osd_draw_on_time_hours / osd_draw_on_time_minutes, written here as static copies
 *    (draw_on_time_hours / draw_on_time_minutes, as in osd_draw_factory_menu) that GCC inlines;
 *  - the serial number goes through a variable-length array of serial_length + 1 bytes;
 *  - the texts at 0x1002f8, 0x1002e8 and 0x1002b0 are separate ROM symbols (one sethi per symbol).
 */

/* The start of the factory record: the serial number, a count followed by up to 0x12 characters. */
struct factory_record_serial {          /* factory_record, 0xA802D274 */
    unsigned char byte_0x0, byte_0x1;
    unsigned char serial_length;        /* +0x02 */
    unsigned char serial[0x12];         /* +0x03: characters; 0 ends the text, 0xFF is shown as a space */
};
/* The first three words of the device settings record. */
struct device_settings_head {           /* device_settings, 0xA802E1A0 */
    unsigned int word_0x0, word_0x4;
    unsigned int on_time;               /* +0x08: bits 8-23 hours, top byte minutes (docs/RECORDS.md) */
};

#define MENU_LAYER_MAIN   0             /* the layer osd_show_menu_layer switches on */
#define PLANE_0           0             /* byte plane 0 (first argument of osd_draw_text / osd_api_write_cell_bytes) */
#define ALL_WINDOWS       8             /* osd_api_set_window_enable: all eight windows */
#define TEXT_ATTR_NORMAL  0x790         /* not highlighted (0x90 = highlighted) */

/* Number fields are drawn as cell codes: a space becomes code 0, a digit becomes its character minus 47
   ('0' -> 1 ... '9' -> 10). */
#define DIGIT_CODE_OFFSET 47

extern unsigned char osd_factory_drawn_flag;
extern struct factory_record_serial factory_record;
extern struct device_settings_head device_settings;
extern const char s_001002b0[], s_001002e8[], s_001002f8[];

extern void osd_api_set_reg_c8_ranges(int, int, int, int, int);
extern void osd_api_set_cell_size_mode(int, int);
extern void osd_api_set_layer_byte_pair(int, int, int);
extern unsigned short osd_api_cell_count_plus_one(int, int);
extern void osd_api_write_reg24_group(unsigned char, unsigned int, unsigned char);
extern void font_load_layout0_glyphs(void);
extern void osd_api_enable(int, int);
extern void osd_api_set_window_enable(int, int, int);
extern void osd_api_set_size_in_cells(int, int, int);
extern void osd_api_set_position(unsigned short, unsigned short, unsigned char);
extern void osd_api_write_reg_cc(int, int);
extern void panel_wait_sync_pulse(void);
extern void osd_api_reset_layer(int);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);
extern void sprintf(unsigned char *, const char *, unsigned short);
extern void osd_api_write_cell_bytes(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
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



/*
 * Draw the factory information page on menu layer 0 and switch the layer on.
 *
 * Called by osd_open_factory_info_page, which then sets menu state 0x113.
 *
 *  1. Set the layer up: 28 x 13 cells, layout-0 glyphs, layer and windows off while it is filled, then three
 *     panel sync pulses, a layer reset and the final position.
 *  2. Fixed texts: "MSI MPG 321URX", "FW VER:" "FW.021 20260112", "SN:", "Panel:" "SDC QMC315AA01_D01" and
 *     "Monitor On Time".
 *  3. The serial number from the factory record, after "SN:".
 *  4. The on-time from the device settings record, after "Monitor On Time".
 *  5. Switch the layer on.
 */
void osd_draw_factory_info_page(void)
{
    unsigned char i;

    osd_factory_drawn_flag = 1;

    /* 1. Layer set-up. */
    osd_api_set_reg_c8_ranges(0, 0, 0, 0, 0);
    osd_api_set_cell_size_mode(4, MENU_LAYER_MAIN);
    osd_api_set_layer_byte_pair(0x18, 0x24, MENU_LAYER_MAIN);
    osd_api_write_reg24_group(0, osd_api_cell_count_plus_one(0x1c, 0xd), MENU_LAYER_MAIN);
    font_load_layout0_glyphs();
    osd_api_enable(0, MENU_LAYER_MAIN);
    osd_api_set_window_enable(ALL_WINDOWS, 0, MENU_LAYER_MAIN);
    osd_api_set_size_in_cells(0x1c, 0xd, MENU_LAYER_MAIN);
    osd_api_set_position(1, 0x62, MENU_LAYER_MAIN);
    osd_api_write_reg_cc(TEXT_ATTR_NORMAL, MENU_LAYER_MAIN);
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    panel_wait_sync_pulse();
    osd_api_reset_layer(MENU_LAYER_MAIN);
    osd_api_set_position(0x61, 5, MENU_LAYER_MAIN);
    osd_api_set_glyph_write_address(0xb, MENU_LAYER_MAIN);
    osd_api_set_text_mode(0, MENU_LAYER_MAIN);

    /* 2. Fixed texts (column, row, field width). */
    osd_draw_text(PLANE_0, 1, 1, 0xe, "\016" "MSI MPG 321URX", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 2, 7, s_001002f8, MENU_LAYER_MAIN);          /* "FW VER:" */
    osd_draw_text(PLANE_0, 8, 2, 0xf, s_001002e8, MENU_LAYER_MAIN);        /* "FW.021 20260112" */
    osd_draw_text(PLANE_0, 1, 3, 3, "\003" "SN:", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 4, 6, "\006" "Panel:", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 6, 4, 0x12, "\022" "SDC QMC315AA01_D01", MENU_LAYER_MAIN);
    osd_draw_text(PLANE_0, 1, 5, 1, s_001002b0, MENU_LAYER_MAIN);          /* "Monitor On Time" */

    /* 3. The serial number, turned into a menu text: a length byte (the characters before the first 0),
       then the characters with 0xFF shown as a space. */
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
        osd_draw_text(PLANE_0, 6, 3, factory_record.serial_length + 1, (const char *)text, MENU_LAYER_MAIN);
    }

    /* 4. The on-time, on the "Monitor On Time" line. */
    draw_on_time_hours(0xe, 5);
    draw_on_time_minutes(0x14, 5);

    /* 5. */
    osd_show_menu_layer();
}
