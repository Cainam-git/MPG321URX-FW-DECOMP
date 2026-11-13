/* ipc_api_open_or_close_uart_ports  (FUN_a0148794)
 *
 * Have the 8051 open the serial ports of a mask (command 0x05: line format, baud rate) or close them.
 * Note: Opened by uart_cmd_init_ports (two ports, 115200 baud); closed by UartSetI2CEnable (command 0x06).
 * Name basis: derived - ipc_8051_open_uart_ports(mask, line format, baud rate) when the first argument is set,
 *   else ipc_8051_close_uart_ports(mask)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148794 @ 0xa0148794 (-mcpu=v8 -O2 -g).
 * Source form: the decompiler's form is kept. The callees are declared without a parameter list, so the call to
 * ipc_8051_open_uart_ports passes only its first argument and the call to ipc_8051_close_uart_ports passes three.
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
extern void ipc_8051_close_uart_ports();
extern int ipc_8051_open_uart_ports();

/*
 * Open or close serial ports of the 8051 (8051 commands 0x05 and 0x06).
 *   open_ports non-zero: call ipc_8051_open_uart_ports (command 0x05); 0: call ipc_8051_close_uart_ports
 *              (command 0x06)
 *   port_mask  passed on as the first argument (one bit per serial port)
 *   line_format the line format byte for the open call
 *   baud_rate  the baud rate for the open call
 * The callees take (port_mask, line_format, baud_rate) and (port_mask) respectively. In the machine code the
 * three argument moves (port_mask, line_format & 0xff, baud_rate) stand before the branch on open_ports, so the open
 * call receives all three; the close branch only sets its port mask again. The source form below (one argument
 * written for the open call, three for the close call) is the form that builds to this code; it does not show
 * which call uses the values. uart_cmd_init_ports opens two ports this way with line format 4 or 2 and 115200
 * baud; UartSetI2CEnable closes one.
 */
void ipc_api_open_or_close_uart_ports(unsigned char open_ports, unsigned char port_mask,undefined1 line_format,undefined4 baud_rate)

{
  if (open_ports != '\0') {
    ipc_8051_open_uart_ports(port_mask);
    return;
  }
  ipc_8051_close_uart_ports(port_mask,line_format,baud_rate);
  return;
}
