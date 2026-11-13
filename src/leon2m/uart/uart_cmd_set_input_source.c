/* uart_cmd_set_input_source  (FUN_a00c18cc)
 *
 * Set the Input Source from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00500, value '0'..'3' (HDMI 1, HDMI 2, DP, Type-C). Returns 0xFF for another value or when
 *   that input is already selected (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00500; settings byte +0x1E gets input_api_menu_index_to_source_id(value);
 *   input_api_source_id_to_menu_index only serves the 'already this input' test; restarts the display path
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c18cc @ 0xa00c18cc-0xa00c1adc (132 words), flags -mcpu=v8 -O3 -g.
 * Source form: the three port helpers (uart_cmd_build_ok_reply, uart_cmd_clear_rx, uart_cmd_send_tx_buffer) are
 * defined in this file and inlined by GCC at -O3 (as in uart_cmd_set_transparency).
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_OFFSET         9         /* byte 9 of a set frame: the one-character value */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define INPUT_CHOICE_MAX          3         /* inputs 0..3 in menu order: HDMI 1, HDMI 2, DP, Type-C */
#define APP_STATE_BIT10           0x400     /* app_state_record halfword +0: set when the input changes;
                                               osd_draw_input_info_banner then shows the input banner */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The field of the user settings record (user_settings, docs/RECORDS.md) used here. */
struct user_settings_record {
    unsigned char pad_0x0[0x1e];
    unsigned char input_source;                 /* +0x1E: Input Source (a source id) */
};
extern struct user_settings_record user_settings;
extern unsigned short app_state_record;         /* flag halfword at +0 */
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern unsigned char input_api_menu_index_to_source_id(unsigned char);
extern void sys_user_reset_display_path(void);
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
 * Set row 1 of uart_cmd_dispatch_set (id 00500): switch the Input Source.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) with nothing changed; then the
 * dispatcher answers "5600-".
 *
 * Two look-ups through the input table: input_api_source_id_to_menu_index turns the stored source id into the menu
 * input 0..3, input_api_menu_index_to_source_id turns a menu input into the source id (5, 6, 0xC or 0xD).
 *
 * Phases:
 *   1. Frame byte 9 is the input as a character '0'..'3' (HDMI 1, HDMI 2, DP, Type-C, the menu order); any other
 *      character is refused.
 *   2. Refused when that input is already the Input Source.
 *   3. The Input Source setting (+0x1E) gets the source id of the input.
 *   4. The display path is restarted, APP_STATE_BIT10 is set so that the input banner is drawn, and a settings
 *      save is requested.
 *   5. Reply "5600+\r", clear the port's receive record, send the reply.
 */
int uart_cmd_set_input_source(unsigned char port)
{
    unsigned char value_char;
    unsigned short input;

    /* Phase 1. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        value_char = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    input = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)input > INPUT_CHOICE_MAX)
        return UART_CMD_REFUSED;
    /* Phase 2. */
    if (input_api_source_id_to_menu_index(user_settings.input_source) == (unsigned char)input)
        return UART_CMD_REFUSED;
    /* Phase 3. */
    user_settings.input_source = input_api_menu_index_to_source_id(input);
    /* Phase 4. */
    sys_user_reset_display_path();
    app_state_record |= APP_STATE_BIT10;
    osd_mark_settings_changed_copy();
    /* Phase 5. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
