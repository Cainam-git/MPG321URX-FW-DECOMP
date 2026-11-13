/* uart_cmd_get_color_values  (FUN_a00bfb28)
 *
 * Report the picture mode colour values to the PC tool with a checksum.
 *   port: command port (2, 3 or 4)
 * Note: Command 580[000 (get row 0x42); 19-byte frame '5b00[' + values + sum.
 * Name basis: derived - values from pq_api_get_mode_color_value; caller uart_cmd_dispatch_get
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bfb28 @ 0xa00bfb28-0xa00bfcc4 (103 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - uart_cmd_clear_rx is defined here as a static copy (GCC inlines it);
 *  - the head bytes are stored in the firmware's order 0, 1, 4, 2, 3.
 */
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[0x25];
extern unsigned char pq_api_get_mode_color_value(unsigned char);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define COLOR_REPLY_LENGTH  0x13    /* "5b00[" + 12 value bytes + sum byte + CR */
#define FIRST_VALUE_BYTE    5
#define LAST_VALUE_BYTE     16
#define SUM_BYTE            17

/* Colour value ids of pq_api_get_mode_color_value: the red, green and blue values of a picture mode. */
#define COLOR_ID_WARM50     6       /* ids 6..8: Warm 50 */
#define COLOR_ID_NORMAL65   9       /* ids 9..11: Normal 65 */
#define COLOR_ID_12         12      /* ids 12..14: part record bytes 0x0C..0x0E */
#define COLOR_ID_COOL93     18      /* ids 18..20: Cool 93 */

/* Make the port ready for the next command: clear its receive state byte and bytes 0, 1, 7, 10 and 0x19 of its
   receive record. */
static void uart_cmd_clear_rx(unsigned char port)
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

/*
 * Answer the get command "580[000" (row 0x42 of uart_cmd_get_rows) with twelve colour values of the part record
 * and their sum, as raw bytes (not as digits).
 *
 *   port  the command port the frame came in on; uart_cmd_dispatch_get passes it on. It selects the receive record
 *         to clear; the reply always goes out from uart_cmd_tx_frame.
 *
 * The reply frame (COLOR_REPLY_LENGTH bytes):
 *    0..4    "5b00[" (fixed here, not taken from the table row)
 *    5..7    Warm 50 red, green, blue          (colour value ids 6..8)
 *    8..10   Normal 65 red, green, blue        (ids 9..11)
 *    11..13  part record bytes 0x0C..0x0E      (ids 12..14)
 *    14..16  Cool 93 red, green, blue          (ids 18..20)
 *    17      the sum of bytes 5..16, kept to 8 bits
 *    18      CR
 * Then the port's receive state and record are cleared and the frame goes out on `port`.
 */
void uart_cmd_get_color_values(unsigned char port)
{
    unsigned char i, sum = 0;

    uart_cmd_tx_frame[0] = '5';
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[4] = '[';
    uart_cmd_tx_frame[2] = '0';
    uart_cmd_tx_frame[3] = '0';
    uart_cmd_tx_frame[5] = pq_api_get_mode_color_value(COLOR_ID_WARM50);
    uart_cmd_tx_frame[6] = pq_api_get_mode_color_value(COLOR_ID_WARM50 + 1);
    uart_cmd_tx_frame[7] = pq_api_get_mode_color_value(COLOR_ID_WARM50 + 2);
    uart_cmd_tx_frame[8] = pq_api_get_mode_color_value(COLOR_ID_NORMAL65);
    uart_cmd_tx_frame[9] = pq_api_get_mode_color_value(COLOR_ID_NORMAL65 + 1);
    uart_cmd_tx_frame[10] = pq_api_get_mode_color_value(COLOR_ID_NORMAL65 + 2);
    uart_cmd_tx_frame[11] = pq_api_get_mode_color_value(COLOR_ID_12);
    uart_cmd_tx_frame[12] = pq_api_get_mode_color_value(COLOR_ID_12 + 1);
    uart_cmd_tx_frame[13] = pq_api_get_mode_color_value(COLOR_ID_12 + 2);
    uart_cmd_tx_frame[14] = pq_api_get_mode_color_value(COLOR_ID_COOL93);
    uart_cmd_tx_frame[15] = pq_api_get_mode_color_value(COLOR_ID_COOL93 + 1);
    uart_cmd_tx_frame[16] = pq_api_get_mode_color_value(COLOR_ID_COOL93 + 2);
    /* Byte 17: the 8-bit sum of the twelve values. */
    for (i = FIRST_VALUE_BYTE; i <= LAST_VALUE_BYTE; i++)
        sum += uart_cmd_tx_frame[i];
    uart_cmd_tx_frame[SUM_BYTE] = sum;
    uart_cmd_tx_frame[18] = '\r';
    uart_cmd_clear_rx(port);
    uart_api_send_bytes(port, COLOR_REPLY_LENGTH, uart_cmd_tx_frame);
}
