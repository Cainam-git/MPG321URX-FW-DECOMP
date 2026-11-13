/* ipc_8051_close_uart_ports  (FUN_a0133f24)
 *
 * Tell the 8051 to close the given serial ports (command 0x06).
 * Name basis: derived - ipc_send_8051_command with command 0x06; 8051 command 0x06; the handler in the 8051
 *   program (uart_close_ports) shows what it does
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133f24, flags -mcpu=v8 -O2 -g. ipc_send_8051_command is declared without a prototype, as the
 * firmware's own calls need.
 */
extern int ipc_send_8051_command();

#define IPC_8051_CMD_CLOSE_UART  0x06
#define IPC_SEND_WAIT_TAKEN      1  /* return when the 8051 has taken the command */

/*
 * Command 0x06: the 8051 closes the serial ports in the mask.
 *   port_mask: byte 1, one bit per serial port
 */
void ipc_8051_close_uart_ports(unsigned char port_mask)

{
  ipc_send_8051_command(IPC_8051_CMD_CLOSE_UART,port_mask,0,0,IPC_SEND_WAIT_TAKEN);
  return;
}
