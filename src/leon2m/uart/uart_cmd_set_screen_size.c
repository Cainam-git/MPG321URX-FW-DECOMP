/* uart_cmd_set_screen_size  (FUN_a00c4ec4)
 *
 * Set the Screen Size from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b002:0; digit 0..8 mapped to the screen size byte; returns 0xFF for a bad value (the task
 *   then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b002:0; settings byte +0x1A4 (osd_draw_screen_size_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c4ec4 @ 0xa00c4ec4-0xa00c5478 (1460 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the first three refusal tests are one '||' condition (a shared return block, so if-conversion does not move
 *    the return value set above the tests);
 *  - the two size compares are written 'input_size == panel_size' / 'input_size >= panel_size' with
 *    input_size the input_api_get_timing_field result, both unsigned short;
 *  - the stored size is set by an if/else-if chain after the 1:1 / 16:10 tests.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */

/* Screen Size values as stored in user_settings.screen_size: the index in the menu list
   (texts Auto, 4:3, 16:9, 16:10, 1:1, 24.5", 27"). */
enum {
    SCREEN_SIZE_INPUT_ASPECT = 0,           /* "Auto" */
    SCREEN_SIZE_4_3          = 1,
    SCREEN_SIZE_16_9         = 2,
    SCREEN_SIZE_16_10        = 3,
    SCREEN_SIZE_1_1          = 4,           /* 4, 5 and 6 are the sizes sys_is_mode_4_to_6 reports */
    SCREEN_SIZE_24_5         = 5,           /* 24.5" */
    SCREEN_SIZE_27           = 6            /* 27" */
};

/* The PC tool numbers the sizes 0..8 in an order of its own (see the chain in the routine); 4 and 6 are
   refused. */
#define TOOL_SIZE_MAX             8
#define TOOL_SIZE_1_1             3
#define TOOL_SIZE_16_10           5

#define PIP_PBP_OFF               0         /* user_settings.pip_pbp_mode */
#define PIP_PBP_PIP               1
#define PIP_PBP_PBP               2

#define MAIN_CHANNEL              0
#define TIMING_WIDTH              7         /* input_api_get_timing_field: width of the input picture */
#define TIMING_HEIGHT             8         /* input_api_get_timing_field: height of the input picture */
#define PANEL_SIZE_WIDTH          0         /* panel_api_get_active_size */
#define PANEL_SIZE_LINES          1
#define CHANNEL_CODE_LAST         10        /* a state code of sys_api_get_channel_state_code */

#define EDID_PORTS_ALL            2         /* UserSwitchEDID: load all four inputs */
#define RESTART_LEVEL_1           1         /* sys_api_restart_channel_at_level */
#define CHANNEL_ALL               4         /* sys_api_set_channel_timeout: all four channels */
#define DISPLAY_DELAY_TICKS       1000
#define RESTART_WAIT_TICKS        0x32
#define PIP_MODE_0                0         /* SYSAPI_ConfigSystemPIPMode arguments */
#define PIP_MODE_2                2

#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit of osd_request_bits */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char osd_request_bits;
extern unsigned char osd_choice_row;

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP/PBP mode (0 off, 1 PIP, 2 PBP) */
    unsigned char pad020[0x4a - 0x20];
    unsigned char optix_scope;                  /* +0x4A: the Optix Scope switch */
    unsigned char pad04b[0xa8 - 0x4b];
    unsigned int gaming_flags_high : 24,        /* +0xA8: gaming flags */
                 adaptive_sync : 1,             /*        bit 7: Adaptive-Sync */
                 gaming_flags_low : 7;
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
    unsigned char pad0b4[0x1a4 - 0xb4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size */
    unsigned char pad1a5[0x1f4 - 0x1a5];
    int word_0x1f4;                             /* +0x1F4: bit 31 (negative) = the DSC switch */
};
extern struct user_settings_record user_settings;
extern unsigned short input_api_get_timing_field(unsigned char, unsigned int);
extern unsigned short panel_api_get_active_size(unsigned char);
extern unsigned char sys_api_get_channel_state_code(unsigned char);
extern void osd_close_menu(void);
extern void audio_mute_outputs(void);
extern void panel_user_set_output_on(int);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void UserSetPIPMode(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void sys_user_apply_second_picture_enable(int);
extern void sys_user_save_mode_slot(void);
extern void sys_user_clear_second_picture_request(void);
extern void sys_api_restart_channel_at_level(int, int);
extern void UserSwitchEDID(unsigned char, unsigned char);
extern void sys_api_set_channel_timeout(unsigned char, unsigned int, unsigned short);
extern void timer_api_sleep_ticks(unsigned short);
extern void SYSAPI_ConfigSystemPIPMode(unsigned int);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

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
 * Set row 0x3B (59) of uart_cmd_dispatch_set: set the Screen Size from a frame of MSI's PC tool and apply it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF); then nothing has changed and the
 * dispatcher answers "5600-".
 *
 * The value is frame byte 9 (value plus 0x30). Tool values and the sizes they give:
 *   0 Auto, 1 4:3, 2 16:9, 3 1:1, 5 16:10, 7 24.5", 8 27"; 4, 6 and anything above 8 are refused.
 *
 * Phases:
 *   1. Refusals: a bad value; PBP on; 1:1 while PIP is on; 1:1 when the input on channel 0 is as wide as the
 *      panel and at least as high, while that channel's state code is 10; 16:10 while the DSC switch is on.
 *   2. Store the size and switch the panel off (panel_user_set_output_on(0)).
 *   3. Switch off what does not go with the new size. For 1:1, 24.5" and 27" (sys_is_mode_4_to_6): Optix Scope,
 *      blur reduction, PIP/PBP and Adaptive-Sync. For 16:10: PIP/PBP and Adaptive-Sync. Switching Adaptive-Sync
 *      off closes the menu, mutes the sound, switches the panel off again and applies the DSC setting.
 *   4. Restart the picture. When the new or the old size is 16:10: load the EDIDs again, restart channels 0 and 1
 *      and set the display delay of all four channels to 1000. Otherwise: wait 0x32 ticks, restart channel 0, and
 *      set the PIP mode by osd_choice_row and the new size (as in osd_apply_screen_size, where osd_choice_row
 *      holds the size from before the change; this routine does not set it).
 *   5. Save the picture settings into the mode slot, raise OSD_REQUEST_SETTINGS_CHANGED, reply "5600+\r".
 */
int uart_cmd_set_screen_size(unsigned char port)
{
    unsigned char value_char, old_size, size, tool_value;
    unsigned short value;

    /* Phase 1: read and check the value. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[9];
    else
        value_char = uart_cmd_rx_record[9];
    value = value_char - VALUE_CHAR_BASE;
    tool_value = value;
    old_size = user_settings.screen_size;
    if (tool_value > TOOL_SIZE_MAX || user_settings.pip_pbp_mode == PIP_PBP_PBP ||
        (tool_value == TOOL_SIZE_1_1 && user_settings.pip_pbp_mode == PIP_PBP_PIP))
        return UART_CMD_REFUSED;
    if (tool_value == TOOL_SIZE_1_1) {
        unsigned short input_size, panel_size;

        /* 1:1 is refused for an input that already fills the panel width and height while channel 0 is in
           state code 10. */
        input_size = input_api_get_timing_field(MAIN_CHANNEL, TIMING_WIDTH);
        panel_size = panel_api_get_active_size(PANEL_SIZE_WIDTH);
        if (input_size == panel_size) {
            input_size = input_api_get_timing_field(MAIN_CHANNEL, TIMING_HEIGHT);
            panel_size = panel_api_get_active_size(PANEL_SIZE_LINES);
            if (input_size >= panel_size) {
                if (sys_api_get_channel_state_code(MAIN_CHANNEL) == CHANNEL_CODE_LAST)
                    return UART_CMD_REFUSED;
            }
        }
    } else if (tool_value == TOOL_SIZE_16_10) {
        /* 16:10 is refused while the DSC switch is on. */
        if (user_settings.word_0x1f4 < 0)
            return UART_CMD_REFUSED;
    }
    /* The tool's numbering to the stored Screen Size. */
    if (tool_value == 0)
        size = SCREEN_SIZE_INPUT_ASPECT;
    else if (tool_value == 1)
        size = SCREEN_SIZE_4_3;
    else if (tool_value == 2)
        size = SCREEN_SIZE_16_9;
    else if (tool_value == TOOL_SIZE_1_1)
        size = SCREEN_SIZE_1_1;
    else if (tool_value == TOOL_SIZE_16_10)
        size = SCREEN_SIZE_16_10;
    else if (tool_value == 7)
        size = SCREEN_SIZE_24_5;
    else if (tool_value == 8)
        size = SCREEN_SIZE_27;
    else
        return UART_CMD_REFUSED;

    /* Phase 2. */
    user_settings.screen_size = size;
    panel_user_set_output_on(0);

    /* Phase 3: features that do not go with the new size. sys_is_mode_4_to_6 reads the size stored above. */
    if (user_settings.optix_scope == 1 && sys_is_mode_4_to_6() == 1) {
        user_settings.optix_scope = 0;
        sys_user_apply_second_picture_enable(0);
    }
    if (sys_is_mode_4_to_6() == 1 && user_settings.blur_free_mode != 0) {
        user_settings.blur_free_mode = 0;
        sys_user_clear_second_picture_request();
    }
    if (sys_is_mode_4_to_6() == 1 && user_settings.pip_pbp_mode != PIP_PBP_OFF) {
        user_settings.pip_pbp_mode = PIP_PBP_OFF;
        UserSetPIPMode();
    }
    if (user_settings.screen_size == SCREEN_SIZE_16_10 && user_settings.pip_pbp_mode != PIP_PBP_OFF) {
        user_settings.pip_pbp_mode = PIP_PBP_OFF;
        UserSetPIPMode();
    }
    if (sys_is_mode_4_to_6() == 1 && user_settings.adaptive_sync) {
        osd_close_menu();
        user_settings.adaptive_sync = 0;
        audio_mute_outputs();
        panel_user_set_output_on(0);
        sys_user_apply_adaptive_sync_setting();
    }
    if (user_settings.screen_size == SCREEN_SIZE_16_10 && user_settings.adaptive_sync) {
        osd_close_menu();
        user_settings.adaptive_sync = 0;
        audio_mute_outputs();
        panel_user_set_output_on(0);
        sys_user_apply_adaptive_sync_setting();
    }

    /* Phase 4: restart the picture. */
    if (user_settings.screen_size == SCREEN_SIZE_16_10 || old_size == SCREEN_SIZE_16_10) {
        /* 16:10 has an EDID variant of its own: load the EDIDs again when it is entered or left. */
        UserSwitchEDID(EDID_PORTS_ALL, 0);
        sys_api_restart_channel_at_level(0, RESTART_LEVEL_1);
        sys_api_restart_channel_at_level(1, RESTART_LEVEL_1);
        sys_api_set_channel_timeout(CHANNEL_ALL, 1, DISPLAY_DELAY_TICKS);
    } else {
        timer_api_sleep_ticks(RESTART_WAIT_TICKS);
        sys_api_restart_channel_at_level(0, RESTART_LEVEL_1);
        if (osd_choice_row == SCREEN_SIZE_24_5) {
            sys_api_restart_channel_at_level(1, RESTART_LEVEL_1);
            if (sys_is_mode_4_to_6() == 0)
                SYSAPI_ConfigSystemPIPMode(PIP_MODE_2);
        }
        if (osd_choice_row == SCREEN_SIZE_27) {
            sys_api_restart_channel_at_level(1, RESTART_LEVEL_1);
            if (sys_is_mode_4_to_6() == 0)
                SYSAPI_ConfigSystemPIPMode(PIP_MODE_2);
        }
        if (osd_choice_row == SCREEN_SIZE_1_1) {
            if (sys_is_mode_4_to_6() == 0)
                SYSAPI_ConfigSystemPIPMode(PIP_MODE_2);
        }
        if (sys_is_mode_4_to_6() == 1)
            SYSAPI_ConfigSystemPIPMode(PIP_MODE_0);
    }

    /* Phase 5. */
    sys_user_save_mode_slot();
    osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
