/* ipc_8051_open_uart_ports  (FUN_a0133f48)
 *
 * Tell the 8051 to open the given serial ports with a line format and a baud rate (command 0x05).
 * Name basis: derived - ipc_send_8051_command with command 0x05; 8051 command 0x05; the handler in the 8051
 *   program (uart_open_ports) shows what it does
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133f48, flags -mcpu=v8 -O3 -g. ipc_send_8051_command is declared without a prototype, as the
 * firmware's own calls need.
 */
extern int ipc_send_8051_command();

#define IPC_8051_CMD_OPEN_UART  0x05
#define IPC_SEND_WAIT_TAKEN     1   /* return when the 8051 has taken the command */
#define UART_BAUD_UNIT          1200    /* the 8051 multiplies byte 3 by this to get the baud rate */

/*
 * Command 0x05: the 8051 opens the serial ports in the mask with the given line format and baud rate.
 *   port_mask:   byte 1, one bit per serial port
 *   line_format: byte 2, the line format byte the 8051 hands to uart_open_ports
 *   baud_rate:   baud rate in bits per second; byte 3 is baud_rate / 1200 (low 8 bits)
 */
void ipc_8051_open_uart_ports(unsigned char port_mask,unsigned char line_format,unsigned int baud_rate)

{
  ipc_send_8051_command(IPC_8051_CMD_OPEN_UART,port_mask,line_format,baud_rate / UART_BAUD_UNIT & 0xff,IPC_SEND_WAIT_TAKEN);
  return;
}
