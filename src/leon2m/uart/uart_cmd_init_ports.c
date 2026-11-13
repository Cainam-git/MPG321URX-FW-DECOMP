/* uart_cmd_init_ports  (FUN_a00ba8bc)
 *
 * Clear the tool command buffers and open two 8051 serial ports at 115200 baud.
 * Note: Opens the ports of mask 0x10 (line format byte 4) and mask 0x04 (line format byte 2); only the port-1
 *   buffers are cleared.
 * Name basis: derived - ipc_api_open_or_close_uart_ports(1, mask, line format, 0x1C200 = 115200) twice; caller
 *   App_CoolInitialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ba8bc @ 0xa00ba8bc-0xa00ba950 (37 words), flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: a per-port helper init_port(port), inlined here for port 1. It finds
 * the receive record and its count byte through port_rx(port, &rx, &count) (out-parameters; the port 2 / 3 / other
 * chain of uart_cmd_clear_rx) and the reply frame through port_tx(port) (the chain of uart_cmd_send_tx_buffer).
 * The records are structs holding the byte arrays and the clear loops run to sizeof. The addresses taken of the
 * locals rx and count keep the last call a normal call (no tail call) and give the minimum frame (save -104).
 */
#define RX_RECORD_SIZE  0x32            /* bytes of one receive record */
#define TX_FRAME_SIZE   0x19            /* bytes of one reply frame cleared here */

/* 8051 serial port masks: one bit per serial port (command 0x05, byte 1). */
#define SERIAL_PORT_BIT4  0x10
#define SERIAL_PORT_BIT2  0x04

#define TOOL_BAUD_RATE  115200          /* bits per second; the 8051 gets 115200 / 1200 = 96 */

struct uart_rx_buffer { unsigned char bytes[RX_RECORD_SIZE]; };
struct uart_tx_buffer { unsigned char bytes[TX_FRAME_SIZE]; };
extern struct uart_rx_buffer uart_cmd_rx_record_port2, uart_cmd_rx_record_port3, uart_cmd_rx_record;
extern struct uart_tx_buffer uart_cmd_tx_frame_port2, uart_cmd_tx_frame_port3, uart_cmd_tx_frame;
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern void ipc_api_open_or_close_uart_ports(unsigned char, unsigned char, unsigned char, unsigned int);

/* The receive record of a port and the byte that counts what has arrived in it. Port 2 and port 3 have their
   own; every other port uses uart_cmd_rx_record and uart_cmd_rx_count. */
static void port_rx(unsigned char port, struct uart_rx_buffer **rx, unsigned char **count)
{
    if (port == 2) {
        *rx = &uart_cmd_rx_record_port2;
        *count = &uart_cmd_rx_state_port2;
    } else if (port == 3) {
        *rx = &uart_cmd_rx_record_port3;
        *count = &uart_cmd_rx_state_port3;
    } else {
        *rx = &uart_cmd_rx_record;
        *count = &uart_cmd_rx_count;
    }
}

/* The reply frame of a port (same split as port_rx). */
static struct uart_tx_buffer *port_tx(unsigned char port)
{
    if (port == 2)
        return &uart_cmd_tx_frame_port2;
    else if (port == 3)
        return &uart_cmd_tx_frame_port3;
    else
        return &uart_cmd_tx_frame;
}

/* Empty the port's receive record, its count and its reply frame, then have the 8051 open two serial ports.
   The port number is also the first argument of ipc_api_open_or_close_uart_ports, where non-zero means "open"
   (command 0x05: mask, line format, baud rate). */
static void init_port(unsigned char port)
{
    struct uart_rx_buffer *rx;
    struct uart_tx_buffer *tx;
    unsigned char *count;
    unsigned char i;

    port_rx(port, &rx, &count);
    for (i = 0; i < sizeof(rx->bytes); i++)
        rx->bytes[i] = 0;
    *count = 0;
    tx = port_tx(port);
    for (i = 0; i < sizeof(tx->bytes); i++)
        tx->bytes[i] = 0;
    ipc_api_open_or_close_uart_ports(port, SERIAL_PORT_BIT4, 4, TOOL_BAUD_RATE);     /* line format byte 4 */
    ipc_api_open_or_close_uart_ports(port, SERIAL_PORT_BIT2, 2, TOOL_BAUD_RATE);     /* line format byte 2 */
}

/*
 * Prepare the PC tool command link at start-up (called once from App_CoolInitialize).
 *
 * Only port 1 is set up, which falls in the "every other port" branch: uart_cmd_rx_record (0x32 bytes),
 * uart_cmd_rx_count and the first 0x19 bytes of uart_cmd_tx_frame are cleared - the record, count and frame that
 * the port-4 command task uart_cmd_run_tool_task works on. Then the 8051 is asked to open its serial ports of
 * mask 0x10 (line format byte 4) and mask 0x04 (line format byte 2), both at 115200 baud. Port 2 and port 3
 * records are not touched.
 */
void uart_cmd_init_ports(void)
{
    init_port(1);
}
