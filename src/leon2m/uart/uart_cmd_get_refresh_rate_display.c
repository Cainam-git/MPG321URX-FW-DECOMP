/* uart_cmd_get_refresh_rate_display  (FUN_a00bcbcc)
 *
 * Report the Refresh Rate display switch to the PC tool.
 *   port: command port (2, 3 or 4)
 * Note: Uncalled copy of a case of uart_cmd_dispatch_get; command 5800250 (row 0x18).
 * Name basis: proven - get frame 5800250; bit 12 of +0xA8 (osd_enter_refresh_rate_choices)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bcbcc, flags -mcpu=v8 -O3 -g.
 * Source form: the flag is formed in an unsigned int local before the digits are stored; the builder is declared without
 * a parameter list, uart_cmd_clear_rx returns unsigned char (result dropped).
 */
extern unsigned int user_settings_gaming_flags;
extern unsigned char uart_cmd_tx_frame[];
extern void uart_cmd_build_get_reply();
extern unsigned char uart_cmd_clear_rx();
extern void uart_cmd_send_reply_frame(unsigned char port, unsigned char length);

#define GET_REPLY_LENGTH  11        /* "5b" + 5-character id + 3 value characters + CR */

#define GAMING_FLAG_REFRESH_RATE_DISPLAY_BIT 12     /* bit 12 of the gaming flags: Refresh Rate display (docs/RECORDS.md) */

/*
 * Answer the get command "5800250" (row 0x18 of uart_cmd_get_rows): the Refresh Rate display switch (bit 12 of the gaming flags, settings word +0xA8), as '0', '0' and the bit plus '0'.
 * The reply is the fixed head from the table row, then the value characters in bytes 7..9, then the received
 * frame is forgotten (uart_cmd_clear_rx) and GET_REPLY_LENGTH bytes go out on `port`.
 * Not called: uart_cmd_dispatch_get has this code inline in its case for the row.
 */
void uart_cmd_get_refresh_rate_display(unsigned char port)
{
    unsigned int display_on;

    display_on = (user_settings_gaming_flags >> GAMING_FLAG_REFRESH_RATE_DISPLAY_BIT) & 1;
    uart_cmd_tx_frame[7] = '0';
    uart_cmd_tx_frame[8] = '0';
    uart_cmd_tx_frame[9] = (display_on + '0');
    (void)uart_cmd_build_get_reply(0x18);
    (void)uart_cmd_clear_rx(port);
    uart_cmd_send_reply_frame(port, GET_REPLY_LENGTH);
}
