/* uart_cmd_get_picture_mode  (FUN_a00bd760)
 *
 * Report the picture mode (game or professional mode) to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800120 (get row 0x2c); reply 5b00120 + three digits.
 * Name basis: derived - get frame 5800120; bit 11 of +0xA8 with byte +0x181 / +0x182
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bd760 @ 0xa00bd760-0xa00bd988 (138 words), flags -mcpu=v8 -O3 -g.
 * Source form: as uart_cmd_get_pro_mode (a switch with case 7 written first; jump table switchdataD_a00ba408),
 * with the Game Mode arm (bit clear) first and the fields read through the structure at user_settings; the
 * function covers its case blocks up to 0xa00bd988.
 */
extern unsigned char uart_cmd_tx_frame[11];
/* The parts of the user settings record read here. */
struct user_settings_record {
    unsigned char pad_0x0[0xa8];
    unsigned int gaming_flags;      /* +0xA8: bit 11 = GAMING_FLAG_PRO_MODE */
    unsigned char pad_0xac[0x181 - 0xac];
    unsigned char pro_mode;         /* +0x181: the Professional mode */
    unsigned char game_mode;        /* +0x182: the Game Mode */
};
extern struct user_settings_record user_settings;
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_PICTURE_MODE  0x2c  /* row of uart_cmd_get_rows: "5800120" */
#define GET_REPLY_LENGTH      11    /* "5b" + 5-character id + 3 value characters + CR */
#define GAMING_FLAG_PRO_MODE_BIT  11
#define GAMING_FLAG_PRO_MODE  0x800 /* set: Professional mode in use; clear: Game Mode */
#define GAME_MODE_COUNT       6     /* the set row stores (tool value + 1) % 6 */

/*
 * Answer the get command "5800120" with the picture mode in use: '0', then '1' for a Professional mode or '0'
 * for a Game Mode (bit 11 of the gaming flags, user settings +0xA8), then the number of that mode.
 *   port: the command port the frame came in on. The only caller, uart_cmd_dispatch_get, passes the port of
 *         uart_cmd_run_tool_task, which is 4.
 *
 * In this order:
 *   1. Bytes 7..9 of uart_cmd_tx_frame get the value. For a Game Mode byte 9 is (game_mode + 5) % 6, the inverse
 *      of uart_cmd_set_game_mode, which stores (tool value + 1) % 6. For a Professional mode byte 9 is the digit
 *      of pro_mode as in uart_cmd_get_pro_mode: only 0..7 have a case, any other value leaves byte 9 as the
 *      previous reply left it.
 *   2. The reply head: bytes 0 and 2..6 are copied from the table row ('5' and the id "00120"), byte 1 is 'b',
 *      byte 10 is CR.
 *   3. The received frame is forgotten: the port's receive state byte and bytes 0, 1, 7, 10 and 0x19 of its receive
 *      record are set to 0 (the same stores as uart_cmd_clear_rx). Ports 2 and 3 have their own byte and record,
 *      every other port uses uart_cmd_rx_count and uart_cmd_rx_record.
 *   4. GET_REPLY_LENGTH bytes go out on `port`.
 */
void uart_cmd_get_picture_mode(unsigned char port)
{
    unsigned int gaming_flags = user_settings.gaming_flags;

    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = ((gaming_flags >> GAMING_FLAG_PRO_MODE_BIT) & 1) + '0';
    if (!(gaming_flags & GAMING_FLAG_PRO_MODE))
        uart_cmd_tx_frame[9] = (user_settings.game_mode + 5) % GAME_MODE_COUNT + '0';
    else {
        switch (user_settings.pro_mode) {
        case 7:                     /* first: see the matching notes */
            uart_cmd_tx_frame[9] = '7';
            break;
        case 0:
            uart_cmd_tx_frame[9] = '0';
            break;
        case 1:
            uart_cmd_tx_frame[9] = '1';
            break;
        case 2:
            uart_cmd_tx_frame[9] = '2';
            break;
        case 3:
            uart_cmd_tx_frame[9] = '3';
            break;
        case 4:
            uart_cmd_tx_frame[9] = '4';
            break;
        case 5:
            uart_cmd_tx_frame[9] = '5';
            break;
        case 6:
            uart_cmd_tx_frame[9] = '6';
            break;
        }
    }
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_PICTURE_MODE, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_PICTURE_MODE, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_PICTURE_MODE, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_PICTURE_MODE, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_PICTURE_MODE, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_PICTURE_MODE, 6);
    uart_cmd_tx_frame[10] = '\r';
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
    uart_api_send_bytes(port, GET_REPLY_LENGTH, uart_cmd_tx_frame);
}
