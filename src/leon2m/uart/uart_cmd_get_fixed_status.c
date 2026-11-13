/* uart_cmd_get_fixed_status  (FUN_a00bdec0)
 *
 * Send the fixed reply frame '5b00\00011' for command 580\ to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get (row 0x41); sends 0x26 bytes from the frame buffer.
 * Name basis: descriptive - frame bytes 35 62 30 30 5C 30 30 30 31 31 0D
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bdec0, flags -mcpu=v8 -O3 -g.
 * Source form: the eleven bytes are stored in ascending index order.
 */
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_reply_frame(unsigned char, unsigned char);

#define STATUS_REPLY_LENGTH  0x26   /* bytes sent: more than the 11 written, the rest of the frame is sent as it is */

/*
 * Answer the get frame of row 0x41 of uart_cmd_get_rows (id "580\" followed by three wildcard bytes) with the
 * fixed frame "5b00\00011" + CR, written here in full (uart_cmd_build_get_reply is not used). No setting is
 * read.
 * The received frame is then forgotten (uart_cmd_clear_rx) and STATUS_REPLY_LENGTH (38) bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_fixed_status(unsigned char port)
{
    uart_cmd_tx_frame[0] = '5';
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = '0';
    uart_cmd_tx_frame[3] = '0';
    uart_cmd_tx_frame[4] = '\\';
    uart_cmd_tx_frame[5] = '0';
    uart_cmd_tx_frame[6] = '0';
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '1';
    uart_cmd_tx_frame[9] = '1';
    uart_cmd_tx_frame[10] = '\r';
    uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, STATUS_REPLY_LENGTH);
}
