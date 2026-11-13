/* uart_cmd_get_firmware_version  (FUN_a00bc214)
 *
 * Report the firmware version to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 58001<0 (row 0x4a).
 * Name basis: proven - get frame 58001<0; reply digits '021' = FW.021
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bc214, flags -mcpu=v8 -O3 -g.
 * Source form: the three digits are stored first, then the builder (called with no parameter list, result dropped) and
 * uart_cmd_clear_rx (result dropped); the reply goes out with uart_api_send_bytes directly (a tail call).
 */
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern int uart_cmd_clear_rx();
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

/*
 * Answer the get command "58001<0" (row 0x4a of uart_cmd_get_rows): the firmware number, the three characters
 * "021" (FW.021). Then the head is built, the received frame is forgotten and GET_REPLY_LENGTH bytes go out on
 * `port`.
 * Not called: uart_cmd_dispatch_get has this code inline in its case for the row.
 */
void uart_cmd_get_firmware_version(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '2';
    uart_cmd_tx_frame[9] = '1';
    (void)uart_cmd_build_get_reply(0x4a);
    (void)uart_cmd_clear_rx(port);
    uart_api_send_bytes(port, GET_REPLY_LENGTH, uart_cmd_tx_frame);
}
