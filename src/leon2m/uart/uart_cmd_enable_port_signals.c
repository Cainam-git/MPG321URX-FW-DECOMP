/* uart_cmd_enable_port_signals  (FUN_a00cbe2c)
 *
 * Switch the signal of all input ports on and acknowledge the PC tool.
 *   param_1: command port (2, 3 or 4)
 * Returns: 0
 * Note: Uncalled standalone copy of set case 0x48 (command 5b00Z..); input_api_set_port_signal(0xFE, 1).
 * Name basis: descriptive - body: input_api_set_port_signal(0xFE, 1) then the '5600+' reply
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default).
 * Source form: the routine takes a second, unused parameter; the return statement shifts it left by 32 bits as an
 * unsigned long long, which leaves 0 in the unsigned int result.
 */
#define ALL_PORTS                0xfe   /* input_api_set_port_signal: all input slots */
#define PORT_SIGNAL_ON           1
#define UART_CMD_OK_REPLY_LENGTH 6      /* "5600+" and CR */

extern int uart_cmd_clear_rx();
extern int uart_cmd_build_ok_reply();
extern int uart_cmd_send_tx_buffer();
extern int input_api_set_port_signal();

/*
 * Set row 0x48 of uart_cmd_dispatch_set. Nothing calls this routine; the dispatcher has its own inlined copy.
 * Switch the signal of all input slots on (input_api_set_port_signal) and reply "5600+". The value in the frame
 * is not read.
 *   port:   command port (2, 3 or 4)
 *   unused: not used
 * Returns 0.
 */
unsigned int uart_cmd_enable_port_signals(unsigned char port, unsigned int unused)

{
  input_api_set_port_signal(ALL_PORTS, PORT_SIGNAL_ON);
  uart_cmd_build_ok_reply(port);
  uart_cmd_clear_rx(port);
  uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
  return (unsigned long long)unused << 0x20;
}
