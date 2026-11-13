/* uart_cmd_set_refresh_rate_display  (FUN_a00c0d10)
 *
 * Set the Refresh Rate display switch from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00250; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00250; bit 12 of +0xA8 (osd_enter_refresh_rate_choices)
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
#define GAMING_REFRESH_RATE_DISPLAY 0x1000      /* bit 12 of gaming_flags: Refresh Rate display switch */

/* The start of the user settings record (docs/RECORDS.md); only gaming_flags is used here. */
struct user_settings_record { unsigned char pad_0x0[0xa8]; unsigned int gaming_flags; };
extern struct user_settings_record user_settings;
extern unsigned char uart_cmd_rx_units_digit_port2;
extern unsigned char uart_cmd_rx_units_digit_port3;
extern unsigned char uart_cmd_rx_units_digit;
extern void osd_close_menu(void);
extern void uart_cmd_build_ok_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_tx_buffer(unsigned char, int);

static int ascii_digit(unsigned char c)
{
  return c - '0';
}

/*
 * Set command 00250 (set row 0x30): the Refresh Rate display switch, 0 or 1. The value is the character in byte
 * 9 of the port's receive record (port 2 and port 3 have their own records, every other port uses the third).
 * The menu is closed; no settings save is requested here.
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED when the value is above 1. The same code is
 * inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_set_refresh_rate_display(unsigned char port)
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
  user_settings.gaming_flags = (user_settings.gaming_flags & ~GAMING_REFRESH_RATE_DISPLAY) | ((value & 1) << 12);
  osd_close_menu();
  uart_cmd_build_ok_reply(port);
  uart_cmd_clear_rx(port);
  uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
  return 0;
}
