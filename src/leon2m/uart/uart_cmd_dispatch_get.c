/* uart_cmd_dispatch_get  (FUN_a00bfcc4)
 *
 * Answer a get command from the PC tool by its command row.
 *   port: command port
 *   cmd: get command row
 * Note: 131 rows: 28 call a handler, 64 answer inline (row 0x41 writes its whole frame, 0x26 bytes), 39 have
 *   no case.
 * Name basis: proven - switch on the 8-byte command table row; case 2 = UartSetI2CEnable; caller
 *   uart_cmd_run_tool_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bfcc4 @ 0xa00bfcc4..0xa00c0adc (902 instructions), flags -mcpu=v8 -O3 -g (also matches with
 * -msoft-float). The 131-entry jump table at 0xA00BA428 (entries image-relative, +0xA0060000) is built from the
 * same source.
 * Source forms the exact build depends on:
 *  - every inline case body is the standalone get handler of that row (uart_cmd_get_color_temperature .. uart_cmd_get_protect_notice, present but
 *    uncalled in the firmware), written directly in the case;
 *  - the cases stand in the order of those handlers in the firmware (handler addresses), not in row order: the
 *    order sets the -frename-registers allocation;
 *  - row 0x1C: the slot index is held in an int (operand order of the address add);
 *  - row 0x4C: the test is written '== 0' first (branch sense of the firmware);
 *  - row 0x25: the halfword is read into an unsigned int first (keeps lduh);
 *  - rows 0x28 / 0x29 / 0x2B: byte 7 is stored before the setting is read (allocation of the two sethi registers);
 *  - the words at user_settings (+0) and user_settings_boundary_detection (+0x1EC) are read through casts of the
 *    byte objects.
 * No branch hints, no asm labels.
 */

#define GET_REPLY_LENGTH   11       /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE    0x30     /* '0': a one-digit value is sent as the value plus 0x30 */
extern unsigned char uart_cmd_alarm_slot_index;
extern unsigned char user_settings[];
extern unsigned char user_settings_language;
extern unsigned char user_settings_transparency;
extern unsigned char user_settings_color_temperature;
extern unsigned char user_settings_response_time;
extern unsigned char user_settings_pip_pbp_mode;
extern unsigned char user_settings_pbp_layout;
extern unsigned char user_settings_pip_size;
extern unsigned char user_settings_optix_scope;
extern unsigned char user_settings_scope_size;
extern unsigned char user_settings_scope_ratio;
extern unsigned char user_settings_refresh_rate_location;
extern unsigned char user_settings_alarm_clock_location;
extern unsigned char user_settings_byte_0x140;
extern unsigned char user_settings_night_vision;
extern unsigned char user_settings_byte_0x177;
extern unsigned char user_settings_crosshair_color;
extern unsigned char user_settings_kvm;
extern unsigned char user_settings_navi_key_up;
extern unsigned char user_settings_navi_key_down;
extern unsigned char user_settings_navi_key_right;
extern unsigned char user_settings_crosshair_icon;
extern unsigned char user_settings_alarm_clock;
extern unsigned char user_settings_pixel_shift;
extern unsigned char user_settings_static_screen_level;
extern unsigned char user_settings_static_screen_start_time;
extern unsigned char user_settings_static_screen_time_required;
extern unsigned char user_settings_multi_logo_detection;
extern unsigned char user_settings_multi_logo_level;
extern unsigned char user_settings_taskbar_detection;
extern unsigned char user_settings_taskbar_level;
extern unsigned char user_settings_boundary_detection;
extern unsigned char user_settings_boundary_level;
extern unsigned char user_settings_protect_notice;
extern unsigned int user_settings_blur_free_mode;
extern unsigned int user_settings_pip_location;
extern unsigned int user_settings_gaming_flags;
extern unsigned int user_settings_settings_page_flags;
extern unsigned int user_settings_professional_flags;
extern unsigned int user_settings_word_0x174;
extern unsigned int user_settings_oled_care_flags;
extern unsigned int user_settings_word_0x1f4;
extern unsigned short user_settings_image_enhancement;
extern void uart_cmd_get_brightness(unsigned char);
extern void uart_cmd_get_contrast(unsigned char);
extern void uart_cmd_get_sharpness(unsigned char);
extern void uart_cmd_get_panel_name(unsigned char);
extern void uart_cmd_get_red_gain(unsigned char);
extern void uart_cmd_get_green_gain(unsigned char);
extern void uart_cmd_get_blue_gain(unsigned char);
extern void uart_cmd_get_game_mode(unsigned char);
extern void uart_cmd_get_screen_size(unsigned char);
extern void uart_cmd_get_pro_mode(unsigned char);
extern void uart_cmd_get_osd_timeout(unsigned char);
extern void uart_cmd_get_navi_key_left(unsigned char);
extern void uart_cmd_get_picture_mode(unsigned char);
extern void uart_cmd_get_serial_number(unsigned char);
extern void uart_cmd_get_serial_number_with_sum(unsigned char);
extern void uart_cmd_get_rgb_brightness(unsigned char);
extern void uart_cmd_get_power_state(unsigned char);
extern void uart_cmd_get_second_source(unsigned char);
extern void uart_cmd_get_pbp_source2(unsigned char);
extern void uart_cmd_get_pbp_source1(unsigned char);
extern void uart_cmd_get_pip_source(unsigned char);
extern void uart_cmd_get_input_source(unsigned char);
extern void UartSetI2CEnable(unsigned char);
extern void uart_cmd_get_port_status_flag(unsigned char);
extern void uart_cmd_get_refresh_rate(unsigned char);
extern void uart_cmd_get_hdr_state(unsigned char);
extern void uart_cmd_get_resolution_code(unsigned char);
extern void uart_cmd_get_color_values(unsigned char);
extern void uart_cmd_build_get_reply(unsigned char);
extern void uart_cmd_build_get_reply_copy(unsigned char);
extern unsigned char uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_reply_frame(unsigned char, unsigned char);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern unsigned char uart_cmd_tx_frame[];

/*
 * Answer a get frame of MSI's PC tool.
 *
 *   port  the command port the frame came in on; the only caller, uart_cmd_run_tool_task, passes 4
 *   cmd   the row of the get command table uart_cmd_get_rows (0x00..0x82) whose 5-character id matched the frame
 *
 * A get frame is "58" + a 5-character id + CR; the answer is "5b" + the same id + three value characters + CR
 * (GET_REPLY_LENGTH bytes) in the reply frame uart_cmd_tx_frame. Each case comment below starts with the id of
 * its row as the table holds it (the ids use the characters after '9' as well, such as ':' and ';').
 *
 * Phases (one switch, one of three paths per row):
 *   1. 28 rows call their own get routine, which builds and sends the answer itself (row 0x02 is
 *      UartSetI2CEnable, the start of the update path).
 *   2. 64 rows answer here: bytes 7..9 of the reply frame get the value, uart_cmd_build_get_reply (or its copy)
 *      fills "5b", the id from the table row and the CR, uart_cmd_clear_rx forgets the received frame, and the 11
 *      bytes are sent. Most values are one setting byte or one bit as "00" + one digit; some rows send a fixed
 *      text. Row 0x41 writes the whole frame itself.
 *   3. The other 39 rows (0x01, 0x0B, 0x0C, 0x0E, 0x10, 0x11, 0x40, 0x44, 0x47, 0x48, 0x4D..0x55, 0x57..0x64,
 *      0x67, 0x69, 0x6D, 0x79..0x7B) have no case: nothing is sent.
 */
void uart_cmd_dispatch_get(unsigned char port, unsigned char cmd)
{
    switch (cmd) {
    case 0x3:                       /* 00400: Brightness */
        uart_cmd_get_brightness(port);
        break;
    case 0x4:                       /* 00410: Contrast */
        uart_cmd_get_contrast(port);
        break;
    case 0x5:                       /* 00420: Sharpness */
        uart_cmd_get_sharpness(port);
        break;
    case 0x4a:                      /* 001<0: the fixed digits "021" (the number of this firmware, FW.021) */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '2';
        uart_cmd_tx_frame[9] = '1';
        uart_cmd_build_get_reply(0x4a);
        uart_cmd_clear_rx(port);
        uart_api_send_bytes(port, GET_REPLY_LENGTH, uart_cmd_tx_frame);
        break;
    case 0x4b:                      /* 001?0: the panel name */
        uart_cmd_get_panel_name(port);
        break;
    case 0x6:                       /* 00430: Color Temperature */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_color_temperature + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply_copy(0x6);
        uart_cmd_clear_rx(port);
        uart_api_send_bytes(port, GET_REPLY_LENGTH, uart_cmd_tx_frame);
        break;
    case 0x7:                       /* 00431: red gain */
        uart_cmd_get_red_gain(port);
        break;
    case 0x8:                       /* 00432: green gain */
        uart_cmd_get_green_gain(port);
        break;
    case 0x9:                       /* 00433: blue gain */
        uart_cmd_get_blue_gain(port);
        break;
    case 0xa:                       /* 00434: the red, green and blue gains (+0x12..+0x14), one character each */
        uart_cmd_tx_frame[7] = user_settings[0x12] + VALUE_CHAR_BASE;
        uart_cmd_tx_frame[8] = user_settings[0x13] + VALUE_CHAR_BASE;
        uart_cmd_tx_frame[9] = user_settings[0x14] + VALUE_CHAR_BASE;
        uart_cmd_build_get_reply_copy(0xa);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0xd:                       /* 00800: the menu language */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_language + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply_copy(0xd);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0xf:                       /* 00415: the fixed digits "001" */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = '1';
        uart_cmd_build_get_reply_copy(0xf);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x13:                      /* 00200: Game Mode */
        uart_cmd_get_game_mode(port);
        break;
    case 0x14:                      /* 00210: settings byte +0x140 */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_byte_0x140 + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x14);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x15:                      /* 00220: the response time level */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_response_time + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x15);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x16:                      /* 00230: the blur reduction mode */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_blur_free_mode + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x16);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x17: {                    /* 00240: automatic level, professional flags bit 31 */
        unsigned int bit;
        bit = (user_settings_professional_flags >> 31);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x17);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x18: {                    /* 00250: Refresh Rate display, gaming flags bit 12 */
        unsigned int bit;
        bit = ((user_settings_gaming_flags >> 12) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x18);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x19:                      /* 00251: the location of the Refresh Rate overlay */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_refresh_rate_location + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x19);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x1a:                      /* 00260: the Alarm Clock timer choice */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_alarm_clock + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x1a);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x1b:                      /* 00261: the alarm timer slot selected by the PC tool */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (uart_cmd_alarm_slot_index + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x1b);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x1c: {                    /* 00262: minutes and seconds of the selected alarm timer slot */
        /* +0x197 + slot / +0x19B + slot: for slots 1..4 these are alarm_minutes_table (+0x198) and
           alarm_seconds_table (+0x19C). */
        int slot = uart_cmd_alarm_slot_index;
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = user_settings[slot + 0x197] + VALUE_CHAR_BASE;
        uart_cmd_tx_frame[9] = user_settings[slot + 0x19b] + VALUE_CHAR_BASE;
        uart_cmd_build_get_reply(0x1c);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x1d:                      /* 00263: the location of the Alarm Clock overlay */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_alarm_clock_location + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x1d);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x1e:                      /* 00270: the Smart Crosshair icon */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_crosshair_icon + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x1e);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x1f:                      /* 00271: the Smart Crosshair colour */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_crosshair_color + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x1f);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x20: {                    /* 00280: Adaptive-Sync, gaming flags bit 7 */
        unsigned int bit;
        bit = ((user_settings_gaming_flags >> 7) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x20);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x21: {                    /* 00290: gaming flags bit 13 */
        unsigned int bit;
        bit = ((user_settings_gaming_flags >> 13) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x21);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x22:                      /* 002:0: Screen Size */
        uart_cmd_get_screen_size(port);
        break;
    case 0x23:                      /* 00300: the Professional mode */
        uart_cmd_get_pro_mode(port);
        break;
    case 0x24: {                    /* 00310: Low Blue Light, professional flags bit 4 */
        unsigned int bit;
        bit = ((user_settings_professional_flags >> 4) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x24);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x25: {                    /* 00340: the Image Enhancement level, bits 0..3 of halfword +0x34 */
        unsigned int level;
        level = user_settings_image_enhancement & 0xf;
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (level + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x25);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x26:                      /* 00810: menu Transparency */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_transparency + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x26);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x27:                      /* 00820: OSD Time out */
        uart_cmd_get_osd_timeout(port);
        break;
    case 0x28: {                    /* 00900: the Navi Key up function, two digits */
        unsigned char function;
        uart_cmd_tx_frame[7] = '0';
        function = user_settings_navi_key_up;
        if (function > 9) {
            uart_cmd_tx_frame[8] = '1';
            uart_cmd_tx_frame[9] = (function + ('0' - 10));
        } else {
            uart_cmd_tx_frame[8] = '0';
            uart_cmd_tx_frame[9] = (function + VALUE_CHAR_BASE);
        }
        uart_cmd_build_get_reply(0x28);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x29: {                    /* 00910: the Navi Key down function, two digits */
        unsigned char function;
        uart_cmd_tx_frame[7] = '0';
        function = user_settings_navi_key_down;
        if (function > 9) {
            uart_cmd_tx_frame[8] = '1';
            uart_cmd_tx_frame[9] = (function + ('0' - 10));
        } else {
            uart_cmd_tx_frame[8] = '0';
            uart_cmd_tx_frame[9] = (function + VALUE_CHAR_BASE);
        }
        uart_cmd_build_get_reply(0x29);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x2a:                      /* 00920: the Navi Key left function */
        uart_cmd_get_navi_key_left(port);
        break;
    case 0x2b: {                    /* 00930: the Navi Key right function, two digits */
        unsigned char function;
        uart_cmd_tx_frame[7] = '0';
        function = user_settings_navi_key_right;
        if (function > 9) {
            uart_cmd_tx_frame[8] = '1';
            uart_cmd_tx_frame[9] = (function + ('0' - 10));
        } else {
            uart_cmd_tx_frame[8] = '0';
            uart_cmd_tx_frame[9] = (function + VALUE_CHAR_BASE);
        }
        uart_cmd_build_get_reply(0x2b);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x2c:                      /* 00120: the picture mode */
        uart_cmd_get_picture_mode(port);
        break;
    case 0x2d: {                    /* 00850: settings page flags bit 17 */
        unsigned int bit;
        bit = ((user_settings_settings_page_flags >> 17) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x2d);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x2e:                      /* 00130: the factory record */
        uart_cmd_get_serial_number(port);
        break;
    case 0x2f:                      /* 00140: "00" and the fixed byte 0x9F */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = 0x9f;
        uart_cmd_build_get_reply(0x2f);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x30:                      /* 00150: the fixed text "V23" */
        uart_cmd_tx_frame[7] = 'V';
        uart_cmd_tx_frame[8] = '2';
        uart_cmd_tx_frame[9] = '3';
        uart_cmd_build_get_reply(0x30);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x33:                      /* 00600: PIP/PBP mode (0 off, 1 PIP, 2 PBP) */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_pip_pbp_mode + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x33);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x38:                      /* 00630: '2' minus the PIP size, settings byte +0x31 (0 Large .. 2 Small) */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = ('2' - user_settings_pip_size);
        uart_cmd_build_get_reply(0x38);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x39: {                    /* 00640: the PIP location, bits 4..7 of word +0x30 */
        unsigned int location;
        location = (user_settings_pip_location >> 4) & 0xf;
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (location + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x39);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x68:                      /* 006=0: the PBP layout */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_pbp_layout + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x68);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x3a: {                    /* 00860: gaming flags bit 6 */
        unsigned int bit;
        bit = ((user_settings_gaming_flags >> 6) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x3a);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x3b:                      /* 002;0: Night Vision */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_night_vision + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x3b);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x3c:                      /* 002A0: the Optix Scope switch */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_optix_scope + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x3c);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x3d:                      /* 002A1: the Optix Scope size */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_scope_size + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x3d);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x3e:                      /* 002A2: the Optix Scope ratio */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_scope_ratio + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x3e);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x56: {                    /* 00510: bit 9 of settings word +0 */
        unsigned int bit;
        bit = ((*(unsigned int *)user_settings >> 9) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x56);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x41:                      /* table row "580\" + three 0xFF wildcard bytes */
        /* The whole frame is written here: "5b00\00011" + CR. 0x26 (38) bytes are sent from the frame, more than
           the 11 written. */
        uart_cmd_tx_frame[0] = '5';
        uart_cmd_tx_frame[1] = 'b';
        uart_cmd_tx_frame[2] = '0';
        uart_cmd_tx_frame[3] = '0';
        uart_cmd_tx_frame[4] = '\\';
        uart_cmd_tx_frame[5] = '0';
        uart_cmd_tx_frame[6] = '0';
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '1';
        uart_cmd_tx_frame[9] = '1';
        uart_cmd_tx_frame[10] = '\r';
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, 0x26);
        break;
    case 0x43:                      /* 00131: the factory record with its sum */
        uart_cmd_get_serial_number_with_sum(port);
        break;
    case 0x45: {                    /* 00880: Power Button (0 OFF, 1 Standby), gaming flags bit 15 */
        unsigned int bit;
        bit = ((user_settings_gaming_flags >> 15) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x45);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x46: {                    /* 00830: Info. On Screen, settings page flags bit 22 */
        unsigned int bit;
        bit = ((user_settings_settings_page_flags >> 22) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x46);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x4c:                      /* 008:0: HDMI CEC, bit 20 of word +0xAC; '0' while PIP/PBP mode is not off */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        if (user_settings[0x1f] == 0)
            uart_cmd_tx_frame[9] = ((*(unsigned int *)(user_settings + 0xac) >> 20) & 1) + VALUE_CHAR_BASE;
        else
            uart_cmd_tx_frame[9] = '0';
        uart_cmd_build_get_reply(0x4c);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x66:                      /* 008?0: settings byte +0x177 */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_byte_0x177 + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x66);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x65:                      /* 008>0: the KVM setting */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_kvm + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x65);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x6a: {                    /* 004:0: settings page flags bits 18..19 */
        unsigned int field;
        field = (user_settings_settings_page_flags >> 18) & 3;
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (field + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x6a);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x6b: {                    /* 008A0: Type C PD Charge, bit 7 of the word at +0x1EC */
        unsigned int bit;
        bit = ((*(unsigned int *)&user_settings_boundary_detection >> 7) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x6b);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x6c: {                    /* 002B0: AI Vision, bit 15 of word +0x174 */
        unsigned int bit;
        bit = ((user_settings_word_0x174 >> 15) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x6c);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x6e: {                    /* 002D0: the DSC switch, bit 31 of word +0x1F4 */
        unsigned int bit;
        bit = (user_settings_word_0x1f4 >> 31);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x6e);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x6f: {                    /* 008B0: bit 30 of word +0x1F4 */
        unsigned int bit;
        bit = ((user_settings_word_0x1f4 >> 30) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x6f);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x70:                      /* 00;00: the Pixel Shift speed */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_pixel_shift + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x70);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x71: {                    /* 00;10: Panel Protect run, OLED care flags bit 31 */
        unsigned int bit;
        bit = (user_settings_oled_care_flags >> 31);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x71);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x72: {                    /* 00;11: Panel Protect request, OLED care flags bit 30 */
        unsigned int bit;
        bit = ((user_settings_oled_care_flags >> 30) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x72);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x73: {                    /* 00;20: Static Screen Detection, OLED care flags bit 15 */
        unsigned int bit;
        bit = ((user_settings_oled_care_flags >> 15) & 1);
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (bit + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x73);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    }
    case 0x74:                      /* 00;21: the Static Screen Detection start time */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_static_screen_start_time + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x74);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x76:                      /* 00;23: the Static Screen Detection reduce level */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_static_screen_level + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x76);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x75:                      /* 00;22: the Static Screen Detection time required */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_static_screen_time_required + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x75);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x77:                      /* 00;30: the fixed digits "000" */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = '0';
        uart_cmd_build_get_reply(0x77);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x7c:                      /* 00;50: Multi Logo Detection on or off */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_multi_logo_detection + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x7c);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x7d:                      /* 00;51: the Multi Logo Detection level, sent as level - 1 */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_multi_logo_level + ('0' - 1));
        uart_cmd_build_get_reply(0x7d);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x7e:                      /* 00;60: Taskbar Detection on or off */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_taskbar_detection + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x7e);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x7f:                      /* 00;61: the Taskbar Detection level, sent as level - 1 */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_taskbar_level + ('0' - 1));
        uart_cmd_build_get_reply(0x7f);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x80:                      /* 00;70: Boundary Detection */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_boundary_detection + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x80);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x81:                      /* 00;71: the Boundary Detection level, sent as level - 1 */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_boundary_level + ('0' - 1));
        uart_cmd_build_get_reply(0x81);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x82:                      /* 00;90: Protect Notice */
        uart_cmd_tx_frame[7] = '0';
        uart_cmd_tx_frame[8] = '0';
        uart_cmd_tx_frame[9] = (user_settings_protect_notice + VALUE_CHAR_BASE);
        uart_cmd_build_get_reply(0x82);
        uart_cmd_clear_rx(port);
        uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
        break;
    case 0x78:                      /* 00740 */
        uart_cmd_get_rgb_brightness(port);
        break;
    case 0x0:                       /* 00100: the power state */
        uart_cmd_get_power_state(port);
        break;
    case 0x37:                      /* 00620: the source of the second picture */
        uart_cmd_get_second_source(port);
        break;
    case 0x36:                      /* 00612: PBP source 2 */
        uart_cmd_get_pbp_source2(port);
        break;
    case 0x35:                      /* 00611: PBP source 1 */
        uart_cmd_get_pbp_source1(port);
        break;
    case 0x34:                      /* 00610: the PIP source */
        uart_cmd_get_pip_source(port);
        break;
    case 0x12:                      /* 00500: Input Source */
        uart_cmd_get_input_source(port);
        break;
    case 0x2:                       /* id "0040:": open the I2C path of the PC tool (update path) */
        UartSetI2CEnable(port);
        break;
    case 0x31:                      /* 00160 */
        uart_cmd_get_port_status_flag(port);
        break;
    case 0x32:                      /* 00170: the refresh rate */
        uart_cmd_get_refresh_rate(port);
        break;
    case 0x3f:                      /* 00190 */
        uart_cmd_get_hdr_state(port);
        break;
    case 0x49:                      /* 001;0 */
        uart_cmd_get_resolution_code(port);
        break;
    case 0x42:                      /* table row "580[000" */
        uart_cmd_get_color_values(port);
        break;
    }
}
