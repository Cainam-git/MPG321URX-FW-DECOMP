/* input_set_port_link_tail_bytes  (FUN_a012b418)
 *
 * Store three bytes of a port's link row and send them.
 * Name basis: descriptive - row bytes 8, 0x0A and 0x0B; mailbox command 0x2E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b418 @ 0xa012b418, flags -mcpu=v8 -O2 -g.
 * Source form: the row is a byte array indexed by port * 0x16 + offset; ipc_set_dp_rx_lane_options takes the five
 * values masked with 0xff.
 */
extern void ipc_set_dp_rx_lane_options(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);   /* 0xa0137d08 */

extern unsigned char port_link_rows[];      /* 0xa802d8ae, 0x16 bytes per port */

#define PORT_LINK_ROW_SIZE 0x16

/*
 * Store link row bytes 8, 0x0A and 0x0B of port `port`, and send them with the fifth value to the input
 * processor with ipc_set_dp_rx_lane_options (mailbox command 0x2E).
 *
 *   port    port number
 *   byte_8  row byte 8
 *   byte_a  row byte 0x0A
 *   byte_b  row byte 0x0B
 *   last    sent only, not stored in the row
 */
void input_set_port_link_tail_bytes(unsigned int port, char byte_8, unsigned int byte_a,
                  unsigned int byte_b, unsigned int last)
{
    unsigned int offset = (port & 0xff) * PORT_LINK_ROW_SIZE;
    port_link_rows[offset + 8] = byte_8;
    port_link_rows[offset + 0xa] = byte_a;
    port_link_rows[offset + 0xb] = byte_b;
    ipc_set_dp_rx_lane_options(port & 0xff, byte_8 & 0xff, byte_a & 0xff, byte_b & 0xff, last & 0xff);
}
