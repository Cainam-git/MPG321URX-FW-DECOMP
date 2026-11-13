/* uart_cmd_toggle_setting_bit14  (FUN_a00c9470)
 *
 * Toggle settings bit 14 of +0xA8 on a PC tool command.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00660; value must be 1 and PIP/PBP on; returns 0xFF for a bad value (the task then replies
 *   5600-), else 0 after '5600+'.
 * Name basis: descriptive - set frame 5b00660; audio_user_toggle_source flips bit 14 of gaming_flags (+0xA8)
 *   and routes the sound again
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the parameter is an int masked with 0xff in its first statement; the value character is compared
 * directly with '1'. Same code as uart_cmd_swap_pip_sources with another action call.
 */
#define UART_CMD_REFUSED         0xff   /* result: value refused; the caller then replies "5600-" */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */

extern unsigned char uart_cmd_rx_units_digit_port2;
extern unsigned char uart_cmd_rx_units_digit_port3;
extern unsigned char uart_cmd_rx_units_digit;
extern unsigned char user_settings_pip_pbp_mode;
extern void audio_user_toggle_source(void);
extern int uart_cmd_build_ok_reply();
extern int uart_cmd_clear_rx();
extern int uart_cmd_send_tx_buffer();

/*
 * Set command 00660 (set row 0x10): toggle the audio source (audio_user_toggle_source flips bit 14 of
 * gaming_flags, settings word +0xA8, and routes the sound again). Only the value '1' is accepted, and only while
 * PIP or PBP is on (pip_pbp_mode, settings byte +0x1F, is not 0). The value is the character in byte 9 of the
 * port's receive record (port 2 and port 3 have their own records, every other port uses the third).
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED. The same code is inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_toggle_setting_bit14(int port)
{
    unsigned char value_char;
    
    port = port & 0xff;
    if (port == 2) {
        value_char = uart_cmd_rx_units_digit_port2;
    } else if (port == 3) {
        value_char = uart_cmd_rx_units_digit_port3;
    } else {
        value_char = uart_cmd_rx_units_digit;
    }
    
    if (value_char != '1') {
        return UART_CMD_REFUSED;
    }
    
    if (user_settings_pip_pbp_mode == 0) {
        return UART_CMD_REFUSED;
    }
    
    audio_user_toggle_source();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
