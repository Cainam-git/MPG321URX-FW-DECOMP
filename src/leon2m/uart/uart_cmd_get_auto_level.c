/* uart_cmd_get_auto_level  (FUN_a00bcb80)
 *
 * Report the automatic level setting to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800240 (row 0x17).
 * Name basis: derived - get frame 5800240; bit 31 of +0x11C, applied by sys_user_apply_auto_level
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bcb80, flags -mcpu=v8 -O3 -g.
 * Source form: the flag is formed in an unsigned int local before the digits are stored; the builder is declared without
 * a parameter list, uart_cmd_clear_rx returns unsigned char (result dropped).
 */
extern unsigned int user_settings_professional_flags;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern unsigned char uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

#define PROFESSIONAL_AUTO_LEVEL_BIT 31      /* bit 31 of the professional flags: automatic level */

/*
 * Answer the get command "5800240" (row 0x17 of uart_cmd_get_rows): the automatic level setting (bit 31 of the professional flags, settings word +0x11C), as '0', '0' and the bit plus '0'.
 * The reply is the fixed head from the table row, then the value characters in bytes 7..9, then the received
 * frame is forgotten (uart_cmd_clear_rx) and GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has this code inline in its case for the row.
 */
void uart_cmd_get_auto_level(unsigned char port)
{
    unsigned int auto_level;

    auto_level = (user_settings_professional_flags >> PROFESSIONAL_AUTO_LEVEL_BIT) & 1;
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (auto_level + '0');
    (void)uart_cmd_build_get_reply(0x17);
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
