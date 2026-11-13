/* uart_api_send_bytes  (FUN_a01487e8)
 *
 * Queue bytes for sending on one of the 8051's serial ports.
 * Name basis: derived - forwards to uart_send_bytes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01487e8 @ 0xa01487e8 (-mcpu=v8 -O2 -g)
 * Forwards its three arguments (port, len, buffer) to uart_send_bytes(port, len, buffer) as a tail call; len is
 * passed on as an unsigned short. Callers: uart_cmd_set_static_screen_settings, uart_cmd_set_color_gains, UartSetI2CEnable and other handlers.
 */
extern void uart_send_bytes(unsigned char cmd, unsigned short len, unsigned char *p);

/*
 * Queue bytes for a serial port of the 8051: hands port, len and buf on to uart_send_bytes unchanged.
 * Callers: uart_cmd_set_static_screen_settings, uart_cmd_set_color_gains, UartSetI2CEnable and other handlers.
 */
void uart_api_send_bytes(unsigned char port, unsigned short len, unsigned char *buf)
{
    uart_send_bytes(port, len, buf);
}
