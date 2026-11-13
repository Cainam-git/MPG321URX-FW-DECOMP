/* input_get_port_link_byte3  (FUN_a012b354)
 *
 * Return byte 3 of a port's link row.
 * Returns: byte
 * Name basis: descriptive - 22-byte rows at 0xA802D8AE; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b354 @ 0xa012b354, flags -mcpu=v8 -O2 -g.
 * The table is addressed as a byte array (index * 0x16 + 3).
 */
extern unsigned char port_link_rows[];      /* 0x16 bytes per port */

#define PORT_LINK_ROW_SIZE 0x16

/*
 * Return byte 3 of the link row of a port (the byte that input_set_port_link_byte3 stores).
 *
 *   port  port number (low byte used)
 */
unsigned char input_get_port_link_byte3(unsigned int port)
{
    return port_link_rows[(port & 0xff) * PORT_LINK_ROW_SIZE + 3];
}
