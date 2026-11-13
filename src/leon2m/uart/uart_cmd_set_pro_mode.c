/* uart_cmd_set_pro_mode  (FUN_a00c5478)
 *
 * Set the Professional mode from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00300, digit 0..8: 4, 5 and 6 are refused (0xFF, reply 5600-) while
 *   sys_user_get_picture_state is not 0; 8 sets the Pro flag and stores no mode; else 0 after '5600+'.
 * Name basis: derived - set frame 5b00300; settings byte +0x181; set uses UserSetProMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c5478 @ 0xa00c5478-0xa00c573c (146 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is computed into an unsigned short and copied into an unsigned char local (mode);
 *  - the test for 4, 5 and 6 is an if/else chain with the same body three times (an || chain is folded into one
 *    range test);
 *  - the store is a switch with one case per value 0..7 (jump table at 0xa00ba634, image-relative).
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */

#define TOOL_PRO_MODE_MAX         8         /* largest value accepted; 8 changes no mode (no case below) */
#define GAMING_FLAG_PRO_MODE      0x800     /* user settings +0xA8 bit 11: Pro (1) / Game (0) */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0xa8];
    unsigned int gaming_flags;                  /* +0xA8 */
    unsigned char pad0ac[0x181 - 0xac];
    unsigned char pro_mode;                     /* +0x181: the Professional mode */
};
extern struct user_settings_record user_settings;
extern int sys_user_get_picture_state(void);
extern void UserSetProMode(void);
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
 * Set row 0x3C (60) of uart_cmd_dispatch_set: choose a Professional mode from a frame of MSI's PC tool and
 * apply it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF); then nothing has changed and the
 * dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read the value from frame byte 9 (value plus 0x30). Refused: a value above 8, and the values 4, 5 and 6
 *      while sys_user_get_picture_state() is not 0 (channel 0's port has flag bit 9 set, or flag bit 6 with
 *      mailbox status 1..4).
 *   2. Switch the menus to the Professional side (gaming flag bit 11) and store the mode 0..7 in pro_mode.
 *      Value 8 passes the test but stores no mode: the Pro side is selected with the mode it had.
 *   3. Apply the mode with all its settings (UserSetProMode) and request that the settings are saved.
 *   4. Reply "5600+\r".
 */
int uart_cmd_set_pro_mode(unsigned char port)
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
    if (mode > TOOL_PRO_MODE_MAX)
        return UART_CMD_REFUSED;
    if (mode == 4) {
        if (sys_user_get_picture_state() != 0)
            return UART_CMD_REFUSED;
    } else if (mode == 5) {
        if (sys_user_get_picture_state() != 0)
            return UART_CMD_REFUSED;
    } else if (mode == 6) {
        if (sys_user_get_picture_state() != 0)
            return UART_CMD_REFUSED;
    }

    /* Phase 2. */
    user_settings.gaming_flags |= GAMING_FLAG_PRO_MODE;
    switch (mode) {
    case 0:
        user_settings.pro_mode = 0;
        break;
    case 1:
        user_settings.pro_mode = 1;
        break;
    case 2:
        user_settings.pro_mode = 2;
        break;
    case 3:
        user_settings.pro_mode = 3;
        break;
    case 4:
        user_settings.pro_mode = 4;
        break;
    case 5:
        user_settings.pro_mode = 5;
        break;
    case 6:
        user_settings.pro_mode = 6;
        break;
    case 7:
        user_settings.pro_mode = 7;
        break;
    }

    /* Phase 3. */
    UserSetProMode();
    osd_mark_settings_changed_copy();

    /* Phase 4. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
