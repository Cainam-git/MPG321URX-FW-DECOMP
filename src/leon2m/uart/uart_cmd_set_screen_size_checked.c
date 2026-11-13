/* uart_cmd_set_screen_size_checked  (FUN_a00ce5dc)
 *
 * Set the Screen Size from a two-digit PC tool command after checking conflicts.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Uncalled; first digit must be 0/1; refused while blur reduction or PIP/PBP is on or the Screen Size is
 *   4..6; then updates input window and PIP mode.
 * Name basis: derived - stores the second digit in settings byte +0x1A4 (screen size)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ce5dc @ 0xa00ce5dc-0xa00ce958 (223 words), flags -mcpu=v8 -O3 -g. No caller in the firmware.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3 (as in uart_cmd_set_transparency);
 *  - the refusal tests of each digit are one '||' chain per digit (separate ifs give a different block layout);
 *  - the digit is held in an unsigned short and compared through an unsigned char cast;
 *  - the settings are members of one structure; the gaming_flags bits are tested and cleared with masks.
 */
#define UART_CMD_REFUSED             0xff   /* result: uart_cmd_run_tool_task would answer "5600-" */
#define UART_CMD_OK_REPLY_LENGTH     6      /* "5600+\r" */
#define VALUE_CHAR_BASE              0x30   /* '0': a digit of the frame is the value plus 0x30 */

#define SIZE_FLAG_DIGIT_OFFSET       6      /* receive record byte of the first digit (0 or 1) */
#define SIZE_DIGIT_OFFSET            7      /* receive record byte of the Screen Size digit */
#define SCREEN_SIZE_DIGIT_MAX        8
#define SCREEN_SIZE_1_1              4      /* Screen Size menu list index of 1:1 */

#define PIP_PBP_OFF                  0      /* user_settings.pip_pbp_mode */
#define PIP_PBP_PIP                  1
#define PIP_PBP_PBP                  2

#define GAMING_FLAG_ADAPTIVE_SYNC    0x80   /* user_settings.gaming_flags bit 7: Adaptive-Sync */
#define GAMING_FLAG_BIT14            0x4000 /* gaming_flags bit 14, flipped by audio_user_toggle_source */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit of osd_request_bits */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char osd_request_bits;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (user_settings, docs/RECORDS.md) used here. */
struct user_settings_record {
    unsigned char pad_0x0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: PIP/PBP mode (0 off, 1 PIP, 2 PBP) */
    unsigned char pad_0x20[0xa8 - 0x20];
    unsigned int gaming_flags;                  /* +0xA8 */
    unsigned int settings_page_flags;           /* +0xAC */
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
    unsigned char pad_0xb4[0x1a4 - 0xb4];
    unsigned char screen_size;                  /* +0x1A4: Screen Size (menu list index) */
};
extern struct user_settings_record user_settings;
extern void osd_close_menu(void);
extern void audio_mute_outputs(void);
extern void panel_user_set_output_on(int);
extern void sys_user_apply_adaptive_sync_setting(void);
extern void UserSetPIPMode(void);
extern unsigned char sys_is_mode_4_to_6(void);
extern void pq_update_input_window(int);
extern void audio_user_update_routing(void);
extern void sys_user_clear_second_picture_request(void);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern void osd_mark_settings_changed_copy(void);

/* Write the reply "5600+" CR into the port's transmit frame. */
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
/* Clear the port's receive state and bytes 0, 1, 7, 10 and 0x19 of its receive record. */
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
/* Send the first len bytes of the port's transmit frame. */
void uart_cmd_send_tx_buffer(unsigned char port, unsigned char len)
{
    if (port == 2)
        uart_api_send_bytes(2, len, uart_cmd_tx_frame_port2);
    else if (port == 3)
        uart_api_send_bytes(3, len, uart_cmd_tx_frame_port3);
    else
        uart_api_send_bytes(port, len, uart_cmd_tx_frame);
}
/*
 * Set the Screen Size from two digits of the port's receive record (uart_cmd_rx_record_port2 for port 2,
 * uart_cmd_rx_record_port3 for port 3, uart_cmd_rx_record otherwise): byte 6 must be '0' or '1', byte 7 is
 * stored as it is into user_settings.screen_size (the menu list index; unlike uart_cmd_set_screen_size there is
 * no translation of the PC tool's numbering). Nothing in the firmware calls this routine.
 *
 * Phases:
 *  1. Refuse when the first digit is not 0 or 1, while blur reduction or PIP/PBP is on, or while the current
 *     Screen Size is 4..6 (sys_is_mode_4_to_6 reads screen_size).
 *  2. Refuse a second digit above 8. The PBP / PIP tests here cannot refuse anything after phase 1, which already
 *     required pip_pbp_mode to be 0.
 *  3. Store the new Screen Size.
 *  4. When the new size is 4..6, switch off what does not go with it: blur reduction and PIP/PBP (both already
 *     off by phase 1), and Adaptive-Sync (close the menu, mute the sound, panel_user_set_output_on(0), apply the
 *     DSC setting again, mark the settings changed).
 *  5. Recompute the input window of channel 0, apply the PIP/PBP mode again, route the sound again when gaming
 *     flag bit 14 is set.
 *  6. Request a settings save and send "5600+".
 *
 * port: command port (2, 3 or 4).
 * Returns 0, or UART_CMD_REFUSED with nothing changed.
 */
int uart_cmd_set_screen_size_checked(unsigned char port)
{
    unsigned char value_char;
    unsigned short digit;

    /* Phase 1: first digit and the states that block a change. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[SIZE_FLAG_DIGIT_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[SIZE_FLAG_DIGIT_OFFSET];
    else
        value_char = uart_cmd_rx_record[SIZE_FLAG_DIGIT_OFFSET];
    digit = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)digit > 1 || user_settings.blur_free_mode != 0 || user_settings.pip_pbp_mode != PIP_PBP_OFF ||
        sys_is_mode_4_to_6() == 1)
        return UART_CMD_REFUSED;

    /* Phase 2: the Screen Size digit. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[SIZE_DIGIT_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[SIZE_DIGIT_OFFSET];
    else
        value_char = uart_cmd_rx_record[SIZE_DIGIT_OFFSET];
    digit = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)digit > SCREEN_SIZE_DIGIT_MAX || user_settings.pip_pbp_mode == PIP_PBP_PBP ||
        ((unsigned char)digit == SCREEN_SIZE_1_1 && user_settings.pip_pbp_mode == PIP_PBP_PIP))
        return UART_CMD_REFUSED;

    /* Phase 3. */
    user_settings.screen_size = digit;

    /* Phase 4: sys_is_mode_4_to_6 now reads the size stored above. */
    if (sys_is_mode_4_to_6() == 1) {
        if (user_settings.blur_free_mode != 0) {
            user_settings.blur_free_mode = 0;
            sys_user_clear_second_picture_request();
        }
    }
    if (sys_is_mode_4_to_6() == 1) {
        if (user_settings.pip_pbp_mode != PIP_PBP_OFF) {
            user_settings.pip_pbp_mode = PIP_PBP_OFF;
            UserSetPIPMode();
        }
    }
    if (sys_is_mode_4_to_6() == 1) {
        if (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC) {
            osd_close_menu();
            user_settings.gaming_flags &= ~GAMING_FLAG_ADAPTIVE_SYNC;
            audio_mute_outputs();
            panel_user_set_output_on(0);
            sys_user_apply_adaptive_sync_setting();
            osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
        }
    }

    /* Phase 5: apply the new size. */
    pq_update_input_window(0);
    UserSetPIPMode();
    if (user_settings.gaming_flags & GAMING_FLAG_BIT14)
        audio_user_update_routing();

    /* Phase 6. */
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, 6);
    return 0;
}
