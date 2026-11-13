/* uart_cmd_set_second_source  (FUN_a00c8818)
 *
 * Set the second picture source from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00620; digit 0..3; returns 0xFF for a bad value or while PIP/PBP is off (the task then
 *   replies 5600-), else 0 after '5600+'.
 * Name basis: derived - set frame 5b00620; settings byte +0x20; refused while PIP/PBP is off; mutes, routes
 *   the sound again when gaming_flags bit 14 is set, unmutes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c8818 @ 0xa00c8818-0xa00c8a44 (139 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is an unsigned short tested as an unsigned char and passed on as it is;
 *  - gaming_flags is a plain word tested with a mask.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_OFFSET         9         /* receive record byte with the value character */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define INPUT_CHOICE_MAX          3         /* inputs '0'..'3' = HDMI 1, HDMI 2, DP, Type-C (menu order) */
#define PIP_PBP_OFF               0
#define CHANNEL_1                 1         /* sys_user_apply_pip_sources: the second picture */
#define GAMING_FLAG_BIT14         0x4000    /* gaming_flags bit 14: the sound of the second picture is played
                                               (audio_user_toggle_source) */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (docs/RECORDS.md) used here. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x1F: 0 = PIP/PBP off */
    unsigned char second_source;                /* +0x20: source id of the second picture (channel 1) */
    unsigned char pad21[0xa8 - 0x21];
    unsigned int gaming_flags;                  /* +0xA8 */
};
extern struct user_settings_record user_settings;
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void sys_user_apply_pip_sources(int);
extern void audio_mute_outputs(void);
extern void audio_unmute_outputs(void);
extern void audio_user_update_routing(void);
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
/* Make the port ready for the next command: clear its receive state and bytes 0, 1, 7, 10 and 0x19 of its
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
/* Send the first `length` bytes of the port's reply frame. */
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
 * Set row 9 (row id 00620) of uart_cmd_dispatch_set: choose the source of the second picture (settings byte
 * +0x20) from a frame of MSI's PC tool ("5b00620" + two '0' + the input character '0'..'3').
 * uart_cmd_get_second_source reports the same byte under the same id. Rows 10 and 12 (ids 00610 and 00612) store
 * the same byte too; they do not mute and always route the sound again.
 *
 *   port  the command port the frame came in on; it selects the receive record and the reply frame (port 2 and
 *         port 3 have their own, every other port uses uart_cmd_rx_record and uart_cmd_tx_frame). The only
 *         caller, uart_cmd_dispatch_set, is called by uart_cmd_run_tool_task with port 4.
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for an input above 3 or while
 * PIP/PBP is off; then nothing has changed and the dispatcher answers "5600-".
 *
 * In this order:
 *   1. Read the input from frame byte 9 (input plus 0x30).
 *   2. Refuse it while PIP/PBP is off (settings byte +0x1F is 0).
 *   3. Store the source id of the input (input_api_menu_index_to_source_id, which turns menu index 0..3 into source
 *      id 5, 6, 0xC or 0xD) and select it as the source of channel 1 (sys_user_apply_pip_sources).
 *   4. Mute the sound; route it again (audio_user_update_routing) only while the sound of the second picture is
 *      played (gaming_flags bit 14); unmute.
 *   5. Request that the settings are saved and reply "5600+\r".
 */
int uart_cmd_set_second_source(unsigned char port)
{
    unsigned char value_char;
    unsigned short input;

    if (port == 2)
        value_char = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        value_char = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    input = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)input > INPUT_CHOICE_MAX)
        return UART_CMD_REFUSED;
    /* There is no second picture while PIP/PBP is off. */
    if (user_settings.pip_pbp_mode == PIP_PBP_OFF)
        return UART_CMD_REFUSED;

    user_settings.second_source = input_api_menu_index_to_source_id(input);
    sys_user_apply_pip_sources(CHANNEL_1);
    audio_mute_outputs();
    /* Route the sound again only while the sound of the second picture is played. */
    if (user_settings.gaming_flags & GAMING_FLAG_BIT14)
        audio_user_update_routing();
    audio_unmute_outputs();
    osd_mark_settings_changed_copy();

    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
