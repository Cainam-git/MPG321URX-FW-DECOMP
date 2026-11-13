/* uart_cmd_set_language  (FUN_a00cce80)
 *
 * Set the menu Language from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0
 * Note: Command 5b00800; no range check: any character is stored as its value minus '0'; replies '5600+'.
 * Name basis: proven - set frame 5b00800; settings byte +0x8 (language byte of the menu texts); also refreshes
 *   HDMI CEC (hdmi_user_send_cec_action4)
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: like uart_cmd_set_info_on_screen without the range test; the character is read into an unsigned
 * char and the language is stored as value - '0'.
 */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */
#define VALUE_CHAR_BASE          0x30   /* a one-digit value arrives as the character '0' + value */

extern unsigned char uart_cmd_rx_units_digit_port2;
extern unsigned char uart_cmd_rx_units_digit_port3;
extern unsigned char uart_cmd_rx_units_digit;
extern unsigned char user_settings_language;
extern void hdmi_user_send_cec_action4(void);
extern void osd_mark_settings_changed_copy(void);
extern void uart_cmd_build_ok_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_tx_buffer(unsigned char, int);

/*
 * Set command 00800 (set row 0x1C): the menu Language (settings byte +0x08). The value is the character in
 * byte 9 of the port's receive record (port 2 and port 3 have their own records, every other port uses the
 * third); there is no range check, any character is stored as its value minus '0'. hdmi_user_send_cec_action4
 * runs and a settings save is requested.
 * Replies "5600+" and returns 0. The same code is inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_set_language(unsigned char port)
{
  unsigned char value_char;

  if (port == 2)
    value_char = uart_cmd_rx_units_digit_port2;
  else if (port == 3)
    value_char = uart_cmd_rx_units_digit_port3;
  else
    value_char = uart_cmd_rx_units_digit;
  user_settings_language = value_char - VALUE_CHAR_BASE;
  hdmi_user_send_cec_action4();
  osd_mark_settings_changed_copy();
  uart_cmd_build_ok_reply(port);
  uart_cmd_clear_rx(port);
  uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
  return 0;
}
