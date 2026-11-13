/* input_set_port_link_field_second  (FUN_a012b078)
 *
 * Store a port's second link setting in the settings and its link row, and send the row.
 * Name basis: descriptive - two bits of settings field +0x2D, row byte 1; mailbox command 0x21
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b078 @ 0xa012b078-0xa012b164, flags -mcpu=v8 -O3 -g.
 * Source form: the settings record is a packed struct with the halfword +0x2D as a 16-bit bit-field.
 */
/* The device settings record (0xA802E1A0, 0x50 bytes), the fields used here. */
struct __attribute__((packed, aligned(4))) device_settings_record {
    unsigned char unused_00[0x2c];
    unsigned char selection_nibbles;    /* +0x2C: one nibble per port, the selection n of that port */
    unsigned short halfword_0x2d:16;    /* +0x2D: a byte per port, each with a 2-bit field per selection */
    unsigned char unused_2f[0x50 - 0x2f];
};
/* A port link row (0x16 bytes at port_link_rows); only the first two bytes are named here. */
struct port_link_row { unsigned char byte_0x00, byte_0x01; unsigned short rest[10]; };
extern struct device_settings_record device_settings;
extern struct port_link_row port_link_rows[];
extern void ipc_set_dp_rx_mode(unsigned char, unsigned char *);

/*
 * Store `value` as link setting byte 1 of port `port` in the settings and in its link row, and send the row.
 *
 *   port   port number
 *   value  new value (2 bits are stored in the settings)
 *
 * With n = nibble `port` of settings byte +0x2C, the value goes into the 2-bit field n of the port's byte in
 * settings halfword +0x2D. Row byte 1 gets the value; the row is sent with ipc_set_dp_rx_mode (mailbox command
 * 0x21). The settings record is not saved here.
 */
void input_set_port_link_field_second(unsigned char port, unsigned char value)
{
    struct port_link_row row;
    unsigned char n = (device_settings.selection_nibbles >> (port * 4)) & 0xf;

    device_settings.halfword_0x2d = (device_settings.halfword_0x2d & ~((3 << (port * 8)) << (n * 2))) | ((value << (port * 8)) << (n * 2));
    port_link_rows[port].byte_0x01 = value;
    row = port_link_rows[port];
    ipc_set_dp_rx_mode(port, (unsigned char *)&row);
}
