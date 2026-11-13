/* uart_cmd_set_optix_scope  (FUN_a00c46d4)
 *
 * Set the Optix Scope switch from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b002A0; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b002A0; settings byte +0x4A (osd_enter_optix_scope_choices); switches off
 *   conflicting modes first
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c46d4 @ 0xa00c46d4-0xa00c49b8 (185 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file and inlined by GCC at -O3; the value byte is read with the
 *    port test written out in the routine;
 *  - value is an unsigned short, cast to a byte for the range test, the store and the '== 1' test;
 *  - the settings fields are members of one structure; Adaptive-Sync (bit 7 of +0xA8) is a 1-bit bit-field
 *    declared directly in it;
 *  - sys_user_apply_second_picture_enable(0) is written in both arms of the '== 1' test (one common call gives a
 *    different block layout).
 */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define SWITCH_MAX                1         /* 0 = OFF, 1 = ON */
#define SWITCH_ON                 1
#define BLUR_FREE_MODE_OFF        0
#define PIP_PBP_OFF               0
#define SCREEN_SIZE_INPUT_ASPECT  0         /* Screen Size "Auto" */
#define PANEL_OFF                 0         /* panel_user_set_output_on: switch the panel off */
#define RESTART_LEVEL_1           1         /* level passed to sys_api_restart_channel_at_level */

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record { unsigned char pad000[0x1f];
                              unsigned char pip_pbp_mode;               /* +0x1F: 0 = off */
                              unsigned char pad020[0x4a - 0x20];
                              unsigned char optix_scope;                /* +0x4A: the Optix Scope switch */
                              unsigned char pad04b[0xa8 - 0x4b];
                              unsigned int gaming_bits_8_31 : 24,       /* +0xA8: gaming_flags */
                                           adaptive_sync : 1,           /*   bit 7: Adaptive-Sync */
                                           gaming_bits_0_6 : 7;
                              unsigned int settings_page_flags;         /* +0xAC */
                              unsigned int blur_free_mode;              /* +0xB0: the blur reduction mode */
                              unsigned char pad0b4[0x1a4 - 0xb4];
                              unsigned char screen_size; };             /* +0x1A4: the Screen Size (menu list
                                                                           index) */
extern struct user_settings_record user_settings;
extern void osd_close_menu(void);
extern void audio_mute_outputs(void);
extern void panel_user_set_output_on(int);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void UserSetPIPMode(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void pq_update_input_window(int);
extern void sys_user_apply_second_picture_enable(int);
extern void sys_user_save_mode_slot(void);
extern void sys_user_clear_second_picture_request(void);
extern void sys_api_restart_channel_at_level(int, int);
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
 * Set row 0x36 (54, row id 002A0) of uart_cmd_dispatch_set: switch Optix Scope off or on from a frame of the PC
 * tool. Switching it on first switches off the settings that do not go with it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed for a value
 * above 1; then the dispatcher answers "5600-".
 *
 * Frame byte read: 9, the switch value plus 0x30.
 *
 * Phases:
 *   1. Read and check the value, store it in optix_scope.
 *   2. Only for ON, in this order:
 *        - blur reduction on: set to 0, then sys_user_save_mode_slot and sys_user_clear_second_picture_request;
 *        - Screen Size 4..6 (sys_is_mode_4_to_6): panel off, Screen Size back to 0 ("Auto"), channels 0 and 1
 *          restarted at level 1, UserSetPIPMode, pq_update_input_window(0);
 *        - PIP/PBP on: PIP/PBP off, close the menu, mute the sound, panel off, UserSetPIPMode;
 *        - Adaptive-Sync on: switched off, close the menu, mute the sound, panel off, sys_user_apply_adaptive_sync_setting
 *          (the routine the Adaptive-Sync command runs after a change).
 *   3. For both values: sys_user_apply_second_picture_enable(0).
 *   4. Reply "5600+\r", clear the port's receive record, send the reply. No save request is made here.
 */
int uart_cmd_set_optix_scope(unsigned char port)
{
    unsigned char value_char;
    unsigned short value;

    /* Phase 1. */

    if (port == 2)
        value_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[9];
    else
        value_char = uart_cmd_rx_record[9];
    value = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)value > SWITCH_MAX)
        return UART_CMD_REFUSED;
    user_settings.optix_scope = value;
    if ((unsigned char)value == SWITCH_ON) {
        /* Phase 2: Optix Scope on ends blur reduction, Screen Size 4..6, PIP/PBP and Adaptive-Sync. */
        if (user_settings.blur_free_mode != BLUR_FREE_MODE_OFF) {
            user_settings.blur_free_mode = BLUR_FREE_MODE_OFF;
            sys_user_save_mode_slot();
            sys_user_clear_second_picture_request();
        }
        if (sys_is_mode_4_to_6() == 1) {
            panel_user_set_output_on(PANEL_OFF);
            user_settings.screen_size = SCREEN_SIZE_INPUT_ASPECT;
            sys_api_restart_channel_at_level(0, RESTART_LEVEL_1);
            sys_api_restart_channel_at_level(1, RESTART_LEVEL_1);
            UserSetPIPMode();
            pq_update_input_window(0);
        }
        if (user_settings.pip_pbp_mode != PIP_PBP_OFF) {
            user_settings.pip_pbp_mode = PIP_PBP_OFF;
            osd_close_menu();
            audio_mute_outputs();
            panel_user_set_output_on(PANEL_OFF);
            UserSetPIPMode();
        }
        if (user_settings.adaptive_sync) {
            user_settings.adaptive_sync = 0;
            osd_close_menu();
            audio_mute_outputs();
            panel_user_set_output_on(PANEL_OFF);
            sys_user_apply_adaptive_sync_setting();
        }
        /* Phase 3. */
        sys_user_apply_second_picture_enable(0);
    } else {
        sys_user_apply_second_picture_enable(0);
    }
    /* Phase 4. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
