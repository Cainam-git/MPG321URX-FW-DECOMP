/* uart_cmd_set_pip_pbp_settings  (FUN_a00c7e3c)
 *
 * Set the PIP/PBP mode with its sources, size, location and layout from one command.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b001g (26-byte frame); fields +0x1F, +0x20, +0x31, +0x30, +0x2F, +0x1E.
 * Name basis: proven - set row 0x8f; same fields as the PIP/PBP menu (osd_enter_pip_pbp_items,
 *   osd_enter_pip_size_choices ...)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c7e3c @ 0xa00c7e3c-0xa00c8410 (373 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers and rx_byte() are defined in this file, so GCC inlines them at -O3;
 *  - only the reads of frame bytes 8 and 0x11 go through rx_byte() (one return per port); the other reads are
 *    written out per port;
 *  - the mode is copied from the unsigned short difference into the unsigned char frame_value, which is reused
 *    for the source digit (computed and tested as an unsigned char);
 *  - the word at +0x30 is a bit-field word (pip_size and pip_location are fields of it);
 *  - app_state_record is declared as one unsigned short.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': a value byte of the frame is the value plus 0x30 */

/* Frame bytes of the 26-byte command (each the value plus 0x30). */
#define FRAME_PIP_PBP_MODE        0x06      /* PIP/PBP mode 0..2 */
#define FRAME_PIP_SOURCE          0x08      /* PIP: source of the second picture, 0..3 */
#define FRAME_PIP_SIZE            0x09      /* PIP: size row 0..2 (stored as 2 - row) */
#define FRAME_PIP_LOCATION        0x0a      /* PIP: location 0..4 */
#define FRAME_PBP_LAYOUT          0x0f      /* PBP: layout 0..2 */
#define FRAME_PBP_SOURCE_1        0x10      /* PBP: source of the main picture, 0..3 */
#define FRAME_PBP_SOURCE_2        0x11      /* PBP: source of the second picture, 0..3 */

/* PIP/PBP mode (user_settings.pip_pbp_mode). */
#define PIP_PBP_OFF               0
#define PIP_PBP_PIP               1
#define PIP_PBP_PBP               2

#define SOURCE_MAX                3         /* sources 0..3 as the frame gives them */
#define PIP_SIZE_MAX              2
#define PIP_LOCATION_MAX          4         /* PIP_LOCATION_* 0..4 */
#define PBP_LAYOUT_MAX            2         /* PBP_LAYOUT_0 / _1 / _CUSTOM */

#define OPTIX_SCOPE_ON            1
#define GAMING_FLAG_ADAPTIVE_SYNC 0x80      /* user settings +0xA8 bit 7: Adaptive-Sync */
#define GAMING_FLAG_BIT14         0x4000    /* user settings +0xA8 bit 14: flipped by audio_user_toggle_source */
#define SETTINGS_HDMI_CEC         0x100000  /* user settings +0xAC bit 20: HDMI CEC */
#define APP_STATE_BIT10           0x400     /* app_state_record halfword +0 bit 10 */

#define CHANNEL_MAIN              0         /* channel 0: the main picture */
#define CHANNEL_SECOND            1         /* channel 1: the second picture */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned short app_state_record;         /* halfword +0 of the application state record */

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0x1e];
    unsigned char input_source;                 /* +0x1E: the selected Input Source (menu index) */
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP_PBP_* */
    unsigned char second_source;                /* +0x20: source of the second picture (menu index) */
    unsigned char pad021[0x2f - 0x21];
    unsigned char pbp_layout;                   /* +0x2F: the PBP layout */
    unsigned int byte_0x30 : 8,
                 pip_size : 8,                  /* +0x31 (bits 16..23 of word +0x30) */
                 bits_15_8 : 8,
                 pip_location : 4,              /* bits 4..7 of word +0x30 */
                 second_location : 4;           /* bits 0..3 */
    unsigned char pad034[0x4a - 0x34];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char pad04b[0xa8 - 0x4b];
    unsigned int gaming_flags;                  /* +0xA8: GAMING_FLAG_* */
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
    unsigned char pad0b4[0x1a4 - 0xb4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
};
extern struct user_settings_record user_settings;
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void sys_user_apply_pip_sources(int);
extern void sys_user_reset_display_path(void);
extern void sys_user_apply_second_picture_enable(int);
extern void panel_user_set_output_on(int);
extern void osd_close_menu(void);
extern void audio_mute_outputs(void);
extern void sys_user_apply_adaptive_sync_setting(void);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void input_api_select_ports(int, int);
extern void sys_api_restart_channel_at_level(int, int);
extern void sys_user_clear_second_picture_request(void);
extern void UserSetPIPMode(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void pq_update_input_window(int);
extern void pq_user_reset_response_level(void);
extern void audio_user_update_routing(void);
extern void sys_user_save_mode_slot(void);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern void osd_mark_settings_changed_copy(void);

/* Put the acknowledge "5600+\r" into the reply frame of the port. */
void uart_cmd_build_ok_reply(unsigned char port)
{
    if (port == 2) {
        uart_cmd_tx_frame_port2[0] = '5';
        uart_cmd_tx_frame_port2[1] = '6';
        uart_cmd_tx_frame_port2[2] = '0';
        uart_cmd_tx_frame_port2[3] = '0';
        uart_cmd_tx_frame_port2[4] = '+';
        uart_cmd_tx_frame_port2[5] = '\r';
    } else if (port == 3) {
        uart_cmd_tx_frame_port3[0] = '5';
        uart_cmd_tx_frame_port3[1] = '6';
        uart_cmd_tx_frame_port3[2] = '0';
        uart_cmd_tx_frame_port3[3] = '0';
        uart_cmd_tx_frame_port3[4] = '+';
        uart_cmd_tx_frame_port3[5] = '\r';
    } else {
        uart_cmd_tx_frame[0] = '5';
        uart_cmd_tx_frame[1] = '6';
        uart_cmd_tx_frame[2] = '0';
        uart_cmd_tx_frame[3] = '0';
        uart_cmd_tx_frame[4] = '+';
        uart_cmd_tx_frame[5] = '\r';
    }
}

/* Make the port ready for the next command: clear its receive state byte and bytes 0, 1, 7, 10 and 0x19 of its
   receive record. */
void uart_cmd_clear_rx(unsigned char port)
{
    if (port == 2) {
        uart_cmd_rx_state_port2 = 0;
        uart_cmd_rx_record_port2[0] = 0;
        uart_cmd_rx_record_port2[1] = 0;
        uart_cmd_rx_record_port2[7] = 0;
        uart_cmd_rx_record_port2[10] = 0;
        uart_cmd_rx_record_port2[0x19] = 0;
    } else if (port == 3) {
        uart_cmd_rx_state_port3 = 0;
        uart_cmd_rx_record_port3[0] = 0;
        uart_cmd_rx_record_port3[1] = 0;
        uart_cmd_rx_record_port3[7] = 0;
        uart_cmd_rx_record_port3[10] = 0;
        uart_cmd_rx_record_port3[0x19] = 0;
    } else {
        uart_cmd_rx_count = 0;
        uart_cmd_rx_record[0] = 0;
        uart_cmd_rx_record[1] = 0;
        uart_cmd_rx_record[7] = 0;
        uart_cmd_rx_record[10] = 0;
        uart_cmd_rx_record[0x19] = 0;
    }
}

/* Send the first `length` bytes of the port's reply frame through the 8051. */
void uart_cmd_send_tx_buffer(unsigned char port, unsigned char length)
{
    if (port == 2)
        uart_api_send_bytes(2, length, uart_cmd_tx_frame_port2);
    else if (port == 3)
        uart_api_send_bytes(3, length, uart_cmd_tx_frame_port3);
    else
        uart_api_send_bytes(port, length, uart_cmd_tx_frame);
}

/* Byte `index` of the port's receive record. */
static unsigned char rx_byte(unsigned char port, int index)
{
    if (port == 2)
        return uart_cmd_rx_record_port2[index];
    if (port == 3)
        return uart_cmd_rx_record_port3[index];
    return uart_cmd_rx_record[index];
}

/*
 * Set row 0x8F (143) of uart_cmd_dispatch_set, the 26-byte frame "5b001g": set the PIP/PBP mode together with
 * its sources, PIP size and location or PBP layout from one frame of the PC tool, and apply it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) as soon as one value is out of
 * range; then nothing is replied here and the dispatcher answers "5600-". Values stored before the refused one
 * keep their new values. Unlike the 26-byte picture settings frame, no byte is skipped here: every byte the
 * chosen mode needs is checked and stored.
 *
 * Sources come as numbers 0..3 and are stored as menu indexes (input_api_menu_index_to_source_id).
 *
 * Phases:
 *   1. Mode (frame byte 6, 0..2), stored at once.
 *   2. PIP or PBP: the source of the second picture (byte 8 for PIP, byte 0x11 for PBP), applied to the
 *      picture channels through sys_user_apply_pip_sources(1).
 *   3. PIP: size row (byte 9, stored as 2 - row) and location (byte 0xA).
 *   4. PBP: layout (byte 0xF) and the source of the main picture (byte 0x10); a changed main source restarts the
 *      display path and sets bit 10 of the application state.
 *   5. Switch the picture output off. With PIP or PBP on, switch off what cannot run beside a second picture:
 *      HDMI CEC (with the ports selected again when the input source translates to source 0), Optix Scope,
 *      the blur reduction mode, Screen Size 4..6 (set back to 0, input window of port 0 recomputed) and
 *      Adaptive-Sync (menu closed, sound muted, DSC setting applied again).
 *   6. Restart channels 0 and 1, apply the PIP/PBP mode (UserSetPIPMode), reset the response level, copy the
 *      settings into the picture mode slot, route the sound again when gaming flag bit 14 is set, request a
 *      save and reply "5600+\r".
 */
int uart_cmd_set_pip_pbp_settings(unsigned char port)
{
    unsigned char frame_value, old_source;
    unsigned short value;

    /* Phase 1: the mode. */
    if (port == 2)
        frame_value = uart_cmd_rx_record_port2[FRAME_PIP_PBP_MODE];
    else if (port == 3)
        frame_value = uart_cmd_rx_record_port3[FRAME_PIP_PBP_MODE];
    else
        frame_value = uart_cmd_rx_record[FRAME_PIP_PBP_MODE];
    value = frame_value - VALUE_CHAR_BASE;
    frame_value = value;
    if (frame_value > PIP_PBP_PBP)
        return UART_CMD_REFUSED;
    user_settings.pip_pbp_mode = value;

    /* Phase 2: source of the second picture, from the byte of the chosen mode. */
    if (frame_value != PIP_PBP_OFF) {
        if (frame_value == PIP_PBP_PIP)
            frame_value = rx_byte(port, FRAME_PIP_SOURCE);
        else if (frame_value == PIP_PBP_PBP)
            frame_value = rx_byte(port, FRAME_PBP_SOURCE_2);
        frame_value = frame_value - VALUE_CHAR_BASE;
        if (frame_value > SOURCE_MAX)
            return UART_CMD_REFUSED;
        user_settings.second_source = input_api_menu_index_to_source_id(frame_value);
        sys_user_apply_pip_sources(1);
    }

    /* Phase 3: PIP size and location. */
    if (user_settings.pip_pbp_mode == PIP_PBP_PIP) {
        if (port == 2)
            frame_value = uart_cmd_rx_record_port2[FRAME_PIP_SIZE];
        else if (port == 3)
            frame_value = uart_cmd_rx_record_port3[FRAME_PIP_SIZE];
        else
            frame_value = uart_cmd_rx_record[FRAME_PIP_SIZE];
        value = frame_value - VALUE_CHAR_BASE;
        if ((unsigned char)value > PIP_SIZE_MAX)
            return UART_CMD_REFUSED;
        user_settings.pip_size = PIP_SIZE_MAX - value;
        if (port == 2)
            frame_value = uart_cmd_rx_record_port2[FRAME_PIP_LOCATION];
        else if (port == 3)
            frame_value = uart_cmd_rx_record_port3[FRAME_PIP_LOCATION];
        else
            frame_value = uart_cmd_rx_record[FRAME_PIP_LOCATION];
        value = frame_value - VALUE_CHAR_BASE;
        if ((unsigned char)value > PIP_LOCATION_MAX)
            return UART_CMD_REFUSED;
        user_settings.pip_location = (unsigned char)value;
    }

    /* Phase 4: PBP layout and the source of the main picture. */
    if (user_settings.pip_pbp_mode == PIP_PBP_PBP) {
        if (port == 2)
            frame_value = uart_cmd_rx_record_port2[FRAME_PBP_LAYOUT];
        else if (port == 3)
            frame_value = uart_cmd_rx_record_port3[FRAME_PBP_LAYOUT];
        else
            frame_value = uart_cmd_rx_record[FRAME_PBP_LAYOUT];
        value = frame_value - VALUE_CHAR_BASE;
        if ((unsigned char)value > PBP_LAYOUT_MAX)
            return UART_CMD_REFUSED;
        user_settings.pbp_layout = value;
        if (port == 2)
            frame_value = uart_cmd_rx_record_port2[FRAME_PBP_SOURCE_1];
        else if (port == 3)
            frame_value = uart_cmd_rx_record_port3[FRAME_PBP_SOURCE_1];
        else
            frame_value = uart_cmd_rx_record[FRAME_PBP_SOURCE_1];
        value = frame_value - VALUE_CHAR_BASE;
        if ((unsigned char)value > SOURCE_MAX)
            return UART_CMD_REFUSED;
        old_source = user_settings.input_source;
        user_settings.input_source = input_api_menu_index_to_source_id((unsigned char)value);
        if (user_settings.input_source != old_source) {
            sys_user_reset_display_path();
            app_state_record |= APP_STATE_BIT10;
        }
    }

    /* Phase 5: output off; with a second picture, the settings that cannot run beside it are switched off. */
    panel_user_set_output_on(0);
    if (user_settings.pip_pbp_mode != PIP_PBP_OFF) {
        if (user_settings.settings_page_flags & SETTINGS_HDMI_CEC) {
            user_settings.settings_page_flags &= ~SETTINGS_HDMI_CEC;
            if (input_api_source_id_to_menu_index(user_settings.input_source) == 0)
                input_api_select_ports(1, 1);
        }
        if (user_settings.optix_scope == OPTIX_SCOPE_ON) {
            user_settings.optix_scope = 0;
            sys_user_apply_second_picture_enable(0);
        }
        if (user_settings.blur_free_mode != 0) {
            user_settings.blur_free_mode = 0;
            sys_user_clear_second_picture_request();
        }
        if (sys_is_mode_4_to_6() == 1) {
            user_settings.screen_size = 0;
            pq_update_input_window(0);
        }
        if (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC) {
            osd_close_menu();
            user_settings.gaming_flags &= ~GAMING_FLAG_ADAPTIVE_SYNC;
            audio_mute_outputs();
            sys_user_apply_adaptive_sync_setting();
        }
    }

    /* Phase 6. */
    sys_api_restart_channel_at_level(CHANNEL_MAIN, 1);
    sys_api_restart_channel_at_level(CHANNEL_SECOND, 1);
    UserSetPIPMode();
    pq_user_reset_response_level();
    sys_user_save_mode_slot();
    if (user_settings.gaming_flags & GAMING_FLAG_BIT14)
        audio_user_update_routing();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
