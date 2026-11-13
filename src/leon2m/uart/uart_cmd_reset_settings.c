/* uart_cmd_reset_settings  (FUN_a00ccef4)
 *
 * Reset all user settings to their defaults on a PC tool command.
 *   param_1: command port (2, 3 or 4)
 * Returns: 0
 * Note: Command 5b00840; the value in the frame is not read; no routine calls it (uart_cmd_dispatch_set has
 *   its own inlined copy).
 * Name basis: proven - set frame 5b00840; sys_user_factory_reset
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default).
 * Source form: the routine takes a second, unused parameter; the return statement shifts it left by 32 bits as an
 * unsigned long long, which leaves 0 in the unsigned int result.
 */
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */

extern int osd_close_menu();
extern int osd_mark_settings_changed_copy();
extern int uart_cmd_clear_rx();
extern int uart_cmd_build_ok_reply();
extern int uart_cmd_send_tx_buffer();
extern int sys_user_factory_reset();

/*
 * Set command 00840 (set row 0x1E): close the menu and reload every user setting from its default
 * (sys_user_factory_reset); a settings save is requested. The value in the frame is not read.
 *   port:   command port (2, 3 or 4)
 *   unused: not used
 * Replies "5600+" and returns 0. Nothing calls this routine; the dispatcher has its own inlined copy (set row
 * 0x1E in uart_cmd_dispatch_set).
 */
unsigned int uart_cmd_reset_settings(unsigned char port, unsigned int unused)

{
  osd_close_menu();
  sys_user_factory_reset();
  osd_mark_settings_changed_copy();
  uart_cmd_build_ok_reply(port);
  uart_cmd_clear_rx(port);
  uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
  return (unsigned long long)unused << 0x20;
}
