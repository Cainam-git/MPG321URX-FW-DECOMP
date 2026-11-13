/* input_set_port_link_byte3  (FUN_a012b328)
 *
 * Store byte 3 of a port's link row and send it.
 * Name basis: descriptive - mailbox command 0x24
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b328 @ 0xa012b328, flags -mcpu=v8 -O2 -g.
 * Source form: ipc_set_dp_mst (void, two unsigned char parameters) is declared here with unsigned int parameters; the
 * caller masks both arguments itself (and 0xff), as the firmware does.
 */
/* A port link row (0x16 bytes at port_link_rows, address 0xa802d8ae); only byte 3 is named here. */
struct port_link_row {
    unsigned char unused_00[3];
    unsigned char byte_0x03;
    unsigned char unused_04[18];
};

extern struct port_link_row port_link_rows[];
extern void ipc_set_dp_mst(unsigned int, unsigned int);     /* 0xa0137aec */

/*
 * Store `value` in byte 3 of the link row of port `port` and send it to the input processor with
 * ipc_set_dp_mst, which asks for DisplayPort multi-stream to be switched on or off (mailbox command 0x24).
 *
 *   port   port number
 *   value  new value
 */
void input_set_port_link_byte3(unsigned int port, unsigned int value)
{
    port_link_rows[port & 0xff].byte_0x03 = value;
    ipc_set_dp_mst(port & 0xff, value & 0xff);
}
