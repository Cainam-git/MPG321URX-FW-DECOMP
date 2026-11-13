/* uart_cmd_build_get_reply  (FUN_a00bac3c)
 *
 * Fill the reply frame header for a get command from its command row.
 *   param_1: get command row
 * Note: Frame 0xA802D078: [0] '5', [1] 'b', [2..6] command id, [10] CR; the caller puts the value in [7..9].
 * Name basis: proven - reads sys_cmd_frame8_get_char(row, 0 / 2..6); used by every get reply
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bac3c, flags -mcpu=v8 -O3 -g.
 * Source form: the first parameter is masked to a byte once (row) and used for all five table reads; the second parameter
 * is unused.
 */
extern unsigned char uart_cmd_tx_frame[];
extern int sys_cmd_frame8_get_char();

/*
 * Fill the fixed part of a get reply in the shared reply frame: byte 0 and bytes 2..6 are copied from the row
 * `row` of the get command table (the same characters as in the get frame the tool sent: "5" and the 5-character
 * id), byte 1 is 'b' and byte 10 is CR. Bytes 7..9, the three value characters, are left to the caller.
 * Called by the get replies.
 */
void uart_cmd_build_get_reply(unsigned char row, unsigned int unused)
{
    unsigned char row_byte;

    row_byte = row & 0xff;
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(row_byte, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(row_byte, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(row_byte, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(row_byte, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(row_byte, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(row_byte, 6);
    uart_cmd_tx_frame[10] = '\r';
}
