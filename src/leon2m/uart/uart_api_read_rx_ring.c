/* uart_api_read_rx_ring  (FUN_a01487cc)
 *
 * Read received bytes of a serial port from its ring buffer.
 * Name basis: derived - forwards to the ring read that prints 'UART buf index over!' for a wrong port
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01487cc @ 0xa01487cc (-mcpu=v8 -O2 -g)
 * Code: uart_read_rx_ring(p1, p2).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int uart_read_rx_ring();

/*
 * Read received bytes of a serial port: calls uart_read_rx_ring with the port and the length only. The buffer
 * and count pointers (arguments 3 and 4) are not written here; they pass through from the caller's registers.
 * Callers: uart_cmd_read_frame and uart_cmd_read_frame_port2.
 */
void uart_api_read_rx_ring(undefined1 port,undefined2 len)

{
  uart_read_rx_ring(port,len);
  return;
}