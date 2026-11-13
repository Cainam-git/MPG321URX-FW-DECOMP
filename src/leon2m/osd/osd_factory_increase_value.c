/* osd_factory_increase_value  (FUN_a008c25c)
 *
 * Raise or toggle the value of the selected factory menu item and redraw it.
 * Note: Item 24 toggles PHY CTS AUTO, which changes the panel-mode thresholds (docs/MAP.md).
 * Name basis: proven - factory menu '+' key handler (header, docs/MAP.md)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008c25c @ 0xa008c25c..0xa008cc28 (627 words), flags -mcpu=v8 -O3 -g (-msoft-float gives the same
 * code).
 * Source forms the exact build depends on: GCC's register renaming follows the source order of the case blocks
 * and of the if/else arms, so that order is kept (all choices are behaviour-neutral: every case ends in break, the
 * labels are disjoint, every arm order uses the exact negated condition):
 *  - first switch case order 6 2 3 7 9 8 10 11 12 4 5 1 13 14 15 16 17 19 21 22 24 23 25 20 26 (the tail from 16
 *    is the order of the '-' twin osd_factory_decrease_value);
 *  - arms: SSC Freq 'if (raised <= 7) {..} else store 7'; PRODUCT 'if (marker == FACTORY_MODE_MARKER)' in both
 *    ifs; Panel NPC 'if ((unsigned char)lum_mode != 2) {..} else ..'; Dummy 'if (v != 7) { if (v == 6) .. else .. }
 *    else ..'; SSC Ratio 'if (raised > 8) store 8; else {..}'; Sensing Test '== 1'; PHY CTS AUTO '!= 1';
 *  - second switch body order Burn In / User gains / other gains;
 *  - '== K' arms written as if/else with a full call per arm;
 *  - the colour-row cases 'value = &field; if (++*value == 0) *value = 0xff;' with the three draw calls repeated
 *    per case (GCC cross-jumps them as the firmware does);
 *  - BRI / CON 'if (settings->x < 100) { if (++settings->x == 0) settings->x = 0xff; }': the byte is below 100, so
 *    the increment never wraps, but the firmware keeps the 0xff test; the draw argument is read through
 *    user_settings, not the pointer (the firmware loads it again);
 *  - the User gains drawn as unsigned (v * 255u + 50) / 100.
 * No asm, no volatile.
 */

/* The items of the factory menu, by their position in osd_factory_menu_layout. The names are the labels the menu
   draws (osd_draw_factory_menu): four colour rows with R, G and B columns, then one item per line. */
enum factory_item {
    FACTORY_ITEM_WARM50_RED = 1, FACTORY_ITEM_WARM50_GREEN = 2, FACTORY_ITEM_WARM50_BLUE = 3,
    FACTORY_ITEM_COOL93_RED = 4, FACTORY_ITEM_COOL93_GREEN = 5, FACTORY_ITEM_COOL93_BLUE = 6,
    FACTORY_ITEM_USER_RED = 7, FACTORY_ITEM_USER_GREEN = 8, FACTORY_ITEM_USER_BLUE = 9,
    FACTORY_ITEM_NORMAL65_RED = 10, FACTORY_ITEM_NORMAL65_GREEN = 11, FACTORY_ITEM_NORMAL65_BLUE = 12,
    FACTORY_ITEM_BRIGHTNESS = 13,       /* "BRI" */
    FACTORY_ITEM_CONTRAST = 14,         /* "CON" */
    FACTORY_ITEM_SSC_FREQ = 15,         /* "SSC" line, "Freq" */
    FACTORY_ITEM_SSC_RATIO = 16,        /* "SSC" line, "Ratio" */
    FACTORY_ITEM_PRODUCT = 17,          /* "PRODUCT": the factory-mode marker */
    FACTORY_ITEM_RESET = 18,            /* "Reset" */
    FACTORY_ITEM_BURN_IN = 19,          /* "Burn In" */
    FACTORY_ITEM_CEC_PWM_ADJUST = 20,   /* "CEC PWM Adjust" */
    FACTORY_ITEM_PANEL_NPC = 21,        /* "Panel NPC" */
    FACTORY_ITEM_DUMMY = 22,            /* "Dummy" */
    FACTORY_ITEM_SENSING_TEST = 23,     /* "Sensing Test" */
    FACTORY_ITEM_PHY_CTS_AUTO = 24,     /* "PHY CTS AUTO" */
    FACTORY_ITEM_HDMI_CTS = 25,         /* "HDMI CTS" */
    FACTORY_ITEM_CRC_AUTO = 26          /* "CRC AUTO" */
};

/* Fields of the device settings record (nvram_get_device_setting / nvram_set_device_setting). */
#define DEVICE_SETTING_PHY_CTS_AUTO  2
#define DEVICE_SETTING_SENSING_TEST  0x10

/* Settings +0x1F6 holds this marker while the factory mode is on; switching it off writes the second value. */
#define FACTORY_MODE_MARKER          0x55aa
#define FACTORY_MODE_MARKER_CLEARED  0xbb99

#define EEPROM_AREA_SETTINGS         0x30    /* the one area SYSAPI_WriteEEPROM accepts */
#define USER_SETTINGS_SIZE           0x1fc   /* bytes of the user settings record, written at offset 0 of that area */

/* Bits of osd_request_bits; osd_run_task_post_redraw_event takes them and posts the OSD event named. */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02    /* event 0x80 */
#define OSD_REQUEST_EVENT_83         0x04    /* event 0x83 */

#define GAIN_MAX                     100     /* upper end of BRI, CON and the User gains */
#define BRIGHTNESS_KNEE_MAX          0x3ff   /* upper end of CEC PWM Adjust (settings halfword +0x1DA) */

/* The fields of the user settings record that the factory menu edits. */
struct user_settings_record {           /* user_settings, 0xA802D290 */
    unsigned char pad000[9];
    unsigned char brightness, contrast;                 /* +0x09, +0x0A */
    unsigned char pad00b[7];
    unsigned char red_gain, green_gain, blue_gain;      /* +0x12..+0x14: the custom gains, 0..100 */
    unsigned char pad015[0x1bf];
    union {                                             /* +0x1D4 */
        unsigned int word;
        struct { unsigned int bits_31_8:24, hdmi_cts:1, bits_6_0:7; } bits;    /* bit 7: "HDMI CTS" */
        unsigned char bytes[4];                         /* bytes[1] = +0x1D5 burn_in_flag */
    } word_0x1d4;
    unsigned short halfword_0x1d8;                      /* +0x1D8 */
    unsigned short brightness_knee;                     /* +0x1DA: shown as "CEC PWM Adjust" */
    unsigned char pad1dc[0x1a];
    unsigned short factory_marker;                 /* +0x1F6 */
};
#define BURN_IN_FLAG 1                  /* index of the burn_in_flag byte in word_0x1d4.bytes */

/* The colour values of the part record that the factory menu shows in the rows Warm50, Normal65 and Cool93. */
struct part_record_colours {            /* part_record, 0xA802E1F0 */
    unsigned char pad0[6];
    unsigned char warm50_red, warm50_green, warm50_blue;            /* +0x06 */
    unsigned char normal65_red, normal65_green, normal65_blue;      /* +0x09 */
    unsigned char pad0c[6];
    unsigned char cool93_red, cool93_green, cool93_blue;            /* +0x12 */
};
/* One record of osd_factory_menu_layout: where an item sits, in menu cells. */
struct factory_item_position { unsigned char col, row, len; };

extern unsigned char osd_factory_item, osd_factory_panel_npc_value, osd_factory_dummy_value, osd_factory_ssc_ratio, osd_factory_ssc_freq;
extern unsigned char osd_request_bits, osd_factory_crc_auto_value;
extern struct user_settings_record user_settings;
extern struct part_record_colours part_record;
extern const struct factory_item_position osd_factory_menu_layout[];

extern void osd_draw_factory_number(unsigned char, unsigned short);
extern int sys_user_apply_brightness(void);
extern int pq_user_apply_color_gain(void);
extern int pq_user_apply_color_settings();
extern void sys_user_apply_config_bit31(void);
extern unsigned short oled_get_lum_mode(void);
extern void oled_set_lum_mode(unsigned char);
extern unsigned short nvram_get_device_setting(unsigned int id);
extern void nvram_set_device_setting(int, int);
extern void nvram_api_store_by_selector(unsigned char);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_api_set_text_mode(int, int);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);
extern void oled_set_inspection_mode(unsigned char on);
extern void oled_set_inspection_pattern(unsigned char pat);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);
extern void input_api_set_port_option_bit20(unsigned char, unsigned char);
extern void osd_draw_factory_ssc_freq(void);
extern void osd_draw_factory_ssc_ratio(void);

/*
 * Raise the value of the highlighted factory menu item by one step, or toggle it, and redraw it.
 *
 * Runs for the down key while a factory menu item is being edited (menu state 0x112, osd_factory_edit_key_down).
 * The item is osd_factory_item. Two phases:
 *
 *  1. Change the value and redraw what shows it:
 *     - colour rows Warm50, Cool93, Normal65 (part record bytes): one higher, not above 0xFF; the whole row of three
 *       is redrawn. Row User (the custom gains): one higher, not above 100, drawn on the 0..255 scale.
 *     - BRI / CON (brightness, contrast): one higher, not above 100, then applied.
 *     - SSC Freq (0..7) / SSC Ratio (0..8): one higher, not above the end; frequency and ratio are redrawn.
 *     - PRODUCT: switches the factory-mode marker and writes the whole user settings record to the EEPROM.
 *     - Burn In, HDMI CTS, CRC AUTO: switch a setting bit; Sensing Test, PHY CTS AUTO: switch a device setting.
 *     - Panel NPC: the luminance mode of the OLED panel controller, 0 -> 1 -> 2 -> 0.
 *     - Dummy: the inspection pattern 0 -> ... -> 7 -> 0; 0 switches the inspection mode off.
 *     - CEC PWM Adjust (settings halfword +0x1DA): one higher, not above 0x3FF, then brightness applied.
 *     For the User gains and the SSC values, a value already at its upper end is stored again and not redrawn.
 *  2. Apply the colour values after a colour change and set the request bits for the main loop.
 *
 * Reset (item 18) has no case here. Unlike the '-' twin, CEC PWM Adjust sets only the settings-changed request
 * here and has no lower limit.
 */
void osd_factory_increase_value(void)
{
    struct user_settings_record *settings;
    unsigned char raised;
    unsigned char *value;
    unsigned short lum_mode;

    /* Phase 1: change the value and redraw it. */
    switch (osd_factory_item) {
    case FACTORY_ITEM_COOL93_BLUE:
        value = &part_record.cool93_blue; if (++*value == 0) *value = 0xff;
        osd_draw_factory_number(FACTORY_ITEM_COOL93_RED, part_record.cool93_red);
        osd_draw_factory_number(FACTORY_ITEM_COOL93_GREEN, part_record.cool93_green);
        osd_draw_factory_number(FACTORY_ITEM_COOL93_BLUE, part_record.cool93_blue);
        break;
    case FACTORY_ITEM_WARM50_GREEN:
        value = &part_record.warm50_green; if (++*value == 0) *value = 0xff;
        osd_draw_factory_number(FACTORY_ITEM_WARM50_RED, part_record.warm50_red);
        osd_draw_factory_number(FACTORY_ITEM_WARM50_GREEN, part_record.warm50_green);
        osd_draw_factory_number(FACTORY_ITEM_WARM50_BLUE, part_record.warm50_blue);
        break;
    case FACTORY_ITEM_WARM50_BLUE:
        value = &part_record.warm50_blue; if (++*value == 0) *value = 0xff;
        osd_draw_factory_number(FACTORY_ITEM_WARM50_RED, part_record.warm50_red);
        osd_draw_factory_number(FACTORY_ITEM_WARM50_GREEN, part_record.warm50_green);
        osd_draw_factory_number(FACTORY_ITEM_WARM50_BLUE, part_record.warm50_blue);
        break;
    case FACTORY_ITEM_USER_RED:
        /* The custom gains are kept as 0..100 and shown as 0..255, rounded. */
        settings = &user_settings;
        raised = settings->red_gain + 1;
        if (raised > GAIN_MAX) settings->red_gain = GAIN_MAX;
        else { settings->red_gain = raised; osd_draw_factory_number(FACTORY_ITEM_USER_RED, (raised * 255u + 50) / 100); }
        break;
    case FACTORY_ITEM_USER_BLUE:
        settings = &user_settings;
        raised = settings->blue_gain + 1;
        if (raised > GAIN_MAX) settings->blue_gain = GAIN_MAX;
        else { settings->blue_gain = raised; osd_draw_factory_number(FACTORY_ITEM_USER_BLUE, (raised * 255u + 50) / 100); }
        break;
    case FACTORY_ITEM_USER_GREEN:
        settings = &user_settings;
        raised = settings->green_gain + 1;
        if (raised > GAIN_MAX) settings->green_gain = GAIN_MAX;
        else { settings->green_gain = raised; osd_draw_factory_number(FACTORY_ITEM_USER_GREEN, (raised * 255u + 50) / 100); }
        break;
    case FACTORY_ITEM_NORMAL65_RED:
        value = &part_record.normal65_red; if (++*value == 0) *value = 0xff;
        osd_draw_factory_number(FACTORY_ITEM_NORMAL65_RED, part_record.normal65_red);
        osd_draw_factory_number(FACTORY_ITEM_NORMAL65_GREEN, part_record.normal65_green);
        osd_draw_factory_number(FACTORY_ITEM_NORMAL65_BLUE, part_record.normal65_blue);
        break;
    case FACTORY_ITEM_NORMAL65_GREEN:
        value = &part_record.normal65_green; if (++*value == 0) *value = 0xff;
        osd_draw_factory_number(FACTORY_ITEM_NORMAL65_RED, part_record.normal65_red);
        osd_draw_factory_number(FACTORY_ITEM_NORMAL65_GREEN, part_record.normal65_green);
        osd_draw_factory_number(FACTORY_ITEM_NORMAL65_BLUE, part_record.normal65_blue);
        break;
    case FACTORY_ITEM_NORMAL65_BLUE:
        value = &part_record.normal65_blue; if (++*value == 0) *value = 0xff;
        osd_draw_factory_number(FACTORY_ITEM_NORMAL65_RED, part_record.normal65_red);
        osd_draw_factory_number(FACTORY_ITEM_NORMAL65_GREEN, part_record.normal65_green);
        osd_draw_factory_number(FACTORY_ITEM_NORMAL65_BLUE, part_record.normal65_blue);
        break;
    case FACTORY_ITEM_COOL93_RED:
        value = &part_record.cool93_red; if (++*value == 0) *value = 0xff;
        osd_draw_factory_number(FACTORY_ITEM_COOL93_RED, part_record.cool93_red);
        osd_draw_factory_number(FACTORY_ITEM_COOL93_GREEN, part_record.cool93_green);
        osd_draw_factory_number(FACTORY_ITEM_COOL93_BLUE, part_record.cool93_blue);
        break;
    case FACTORY_ITEM_COOL93_GREEN:
        value = &part_record.cool93_green; if (++*value == 0) *value = 0xff;
        osd_draw_factory_number(FACTORY_ITEM_COOL93_RED, part_record.cool93_red);
        osd_draw_factory_number(FACTORY_ITEM_COOL93_GREEN, part_record.cool93_green);
        osd_draw_factory_number(FACTORY_ITEM_COOL93_BLUE, part_record.cool93_blue);
        break;
    case FACTORY_ITEM_WARM50_RED:
        value = &part_record.warm50_red; if (++*value == 0) *value = 0xff;
        osd_draw_factory_number(FACTORY_ITEM_WARM50_RED, part_record.warm50_red);
        osd_draw_factory_number(FACTORY_ITEM_WARM50_GREEN, part_record.warm50_green);
        osd_draw_factory_number(FACTORY_ITEM_WARM50_BLUE, part_record.warm50_blue);
        break;
    case FACTORY_ITEM_BRIGHTNESS:
        settings = &user_settings;
        if (settings->brightness < GAIN_MAX) { if (++settings->brightness == 0) settings->brightness = 0xff; }
        osd_draw_factory_number(FACTORY_ITEM_BRIGHTNESS, user_settings.brightness);
        sys_user_apply_brightness();
        break;
    case FACTORY_ITEM_CONTRAST:
        settings = &user_settings;
        if (settings->contrast < GAIN_MAX) { if (++settings->contrast == 0) settings->contrast = 0xff; }
        osd_draw_factory_number(FACTORY_ITEM_CONTRAST, user_settings.contrast);
        pq_user_apply_color_gain();
        break;
    case FACTORY_ITEM_SSC_FREQ:
        /* The ratio is shown as a percentage computed from both values, so both are redrawn. */
        raised = osd_factory_ssc_freq + 1;
        if (raised <= 7) { osd_factory_ssc_freq = raised; osd_draw_factory_ssc_freq(); osd_draw_factory_ssc_ratio(); }
        else osd_factory_ssc_freq = 7;
        break;
    case FACTORY_ITEM_SSC_RATIO:
        raised = osd_factory_ssc_ratio + 1;
        if (raised > 8) osd_factory_ssc_ratio = 8;
        else { osd_factory_ssc_ratio = raised; osd_draw_factory_number(FACTORY_ITEM_SSC_RATIO, raised); osd_draw_factory_ssc_ratio(); }
        break;
    case FACTORY_ITEM_PRODUCT:
        /* Switch the factory-mode marker, show it as ON / OFF and save the whole settings record. */
        if (user_settings.factory_marker == FACTORY_MODE_MARKER) user_settings.factory_marker = FACTORY_MODE_MARKER_CLEARED;
        else user_settings.factory_marker = FACTORY_MODE_MARKER;
        osd_api_set_glyph_write_address(0xd6, 0);
        if (user_settings.factory_marker == FACTORY_MODE_MARKER)
            osd_draw_text(0, 9, 0xd, 3, "\003" "ON ", 0);
        else
            osd_draw_text(0, 9, 0xd, 3, "\003" "OFF", 0);
        SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
        break;
    case FACTORY_ITEM_BURN_IN:
        settings = &user_settings;
        settings->word_0x1d4.bytes[BURN_IN_FLAG] ^= 1;
        osd_api_set_glyph_write_address(0xca, 0);
        osd_api_set_text_mode(0, 0);
        if (settings->word_0x1d4.bytes[BURN_IN_FLAG] == 1)
            osd_draw_text(0, osd_factory_menu_layout[FACTORY_ITEM_BURN_IN].col + 8, 0xf, 3, "\003" "ON ", 0);
        else
            osd_draw_text(0, osd_factory_menu_layout[FACTORY_ITEM_BURN_IN].col + 8, 0xf, 3, "\003" "OFF", 0);
        break;
    case FACTORY_ITEM_PANEL_NPC:
        /* Read the luminance mode back from the panel controller and step it up, 2 wrapping to 0. */
        value = &osd_factory_panel_npc_value;
        lum_mode = oled_get_lum_mode();
        if ((unsigned char)lum_mode != 2) { lum_mode++; *value = lum_mode; oled_set_lum_mode((unsigned char)lum_mode); }
        else { *value = 0; oled_set_lum_mode(0); }
        osd_draw_factory_number(FACTORY_ITEM_PANEL_NPC, osd_factory_panel_npc_value);
        break;
    case FACTORY_ITEM_DUMMY:
        /* Value 0 is inspection mode off; 1..7 is inspection mode on with that pattern. Stepping from 6 to 7
           sends pattern 0, not 7. */
        raised = osd_factory_dummy_value;
        if (raised != 7) { if (raised == 6) { osd_factory_dummy_value = raised + 1; oled_set_inspection_mode(1); oled_set_inspection_pattern(0); } else { osd_factory_dummy_value = raised + 1; oled_set_inspection_mode(1); oled_set_inspection_pattern(osd_factory_dummy_value); } }
        else { osd_factory_dummy_value = 0; oled_set_inspection_mode(0); oled_set_inspection_pattern(0); }
        osd_draw_factory_number(FACTORY_ITEM_DUMMY, osd_factory_dummy_value);
        break;
    case FACTORY_ITEM_PHY_CTS_AUTO:
        if (nvram_get_device_setting(DEVICE_SETTING_PHY_CTS_AUTO) != 1) nvram_set_device_setting(DEVICE_SETTING_PHY_CTS_AUTO, 1);
        else nvram_set_device_setting(DEVICE_SETTING_PHY_CTS_AUTO, 0);
        osd_api_set_glyph_write_address(0xd3, 0);
        if (nvram_get_device_setting(DEVICE_SETTING_PHY_CTS_AUTO))
            osd_draw_text(0, osd_factory_menu_layout[FACTORY_ITEM_PHY_CTS_AUTO].col + 0xb, 0x14, 3, "\003" "ON ", 0);
        else
            osd_draw_text(0, osd_factory_menu_layout[FACTORY_ITEM_PHY_CTS_AUTO].col + 0xb, 0x14, 3, "\003" "OFF", 0);
        nvram_api_store_by_selector(1);
        break;
    case FACTORY_ITEM_SENSING_TEST:
        if (nvram_get_device_setting(DEVICE_SETTING_SENSING_TEST) == 1) nvram_set_device_setting(DEVICE_SETTING_SENSING_TEST, 0);
        else nvram_set_device_setting(DEVICE_SETTING_SENSING_TEST, 1);
        osd_api_set_glyph_write_address(0xf7, 0);
        if (nvram_get_device_setting(DEVICE_SETTING_SENSING_TEST))
            osd_draw_text(0, osd_factory_menu_layout[FACTORY_ITEM_SENSING_TEST].col + 0xb, 0x13, 3, "\003" "ON ", 0);
        else
            osd_draw_text(0, osd_factory_menu_layout[FACTORY_ITEM_SENSING_TEST].col + 0xb, 0x13, 3, "\003" "OFF", 0);
        nvram_api_store_by_selector(1);
        break;
    case FACTORY_ITEM_HDMI_CTS:
        /* Switch bit 7 of settings word +0x1D4. sys_user_apply_config_bit31 then passes on bit 9 of settings
           word +0, not this bit. The label is drawn again with the value. */
        settings = &user_settings;
        settings->word_0x1d4.bits.hdmi_cts ^= 1;
        sys_user_apply_config_bit31();
        osd_api_set_glyph_write_address(0xea, 0);
        osd_api_set_text_mode(0, 0);
        {
            unsigned char col = osd_factory_menu_layout[FACTORY_ITEM_HDMI_CTS].col, row = osd_factory_menu_layout[FACTORY_ITEM_HDMI_CTS].row;
            osd_draw_text(0, col, row, 8, "\010" "HDMI CTS", 0);
            if (settings->word_0x1d4.bits.hdmi_cts)
                osd_draw_text(0, col + 0xc, row, 3, "\003" "ON ", 0);
            else
                osd_draw_text(0, col + 0xc, row, 3, "\003" "OFF", 0);
        }
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        break;
    case FACTORY_ITEM_CEC_PWM_ADJUST:
        settings = &user_settings;
        if ((unsigned short)(settings->brightness_knee + 1) > BRIGHTNESS_KNEE_MAX) settings->brightness_knee = BRIGHTNESS_KNEE_MAX;
        else settings->brightness_knee = settings->brightness_knee + 1;
        sys_user_apply_brightness();
        osd_draw_factory_number(FACTORY_ITEM_CEC_PWM_ADJUST, settings->brightness_knee);
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        break;
    case FACTORY_ITEM_CRC_AUTO:
        osd_factory_crc_auto_value ^= 1;
        input_api_set_port_option_bit20(0xd, osd_factory_crc_auto_value);
        input_api_set_port_option_bit20(0xc, osd_factory_crc_auto_value);
        osd_api_set_glyph_write_address(0xf4, 0);
        osd_api_set_text_mode(0, 0);
        if (osd_factory_crc_auto_value == 1)
            osd_draw_text(0, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].col + 8, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].row, 3, "\003" "ON ", 0);
        else
            osd_draw_text(0, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].col + 8, osd_factory_menu_layout[FACTORY_ITEM_CRC_AUTO].row, 3, "\003" "OFF", 0);
        break;
    }

    /* Phase 2: apply colour changes and tell the main loop. */
    switch (osd_factory_item) {
    case FACTORY_ITEM_BURN_IN:
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        break;
    case FACTORY_ITEM_USER_RED: case FACTORY_ITEM_USER_GREEN: case FACTORY_ITEM_USER_BLUE:
        pq_user_apply_color_settings();
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED | OSD_REQUEST_EVENT_83;
        break;
    case FACTORY_ITEM_WARM50_RED: case FACTORY_ITEM_WARM50_GREEN: case FACTORY_ITEM_WARM50_BLUE:
    case FACTORY_ITEM_COOL93_RED: case FACTORY_ITEM_COOL93_GREEN: case FACTORY_ITEM_COOL93_BLUE:
    case FACTORY_ITEM_NORMAL65_RED: case FACTORY_ITEM_NORMAL65_GREEN: case FACTORY_ITEM_NORMAL65_BLUE:
        pq_user_apply_color_settings();
        osd_request_bits |= OSD_REQUEST_EVENT_83;
        break;
    }
}
