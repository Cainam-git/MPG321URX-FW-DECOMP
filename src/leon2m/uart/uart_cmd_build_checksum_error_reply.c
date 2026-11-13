/* uart_cmd_build_checksum_error_reply  (FUN_a00bac04)
 *
 * Put the '5600' + 0xEE reply (data check failed) into the reply frame.
 * Note: Unused standalone copy; the block commands send it when their byte sum does not match.
 * Name basis: derived - frame 35 36 30 30 EE 0D; same reply in the 001i / 001j handlers on a sum mismatch
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bac04, flags -mcpu=v8 -O3 -g.
 */
#define UART_REPLY_SUM_ERROR 0xee       /* fifth reply byte instead of '+' when the byte sum of a block is wrong */

extern unsigned char uart_cmd_tx_frame[];

/* Fill the shared reply frame with "5600" + 0xEE + CR. Only the frame is filled, nothing is sent. Not called;
   the block commands build the same frame themselves. */
void uart_cmd_build_checksum_error_reply(void)
{
    uart_cmd_tx_frame[0] = '5';
    uart_cmd_tx_frame[1] = '6';
    uart_cmd_tx_frame[2] = '0';
    uart_cmd_tx_frame[3] = '0';
    uart_cmd_tx_frame[4] = UART_REPLY_SUM_ERROR;
    uart_cmd_tx_frame[5] = '\r';
}
