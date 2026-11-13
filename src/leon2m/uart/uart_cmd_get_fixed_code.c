/* uart_cmd_get_fixed_code  (FUN_a00bdb48)
 *
 * Report the fixed code '00' + 0x9F for command 5800140 to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get (row 0x2f).
 * Name basis: descriptive - reply bytes '0', '0', 0x9F; nothing is read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bdb48, flags -mcpu=v8 -O3 -g.
 * Source form: the three stores are in ascending order 7, 8, 9; of the six possible orders it is the only one that
 * gives the firmware's store order 9, 8, 7 after scheduling. The parameter is an unsigned int that is masked to a byte
 * before it is passed on.
 */
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern int uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define FIXED_VALUE_CODE  0x9f      /* third value byte of the reply: a fixed code, not a digit */

/*
 * Answer the get command "5800140" (row 0x2f of uart_cmd_get_rows) with a fixed value: the characters '0', '0' and
 * the byte 0x9f. No setting is read.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_fixed_code(unsigned int port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = FIXED_VALUE_CODE;
    (void)uart_cmd_build_get_reply(0x2f);
    port &= 0xff;
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
