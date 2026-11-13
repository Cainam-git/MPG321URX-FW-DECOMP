/* uart_cmd_get_pip_size  (FUN_a00bdc14)
 *
 * Report the PIP size to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800630 (row 0x38); the answer is the
 *   character '2' minus the byte.
 * Name basis: derived - get frame 5800630; settings byte +0x31, which osd_enter_pip_size_choices uses as the
 *   PIP size (choice row 2 minus the byte)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bdc14, flags -mcpu=v8 -O3 -g.
 * Source form: the record is declared as a struct that holds only the byte at +0x31; the stores are in ascending
 * index order.
 */
/* The field of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad[0x31];
    unsigned char byte_0x31;                    /* +0x31: 0..2 */
};
extern struct user_settings_record user_settings;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply(unsigned char);
extern unsigned char uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_reply_frame(unsigned char, unsigned char);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */
#define VALUE_CHAR_BASE   0x30      /* '0': a one-digit value is sent as the value plus 0x30 */

/*
 * Answer the get command "5800630" (row 0x38 of uart_cmd_get_rows) with user settings byte +0x31 (0..2), sent
 * mirrored: the characters '0', '0' and '2' minus the byte.
 * The reply head ("5b", the id of the table row, CR) is filled in by uart_cmd_build_get_reply; bytes 7..9 of
 * uart_cmd_tx_frame carry the value. The received frame is then forgotten (uart_cmd_clear_rx) and
 * GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has the same code inline in its case for the row.
 */
void uart_cmd_get_pip_size(unsigned char port)
{
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = '2' - user_settings.byte_0x31;
    uart_cmd_build_get_reply(0x38);
    uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
