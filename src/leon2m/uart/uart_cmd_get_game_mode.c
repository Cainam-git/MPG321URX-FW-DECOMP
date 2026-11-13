/* uart_cmd_get_game_mode  (FUN_a00bc95c)
 *
 * Report the Game Mode to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 5800200 (get row 0x13); reply 5b00200 + three digits.
 * Name basis: proven - get frame 5800200; settings byte +0x182 (game mode list); set uses UserSetGameMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bc95c @ 0xa00bc95c-0xa00bcaa8 (83 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record clears are written in ascending offset order (0, 1, 7, 10, 0x19) in all three arms.
 */
extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char user_settings_game_mode;
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern unsigned char input_api_source_id_to_menu_index(unsigned char);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_GAME_MODE  0x13    /* get row 00200: frame "5800200" + CR */
#define GET_REPLY_LENGTH   11      /* "5b" + 5-character id + 3 value characters + CR */
#define GAME_MODE_COUNT    6       /* the Game Mode list has six entries */

/*
 * Answer the get frame "5800200" with the Game Mode (user settings byte +0x182) as "5b00200" + "00" + one digit
 * + CR. Called by uart_cmd_dispatch_get for get row 0x13.
 *
 *   port  the command port the frame came in on (the only caller of uart_cmd_dispatch_get passes 4)
 *
 * The PC tool counts the modes one lower than the setting: stored 1..5 are sent as 0..4 and stored 0 as 5.
 * uart_cmd_set_game_mode stores (tool value + 1) % 6, the inverse.
 *
 * As in the other get routines, the answer is always built in uart_cmd_tx_frame and the port decides which
 * receive record is cleared (the body of uart_cmd_clear_rx) and where the answer is sent.
 */
void uart_cmd_get_game_mode(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (user_settings_game_mode + 5) % GAME_MODE_COUNT + '0';
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_GAME_MODE, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_GAME_MODE, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_GAME_MODE, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_GAME_MODE, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_GAME_MODE, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_GAME_MODE, 6);
    uart_cmd_tx_frame[10] = '\r';
    /* Forget the received frame. */
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
