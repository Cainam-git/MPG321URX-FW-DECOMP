/* uart_cmd_set_pip_pbp_mode  (FUN_a00c7a5c)
 *
 * Set the PIP/PBP mode from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00600; digit 0..2 (off, PIP, PBP), switching off conflicting modes; returns 0xFF for a bad
 *   value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00600; settings byte +0x1F (osd_enter_pip_pbp_items)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c7a5c @ 0xa00c7a5c-0xa00c7e3c (248 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the frame byte is read into an unsigned char and the value computed into an unsigned short, tested as an
 *    unsigned char;
 *  - the settings words +0xA8 / +0xAC / +0xB0 are plain unsigned int members cleared with &= ~mask.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': a value byte of the frame is the value plus 0x30 */
#define VALUE_CHAR_OFFSET         9         /* frame byte 9: the one-digit value of the command */

/* PIP/PBP mode (user_settings.pip_pbp_mode). */
#define PIP_PBP_OFF               0
#define PIP_PBP_PIP               1
#define PIP_PBP_PBP               2

#define OPTIX_SCOPE_ON            1
#define SCREEN_SIZE_16_10         3         /* Screen Size menu list index */

#define GAMING_FLAG_ADAPTIVE_SYNC 0x80      /* user settings +0xA8 bit 7: Adaptive-Sync */
#define GAMING_FLAG_BIT13         0x2000    /* user settings +0xA8 bit 13 */
#define GAMING_FLAG_BIT14         0x4000    /* user settings +0xA8 bit 14: flipped by audio_user_toggle_source */
#define SETTINGS_HDMI_CEC         0x100000  /* user settings +0xAC bit 20: HDMI CEC */

#define CHANNEL_MAIN              0         /* channel 0: the main picture */
#define CHANNEL_SECOND            1         /* channel 1: the second picture */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0x19];
    unsigned char response_time;                /* +0x19: the response time level */
    unsigned char pad01a[0x1e - 0x1a];
    unsigned char input_source;                 /* +0x1E: the selected Input Source */
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP_PBP_* */
    unsigned char pad020[0x4a - 0x20];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char pad04b[0xa8 - 0x4b];
    unsigned int gaming_flags;                  /* +0xA8: GAMING_FLAG_* */
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
    unsigned char pad0b4[0x1a4 - 0xb4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
};
extern struct user_settings_record user_settings;
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

/*
 * Set row 8 of uart_cmd_dispatch_set ("00600"): set the PIP/PBP mode from one frame of the PC tool, switch off
 * the settings that cannot run beside a second picture, and apply the mode.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value above 2 (frame byte 9
 * minus 0x30); then nothing is stored and the dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read and check the mode, store it.
 *   2. Switch Optix Scope off when it is on, and switch the picture output off.
 *   3. With PIP or PBP chosen, switch off: Adaptive-Sync (menu closed, sound muted, DSC setting applied again),
 *      HDMI CEC (when the input source translates to source id 0, the output is switched off, the ports
 *      selected again and channels 0 and 1 restarted), the blur reduction mode, and Screen Size 16:10.
 *   4. Clear the response time and apply the PIP/PBP mode (UserSetPIPMode).
 *   5. With PIP or PBP chosen: clear gaming flag bit 13 and the blur reduction mode; Screen Size 4..6, and with
 *      PBP any Screen Size, goes back to 0 and the input window of port 0 is recomputed.
 *   6. Reset the response level, route the sound again when gaming flag bit 14 is set, copy the settings into
 *      the picture mode slot, request a save and reply "5600+\r".
 */
int uart_cmd_set_pip_pbp_mode(unsigned char port)
{
    unsigned char value_char;
    unsigned short mode;

    /* Phase 1. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        value_char = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    mode = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)mode > PIP_PBP_PBP)
        return UART_CMD_REFUSED;
    user_settings.pip_pbp_mode = mode;

    /* Phase 2. */
    if (user_settings.optix_scope == OPTIX_SCOPE_ON) {
        user_settings.optix_scope = 0;
        sys_user_apply_second_picture_enable(0);
    }
    panel_user_set_output_on(0);

    /* Phase 3: settings that are switched off when a second picture is chosen. */
    if ((user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC) && user_settings.pip_pbp_mode != PIP_PBP_OFF) {
        osd_close_menu();
        user_settings.gaming_flags &= ~GAMING_FLAG_ADAPTIVE_SYNC;
        audio_mute_outputs();
        sys_user_apply_adaptive_sync_setting();
    }
    if ((user_settings.settings_page_flags & SETTINGS_HDMI_CEC) && user_settings.pip_pbp_mode != PIP_PBP_OFF) {
        user_settings.settings_page_flags &= ~SETTINGS_HDMI_CEC;
        if (input_api_source_id_to_menu_index(user_settings.input_source) == 0) {
            panel_user_set_output_on(0);
            input_api_select_ports(1, 1);
            sys_api_restart_channel_at_level(CHANNEL_MAIN, 1);
            sys_api_restart_channel_at_level(CHANNEL_SECOND, 1);
        }
    }
    if (user_settings.blur_free_mode != 0 && user_settings.pip_pbp_mode != PIP_PBP_OFF) {
        user_settings.blur_free_mode = 0;
        sys_user_clear_second_picture_request();
    }
    if (user_settings.screen_size == SCREEN_SIZE_16_10 && user_settings.pip_pbp_mode != PIP_PBP_OFF)
        user_settings.screen_size = 0;

    /* Phase 4. */
    user_settings.response_time = 0;
    UserSetPIPMode();

    /* Phase 5. */
    if (user_settings.pip_pbp_mode != PIP_PBP_OFF) {
        user_settings.gaming_flags &= ~GAMING_FLAG_BIT13;
        user_settings.blur_free_mode = 0;
        if (sys_is_mode_4_to_6() == 1) {
            user_settings.screen_size = 0;
            pq_update_input_window(0);
        }
        if (user_settings.pip_pbp_mode == PIP_PBP_PBP) {
            user_settings.screen_size = 0;
            pq_update_input_window(0);
        }
    }

    /* Phase 6. */
    pq_user_reset_response_level();
    if (user_settings.gaming_flags & GAMING_FLAG_BIT14)
        audio_user_update_routing();
    sys_user_save_mode_slot();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
