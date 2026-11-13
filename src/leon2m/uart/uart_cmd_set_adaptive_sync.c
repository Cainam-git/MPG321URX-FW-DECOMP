/* uart_cmd_set_adaptive_sync  (FUN_a00c4430)
 *
 * Set the Adaptive-Sync switch from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00280; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: derived - set frame 5b00280; bit 7 of +0xA8 = switch row 5 of the Gaming page
 *   (osd_draw_gaming_item_state); switches off conflicting PIP/PBP and screen size modes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c4430 @ 0xa00c4430-0xa00c46d4 (169 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file and inlined by GCC at -O3; the value byte is read with the
 *    port test written out in the routine;
 *  - the value goes through an unsigned short and then a byte (value) before the test;
 *  - gaming_flags is a union of the plain word and a bit-field view: the compare and the store use the 1-bit
 *    field, the later test the word mask (no common load);
 *  - 'osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED' is written in both arms of that test.
 */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

#define UART_CMD_REFUSED              0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH      6         /* "5600+\r" */
#define VALUE_CHAR_BASE               0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define SWITCH_MAX                    1         /* 0 = OFF, 1 = ON */
#define GAMING_FLAG_ADAPTIVE_SYNC     0x80      /* user settings +0xA8 bit 7: Adaptive-Sync */
#define PIP_PBP_OFF                   0
#define SCREEN_SIZE_INPUT_ASPECT      0         /* Screen Size "Auto" */
#define PANEL_OFF                     0         /* panel_user_set_output_on: switch the panel off */
#define OSD_REQUEST_SETTINGS_CHANGED  0x02      /* osd_request_bits bit 1 */

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record { unsigned char pad000[0x1f];
                              unsigned char pip_pbp_mode;               /* +0x1F: 0 = off */
                              unsigned char pad020[0x4a - 0x20];
                              unsigned char optix_scope;                /* +0x4A: the Optix Scope switch */
                              unsigned char pad04b[0xa8 - 0x4b];
                              union { unsigned int word;                /* +0xA8: GAMING_FLAG_* switches */
                                      struct { unsigned int bits_8_31 : 24,
                                                            adaptive_sync : 1,      /* bit 7 */
                                                            bits_0_6 : 7; } bits; } gaming_flags;
                              unsigned char pad0ac[0x1a4 - 0xac];
                              unsigned char screen_size; };             /* +0x1A4: the Screen Size (menu list
                                                                           index) */
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void osd_close_menu(void);
extern void audio_mute_outputs(void);
extern void panel_user_set_output_on(int);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void UserSetPIPMode(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void pq_update_input_window(int);
extern void sys_user_apply_second_picture_enable(int);
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
 * Set row 0x39 (57, row id 00280) of uart_cmd_dispatch_set: switch Adaptive-Sync (gaming_flags bit 7, switch row
 * 5 of the Gaming page) off or on from a frame of the PC tool, and switch off what does not go with it.
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
 *   1. Read and check the value.
 *   2. Only when the switch changes: store it, close the menu, mute the sound (audio_mute_outputs), switch the
 *      panel off and run sys_user_apply_adaptive_sync_setting. That routine loads the EDID again, restarts channels 0 and 1
 *      and passes gaming_flags bit 7 (this switch) to dp_api_set_dsc_support for sources 0xC and 0xD.
 *   3. With Adaptive-Sync on (changed or not):
 *        - PIP/PBP on: PIP/PBP off, close the menu, mute the sound, panel off, UserSetPIPMode;
 *        - Screen Size 4..6 (sys_is_mode_4_to_6): Screen Size back to 0 ("Auto"), pq_update_input_window(0);
 *        - Optix Scope off, applied through sys_user_apply_second_picture_enable.
 *   4. Set the settings-changed request bit for the main loop (in both cases), reply "5600+\r", clear the port's
 *      receive record, send the reply.
 */
int uart_cmd_set_adaptive_sync(unsigned char port)
{
    unsigned char value_char;
    unsigned short value_word;
    unsigned char value;

    /* Phase 1. */

    if (port == 2)
        value_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[9];
    else
        value_char = uart_cmd_rx_record[9];
    value_word = value_char - VALUE_CHAR_BASE;
    value = value_word;
    if (value > SWITCH_MAX)
        return UART_CMD_REFUSED;
    /* Phase 2: a new switch value. */
    if (value != user_settings.gaming_flags.bits.adaptive_sync) {
        user_settings.gaming_flags.bits.adaptive_sync = value;
        osd_close_menu();
        audio_mute_outputs();
        panel_user_set_output_on(PANEL_OFF);
        sys_user_apply_adaptive_sync_setting();
    }
    /* Phase 3: Adaptive-Sync on ends PIP/PBP, Screen Size 4..6 and Optix Scope. */
    if (user_settings.gaming_flags.word & GAMING_FLAG_ADAPTIVE_SYNC) {
        if (user_settings.pip_pbp_mode != PIP_PBP_OFF) {
            user_settings.pip_pbp_mode = PIP_PBP_OFF;
            osd_close_menu();
            audio_mute_outputs();
            panel_user_set_output_on(PANEL_OFF);
            UserSetPIPMode();
        }
        if (sys_is_mode_4_to_6() == 1) {
            user_settings.screen_size = SCREEN_SIZE_INPUT_ASPECT;
            pq_update_input_window(0);
        }
        user_settings.optix_scope = 0;
        sys_user_apply_second_picture_enable(0);
        /* Phase 4. */
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    } else {
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    }
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
