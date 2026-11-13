/* uart_cmd_set_navi_key_right  (FUN_a00c1608)
 *
 * Set the Navi Key right function from a PC tool command and acknowledge it.
 *   param_1: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00930; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00930; settings byte +0x18D
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the routine takes a second, unused parameter and returns CONCAT44(unused, result), which the int
 * return type truncates to result.
 */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */
#define UART_CMD_REFUSED         0xff   /* result: value refused; the caller then replies "5600-" */
#define NAVI_KEY_FUNCTION_COUNT  12     /* Navi Key functions 0..11 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

extern unsigned char user_settings_navi_key_right;
extern int osd_mark_settings_changed_copy();
extern int uart_cmd_clear_rx();
extern int uart_cmd_build_ok_reply();
extern int uart_cmd_send_tx_buffer();
extern int uart_cmd_parse_value();

/*
 * Set command 00930 (set row 0x44): the Navi Key right function (settings byte +0x18D), 0..11. The value is the
 * three-digit number of the frame, read by uart_cmd_parse_value (which returns 0xFF for a malformed number). A
 * settings save is requested.
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED when the value is 12 or more. The same code is
 * inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_set_navi_key_right(int port, unsigned int unused)
{
  unsigned int result;
  unsigned int value;
  
  port = port & 0xff;
  value = uart_cmd_parse_value(port);
  result = UART_CMD_REFUSED;
  if ((value & 0xff) < NAVI_KEY_FUNCTION_COUNT) {
    user_settings_navi_key_right = (unsigned char)value;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    result = 0;
  }
  return CONCAT44(unused, result);
}
