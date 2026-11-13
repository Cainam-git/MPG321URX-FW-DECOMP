/* uart_cmd_set_scope_size  (FUN_a00c3ec8)
 *
 * Set the Optix Scope size from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b002A1; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b002A1; settings byte +0x4B (osd_enter_scope_size_choices)
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the character goes through a static helper ascii_digit() returning c - '0' (inlined; its int
 * result kept in an unsigned char gives the 'and 0xff' of the loaded byte and of the digit); the parameter is an
 * int masked with 0xff in its first statement.
 */
#define UART_CMD_REFUSED         0xff   /* result: value refused; the caller then replies "5600-" */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */

extern unsigned char uart_cmd_rx_units_digit_port2;
extern unsigned char uart_cmd_rx_units_digit_port3;
extern unsigned char uart_cmd_rx_units_digit;
extern unsigned char user_settings_scope_size;
extern int sys_user_apply_second_picture_enable(int);
extern int uart_cmd_build_ok_reply();
extern int uart_cmd_clear_rx();
extern int uart_cmd_send_tx_buffer();

static int ascii_digit(unsigned char c)
{
  return c - '0';
}

/*
 * Set command 002A1 (set row 0x37): the Optix Scope size (settings byte +0x4B), 0..2. The second picture is then
 * switched as the settings say (sys_user_apply_second_picture_enable(1)); no settings save is requested here. The
 * value is the character in byte 9 of the port's receive record (port 2 and port 3 have their own records,
 * every other port uses the third).
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED when the value is above 2. The same code is
 * inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_set_scope_size(int port)
{
    unsigned char value_char;
    unsigned char value;
    
    port = port & 0xff;
    if (port == 2) {
        value_char = uart_cmd_rx_units_digit_port2;
    } else if (port == 3) {
        value_char = uart_cmd_rx_units_digit_port3;
    } else {
        value_char = uart_cmd_rx_units_digit;
    }
    
    value = ascii_digit(value_char);
    if (value > 2) {
        return UART_CMD_REFUSED;
    }
    
    user_settings_scope_size = value;
    sys_user_apply_second_picture_enable(1);
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
