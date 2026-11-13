/* uart_cmd_set_blur_free  (FUN_a00c4144)
 *
 * Set the blur reduction mode from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00230; digit 0..2, switches off Optix Scope and PIP/PBP when they conflict; returns 0xFF for
 *   a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: derived - set frame 5b00230; settings word +0xB0, kept by APPBlurFree_AfterMute
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c4144 @ 0xa00c4144-0xa00c4430 (187 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file and inlined by GCC at -O3; the value byte is read with the
 *    port test written out in the routine;
 *  - the value goes through an unsigned short and then a byte (mode) before the test;
 *  - the two early refusals are one || condition;
 *  - the automatic level switch (bit 31 of +0x11C) is a 1-bit bit-field declared directly in the settings
 *    structure.
 */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define BLUR_FREE_MODE_MAX        2         /* largest blur reduction mode this command accepts (0 = off) */
#define PIP_PBP_OFF               0
#define SCREEN_SIZE_INPUT_ASPECT  0         /* Screen Size "Auto" */
#define PANEL_OFF                 0         /* panel_user_set_output_on: switch the panel off */
#define RESTART_LEVEL_1           1         /* level passed to sys_api_restart_channel_at_level */

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record { unsigned char pad000[0x1f];
                              unsigned char pip_pbp_mode;               /* +0x1F: 0 = off */
                              unsigned char pad020[0x4a - 0x20];
                              unsigned char optix_scope;                /* +0x4A: the Optix Scope switch */
                              unsigned char pad04b[0xb0 - 0x4b];
                              unsigned int blur_free_mode;              /* +0xB0: the blur reduction mode */
                              unsigned char pad0b4[0x11c - 0xb4];
                              unsigned int auto_level : 1,              /* +0x11C bit 31 (professional flags):
                                                                           automatic level */
                                           professional_rest : 31;
                              unsigned char pad120[0x1a4 - 0x120];
                              unsigned char screen_size; };             /* +0x1A4: the Screen Size (menu list
                                                                           index) */
extern struct user_settings_record user_settings;
extern unsigned char input_user_has_rate_mode(void);
extern void sys_user_apply_second_picture_enable(int);
extern void sys_user_apply_auto_level(void);
extern void sys_user_clear_second_picture_request(void);
extern void sys_user_save_mode_slot(void);
extern void panel_user_set_output_on(int);
extern void sys_api_restart_channel_at_level(int, int);
extern void UserSetPIPMode(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void pq_update_input_window(int);
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
 * Set row 0x2F (47, row id 00230) of uart_cmd_dispatch_set: set the blur reduction mode (0 = off) from a frame of
 * the PC tool and switch off what does not go with it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed; then the
 * dispatcher answers "5600-". Refused: a mode above 2, or input_user_has_rate_mode() giving 0
 * (pq_select_rate_mode gives 0 for the refresh rate of channel 0 in whole hertz).
 *
 * Frame byte read: 9, the mode plus 0x30.
 *
 * Phases:
 *   1. Read and check the mode.
 *   2. Only when the mode changes: store it; switch Optix Scope off (and apply that through
 *      sys_user_apply_second_picture_enable); with a mode other than 0, switch the automatic level off (and apply
 *      it); then sys_user_clear_second_picture_request.
 *   3. Always: sys_user_save_mode_slot.
 *   4. With a mode other than 0 and PIP/PBP on: PIP/PBP off, panel off, channels 0 and 1 restarted at level 1,
 *      UserSetPIPMode.
 *   5. With a mode other than 0 and a Screen Size of 4..6 (sys_is_mode_4_to_6): panel off, Screen Size back to
 *      0 ("Auto"), pq_update_input_window(0).
 *   6. Save request (osd_mark_settings_changed_copy), reply "5600+\r", clear the port's receive record, send the
 *      reply.
 */
int uart_cmd_set_blur_free(unsigned char port)
{
    unsigned char value_char;
    unsigned short value;
    unsigned char mode;

    /* Phase 1. */

    if (port == 2)
        value_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[9];
    else
        value_char = uart_cmd_rx_record[9];
    value = value_char - VALUE_CHAR_BASE;
    mode = value;
    if (mode > BLUR_FREE_MODE_MAX || input_user_has_rate_mode() == 0)
        return UART_CMD_REFUSED;
    /* Phase 2: a new mode. */
    if (user_settings.blur_free_mode != mode) {
        user_settings.blur_free_mode = mode;
        if (user_settings.optix_scope != 0) {
            user_settings.optix_scope = 0;
            sys_user_apply_second_picture_enable(0);
        }
        if (user_settings.auto_level && user_settings.blur_free_mode != 0) {
            user_settings.auto_level = 0;
            sys_user_apply_auto_level();
        }
        sys_user_clear_second_picture_request();
    }
    /* Phase 3. */
    sys_user_save_mode_slot();
    /* Phase 4: blur reduction on ends PIP/PBP. */
    if (user_settings.pip_pbp_mode != PIP_PBP_OFF && user_settings.blur_free_mode != 0) {
        user_settings.pip_pbp_mode = PIP_PBP_OFF;
        panel_user_set_output_on(PANEL_OFF);
        sys_api_restart_channel_at_level(0, RESTART_LEVEL_1);
        sys_api_restart_channel_at_level(1, RESTART_LEVEL_1);
        UserSetPIPMode();
    }
    /* Phase 5: blur reduction on puts Screen Size 4..6 back to "Auto". */
    if (sys_is_mode_4_to_6() == 1) {
        if (user_settings.blur_free_mode != 0) {
            panel_user_set_output_on(PANEL_OFF);
            user_settings.screen_size = SCREEN_SIZE_INPUT_ASPECT;
            pq_update_input_window(0);
        }
    }
    /* Phase 6. */
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
