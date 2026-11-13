/* uart_cmd_set_game_mode  (FUN_a00c3820)
 *
 * Set the Game Mode from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00200; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00200; settings byte +0x182 (game mode list); set uses UserSetGameMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c3820 @ 0xa00c3820-0xa00c3a30 (132 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is an unsigned short tested as an unsigned char;
 *  - the two settings fields are members of one structure, and the flag word is cleared before the Game Mode
 *    is stored (the word store fills the delay slot of the call).
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */

#define GAME_MODE_COUNT           6         /* the Game Mode list has six entries */
#define GAMING_FLAG_PRO_MODE      0x800     /* gaming_flags bit 11: Pro Mode (1) or Game Mode (0) */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
/* The two fields of the user settings record written here. */
struct user_settings_record {
    unsigned char pad0[0xa8];
    unsigned int gaming_flags;                  /* +0xA8 */
    unsigned char pad0ac[0x182 - 0xac];
    unsigned char game_mode;                    /* +0x182: the Game Mode */
};
extern struct user_settings_record user_settings;
extern void UserSetGameMode(void);
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
 * Set row 0x2C (44, row id 00200) of uart_cmd_dispatch_set: choose a Game Mode from a frame of MSI's PC tool and
 * apply it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value above 5; then nothing
 * has changed and the dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read the mode from frame byte 9 (mode plus 0x30).
 *   2. Leave Pro Mode (clear GAMING_FLAG_PRO_MODE) and store the Game Mode. The PC tool counts the modes one
 *      lower than the setting: tool value 0..4 is stored as 1..5 and tool value 5 as 0
 *      (uart_cmd_get_game_mode sends the inverse). Then apply it (UserSetGameMode) and request that the settings
 *      are saved.
 *   3. Reply "5600+\r".
 */
int uart_cmd_set_game_mode(unsigned char port)
{
    unsigned char value_char;
    unsigned short tool_mode;

    /* Phase 1. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[9];
    else
        value_char = uart_cmd_rx_record[9];
    tool_mode = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)tool_mode > GAME_MODE_COUNT - 1)
        return UART_CMD_REFUSED;

    /* Phase 2. */
    user_settings.gaming_flags &= ~GAMING_FLAG_PRO_MODE;
    user_settings.game_mode = ((unsigned char)tool_mode + 1) % GAME_MODE_COUNT;
    UserSetGameMode();
    osd_mark_settings_changed_copy();

    /* Phase 3. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
