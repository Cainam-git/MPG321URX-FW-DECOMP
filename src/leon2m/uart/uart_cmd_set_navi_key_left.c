/* uart_cmd_set_navi_key_left  (FUN_a00c165c)
 *
 * Set the Navi Key left function from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00920; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00920; settings byte +0x18C
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the result is held in an unsigned int variable and returned in one place.
 */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */
#define UART_CMD_REFUSED         0xff   /* result: value refused; the caller then replies "5600-" */
#define NAVI_KEY_FUNCTION_COUNT  12     /* Navi Key functions 0..11 */

extern unsigned char user_settings_navi_key_left;
extern int osd_mark_settings_changed_copy();
extern int uart_cmd_clear_rx();
extern int uart_cmd_build_ok_reply();
extern int uart_cmd_send_tx_buffer();
extern int uart_cmd_parse_value();

/*
 * Set command 00920 (set row 0x43): the Navi Key left function (settings byte +0x18C), 0..11. The value is the
 * three-digit number of the frame, read by uart_cmd_parse_value (which returns 0xFF for a malformed number). A
 * settings save is requested.
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED when the value is 12 or more. The same code is
 * inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_set_navi_key_left(int port)
{
  unsigned int result;
  unsigned int value;
  
  port = port & 0xff;
  value = uart_cmd_parse_value(port);
  result = UART_CMD_REFUSED;
  if ((value & 0xff) < NAVI_KEY_FUNCTION_COUNT) {
    user_settings_navi_key_left = (unsigned char)value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    result = 0;
  }
  return result;
}
