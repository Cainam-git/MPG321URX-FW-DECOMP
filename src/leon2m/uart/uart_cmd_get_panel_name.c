/* uart_cmd_get_panel_name  (FUN_a00bc258)
 *
 * Report the panel name to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Command 58001?0 (get row 0x4b); reply 5b001?0 + length byte 0x12 + 18 text characters
 * Name basis: proven - get frame 58001?0; text 'SDC QMC315AA01_D01'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bc258 @ 0xa00bc258-0xa00bc3b0 (86 words), flags -mcpu=v8 -O3 -g.
 * Source form: the text length 0x12 is a local that gives both byte 7 and the loop limit (a constant limit
 * compiles to cmp 0x11; bleu).
 */
extern unsigned char uart_cmd_tx_frame[0x25];
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern const char s_00198280[];                /* "SDC QMC315AA01_D01" (18 characters) */
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_ROW_PANEL_NAME 0x4b    /* get row 001?0: frame "58001?0" + CR */
#define NAME_REPLY_LENGTH  0x25    /* "5b" + id + length byte + 18 text bytes + 10 bytes + CR */

/*
 * Answer the get frame "58001?0" with the panel name text "SDC QMC315AA01_D01". Called by uart_cmd_dispatch_get
 * for get row 0x4B.
 *
 *   port  the command port the frame came in on (the only caller of uart_cmd_dispatch_get passes 4)
 *
 * The answer is 0x25 bytes: "5b001?0", the text length 0x12 in byte 7, the 18 characters in bytes 8..0x19 and a
 * CR in byte 0x24. Bytes 0x1A..0x23 are not written here and go out as they are. uart_cmd_tx_frame is the 0x19-byte
 * reply frame (uart_cmd_init_ports clears 0x19 bytes) and uart_cmd_rx_record_port3 starts 0x20 bytes after it, so
 * bytes 0x20..0x24 of this answer are the first five bytes of port 3's receive record, and the CR is written
 * into its byte 4.
 *
 * As in the other get routines, the answer is always built in uart_cmd_tx_frame and the port decides which
 * receive record is cleared (the body of uart_cmd_clear_rx) and where the answer is sent.
 */
void uart_cmd_get_panel_name(unsigned char port)
{
    unsigned char i, length = 0x12;

    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_PANEL_NAME, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_PANEL_NAME, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_PANEL_NAME, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_PANEL_NAME, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_PANEL_NAME, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_PANEL_NAME, 6);
    uart_cmd_tx_frame[7] = length;
    for (i = 0; i < length; i++)
        uart_cmd_tx_frame[8 + i] = s_00198280[i];
    uart_cmd_tx_frame[0x24] = '\r';
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
    uart_api_send_bytes(port, NAME_REPLY_LENGTH, uart_cmd_tx_frame);
}
