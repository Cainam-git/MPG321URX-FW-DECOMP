/* uart_cmd_dispatch_set  (FUN_a00ccf34)
 *
 * Carry out a set command from the PC tool by its command row.
 *   port: command port
 *   cmd: set command row
 * Returns: 0, or 0xFF when refused
 * Note: Prints row and port; after a successful command it closes the menu unless the state is 0x106
 *   (overlays) or 0x109 (PBP split) or the row is 0x8C.
 * Name basis: proven - switch over 0x9A rows found by uart_cmd_find_set_command, 30 handlers inlined; caller
 *   uart_cmd_run_tool_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ccf34 @ 0xa00ccf34-0xa00ce348 (1285 words), flags -mcpu=v8 -O3 -g. Jump table at 0x0005a654 for
 * rows 0..0x99. Caller: uart_cmd_run_tool_task (port 4).
 * Source forms the exact build depends on:
 *  - thirty handlers are written as static functions in this file (GCC inlines them at -O3); their uncalled
 *    standalone copies in the firmware are listed at each function;
 *  - the case bodies stand in the order of the firmware, not in row order: that order sets the register names of
 *    the inlined code;
 *  - the handlers return early on a refused value;
 *  - rows 0x40 / 0x41 read the three value digits through this file's own copy of uart_cmd_parse_value
 *    (read_three_digits, inlined); rows 0x42..0x44 call uart_cmd_parse_value;
 *  - row 0x51: crosshair_x is written before crosshair_y;
 *  - after the switch the result is copied into an unsigned char, and the menu state is read once per test.
 */

#define UART_CMD_REFUSED          0xff  /* handler result: value refused; uart_cmd_run_tool_task then replies "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6     /* "5600+" + CR, built by uart_cmd_build_ok_reply */
#define BAD_VALUE                 0xff  /* read_three_digits: a character is not a digit of 0..199 */
#define VALUE_CHAR_OFFSET         9     /* frame byte of the one-digit value ("5b" + 5-character id + bytes 7..9) */
#define VALUE_HUNDREDS_OFFSET     7     /* first of the three value digits */
#define VALUE_TENS_OFFSET         8

#define SET_ROW_KEEP_MENU             0x8c   /* the one row after which the menu is never closed (no handler) */
#define MENU_STATE_SCREEN_OVERLAYS    0x106  /* the overlay screen: crosshair, alarm timer, refresh rate counter */
#define MENU_STATE_PBP_CUSTOM_SPLIT   0x109  /* the PBP custom split editor */

#define OSD_TIMEOUT_MAX           30    /* row 0x40: OSD Time out 0..30 */
#define NAVI_KEY_FUNCTION_MAX     11    /* rows 0x41..0x44: Navi Key function 0..11 */
#define ALARM_SLOT_MAX            4     /* row 0x33: alarm timer slot 0..4 */
#define CROSSHAIR_RESET_X         0x750 /* the values osd_reset_crosshair_position stores */
#define CROSSHAIR_RESET_Y         0x402
#define ALL_PORTS                 0xfe  /* input_api_set_port_signal: all input slots */
#define PORT_SIGNAL_ON            1

/* The fields of the user settings record (user_settings, docs/RECORDS.md) written here. */
struct user_settings_record {
    unsigned char pad_0x0[8];
    unsigned char language;                     /* +0x08 (written through user_settings_language) */
    unsigned char pad_0x9[3];
    unsigned char osd_timeout;                  /* +0x0C: OSD Time out */
    unsigned char pad_0xd[0x1f - 0xd];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 off, 1 PIP, 2 PBP */
    unsigned char pad_0x20[0x4b - 0x20];
    unsigned char scope_size, scope_ratio;      /* +0x4B / +0x4C: Optix Scope size and ratio */
    unsigned char pad_0x4d[0xa8 - 0x4d];
    union {                                     /* +0xA8: gaming_flags */
        unsigned int word;
        struct {
            unsigned int : 16,
                power_button_standby : 1,       /* bit 15: Power Button choice (0 OFF, 1 Standby) */
                : 2,
                refresh_rate_display : 1,       /* bit 12: Refresh Rate display switch */
                : 5,
                rgb_led : 1,                    /* bit 6: RGB LED switch (gpio_user_set_port2_bit2 drives the pin) */
                : 6;
        } bits;
    } gaming_flags;
    union {                                     /* +0xAC: settings_page_flags */
        unsigned int word;
        struct { unsigned int : 9, info_on_screen : 1, : 22; } bits;    /* bit 22: Info. On Screen */
    } settings_page_flags;
    unsigned char pad_0xb0[0x174 - 0xb0];
    union {                                     /* +0x174: word_0x174 */
        unsigned int word;
        unsigned char bytes[4];                 /* bytes[3] = byte_0x177 */
        struct { unsigned int : 16, ai_vision : 1, : 15; } bits;        /* bit 15: AI Vision switch */
    } word_0x174;
    unsigned char pad_0x178[0x17c - 0x178];
    unsigned char kvm;                          /* +0x17C: KVM_AUTO 0 / KVM_UPSTREAM 1 / KVM_TYPE_C 2 */
    unsigned char pad_0x17d[0x18a - 0x17d];
    unsigned char navi_key_up, navi_key_down, navi_key_left, navi_key_right;   /* +0x18A..+0x18D */
    unsigned char pad_0x18e[0x1ac - 0x18e];
    unsigned short crosshair_x, crosshair_y;    /* +0x1AC / +0x1AE: Smart Crosshair position */
    unsigned char pad_0x1b0[0x1dc - 0x1b0];
    union {                                     /* +0x1DC: oled_care_flags */
        unsigned int word;
        unsigned char bytes[4];                 /* bytes[1] = pixel_shift (+0x1DD, Pixel Shift speed) */
        struct { unsigned int : 16, static_screen : 1, : 15; } bits;    /* bit 15: Static Screen Detection */
    } oled_care_flags;
    unsigned char static_screen_start_time;     /* +0x1E0 */
    unsigned char static_screen_time_required;  /* +0x1E1 */
    unsigned char pad_0x1e2[0x1e8 - 0x1e2];
    unsigned char multi_logo_detection;         /* +0x1E8: Multi Logo Detection on or off */
    unsigned char pad_0x1e9[0x1ec - 0x1e9];
    union {                                     /* +0x1EC: boundary_detection, read as a word */
        unsigned int word;
        unsigned char bytes[4];                 /* bytes[2] = protect_notice (+0x1EE) */
        struct { unsigned int : 24, type_c_pd_charge : 1, : 7; } bits;  /* bit 7: Type C PD Charge */
    } boundary_detection;
};
extern struct user_settings_record user_settings;
extern unsigned char uart_cmd_alarm_slot_index, user_settings_language;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern int dbg_printf(const char *fmt, ...);
extern unsigned short osd_get_menu_state(void);
extern void osd_close_menu(void);
extern void osd_mark_settings_changed_copy(void);
extern void uart_cmd_build_ok_reply(unsigned char port);
extern void uart_cmd_clear_rx(unsigned char port);
extern void uart_cmd_send_tx_buffer(unsigned char port, unsigned char len);
extern void sys_user_swap_pip_sources(void);
extern void audio_user_toggle_source(void);
extern void hdmi_user_send_cec_action4(void);
extern void sys_user_factory_reset(void);
extern void sys_user_apply_second_picture_enable(unsigned char flag);
extern void gpio_user_set_port2_bit2(void);
extern void input_api_set_port_signal(int, int);
extern void gpio_user_set_port7_bit1(unsigned char);
extern void oled_user_apply_pixel_shift_speed(void);
extern void oled_user_apply_screen_saver_range(void);
extern void oled_user_apply_multi_logo(void);
extern void ldc_user_apply_grid_enable(void);
extern int uart_cmd_set_power_state(unsigned char port);
extern int uart_cmd_set_pbp_source1(unsigned char port);
extern int uart_cmd_set_input_source(unsigned char port);
extern int uart_cmd_set_auto_level(unsigned char port);
extern int uart_cmd_set_refresh_rate_custom_position(unsigned char port);
extern int uart_cmd_set_alarm_clock_custom_position(unsigned char port);
extern int uart_cmd_set_crosshair_position(unsigned char port);
extern int uart_cmd_set_alarm_clock_location(unsigned char port);
extern int uart_cmd_set_alarm_slot_time(unsigned char port);
extern int uart_cmd_set_alarm_clock(unsigned char port);
extern int uart_cmd_set_refresh_rate_location(unsigned char port);
extern int uart_cmd_set_crosshair_color(unsigned char port);
extern int uart_cmd_set_crosshair_icon(unsigned char port);
extern int uart_cmd_set_game_mode(unsigned char port);
extern int uart_cmd_set_byte_0x140(unsigned char port);
extern int uart_cmd_set_response_time(unsigned char port);
extern int uart_cmd_set_pbp_mode(unsigned char port);
extern int uart_cmd_set_blur_free(unsigned char port);
extern int uart_cmd_set_adaptive_sync(unsigned char port);
extern int uart_cmd_set_optix_scope(unsigned char port);
extern int uart_cmd_set_alarm_presets(unsigned char port);
extern int uart_cmd_set_screen_size(unsigned char port);
extern int uart_cmd_set_pro_mode(unsigned char port);
extern int uart_cmd_set_color_gains(unsigned char port);
extern int uart_cmd_set_color_temperature(unsigned char port);
extern int uart_cmd_set_low_blue_light(unsigned char port);
extern int uart_cmd_set_image_enhancement(unsigned char port);
extern int uart_cmd_set_transparency(unsigned char port);
extern int uart_cmd_set_setting_bit17(unsigned char port);
extern int uart_cmd_set_brightness(unsigned char port);
extern int uart_cmd_set_contrast(unsigned char port);
extern int uart_cmd_set_picture_settings(unsigned char port);
extern int uart_cmd_set_sharpness(unsigned char port);
extern int uart_cmd_set_hdmi_cec(unsigned char port);
extern int uart_cmd_set_pip_pbp_mode(unsigned char port);
extern int uart_cmd_set_pip_pbp_settings(unsigned char port);
extern int uart_cmd_set_pbp_source2(unsigned char port);
extern int uart_cmd_set_pip_source(unsigned char port);
extern int uart_cmd_set_second_source(unsigned char port);
extern int uart_cmd_set_pip_size(unsigned char port);
extern int uart_cmd_set_pip_position(unsigned char port);
extern int uart_cmd_set_pip_location(unsigned char port);
extern int uart_cmd_set_night_vision(unsigned char port);
extern int uart_cmd_set_setting_bit9(unsigned char port);
extern int uart_cmd_adjust_pbp_split(unsigned char port);
extern int uart_cmd_set_display_hdr(unsigned char port);
extern int uart_cmd_set_dsc(unsigned char port);
extern int uart_cmd_set_power_led(unsigned char port);
extern int uart_cmd_set_panel_protect_byte_0x1e5(unsigned char port);
extern int uart_cmd_start_panel_protect(unsigned char port);
extern int uart_cmd_set_static_screen_settings(unsigned char port);
extern int uart_cmd_set_static_screen_reduce_level(unsigned char port);
extern int uart_cmd_answer_panel_protect(unsigned char port);
extern int uart_cmd_set_multi_logo_level(unsigned char port);
extern int uart_cmd_set_taskbar_level(unsigned char port);
extern int uart_cmd_set_taskbar_detection(unsigned char port);
extern int uart_cmd_set_boundary_level(unsigned char port);
extern int uart_cmd_set_boundary_detection(unsigned char port);
extern int uart_cmd_set_rgb_brightness(unsigned char port);
extern int uart_cmd_check_data_block(unsigned char port);
extern int uart_cmd_write_factory_record(unsigned char port);
extern int uart_cmd_set_red_gain(unsigned char port);
extern int uart_cmd_set_green_gain(unsigned char port);
extern int uart_cmd_set_blue_gain(unsigned char port);

extern unsigned char uart_cmd_parse_value(unsigned char port);

/*
 * The set frame of each port lies in that port's receive record: uart_cmd_rx_record_port2 for port 2,
 * uart_cmd_rx_record_port3 for port 3, uart_cmd_rx_record for every other port. A frame is "5b", the 5-character
 * row id (bytes 2..6) and the value in bytes 7..9.
 *
 * Every inlined handler below ends the same way when the value is taken: uart_cmd_build_ok_reply writes "5600+" CR
 * into the port's transmit frame, uart_cmd_clear_rx clears the port's receive state, uart_cmd_send_tx_buffer sends
 * the 6 bytes, and the handler returns 0. A refused value returns UART_CMD_REFUSED with nothing changed.
 */

/* Read bytes 7..9 of the frame as a three-digit decimal value 0..199; BAD_VALUE when a character does not fit
 * (the hundreds digit may only be '0' or '1'). Same code as uart_cmd_parse_value. */
static unsigned char read_three_digits(unsigned char port)
{
    unsigned char hundreds, tens, ones;
    unsigned short value;

    if (port == 2) {
        hundreds = uart_cmd_rx_record_port2[VALUE_HUNDREDS_OFFSET];
        tens = uart_cmd_rx_record_port2[VALUE_TENS_OFFSET];
        ones = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    } else if (port == 3) {
        hundreds = uart_cmd_rx_record_port3[VALUE_HUNDREDS_OFFSET];
        tens = uart_cmd_rx_record_port3[VALUE_TENS_OFFSET];
        ones = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    } else {
        hundreds = uart_cmd_rx_record[VALUE_HUNDREDS_OFFSET];
        tens = uart_cmd_rx_record[VALUE_TENS_OFFSET];
        ones = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    }
    if (hundreds < '0' || hundreds > '1')
        return BAD_VALUE;
    if (tens < '0' || tens > '9')
        return BAD_VALUE;
    if (ones < '0' || ones > '9')
        return BAD_VALUE;
    hundreds -= '0';
    tens -= '0';
    ones -= '0';
    value = hundreds * 100 + tens * 10 + ones;
    return value;
}

/* Return the one-character value of the frame (byte 9), as received. */
static unsigned char read_value_char(unsigned char port)
{
    unsigned char c;

    if (port == 2)
        c = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        c = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        c = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    return c;
}

/* Row 0x0F (00650), standalone copy uart_cmd_swap_pip_sources: value '1' only, and only while PIP or PBP is on. */
static int cmd_swap_pip_sources(unsigned char port)
{
    if (read_value_char(port) != '1')
        return UART_CMD_REFUSED;
    if (user_settings.pip_pbp_mode == 0)
        return UART_CMD_REFUSED;
    sys_user_swap_pip_sources();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x10 (00660), standalone copy uart_cmd_toggle_setting_bit14: value '1' only, and only while PIP or PBP is
 * on; audio_user_toggle_source flips bit 14 of gaming_flags and routes the sound again. */
static int cmd_toggle_audio_source(unsigned char port)
{
    if (read_value_char(port) != '1')
        return UART_CMD_REFUSED;
    if (user_settings.pip_pbp_mode == 0)
        return UART_CMD_REFUSED;
    audio_user_toggle_source();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x16 (00440), standalone copy uart_cmd_accept_code440: value 0 or 1 is acknowledged; nothing is stored, only
 * a settings save is requested. */
static int cmd_accept_00440(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x1C (00800), standalone copy uart_cmd_set_language: the menu Language. There is no range check: any
 * character is stored as its value minus '0'. */
static int cmd_set_language(unsigned char port)
{
    user_settings_language = read_value_char(port) - '0';
    hdmi_user_send_cec_action4();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x1E (00840), standalone copy uart_cmd_reset_settings: close the menu and reload every user setting from its
 * default; the value is not read. */
static int cmd_reset_settings(unsigned char port)
{
    osd_close_menu();
    sys_user_factory_reset();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x30 (00250), standalone copy uart_cmd_set_refresh_rate_display: the Refresh Rate display switch, 0 or 1.
 * No save is requested here. */
static int cmd_set_refresh_rate_display(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.gaming_flags.bits.refresh_rate_display = value;
    osd_close_menu();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x33 (00261), standalone copy uart_cmd_set_alarm_slot: choose the alarm timer slot 0..4 whose time the get
 * command 00262 (uart_cmd_dispatch_get) reports. */
static int cmd_set_alarm_slot(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > ALARM_SLOT_MAX)
        return UART_CMD_REFUSED;
    uart_cmd_alarm_slot_index = value;
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x37 (002A1), standalone copy uart_cmd_set_scope_size: Optix Scope size 0..2, then the second picture is
 * switched as the settings say. */
static int cmd_set_scope_size(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 2)
        return UART_CMD_REFUSED;
    user_settings.scope_size = value;
    sys_user_apply_second_picture_enable(1);
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x38 (002A2), standalone copy uart_cmd_set_scope_ratio: Optix Scope ratio 0..2, as row 0x37. */
static int cmd_set_scope_ratio(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 2)
        return UART_CMD_REFUSED;
    user_settings.scope_ratio = value;
    sys_user_apply_second_picture_enable(1);
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x40 (00820), standalone copy uart_cmd_set_osd_timeout: OSD Time out, three digits 0..30. */
static int cmd_set_osd_timeout(unsigned char port)
{
    unsigned char value = read_three_digits(port);

    if (value > OSD_TIMEOUT_MAX)
        return UART_CMD_REFUSED;
    user_settings.osd_timeout = value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x41 (00900), standalone copy uart_cmd_set_navi_key_up: the Navi Key up function, three digits 0..11. */
static int cmd_set_navi_key_up(unsigned char port)
{
    unsigned char value = read_three_digits(port);

    if (value > NAVI_KEY_FUNCTION_MAX)
        return UART_CMD_REFUSED;
    user_settings.navi_key_up = value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x42 (00910), standalone copy uart_cmd_set_navi_key_down: the Navi Key down function 0..11. */
static int cmd_set_navi_key_down(unsigned char port)
{
    unsigned char value = uart_cmd_parse_value(port);

    if (value > NAVI_KEY_FUNCTION_MAX)
        return UART_CMD_REFUSED;
    user_settings.navi_key_down = value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x43 (00920), standalone copy uart_cmd_set_navi_key_left: the Navi Key left function 0..11. */
static int cmd_set_navi_key_left(unsigned char port)
{
    unsigned char value = uart_cmd_parse_value(port);

    if (value > NAVI_KEY_FUNCTION_MAX)
        return UART_CMD_REFUSED;
    user_settings.navi_key_left = value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x44 (00930), standalone copy uart_cmd_set_navi_key_right: the Navi Key right function 0..11. */
static int cmd_set_navi_key_right(unsigned char port)
{
    unsigned char value = uart_cmd_parse_value(port);

    if (value > NAVI_KEY_FUNCTION_MAX)
        return UART_CMD_REFUSED;
    user_settings.navi_key_right = value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x46 (00860), standalone copy uart_cmd_set_rgb_led: the RGB LED switch 0 or 1, then the pin is driven. */
static int cmd_set_rgb_led(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.gaming_flags.bits.rgb_led = value;
    gpio_user_set_port2_bit2();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x48, standalone copy uart_cmd_enable_port_signals: switch the signal of all input slots on; the value is
 * not read. */
static int cmd_enable_port_signals_48(unsigned char port)
{
    input_api_set_port_signal(ALL_PORTS, PORT_SIGNAL_ON);
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x4A, standalone copy uart_cmd_enable_port_signals_copy: the same as row 0x48. */
static int cmd_enable_port_signals_4a(unsigned char port)
{
    input_api_set_port_signal(ALL_PORTS, PORT_SIGNAL_ON);
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x4C (00880), standalone copy uart_cmd_set_power_button: the Power Button choice 0 or 1. */
static int cmd_set_power_button(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.gaming_flags.bits.power_button_standby = value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x4D (00830), standalone copy uart_cmd_set_info_on_screen: the Info. On Screen switch 0 or 1; the menu is
 * closed. */
static int cmd_set_info_on_screen(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.settings_page_flags.bits.info_on_screen = value;
    osd_close_menu();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x51 (002=0), standalone copy uart_cmd_reset_crosshair_position: value 1 puts the Smart Crosshair back to
 * the position the menu's Reset item stores; value 0 is acknowledged without a change. */
static int cmd_reset_crosshair_position(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    if (value == 1) {
        user_settings.crosshair_x = CROSSHAIR_RESET_X;
        user_settings.crosshair_y = CROSSHAIR_RESET_Y;
    }
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x6A (008>0), standalone copy uart_cmd_set_kvm: the KVM setting 0..2. */
static int cmd_set_kvm(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 2)
        return UART_CMD_REFUSED;
    user_settings.kvm = value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x6B (008?0), standalone copy uart_cmd_set_byte_0x177: settings byte +0x177, 0 or 1. */
static int cmd_set_byte_0x177(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.word_0x174.bytes[3] = value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x72 (008A0), standalone copy uart_cmd_set_type_c_pd_charge: the Type C PD Charge switch 0 or 1, then the
 * pin is driven. */
static int cmd_set_type_c_pd_charge(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.boundary_detection.bits.type_c_pd_charge = value;
    gpio_user_set_port7_bit1(0);
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x73 (00;00), standalone copy uart_cmd_set_pixel_shift: the Pixel Shift speed 0..2, applied at once. */
static int cmd_set_pixel_shift(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 2)
        return UART_CMD_REFUSED;
    user_settings.oled_care_flags.bytes[1] = value;
    oled_user_apply_pixel_shift_speed();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x76 (00;20), standalone copy uart_cmd_set_static_screen_detection: the Static Screen Detection switch 0 or
 * 1, then the screen saver range is applied. */
static int cmd_set_static_screen_detection(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.oled_care_flags.bits.static_screen = value;
    oled_user_apply_screen_saver_range();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x77 (00;21), standalone copy uart_cmd_set_static_screen_start_time: start time 0 or 1, as row 0x76. */
static int cmd_set_static_screen_start_time(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.static_screen_start_time = value;
    oled_user_apply_screen_saver_range();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x78 (00;22), standalone copy uart_cmd_set_static_screen_time_required: time required 0 or 1, as row
 * 0x76. */
static int cmd_set_static_screen_time_required(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.static_screen_time_required = value;
    oled_user_apply_screen_saver_range();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x81 (00;50), standalone copy uart_cmd_set_multi_logo_detection: Multi Logo Detection 0 or 1, applied at
 * once. */
static int cmd_set_multi_logo_detection(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.multi_logo_detection = value;
    oled_user_apply_multi_logo();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x87 (00;90), standalone copy uart_cmd_set_protect_notice: Protect Notice 0 or 1. */
static int cmd_set_protect_notice(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.boundary_detection.bytes[2] = value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/* Row 0x88 (002B0), standalone copy uart_cmd_set_ai_vision: the AI Vision switch 0 or 1, then
 * ldc_user_apply_grid_enable runs. */
static int cmd_set_ai_vision(unsigned char port)
{
    unsigned char value = read_value_char(port) - '0';

    if (value > 1)
        return UART_CMD_REFUSED;
    user_settings.word_0x174.bits.ai_vision = value;
    ldc_user_apply_grid_enable();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}

/*
 * Carry out one set frame from the PC tool. 'cmd' is the row of the set tables that uart_cmd_find_set_command
 * matched: 0..0x8C in the 11-byte table uart_cmd_set_rows11, 0x8D..0x98 in the 26-byte table, 0x99 for the
 * 42-byte frame. Each case below carries the row id (frame bytes 2..6) of its row.
 *
 * Phases:
 *  1. Print the row and the port on the debug output ("UartSetCmdProcess").
 *  2. Run the handler of the row. A handler checks the value in the frame, stores and applies the setting, sends
 *     "5600+" itself and returns 0, or returns UART_CMD_REFUSED with nothing changed. Rows without a handler,
 *     and rows not listed, do nothing and give 0: then no reply is sent at all.
 *  3. After a result of 0 the on-screen menu is closed, except after row SET_ROW_KEEP_MENU and while the overlay
 *     screen or the PBP custom split editor is open.
 *
 * port: the command port (uart_cmd_run_tool_task passes 4).
 * Returns the handler's result as a byte: 0, or UART_CMD_REFUSED (uart_cmd_run_tool_task then replies "5600-").
 */
unsigned char uart_cmd_dispatch_set(unsigned char port, unsigned char cmd)
{
    int result;
    unsigned char status;

    /* Phase 1: trace. */
    dbg_printf("UartSetCmdProcess %d (%d)\r\n", cmd, port);

    /* Phase 2: the handler of the row (case order as in the firmware). */
    result = 0;
    switch (cmd) {
    case 0:     /* 00100 */
        result = uart_cmd_set_power_state(port);
        break;
    case 1:     /* 00500 */
        result = uart_cmd_set_input_source(port);
        break;
    case 2:     /* 00102 */
        result = 0;
        break;
    case 3:     /* 00400 */
        result = uart_cmd_set_brightness(port);
        break;
    case 4:     /* 00410 */
        result = uart_cmd_set_contrast(port);
        break;
    case 5:     /* 00420 */
        result = uart_cmd_set_sharpness(port);
        break;
    case 6:     /* 00150 */
        result = 0;
        break;
    case 7:     /* 00155 */
        result = 0;
        break;
    case 8:     /* 00600 */
        result = uart_cmd_set_pip_pbp_mode(port);
        break;
    case 9:     /* 00620 */
        result = uart_cmd_set_second_source(port);
        break;
    case 10:    /* 00610 */
        result = uart_cmd_set_pip_source(port);
        break;
    case 11:    /* 00611 */
        result = uart_cmd_set_pbp_source1(port);
        break;
    case 15:    /* 00650 */
        result = cmd_swap_pip_sources(port);
        break;
    case 12:    /* 00612 */
        result = uart_cmd_set_pbp_source2(port);
        break;
    case 13:    /* 00630 */
        result = uart_cmd_set_pip_size(port);
        break;
    case 14:    /* 00640 */
        result = uart_cmd_set_pip_location(port);
        break;
    case 74:    /* 0x4A */
        result = cmd_enable_port_signals_4a(port);
        break;
    case 17:    /* 00430 */
        result = uart_cmd_set_color_temperature(port);
        break;
    case 18:    /* 00431 */
        result = uart_cmd_set_red_gain(port);
        break;
    case 19:    /* 00432 */
        result = uart_cmd_set_green_gain(port);
        break;
    case 20:    /* 00433 */
        result = uart_cmd_set_blue_gain(port);
        break;
    case 16:    /* 00660 */
        result = cmd_toggle_audio_source(port);
        break;
    case 21:    /* 00434 */
        result = uart_cmd_set_color_gains(port);
        break;
    case 23:    /* 00604 */
        result = 0;
        break;
    case 24:    /* 00605 */
        result = 0;
        break;
    case 25:    /* 00612 (row 0x0C matches first) */
        result = 0;
        break;
    case 26:    /* 00613 */
        result = 0;
        break;
    case 27:    /* 00614 */
        result = 0;
        break;
    case 29:    /* 00619 */
        result = 0;
        break;
    case 31:    /* 00625 */
        result = 0;
        break;
    case 32:    /* 00626 */
        result = 0;
        break;
    case 22:    /* 00440 */
        result = cmd_accept_00440(port);
        break;
    case 33:    /* 00627 */
        result = 0;
        break;
    case 34:    /* 00628 */
        result = 0;
        break;
    case 35:    /* 00629 */
        result = 0;
        break;
    case 28:    /* 00800 */
        result = cmd_set_language(port);
        break;
    case 36:    /* 00630 (row 0x0D matches first) */
        result = 0;
        break;
    case 38:    /* 00650 (row 0x0F matches first) */
        result = 0;
        break;
    case 39:    /* 00670 */
        result = 0;
        break;
    case 40:    /* 00660 (row 0x10 matches first) */
        result = 0;
        break;
    case 41:    /* 00270 */
        result = uart_cmd_set_crosshair_icon(port);
        break;
    case 48:    /* 00250 */
        result = cmd_set_refresh_rate_display(port);
        break;
    case 51:    /* 00261 */
        result = cmd_set_alarm_slot(port);
        break;
    case 55:    /* 002A1 */
        result = cmd_set_scope_size(port);
        break;
    case 42:    /* 00271 */
        result = uart_cmd_set_crosshair_color(port);
        break;
    case 43:    /* 00240 */
        result = uart_cmd_set_auto_level(port);
        break;
    case 44:    /* 00200 */
        result = uart_cmd_set_game_mode(port);
        break;
    case 45:    /* 00210 */
        result = uart_cmd_set_byte_0x140(port);
        break;
    case 46:    /* 00220 */
        result = uart_cmd_set_response_time(port);
        break;
    case 47:    /* 00230 */
        result = uart_cmd_set_blur_free(port);
        break;
    case 49:    /* 00251 */
        result = uart_cmd_set_refresh_rate_location(port);
        break;
    case 50:    /* 00260 */
        result = uart_cmd_set_alarm_clock(port);
        break;
    case 52:    /* 00262 */
        result = uart_cmd_set_alarm_slot_time(port);
        break;
    case 56:    /* 002A2 */
        result = cmd_set_scope_ratio(port);
        break;
    case 53:    /* 00263 */
        result = uart_cmd_set_alarm_clock_location(port);
        break;
    case 54:    /* 002A0 */
        result = uart_cmd_set_optix_scope(port);
        break;
    case 57:    /* 00280 */
        result = uart_cmd_set_adaptive_sync(port);
        break;
    case 72:    /* 0x48 */
        result = cmd_enable_port_signals_48(port);
        break;
    case 58:    /* 00290 */
        result = 0;
        break;
    case 64:    /* 00820 */
        result = cmd_set_osd_timeout(port);
        break;
    case 59:    /* 002:0 */
        result = uart_cmd_set_screen_size(port);
        break;
    case 60:    /* 00300 */
        result = uart_cmd_set_pro_mode(port);
        break;
    case 65:    /* 00900 */
        result = cmd_set_navi_key_up(port);
        break;
    case 61:    /* 00310 */
        result = uart_cmd_set_low_blue_light(port);
        break;
    case 62:    /* 00340 */
        result = uart_cmd_set_image_enhancement(port);
        break;
    case 63:    /* 00810 */
        result = uart_cmd_set_transparency(port);
        break;
    case 66:    /* 00910 */
        result = cmd_set_navi_key_down(port);
        break;
    case 67:    /* 00920 */
        result = cmd_set_navi_key_left(port);
        break;
    case 69:    /* 00850 */
        result = uart_cmd_set_setting_bit17(port);
        break;
    case 71:    /* 002;0 */
        result = uart_cmd_set_night_vision(port);
        break;
    case 73:    /* 0x49 */
        result = 0;
        break;
    case 80:    /* 008:0 */
        result = uart_cmd_set_hdmi_cec(port);
        break;
    case 91:    /* 00510 */
        result = uart_cmd_set_setting_bit9(port);
        break;
    case 68:    /* 00930 */
        result = cmd_set_navi_key_right(port);
        break;
    case 70:    /* 00860 */
        result = cmd_set_rgb_led(port);
        break;
    case 109:   /* 006=0 */
        result = uart_cmd_set_pbp_mode(port);
        break;
    case 113:   /* 004:0 */
        result = uart_cmd_set_display_hdr(port);
        break;
    case 116:   /* 00;10 */
        result = uart_cmd_start_panel_protect(port);
        break;
    case 117:   /* 00;11 */
        result = uart_cmd_set_panel_protect_byte_0x1e5(port);
        break;
    case 121:   /* 00;23 */
        result = uart_cmd_set_static_screen_reduce_level(port);
        break;
    case 122:   /* 00;30 */
        result = uart_cmd_answer_panel_protect(port);
        break;
    case 127:   /* 00740 */
        result = uart_cmd_set_rgb_brightness(port);
        break;
    case 76:    /* 00880 */
        result = cmd_set_power_button(port);
        break;
    case 77:    /* 00830 */
        result = cmd_set_info_on_screen(port);
        break;
    case 128:   /* 006>0 */
        result = uart_cmd_adjust_pbp_split(port);
        break;
    case 130:   /* 00;51 */
        result = uart_cmd_set_multi_logo_level(port);
        break;
    case 131:   /* 00;60 */
        result = uart_cmd_set_taskbar_detection(port);
        break;
    case 81:    /* 002=0 */
        result = cmd_reset_crosshair_position(port);
        break;
    case 132:   /* 00;61 */
        result = uart_cmd_set_taskbar_level(port);
        break;
    case 133:   /* 00;70 */
        result = uart_cmd_set_boundary_detection(port);
        break;
    case 134:   /* 00;71 */
        result = uart_cmd_set_boundary_level(port);
        break;
    case 138:   /* 002D0 */
        result = uart_cmd_set_dsc(port);
        break;
    case 139:   /* 008B0 */
        result = uart_cmd_set_power_led(port);
        break;
    case 107:   /* 008?0 */
        result = cmd_set_byte_0x177(port);
        break;
    case 141:   /* 001e, 26-byte row */
        result = uart_cmd_set_picture_settings(port);
        break;
    case 106:   /* 008>0 */
        result = cmd_set_kvm(port);
        break;
    case 114:   /* 008A0 */
        result = cmd_set_type_c_pd_charge(port);
        break;
    case 136:   /* 002B0 */
        result = cmd_set_ai_vision(port);
        break;
    case 115:   /* 00;00 */
        result = cmd_set_pixel_shift(port);
        break;
    case 142:   /* 001f, 26-byte row */
        result = uart_cmd_set_alarm_presets(port);
        break;
    case 143:   /* 001g, 26-byte row */
        result = uart_cmd_set_pip_pbp_settings(port);
        break;
    case 118:   /* 00;20 */
        result = cmd_set_static_screen_detection(port);
        break;
    case 119:   /* 00;21 */
        result = cmd_set_static_screen_start_time(port);
        break;
    case 120:   /* 00;22 */
        result = cmd_set_static_screen_time_required(port);
        break;
    case 135:   /* 00;90 */
        result = cmd_set_protect_notice(port);
        break;
    case 145:   /* 001i, 26-byte row */
        result = uart_cmd_check_data_block(port);
        break;
    case 146:   /* 001j, 26-byte row */
        result = uart_cmd_write_factory_record(port);
        break;
    case 147:   /* 006<, 26-byte row */
        result = uart_cmd_set_pip_position(port);
        break;
    case 30:    /* 00840 */
        result = cmd_reset_settings(port);
        break;
    case 148:   /* 002<, 26-byte row */
        result = uart_cmd_set_crosshair_position(port);
        break;
    case 149:   /* 002>, 26-byte row */
        result = uart_cmd_set_alarm_clock_custom_position(port);
        break;
    case 150:   /* 002?, 26-byte row */
        result = uart_cmd_set_refresh_rate_custom_position(port);
        break;
    case 151:   /* 001n, 26-byte row */
        result = uart_cmd_set_static_screen_settings(port);
        break;
    case 153:   /* 0x99: the 42-byte frame */
        result = 0;
        break;
    case 129:   /* 00;50 */
        result = cmd_set_multi_logo_detection(port);
        break;
    }

    /* Phase 3: close the menu after a command that was not refused. */
    status = result;
    if (cmd != SET_ROW_KEEP_MENU) {
        if (status == 0) {
            if (osd_get_menu_state() != MENU_STATE_SCREEN_OVERLAYS) {
                if (osd_get_menu_state() != MENU_STATE_PBP_CUSTOM_SPLIT)
                    osd_close_menu();
            }
        }
    }
    return status;
}
