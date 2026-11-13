/* input_set_port_type  (FUN_a006d414)
 *
 * Set the type of one port record, or of ports 0..5 for 0xFF.
 *   port: port index, 0xFF = all
 *   type: port type
 * Name basis: derived - type nibble published to the main processor by ipc_build_port_descriptor; caller
 *   ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d414 @ 0xa006d414, flags -mcpu=v8 -Os -g.
 * Source form: the test "port > 8" comes first (the 0xff case falls through, the single-record store is at the end).
 */

/* One port record (20 bytes, see docs/DATA.md); only the type byte is used here. */
struct port_record { unsigned char type, b1; unsigned short h2, h4, h6, h8, ha; unsigned char bc, bd, be, bf, b10, b11, b12, b13; };
extern struct port_record input_port_records[];

#define PORT_ALL      0xff      /* "all ports" in the port argument */
#define PORT_COUNT    9

/*
 * Set the type byte of port record 'port' (0..8). With port = 0xff the records 0..5 get it (not 6..8). Any other
 * port number changes nothing.
 *
 * The low nibble of the type is the port type that the port descriptor sent to the main processor carries
 * (ipc_build_port_descriptor). Called from ipc_dispatch_command with the two bytes of a command word.
 */
void input_set_port_type(unsigned char port, unsigned char type)
{
    /* Testing "port > 8" first gives the block order of the firmware. */
    if (port > PORT_COUNT - 1) {
        if (port == PORT_ALL) {
            input_port_records[0].type = type;
            input_port_records[1].type = type;
            input_port_records[2].type = type;
            input_port_records[3].type = type;
            input_port_records[4].type = type;
            input_port_records[5].type = type;
        }
    } else
        input_port_records[port].type = type;
}
