/* uart_cmd_set_ai_vision  (FUN_a00c9e9c)
 *
 * Set the AI Vision switch from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b002B0; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b002B0; bit 15 of +0x174 (osd_toggle_ai_vision)
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
#define SETTINGS_AI_VISION       0x8000 /* bit 15 of the word at +0x174: AI Vision switch */

/* The start of the user settings record (docs/RECORDS.md) up to the word at +0x174 (word_0x174). */
struct user_settings_record { unsigned char pad_0x0[0x174]; unsigned int word_0x174; };
extern struct user_settings_record user_settings;
extern unsigned char uart_cmd_rx_units_digit_port2;
extern unsigned char uart_cmd_rx_units_digit_port3;
extern unsigned char uart_cmd_rx_units_digit;
extern void ldc_user_apply_grid_enable(void);
extern void osd_mark_settings_changed_copy(void);
extern void uart_cmd_build_ok_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_tx_buffer(unsigned char, int);

static int ascii_digit(unsigned char c)
{
  return c - '0';
}

/*
 * Set command 002B0 (set row 0x88): the AI Vision switch, 0 or 1. ldc_user_apply_grid_enable then runs and a
 * settings save is requested. The value is the character in byte 9 of the port's receive record (port 2 and
 * port 3 have their own records, every other port uses the third).
 * Replies "5600+" and returns 0, or returns UART_CMD_REFUSED when the value is above 1. The same code is
 * inlined in uart_cmd_dispatch_set.
 */
int uart_cmd_set_ai_vision(unsigned char port)
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
  user_settings.word_0x174 = (user_settings.word_0x174 & ~SETTINGS_AI_VISION) | ((value & 1) << 15);
  ldc_user_apply_grid_enable();
  osd_mark_settings_changed_copy();
  uart_cmd_build_ok_reply(port);
  uart_cmd_clear_rx(port);
  uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
  return 0;
}
