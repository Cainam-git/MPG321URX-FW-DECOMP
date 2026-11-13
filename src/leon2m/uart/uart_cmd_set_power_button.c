/* uart_cmd_set_power_button  (FUN_a00c135c)
 *
 * Set the Power Button setting from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00880; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00880; bit 15 of +0xA8 (osd_draw_power_button_choices)
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g.
 * Source form: the character goes through a static helper ascii_digit() returning c - '0' (inlined; its int
 * result kept in an unsigned char gives the 'and 0xff' of the loaded byte and of the digit). The new bit value is
 * computed before the range test.
 */
#define UART_CMD_REFUSED         0xff   /* result: value refused; the caller then replies "5600-" */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */
#define GAMING_POWER_BUTTON_STANDBY 0x8000      /* bit 15 of gaming_flags: Power Button choice (0 OFF, 1 Standby) */

/* The start of the user settings record (docs/RECORDS.md); only gaming_flags is used here. */
struct user_settings_record { unsigned char pad_0x0[0xa8]; unsigned int gaming_flags; };
extern struct user_settings_record user_settings;
extern unsigned char uart_cmd_rx_units_digit_port2;
extern unsigned char uart_cmd_rx_units_digit_port3;
extern unsigned char uart_cmd_rx_units_digit;
extern void osd_mark_settings_changed_copy(void);
extern void uart_cmd_build_ok_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_tx_buffer(unsigned char, int);

static int ascii_digit(unsigned char c)
{
  return c - '0';
}

/*
 * Set command 00880 (set row 0x4C): the Power Button choice, 0 or 1. A settings save is requested. The value is
 * the character in byte 9 of the port's receive record (port 2 and port 3 have their own records, every other
 * port uses the third).
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED when the value is above 1. The same code is
 * inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_set_power_button(unsigned char port)
{
  unsigned char value_char;
  unsigned char value;

  if (port == 2)
    value_char = uart_cmd_rx_units_digit_port2;
  else if (port == 3)
    value_char = uart_cmd_rx_units_digit_port3;
  else
    value_char = uart_cmd_rx_units_digit;
  value = ascii_digit(value_char);
  if (value > 1)
    return UART_CMD_REFUSED;
  user_settings.gaming_flags = (user_settings.gaming_flags & ~GAMING_POWER_BUTTON_STANDBY) | ((value & 1) << 15);
  osd_mark_settings_changed_copy();
  uart_cmd_build_ok_reply(port);
  uart_cmd_clear_rx(port);
  uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
  return 0;
}
